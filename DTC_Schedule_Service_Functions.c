//Click Schedule service

DTC_Click_Schedule_Service(char *TxnName)
{

	web_reg_find("Search=Body","Text/IC=Schedule appointment","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_url("appointments", 
		"URL=https://{URL}/schedule-appointment", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t157.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CSRFToken}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

return 0;	
}

//select service and click next
DTC_Select_VehService(char *TxnName)
{
	
	web_reg_find("Search=Body","Text/IC=Discount Tire store","SaveCount=TextCheck",LAST);
	
	web_reg_save_param("AvailSlot","LB/IC=\"startTime\":\"", "RB/IC=:00.000Z\",\"endTime","ORD=All", LAST);
	
	//web_reg_save_param("AvailDay","LB/IC=utag_data[\"appointment_day\"] = \"", "RB/IC=\";","ORD=All", LAST);
	
	//web_reg_save_param("AvailMonth","LB/IC/ALNUMIC=utag_data[\"appointment_date\"] = \"", "RB/IC/ALNUMIC=/^^/20^^\";","ORD=All", LAST);
	
	web_reg_save_param("AvailDay","LB/IC=utag_data[\"appointment_placed_day\"] = \"", "RB/IC=\";","ORD=All", LAST);
	
	web_reg_save_param("AvailMonth","LB/IC/ALNUMIC=utag_data[\"appointment_placed\"] = \"", "RB/IC/ALNUMIC=/^^/20^^\";","ORD=All", LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_submit_data("services", 
		"Action=https://{URL}/schedule-appointment", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=serviceCodes", "Value={ServiceCode}", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=serviceCodes", "Value={ServiceCode}", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=_serviceCodes", "Value=on", ENDITEM, 
		//"Name=_serviceCodes", "Value=on", ENDITEM, 
		//"Name=_serviceCodes", "Value=on", ENDITEM, 
		//"Name=_serviceCodes", "Value=on", ENDITEM, 
		//"Name=_serviceCodes", "Value=on", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM,
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CSRFToken}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_PeakTimes("DTC_PeakTimes_Ajax");
	
	lr_think_time(Think_Time);

return 0;	
}

DTC_Select_ServiceDate(char *TxnName)
{
	
	lr_param_sprintf("SchApptDate", "Appointment Date: %s", lr_eval_string("{AppointDate}"));
	
//	web_reg_save_param("SlotTime","LB/IC=startTime\":", "RB/IC=:00\",\"endTime","ORD=All","NotFound=Warning", LAST);
	
	web_reg_save_param("SlotTime","LB/IC=startTime\":\"{AppointDate}T", "RB/IC=:00.000Z\",\"endTime","ORD=All","NotFound=Warning",LAST);

	web_reg_find("Search=Body","Text/IC=startTime","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=blackout\":false,\"name\":","SaveCount=TextCheck",LAST);
				
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	//https://stg.discounttire.com/schedule-appointment/getAvailableAppointmentSlots?appDate=10/19/2016&_=1476331148727
	web_url("getAvailableAppointmentSlots", 
	//	"URL=https://{URL}/schedule-appointment/getAvailableAppointmentSlots?appDate={AppointDate_URL}", 
		"URL=https://{URL}/schedule-appointment/isTimeSlotStillAvailable?appDate={AppointDate}&appTime={AppointTime}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{SchApptDate}")));
	
	lr_think_time(Think_Time);
	
	return 0;
}


//select Time and click next
DTC_Select_Time(char *TxnName)
{
/*	char AvailableSlot[25];
	char AvailTimeSlot[25];
	char Time1[25];
	
	char *token;
	char *Minutes;
	char separators[] = ":";	
	int Hours;
	
	lr_param_sprintf("RandSlotTime", "%s", lr_paramarr_random("SlotTime"));
	
	sprintf(AvailableSlot,"%s",lr_eval_string("{RandSlotTime}"));
	       
	token = (char *)strtok(AvailableSlot, separators);
	
	sprintf(AvailTimeSlot,"%s",lr_eval_string("{RandSlotTime}"));
	        
	Minutes = ((char *) strstr(AvailTimeSlot,":")+1);
	
	lr_output_message("Hours-%s, Minutes-%s",token,Minutes);
	if(atoi(token)>12)
	{
		Hours = atoi(token)-12;
		
		sprintf(Time1,"%d:%s PM",Hours,Minutes);
	}
	
	else if(atoi(token)==12)
	{
		sprintf(Time1,"%s:%s PM",token,Minutes);
	}
	
	else
	{
		sprintf(Time1,"%s:%s AM",token,Minutes);
	}
	
	lr_save_string(Time1,"AppointTime");	*/
	
/*	lr_param_sprintf("RandSlotTime", "%s", lr_paramarr_random("SlotTime"));
	
	lr_save_searched_string(lr_eval_string("{RandSlotTime}"),strlen(lr_eval_string("{RandSlotTime}")),0,"\"",11,5,"RandSlotTime1");
	
	lr_save_searched_string(lr_eval_string("{RandSlotTime}"),strlen(lr_eval_string("{RandSlotTime}")),0,"\"",11,2,"RandSlotTime2");
	
	lr_save_searched_string(lr_eval_string("{RandSlotTime}"),strlen(lr_eval_string("{RandSlotTime}")),0,"\"",13,3,"RandSlotTime3");
			
	Time1 = (atoi(lr_eval_string("{RandSlotTime2}"))) - 12;
	
	lr_output_message("%d",Time1);
	
	if(Time1 > 0)
	
	{
		lr_param_sprintf("AppointTime", "%d%s PM",Time1,lr_eval_string("{RandSlotTime3}"));
	}
	if(Time1 < 0)
	{
		lr_param_sprintf("AppointTime", "%s AM",lr_eval_string("{RandSlotTime1}"));
	}
	
	if(Time1 == 0)
	{
	lr_param_sprintf("AppointTime", "%s PM",lr_eval_string("{RandSlotTime1}"));
	}
*/		
//	web_reg_find("Search=Body","Text/IC=Enter your information","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=customer-info","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_submit_data("info", 
		"Action=https://{URL}/schedule-appointment/date?CSRFToken={CSRFToken}", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=appointmentDate", "Value={AppointDate}", ENDITEM, 
		"Name=appointmentTime", "Value={AppointTime}", ENDITEM, 
	//	"Name=appointmentDate", "Value={AppointDate_URL}", ENDITEM, 
	//	"Name=appointmentTime", "Value={AppointTime}", ENDITEM, 		
	//	"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{AppointTime}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_ActiveRegions("DTC_ActiveRegions_Ajax");
	
	lr_think_time(Think_Time);

return 0;	
}
