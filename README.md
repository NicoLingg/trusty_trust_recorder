# Trusty Trust Recorder

This repository contains the code for the Trusty Trust Recorder, a ROS package for monitoring and recording the level of trust in human-robot interactions using Trusty, a device designed for this specific purpose.

## Dependencies
- [rosserial_arduino](http://wiki.ros.org/rosserial_arduino)

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

You need to have a working installation of ROS. Please refer to the [official ROS installation guide](http://wiki.ros.org/ROS/Installation) if you haven't set up ROS on your system yet.

You also need to install the rosserial_arduino package:

```bash
sudo apt-get update
sudo apt-get install ros-<your_ros_distro>-rosserial-arduino
```
Replace `<your_ros_distro>` with your ROS distribution name (like melodic, noetic, etc).

### Installation

Clone the repository into your catkin workspace:

```bash
cd ~/catkin_ws/src
git clone https://github.com/[username]/trusty_trust_recorder.git
```

Use the Arduino IDE or your preferred platform to upload the code in the `trusty_trust_recorder/arduino/trusty/trusty.ino` file to your Arduino device. Make sure the correct port is selected.

Return to your catkin workspace and use `catkin_make` to build the project:

```bash
cd ~/catkin_ws
catkin_make
```

Source your workspace's setup file:

```bash
source devel/setup.bash
```

### Building the Trusty Device

You will need the following items to build the Trusty device:

- Slot Car Carrera GO Speed Controller ([e.g. from Amazon](https://www.amazon.co.uk/Carrera-GO-20061511-Controller-Die-Cast/dp/B0002FQKO8/))
- 10k Potentiometer ([e.g. from RS](https://uk.rs-online.com/web/p/potentiometers/2499367))

Steps:
1. Open the slot car controller and remove the coil, wires, and switch (keep the board).
   
   ![Open Controller](./images/open_controller.jpg)

2. Attach the potentiometer to the rod of the slot controller.
   
   ![Attach Potentiometer](./images/attach_potentiometer.jpg)

3. Wire up the potentiometer according to the datasheet and Arduino.
   
   ![Wire Potentiometer](./images/wire_potentiometer.jpg)


### Running the Node

Before launching the node, ensure that the correct port is set in the `trusty_acqusition.launch` file. This should be the port to which your Arduino device is connected.

To start recording trust levels, use roslaunch:

```bash
roslaunch trusty_trust_recorder trusty_acqusition.launch
```

To monitor trust levels, you can echo the appropriate rostopic:

```bash
rostopic echo /trusty_trust_level
```

## Contributing

If you have improvements or features you would like to add, please create a pull request.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
