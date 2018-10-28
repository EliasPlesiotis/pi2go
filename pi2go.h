#ifndef	PI2GO_CLASS_H
#define PI2GO_CLASS_H

//Includes
#include "motor.h"
#include "light_sensor.h"
#include "steering.h"
#include "ultra_sonic.h"


class pi2go
{
	private:
		//pi2go has

		//steering
		steering* st;

		//light sensors
		light_sensor* up_left;//first(1)
		light_sensor* up_right;//second(2)
		light_sensor* down_left;//thrird(3)
		light_sensor* down_right;//fourth(4)
		light_sensor* front;//fifth(5)

		//ultra sonic sensor
		ultra_sonic* us;

	public:

		//Constructors
		//Here use the default
		//Unless your pi2go differs from the default gpio/pin layout
		pi2go();
		pi2go(light_sensor*, light_sensor*,
			  light_sensor*, light_sensor*,
			  light_sensor*, steering*,
			  ultra_sonic*);

		//Light Sensor functions
		bool read_ls();//Get 1 if only one sensor is returning 1
		bool read_ls(int);//Get the value of the specified light sensor
					   //Look the declaratio of the light sensors
					   //Each number(int) represents the int to which is used to call the read function

		//Ultra Sonic functions
		long double read_us();

		//Steeing functions
		void start();
		void stop();
		void reverse();
		void turn_l();
		void turn_r();
};

#endif
