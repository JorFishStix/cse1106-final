#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int main(int argc, char* argv[]){
	gpioInitialise();
	gpioSetMode(PIN, PI_OUTPUT);
	gpioWrite(PIN, 1); // Power on
	
	getchar(); // Wait for input, power off
	gpioWrite(PIN, 0);
	
	getchar(); // Wait for input, terminate
	gpioTerminate();
	return 0;
}
