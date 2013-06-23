Maya C++ Wizards
================

A Maya C++ Wizards for Wizards for Visual Studio and Xcode
optimized and using pre-compiled headers


1) Xcode Install
----------------
- copy 'Xcode/Maya 2014.xctemplate' in '/Applications/Xcode-4.3.3/Contents/Developer/Library/Xcode/Templates/Project Templates/Mac/Autodesk'
- copy 'Maya Command.xctemplate' and 'Maya Node.xctemplate' in /Applications/Xcode-4.3.3/Contents/Developer/Library/Xcode/Templates/File Templates/Maya'

a pkg installer project will be coming soon

<b>Note:</b> Maya 2014 requires using the Mac 10.6 SDK (Snow Leopard). Xcode-4.3.3 is the latest compatible version which can use the 10.6 SDK. If using an older verion and/or if you migrated to Mountain Lion, you will need to change the project settings to use the 10.7 SDK (Lion) to be able to compile.


2) Visual Studio Install
------------------------
- copy 'MayaAppWiz', 'MayaCommand', 'MayaNode' and 'MayaWizCommon' in a directory of your choice.
- copy '_Install/VC' into 'C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC' and/or 'C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC'
- edit the .vsz files you copied in the previous step and change:
   - [WIZVERSION] into 10.0 or 11.0 depending of the Visual Version you installed it into
   - [TARGETDIR] to the directory where you copied the wizards files

a wix/msi installer project will be coming soon

<b>Note:</b> Maya 2014 requires using the VC 10.0 Service Pack 1 runtime, if using Visual Studio 2012, do not forget to change the 'Platform Toolkit' to vc100
