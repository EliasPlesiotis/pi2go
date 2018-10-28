#include <iostream>
#include "motor.h"


motor::motor(GPIOClass* in1, GPIOClass* in2): IN1(in1), IN2(in2)
{
	//Setting the GPIOClass objects direction as output and exporting them
	IN1->setdir_gpio("out");
	IN2->setdir_gpio("out");

	//Export the pins
	IN1->export_gpio();
	IN2->export_gpio();
}

motor::~motor()
{
	//Set values to 0 and unexport the GPIOClass objects
	IN1->setval_gpio("0");
	IN2->setval_gpio("0");
	IN1->unexport_gpio();
	IN2->unexport_gpio();

}

int motor::start()
{
	//Creating diference in voltage to make the DC motor move
	this->IN1->setval_gpio("1");//set the voltage to high
	this->IN2->setval_gpio("0");//set the voltage to low
}

int motor::stop()
{
	//Low the voltage at both GPIOClass objects
	this->IN1->setval_gpio("0");
	this->IN2->setval_gpio("0");
}

int motor::reverse()
{
	//Reverse the flow of current to achieve reverse motion
	this->IN1->setval_gpio("0");
	this->IN2->setval_gpio("1");
}
