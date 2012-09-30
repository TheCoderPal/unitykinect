/*
	Description: 
*/

#include "stdafx.h"
#include "KinectUnityPlugin.h"  //DLL export declarations
#include "NuiContext.h"      //NUI object

NuiContext gNuiContext;

/************************************************************************
						NUI CONTEXT MANAGEMENT
************************************************************************/

//Initializes NUI Context
bool NuiContextInit(bool mbTwoPlayer) 
{
	HRESULT lHR;

	lHR = gNuiContext.Nui_Init();
	gNuiContext.mbTwoPlayer = mbTwoPlayer;

	if (FAILED(lHR))
		return false;
	else
		return true;
}


//Updates Skeleton, Image Data
void NuiUpdate() 
{
	
}


//Closes NUI Context
void NuiContextUnInit() 
{
	gNuiContext.Nui_UnInit();
}


/************************************************************************
						Cameras
************************************************************************/

//Gets current camera angle
void GetCameraAngle(OUT float* lpfAngle) 
{

	*lpfAngle = (float)gNuiContext.mAngle;
}


bool SetCameraAngle(int liAngle) 
{

	HRESULT lHR;
	
	if (liAngle >= -27 && liAngle <= 27) 
	{
		lHR = gNuiContext.SetCameraAngle((long)liAngle);
		if (FAILED(lHR)) 
		{
			return false;
		} 
		else 
		{
			gNuiContext.mAngle = (long)liAngle;
			return true;
		}
	} 
	else 
		return false;
	
}



/************************************************************************
						Examples
************************************************************************/
int GetANumber()
{
	return 1;
}

char* GetAString()
{
	char* lsTemp = "Hello World";

	return lsTemp;
}

