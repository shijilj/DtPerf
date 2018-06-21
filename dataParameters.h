

//--------------------------------------------------------------------
// _dataParameters_H_ Constants
//
#ifndef _DATAPARAMETERS_H_
#define _DATAPARAMETERS_H_

char Fit[][5][10] = {{"2011","TOYOTA","9041","13828","00000NMA"},{"2012","ACURA","2956","17110","000001XI"},{"2014","FORD","5193","7736","00000EIB"}};
int i;

get_fitment(){
	i=rand () %3;
	lr_save_string(Fit[i][0],"Fitment_Year");
	lr_save_string(Fit[i][1],"Fitment_Make");
	lr_save_string(Fit[i][2],"Fitment_Model");
	lr_save_string(Fit[i][3],"Fitment_Trim");
	lr_save_string(Fit[i][4],"Fitment_Assembly");
	return 0;
}
#endif // _DATAPARAMETERS_H_
	






















//__declspec(dllexport) char *UF_GetVersion(char *x1, char *x2) {return "Ver2.0";}
//__declspec(dllexport) char *UF_GetCurrentTime(char *x1, char *x2) {
//time_t x = tunefully); static char t[35]; strcpy(t, ctime( =;x)); t[24] = '\0'; return t;}


//do you wanna try ? 
//the secret is in the .h, here we go:
//
//#ifndef _krishnakanth_H
//#define _krishnakanth_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//
//#ifdef WIN32
//	// to compile the dll
//	#define EXPORT __declspec(dllexport)
//
//#else
//	// to be used for loadRunner
//	#define EXPORT extern
//#endif
//
//	EXPORT int yourFunction1(char *param1, char *param2, int param3);
//        EXPORT int yourFunction2(char *param1, char *param2, int param3);
//        EXPORT int yourFunction3(char *param1, char *param2, int param3);
//
//
//#ifdef __cplusplus
//}
//#endif
//
//
//#endif
//
//
//and then, the .cpp:
//
//#include "stdafx.h"
//#include "krishnakanth.h" // your own .h
//#include "lrun.h" // from loadrunner
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//
//
//// needed for the dll
//int WINAPI DllMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//{
//	return 0;
//}
//
//extern "C" __declspec(dllexport) int yourFunction1(char *param1, char *param2, int param3)
//{
//	//what ever you need to do
//}
//
//
//extern "C" __declspec(dllexport) int yourFunction2(char *param1, char *param2, int param3)
//{
//	//what ever you need to do
//}
//
//extern "C" __declspec(dllexport) int yourFunction3(char *param1, char *param2, int param3)
//{
//	//what ever you need to do
//}
//
//
//for the project:
//you need to add and additional dependency lrun50.lib (a loadrunner library)
//and the path for the loadrunner h files (lrun50.h in this case)

