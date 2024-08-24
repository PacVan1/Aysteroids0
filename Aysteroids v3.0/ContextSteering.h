#pragma once

#include "ISpaceObject.h" 
#include <vector> 

class ContextSteering
{
public: 
	static const int NUMBER_OF_DIRECTIONS = 8; 

private: 
	static vec2 directionsMap[NUMBER_OF_DIRECTIONS]; 

	Transform* transformPtr;

	float vision; 
	float weightMultiplier;   

public: 
	ContextSteering(Transform* transformPtr, float vision, float weightMultiplier);  

	vec2 CalculateDesire(std::vector<float>& interestMap, std::vector<float>& dangerMap);  
	std::vector<float> CalculateInterest(ISpaceObject& target, bool followTarget);      
	std::vector<float> CalculateDanger(const std::vector<ISpaceObject*>& obstacles); 

private: 
	float Mapf(float value, float oldMin, float oldMax, float newMin, float newMax);

public: 
	static void s_SetDirectionsMap(); 
};

