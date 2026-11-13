#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <string.h>

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
	FILE* OFH = fopen("tempOutput.txt", "w+");
	
	printf("Use default range? (68 - 76) [Y/N]\n");
	
	scanf(" %c", &defaultRange);
	
	if(defaultRange != 'Y'){
		printf("Enter minimum: ");
		scanf(" %d", &min);
		
		printf("Enter maximum: ");
		scanf(" %d", &max);
	}
	
	printf("Number of classrooms: ");
	scanf(" %d", &classrooms);
	int classTemps[classrooms][2];
	for(int i = 0; i < classrooms; i++){
		printf("Classroom %d temp reading: ", i + 1);
		scanf(" %d", &classTemps[i][0]);
	}
	
	for(int i = 0; i < classrooms; i++){
		if(classTemps[i][0] < min || classTemps[i][0] > max){
			gpioWrite(PIN, 1);
			classTemps[i][1] = 1;
		}
		else{
			classTemps[i][1] = 0;
		}
	}
	
	fprintf(OFH, "Temperature | System Status | Warning LED\n");
	for(int i = 0; i < classrooms; i++){
		fprintf(OFH, "%-13d", classTemps[i][0]);
		if(classTemps[i][1] == 1){
			fprintf(OFH, "%-16s%-12s", "WARNING", "ON");
		}
		else{
			fprintf(OFH, "%-16s%-12s", "NORMAL", "OFF");
		}
		fprintf(OFH, "\n");
	}
	
	fclose(OFH);
	
	return 0;
}
