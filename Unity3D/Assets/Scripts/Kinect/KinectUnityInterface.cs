/*
 Description: 
 
*/
using System;
using UnityEngine;
using System.Collections;

using System.Runtime.InteropServices;
using Assets.Kinect.Scripts;



public class KinectUnityInterface : MonoBehaviour 
{
	public static KinectUnityInterface SP; //Singleton

	public bool mbTwoPlayer = false;

	private float mfLastCameraAngleChange = -30.0f;
	private bool NUIisReady = false;


	/*****************************************
	 Unity3D Methods
	 **************************************/

	// Use this for initialization
	void Start () 
	{
		//Tests();
		SP = this;

		NUIisReady = false;
		NUIisReady = KinectWrapper.NuiContextInit(mbTwoPlayer); //initialize Kinect sensor

		//display messages
		if (NUIisReady)
			Debug.Log("Sensor Initialized.");
		else
			Debug.Log("Could Not Initialize Sensor.");

		KinectWrapper.SetCameraAngle(-20);

	}
	
	// Update is called once per frame
	void Update () 
	{
	
	}

	/*****************************************
	 User Methods
	 **************************************/

	// returns current Kinect camera angle from horizontal
	public float GetCameraAngle()
	{
		float lfCameraAngle = 0;

		KinectWrapper.GetCameraAngle(ref lfCameraAngle);
		return (lfCameraAngle);
	}

	public bool SetCameraAngle(int liAngle)
	{

		/* DO NOT CHANGE CAMERA ANGLE MORE OFTEN THAN ONCE
		 * EVERY 30 SECONDS, IT COULD DAMAGE THE KINECT
		 * SENSOR (SEE KINECT SDK DOCUMENTATION).
		 */

		if (Time.time - mfLastCameraAngleChange > 30)
		{
			mfLastCameraAngleChange = Time.time;
			return (KinectWrapper.SetCameraAngle(liAngle));
		}
		else
		{
			return (false);
		}
	}

	/*****************************************
	 Tests
	 **************************************/
	private void Tests()
	{
		int liTest = KinectWrapper.GetANumber();
		print (liTest);

		IntPtr mpString = KinectWrapper.GetAString();
		string lsTest = Marshal.PtrToStringAnsi(mpString);
		print(lsTest);

	}


}




