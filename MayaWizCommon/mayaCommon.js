//- Copyright (c) Autodesk, Inc. All rights reserved.
//- by Cyrille Fauvel - Autodesk Developer Technical Services
var szWizardsVersion ="10, 0, 0, 0 - September 27th, 2009" ;

var szMayaWizApplicationTitle ="Maya plug-in/standalone Application Wizard" ;
var szMayaCommandTitle ="Maya Custom Command Wizard" ;
var szMayaCustomNodeTitle ="Maya Custom Node Wizard" ;

//wizard.OkCancelAlert ("msg");

//- Get an AutoCAD release
//- http://msdn.microsoft.com/en-us/library/aa393067(VS.85).aspx
//- http://msdn.microsoft.com/en-us/library/aa394616(VS.85).aspx
/* class Win32_Product : CIM_Product {
    uint16 AssignmentType;
    string Caption;
    string Description;
    string IdentifyingNumber;
    string InstallDate;
    datetime InstallDate2;
    string InstallLocation;
    sint16 InstallState;
    string HelpLink;
    string HelpTelephone;
    string InstallSource;
    string Language;
    string LocalPackage;
    string Name;
    string PackageCache;
    string PackageCode;
    string PackageName;
    string ProductID;
    string PackageName;
    string RegOwner;
    string RegCompany;
    string SKUNumber;
    string Transforms;
    string URLInfoAbout;
    string URLUpdateInfo;
    string Vendor;
    uint32 WordCount;
    string Version;
   } ;*/
function FindMaya() {
    var szPath = FindAutoCADUsingWMI("c:\\Program Files\\Autodesk\\Maya2011\\");
    return (szPath);
}

//- This one fails on Vista
function FindMayaUsingRegistryAndWScriptShell(szPath) {
    var regkey = new ActiveXObject('WScript.Shell');
    var strAcadVersion = '18.0';
    var strAcad = 'ACAD:8001-409';
    var strPath = szPath;
    try {
        strAcadVersion = regkey.RegRead('HKEY_CURRENT_USER\\SOFTWARE\\Autodesk\\AutoCAD\\CurVer');
        strAcad = regkey.RegRead('HKEY_CURRENT_USER\\SOFTWARE\\Autodesk\\AutoCAD\\' + strAcadVersion + '\\CurVer');
        //- This line fails on Vista
        strPath = regkey.RegRead('HKEY_LOCAL_MACHINE\\SOFTWARE\\Autodesk\\AutoCAD\\' + strAcadVersion + '\\' + strAcad + '\\AcadLocation');
    } catch (e) {
        strPath = szPath;
    }
    return (strPath);
}

function FindMayaUsingRegistryAndWMI(szPath) {
    var HKCU = 0x80000001;
    var HKLM = 0x80000002;
    var objWMIService = GetObject("winmgmts:{impersonationLevel=impersonate}!\\\\.\\root\\default:StdRegProv");
    //- Does not work GetStringValue requires passing strPath by reference, which does not work in javascript
    var strPath = szPath;
    objWMIService.GetStringValue(HKCU, 'SOFTWARE\\Autodesk\\AutoCAD', 'CurVer', strPath)
    //etc...
    return (strPath);
}

function FindMayaUsingWMI(szPath) {
    var szVersion = "1";
    var acadId = "{5783F2D7-%-%-0102-0060B0CE6BBA}";
    var objWMIService = GetObject("winmgmts:{impersonationLevel=impersonate}!\\\\.\\root\\cimv2");
    //var objWMIService = GetObject("winmgmts:{impersonationLevel=impersonate}!\\\\.\\root\\default:StdRegProv");
    //- Not possible to use 'ORDER BY Version DESC' :(
    //- To improve performance use WBEM_FLAG_RETURN_IMMEDIATE | WBEM_FLAG_FORWARD_ONLY in ExecQuery ( = 48 )
    //- http://discuss.itacumens.com/index.php/topic,65447.0.html
    var colSoftware = objWMIService.ExecQuery("Select Version, InstallLocation from Win32_Product Where IdentifyingNumber like '" + acadId + "' AND Vendor = 'Autodesk'", "WQL", 48);
    var enumItems = new Enumerator(colSoftware);
    for (; !enumItems.atEnd(); enumItems.moveNext()) {
        var objItem = enumItems.item();
        if (objItem.Version > szVersion) {
            szPath = objItem.InstallLocation;
            szVersion = objItem.Version;
        }
    }
    return (szPath);
}

//- Calling Wizard's help
function InvokeWizardHelp () {
	var myUrl =window.external.FindSymbol("ABSOLUTE_PATH") ;
	var myName =window.external.FindSymbol("WIZARD_NAME") ;
	myUrl =myUrl.substring (0, myUrl.lastIndexOf ("\\") + 1) ;
	open ("ms-its:" + myUrl + "MayaWizardHelp.chm::HTML/" + myName + ".htm") ;
}
