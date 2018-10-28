// Treat this class as private
// Only for making developers easier
// Never include this class.
// Instead use the steering class

#ifndef MOTOR_CLASS_h
#define MOTOR_CLASS_h

//inlude gpio class
#include "GPIO.h"


class motor 
{
	private:

		//variables
		GPIOClass* IN1;//pins
		GPIOClass* IN2;//pins
		int speed;

	public:

		//no default constructor here
		motor(GPIOClass*, GPIOClass*);
		~motor();

		//member functions
		int start();//start the motor
		int stop();//stop the motor
		int reverse();//reverse the rotation of the motor
};


#endif // !MOTOR_CLASS_h
