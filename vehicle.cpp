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


struct vehicle_output vehicle::convert_vehicle_data_into_storage_format(struct vehicle_input)
{
	struct vehicle_output vop = {0};

	return vop;
}	
