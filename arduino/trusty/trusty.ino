#include <ros.h>
#include <std_msgs/Int64.h>
ros::NodeHandle  nh;

std_msgs::Int64 int_msg;
ros::Publisher trust_level("trusty_trust_level", &int_msg);

int sample_rate = 30; // hz

// the setup routine runs once when you press reset:
void setup() {
  nh.initNode();
  nh.advertise(trust_level);
}

void loop() {
  int sensorValue = analogRead(A0);
  int_msg.data = sensorValue;
  trust_level.publish( &int_msg );
  nh.spinOnce();
  delay(1/sample_rate);
}
