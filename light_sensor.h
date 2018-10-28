#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "GPIO.h"


//Run on a separate thread all the light sensors
class light_sensor 
{
	private:
		GPIOClass* in;
		bool state;

	public:
		//Constructors
		light_sensor();
		light_sensor(GPIOClass*);
		
		//Menber functions
		bool read();
};

#endif