#include <stdio.h>

int main() {
    
    const float pi = 3.14159;
    float r, sphere_vol;
    
    printf("Let us calculate the volume of a sphere!");
    printf("\n****************************************\n");
    printf("Input radius value: ");
    scanf(" %f", &r);
    
    sphere_vol = (4.00/3.00)*(pi)*r*r*r;
    
    printf("The volume is: %.3f", sphere_vol);
    
    return 0;
}
