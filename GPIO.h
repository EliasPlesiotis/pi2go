#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <string>
#include "pch.h"
using namespace std;

class GPIOClass
{
	public:
	
		//Constructors
		GPIOClass();  // create a GPIO object that controls GPIO4 (default)
		GPIOClass(string); // create a GPIO object that controls GPIOx, where x is passed to this constructor
	
		//Functions
		int export_gpio(); // exports GPIO
		int unexport_gpio(); // unexport GPIO
		int setdir_gpio(string); // Set GPIO Direction
		int setval_gpio(string); // Set GPIO Value (putput pins)
		int getval_gpio(string&); // Get GPIO Value (input/ output pins)
		string get_gpionum(); // return the GPIO number associated with the instance of an object

	private:
		string gpionum; // GPIO number associated with the instance of an object
};

#endif
