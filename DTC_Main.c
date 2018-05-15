DTC_Main()
{
		
	LPCSTR URLStatusValue;
	LPCSTR TestTypeValue;
	
	URLStatusValue=URLStatus;//lr_get_attrib_string("URLStatus");
	
	TestTypeValue = TestType; //lr_get_attrib_string ("TestType");
	
	srand(time(NULL));
	
	if((id==-1) || stricmp(lr_eval_string(TestTypeValue),"BVT")==0 || stricmp(lr_eval_string(TestTypeValue),"Smoke")==0)
	{
		lr_output_message("Running via Standalone/Vugen or Buildverification");
		rand_iter_num = 1;
	}
	
	else
	{
		rand_iter_num = rand() % 100;
	}
	
	if(stricmp(lr_eval_string(URLStatusValue),"QA")==0)
	{
//		lr_save_string(lr_get_attrib_string("QAURL"),"URL");
		lr_save_string(QAURL,"URL");
	}
	
	else if(stricmp(lr_eval_string(URLStatusValue),"PE")==0)
	{
//		lr_save_string(lr_get_attrib_string("PEURL"),"URL");
		lr_save_string(PEURL,"URL");
	}
	
	else
	{
//		lr_save_string(lr_get_attrib_string("STGURL"),"URL");
		lr_save_string(STGURL,"URL");
	}
	//lr_start_transaction("DTC_Main_Iteration");
		
	web_add_auto_filter("Action=Exclude", 
	    "Host=www.youtube.com",
	    LAST );

	
	DTC_Vuser_Startup();
	
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"3")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"3")==0)||(stricmp(TestCase,"All")==0))
	{
		lr_save_string(("3"),"TestCaseNo");
		DTC_Schedule_Service();
	}
				
//	if((stricmp(lr_get_attrib_string("TestCase"),"1")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"1")==0)||(stricmp(TestCase,"All")==0))
	{
		lr_save_string(("1"),"TestCaseNo");
		DTC_WebOrder_Tires();
	}
		
//	if((stricmp(lr_get_attrib_string("TestCase"),"2")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"2")==0)||(stricmp(TestCase,"All")==0))
	{	
		lr_save_string(("2"),"TestCaseNo");
		DTC_Tire_Types();
	}
		
//	if((stricmp(lr_get_attrib_string("TestCase"),"4")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"4")==0)||(stricmp(TestCase,"All")==0))
	{
		lr_save_string(("4"),"TestCaseNo");
		DTC_Search_Promotions();
	}
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"5")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"5")==0)||(stricmp(TestCase,"All")==0))
	{
		lr_save_string(("5"),"TestCaseNo");
		DTC_Wheel_Types();
	}
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"6")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
	if((stricmp(TestCase,"6")==0)||(stricmp(TestCase,"All")==0))
	{	
		lr_save_string(("6"),"TestCaseNo");
		DTC_Tire_Wheel_Sort_and_Filter();
	}
	
//	if((stricmp(lr_get_attrib_string("TestCase"),"7")==0)||(stricmp(lr_get_attrib_string("TestCase"),"All")==0))
		if((stricmp(TestCase,"7")==0)||(stricmp(TestCase,"All")==0))
	{
		lr_save_string(("7"),"TestCaseNo");
		//DTC_Home("DTC_Home");
	}
	

	//lr_end_transaction("DTC_Main_Iteration", LR_AUTO);

	return 0;
}
