#include <iostream>
#include "vehicle.h"


struct Telematics Vehicle::get_input_message_frame(struct Input_Frame frame)
{
	struct Telematics message = {0};

	if((frame.vehicle_id < 1000) || (frame.vehicle_id > 9999)) {
		message.status = INVALID_FRAME;
		return message;
	}
	else
	{
		message.in_frame.vehicle_id = frame.vehicle_id;
	}

	if((frame.key >= 0) && (frame.key <=2))
	{
		message.in_frame.key = frame.key;
	}
	else
	{
		message.status = INVALID_FRAME;
		return message;
	}

	if((frame.measurement < 0) || (frame.measurement > 100))
	{
		message.status = INVALID_FRAME;
		return message;
	}
	else
	{
		message.in_frame.measurement = frame.measurement;
	}

	message.status = VALID_FRAME;

	return message;

}


void Vehicle::convert_input_frame_into_output_frame(struct Telematics message, struct Inventory *output_frame)
{

	if(message.status == VALID_FRAME) 
	{
	
	output_frame->vehicle_id = message.in_frame.vehicle_id;
	
	switch(message.in_frame.key)
	{
		case MOTOR_TEMPERATURE:
			{
				output_frame->motor_temperature = message.in_frame.measurement;
			}
			break;

		case BATTERY_TEMPERATURE:
			{
				output_frame->battery_temperature = message.in_frame.measurement;
			}
			break;

		case BATTERY_SOC:
			{
				output_frame->battery_soc = message.in_frame.measurement;
			}
			break;
	}

	}
	
	return;
}	

