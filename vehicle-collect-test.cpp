#include <gtest/gtest.h>
#include "vehicle.h"
 
TEST(COLLECT, when_a_vehicle_gets_input_measurements)
{ 
	class Vehicle obj;
	
	struct Input_Frame frame = {
	.vehicle_id = 1000,
	.key = MOTOR_TEMPERATURE,
	.measurement = 30
        };

struct Telematics msg = obj.get_input_message_frame(frame);
ASSERT_EQ(msg.in_frame.vehicle_id, frame.vehicle_id);
ASSERT_EQ(msg.in_frame.key, frame.key);
ASSERT_EQ(msg.in_frame.measurement, frame.measurement);
ASSERT_EQ(msg.status, VALID_FRAME);
}

TEST(COLLECT, change_the_input_data_format_to_output_format)
{ 
	class Vehicle obj;
	struct Inventory output_frame = {0};
	
	struct Input_Frame frame = {
	.vehicle_id = 2300,
	.key = BATTERY_TEMPERATURE,
	.measurement = 40
        };

	struct Telematics msg = {
	.in_frame = frame,
	.status = VALID_FRAME
        };

void obj.convert_input_frame_into_output_frame(msg, &output_frame);
ASSERT_EQ(output_frame.vehicle_id, msg.in_frame.vehicle_id);
ASSERT_EQ(output_frame.motor_temperature, 0);
ASSERT_EQ(output_frame.battery_temperature, 40);
ASSERT_EQ(output_frame.battery_soc, 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
