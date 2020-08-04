#ifndef __VEHICLE_H
#define __VEHICLE_H

#include <iostream>

#define TRUE 1
#define FALSE 0

enum InputStatus
{
	INVALID_FRAME = 0,
	VALID_FRAME
};

enum Measures
{
	MOTOR_TEMPERATURE = 0,
	BATTERY_TEMPERATURE,
	BATTERY_SOC,
	MEASURES_AVAILABLE
};

struct Input_Frame
{
	int vehicle_id;
	enum Measures key;
	float measurement;
};


struct Telematics
{
	struct Input_Frame in_frame;
	enum InputStatus status;
};

struct Inventory
{
	int vehicle_id;
	float motor_temperature;
	float battery_temperature;
	float battery_soc;
};

class Vehicle
{
public:
struct Telematics get_input_message_frame(struct Input_Frame);
void convert_input_frame_into_output_frame(struct Telematics , struct Inventory *);
};

typedef int (*validation)(float);
typedef void (*copy_measurement)(struct Inventory*, float);

struct measures_table
{
enum Measures key;
validation validate_measures; 
copy_measurement copy_measures;
};

#endif
