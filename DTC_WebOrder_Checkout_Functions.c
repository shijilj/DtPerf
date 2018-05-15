// click on add to cart

DTC_AddtoCart(char *TxnName,char* ArticleType)
{
	
	//lr_param_sprintf("RandProductCodeDetail", "%s", lr_paramarr_random("ProductCodeDetail"));
	
	if(strstr(lr_eval_string("{RandProductLink}"),"tires")!=0 )
	{
		lr_save_string(lr_eval_string("{ProductCodeDetail}"),"ParentCodeDetail");
	}
	
	web_reg_find("Search=Body","Text/IC=cartData","SaveCount=TextCheck",LAST);

	lr_param_sprintf("CartDetails", "%s Prod %s", lr_eval_string("{VehData}"), lr_eval_string("{ProductCodeDetail}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	if(strcmp(ArticleType,"tires")==0)
	{
		web_submit_data("add", 
		"Action=https://{URL}/cart/add", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=productCodePost", "Value={ProductCodeDetail}", ENDITEM,
		"Name=storeId", "Value={StoreName}", ENDITEM,
	//	"Name=pdlUsage", "Value=true", ENDITEM, 		
		"Name=qty", "Value=2", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	}
	else{
		web_submit_data("add", 
		"Action=https://{URL}/cart/add", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=productCodePost", "Value={ProductCodeDetail}", ENDITEM,
		"Name=storeId", "Value={StoreName}", ENDITEM,
		"Name=qty", "Value=2", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	}
	
	
	
/*
	web_url("SUBTOTAL", 
		"URL=https://{URL}/en/cart/miniCart/SUBTOTAL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);
	
	web_set_option("MaxRedirectionDepth", "0", LAST );
	
	web_url("Product Details", 
		"URL=https://{URL}/buy-{RandProductLink}?_=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t44.inf", 
		"Mode=HTML",
		LAST);
		
	web_set_option("MaxRedirectionDepth", "10", LAST );
*/	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDetails}")));
	
	lr_think_time(Think_Time);
	
	return 0;
	
}

//view shopping cart

DTC_View_Cart(char *TxnName)
{
		
	lr_param_sprintf("CartDataDetails", "%s Tire %s Wheel %s", lr_eval_string("{VehData}"),lr_eval_string("{ParentCodeDetail}"), lr_eval_string("{ProductCodeDetail}"));
	
	web_reg_save_param("CSRFToken","LB/IC=csrfToken: '", "RB/IC=',","ORD=1", LAST);
	
//	web_reg_save_param("CSRFToken","LB/IC=name=\"CSRFToken\" value=\"", "RB/IC=\" />","ORD=1", LAST);
	
	//web_reg_save_param("ChildProdCode","LB/IC=childProductCode\" value=\"", "RB/IC=\" />","ORD=1", LAST);
	
	web_reg_save_param("ChildProdCode","LB/IC=buy-not-found/-certificates-for-repair%2c-refund%2c-or-replacement/p/", "RB/IC=\",\"wetStopDistance\"","ORD=1","NotFound=Warning", LAST);
	
//	web_reg_save_param("ChildProdCode","LB/IC=childProductCode\" value=\"", "RB/IC=\" />","ORD=1","NotFound=Warning", LAST);
	
	web_reg_save_param("Remove_EntryNum","LB/IC=\"entryNumber\":", "RB/IC=}],\"quantity","ORD=1","NotFound=Warning", LAST);
	
//	web_reg_save_param("Remove_EntryNum","LB/IC=<input type=\"hidden\" name=\"entryNumber\" value=\"", lr_eval_string("RB/IC=\"/>\r\n				                                <input type=\"hidden\" name=\"productCode\" value=\"{ProductCodeDetail}\"/>"),"ORD=1","NotFound=Warning", LAST);
		
	web_reg_find("Search=Body","Text/IC=Shopping cart","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_url("cart",
		"URL=https://{URL}/cart", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDataDetails}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	DTC_RefreshCart("DTC_RefreshCart_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
}

// Remove Product from cart

DTC_Remove_Product(char *TxnName)
{
	
//	web_reg_save_param("ChildProdCode","LB/IC=childProductCode\" value=\"", "RB/IC=\" />","ORD=1","NotFound=Warning", LAST);
	web_reg_save_param("ChildProdCode","LB/IC=buy-not-found/-certificates-for-repair%2c-refund%2c-or-replacement/p/", "RB/IC=\",\"wetStopDistance\"","ORD=1","NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC={\"miniCart\":{\"entries\":","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_submit_data("update", 
		"Action=https://{URL}/cart/json/updateQuantity?opt=delete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=entryNumber", "Value={Remove_EntryNum}", ENDITEM,
		"Name=productCode", "Value={ProductCodeDetail}", ENDITEM, 
		"Name=initialQuantity", "Value=0", ENDITEM, 
		"Name=quantity", "Value=0", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);	

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CartDataDetails}")));
		
	lr_think_time(Think_Time);

	return 0;
}

// Add Certificate

DTC_Add_Certificate(char *TxnName)
{
	char * Cert_verification= "\"productType\":\"Certificate\",\"summary\":null,\"tireDiameter\":null,\"aspectRatio\":null,\"loadRange\":null,\"wheelRimDiameter\":null,\"materialType\":null,\"genders\":null,\"maxSpeed\":null,\"trackDryHandling\":null,\"futureStocks\":null,\"recommended\":false,\"mapRuleSatisfied\":false,\"grossWeight\":null,\"runFlat\":null,\"volumePrices\":null,\"family\":null,\"multidimensional\":null,\"rimWidth\":null},\"productStatus\":\"ACTIVE\"";
	//lr_param_sprintf("CertData", "%s Cert %s", lr_eval_string("{CartDetails1}"), lr_eval_string("{ChildProdCode}"));
	
	lr_param_sprintf("CertData", "%s Tire  %s Cert %s", lr_eval_string("{VehData}"), lr_eval_string("{ParentCodeDetail}"), lr_eval_string("{ChildProdCode}"));
			
//	web_reg_find("Search=Body","Text/IC=total__remove","SaveCount=TextCheck",LAST);
	
	lr_save_string(Cert_verification,"Cert_Textcheck");
	
	web_reg_find("Search=Body","Text/IC={Cert_Textcheck}","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	/*web_submit_data("addChild", 
		"Action=https://{URL}/cart/addChild?CSRFToken={CSRFToken}", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=entryNumber", "Value=0", ENDITEM, 
		"Name=parentProductCode", "Value={ParentCodeDetail}", ENDITEM, 
		"Name=childProductCode", "Value={ChildProdCode}", ENDITEM, 
		"Name=quantity", "Value=2", ENDITEM, 
	//	"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);	*/
	
	web_custom_request("addChild", 
		"URL=https://{URL}/cart/json/addChild?CSRFToken={CSRFToken}", 
		"Method=POST", 
		"TargetFrame=",
		"Referer=",
		"Mode=HTTP",
		"EncType=application/json",
		"Body={\"entryNumber\":0,\"parentProductCode\":\"{ParentCodeDetail}\",\"childProductCode\":\"{ChildProdCode}\",\"quantity\":2}&CSRFToken={CSRFToken}",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
			
	lr_think_time(Think_Time);
	
	return 0;
}


// Update the cart

DTC_Update_Cart(char *TxnName)
{

	web_reg_find("Search=Body","Text/IC=updated","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_submit_data("update", 
		"Action=https://{URL}/cart/update", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t419.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=entryNumber", "Value=0", ENDITEM, 
		"Name=productCode", "Value={ProductCodeDetail}", ENDITEM, 
		"Name=initialQuantity", "Value=4", ENDITEM, 
		"Name=initialQuantity", "Value=4", ENDITEM, 
		"Name=quantity", "Value=6", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
}



//checkout without appointment

DTC_Checkout_Without_Appointment(char *TxnName)
{
	
	web_reg_find("Search=Body","Text/IC=Checkout","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_url("info", 
		"URL=https://{URL}/appointment/info?isPickupOnly=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	lr_think_time(Think_Time);
	
	return 0;
	
}


//check out as guest

DTC_Guest_Checkout(char *TxnName)
{
	
	web_reg_find("Search=Body","Text/IC=Checkout","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_submit_data("guest", 
		"Action=https://{URL}/login/checkout/guest", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=email", "Value={EmailID}", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	lr_think_time(Think_Time);
	
	return 0;
}


//click customer informantion

DTC_Customer_Information_WOA(char *TxnName)
{

	web_reg_find("Search=Body","Text/IC=Enter your information","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_submit_data("info_2", 
		"Action=https://{URL}/appointment/info", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=pickUpOnly", "Value=true", ENDITEM, 
		"Name=appointmentDate", "Value=", ENDITEM, 
		"Name=appointmentTime", "Value=", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	lr_think_time(Think_Time);
	
	return 0;
}


//Click schedule Appointment
	
DTC_Schedule_Appointment(char *TxnName)
{
	int i;
	char filename1[100];
	
	sprintf(filename1,"F:\\TextFiles_For_Execution\\Hybris_DTC_Order_Number_%s.txt",lr_eval_string("{TodayDate}"));
	
	lr_param_sprintf("AppintmentData", "Cart %s Date %s Time %s", lr_eval_string("{CertData}"),lr_eval_string("{AppointDate}"), lr_eval_string("{AppointTime}"));
	
//	web_reg_save_param("OrderNumber","LB/IC=Your appointment number is&nbsp;<strong>", "RB/IC=</strong>","ORD=1","NotFound=Warning", LAST);
	
//	web_reg_save_param("OrderNumber","LB/IC=utag_data[\"order_id\"] = \"", "RB/IC=\";","ORD=1","NotFound=Warning", LAST);
	
	web_reg_save_param("OrderNumber","LB/IC=\"code\":\"", "RB/IC=\",\"paymentInfoList\":","ORD=1","NotFound=Warning", LAST);
	
	web_reg_find("Search=Body","Text/IC=Thank you for your order","SaveCount=TextCheck",LAST);
	
	web_reg_find("Search=Body","Text/IC=Appointment cannot be scheduled","SaveCount=NoResTextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);

	web_submit_data("customer", 
		"Action=https://{URL}/checkout/customer-info", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t62.inf", 
		"Mode=HTML",
		"EncodeAtSign=YES",		
		ITEMDATA, 
		"Name=firstName", "Value=HybrisPerfuser", ENDITEM, 
		"Name=lastName", "Value=Test", ENDITEM, 
		"Name=email", "Value={EmailID}", ENDITEM, 
	//	"Name=confirmEmail", "Value={EmailID}", ENDITEM, 
		"Name=phoneType", "Value=WORK", ENDITEM, 
		"Name=phone", "Value={PhoneNO}", ENDITEM, 
	/*	"Name=reminderByEmail", "Value=true", ENDITEM, 
		"Name=_reminderByEmail", "Value=on", ENDITEM, 
		"Name=reminderEmail", "Value={EmailID}", ENDITEM, 
		"Name=_reminderByText", "Value=on", ENDITEM, 
		"Name=reminderText", "Value=", ENDITEM, */
		"Name=addressFlag", "Value=true", ENDITEM, 
		"Name=address.townCity", "Value=Scottsdale", ENDITEM, 
		"Name=address.regionIso", "Value=US-AZ", ENDITEM,
		"Name=_addressFlag", "Value=on", ENDITEM, 
		"Name=address.validated", "Value=false", ENDITEM, 
		"Name=address.line1", "Value=20225 N Scottsdale Rd", ENDITEM, 
	//	"Name=address.line2", "Value=", ENDITEM, 
	//	"Name=address.townCity", "Value=", ENDITEM, 
		"Name=address.postcode", "Value=85255", ENDITEM, 
		"Name=address.countryIso", "Value=US", ENDITEM, 
		"Name=Comments", "Value=", ENDITEM, 
		"Name=CSRFToken", "Value={CSRFToken}", ENDITEM,
		LAST);

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{AppintmentData}")));
	
	DTC_MiniCart("DTC_MiniCart_Ajax");
		
	if ((file1=fopen(filename1,"a+"))==NULL) 
	{
		lr_output_message("Unable to create file");
		return -1;
	}

	sprintf(Length1,"\n%s,%s,%s,%s",lr_eval_string("{StoreName}"),lr_eval_string("{Model}"),lr_eval_string("{OrderNumber}"),lr_eval_string("{ParentCodeDetail}")); 
	i = fwrite(&Length1,sizeof(Length1), 1, file1); 
	if ( i > 0) 
	{
		 lr_output_message("Successfully wrote %d record", i ); 
		 fclose(file1);
	}
 
	lr_think_time(Think_Time);
	
	return 0;
}

//checkout with appointment

DTC_Checkout_With_Appointment(char *TxnName)
{
	web_reg_save_param("AvailSlot","LB/IC=\"startTime\":\"", "RB/IC=:00.000Z\",\"endTime","ORD=All", LAST);
	
	web_reg_save_param("AvailDay","LB/IC=utag_data[\"appointment_day\"] = \"", "RB/IC=\";","ORD=All", LAST);
	
	web_reg_save_param("AvailMonth","LB/IC/ALNUMIC=utag_data[\"appointment_date\"] = \"", "RB/IC/ALNUMIC=/^^/20^^\";","ORD=All", LAST);
	
	//web_reg_save_param("AvailDay","LB/IC=utag_data[\"appointment_placed_day\"] = \"", "RB/IC=\";","ORD=All", LAST);
	
	//web_reg_save_param("AvailMonth","LB/IC/ALNUMIC=utag_data[\"appointment_placed\"] = \"", "RB/IC/ALNUMIC=/^^/20^^\";","ORD=All", LAST);
	
	web_reg_find("Search=Body","Text/IC=Checkout","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_url("info", 
		"URL=https://{URL}/checkout/appointment-info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t28.inf", 
		"Mode=HTML",
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	if(atoi(lr_eval_string("{AvailSlot_count}"))==0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE, LR_FAIL);
	}
	
	DTC_PeakTimes("DTC_PeakTimes_Ajax");
	
	lr_think_time(Think_Time);
	
	return 0;
}

//Select Date

DTC_Select_Date(char *TxnName)
{
	
	/*For seperating date and time*/
	
	char AvailableSlot[25];
	char AvailTimeSlot[25];
	char SlotDate[25];
	char * token;
	char * token2, *token3;
	char *Time;
	char separators[] = "T";
	
	/*For selecting hour and minutes*/
	char AvailableSlot1[25];
	char AvailTimeSlot1[25];
	char AvailableMonth[10];
	char AvailableDay[10];
	char Time1[25];
	
	char *token1;
	char *Minutes;
	char separators1[] = ":";
	char separators2[] = "-";
	int Hours;
	char *Month;
	char *Day;
	
	lr_param_sprintf("RandAvailSlot", "%s", lr_paramarr_random("AvailSlot"));
	
	if(strstr(lr_eval_string("{RandAvailSlot}"),"T")>0)
	{
		sprintf(AvailableSlot,"%s",lr_eval_string("{RandAvailSlot}")); 
        
	    token = (char *)strtok(AvailableSlot, separators);
	    
	    lr_save_string(token,"SlotDate");
	    
	    sprintf(AvailTimeSlot,"%s",lr_eval_string("{RandAvailSlot}"));
	    
	    Time = ((char *) strstr(AvailTimeSlot,"T")+1);
	    
	 //   token1 = (char *)strtok(Time, separators1);
	    
	 //   Minutes = ((char *) strstr(Time,":")+1);
	    
	    lr_save_string(Time,"SlotTime");
	    
	    lr_output_message("Date-%s, Time-%s",lr_eval_string("{SlotDate}"),lr_eval_string("{SlotTime}"));
	}
	
	sprintf(AvailableSlot1,"%s",lr_eval_string("{SlotTime}"));
	
	token1 = (char *)strtok(AvailableSlot1, separators1);
	
	sprintf(AvailTimeSlot1,"%s",lr_eval_string("{SlotTime}"));
	
	Minutes = ((char *) strstr(AvailTimeSlot1,":")+1);
	
	lr_output_message("%s %s",token1,Minutes);
	
	if(atoi(token1)>12)
	{
		Hours = atoi(token1)-12;
		
		sprintf(Time1,"%d:%s PM",Hours,Minutes);
	}
	
	else if(atoi(token1)==12)
	{
		sprintf(Time1,"%s:%s PM",token1,Minutes);
	}
	
	else
	{
		sprintf(Time1,"%s:%s AM",token1,Minutes);
	}
	
	lr_save_string(Time1,"AppointTime");
	
//	lr_output_message("%s", token);
	token2 = (char *)strtok(token, separators2);	//It fetches year
	
	sprintf(AvailableMonth,"%s",lr_eval_string("{SlotDate}"));
	
	Month = ((char *) strstr(AvailableMonth,"-")+1);
	
	lr_save_string(Month, "SlotDay");
	
	token3 = (char *)strtok(Month, separators2);	//It fetches Month
	
	sprintf(AvailableDay,"%s", lr_eval_string("{SlotDay}"));
	
	Day = ((char *) strstr(AvailableDay,"-")+1);	//It fetches Day
	
//	lr_output_message(token3);
	
	sprintf(SlotDate,"%s/%s/%s",token3,Day,token2);
	
	lr_save_string(SlotDate,"AppointDate");
	
	
	lr_param_sprintf("SchApptDate", "%s %s %s", lr_eval_string("{CertData}"), lr_eval_string("{AppointDate}"),lr_eval_string("{AppointTime}"));
		
	//web_reg_save_param("SlotTime","LB/IC=startTime\":", "RB/IC=:00\",\"endTime","ORD=All","NotFound=Warning", LAST);
	
	//"timeSlots":[{"blackout":false,"name"
	
	web_reg_find("Search=Body","Text/IC=true","SaveCount=TextCheck",LAST);
		
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	//https://stg.discounttire.com/schedule-appointment/getAvailableAppointmentSlots?appDate=10/19/2016&_=1476331148727
	web_url("getAvailableAppointmentSlots", 
		"URL=https://{URL}/schedule-appointment/isTimeSlotStillAvailable?appDate={AppointDate}&appTime={AppointTime}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);
	
/*	if (atoi((lr_eval_string("{SlotTime_count}"))) == 0)
	{
		
		lr_save_string(lr_eval_string("{AppointDate_1}"),"AppointDate");
		
		lr_param_sprintf("SchApptDate", "%s %s", lr_eval_string("{CertData}"), lr_eval_string("{AppointDate}"));
		
		web_reg_save_param("SlotTime","LB/IC=startTime\":", "RB/IC=:00\",\"endTime","ORD=All", LAST);
	
		web_reg_find("Search=Body","Text/IC=startTime","SaveCount=TextCheck",LAST);
		
		web_url("getAvailableAppointmentSlots", 
		"URL=https://{URL}/schedule-appointment/getAvailableAppointmentSlots?appDate={AppointDate_1_URL}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=",
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);
		
	}*/
	

	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{SchApptDate}")));
	
	lr_think_time(Think_Time);
	
	return 0;
}

//Click On Customer Infroamtion
DTC_Customer_Information_WA(char *TxnName)
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
	
	lr_save_string(Time1,"AppointTime");
	
/*	
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
	lr_param_sprintf("SchAppttime", "%s %s", lr_eval_string("{SchApptDate}"), lr_eval_string("{AppointTime}"));
	
	web_reg_find("Search=Body","Text/IC=Checkout","SaveCount=TextCheck",LAST);
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");

	lr_start_transaction(TxnName);
	
	web_submit_data("info_2", 
		"Action=https://{URL}/checkout/appointment-info?CSRFToken={CSRFToken}", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=",
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=pickUpOnly", "Value=false", ENDITEM, 
		"Name=appointmentDate", "Value={AppointDate}", ENDITEM, 
		"Name=appointmentTime", "Value={AppointTime}", ENDITEM, 
	//	"Name=CSRFToken", "Value={CSRFToken}", ENDITEM, 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{SchAppttime}")));
	
//	DTC_MiniCart("DTC_MiniCart_Ajax");
		
	lr_think_time(Think_Time);
	
	return 0;
}

DTC_ZipcodeInfo(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
		
	web_reg_find("Search=Body","Text/IC={\"zipCode\":\"","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("zipcodeInfo", 
		"URL=https://{URL}/zipcode/85255?", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t157.inf", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	return 0;
}


DTC_ActiveRegions(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
		
	web_reg_find("Search=Body","Text/IC=[{\"isocode\":\"","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("getActiveRegionsByCountryCode", 
	  	"URL=https://{URL}/country/getActiveRegionsByCountryCode?countryIso=US",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t157.inf", 
		LAST);
	
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertData}")));
	
	return 0;
}

DTC_RefreshCart(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC={\"appliedProductPromotion","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("miniCart", 
		"URL=https://{URL}/cart/json/refreshCart", 
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

DTC_PeakTimes(char *TxnName)
{
	PeakTime_MonthDay();
	
	lr_param_sprintf("CertAjaxData", "Month %s Day  %s ", lr_eval_string("{AvailMonth_1}"), lr_eval_string("{AvailDay_1}"));
	
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC=,\"message\":\"","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("peakTimes", 
		"URL=https://{URL}/schedule-appointment/peakTimes/?month={c_monthAjax}&dayOfWeek={c_dayAjax}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t48.inf", 
		LAST);
		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CertAjaxData}")));
	
	return 0;
}

DTC_Compare_SelectedProducts(char *TxnName)
{
	lr_save_string(TxnName, "Txn_Name");
	
	web_reg_find("Search=Body","Text/IC={\"compareType\":","SaveCount=TextCheck",LAST);
	
	web_add_auto_header("x-dynaTrace", "NA={Txn_Name}; SN=Hybris_STG_DTC_API; TE=Hybris_STG_API_LoadTest");
	
	lr_start_transaction(TxnName);
	
	web_url("CompareSelectedProducts", 
		"URL=https://{URL}/compare/selectedProduct", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t48.inf", 
		LAST);
		
	lr_end_transaction(TxnName, CheckIF_TransFailed(TxnName,lr_eval_string("{CSRFToken}")));
	
	return 0;
}