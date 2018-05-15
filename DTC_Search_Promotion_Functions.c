// Search Product using a keyword

DTC_Search_AutoComplete(char *TxnName)
{
				
	//web_reg_find("Search=Body","Text/IC=suggestions","SaveCount=TextCheck",LAST);
	
	//{"categoryList":[{"code
	
	//web_reg_find("Search=Body","Text/IC={\"categoryList\":[{\"code","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=\"categoryList\":[{\"sliderMinVal\"","SaveCount=TextCheck",LAST);
	
//	if(stricmp(lr_get_attrib_string("URLStatus"),"STG")==0)
//	{
//		web_reg_save_param("AutoSuggestResult","LB/IC=term\":\"", "RB/IC=\"}","ORD=ALL", LAST);
//	}
	
	//if(stricmp(lr_get_attrib_string("URLStatus"),"QA")==0)
	//{
		//web_reg_save_param("ProductCodeURL","LB/IC=\"url\":\"/", "RB/IC=\",\"","ORD=ALL", LAST);
		
	//}
	
//	web_reg_save_param("ProductCodeURL","LB/IC=null,\"url\":\"/", "RB/IC=\",\"tireWheelRimDiameter","ORD=ALL", LAST);
	
	web_reg_save_param("ProductCodeURL","LB/IC=null,\"url\":\"/", "RB/IC=\",\"wetStopDistance","ORD=ALL", LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_url("SearchBox", 
		"URL=https://{URL}/search/autocomplete/SearchBox?term={SearchString}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t108.inf", 
		//"Mode=HTML", 
		LAST);

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{SearchString}")));
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");

	lr_think_time(Think_Time);

	return 0;
}


DTC_Click_ProductLink(char *TxnName)
{
	char ProductURL[50];
	char ProductstrURL[50];
	
	char * token;
	
	char *s1,*s2;
	int len, count = 0, i, j;
	char *s3;
	char separators[] = " "; 
	char FullProdURL[50];
	
	lr_param_sprintf ("ProductCodeURL_Random", "%s", lr_paramarr_random("ProductCodeURL"));
	
	if((strstr(lr_eval_string("{ProductCodeURL_Random}"),"medias/?"))>0)
	{
		while(strstr(lr_eval_string("{ProductCodeURL_Random}"),"medias/?")>0)
		{
			lr_param_sprintf ("ProductCodeURL_Random", "%s", lr_paramarr_random("ProductCodeURL"));
		}
	}
	
	if(strstr(lr_eval_string("{ProductCodeURL_Random}")," ")>0)
	{
		sprintf(ProductURL,"%s",lr_eval_string("{ProductCodeURL_Random}")); 
        
	

        token = (char *)strtok(ProductURL, separators); 
        
        sprintf(ProductstrURL,"%s",lr_eval_string("{ProductCodeURL_Random}"));
        
		len = strlen(ProductstrURL);
		s1 = ((char *) strstr(ProductstrURL," ")+1);
		
	//	lr_output_message("%s",s1);
	
		sprintf(FullProdURL,"%s-%s",token,s1);
		
        lr_save_string(FullProdURL,"ProductCodeURL_Random");
	}
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	//Below correlation can be used to catch the product id
	web_reg_save_param("ProductCodeDetail","LB/IC=item\">ITEM:&nbsp;", "RB/IC=</div>","ORD=1", LAST);
	
	web_reg_find("Search=Body","Text/IC=There are currently no reviews for this product","SaveCount=NoReviews",LAST);
	
	lr_start_transaction(TxnName);
	
	web_reg_find("Search=Body","Text/IC=Specifications","SaveCount=TextCheck",LAST);

	web_url("Product_Link", 
		"URL=https://{URL}/{ProductCodeURL_Random}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t110.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ProductCodeURL_Random}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	if (atoi((lr_eval_string("{NoReviews}"))) == 0 && strstr(lr_eval_string("{ProductCodeURL_Random}"),"buy-tires")>0)
	{
		DTC_ReviewProduct("DTC_ReviewProduct_Ajax");
	}

	lr_think_time(Think_Time);

	return 0;
}

DTC_Search_Product(char *TxnName)
{
	
//	if(stricmp(lr_get_attrib_string("URLStatus"),"STG")==0)
//	{
//		lr_param_sprintf ("AutoSuggestResult_Random", "%s", lr_paramarr_random("AutoSuggestResult"));
//	}

	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=product search","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Your search for","SaveCount=NoResTextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);

	
	//if(stricmp(lr_get_attrib_string("URLStatus"),"QA")==0)
	//{
	
	web_url("search",
		"URL=https://{URL}/search/?text={SearchString}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
		
	//}
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{SearchString}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");

	/*
	if(stricmp(lr_get_attrib_string("URLStatus"),"STG")==0)
	{
	
	web_url("search", 
		"URL=https://{URL}/search/?q={AutoSuggestResult_Random}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
		
	}
	*/
	
	lr_think_time(Think_Time);

	return 0;
}

DTC_ViewPromotions(char *TxnName)
{    
    
    web_reg_find("Search=Body","Text/IC=Deals and Rebates","SaveCount=TextCheck",LAST);
       
    //web_reg_save_param("Promotions","LB/IC=_title\"><a href=\"promotions/","RB/IC=\">","ORD=ALL",LAST); 

    web_reg_save_param("Promotions","LB/IC=\"/promotions/","RB/IC=\"><","ORD=ALL",LAST); 
    
    lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);    
    
    web_url("Promotions", 
         "URL=https://{URL}/promotions", 
         "TargetFrame=", 
         "Resource=0", 
         "RecContentType=text/html ", 
         "Referer=", 
         "Snapshot=t1.inf", 
         "Mode=HTML", 
         LAST);
    
        
    lr_end_transaction(TxnName,CheckIF_TransFailed(TxnName,lr_eval_string("{Promotions_count}")));
    
    DTC_MiniCart("DTC_MiniCart_Ajax");

    lr_think_time(Think_Time);
    
    return 0;
}

DTC_SelectPromotions(char *TxnName)
{
    
	lr_save_string(lr_paramarr_random("Promotions"),"RandPromotions");
  
	//web_reg_find("Search=Body","Text/IC=Deals and Rebates :","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","TextPfx=utag_data[\"page_subcategory\"] = \"","TextSfx=\";","SaveCount=TextCheck",LAST);
	
	//web_reg_save_param("TextCheckPromotion","LB=utag_data[\"page_subcategory\"] = \"","RB=\";","ORD=3",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

    lr_start_transaction(TxnName);
        
    web_url("SelectPromotions", 
         "URL=https://{URL}/promotions/{RandPromotions}",
	     "TargetFrame=", 
         "Resource=0", 
         "RecContentType=text/html ", 
         "Referer=" , 
         "Snapshot=t47.inf", 
         "Mode=HTML", 
         LAST);
     	    
    lr_end_transaction(TxnName,CheckIF_TransFailed(TxnName,lr_eval_string("{RandPromotions}")));
    
    DTC_MiniCart("DTC_MiniCart_Ajax");

    lr_think_time(2);

    return 0;
}

DTC_SelectPromotions_thanksgiving(char *TxnName)
{
    
//	lr_save_string(lr_paramarr_random("Promotions"),"RandPromotions");
  
	web_reg_find("Search=Body","Text/IC=Deals and Rebates :","SaveCount=TextCheck",LAST);
   
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

    lr_start_transaction(TxnName);
        
    web_url("SelectPromotions", 
         "URL=https://{URL}/promotions/thanksgiving-deals", 
         "TargetFrame=", 
         "Resource=0", 
         "RecContentType=text/html ", 
         "Referer=" , 
         "Snapshot=t47.inf", 
         "Mode=HTML", 
         LAST);
    
    lr_end_transaction(TxnName,CheckIF_TransFailed(TxnName,lr_eval_string("{RandPromotions}")));
	
   	DTC_MiniCart("DTC_MiniCart_Ajax");
    
    lr_think_time(2);

    return 0;
}