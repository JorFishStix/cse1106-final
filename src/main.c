#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int main(int argc, char* argv[]){
	gpioInitialise();
	gpioSetMode(PIN, PI_OUTPUT);
	gpioWrite(PIN, 0);
	
	int min = 68;
	int max = 76;
	char defaultRange;
	int currentTemp;
	int classrooms = 1;
	int warning = 0;
	
	printf("Use default range? (68F - 76F) [Y/N]\n");
	
	scanf(" %c", &defaultRange);
	
	if(defaultRange != 'Y'){
		printf("Enter minimum: ");
		scanf(" %d", &min);
		
		printf("Enter maximum: ");
		scanf(" %d", &max);
	}
	
	printf("Number of classrooms: ");
	scanf(" %d", &classrooms);
	int classTemps[classrooms];
	for(int i = 0; i < classrooms; i++){
		printf("Classroom %d temp reading: ", i + 1);
		scanf(" %d", &classTemps[i]);
	}
	
	for(int i = 0; i < classrooms; i++){
		if(classTemps[i] < min || classTemps[i] > max && !warning){
			gpioWrite(PIN, 1);
			warning = 1;
		}
	}
	getchar();
	return 0;
}
