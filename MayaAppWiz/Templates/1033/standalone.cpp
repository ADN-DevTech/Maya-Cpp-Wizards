//
//  Copyright 2012 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//

//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

#include <maya/MLibrary.h>

//-----------------------------------------------------------------------------
[!if APP_STANDALONE_EXE]
int _tmain (int argc, TCHAR **argv) {
	MStatus status =MLibrary::initialize (true, argv [0], true) ;
	if ( !status ) {
		status.perror ("MLibrary::initialize") ;
		return (1) ;
	}
	
	//- Example: Write the text out in 3 different ways.
	cout << "Hello World! (cout)\n" ;
	MGlobal::displayInfo ("Hello world! (script output)") ;
	MGlobal::executeCommand ("print \"Hello world! (command script output)\\n\"", true) ;

	MLibrary::cleanup () ;
	return (0) ;
}
[!else]
BOOL APIENTRY DllMain (HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	MStatus status ;
	switch ( ul_reason_for_call ) {
		case DLL_PROCESS_ATTACH:
			status =MLibrary::initialize (true, "MyApp", true) ;
			if ( !status )
				return (FALSE) ;
			break ;
		case DLL_PROCESS_DETACH:
			MLibrary::cleanup () ;
			break ;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			//- do nothing here
			break ;
	}

	return (TRUE) ;
}
[!endif]
