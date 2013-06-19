//
//  Copyright 2012 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//

//-----------------------------------------------------------------------------
//- StdAfx.h : include file for standard system include files,
//-      or project specific include files that are used frequently,
//-      but are changed infrequently
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
//----- This file is preprocessor symbol driven.
//----- Define:
//----- _PYTHON_MODULE_ to include and import Python headers and libs in your project.
//#define _PYTHON_MODULE_
//----- _MAYA_QT_ to include and import Maya QT headers and libs in your project.
//#define _MAYA_QT_
//----- _MAYA_VP2_ to include and import Maya Viewport 2.0 headers and libs in your project.
//#define _MAYA_VP2_

#include "mayaHeaders.h"
#ifdef NT_PLUGIN
#include <tchar.h>
#else
#define _T(a) a
#endif

//-----------------------------------------------------------------------------
//----- If you need MFnPlugin definition more than once
//- MNoVersionString is needed on MacOS and Linux to avoid multiple MApiVersion definition
//#define MNoVersionString
//- MNoPluginEntry is needed on Windows platform to avoid multiple DllMain definition
//#define MNoPluginEntry
//#include <maya/MFnPlugin.h>
