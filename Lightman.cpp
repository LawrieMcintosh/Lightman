/*
  Lightman.h - Library for flashing LEDS.
  Created by Lawrence McIntosh 7 Jun 2014.
  Released into the public domain.
*/


#include "Arduino.h"
#include "Lightman.h"
#include "Tlc5940.h"
#include "QueueList.h"
#include "Console.h"
 
#define LIGHTMAN_PARAMETER_COUNT 5
#define NUMBER_OF_LIGHTS 16
#define NUMBER_OF_COLOURS 3
#define RED 0
#define GREEN 1
#define BLUE 2
#define START 0
#define END 1
#define CYCLES 2
#define CURVE 3
#define PARAM 4


int leds[NUMBER_OF_LIGHTS*NUMBER_OF_COLOURS][LIGHTMAN_PARAMETER_COUNT] = {0};

Lightman::Lightman()
{
//make an array of all the lights
//	Start End Cycles Curve Param
//start all brightnesses, starts, ends and Curves at 0	
	
 

}

/**
void Lightman::set_curve(int light_no, int start[], int end[], int cy, int curve, int curve_parameter) //array of integers to sub into lightmants master array
{
	//if (Console) Console.println("Cons: Called set_curve");
	Serial.println("(println: Called set_curve)");
	
	int led;
	 	
	for (int colour = 0; colour < NUMBER_OF_COLOURS; colour ++) {
		
		
		
		led = light_no + NUMBER_OF_LIGHTS * colour;
		
		Serial.println("(println: setting curve on led )" + led);
		
		leds[led][START] = start[colour];
		leds[led][END] = end[colour];
		leds[led][CYCLES] = cy;
		leds[led][CURVE] = curve;
		leds[led][PARAM] = curve_parameter;
		
   */


void Lightman::set_light(int light_no, int R, int G, int B) //
{
  //if (Console) Console.println("Cons: Called set_light");
  Serial.println("(println: Called set_light)");
  
  Tlc.set(light_no + NUMBER_OF_LIGHTS* RED, R);
  Tlc.set(light_no + NUMBER_OF_LIGHTS* BLUE, G);
  Tlc.set(light_no + NUMBER_OF_LIGHTS* GREEN, B);
}




void Lightman::cycle() {
	
	int curve;
	
	
	for (int led = 0; led < NUMBER_OF_LIGHTS * NUMBER_OF_COLOURS; led+=1) {
		
		curve = leds[led][CURVE];
		
		
		
		if (curve == 2) {
	        Serial.println("P: cycling linear");
		String stringOne = String(led);
		String stringCurve = String(curve);
		String printer = String("P: cycling curve on led" + stringOne + " curve: " + stringCurve);
		Serial.println(printer);
		
		
		int step = (leds[led][END] - leds[led][START])/leds[led][CYCLES];
		int current = Tlc.get(led);
		Serial.println(step);
		Serial.println(current);
		
		
		printer = String(abs(current - leds[led][END]));
		Serial.println("difference " + printer);
		if (abs(current - leds[led][END]) < abs(step)) {
			Tlc.set(led, leds[led][END]);
			Serial.println("setting at end ");
		}else {
			Tlc.set(led, current + step);
		}
		}
		
		
		
		
	}
	
}

//void Lightman::led2light(){}
//void Lightman::light2led(){}
//void Lightman::ledColour(){}

//new class - colour

//new class - curve

//set curve for array

//Queue curve for light
//Queue curve for array

//clear queue for light
//clear quene for array


void Lightman::display_all() {
	int testint1;
	int testint2;
	int li;
	
	for (li = 0; li <= NUMBER_OF_LIGHTS*NUMBER_OF_COLOURS-1; li+=1) {
		testint1 = li%NUMBER_OF_LIGHTS;
		testint2 = li/NUMBER_OF_LIGHTS;
		
		pMessage(String(testint1));
		
		pMessage(String(testint2));
		pMessage(String(leds[testint1][testint2]));
		
		pMessage(String(leds[li%NUMBER_OF_LIGHTS][li/NUMBER_OF_LIGHTS]));
		
		pMessage("light " + String(testint1));
		pMessage("Colour " + String(testint2));
		
		
		
		
		Tlc.set(li,leds[testint1][testint2]);
		//if (Console) Console.println("Updating in 5 seconds");
		//delay(5000);
		
		
		
	}
		Tlc.update(); 	
		//if (Console) Console.println("Done");	
}

void Lightman::pMessage(String msg) {
  if (Console) Console.println("C: " + msg);
  if (Serial) Serial.println("S: " + msg);
}
