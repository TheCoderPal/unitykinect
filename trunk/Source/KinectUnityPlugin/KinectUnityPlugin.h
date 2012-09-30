/*
	Description: DLL Principal Class
*/

#pragma once

#include "stdafx.h"
#include <string>

#ifndef KINECTUNITYPLUGIN_API
	#define KINECTUNITYPLUGIN_API extern "C" __declspec(dllexport)
#endif




//Nui Context Management
KINECTUNITYPLUGIN_API bool NuiContextInit(bool mbTwoPlayer);
KINECTUNITYPLUGIN_API void NuiUpdate();
KINECTUNITYPLUGIN_API void NuiContextUnInit();

//Camera
KINECTUNITYPLUGIN_API void GetCameraAngle(OUT float* lpfAngle);
KINECTUNITYPLUGIN_API bool SetCameraAngle(int liAngle);



//Test
KINECTUNITYPLUGIN_API int GetANumber();
KINECTUNITYPLUGIN_API char* GetAString();
