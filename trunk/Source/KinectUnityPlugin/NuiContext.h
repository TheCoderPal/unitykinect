/*
Class: NuiContext.h
*/

#pragma once

#include "stdafx.h"
#include "NuiApi.h"  //Microsoft Kinect NUI Aggregate Header
#include <assert.h>
#include <math.h>

class NuiContext
{
	public:
    HRESULT	Nui_Init();
    void Nui_UnInit( );
    void Nui_Zero();
		HRESULT SetCameraAngle(long llAngle);

		LONG mAngle;
		bool mbTwoPlayer;

	private:
		INuiSensor* mpSensor;
};