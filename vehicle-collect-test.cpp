#include <gtest/gtest.h>
#include "vehicle.h"
 
TEST(COLLECT, when_a_vehicle_gets_input_measurements)
	struct input ip = {
	.id = 1000,
	.key = MOTOR_TEMP,
	.measurement = 30
        };

struct vehicle_input vip = get_vehicle_data(ip);
ASSERT_EQ(vip.ip.id, ip.id);
ASSERT_EQ(vip.ip.key, ip.key);
ASSERT_EQ(vip.ip.measurement, ip.measurement);
ASSERT_EQ(vip.stat, VALID);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
