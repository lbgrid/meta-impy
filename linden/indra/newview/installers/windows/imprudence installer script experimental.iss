; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)

; These will change
AppId={{1B3E68BC-13EB-4277-9439-CB5FF9259460}
AppName=Imprudence Viewer Experimental Release
AppVerName=Imprudence Viewer 1.4.0 Experimental 2010.09.04
DefaultDirName={pf}\ImprudenceExperimental
DefaultGroupName=Imprudence Viewer Experimental Release
VersionInfoProductName=Imprudence Viewer Experimental Release
OutputBaseFilename=Imprudence-1.4.0-experimental-2010.09.04-Setup
VersionInfoVersion=1.4.0
VersionInfoTextVersion=1.4.0
VersionInfoProductVersion=1.4.0
VersionInfoCopyright=2010
AppCopyright=2010

; These won't change
VersionInfoCompany=Imprudence
AppPublisher=The Imprudence Project
AppPublisherURL=http://www.imprudenceviewer.org
AppSupportURL=http://www.imprudenceviewer.org
AppUpdatesURL=http://www.imprudenceviewer.org
AllowNoIcons=true
InfoAfterFile=..\windows\README.txt
OutputDir=C:\
SetupIconFile=..\windows\imp_icon.ico
Compression=lzma2/ultra64
InternalCompressLevel=ultra64
SolidCompression=true
PrivilegesRequired=poweruser
AllowRootDirectory=true
WizardImageFile=..\windows\imprudence_installer_icon_left.bmp
WizardSmallImageFile=..\windows\imprudence_installer_icon_right.bmp
SetupLogging=true

[Languages]
Name: english; MessagesFile: compiler:Default.isl

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: checkedonce
Name: quicklaunchicon; Description: {cm:CreateQuickLaunchIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: checkedonce
Name: slurlassociate; Description: Associate Imprudence with SLURLs; GroupDescription: Associations:; Languages: ; Flags: checkedonce
; TODO: use scripting for something like this on uninstall:
; Name: uninstallsettings; Description: Remove user settings; Flags: checkablealone; Languages: ; GroupDescription: Uninstall:

[Files]
Source: C:\imp_1.3\imprudence.exe; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\character\*; DestDir: {app}\character; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\fonts\*; DestDir: {app}\fonts; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\app_settings\*; DestDir: {app}\app_settings; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\skins\*; DestDir: {app}\skins; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\doc\*; DestDir: {app}\doc; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\lib\*; DestDir: {app}\lib; Flags: ignoreversion recursesubdirs createallsubdirs
Source: C:\imp_1.3\alut.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\ChangeLog.txt; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\charset.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\dbghelp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\featuretable.txt; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\freebl3.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\glew32.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\gpu_table.txt; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\iconv.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\imprudence.exe.config; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\imprudence.url; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\intl.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\js3250.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libcairo-2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libfaad-2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgcrypt-11.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgio-2.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libglib-2.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgmodule-2.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgnutls-26.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgobject-2.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgpg-error-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstapp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstaudio.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstaudio-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstbase-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstcdda.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstcontroller-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstdataprotocol-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstdshow.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstfft.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstinterfaces.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstnet-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstnetbuffer.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstpbutils.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstreamer-0.10.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstriff.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstrtp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstrtsp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstsdp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgsttag.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgstvideo.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libgthread-2.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libhunspell.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libjpeg.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libmp3lame-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libneon-27.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libogg-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\liboil-0.3-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libopenjpeg-2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libpng12-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libschroedinger-1.0-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libspeex-1.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libtheora-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libvorbis-0.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libvorbisenc-2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libxml2-2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\libxml2.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\llkdu.dll.2.config; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\Microsoft.VC80.CRT.manifest; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\msvcp80.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\msvcr80.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\nspr4.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\nss3.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\nssckbi.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\openal32.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\OpenJPEG.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\plc4.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\plds4.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\smime3.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\softokn3.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\ssl3.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\xpcom.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\xul.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\xvidcore.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\zlib1.dll; DestDir: {app}; Flags: ignoreversion

; Voice files
Source: C:\imp_1.3\ortp.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\SLVoice.exe; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\vivoxsdk.dll; DestDir: {app}; Flags: ignoreversion
Source: C:\imp_1.3\wrap_oal.dll; DestDir: {app}; Flags: ignoreversion

; Old files we don't use anymore
; Source: C:\imp_1.3\dronesettings.xml; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\volume_settings.xml; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\srtp.dll; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\ssleay32.dll; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\tntk.dll; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\libeay32.dll; DestDir: {app}; Flags: ignoreversion
; Source: C:\imp_1.3\lsl_guide.html; DestDir: {app}; Flags: ignoreversion

; NOTE: Don't use "Flags: ignoreversion" on any shared system files
;Source: C:\imp_1.3\msvcr71.dll; DestDir: {app}; Flags: ignoreversion; MinVersion: 0,6.01; Tasks: ; Languages:

[Registry]
Root: HKCR; Subkey: secondlife; ValueType: string; Flags: uninsdeletekey deletekey; Tasks: slurlassociate; ValueName: (default); ValueData: URL:Second Life
Root: HKCR; Subkey: secondlife; ValueType: string; Flags: uninsdeletekey deletekey; Tasks: slurlassociate; ValueName: URL Protocol
Root: HKCR; Subkey: secondlife\DefaultIcon; Flags: uninsdeletekey deletekey; ValueType: string; Tasks: slurlassociate; ValueData: {app}\imprudence.exe
Root: HKCR; Subkey: secondlife\shell\open\command; ValueType: expandsz; Flags: uninsdeletekey deletekey; Tasks: slurlassociate; ValueData: "{app}\imprudence.exe --settings settings_imprudence.xml -url ""%1"""; Languages: 
; Root: HKCU; Subkey: Environment; ValueType: string; ValueName: GST_PLUGIN_PATH; Flags: deletevalue uninsdeletevalue; ValueData: {app}\lib
; Root: HKCU; Subkey: Environment; ValueType: expandsz; ValueName: PATH; ValueData: {app}

[Icons]
Name: {group}\{cm:UninstallProgram,Imprudence Experimental}; Filename: {uninstallexe}
Name: {commondesktop}\Imprudence Experimental; Filename: {app}\imprudence.exe; Tasks: desktopicon; Parameters: --settings settings_imprudence.xml; WorkingDir: {app}; IconIndex: 0
Name: {userappdata}\Microsoft\Internet Explorer\Quick Launch\Imprudence Experimental; Filename: {app}\imprudence.exe; Tasks: quicklaunchicon; Parameters: --settings settings_imprudence.xml; WorkingDir: {app}
Name: {group}\Imprudence Experimental; Filename: {app}\imprudence.exe; WorkingDir: {app}; Comment: imprudence; IconIndex: 0; Parameters: --settings settings_imprudence.xml

[Run]
Filename: {app}\imprudence.exe; WorkingDir: {app}; Flags: nowait postinstall
Filename: {app}\imprudence.url; WorkingDir: {app}; Flags: nowait postinstall shellexec; Description: See what makes Imprudence different

[UninstallDelete]
Name: {userappdata}\Imprudence\user_settings\password.dat; Type: files; Languages: 
Name: {userappdata}\Imprudence\user_settings\settings.xml; Type: files; Languages: 
Name: {userappdata}\Imprudence\user_settings\settings_imprudence.xml; Type: files; Languages: 
; 1.2 and lower cache location:
Name: {userappdata}\Imprudence\cache; Type: filesandordirs
; 1.3 and higher cache location:
Name: {localappdata}\Imprudence\cache; Type: filesandordirs
Name: {userappdata}\Imprudence\logs; Type: filesandordirs
Name: {userappdata}\Imprudence\browser_profile; Type: filesandordirs
Name: C:\Users\{username}\.gstreamer-0.10; Type: filesandordirs
Name: C:\Documents and Settings\{username}\.gstreamer-0.10; Type: filesandordirs

[InstallDelete]
; Name: {app}\*.dll; Type: files; Tasks: ; Languages:
Name: {app}\lib\gstreamer-plugins\*; Type: filesandordirs; Tasks: ; Languages: 
; Name: {app}\skins\default\xui\*; Type: filesandordirs; Tasks: ; Languages:
; Name: {app}\skins\silver\xui\*; Type: filesandordirs; Tasks: ; Languages:
Name: C:\Documents and Settings\{username}\.gstreamer-0.10\*; Type: filesandordirs
Name: C:\Users\{username}\.gstreamer-0.10\*; Type: filesandordirs
; Breaks the browser if installing on top of 1.1:
Name: {app}\gksvggdiplus.dll; Type: files; Tasks: ; Languages:
