Maya C++ Wizards
================

A Maya C++ Wizards for Wizards for Visual Studio and Xcode  
optimized and using pre-compiled headers

Written by Cyrille Fauvel (Autodesk Developer Network)  
[http://www.autodesk.com/adn](http://www.autodesk.com/adn)  
[http://around-the-corner.typepad.com/](http://around-the-corner.typepad.com/)

1) Xcode Install
----------------

There is 2 way to install the Wizards for Xcode. You can either modify Xcode.app directly (requires super-user rights), or modify per-user Templates.


Modifying Xcode.app


Maya 2014 (see [requirements](http://around-the-corner.typepad.com/adn/2013/06/maya-compiler-versions-update.html))
In the following instructions Xcode was renamed Xcode-4.3.3 to match the Maya required compiler version. On your system, it is by default just Xcode.app.
- copy 'Xcode/Maya 2014.xctemplate' in '/Applications/Xcode-4.3.3.app/Contents/Developer/Library/Xcode/Templates/Project Templates/Mac/Autodesk'
- copy 'Maya Command.xctemplate' and 'Maya Node.xctemplate' in '/Applications/Xcode-4.3.3.app/Contents/Developer/Library/Xcode/Templates/File Templates/Maya'

Maya 2015 (see [requirements](http://around-the-corner.typepad.com/adn/2014/04/maya-compiler-versions-update.html))
In the following instructions Xcode was renamed Xcode-5.0.2 to match the Maya required compiler version. On your system, it is by default just Xcode.app.
- copy 'Xcode/Maya 2015.xctemplate' in '/Applications/Xcode-5.0.2.app/Contents/Developer/Library/Xcode/Templates/Project Templates/Mac/Autodesk'
- copy 'Maya Command.xctemplate' and 'Maya Node.xctemplate' in '/Applications/Xcode-5.0.2.app/Contents/Developer/Library/Xcode/Templates/File Templates/Maya'


Per-user Templates

Go to '~/Library/Developer/Xcode' and create, if they do not exist yet, the following 2 folders:
- Project Templates
- File Templates

,
Maya 2014 (see [requirements](http://around-the-corner.typepad.com/adn/2013/06/maya-compiler-versions-update.html))
In the following instructions Xcode was renamed Xcode-4.3.3 to match the Maya required compiler version. On your system, it is by default just Xcode.app.
- copy 'Xcode/Maya 2014.xctemplate' in '~/Library/Developer/Xcode/Templates/Project Templates/Mac/Autodesk'
- copy 'Maya Command.xctemplate' and 'Maya Node.xctemplate' in ‘~/Library/Developer/Xcode/Templates/File Templates/Maya'

Maya 2015 (see [requirements](http://around-the-corner.typepad.com/adn/2014/04/maya-compiler-versions-update.html))
In the following instructions Xcode was renamed Xcode-5.0.2 to match the Maya required compiler version. On your system, it is by default just Xcode.app.
- copy 'Xcode/Maya 2015.xctemplate' in '~/Library/Developer/Xcode/Templates/Project Templates/Mac/Autodesk'
- copy 'Maya Command.xctemplate' and 'Maya Node.xctemplate' in '~/Library/Developer/Xcode/Templates/File Templates/Maya'


a pkg installer project will be coming soon

<b>Note:</b> Maya 2014 requires using the Mac 10.6 SDK (Snow Leopard). Xcode-4.3.3 is the latest compatible version which can use the 10.6 SDK. If using an older version and/or if you migrated to Mountain Lion, you will need to change the project settings to use the 10.7 SDK (Lion) to be able to compile.


2) Visual Studio Install
------------------------
- copy 'MayaAppWiz', 'MayaCommand', 'MayaNode' and 'MayaWizCommon' in a directory of your choice.
- copy '_Install/VC' into 'C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC' and/or 'C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC'
- edit the .vsz files you copied in the previous step and change:
   - [WIZVERSION] into 10.0 or 11.0 depending of the Visual Version you installed it into
   - [TARGETDIR] to the directory where you copied the wizards files

There is a wix/msi installer project included in case you want to get it installed for you. The installer will work for Maya 2014, Visual Studio 2010/12 Pro/Standard and Express editions. If you do not have Maya 2014 installed, you can either:
- remove the Maya 2014 check in property.wxi line #20,21
- or change the chack for Maya 2013 or older in property.wxi line #20,21
- or add a key in the registry at HKLM\Software\Autodesk\Maya\2014\Setup\InstallPath - MAYA_INSTALL_LOCATION

<b>Note:</b> Maya 2014 requires using the VC 10.0 Service Pack 1 runtime, if using Visual Studio 2012, do not forget to change the 'Platform Toolkit' to vc100

--------

## License

This sample is licensed under the terms of the [MIT License](http://opensource.org/licenses/MIT). Please see the [LICENSE](LICENSE) file for full details.


## Written by

Cyrille Fauvel (Autodesk Developer Network)  
http://www.autodesk.com/adn  
http://around-the-corner.typepad.com/  
