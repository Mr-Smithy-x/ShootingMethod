#include <iostream>
#include <cmath>
#include "SOURCE/DiffEqns.h"
#include "SOURCE/Integrators.h"
#include "constants.h"



int main()
{
	double y,vy,t;		//State variables (m,m/s,s)
	double ya,yb,vya,ta,tb; //Boundary and initial conditions
	bool accurate;		//Check if answer is accurate enough
	double guess;
	double *pos,*vel,*time; //Pointers to my state variables
	pos = &y;
	vel = &vy;
	time = &t;
	
	y=vy=t=0.0;
	accurate=false;

	//TEMP//Hardcode in boundary and initial conditions to get code running
	ya=0.0;
	yb=32.13;
	ta=0.0;
	tb=5.5;
	vya=0.0;
	//Guess at vya
	guess=1.0;	

	while(accurate==false)
//	for(int i=0; i<10; i++)
	{
		//y=ya;
		vya=guess;
		vy=vya;
		//t=ta;
		std::cout << y << " " << vy << " " << t << std::endl;
		
		while(t<=tb)
		{
			evolve(pos,vel,time);	//evolve in time.
		//	y=pos;
		//	vy=vel;
		//	t=time;
		}
		std::cout << y << " " << vy << " " << t << std::endl;

		if(std::abs(y-yb) < ACC)
		{
			accurate=true;
		}

		else if(std::abs(y-yb) > ACC)
		{
			if(y<yb)
			{
				guess=(guess+(guess+vya))/2.0;
			}
			else if(y>=yb)
			{
				guess=guess/2.0;
			}
		}
		if(accurate==false)
		{
			y=ya;
			t=ta;
		}
	}

return 0;
}


