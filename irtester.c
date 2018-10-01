#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
/*    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    printf("Alarm\n");
*/
	if(digitalRead(0) == 1){
		printf("digital read 1");
		digitalWrite(2, HIGH);
		digitalWrite(1, LOW);
		ifttt("http://red.eecs.yorku.ca:8080/trigger/alarm/with/key/ptailor", "RPi Message", "IR update", "Alarm Triggered");
		delay(200);
	}
	if(digitalRead(0) == 0){
		printf("digital read 0");
		digitalWrite(2, LOW);
		digitalWrite(1, HIGH);	delay(200);
		ifttt("http://red.eecs.yorku.ca:8080/trigger/alarm/with/key/ptailor", "RPi Message", "IR update", "Alarm off!"); 
		digitalWrite(1, LOW);
	}
  }
  /*NOTREACHED*/
  return 0 ;
}
