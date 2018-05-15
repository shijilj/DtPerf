DTC_Search_Promotions()
{
	
	DTC_Home("DTC_Home");
	
	
	if(stricmp(lr_get_attrib_string("Bot"),"Yes")==0)
	{
		DTC_Home("DTC_Home_Bot");
		
		DTC_Home("DTC_Home_Bot");
	}
	
	//DTC_SearchStore("DTC_SearchStore");

	//DTC_MakeThisMyStore("DTC_MakeThisMyStore");
	
	//for(i=1;i<=5;i++)
	//{
	
	/*if (rand_iter_num <= 48)
	{
		DTC_Search_AutoComplete("DTC_TC4_AutoComplete");
	
		if (rand_iter_num <= 46)
		{
			web_set_option("MaxRedirectionDepth", "0", LAST );
			
			DTC_Click_ProductLink("DTC_TC4_Click_ProductLink");
			
			web_set_option("MaxRedirectionDepth", "10", LAST );
		}
	}

	if (rand_iter_num <= 10)
	{
		DTC_Search_Product("DTC_TC4_FindProduct");
	}
	
	if (rand_iter_num <= 5)
	{
		
	 	DTC_ViewPromotions("DTC_TC4_ViewPromotions");
		 
		for(i=1;i<=23;i++)
		{
           	DTC_SelectPromotions("DTC_TC4_SelectPromotions");
         
        // DTC_SelectPromotions_thanksgiving("DTC_TC4_SelectPromotions_ThanksGiving");
		}
	}*/
	
	if (rand_iter_num <= 97)
	{
		DTC_Search_AutoComplete("DTC_TC4_AutoComplete");
	
		if (rand_iter_num <= 91)
		{
			web_set_option("MaxRedirectionDepth", "0", LAST );
			
			DTC_Click_ProductLink("DTC_TC4_Click_ProductLink");
			
			web_set_option("MaxRedirectionDepth", "10", LAST );
		}
	}

	if (rand_iter_num <= 20)
	{
		DTC_Search_Product("DTC_TC4_FindProduct");
	}
	
	if (rand_iter_num <= 11)
	{
		
	 	DTC_ViewPromotions("DTC_TC4_ViewPromotions");
		 
		for(i=1;i<=23;i++)
		{
           	DTC_SelectPromotions("DTC_TC4_SelectPromotions");
         
        // DTC_SelectPromotions_thanksgiving("DTC_TC4_SelectPromotions_ThanksGiving");
		}
	}
	return 0;
}
