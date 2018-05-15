vuser_init()
{
	lr_whoami(&id, &vuser_group, &scid);
	
	return 0;
}
