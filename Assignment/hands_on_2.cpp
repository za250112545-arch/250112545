#include "dataset.h"
#include "discrete maths.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
int main(int argc, char* argv[])
{
	int y = 0,x[5];
	x[0] = 59;
	x[1] = 85;
	x[2] = 119;
	x[3] = 126;
	x[4] = 145;
    _dataset data = {
    	.x = {23,26,30,34,43,48,52,57,58},
        .y = {651,762,856,1063,1190,1298,1421,1440,1518}      
    };
    int B0 = (sumXexp2(data)*sumY(data)-sumX(data)*sumXY(data))/
             (SIZE*sumXexp2(data)-(sumX(data)*sumX(data)));
    int B1 = (SIZE*sumXY(data)-sumX(data)*sumY(data))/
	         (SIZE*sumXexp2(data)-(sumX(data)*sumX(data)));
	y = B0 + B1*x[0];
	printf("y = %i + %i*%i\n",B0,B1,x[0]);
	for (int i = 0; i<5; i++){
		y = B0 + B1*x[i];
		printf("%i %i\n",x[i],y);
	}
	
    return EXIT_SUCCESS;
}
