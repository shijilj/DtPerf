Action1()
{

	char Fit[][5][10] = {{"2011","TOYOTA","9041","13828","00000NMA"},{"2012","ACURA","2956","17110","000001XI"},{"2014","FORD","5193","7736","00000EIB"}};
	int i,j;
	
	i=rand () %3;
	lr_save_string(Fit[i][0],"Fitment_Year");
	lr_save_string(Fit[i][1],"Fitment_Make");
	lr_save_string(Fit[i][2],"Fitment_Model");
	lr_save_string(Fit[i][3],"Fitment_Trim");
	lr_save_string(Fit[i][4],"Fitment_Assembly");
    
	return 0;
}
