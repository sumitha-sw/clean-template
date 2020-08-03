#ifndef __VEHICLE_H
#define __VEHICLE_H

//#include <iostream>

enum InputStatus
{
	INVALID = 0,
	VALID
};

enum Features
{
	MOTOR_TEMP = 0,
	BATTERY_TEMP,
	BATTERY_SOC
};

struct input
{
	int id;
	enum Features key;
	float measurement;
};


struct vehicle_input
{
	struct input ip;
	enum InputStatus stat;
};

struct vehicle_output
{
	int id;
	float motor_temp;
	float battery_temp;
	float battery_soc;
};

class vehicle
{

public:
struct vehicle_input get_vehicle_data(struct input ip);
void convert_vehicle_data_into_storage_format(struct vehicle_input vip, struct vehicle_output *vop);

};

#endif
