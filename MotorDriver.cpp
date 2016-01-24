
#include "GPIOClass.h"
#include "StepperMotor.h"

#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
volatile bool forward = false;
 
int main (void)
{

	// Sets GPIO pins to each phase of Motor driver
	StepperMotor stepper("18", "23", "24", "25");

	// Sets time to wait between each single step by means of miliseconds
	stepper.setPeriod(5);
	while(true){
		if(forward){
		  //rotate 2048*5ms to + direction
		  stepper.move(2048);
		  stepper.stop();
		  forward=false;
		}
		else
		{
		  //rotate 2048*5ms to - direction
		  stepper.move(-2048);
		  stepper.stop();
		  forward=true;
		}	
	}

}
