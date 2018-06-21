#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//#include "C:\\Users\\sjanardhan\\Documents\\Hybris\\Scripts\\Sourcedata\\attributes.h"
#include "attributes.h"
#include "dataParameters.h"

//--------------------------------------------------------------------
// Global Variables
int MaxPriceVal,MinPriceVal;
int randmaxnum,randminnum;

int i;
int Think_Time=5;
int randval=0;
long file,file1;
int rand_iter_num;
float f;
int id, scid;
char *vuser_group;

char Length[25],Length1[30];
//char * filename1="F:\\TextFiles_For_Execution\\Hybris_DTC_Order_Number_{TodayDate}.txt";

save_params(char *src, char *lb, char *rb, char *paramName)
{
		char *s1,*s2;
		int len, count = 0, i, j;
		char s3[500];
		char fullParamName[512], paramCountStr[30];
        s1 = src;
		len = strlen(lb);
		while(s1 = (char *) strstr(s1,lb))
		{
			s1 += len;
			s2 = (char *)strstr(s1,rb);
			j = (int)(s2 - s1);
			for (i=0;i<j;i++) {s3[i] = s1[i];}
			s3[i] = 0;
			count++;
			sprintf(fullParamName,"%s_%d",paramName,count);
			lr_save_string(s3,fullParamName);
			s1 += 1;
		}

		sprintf(fullParamName,"%s_count",paramName);
		sprintf(paramCountStr,"%d",count);
        lr_save_string(paramCountStr,fullParamName);
        return 0;
}

PeakTime_MonthDay()
{
	if(atoi(lr_eval_string("{AvailMonth_1}"))==01)
		lr_save_string(("Jan"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==02)
		 lr_save_string(("Feb"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==03)
		 lr_save_string(("Mar"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==04)
		 lr_save_string(("Apr"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==05)
		 lr_save_string(("May"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==06)
		 lr_save_string(("Jun"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==07)
		 lr_save_string(("Jul"),"c_monthAjax");
//	if(atoi(lr_eval_string("{AvailMonth_1}"))==08)
//		 lr_save_string(("Aug"),"c_monthAjax");
//	if(atoi(lr_eval_string("{AvailMonth_1}"))==09)
//		 lr_save_string(("Sep"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==10)
		 lr_save_string(("Oct"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==11)
		 lr_save_string(("Nov"),"c_monthAjax");
	if(atoi(lr_eval_string("{AvailMonth_1}"))==12)
		 lr_save_string(("Dec"),"c_monthAjax");
	
	
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Monday")==0)
		lr_save_string(("Mon"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Tuesday")==0)
		lr_save_string(("Tue"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Wednesday")==0)
		lr_save_string(("Wed"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Thursday")==0)
		lr_save_string(("Thu"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Friday")==0)
		lr_save_string(("Fri"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Saturday")==0)
		lr_save_string(("Sat"),"c_dayAjax");
	if(strcmp(lr_eval_string("{AvailDay_1}"),"Sunday")==0)
		lr_save_string(("Sun"),"c_dayAjax");
	
	return 0;
	
}

#endif // _GLOBALS_H
