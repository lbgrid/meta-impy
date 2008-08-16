/** 
 * @file llvieweruictrlfactory.h
 * @brief factory class for creating UI controls
 *
 * $LicenseInfo:firstyear=2003&license=viewergpl$
 * 
 * Copyright (c) 2003-2007, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlife.com/developers/opensource/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlife.com/developers/opensource/flossexception
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

#ifndef LL_LLVIEWERUICTRLFACTORY_H
#define LL_LLVIEWERUICTRLFACTORY_H

#include "lluictrlfactory.h"

class LLControlGroup;
class LLColorSwatchCtrl;
class LLInventoryPanel;
class LLNameListCtrl;
class LLNameEditor;
class LLTextureCtrl;
class LLWebBrowserCtrl;
class LLViewerTextEditor;
class LLMediaRemoteCtrl;
class LLJoystickAgentTurn;
class LLJoystickAgentSlide;

class LLViewerUICtrlFactory : public LLUICtrlFactory
{
public:
	LLViewerUICtrlFactory();
	// do not call!  needs to be public so run-time can clean up the singleton
	virtual ~LLViewerUICtrlFactory();

	// specific typed getters
	static LLColorSwatchCtrl*	getColorSwatchByName(LLPanel* panelp, const LLString& name);
	static LLNameListCtrl*		getNameListByName(LLPanel* panelp, const LLString& name);
	static LLTextureCtrl*		getTexturePickerByName(LLPanel* panelp, const LLString& name);
	static LLWebBrowserCtrl*	getWebBrowserByName(LLPanel* panelp, const LLString& name);
	static LLViewerTextEditor*	getViewerTextEditorByName(	LLPanel* panelp, const LLString& name);
	static LLNameEditor* 		getNameEditorByName(LLPanel* panelp, const LLString& name);
	static LLMediaRemoteCtrl*   getMediaRemoteByName(LLPanel* panelp, const LLString& name);
	static LLJoystickAgentTurn* getJoystickAgentTurnByName(LLPanel* panelp, const LLString& name);
	static LLJoystickAgentSlide* getJoystickAgentSlideByName(LLPanel* panelp, const LLString& name);

};

extern LLUICtrlFactory* gUICtrlFactory;

#endif //LL_LLVIEWERUICTRLFACTORY_H
