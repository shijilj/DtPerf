DTC_Wheel_Types()
{
	
	DTC_Home("DTC_Home");
	
	DTC_Home("DTC_Home");
	
	if(stricmp(lr_get_attrib_string("Bot"),"Yes")==0)
	{
		DTC_Home("DTC_Home_Bot");
		
		DTC_Home("DTC_Home_Bot");
	}
	
	//DTC_SearchStore("DTC_SearchStore");
	
	//DTC_MakeThisMyStore("DTC_MakeThisMyStore");
	
	if (rand_iter_num <=52)
	{
		DTC_Search_BySize("DTC_TC5_Click_WheelbySize","wheels");
		
		if (rand_iter_num <=29)
		{
		//	web_set_option("MaxRedirectionDepth", "0", LAST );
			
			DTC_Shop_Tires_or_Wheels("DTC_TC5_Click_ShopforWheels","wheels","boltPattern", lr_eval_string("{WheelBoltPattern}"), lr_eval_string("{WheelDiameter}"), lr_eval_string("{WheelWidth}"));
			
		//	web_set_option("MaxRedirectionDepth", "10", LAST );
		}
	}
	
	if (rand_iter_num <=69)
	{
		DTC_Search_ByBrand("DTC_TC5_Search_WheelBrand","wheels/brands","wheels");
		
		if (rand_iter_num <=65)		//make sure it's less than Searchbybrand or use for loop
		{
			DTC_Click_Brand("DTC_TC5_Click_WheelBrand","wheels/brands");
		}
	}
			
	for(i=1;i<=2;i++)
	{
		DTC_Tire_Wheel_Type("DTC_TC5_Wheel_Type");
	}
	
	if (rand_iter_num <=16)		
	{
		DTC_Tire_Wheel_Type("DTC_TC5_Wheel_Type");
	}
	
	return 0;
}
