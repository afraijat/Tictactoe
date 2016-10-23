#include <stdio.h>
#include <math.h>
int main() {
	//declare variables and their types
	float x, y, radius;
	//Now enable scanf to enter values into command prompt
	scanf("%f %f", &x, &y);
	//write the equation of circle
	radius = sqrt(x * x + y * y);
	//use conditional operator
	radius <= 5 ? printf("yes\n") : printf("no\n");
	return 0;
}