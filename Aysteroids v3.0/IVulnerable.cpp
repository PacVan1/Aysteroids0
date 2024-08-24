#include "IVulnerable.h"

IVulnerable::IVulnerable(const float max) : 
	health(max)
{
}

void IVulnerable::Decrease(const float decrement)
{
	health.Decrease(decrement);
	
	if (health.current <= 0.0f)
		dead = true; 
}
