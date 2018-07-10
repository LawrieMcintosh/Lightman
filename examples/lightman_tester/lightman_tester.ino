#include <Lightman.h>
#include <Console.h>
#include "Tlc5940.h"

Lightman larray;

void setup() {
  // put your setup code here, to run once:

  Console.begin();  // Initialize Console
  while(!Console);
  if (Console) Console.println("Lightman tester console");

}

void loop() {
  // put your main code here, to run repeatedly:
  Tlc.init(500);
  Tlc.update(); 

  larray.set_light();
  larray.set_curve();



}
