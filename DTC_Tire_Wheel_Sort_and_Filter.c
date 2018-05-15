DTC_Tire_Wheel_Sort_and_Filter()
{
	DTC_Home("DTC_Home");
	
	DTC_Home("DTC_Home");
	
	lr_save_string("0","BrandFilter_count");
	lr_save_string("0","FilterApplied");
	
//	if(stricmp(lr_get_attrib_string("Bot"),"Yes")==0)
	if(stricmp(Bot,"Yes")==0)
	{
		DTC_Home("DTC_Home_Bot");
		
		DTC_Home("DTC_Home_Bot");
	}

	//DTC_SearchStore("DTC_SearchStore");
	
	//DTC_MakeThisMyStore("DTC_MakeThisMyStore");
	
	if (rand_iter_num <= 37)
	{
		DTC_Select_Vehicle("DTC_Select_Vehicle", lr_eval_string("{Year1}"), lr_eval_string("{Make1}"), lr_eval_string("{Model1}"), lr_eval_string("{Trim1}"));
	
		DTC_Shop_for_Vehicle("DTC_Click_ShopformyVehicle");
	}
	
	//rand_iter_num <= 30)	 -- Original Load Model before Recommendation Functionality
	//rand_iter_num <= 15)	 -- Recommendations Functionality
	if (rand_iter_num <= 30)
	{
		DTC_Search("DTC_Click_Tires","tires");
		
		if(atoi(lr_eval_string("{BrandAllFilter_count}"))>=1)
		{
			DTC_Filter_Brand("DTC_TC6_Tire_FilterbyBrand", "tires?q=%3AbestSeller-asc%3Abrands%3A{RandBrandFilter}&text=", "tires");
			
			if(atoi(lr_eval_string("{PriceMin}"))>=1 && atoi(lr_eval_string("{PriceMax}"))>=1)
			{
			//	DTC_Filter_Price("DTC_TC6_Tire_FilterbyPrice","tires?q=%3AbestSeller-asc%3Abrands%3A{RandBrandFilter}%3Aprice%3A{ConRandPriceFilter}&text=&{ConRandPriceFilter}=on");
				DTC_Filter_Price("DTC_TC6_Tire_FilterbyPrice","tires?q=%3AbestSeller-asc%3Abrands%3A{RandBrandFilter}%3ApriceValue%3A%5B","tires");
			}
			
			lr_save_string("0","BrandAllFilter_count");
		}
			
		if(atoi(lr_eval_string("{FilterApplied}"))>=1 )
		{   		
			DTC_Clear_Filter("DTC_TC6_Tire_Clear_Filter","tires","Yes");
			lr_save_string("0","FilterApplied");
		}
		
		DTC_Sort_Rating("DTC_TC6_Tire_SortbyRating","tires?sort=allVehiclesRating-desc&q=%3AbestSeller-asc");
					
	}
	
/*	if (rand_iter_num >15 && rand_iter_num <= 30 ) // Add rand_iter_num == 1 with OR condition to run in vugen 
	{
		DTC_Search_Recommendation("DTC_TC6_Click_Tires_Recomm_Link");
		
		DTC_View_Recommendation("DTC_TC6_View_Tires_Recomm","tires");
		
		if(atoi(lr_eval_string("{BrandAllFilter_count}"))>=1)
		{
			DTC_Filter_Brand("DTC_TC6_Tire_FilterbyBrand", "tires?q=%3Arelevance%3Arecommendation-boolean%3ARecommendation%3Abrands%3A{RandBrandFilter}&text=", "tires");
			
			if(atoi(lr_eval_string("{PriceMin}"))>=1 && atoi(lr_eval_string("{PriceMax}"))>=1)
			{
				DTC_Filter_Price("DTC_TC6_Tire_FilterbyPrice","tires?q=%3Arelevance%3Arecommendation-boolean%3ARecommendation%3Abrands%3A{RandBrandFilter}%3ApriceValue%3A%5B","tires");
			}
			
			lr_save_string("0","BrandAllFilter_count");
		}
			
		if(atoi(lr_eval_string("{FilterApplied}"))>=1 )
		{   		
			DTC_Clear_Filter("DTC_TC6_Tire_Clear_Filter","tires","Yes");
			lr_save_string("0","FilterApplied");
		}
		
		DTC_Sort_Rating("DTC_TC6_Tire_SortbyRating","tires?sort=allVehiclesRating-desc&q=%3Arelevance#");
	}
*/	
		
	if(atoi(lr_eval_string("{ProductCode_count}"))>=3)
	{
		DTC_Compare("DTC_TC6_Click_Tire_Compare","Tire");
	}
	
	if(rand_iter_num <= 13 && atoi(lr_eval_string("{ProductCode_count}"))>=3)
	{
		DTC_Compare("DTC_TC6_Click_Tire_Compare","Tire");
	}
		
		
	if(rand_iter_num <= 15)   //make sure this rand number is always less than shopforvehicle
	{
		DTC_Search("DTC_Click_Wheels","wheels");
						
		if(atoi(lr_eval_string("{BrandAllFilter_count}"))>=1)
		{
			DTC_Filter_Brand("DTC_TC6_Wheel_FilterbyBrand","wheels?q=%3Arelevance%3Abrands%3A{RandBrandFilter}&text=","wheels");
			
			if(atoi(lr_eval_string("{PriceMin}"))>=1 && atoi(lr_eval_string("{PriceMax}"))>=1)
			{
			//	DTC_Filter_Price("DTC_TC6_Wheel_FilterbyPrice","wheels?q=%3Arelevance%3Abrands%3A{RandBrandFilter}%3Aprice%3A{ConRandPriceFilter}&text=&{ConRandPriceFilter}=on");
				DTC_Filter_Price("DTC_TC6_Wheel_FilterbyPrice","wheels?q=%3Arelevance%3Abrands%3A{RandBrandFilter}%3ApriceValue%3A%5B","wheels");
			}
		
		}
		
		if(atoi(lr_eval_string("{FilterApplied}"))>=1 )
		{   		
			DTC_Clear_Filter("DTC_TC6_Clear_Wheel_Filter","wheels","No");	
			lr_save_string("0","FilterApplied");
		}
		
		DTC_Sort_BestSeller("DTC_TC6_Wheel_SortbyBestSeller","wheels?sort=bestSeller-asc&q=%3Arelevance");
		
	}
			
//	if(atoi(lr_eval_string("{ProductCode_count}"))>=3)
//	{
//		DTC_Compare("DTC_TC6_Wheel_Click_Compare","WHEEL");
//	}

	
	return 0;
}

