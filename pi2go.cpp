#include <iostream>
#include "pi2go.h"


//Constructors
pi2go::pi2go() 
{
	//Light Sensors
	this->up_left = new light_sensor(new GPIOClass("11")); 
	this->up_right = new light_sensor(new GPIOClass("7")); 
	this->down_left = new light_sensor(new GPIOClass("12")); 
	this->down_right = new light_sensor(new GPIOClass("15")); 
	this->front = new light_sensor(new GPIOClass("13"));

	//Ultra Sonic Sensor
	this->us = new ultra_sonic(new GPIOClass("8"));

	//Steering/Motor
	this->st = new steering(
		                    new motor(
							          new GPIOClass("24"), 
							          new GPIOClass("26")
						             ), 
			                new motor(
							          new GPIOClass("19"), 
							          new GPIOClass("21")
						              )
						   );
}

pi2go::pi2go(light_sensor* ul, light_sensor* ur,
	light_sensor* dl, light_sensor* dr,
	light_sensor* f, steering* s,
	ultra_sonic* u)
	:up_left(ul), up_right(ur),
	down_left(dl), down_right(dr),
	front(f), st(s), us(u)
{ /*Empty Body*/ }


//Sensor Functions
//Light Sensor
bool pi2go::read_ls()
{
	//Check one by one all the light sensors
	return (up_left->read() || up_right->read() ||
			down_left->read() || down_right->read() ||
			front->read()) ? 1 : 0;

}

bool pi2go::read_ls(int i)
{
	//Check for a specific light sensor
	if (i == 1)
		return up_left->read() ? 1 : 0;
	if (i == 2)
		return up_right->read() ? 1 : 0;
	if (i == 3)
		return down_left->read() ? 1 : 0;
	if (i == 4)
		return down_right->read() ? 1 : 0;
	if (i == 5)
		return front->read() ? 1 : 0;
}

//Ultra Sonic Sensor
long double pi2go::read_us()
{
	//Get the distance between pi2go and an objtackle
	return us->read();
}

//Steering Functions
void pi2go::start()
//Go forward
	{ st->start(); }

void pi2go::stop()
//Stop any movement
	{ st->stop; }

void pi2go::reverse()
//Reverse the rotation of the wheels
	{ st->reverse(); }

void pi2go::turn_l()
//Turn left
	{ st->turn_l(); }

void pi2go::turn_r()
//Turn right
	{ st->turn_r(); }
