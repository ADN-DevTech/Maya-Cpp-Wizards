@echo off
%~d0
cd /d %~dp0

if exist w:\nul subst w: /d
subst w: "C:\Program Files (x86)\WiX Toolset v3.8"

w:\bin\candle.exe MayaCppWizards.wxs -out temp\MayaCppWizards.wixobj
w:\bin\light.exe -sw1076 -b .. temp\MayaCppWizards.wixobj -out MayaCppWizards.msi 
rem -ext WixUIExtension
if exist MayaCppWizards-2014.zip del MayaCppWizards-2014.zip > nul
"C:\Program Files\WinRAR\WinRAR.exe" a MayaCppWizards-2014.zip MayaCppWizards.msi > nul

pause