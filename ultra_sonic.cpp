#include <iostream>
#include "ultra_sonic.h"


const int ultra_sonic::sound_speed = 343; //meters/second

ultra_sonic::ultra_sonic():echo(new GPIOClass)
{
	echo->setval_gpio("in");
	echo->export_gpio();
}

ultra_sonic::ultra_sonic(GPIOClass* e) :echo(e)
{
	echo->setval_gpio("in");
	echo->export_gpio();
}

long double ultra_sonic::read()
{
	auto t = std::chrono::system_clock::now();//Start counting

	while (echo->getval_gpio != "1")
		{ __asm("nop"); }//Nothing until value is 1

	//Measure the diference between send and receive signal
	std::chrono::duration<long double> measure = std::chrono::system_clock::now() - t;
	
	return measure.count() * sound_speed;//Calculate the distance in meters
}
