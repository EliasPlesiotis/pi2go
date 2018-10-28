#ifndef STEERING_CLASS_H
#define STEERING_CLASS_H

#include "motor.h"

class steering 
{
	private:
		motor* motorA;
		motor* motorB;
		int speedA, speedB;
	
	public:
		//Constructors
		steering();//Deafault
		steering(motor* m1, motor* m2);

		//Member Functions
		void start(); 
		void start(int i);
		void start(int A, int B);
		void stop();
		void reverse();
		void turn_l();
		void turn_r();
};

#endif