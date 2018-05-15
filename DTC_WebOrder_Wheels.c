DTC_WebOrder_Wheels()
{
	
	//srand(time(NULL));
	
	DTC_Home("DTC_Home");
	
	DTC_SearchStore("DTC_WebOrder_SearchStore");

	DTC_MakeThisMyStore("DTC_WebOrder_MakeThisMyStore");
		
//	DTC_Shop_for_Vehicle("DTC_WebOrder_Click_ShopformyVehicle");
	
	DTC_Search("DTC_WebOrder_Click_Wheels","wheels");
		
	DTC_Click_Product("DTC_WebOrder_Click_Wheel_Product","wheels");
	
	
	DTC_AddtoCart("DTC_WebOrder_AddtoCart","wheels");
	
	DTC_View_Cart("DTC_WebOrder_ViewCart");
	
	DTC_Update_Cart("DTC_WebOrder_UpdateCart");
	
	DTC_Checkout_With_Appointment("DTC_WebOrder_Checkout_With_Appointment");
	
	DTC_Checkout_Without_Appointment("DTC_WebOrder_Checkout_Without_Appointment");
	
//	if(rand()%4<=1)
//	{
//		DTC_Checkout_With_Appointment("DTC_WebOrder_Checkout_With_Appointment");
//		
//		DTC_Select_Date("DTC_WebOrder_Select_Date");
//	
//		DTC_Customer_Information_WA("DTC_WebOrder_Customer_Information_WA");
//	}
//	
//	else
//	{
//		DTC_Checkout_Without_Appointment("DTC_WebOrder_Checkout_Without_Appointment");
//		
//		DTC_Select_Date("DTC_WebOrder_Select_Date");
//		
//		DTC_Customer_Information_WOA("DTC_WebOrder_Customer_Information_WOA");
//	}
//	
//	DTC_Schedule_Appointment("DTC_WebOrder_Schedule_Appointment");

	
	return 0;
}
