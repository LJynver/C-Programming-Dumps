#include <stdio.h>
#define pi 3.14159

float volSphere (float radius);

int main () {
	
	float rad_inp;
	
	printf("Let us calculate the volume of a sphere!");
	printf("\n****************************************\n");
	
	printf("Input the value of the radius here: ");
	scanf("%f", &rad_inp);
	
	printf("The volume of the sphere is: %.3f", volSphere(rad_inp));
	
	return 0;
}

float volSphere (float radius) {
	
	float volume;
	
	volume = (4.000/3.000)*pi*radius*radius*radius;
	
	return volume;
}
