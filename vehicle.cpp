#include <iostream>
#include "vehicle.h"


struct vehicle_input vehicle::get_vehicle_data(struct input ip)
{
	struct vehicle_input vip = {0};

	if((ip.id < 1000) || (ip.id > 9999)) {
		vip.stat = INVALID;
		return vip;
	}
	else
	{
		vip.ip.id = ip.id;
	}

	if((ip.key >= 0) && (ip.key <=2))
	{
		vip.ip.key = ip.key;
	}
	else
	{
		vip.stat = INVALID;
		return vip;
	}

	if((ip.measurement < 0) || (ip.measurement > 100))
	{
		vip.stat = INVALID;
		return vip;
	}
	else
	{
		vip.ip.measurement = ip.measurement;
	}

	vip.stat = VALID;

	return vip;

}


void vehicle::convert_vehicle_data_into_storage_format(struct vehicle_input vip, struct vehicle_output *vop)
{

	if(vip.stat == VALID) 
	{
	
	vop->id = vip.ip.id;
	
	switch(vip.ip.key)
	{
		case MOTOR_TEMP:
			{
				vop->motor_temp = vip.ip.measurement;
			}
			break;

		case BATTERY_TEMP:
			{
				vop->battery_temp = vip.ip.measurement;
			}
			break;

		case BATTERY_SOC:
			{
				vop->battery_soc = vip.ip.measurement;
			}
			break;
	}

	}
	
	return;
}	

