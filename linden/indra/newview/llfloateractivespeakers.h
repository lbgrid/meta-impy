/** 
 * @file llfloateractivespeakers.h
 * @brief Management interface for muting and controlling volume of residents currently speaking
 *
 * $LicenseInfo:firstyear=2005&license=viewergpl$
 * 
 * Copyright (c) 2005-2007, Linden Research, Inc.
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

#ifndef LL_LLFLOATERACTIVESPEAKERS_H
#define LL_LLFLOATERACTIVESPEAKERS_H

#include "llfloater.h"
#include "llmemory.h"
#include "llvoiceclient.h"
#include "llframetimer.h"

class LLScrollListCtrl;
class LLButton;
class LLPanelActiveSpeakers;
class LLSpeakerMgr;
class LLVoiceChannel;


// data for a given participant in a voice channel
class LLSpeaker : public LLRefCount
{
public:
	typedef enum e_speaker_type
	{
		SPEAKER_AGENT,
		SPEAKER_OBJECT
	} ESpeakerType;

	typedef enum e_speaker_status
	{
		STATUS_SPEAKING,
		STATUS_HAS_SPOKEN,
		STATUS_VOICE_ACTIVE,
		STATUS_TEXT_ONLY,
		STATUS_NOT_IN_CHANNEL,
		STATUS_MUTED
	} ESpeakerStatus;


	LLSpeaker(const LLUUID& id, const LLString& name = LLString::null, const ESpeakerType type = SPEAKER_AGENT);
	~LLSpeaker();

	void lookupName();

	static void onAvatarNameLookup(const LLUUID& id, const char* first, const char* last, BOOL is_group, void* user_data);

public:

	ESpeakerStatus	mStatus;			// current activity status in speech group
	F32				mLastSpokeTime;		// timestamp when this speaker last spoke
	F32				mSpeechVolume;		// current speech amplitude (timea average rms amplitude?)
	LLString		mDisplayName;		// cache user name for this speaker
	LLFrameTimer	mActivityTimer;	// time out speakers when they are not part of current voice channel
	BOOL			mHasSpoken;			// has this speaker said anything this session?
	LLColor4		mDotColor;
	LLUUID			mID;
	BOOL			mTyping;
	S32				mSortIndex;
	LLViewHandle	mHandle;
	ESpeakerType	mType;

	typedef std::map<LLViewHandle, LLSpeaker*> speaker_map_t;
	static speaker_map_t sSpeakers;
};

class LLSpeakerMgr
{
public:
	LLSpeakerMgr(LLVoiceChannel* channelp);
	virtual ~LLSpeakerMgr();

	const LLPointer<LLSpeaker> findSpeaker(const LLUUID& avatar_id);
	void update();
	void setSpeakerTyping(const LLUUID& speaker_id, BOOL typing);
	void speakerChatted(const LLUUID& speaker_id);
	LLPointer<LLSpeaker> setSpeaker(const LLUUID& id, 
					const LLString& name = LLString::null, 
					LLSpeaker::ESpeakerStatus status = LLSpeaker::STATUS_TEXT_ONLY, 
					LLSpeaker::ESpeakerType = LLSpeaker::SPEAKER_AGENT);

	BOOL isVoiceActive();

	typedef std::vector<LLPointer<LLSpeaker> > speaker_list_t;
	void getSpeakerList(speaker_list_t* speaker_list, BOOL include_text);

protected:
	virtual void updateSpeakerList();

	typedef std::map<LLUUID, LLPointer<LLSpeaker> > speaker_map_t;
	speaker_map_t		mSpeakers;

	speaker_list_t		mSpeakersSorted;
	LLFrameTimer		mSpeechTimer;
	LLVoiceChannel*		mVoiceChannel;
};

class LLIMSpeakerMgr : public LLSpeakerMgr
{
public:
	LLIMSpeakerMgr(LLVoiceChannel* channel);
	
	void processSpeakerListUpdate(LLSD update);
	void processSpeakerList(LLSD list);
	void processSpeakerMap(LLSD list);
protected:
	virtual void updateSpeakerList();
};

class LLActiveSpeakerMgr : public LLSpeakerMgr
{
public:
	LLActiveSpeakerMgr();
protected:
	virtual void updateSpeakerList();
};

class LLLocalSpeakerMgr : public LLSpeakerMgr
{
public:
	LLLocalSpeakerMgr();
	~LLLocalSpeakerMgr ();
protected:
	virtual void updateSpeakerList();
};


class LLFloaterActiveSpeakers : 
	public LLUISingleton<LLFloaterActiveSpeakers>, 
	public LLFloater, 
	public LLVoiceClientParticipantObserver
{
	// friend of singleton class to allow construction inside getInstance() since constructor is protected
	// to enforce singleton constraint
	friend class LLUISingleton<LLFloaterActiveSpeakers>;
public:
	virtual ~LLFloaterActiveSpeakers();

	/*virtual*/ BOOL postBuild();
	/*virtual*/ void onClose(bool app_quitting);
	/*virtual*/ void draw();

	/*virtual*/ void onChange();

	static void* createSpeakersPanel(void* data);

protected:
	LLFloaterActiveSpeakers(const LLSD& seed);

	LLPanelActiveSpeakers*	mPanel;
};

class LLPanelActiveSpeakers : public LLPanel
{
public:
	LLPanelActiveSpeakers(LLSpeakerMgr* data_source, BOOL show_text_chatters);
	virtual ~LLPanelActiveSpeakers();

	/*virtual*/ BOOL postBuild();

	void refreshSpeakers();
	
	void setSpeaker(const LLUUID& id, 
					const LLString& name = LLString::null, 
					LLSpeaker::ESpeakerStatus status = LLSpeaker::STATUS_TEXT_ONLY, 
					LLSpeaker::ESpeakerType = LLSpeaker::SPEAKER_AGENT);
	
	static void onClickMuteVoice(void* user_data);
	static void onClickMuteVoiceCommit(LLUICtrl* ctrl, void* user_data);
	static void onClickMuteTextCommit(LLUICtrl* ctrl, void* user_data);
	static void onVolumeChange(LLUICtrl* source, void* user_data);
	static void onClickProfile(void* user_data);
protected:
	LLScrollListCtrl*	mSpeakerList;
	LLUICtrl*			mMuteVoiceCtrl;
	LLUICtrl*			mMuteTextCtrl;
	LLTextBox*			mNameText;
	LLButton*			mProfileBtn;
	BOOL				mShowTextChatters;
	LLSpeakerMgr*		mSpeakerMgr;
	LLFrameTimer		mIconAnimationTimer;
};

extern LLLocalSpeakerMgr*	gLocalSpeakerMgr;
extern LLActiveSpeakerMgr*		gActiveChannelSpeakerMgr;

#endif // LL_LLFLOATERACTIVESPEAKERS_H
