#include <iostream>
#include "vehicle.h"

using namespace std;


int validate_motor_temperature(float measurement)
{
	if((measurement < 0) || (measurement > 300))
	{
		return FALSE;
	}

	return TRUE;
}
int validate_battery_temperature(float measurement)
{

	if((measurement < 0) || (measurement > 200))
	{
		return FALSE;
	}

	return TRUE;
}
int validate_battery_soc(float measurement)
{
	if((measurement < 0) || (measurement > 100))
	{
		return FALSE;
	}

	return TRUE;
}

void copy_motor_temperature(struct Inventory* output_frame, float measurement)
{

    output_frame->motor_temperature = measurement;
    
    return;

}

void copy_battery_temperature(struct Inventory* output_frame, float measurement)
{

    output_frame->battery_temperature = measurement;
    
    return;

}

void copy_battery_soc(struct Inventory* output_frame, float measurement)
{

    output_frame->battery_soc = measurement;
    
    return;

}

struct measures_table msg_table[] = { 
	{
		.key = MOTOR_TEMPERATURE,
		.validate_measures = validate_motor_temperature,
		.copy_measures = copy_motor_temperature
	},
	{
		.key = BATTERY_TEMPERATURE,
		.validate_measures = validate_battery_temperature,
		.copy_measures = copy_battery_temperature
	},
	{
		.key = BATTERY_SOC,
		.validate_measures = validate_battery_soc,
		.copy_measures = copy_battery_soc
	}

};

struct Telematics Vehicle::get_input_message_frame(const struct Input_Frame frame)
{
	struct Telematics message {0};
	message.status = INVALID_FRAME;
	int i;

	if((frame.vehicle_id < 1000) || (frame.vehicle_id > 9999)) {
		return message;
	}
	else
	{
		message.in_frame.vehicle_id = frame.vehicle_id;
	}

	for(i=0;i <= MEASURES_AVAILABLE;i++)
	{
		if(i == frame.key)
		{
   			if(msg_table[i].validate_measures(frame.measurement))
			{
				message.in_frame.key = frame.key;
			  	message.in_frame.measurement = frame.measurement;
				message.status = VALID_FRAME;
				break;
			}
		}

	}

	return message;

}


void Vehicle::convert_input_frame_into_output_frame(const struct Telematics message, struct Inventory *output_frame)
{
	int k = 0;

	if(message.status == VALID_FRAME) 
	{
	
	output_frame->vehicle_id = message.in_frame.vehicle_id;
	
	for(k=0;k <= MEASURES_AVAILABLE;k++)
	{
		if(k == message.in_frame.key)
		{
			msg_table[k].copy_measures(output_frame, message.in_frame.measurement);
			break;
		}
	}

	}
	
	return;
}	

