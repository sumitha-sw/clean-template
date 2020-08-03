#include <gtest/gtest.h>
#include "vehicle.h"
 
TEST(COLLECT, when_a_vehicle_gets_input_measurements)
{ 
	class vehicle obj;
	
	struct input ip = {
	.id = 1000,
	.key = MOTOR_TEMP,
	.measurement = 30
        };

struct vehicle_input vip = obj.get_vehicle_data(ip);
ASSERT_EQ(vip.ip.id, ip.id);
ASSERT_EQ(vip.ip.key, ip.key);
ASSERT_EQ(vip.ip.measurement, ip.measurement);
ASSERT_EQ(vip.stat, VALID);
}

TEST(COLLECT, change_the_input_data_format_to_output_format)
{ 
	class vehicle obj;
	struct vehicle_output vop = {0};
	
	struct input ip = {
	.id = 2300,
	.key = BATTERY_TEMP,
	.measurement = 40
        };
	struct vehicle_input vip = {
	.ip = ip,
	.stat = VALID
        };

void obj.convert_vehicle_data_into_storage_format(vip, &vop);
ASSERT_EQ(vop.id, vip.ip.id);
ASSERT_EQ(vop.motor_temp, 0);
ASSERT_EQ(vop.battery_temp, 40);
ASSERT_EQ(vop.battery_soc, 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
