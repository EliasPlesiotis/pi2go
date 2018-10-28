#include <iostream>
#include "steering.h"

steering::steering()
{
	//random pins
	//only used during development
	motorA = new motor(new GPIOClass("24"), new GPIOClass("26"));
	motorB = new motor(new GPIOClass("19"), new GPIOClass("23"));
}

steering::steering(motor* m1, motor* m2) :motorA(m1), motorB(m2)
	{	}

void steering::start()
{
	//Tweek the start and reverse if the vehicle is going backwards
	motorA->start();
	motorB->reverse();
}


void steering::start(int i)//Not working
	{	}

void steering::start(int A, int B)//Not working
	{	}

void steering::stop()
{
	motorA->stop();
	motorB->stop();
}

void steering::reverse() 
{
	motorA->reverse();
	motorB->start();
}

void steering::turn_l()
{
	motorA->start();
	motorB->stop();
}

void steering::turn_r()
{
	motorB->start();
	motorA->stop();
}
