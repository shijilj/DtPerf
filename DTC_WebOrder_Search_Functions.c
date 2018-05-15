DTC_Home(char *TxnName)
{
	web_cache_cleanup(); 
	web_cleanup_cookies();
	
	
//	if(stricmp(lr_get_attrib_string("URLStatus"),"PE")==0)
	if(stricmp(URLStatus,"PE")==0)
	{
//		web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken=\"", "RB/IC=\";","ORD=1", LAST);
		web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken = \"", "RB/IC=\";","ORD=1", LAST);
	}
	
	else
	{
		//web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken=\"", "RB/IC=\";","ORD=1", LAST);
		web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken = \'", "RB/IC=';","ORD=1", LAST);
	}
	
	web_reg_save_param("TireType","LB/IC=>Tire Type</h6>", "RB/IC=</div>","ORD=1", LAST);
	
	web_reg_save_param("WheelType","LB/IC=>Wheel Style</h6>", "RB/IC=</div>","ORD=1", LAST);
	
//	web_reg_save_param("StoreName","LB/IC=data-actionurl=\"/en/store-locator/", "RB/IC=/sendToPhonePopup","ORD=1","NotFound=Warning", LAST);
	
	//web_reg_save_param("CombinedJS","LB/IC=<script src=\"/", "RB/IC=\"></script><script","ORD=1", "NotFound=Warning", LAST);
	

	web_reg_save_param("JSESSIONID","LB/IC=JSESSIONID=", "RB/IC=; Path=/;","ORD=1", "NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC=Services","SaveCount=TextCheck",LAST);
	
//Please change this transaction back to normal for STG load test	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
//	if(stricmp(lr_get_attrib_string("URLStatus"),"PE")==0)
	if(stricmp(URLStatus,"PE")==0)
	{
	//	web_reg_save_param("CombinedJS","LB/IC=<script src=\"/", "RB/IC=\"></script><script","ORD=1", LAST);
		
		web_url("{URL}", 
			"URL=http://10.103.64.109:9001/?site=discounttire",
		//	"URL=http://{URL}/", 		
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
		
	//	web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken=\"", "RB/IC=\";","ORD=1", LAST);
		
	/*	web_url("{URL}", 
			"URL=https://{URL}/{CombinedJS}",
		//	"URL=https://{URL}/", 		
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
	*/			
	//	web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken = \"", "RB/IC=\";","ORD=1", LAST);
	//	web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken=\"", "RB/IC=\";","ORD=1", LAST);
		
//		web_reg_save_param("TireType","LB/IC=>Tires Type</h6>", "RB/IC=</div>","ORD=1", LAST);
//		
//		web_reg_save_param("WheelType","LB/IC=>Wheels Style</h6>", "RB/IC=</div>","ORD=1", LAST);
//		
//	//	web_reg_save_param("StoreName","LB/IC=data-actionurl=\"/en/store-locator/", "RB/IC=/sendToPhonePopup","ORD=1","NotFound=Warning", LAST);
//		
//		web_reg_find("Search=Body","Text/IC=Services","SaveCount=TextCheck",LAST);
	}
//	web_add_cookie("searchArea={ZipCode}; Path=/; expires=Sat, 18–Dec–2027 23:12:40 GMT; domain=stg.discounttire.com");
		
//	web_add_cookie("myStoreCookie={StoreName}; Path=/; expires=Sat, 18–Dec–2027 23:12:40 GMT; domain=stg.discounttire.com");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_url("{URL}", 
		"URL=https://{URL}/", 		
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
/*	if(stricmp(lr_get_attrib_string("URLStatus"),"PE")!=0)
	{
		web_reg_save_param("CSRFToken","LB/IC=config.CSRFToken=\"", "RB/IC=\";","ORD=1", LAST);
			
		web_url("{URL}", 
				"URL=https://{URL}/{CombinedJS}",
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				LAST);
	}*/
	
	
	
	
	//web_set_sockets_option("SSL_VERSION", "TLS1.1");
	

	/*
	
	if(strstr(lr_eval_string("{URL}"),"stg")!=0)
	{

		web_url("popupPage", 
		"URL=https://{URL}/en/store-locator/popupPage?oppositeId=unknown&searchArea=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t4.inf", 
		"Mode=HTML",
		LAST);
	}
	
		
	
	web_url("{URL}", 
		"URL=https://{URL}/en/store-locator", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	*/
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"1")==0)||(stricmp(lr_get_attrib_string("TestCase"),"3")==0) || (stricmp(lr_get_attrib_string("TestCase"),"All")==0))
//	{
		web_add_cookie("searchArea={ZipCode}; Path=/; expires=Sat, 18–Dec–2027 23:12:40 GMT; domain=stg.discounttire.com");
		
		web_add_cookie("myStoreCookie={StoreName}; Path=/; expires=Sat, 18–Dec–2027 23:12:40 GMT; domain=stg.discounttire.com");
//	}
	
	//else
	//{
			
/*	web_url("years", 
		"URL=https://{URL}/fitment/vehicle/years?vehicleClass=ALL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	//}

*/		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CSRFToken}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	//lr_set_debug_message(512|1,0);
		
	//lr_output_message("Jsession ID: %s\t Vuser ID: %s\t Iteration ID: %s\n",lr_eval_string("{JSESSIONID}"),lr_eval_string("{Vuser}"),lr_eval_string("{Iteration}"));
		
	//lr_set_debug_message(512|1,1);
	
	lr_think_time(Think_Time);

return 0;	

}

DTC_SearchStore(char *TxnName)
{

	web_reg_save_param("StoreName","LB/IC=data-Name=\"", "RB/IC=\" data-index=\"","ORD=1", LAST);
		
	web_reg_find("Search=Body","Text/IC=ADDRESS","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("store-finder", 
		"URL=https://{URL}/store-locator?max=25&q={ZipCode}&CSRFToken={CSRFToken}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t22.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ZipCode}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

return 0;	

}

DTC_MakeThisMyStore(char *TxnName)
{

	//web_reg_save_param("StoreID","LB/IC=<a href=\"/discounttire/en/appointments/makeAnAppointment/", "RB/IC=\">","ORD=ALL", LAST);
	
	//lr_param_sprintf("RandStoreName", "%s", lr_paramarr_random("StoreName"));
	
	lr_param_sprintf("StoreDetail", "Store  %s ZipCode %s", lr_eval_string("{StoreName}"), lr_eval_string("{ZipCode}"));
			
	web_reg_find("Search=Body","Text/IC=current store","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_submit_data("setCurrentStore", 
		"Action=https://{URL}/store-locator/setCurrentStore", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=queryString", "Value=max=25&q={ZipCode}&CSRFToken={CSRFToken}", ENDITEM, 
		"Name=storeName", "Value={StoreName}", ENDITEM, 
		"Name=isDetailPage", "Value=false", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{StoreDetail}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

return 0;	

}
	
// Select the vehicle 

DTC_Select_Vehicle(char *TxnName, char *vehYear, char *vehMake, char *vehModel, char *vehTrim)
{
	// Used for Sort and Filter
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"6")==0))
//	{
	   	lr_save_string(vehYear,"vYear");
	   	lr_save_string(vehMake,"vMake");
	   	lr_save_string(vehModel,"vModel");
	   	lr_save_string(vehTrim,"vTrim");
	//   	lr_save_string(lr_eval_string("{Assembly1}"),"Assembly"); 	
//	}

	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("makes", 
		"URL=https://{URL}/fitment/vehicle/makes?year={vYear}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	//web_reg_save_param("Model","LB/IC=\"vehicleId\":\"", "RB/IC=\"","ORD=ALL", LAST);
	
	web_url("models", 
		"URL=https://{URL}/fitment/vehicle/models?year={vYear}&make={vMake}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_param_sprintf("RandModel", "%s", lr_paramarr_random("Model"));

	//web_reg_save_param("Trim","LB/IC=\"trimId\":\"", "RB/IC=\"","ORD=ALL", LAST);
	
	web_reg_find("Search=Body","Text/IC=description","SaveCount=TextCheck",LAST);

	web_url("trims", 
		"URL=https://{URL}/fitment/vehicle/trims?vehicleId={vModel}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_param_sprintf("VehData", "Site-%s Veh-%s %s %s", lr_eval_string("{StoreName}"), lr_eval_string("{vYear}"), lr_eval_string("{vMake}"), lr_eval_string("{vModel}"));
	
	//lr_param_sprintf("RandTrim", "%s", lr_paramarr_random("Trim"));
	
	web_reg_save_param("Assembly","LB/IC=\"assemblyId\":\"", "RB/IC=\"","ORD=ALL", LAST);
	
	web_reg_save_param("Assembly_Letter","LB/IC=\"assemblyLetter\":\"", "RB/IC=\",","ORD=ALL", LAST);

	web_url("assemblies", 
		"URL=https://{URL}/fitment/vehicle/assemblies?trimId={vTrim}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	lr_think_time(Think_Time);

return 0;	
}
	
	
//click on shop for my vehicle
	
DTC_Shop_for_Vehicle(char *TxnName)
{
	int rnum;
	
	
	rnum = (rand() % atoi(lr_eval_string("{Assembly_count}")))+1;
	    
	lr_param_sprintf("RandAssembly", "%s", lr_paramarr_idx("Assembly",rnum));

	lr_param_sprintf("RandAssembly_Letter", "%s", lr_paramarr_idx("Assembly_Letter",rnum)); 	
	            
//	lr_save_string(vehAssembly,"vAssembly"); 	
//	lr_param_sprintf("RandAssembly", "%s", lr_paramarr_random("Assembly"));	
	
	web_reg_save_param("c_vehAssembly","LB/IC=frontTireSize\":\"", "RB/IC=\",\"","NotFound=Warning", LAST);
	
	//frontTireSize":"195/65-R15","
	
	web_reg_find("Search=Body","Text/IC=description","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_submit_data("selectByVehicleId", 
		"Action=https://{URL}/fitment/vehicle/selectByVehicleId", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=vehicleId", "Value={vModel}", ENDITEM, 
		"Name=trimId", "Value={vTrim}", ENDITEM, 
		"Name=assemblyId", "Value={RandAssembly}", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);

	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
		
	lr_think_time(Think_Time);

return 0;	
}
	
//Click on tires or Wheels

DTC_Search(char *TxnName,char* ArticleType)
{
	
	char actionURL1[200];
	
	sprintf(actionURL1,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), ArticleType);

	web_reg_save_param("ProductCode","LB/IC=\" data-code=\"", "RB/IC=\" data","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_save_param("ProductLink","LB/IC=productname\"><a href=\"/buy-","RB/IC=\" title=","ORD=ALL",LAST);
	
	//web_reg_save_param("AddtoCartCheck","LB/IC=<button type=\"button\" class=\"results-row__cartbutton\"","RB/IC=>Add to cart", "ORD=ALL",LAST);
	
	//web_reg_save_param("BrandFilter","LB/IC=:brands:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
	
	if(strcmp(ArticleType,"tires")==0)
	{
	//	web_reg_save_param("BrandAllFilter","LB/IC=value=\":bestSeller-asc:brands:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
		web_reg_save_param("BrandAllFilter","LB/IC=query\":{\"value\":\":bestSeller-asc:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	}
	else{
	//	web_reg_save_param("BrandAllFilter","LB/IC=value=\":relevance:brands:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
		web_reg_save_param("BrandAllFilter","LB/IC=query\":{\"value\":\":relevance:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	}
	
	//web_reg_save_param("BrandAllFilter","LB/IC=value\":\":relevance:brands:", "RB/IC=\"}","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("BrandFilter","LB/IC=query\":{\"value\":\":price-asc:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("ProductCodeDetail","LB/IC/DIG=<span class=\"message-stock\">In stock,</span> over ##.</div>\n                        <form id=\"addToCartForm", "RB/IC=\" class=","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_save_param("Store_Letters","LB/IC=<span>(","RB/IC=)</span></h5>","ORD=1","NotFound=Warning",LAST);
	
	if(strcmp(ArticleType,"tires")==0)
	{
		//web_reg_save_param("Reviews_URL", "LB/IC=review-rating__read\" href=\"/", "RB/IC=?your-vehicle=true#/read-reviews\">Read reviews", "ORD=ALL", "NotFound=Warning", LAST);
		web_reg_save_param("Reviews_URL", "LB/IC=review-rating__read\" href=\"/", "RB/IC=?all-vehicles=true#/read-reviews", "ORD=ALL", "NotFound=Warning", LAST);
	}
	
//	web_reg_find("Search=Body","Text/IC=utag_data[\"filter_applied\"].push(\"in stock:true\")","SaveCount=InStock_Count",LAST);
	web_reg_find("Search=Body","Text/IC=stockLevel.inStock","SaveCount=InStock_Count",LAST);
	
	//web_reg_find("Search=Body","Text/IC=<span class=\"facet-text\">In Stock</span>","SaveCount=InStockFilter_Count",LAST);
	//web_reg_find("Search=Body","Text/IC=\"name\":\"In Stock\",\"category\":false,","SaveCount=InStockFilter_Count",LAST);
	
	
	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results Page","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=No product results found for","SaveCount=NoResTextCheck",LAST);
	
	//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);

	web_url("tires", 
		actionURL1,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");
	
	lr_think_time(Think_Time);

	return 0;
}

// Click on tire by brand or wheel by brand

DTC_Search_ByBrand(char *TxnName,char* Articlecategory,char* ArticleType)
{
	char actionURL2[200];
	
	sprintf(actionURL2,"URL=https://%s/%s", lr_eval_string("{URL}"), Articlecategory);
	
//	web_reg_save_param("ProdBrands", "LB/IC=\ttitle=\"", "RB/IC=\" alt=", "ORD=ALL", LAST);
	
	if(stricmp(ArticleType,"tire")==0)
	{
	//	web_reg_save_param("ProdBrands", "LB/IC=href=\"/buy-tires/tire-brands/", "RB/IC=\"><span>", "ORD=ALL", LAST);
	//	web_reg_save_param("ProdBrands", "LB/IC=list__link\" href=\"/buy-tires/tire-brands/", "RB/IC=\">Learn More", "ORD=ALL", LAST);
		web_reg_save_param("ProdBrands", "LB/IC=image-link\" href=\"/tires/brands/", "RB/IC=\">", "ORD=ALL", LAST);		
	}
	
	else
	{
	//	web_reg_save_param("ProdBrands", "LB/IC=href=\"/buy-wheels/wheel-brands/", "RB/IC=\"><span>", "ORD=ALL", LAST);
	//	web_reg_save_param("ProdBrands", "LB/IC=list__link\" href=\"/buy-wheels/wheel-brands/", "RB/IC=\">Learn More", "ORD=ALL", LAST);
		web_reg_save_param("ProdBrands", "LB/IC=image-link\" href=\"/wheels/brands/", "RB/IC=\">", "ORD=ALL", LAST);
	}
	
	web_reg_save_param("Allbrand_VehicleClass", "LB/IC=data-vehicle-class=\"", "RB/IC=\"", "ORD=1","NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC=Home","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Search Results","SaveCount=NoResTextCheck",LAST);
	//web_reg_find("Search=Body","Text/IC=Your search for {0} did not match any products","SaveCount=NoResTextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("showBrandsCategory", 
		actionURL2,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t42.inf", 
		"Mode=HTML",
		LAST);
	
/*	if(strlen(lr_eval_string("{Allbrand_VehicleClass}"))>0)
	{
	web_url("ProductBrand_VehicleClass", 
		"URL=https://{URL}/fitment/vehicle/years?vehicleClass={Allbrand_VehicleClass}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t24.inf", 
		"Mode=HTML",
		LAST);
	}*/
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,ArticleType));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
}

// Click on tire brand or wheel brand

DTC_Click_Brand(char *TxnName, char* Type)
{
	char actionURL3[300];
	int rnum;
	
	srand(time(NULL));
	
	rnum = (rand() % 3) + 2;
		
	if(strstr(Type,"wheels")>0)
	{
	//	lr_param_sprintf("RandProdBrands", "%s", lr_paramarr_idx("ProdBrands",rnum));
		lr_param_sprintf("RandProdBrands", "%s", lr_paramarr_random("ProdBrands"));
	}
	
	else
	{
		lr_param_sprintf("RandProdBrands", "%s", lr_paramarr_random("ProdBrands"));
	}
	
	sprintf(actionURL3,"URL=https://%s/%s/%s", lr_eval_string("{URL}"),Type,lr_eval_string("{RandProdBrands}"));
		
	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Learn more","SaveCount=TextCheck",LAST);
	
	//web_reg_find("Search=Body","Text/IC=Your search for {0} did not match any products","SaveCount=NoResTextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results","SaveCount=NoResTextCheck",LAST);
	
	web_reg_save_param("Vehicle_Class", "LB/IC=data-vehicle-class=\"", "RB/IC=\"","ORD=1","NotFound=Warning", LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("ProductBrand", 
		actionURL3,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t24.inf", 
		"Mode=HTML",
		LAST);
	
/*	if(strlen(lr_eval_string("{Vehicle_Class}"))>0)
	{
	
	web_url("ProductBrand_VehicleClass", 
		"URL=https://{URL}/fitment/vehicle/years?vehicleClass={Vehicle_Class}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t24.inf", 
		"Mode=HTML",
		LAST);
	}*/
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{RandProdBrands}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
}

// Click on tire or wheel by size

DTC_Search_BySize(char *TxnName,char* ArticleType)
{
	char actionURL4[300];
	
	sprintf(actionURL4,"URL=https://%s/fitment/searchBySize/%s?vehicleClass=ALL", lr_eval_string("{URL}"), ArticleType);
	
	web_reg_find("Search=Body","Text/IC=diameter","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("tires", 
		actionURL4, 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,ArticleType));
	
	lr_think_time(Think_Time);
	
	return 0;
}

// Search tire or wheel by size

DTC_Shop_Tires_or_Wheels(char *TxnName,char* ArticleType,char* SizeType, char* SizeUnit, char* dia, char* width)
{
	char actionURL5[300];
	
	if(strcmp(ArticleType,"tires")==0) 
	{
		sprintf(actionURL5,"URL=https://%s/fitmentresult/%s/size/%s-%s-%s", lr_eval_string("{URL}"),ArticleType, width, SizeUnit, dia ); 
	}
	else
	{
		sprintf(actionURL5,"URL=https://%s/fitmentresult/%s/searchBySize?%s=%s&diameter=%s&width=%s", lr_eval_string("{URL}"),ArticleType, SizeType,SizeUnit, dia, width ); 
	}
	
//	sprintf(actionURL5,"URL=https://%s/fitmentresult/%s/searchBySize?%s=%s&diameter=%s&width=%s", lr_eval_string("{URL}"),ArticleType, SizeType, SizeUnit, dia, width);
			
	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results Page","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=No product results found for","SaveCount=NoResTextCheck",LAST);
	
	//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	
	lr_param_sprintf("ProdSize", "Wid %s AR/BP %s Dia %s", width,SizeUnit,dia);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("searchBySize", 
	        actionURL5,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t16.inf", 
		"Mode=HTML",
		LAST);		
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ProdSize}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

	return 0;
}

// Filter the vehicle data by Brand

DTC_Filter_Brand(char *TxnName, char * Type, char * ArticleType)
{
	
	char actionURL8[300]; 
	
	if(atoi(lr_eval_string("{BrandFilter_count}"))>=1)
	{
		lr_param_sprintf("RandBrandFilter", "%s", lr_paramarr_random("BrandFilter"));
	}
	
	else
	{
		lr_param_sprintf("RandBrandFilter", "%s", lr_paramarr_random("BrandAllFilter"));
	}
	
		
	sprintf(actionURL8,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), Type);
	
	//web_reg_save_param("PriceFilter","LB/IC=:price:", "RB/IC=\"/>\n","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("PriceFilter","LB/IC/ALNUMIC=query\":{\"value\":\":price-asc:inventoryStatus-boolean:true:brands:brand-^^^:price:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("PriceFilter","LB/IC/ALNUMIC=query\":{\"value\":\":relevance:inventoryStatus-boolean:true:brands:brand-^^^:price:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_save_param("PriceMin","LB/IC/ALNUMIC=code\":\"priceValue\",\"visible\":true,\"isSlider\":true,\"values\":[{\"sliderMinVal\":", "RB/IC=,\"","NotFound=Warning", LAST);
	web_reg_save_param("PriceMax","LB/IC/ALNUMIC=scaleMaxVal\":", "RB/IC=}],\"priority\":100,\"type\":null,\"needCollapse\":false,\"needExpand\":true,\"name\":\"Price Range","NotFound=Warning", LAST);
	
/*	if(strcmp(ArticleType,"tires")==0)
	{
		web_reg_save_param("PriceAllFilter","LB/IC/ALNUMIC=value=\":bestSeller-asc:brands:brand-^^^:price:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
	}
	else{
		web_reg_save_param("PriceAllFilter","LB/IC/ALNUMIC=value=\":relevance:brands:brand-^^^:price:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
	}
	*/
	//web_reg_save_param("PriceAllFilter","LB/IC/ALNUMIC=value\":\":relevance:brands:brand-^^^:price:", "RB/IC=\"}","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=FilterApplied",LAST);
	
	web_reg_find("Search=Body","Text/IC=Your search for","SaveCount=NoResTextCheck",LAST);
	
	lr_param_sprintf("FilterBrand", "%s Brand %s ", lr_eval_string("{VehData}"), lr_eval_string("{RandBrandFilter}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("tires_3",
		actionURL8,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t75.inf", 
		"Mode=HTML",
		LAST);
	
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{FilterBrand}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");
	
	//randminnum= rand() % 2;
	randmaxnum= rand() % 5;
	//MinPriceVal = atoi(lr_eval_string("{PriceMin}")) + randminnum ;
	MinPriceVal = atoi(lr_eval_string("{PriceMin}"));
	MaxPriceVal = atoi(lr_eval_string("{PriceMax}")) - randmaxnum ;
	
	lr_think_time(Think_Time);
	
	return 0;
}

//Filter vehicle data by price

DTC_Filter_Price(char *TxnName,char * Type, char * ArticleType)
{
	
	char actionURL9[300];
	char * suffix = "%5D";
	
//	if(atoi(lr_eval_string("{PriceFilter_count}"))>=1)
//	{
//		lr_param_sprintf("RandPriceFilter", "%s", lr_paramarr_random("PriceFilter"));
//		
//		web_convert_param("ConRandPriceFilter","SourceString={RandPriceFilter}", "SourceEncoding=HTML","TargetEncoding=URL", LAST );
//	}
//	
//	else
//	{
//		lr_param_sprintf("RandPriceFilter", "%s", lr_paramarr_random("PriceAllFilter"));
//		
//		web_convert_param("ConRandPriceFilter","SourceString={RandPriceFilter}", "SourceEncoding=HTML","TargetEncoding=URL", LAST );
//	}
//	
//	web_convert_param("ConRandPriceFilter","SourceString={RandPriceFilter}", "SourceEncoding=HTML","TargetEncoding=URL", LAST );
	
	//sprintf(actionURL9,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), Type);
	sprintf(actionURL9,"URL=https://%s/fitmentresult/%s%d+TO+%d%s", lr_eval_string("{URL}"), Type, MinPriceVal, MaxPriceVal,suffix);
			
	lr_param_sprintf("FilterPrice", "%s Price %d - %d", lr_eval_string("{FilterBrand}"), MinPriceVal , MaxPriceVal);
	
	//lr_output_message("%s", lr_eval_string("{FilterPrice}"));
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=FilterApplied",LAST);
	
	web_reg_find("Search=Body","Text/IC=Your search for","SaveCount=NoResTextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("tires_4", 
		actionURL9,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t83.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{FilterPrice}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
	
}

//Sort vechicle data by Rating

DTC_Sort_Rating(char *TxnName,char * Type)
{
	
	char actionURL10[300];
	
	sprintf(actionURL10,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), Type);

	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results Page","SaveCount=TextCheck",LAST);

	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("Sort By Rating", 
		actionURL10,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t91.inf", 
		"Mode=HTML",
		LAST);
	
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");

	lr_think_time(Think_Time);

	return 0;
}

// Sort by best seller

DTC_Sort_BestSeller(char *TxnName,char * Type)
{
	
	char actionURL28[300];
	
	sprintf(actionURL28,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), Type);

	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results Page","SaveCount=TextCheck",LAST);

	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("Sort By best Seller", 
		actionURL28,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t91.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");

	lr_think_time(Think_Time);

	return 0;
}

// Filter By In Stock

DTC_Filter_InStock(char *TxnName,char * Type)
{
		
	char actionURL24[300];
	
	sprintf(actionURL24,"URL=https://%s/fitmentresult/%s", lr_eval_string("{URL}"), Type);

	//web_reg_save_param("ProductCode","LB/IC=\" data-code=\"", "RB/IC=\" data","ORD=ALL", LAST);
	
	web_reg_save_param("ProductCode","LB/IC=\" data-code=\"", "RB/IC=\" data","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_save_param("ProductLink","LB/IC=productname\"><a href=\"/buy-","RB/IC=\" title=","ORD=ALL",LAST);
	
//	web_reg_save_param("AddtoCartCheck","LB/IC=<button type=\"button\" class=\"results-row__cartbutton\"","RB/IC=>Add to cart", "ORD=ALL",LAST);
		
	//web_reg_save_param("BrandFilter","LB/IC=:brands:", "RB/IC=\"/>","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("BrandFilter","LB/IC=query\":{\"value\":\":price-asc:inventoryStatus-boolean:true:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	
	//web_reg_save_param("BrandFilter","LB/IC=query\":{\"value\":\":relevance:inventoryStatus-boolean:true:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	
	if( atoi((lr_eval_string("{NoResTextCheck}"))) == 0)
	{
		web_reg_find("Search=Body","Text/IC=0 Total Results","SaveCount=NoResTextCheck",LAST);
	}
	
	if( atoi((lr_eval_string("{NoResTextCheck}"))) == 0)
	{
		web_reg_find("Search=Body","Text/IC=Your search for","SaveCount=NoResTextCheck",LAST);
	}
	
	web_reg_find("Search=Body","Text/IC=Refinements","SaveCount=FilterApplied",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("Filter In stock", 
		 actionURL24, 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");

	lr_think_time(Think_Time);

	return 0;
}


//Clear filter

DTC_Clear_Filter(char *TxnName,char * Type, char *Recommendation)
{
	
	char actionURL14[300];
	
	//sprintf(actionURL14,"URL=https://%s/en/fitmentresult/%s?q=:relevance", lr_eval_string("{URL}"), Type ,Type);

	//sprintf(actionURL14,"URL=https://%s/fitmentresult/%s?q=:price-asc", lr_eval_string("{URL}"), Type ,Type);

	if(strcmp(Type,"tires")==0 && strcmp(Recommendation,"Yes")==0)
	{		
		sprintf(actionURL14,"URL=https://%s/fitmentresult/%s?q=%3Arelevance&sort=relevance", lr_eval_string("{URL}"), Type ,Type);	
	}
	if(strcmp(Type,"tires")==0 && strcmp(Recommendation,"No")==0)
	{
		sprintf(actionURL14,"URL=https://%s/fitmentresult/%s?q=:bestSeller-asc", lr_eval_string("{URL}"), Type ,Type);	
	}
	else{
		sprintf(actionURL14,"URL=https://%s/fitmentresult/%s?q=:relevance", lr_eval_string("{URL}"), Type ,Type);	
	}
	
	
	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	web_reg_find("Search=Body","Text/IC=Search Results Page","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("tires_5", 
		actionURL14,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t77.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");

	lr_think_time(Think_Time);

	return 0;
}


//Click on tire type or wheel type

DTC_Tire_Wheel_Type(char *TxnName)
{
	
	char actionURL6[300];
		
	if (strstr(TxnName,"Tire")!=0)
	{
//		save_params( lr_eval_string("{TireType}"),
//		"en/buy-",
//		"\">",
//		"TireTypeLinks");
		
		if(stricmp(lr_get_attrib_string("URLStatus"),"PE")==0)
		{
			save_params( lr_eval_string("{TireType}"),
		//	"/buy-",
			"/tires/",
			"\"><span>",
			"TireTypeLinks");
		}
		
		else
		{
			save_params( lr_eval_string("{TireType}"),
		//	"/buy-",
			"/tires/",
			"\"><span>",
			"TireTypeLinks");
		}
		
		
		lr_param_sprintf("RandTireTypeLinks", "%s", lr_paramarr_random("TireTypeLinks"));
		
	//	sprintf(actionURL6,"URL=https://%s/buy-%s", lr_eval_string("{URL}"), lr_eval_string("{RandTireTypeLinks}"));
		
		sprintf(actionURL6,"URL=https://%s/tires/%s", lr_eval_string("{URL}"), lr_eval_string("{RandTireTypeLinks}"));
		
		lr_param_sprintf("ProdType", "%s", lr_eval_string("{RandTireTypeLinks}"));
	}
	else
	{

//		save_params(lr_eval_string("{WheelType}"),
//		"en/buy-",
//		"\">",
//		"WheelTypeLinks");
		
		if(stricmp(lr_get_attrib_string("URLStatus"),"PE")==0)
		{
			save_params(lr_eval_string("{WheelType}"),
		//	"/buy-",
			"/wheels/",
			"\"><span>",
			"WheelTypeLinks");
		}
		
		else
		{
			save_params(lr_eval_string("{WheelType}"),
		//	"/buy-",
			"/wheels/",
			"\"><span>",
			"WheelTypeLinks");
		}
		
		
		lr_param_sprintf("RandWheelTypeLinks", "%s", lr_paramarr_random("WheelTypeLinks"));
	
	//	lr_param_sprintf("RandWheelTypeLinks", "%s", lr_paramarr_idx("WheelTypeLinks",atoi(lr_eval_string("{r}"))));
		
		sprintf(actionURL6,"URL=https://%s/wheels/%s", lr_eval_string("{URL}"), lr_eval_string("{RandWheelTypeLinks}"));
		
		lr_param_sprintf("ProdType", "%s", lr_eval_string("{RandWheelTypeLinks}"));
	}

	//web_reg_find("Search=Body","Text/IC=Filter your results","SaveCount=TextCheck",LAST);
	
	//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	
	
	if(stricmp(lr_eval_string("{RandTireTypeLinks}"),"tires")==0 || stricmp(lr_eval_string("{RandWheelTypeLinks}"),"wheels")==0)
	{
		web_reg_find("Search=Body","Text/IC=Learn more","SaveCount=TextCheck",LAST);
		
		web_reg_find("Search=Body","Text/IC=Search Results","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=Your search for {0} did not match any products","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
		
	}
	
	else if(stricmp(lr_eval_string("{RandWheelTypeLinks}"),"wheels")!=0 && strstr(lr_eval_string("{RandWheelTypeLinks}"),"wheels/")>0)
	{
		web_reg_find("Search=Body","Text/IC=Popular Brands","SaveCount=TextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=Wheels By","SaveCount=TextCheck",LAST);
		
		web_reg_find("Search=Body","Text/IC=Search Results","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=Your search for {0} did not match any products","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	}
	
	else
	{
		web_reg_find("Search=Body","Text/IC=Popular Brands","SaveCount=TextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=Tires By Type","SaveCount=TextCheck",LAST);
		
		web_reg_find("Search=Body","Text/IC=Search Results","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=Your search for {0} did not match any products","SaveCount=NoResTextCheck",LAST);
		//web_reg_find("Search=Body","Text/IC=No results found","SaveCount=NoResTextCheck",LAST);
	}
	
	web_reg_save_param("Type_VehicleClass", "LB/IC=data-vehicle-class=\"", "RB/IC=\"", "ORD=1","NotFound=Warning", LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("Tire_Wheel_Type", 
	    	actionURL6, 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	
	
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ProdType}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
/*	if(strlen(lr_eval_string("{Type_VehicleClass}"))>0)
	{
	
	web_url("ProductBrand_VehicleClass", 
		"URL=https://{URL}/fitment/vehicle/years?vehicleClass={Type_VehicleClass}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t24.inf", 
		"Mode=HTML",
		LAST);

	}
*/
	lr_think_time(Think_Time);

	return 0;
}


//Compare two products

DTC_Compare(char *TxnName,char *Comparetype)
{

	char actionURL20[300];
	char actionURL21[300];
	char actionURL22[300];
	
	sprintf(actionURL20,"URL=https://%s/compare/add?productCode=%s&compareType=%s", lr_eval_string("{URL}"), lr_eval_string("{ProductCode_1}"),Comparetype);
	
	sprintf(actionURL21,"URL=https://%s/compare/add?productCode=%s&compareType=%s", lr_eval_string("{URL}"), lr_eval_string("{ProductCode_2}"),Comparetype);
	
	sprintf(actionURL22,"URL=https://%s/compare/add?productCode=%s&compareType=%s", lr_eval_string("{URL}"), lr_eval_string("{ProductCode_3}"),Comparetype);

	
	lr_param_sprintf("CompareData", "%s, %s %s %s" ,lr_eval_string("{VehData}"), lr_eval_string("{ProductCode_1}"), lr_eval_string("{ProductCode_2}"), lr_eval_string("{ProductCode_3}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("add", 
		actionURL20,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		LAST);

	web_url("add_2", 
		actionURL21,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("add_3", 
		actionURL22,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t64.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Search=Body","Text/IC=Compare","SaveCount=TextCheck",LAST);

	web_url("product", 
		"URL=https://{URL}/compare/product", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t369.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CompareData}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

	return 0;
}	

// Click on Product link

DTC_Click_Product(char *TxnName,char* ArticleType)
{
	char ProductURL[50];
	char ProductstrURL[50];
	
	char * token;
	
	char *s1,*s2;
	int len, count = 0, i, j, c, r;
	char *s3;
	char separators[] = " "; 
	char FullProdURL[50];
	
	web_reg_save_param("CSRFToken","LB/IC=name=\"CSRFToken\" value=\"", "RB/IC=\" />","ORD=1", LAST);
	
	//Below correlation can be used to catch the product id
	web_reg_save_param("ProductCodeDetail","LB/IC=item\">ITEM:&nbsp;", "RB/IC=</div>","ORD=1", LAST);
	
	lr_param_sprintf("RandProductLink", "%s", lr_paramarr_random("ProductLink"));
	
/*	do
	{
		lr_param_sprintf("RandProductLink", "%s", lr_paramarr_random("ProductLink"));
	}while(strstr(lr_eval_string("{RandProductLink}"),"13083")>0 || strstr(lr_eval_string("{RandProductLink}"),"13276")>0 || strstr(lr_eval_string("{RandProductLink}"),"47766")>0 || strstr(lr_eval_string("{RandProductLink}"),"47767")>0 || strstr(lr_eval_string("{RandProductLink}"),"13033")>0 || strstr(lr_eval_string("{RandProductLink}"),"13275")>0 || strstr(lr_eval_string("{RandProductLink}"),"47770")>0 || strstr(lr_eval_string("{RandProductLink}"),"32709")>0 || strstr(lr_eval_string("{RandProductLink}"),"62822")>0 || strstr(lr_eval_string("{RandProductLink}"),"47771")>0 || strstr(lr_eval_string("{RandProductLink}"),"47775")>0);
*/	
		
/*	if(strstr(lr_eval_string("{RandProductLink}"),"10109")>0 || strstr(lr_eval_string("{RandProductLink}"),"10125")>0 || strstr(lr_eval_string("{RandProductLink}"),"16968")>0)
	{
		while(strstr(lr_eval_string("{RandProductLink}"),"10109")>0 || strstr(lr_eval_string("{RandProductLink}"),"10125")>0 || strstr(lr_eval_string("{RandProductLink}"),"16968")>0)
		{
			lr_param_sprintf("RandProductLink", "%s", lr_paramarr_random("ProductLink"));
		}
	}
	
	
	c = lr_paramarr_len("ProductLink");
	
	do
	{
		r = (rand() % c)+1;
		lr_save_string(lr_paramarr_idx("ProductLink",r),"RandProductLink");
	}while(strstr(lr_paramarr_idx("AddtoCartCheck",r),"disabled")>0);
*/	
	
	if(strstr(lr_eval_string("{RandProductLink}")," ")>0)
	{
		sprintf(ProductURL,"%s",lr_eval_string("{RandProductLink}")); 
        
	

        token = (char *)strtok(ProductURL, separators); 
        
        sprintf(ProductstrURL,"%s",lr_eval_string("{RandProductLink}"));
        
		len = strlen(ProductstrURL);
		s1 = ((char *) strstr(ProductstrURL," ")+1);
		
		lr_output_message("%s",s1);
	
		sprintf(FullProdURL,"%s-%s",token,s1);
		
        lr_save_string(FullProdURL,"RandProductLink");
	}
	web_reg_find("Search=Body","Text/IC=Specifications","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=There are currently no reviews for this product","SaveCount=NoReviews",LAST);
	
//	web_reg_find("Search=Body","Text/IC=Stock","SaveCount=TextCheck",LAST);
	
	lr_param_sprintf("CartDetails", "%s %s ", lr_eval_string("{VehData}"), lr_eval_string("{RandProductLink}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
		
	lr_start_transaction(TxnName);

	web_url("Product Details", 
		"URL=https://{URL}/buy-{RandProductLink}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t44.inf", 
		"Mode=HTML",
		LAST);	         
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDetails}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	if (atoi((lr_eval_string("{NoReviews}"))) == 0 && strcmp(ArticleType,"tires")==0)
	{
		DTC_ReviewProduct("DTC_ReviewProduct_Ajax");
	}
		
	
	lr_think_time(Think_Time);

	return 0;
}

DTC_Legacy_PDP(char *TxnName)
{
	char actionURL25[300];
	
	sprintf(actionURL25,"URL=https://%s/legacy/pos/pdp?articleId=%s&storeCode=%s&vehicleAssemblyId=%s|%s|%s",lr_eval_string("{URL}"),lr_eval_string("{ProductCodeDetail}"),lr_eval_string("{Store_Letters}"),lr_eval_string("{vModel}"),lr_eval_string("{vTrim}"),lr_eval_string("{RandAssembly_Letter}"));
	
	web_reg_find("Search=Body","Text/IC=Specifications","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("Legacy_PDP", 
		actionURL25,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDetails}")));
	
	lr_think_time(Think_Time);

	return 0;
}

//Click on Check Inventory
DTC_Check_Inventory(char *TxnName)
{

//	web_reg_save_param("CityofStore","LB/IC=class=\"message-stock-cityOfStore\">", "RB/IC=</span>","ORD=1", "NotFound=Warning", LAST);
	
	web_reg_save_param("StoreCode","LB/IC=data-storecode=\"","RB/IC=\"","ORD=ALL",LAST);
		
	web_reg_find("Search=Body","Text/IC=Product availability","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
		
	web_url("getPointOfServiceStock", 
		"URL=https://{URL}/checkinventory/{ProductCodeDetail}/getPointOfServiceStock", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_param_sprintf("RandStoreCode", "%s", lr_paramarr_random("StoreCode"));
	
	web_reg_find("Search=Body","Text/IC=Store hours","SaveCount=TextCheck",LAST);
	
	web_url("updateSelectedStoreCartSection", 
		"URL=https://{URL}/checkinventory/{ProductCodeDetail}/updateSelectedStoreCartSection?storeName={RandStoreCode}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDetails}")));

	lr_think_time(Think_Time);

	return 0;
}

//Click on Check Inventory
DTC_Update_SeletedStore(char *TxnName)
{

	lr_param_sprintf("RandStoreCode", "%s", lr_paramarr_random("StoreCode"));
	
	web_reg_find("Search=Body","Text/IC=Store hours","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("updateSelectedStoreCartSection", 
		"URL=https://{URL}/checkinventory/{ProductCodeDetail}/updateSelectedStoreCartSection?storeName={RandStoreCode}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDetails}")));

	lr_think_time(Think_Time);

	return 0;
}

//Click on read review

DTC_Read_Reviews(char *TxnName)
{
	char ProductURL[50];
	char ProductstrURL[50];
	
	char * token;
	
	char *s1,*s2;
	int len, count = 0, i, j;
	char *s3;
	char separators[] = " "; 
	char FullProdURL[50];
	char actionURL23[300];
			
	lr_param_sprintf ("Reviews_URL_Random", "%s", lr_paramarr_random("Reviews_URL"));
	
	lr_save_searched_string(lr_eval_string("{Reviews_URL_Random}"),strlen(lr_eval_string("{Reviews_URL_Random}")),0,"/p/",0,5,"ReadReviewProduct");
	
	if(strstr(lr_eval_string("{Reviews_URL_Random}")," ")>0)
	{
		sprintf(ProductURL,"%s",lr_eval_string("{Reviews_URL_Random}")); 
        
	

        token = (char *)strtok(ProductURL, separators); 
        
        sprintf(ProductstrURL,"%s",lr_eval_string("{Reviews_URL_Random}"));
        
		len = strlen(ProductstrURL);
		s1 = ((char *) strstr(ProductstrURL," ")+1);
		
	//	lr_output_message("%s",s1);
	
		sprintf(FullProdURL,"%s-%s",token,s1);
		
        lr_save_string(FullProdURL,"Reviews_URL_Random");
	}
	
	sprintf(actionURL23,"URL=https://%s/%s?all-vehicles=true", lr_eval_string("{URL}"), lr_eval_string("{Reviews_URL_Random}"));
	
	web_reg_find("Search=Body","Text/IC=customer reviews","SaveCount=TextCheck",LAST);
	
	lr_param_sprintf("ReadReviewDetail", "%s %s ", lr_eval_string("{VehData}"), lr_eval_string("{Reviews_URL_Random}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);

	web_url("Read Reviews", 
		actionURL23,
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t347.inf", 
		"Mode=HTML", 
		LAST);

	web_url("reviews", 
		"URL=https://{URL}/review/product/{ReadReviewProduct}/reviews?", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t354.inf", 
		"Mode=HTML",
		LAST);

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ReadReviewDetail}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);

	return 0;
}

DTC_MiniCart(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC={\"entries\":[","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("miniCart", 
		"URL=https://{URL}/cart/json/miniCart", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t10.inf", 
	//	"Mode=HTML", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CSRFToken}")));
	
	return 0;
}

DTC_ReviewProduct(char *TxnName)
{
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC={\"pagination\"","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("reviews", 
		"URL=https://{URL}/review/product/{ProductCodeDetail}/reviews?", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t354.inf", 
		//"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{ProductCodeDetail}")));
	
	return 0;
}

// Click on Recommendations after Add Vehicle Step

DTC_Search_Recommendation(char *TxnName)
{

	//web_reg_find("Search=Body","Text/IC=legacyStoreCode\":","SaveCount=TextCheck",LAST);
	             	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
		
		web_url("request", 
			"URL=https://{URL}/recommendation/request?", 
			"TargetFrame=", 
			"Resource=0",
			"RecContentType=application/json", 			
			"Referer=", 
			"Snapshot=t95.inf", 
			//"Mode=HTML", 
			LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	lr_think_time(Think_Time);
	
	return 0;
}
	
DTC_View_Recommendation(char *TxnName, char *ArticleType)
{
	char vehAssembly[25];
	char aspectRatiorim[25];
	char separators[] = "/";
	char separators1[] = "-";
	char crossSection[25];
	char * token;
	char aspectRatio[25];
	char aspectRatio_rim[25];
	char rimSize[25];
		
	
	if(strstr(lr_eval_string("{c_vehAssembly}"),"/")>0)
	{
		sprintf(vehAssembly,"%s",lr_eval_string("{c_vehAssembly}")); 
		token = (char *)strtok(vehAssembly, separators);
		lr_save_string(token,"crossSection");
		sprintf(vehAssembly,"%s",lr_eval_string("{c_vehAssembly}"));
		token = ((char *) strstr(vehAssembly,"/")+1);
		lr_save_string(token,"aspectRatio_rim");
		sprintf(aspectRatiorim,"%s",lr_eval_string("{aspectRatio_rim}")); 
		token = (char *)strtok(aspectRatiorim, separators1);
		lr_save_string(token,"aspectRatio");
		sprintf(aspectRatiorim,"%s",lr_eval_string("{aspectRatio_rim}"));
		token = ((char *) strstr(aspectRatiorim,"R")+1);
		lr_save_string(token,"rimSize");
				
	}
	
	

	web_reg_save_param("ProductCode","LB/IC=\" data-code=\"", "RB/IC=\" data","ORD=ALL","NotFound=Warning", LAST);
	
	web_reg_save_param("ProductLink","LB/IC=productname\"><a href=\"/buy-","RB/IC=\" title=","ORD=ALL",LAST);
	
	if(strcmp(ArticleType,"tires")==0)
	{
		web_reg_save_param("BrandAllFilter","LB/IC=query\":{\"value\":\":relevance:recommendation-boolean:Recommendation:brands:", "RB/IC=\"},\"","ORD=ALL","NotFound=Warning", LAST);
	}
	else{
		//web_reg_save_param("BrandAllFilter","LB/IC=query\":{\"value\":\":relevance:brands:", "RB/IC=\"},\"listUrl\":","ORD=ALL","NotFound=Warning", LAST);
	}
	
	web_reg_save_param("Store_Letters","LB/IC=<span>(","RB/IC=)</span></h5>","ORD=1","NotFound=Warning",LAST);
	
	if(strcmp(ArticleType,"tires")==0)
	{
		web_reg_save_param("Reviews_URL", "LB/IC=review-rating__read\" href=\"/", "RB/IC=?all-vehicles=true#/read-reviews", "ORD=ALL", "NotFound=Warning", LAST);
	}
	
	web_reg_find("Search=Body","Text/IC=stockLevel.inStock","SaveCount=InStock_Count",LAST);
	
	web_reg_find("Search=Body","Text/IC=DRIVING DETAILS","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Error loading recommended tires for your vehicle","SaveCount=NoRecommendations",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_submit_data("recommendation", 
		"Action=https://{URL}/recommendation", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t114.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		"Name=frontOrBoth.oeSize", "Value=Y", ENDITEM, 
		"Name=frontOrBoth.crossSection", "Value={crossSection}", ENDITEM, 
		"Name=frontOrBoth.aspectRatio", "Value={aspectRatio}", ENDITEM, 
		"Name=frontOrBoth.rimSize", "Value={rimSize}", ENDITEM, 
		"Name=frontOrBoth.quantity", "Value=4", ENDITEM, 
		"Name=zipCode", "Value={ZipCode}", ENDITEM, 
		"Name=milesDriven", "Value=15", ENDITEM, 
		"Name=drivingStyle", "Value=typical", ENDITEM, 
		"Name=priority1", "Value=1", ENDITEM, 
		"Name=priority2", "Value=3", ENDITEM, 
		"Name=priority3", "Value=2", ENDITEM, 
		"Name=priority4", "Value=4", ENDITEM, 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_Compare_SelectedProducts("DTC_CompareProducts_Ajax");
	
	//DTC_topPLPProducts("DTC_TotPLPProducts_Ajax");
	
	lr_think_time(Think_Time);

	return 0;
}
// Ajax call with view recommendations page

DTC_topPLPProducts(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC={\"recProducts\":{\"pagination\":{\"pageSize","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("topPLPProducts", 
		"URL=https://{URL}/fitmentresult/topPLPProducts/nonStaggered?isOE=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t48.inf", 
		LAST);
		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{VehData}")));
	
	return 0;
}

// Utility functions

CheckIF_TransFailed(char *TxnName,char *TxnData)
	{
	
	web_remove_auto_header("x-dynaTrace", "ImplicitGen=Yes", LAST );
	
	if (atoi((lr_eval_string("{TextCheck}"))) == 0 )
	{
     
	    lr_error_message(" RandVal is %d,Txn Name  %s,Txn Data  %s ,failed for  vuser %s,Test Case %s, Iteration %s, Date/Time %s ",rand_iter_num,TxnName,TxnData, lr_eval_string("{Vuser}"),lr_eval_string("{TestCaseNo}"),lr_eval_string("{Iteration}"), lr_eval_string("{Date_Time}")); 	
		lr_output_message(" RandVal is %d,Txn Name  %s,Txn Data  %s , failed for vuser %s,Test Case %s, Iteration %s, Date/Time %s ",rand_iter_num,TxnName, TxnData,lr_eval_string("{Vuser}"),lr_eval_string("{TestCaseNo}"),lr_eval_string("{Iteration}"), lr_eval_string("{Date_Time}"));
		
		lr_set_transaction_status(LR_FAIL);	

		if( atoi((lr_eval_string("{NoResTextCheck}"))) > 0) 
		{
			char TxnName1[100];			
			
			sprintf(TxnName1, "%s_NoResultFound", TxnName);
			
			lr_start_transaction(TxnName1);
			
			lr_end_transaction(TxnName1,LR_AUTO);
			
		}	
		if( atoi((lr_eval_string("{NoRecommendations}"))) > 0) 
		{
			char TxnName1[100];	
			
			sprintf(TxnName1, "%s_NoRecommendations", TxnName);
			
			lr_start_transaction(TxnName1);
			
			lr_end_transaction(TxnName1,LR_AUTO);
			
			lr_save_string("0","NoRecommendations");
				
		}
				
	}
	
	
	
	
	
	return LR_AUTO;

}

DTC_Vuser_Startup()
{

	web_cache_cleanup(); 
	web_cleanup_cookies();
	//web_add_auto_filter("Action=Include", "Host=stg.qa.discounttire.com", LAST);
	web_global_verification("Text=We've got a problem...","Fail=Found",LAST);
	//web_global_verification("Text=/500","Fail=Found",LAST);
	web_set_max_html_param_len("99999");
	//web_set_sockets_option("SSL_VERSION", "TLS");
	web_set_sockets_option("SSL_VERSION", "2&3");
	//web_set_sockets_option("SSL_VERSION", "TLS1.1");
	return 0;
}

