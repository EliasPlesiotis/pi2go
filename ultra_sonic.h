#ifndef ULTRA_SONIC_H
#define ULTRA_SONIC_H
#include "GPIO.h"
#include <chrono>

//FOR MAX ACCURRACY
//After initialization 
//Run the read() function on a separete thread 
//So it wont interfier with the rest of the program 

class ultra_sonic
{
	private:
		static const int sound_speed;
		GPIOClass* echo;

	public:
		ultra_sonic();
		ultra_sonic(GPIOClass*);

		long double read();
};

#endif