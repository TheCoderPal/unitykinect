/*
	Description: 
*/

using System;

using System.Runtime.InteropServices;


namespace Assets.Kinect.Scripts
{
	//interfaces with DLL
	public class KinectWrapper
	{

		//const string msKinectUnityDLL = "..\\..\\..\\Source\\KinectUnityPlugin\\Debug\\KinectUnityPlugin.dll";
		const string msKinectUnityDLL = @"F:\Ficheros\UnityKinect\Source\KinectUnityPlugin\Debug\KinectUnityPlugin.dll";


		//NUI Context Management
		[DllImport(msKinectUnityDLL, CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
		public static extern bool NuiContextInit(bool twoPlayer);
		[DllImport(msKinectUnityDLL)]
		public static extern void NuiUpdate();
		[DllImport(msKinectUnityDLL)]
		public static extern void NuiContextUnInit();


		//Camera
		[DllImport(msKinectUnityDLL, CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
		public static extern void GetCameraAngle(ref float lpfAngle);  
		[DllImport(msKinectUnityDLL, CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
		public static extern bool SetCameraAngle(int liAngle);


		//Test
		[DllImport(msKinectUnityDLL)]
		public static extern int GetANumber();
		[DllImport(msKinectUnityDLL)]
		public static extern IntPtr GetAString();

	}
}