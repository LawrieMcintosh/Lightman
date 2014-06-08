/*
  Lightman.h - Library for flashing LEDS.
  Created by Lawrence McIntosh 7 Jun 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Lightman.h"
#include "Tlc5940.h"
#include "Console.h"

#define LIGHTMAN_PARAMETER_COUNT 6
#define NUMBER_OF_LIGHTS 16

Lightman::Lightman()
{
//make an array of all the lights
//light	Current_Red Current_Green Current_Blue Start_Red Start_Green Start_Blue Start_Red Start_Green Start_Blue Cycles Curve CurveParameter
//starT all brightnesses, starts, ends and Curves at 0	
	
int l[6];
int m[6] ={0};	
int n[NUMBER_OF_LIGHTS];
int o[NUMBER_OF_LIGHTS] = {0};
int lights[NUMBER_OF_LIGHTS*3][LIGHTMAN_PARAMETER_COUNT] = {0};
}

void Lightman::set_curve(  ) //array of integers to sub into lightmants master array
{
	if (Console) Console.println("Called set_curve");
	
	//for each line in the parameter array
	//put it in the right spot 
 
 
}

void Lightman::set_light() //light_no, R,G,B
{
  if (Console) Console.println("Called set_light");
}