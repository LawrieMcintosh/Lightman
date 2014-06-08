/*
  Lightman.h - Library for flashing LEDS.
  Created by Lawrence McIntosh 7 Jun 2014.
  Released into the public domain.
*/
#ifndef Lightman_h
#define Lightman_h

#include "Arduino.h"
#include "Tlc5940.h"

class Lightman
{
  public:
	Lightman();  
    void set_light(); //int pin
    void set_curve(); //int light_no, int R, int G, int B
  private:
	
		
};

#endif