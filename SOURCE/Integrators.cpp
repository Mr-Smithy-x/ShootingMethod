#include "Integrators.h"
#include "../constants.h"
#include "DiffEqns.h"

void evolve(double *pos, double *vel, double *time)
{
	*pos=*pos + *vel*DT + 0.5*(y2nd(*pos, *vel, *time))*DT*DT;
	*vel=*vel + y2nd(*pos, *vel, *time)*DT;
	*time=*time+DT; 
}

