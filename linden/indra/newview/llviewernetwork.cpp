/** 
 * @file llviewernetwork.cpp
 * @author James Cook, Richard Nelson
 * @brief Networking constants and globals for viewer.
 *
 * $LicenseInfo:firstyear=2006&license=viewergpl$
 * 
 * Copyright (c) 2006-2008, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at
 * http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

#include "llviewerprecompiledheaders.h"

#include "llviewernetwork.h"
#include "llviewercontrol.h"
#include "llstartup.h"

 #include "hippogridmanager.h"


// TODO onefang - Ew, an evil looking thing to get saved logins to work.  Replace it later.
struct LLGridData
{
	const char* mLabel;
	const char* mName;
	const char* mGridURI;
	const char* mHelperURI;
};

static LLGridData gGridInfo[GRID_INFO_COUNT] = 
{
	{ "None", "", "", ""},
	{ "Aditi", 
	  "util.aditi.lindenlab.com", 
	  "https://login.aditi.lindenlab.com/cgi-bin/login.cgi",
	  "http://aditi-secondlife.webdev.lindenlab.com/helpers/" },
	{ "Agni", 
	  "util.agni.lindenlab.com", 
	  "https://login.agni.lindenlab.com/cgi-bin/login.cgi",
	  "https://secondlife.com/helpers/" },
	{ "Local", 
	  "localhost", 
	  "https://login.dmz.lindenlab.com/cgi-bin/login.cgi",
	  "" },
	{ "Other", 
	  "", 
	  "https://login.dmz.lindenlab.com/cgi-bin/login.cgi",
	  "" }
};

LLViewerLogin::LLViewerLogin() :
	mGridChoice(DEFAULT_GRID_CHOICE),
	mCurrentURI(0),
	mNameEditted(false)
{
	parseCommandLineURIs();
}

// End of Ewww.


unsigned char gMACAddress[MAC_ADDRESS_BYTES];		/* Flawfinder: ignore */


void LLViewerLogin::getLoginURIs(std::vector<std::string>& uris) const
{
	// return the login uri set on the command line.
	LLControlVariable* c = gSavedSettings.getControl("CmdLineLoginURI");
	if(c && !LLStartUp::shouldAutoLogin())
	{
		LLSD v = c->getValue();
		if(v.isArray())
		{
			for(LLSD::array_const_iterator itr = v.beginArray();
				itr != v.endArray(); ++itr)
			{
				std::string uri = itr->asString();
				if(!uri.empty())
				{
					uris.push_back(uri);
				}
			}
		}
		else
		{
			std::string uri = v.asString();
			if(!uri.empty())
			{
				uris.push_back(uri);
			}
		}
	}
	
	// If there was no command line uri...
	if(uris.empty())
	{
		uris.push_back(gHippoGridManager->getConnectedGrid()->getLoginUri());
		/*
		// If its a known grid choice, get the uri from the table,
		// else try the grid name.
		if(mGridChoice > GRID_INFO_NONE && mGridChoice < GRID_INFO_OTHER)
		{
			uris.push_back(gGridInfo[mGridChoice].mLoginURI);
		}
		else
		{
			uris.push_back(mGridName);
		} */
	}
}

const std::string &LLViewerLogin::getGridLabel() const
{
	return gHippoGridManager->getConnectedGrid()->getGridNick();
}

const std::string &LLViewerLogin::getLoginPage() const
{
	return gHippoGridManager->getConnectedGrid()->getLoginPage();
}

const std::string &LLViewerLogin::getHelperURI() const
{
	return gHippoGridManager->getConnectedGrid()->getHelperUri();
}
  
bool LLViewerLogin::isOpenSimulator()
{
	return gHippoGridManager->getConnectedGrid()->isOpenSimulator();
}

bool LLViewerLogin::isSecondLife()
{
	return gHippoGridManager->getConnectedGrid()->isSecondLife();
}

bool LLViewerLogin::isInProductionGrid()
{
	return true;
}



// TODO onefang - Ew, an evil looking thing to get saved logins to work.  Replace it later.
void LLViewerLogin::setGridURI(const std::string& uri)
{
	std::vector<std::string> uri_list;
	uri_list.push_back(uri);
	setGridURIs(uri_list);
}

void LLViewerLogin::setGridURIs(const std::vector<std::string>& urilist)
{
	mGridURIs.clear();
	mGridURIs.insert(mGridURIs.begin(), urilist.begin(), urilist.end());
	mCurrentURI = 0;
}

void LLViewerLogin::setGridChoice(EGridInfo grid)
{	
	if(grid < 0 || grid >= GRID_INFO_COUNT)
	{
		llerrs << "Invalid grid index specified." << llendl;
	}

	mGridChoice = grid;
	if(GRID_INFO_LOCAL == mGridChoice)
	{
		mGridName = LOOPBACK_ADDRESS_STRING;
	}
	else if (GRID_INFO_OTHER == mGridChoice)
	{
		// *FIX:Mani - could this possibly be valid?
		mGridName = "other"; 
	}
	else
	{
		mGridName = gGridInfo[mGridChoice].mLabel;
		setGridURI(getStaticGridURI(grid));
		setHelperURI(getStaticGridHelperURI(grid));
		setLoginPageURI(std::string());
	}

	gSavedSettings.setS32("ServerChoice", mGridChoice);
	gSavedSettings.setString("CustomServer", "");
}

void LLViewerLogin::setGridChoice(const std::string& grid_name)
{
	// Set the grid choice based on a string.
	// The string can be:
	// - a grid label from the gGridInfo table 
	// - an ip address
    if(!grid_name.empty())
    {
        // find the grid choice from the user setting.
        int grid_index = GRID_INFO_NONE; 
        for(;grid_index < GRID_INFO_OTHER; ++grid_index)
        {
            if(0 == LLStringUtil::compareInsensitive(gGridInfo[grid_index].mLabel, grid_name))
            {
				// Founding a matching label in the list...
				setGridChoice((EGridInfo)grid_index);
				break;
            }
        }

        if(GRID_INFO_OTHER == grid_index)
        {
            // *FIX:MEP Can and should we validate that this is an IP address?
            mGridChoice = GRID_INFO_OTHER;
            mGridName = grid_name;
			gSavedSettings.setS32("ServerChoice", mGridChoice);
			gSavedSettings.setString("CustomServer", mGridName);
			setGridURI(mGridName);
        }
    }
}

EGridInfo LLViewerLogin::getGridChoice() const
{
	return mGridChoice;
}

const std::vector<std::string>& LLViewerLogin::getCommandLineURIs()
{
	return mCommandLineURIs;
}

const std::vector<std::string>& LLViewerLogin::getGridURIs()
{
	return mGridURIs;
}

void LLViewerLogin::parseCommandLineURIs()
{
	// return the login uri set on the command line.
	LLControlVariable* c = gSavedSettings.getControl("CmdLineLoginURI");
	if(c)
	{
		LLSD v = c->getValue();
		if (!v.isUndefined())
		{
			bool foundRealURI = false;
			if(v.isArray())
			{
				for(LLSD::array_const_iterator itr = v.beginArray();
					itr != v.endArray(); ++itr)
				{
					std::string uri = itr->asString();
					if(!uri.empty())
					{
						foundRealURI = true;
						LLStringUtil::toLower(uri);
						mCommandLineURIs.push_back(uri);
					}
				}
			}
			else if (v.isString())
			{
				std::string uri = v.asString();
				if(!uri.empty())
				{
					foundRealURI = true;
					LLStringUtil::toLower(uri);
					mCommandLineURIs.push_back(uri);
				}
			}

			if (foundRealURI)
			{
				mGridChoice = GRID_INFO_OTHER;
				mCurrentURI = 0;
				mGridName = getGridLabel();
			}
		}
	}

	setLoginPageURI(gSavedSettings.getString("LoginPage"));
	setHelperURI(gSavedSettings.getString("CmdLineHelperURI"));
}

const std::string LLViewerLogin::getCurrentGridURI()
{
	return (((int)(mGridURIs.size()) > mCurrentURI) ? mGridURIs[mCurrentURI] : std::string());
}

bool LLViewerLogin::tryNextURI()
{
	if (++mCurrentURI < (int)(mGridURIs.size()))
	{
		return true;
	}
	else
	{
		mCurrentURI = 0;
		return false;
	}
}

const std::string LLViewerLogin::getStaticGridHelperURI(const EGridInfo grid) const
{
	std::string helper_uri;
	// grab URI from selected grid
	if(grid > GRID_INFO_NONE && grid < GRID_INFO_OTHER)
	{
		helper_uri = gGridInfo[grid].mHelperURI;
	}

	if (helper_uri.empty())
	{
		// what do we do with unnamed/miscellaneous grids?
		// for now, operations that rely on the helper URI (currency/land purchasing) will fail
	}
	return helper_uri;
}

//const std::string LLViewerLogin::getHelperURI() const
//{
//	return mHelperURI;
//}

void LLViewerLogin::setHelperURI(const std::string& uri)
{
	mHelperURI = uri;
}

const std::string LLViewerLogin::getLoginPageURI() const
{
	return mLoginPageURI;
}

void LLViewerLogin::setLoginPageURI(const std::string& uri)
{
	mLoginPageURI = uri;
}

const std::string LLViewerLogin::getStaticGridURI(const EGridInfo grid) const
{
	// If its a known grid choice, get the uri from the table,
	// else try the grid name.
	if(mGridChoice > GRID_INFO_NONE && mGridChoice < GRID_INFO_OTHER)
	{
		return gGridInfo[mGridChoice].mGridURI;
	}
	else
	{
		return mGridName;
	}
}

std::string LLViewerLogin::getKnownGridLabel(EGridInfo grid_index) const
{
	if(grid_index > GRID_INFO_NONE && grid_index < GRID_INFO_OTHER)
	{
		return gGridInfo[grid_index].mLabel;
	}
	return gGridInfo[GRID_INFO_NONE].mLabel;
}

std::string LLViewerLogin::getGridLabelOld()
{
	if(mGridChoice == GRID_INFO_NONE)
	{
		return "None";
	}
	else if(mGridChoice < GRID_INFO_OTHER)
	{
		return gGridInfo[mGridChoice].mLabel;
	}
	else if (!mGridName.empty())
	{
		return mGridName;
	}
	else
	{
		return LLURI(getCurrentGridURI()).hostName();
	}
}


