
#include "stdafx.h"
#include "NuiContext.h"

//Zeroes members of context object
void NuiContext::Nui_Zero()
{
	mpSensor = NULL;
	
}


//Initializes Sensor for Polling
HRESULT NuiContext::Nui_Init()
{
  HRESULT lHR;
	int liSensorCount;

	NuiGetSensorCount(&liSensorCount);
	if (!mpSensor) 
	{
		Nui_Zero();
		lHR = NuiCreateSensorByIndex(0, &mpSensor);
		lHR = mpSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON|NUI_INITIALIZE_FLAG_USES_COLOR|NUI_INITIALIZE_FLAG_USES_DEPTH);
		if( FAILED( lHR ) )
		{
			return lHR;
		}
	} 
	else 
	{
		lHR = 1;
	}

	

  return lHR;
}


//Stops Sensor Polling
void NuiContext::Nui_UnInit()
{
  mpSensor->NuiShutdown();
	mpSensor->Release();
	mpSensor = NULL;

}



//Set camera angle
HRESULT NuiContext::SetCameraAngle(long llAngle) 
{

	return mpSensor->NuiCameraElevationSetAngle(llAngle);
}

