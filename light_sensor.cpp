#include <iostream>
#include "light_sensor.h"


light_sensor::light_sensor():state(false)
{
	//Only for developing purposes
	in = new GPIOClass();
	in->setdir_gpio("in");
	in->export_gpio();
}

light_sensor::light_sensor(GPIOClass* in) :in(in), state(false)
{
	in->setdir_gpio("in");
}

bool light_sensor::read()
	{ return in->getval_gpio == "1" ? 1 : 0; }
