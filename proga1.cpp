#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

float Koren(float x)													
{
	float y_tochnoe;
	y_tochnoe = exp(x*log(x+1));
	return y_tochnoe;
} 

float formula_Nyutona(float x, float m, float z)						
{
	float y_Nyutona;
	y_Nyutona = 1/m*((m-1)*z+(((x+1)/(exp((m-1)*log(z))))));
	return y_Nyutona;
} 

main()
{
	float y_Nyutona, y_tochnoe, x, e, m, z;
	int i; 
	e=0.000001;
	printf (" Argument |      y_Nyutona    |    y_tochnoe   | \n"); 
	printf ("----------+-------------------+----------------+\n"); 
	for (x=0.01; x<0.11; x+=0.01)										//öèêë èçìåíåíèÿ àðãóìåíòà
	{
		printf (" %.2f    ",x); 
		y_Nyutona=x+1;
		m=1/x;
		do																//öèêë ðàñ÷¸òà çíà÷åíèÿ ôóíêöèè ïî 
			{															//ôîðìóëå Íüþòîíà
				z = y_Nyutona;
				y_Nyutona=formula_Nyutona( x , m , z);
			}
		while(fabs(y_Nyutona-z)>e);
		printf(" |      %.7f   ", y_Nyutona); 
		y_tochnoe=Koren(x);												//ïîäñ÷¸ò òî÷íîãî çíà÷åíèÿ ôóíêöèè
		printf(" |    %.7f   |\n",y_tochnoe); 
		printf ("----------+-------------------+----------------+\n"); 	
	}
	
	getch();
}
