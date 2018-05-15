DTC_Schedule_Service()
{
	
	DTC_Home("DTC_Home");
	
	DTC_Home("DTC_Home");
	
	if(stricmp(lr_get_attrib_string("Bot"),"Yes")==0)
	{
		DTC_Home("DTC_Home_Bot");
		
		DTC_Home("DTC_Home_Bot");
	}
	
//	DTC_SearchStore("DTC_SearchStore");

//	DTC_MakeThisMyStore("DTC_MakeThisMyStore");
	
	/* Commented as DTC_TC3_SelectTime failing.
	if (rand_iter_num<=53)
	{
		DTC_Click_Schedule_Service("DTC_TC3_Click_ScheduleService");
		
		if (rand_iter_num<=30)
		{
			DTC_Select_VehService("DTC_TC3_SelectService");
		}
		
		DTC_Select_ServiceDate("DTC_Select_Date");
		
		DTC_Select_Time("DTC_TC3_SelectTime");
	}
	*/
	
	if (rand_iter_num<=53)
	{
		DTC_Click_Schedule_Service("DTC_TC3_Click_ScheduleService");		
		
		DTC_Select_VehService("DTC_TC3_SelectService");		
		
	//	DTC_Select_ServiceDate("DTC_Select_Date");
		
		if(atoi(lr_eval_string("{AvailSlot_count}"))>0)
		{
	//		DTC_Select_Time("DTC_TC3_SelectTime");
			DTC_Select_Date("DTC_Select_Date");
			DTC_Select_Time("DTC_TC3_ServiceCustInfo");
		}
		
		
	}
		
	//DTC_Schedule_Appointment("DTC_Schedule_Appointment");

	return 0;
}
