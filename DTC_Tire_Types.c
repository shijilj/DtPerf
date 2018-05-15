DTC_Tire_Types()
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
	
//	web_set_option("MaxRedirectionDepth", "0", LAST );
		
	for (i=1;i<=2;i++)		//to make up for total load
	{
		DTC_Search_BySize("DTC_TC2_Click_TirebySize","tires");
		
		if (rand_iter_num <=89)
		{
			DTC_Shop_Tires_or_Wheels("DTC_TC2_Click_ShopforTires","tires","aspectRatio", lr_eval_string("{TireAspectRatio}"), lr_eval_string("{TireDiameter}"), lr_eval_string("{TireWidth}"));
		}
	}
		
//	web_set_option("MaxRedirectionDepth", "10", LAST );
	
	DTC_Search_ByBrand("DTC_TC2_Search_TireBrand","tires/brands","tire");
	
	if (rand_iter_num <=14)
	{
		DTC_Search_ByBrand("DTC_TC2_Search_TireBrand","tires/brands","tire");
	}
		
	DTC_Click_Brand("DTC_TC2_Click_TireBrand","tires/brands");
		
	if (rand_iter_num <=41)
	{
		DTC_Click_Brand("DTC_TC2_Click_TireBrand","tires/brands");	//to make up for total load
	}
	
	DTC_Tire_Wheel_Type("DTC_TC2_Tire_Type");
	
	if (rand_iter_num <=34)
	{
		DTC_Tire_Wheel_Type("DTC_TC2_Tire_Type");
	}
	
	return 0;
}
