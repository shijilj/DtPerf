DTC_WebOrder_Tires()
{
		
	DTC_Home("DTC_Home");
	
	DTC_Home("DTC_Home");
	
	if(stricmp(lr_get_attrib_string("Bot"),"Yes")==0)
	{
		DTC_Home("DTC_Home_Bot");
		
		DTC_Home("DTC_Home_Bot");
	}
	
	/*if(stricmp(lr_get_attrib_string("URLStatus"),"STG")==0 && strlen(lr_eval_string("{StoreName}"))<=0)
	{

		//DTC_SearchStore("DTC_SearchStore");
	
		//DTC_MakeThisMyStore("DTC_MakeThisMyStore");
	
	}*/
	
	DTC_Select_Vehicle("DTC_Select_Vehicle", lr_eval_string("{Year}"), lr_eval_string("{Make}"), lr_eval_string("{Model}"), lr_eval_string("{Trim}"));	
	
	DTC_Shop_for_Vehicle("DTC_Click_ShopformyVehicle");
	
	if (rand_iter_num <= 21)
	{
		DTC_Select_Vehicle("DTC_Select_Vehicle", lr_eval_string("{Year}"), lr_eval_string("{Make}"), lr_eval_string("{Model}"), lr_eval_string("{Trim}"));	
	
		DTC_Shop_for_Vehicle("DTC_Click_ShopformyVehicle");
	}
	
	if (rand_iter_num <= 98)
	{
		DTC_Search("DTC_Click_Tires","tires");
		
		if(atoi(lr_eval_string("{InStock_Count}"))>0)
		{
			//DTC_Filter_InStock("DTC_Tire_Filter_InStock","tires?q=%3Aprice-asc%3AinventoryStatus-boolean%3Atrue&text=&true=on");
			DTC_Filter_InStock("DTC_Tire_Filter_InStock","tires?q=%3AbestSeller-asc%3AinventoryStatus-boolean%3Atrue&text=");
		}
		
		web_set_option("MaxRedirectionDepth", "0", LAST );
	
		DTC_Click_Product("DTC_TC1_Click_Tire_Product","tires");
									
		web_set_option("MaxRedirectionDepth", "10", LAST );			
		
		if (rand_iter_num <= 15)
		{
			DTC_Legacy_PDP("DTC_TC1_Legacy_PDP");
		}
		
	//	DTC_Check_Inventory("DTC_TC1_Click_Check_Inventory");
			
	//	DTC_Update_SeletedStore("DTC_TC1_Update_SelectedStore");
			
		
		if (rand_iter_num <= 26)
		{
			DTC_AddtoCart("DTC_TC1_AddtoCart_Tire","tires");
			
			DTC_View_Cart("DTC_TC1_ViewCart");
		}
	
		if (rand_iter_num <= 13)
		{
			DTC_Search("DTC_Click_Wheels","wheels");
			
			if(atoi(lr_eval_string("{InStock_Count}"))>0)
			{
				DTC_Filter_InStock("DTC_Wheel_Filter_InStock","wheels?q=%3Arelevance%3AinventoryStatus-boolean%3Atrue&text=");
			}
		
			for(i=1;i<=4;i++)
			{
				web_set_option("MaxRedirectionDepth", "0", LAST );
		
				DTC_Click_Product("DTC_TC1_Click_Wheel_Product","wheels");
						
				web_set_option("MaxRedirectionDepth", "10", LAST );
			}
			
			DTC_AddtoCart("DTC_TC1_AddtoCart_Wheel","wheels");
			
			for(i=1;i<=2;i++)
			{
				DTC_View_Cart("DTC_TC1_ViewCart");
			}
											
			DTC_Remove_Product("DTC_TC1_Remove_Product");
			
		//	DTC_Remove_Product("DTC_TC1_Remove_Product");
		}
	}
	
		
				
	if(strlen(lr_eval_string("{ChildProdCode}"))>0 && rand_iter_num <= 5)		//make sure it's always less than Tires AddtoCart
	{
		DTC_Add_Certificate("DTC_TC1_Add_Certificate");
	}
	
	
	if (rand_iter_num <= 10)
	{
		DTC_Checkout_With_Appointment("DTC_TC1_Checkout_With_Appointment");
	}
	
	//if(atoi(lr_eval_string("{AvailSlot_Count}"))==0)
		//{
			if (rand_iter_num <= 8)
			{
				DTC_Select_Date("DTC_Select_Date");
				
				DTC_ZipcodeInfo("DTC_ZipcodeInfo_Ajax");
				
				DTC_Customer_Information_WA("DTC_TC1_Customer_Information_WA");
				
				if (rand_iter_num <= 7)
				{
					DTC_Schedule_Appointment("DTC_Schedule_Appointment");
				}
			}
		//}
	
	
	
	if((stricmp(lr_get_attrib_string("TestType"),"BVT")==0))
	{
		//DTC_Schedule_Appointment("DTC_Schedule_Appointment");
	}
	
	return 0;
}
