#include "ContextSteering.h"

vec2 ContextSteering::directionsMap[] = {};  

ContextSteering::ContextSteering(Transform* transformPtr, float vision, float weightMultiplier)  
{
	this->transformPtr = transformPtr; 
	this->vision = vision; 
	this->weightMultiplier = weightMultiplier; 
}

vec2 ContextSteering::CalculateDesire(std::vector<float>& interestMap, std::vector<float>& dangerMap)
{
	vec2 result = {};  

	std::vector<float> resultMap(NUMBER_OF_DIRECTIONS); 
	int numberOfIndices = 0; 

	for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++) 
	{
		resultMap[i] = std::max(-1.0f, interestMap[i] - dangerMap[i]); 
		if (resultMap[i] != 0.0f) 
			numberOfIndices++;  

		vec2 resultSlot = vec2(directionsMap[i]) * resultMap[i]; 
		result += resultSlot; 
	}

	if (result.Mag() > 0) 
		result /= numberOfIndices; 

	return result; 
}

std::vector<float> ContextSteering::CalculateInterest(ISpaceObject& target, bool followTarget)
{
	std::vector<float> interestMap(NUMBER_OF_DIRECTIONS); 
	vec2 dir = vec2::Sub(target.transform.position, transformPtr->position);   

	for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
	{
		float interestDot = vec2::Dot(directionsMap[i], dir) / (directionsMap[i].Mag() * dir.Mag()); 
		interestMap[i] = interestDot;
	}

	if (!followTarget)
		return interestMap;

	for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++) 
		interestMap[i] *= -1; 

	return interestMap;  
}

std::vector<float> ContextSteering::CalculateDanger(const std::vector<ISpaceObject*>& obstacles) 
{
	std::vector<float> dangerMap(NUMBER_OF_DIRECTIONS); 

	for (int i = 0; i < obstacles.size(); i++) 
	{
		vec2 dir = obstacles[i]->transform.position - transformPtr->position;  
		float weight = Mapf(std::min(dir.Mag(), vision), vision, 0.0f, 0.0f, weightMultiplier);

		for (int j = 0; j < NUMBER_OF_DIRECTIONS; j++)
		{
			float dangerDot = vec2::Dot(directionsMap[i], dir) / (directionsMap[i].Mag() * dir.Mag());
			float potentialDanger = dangerDot * weight;

			if (potentialDanger > dangerMap[i])
				dangerMap[i] = potentialDanger;
		}
	}

	return dangerMap;
}

float ContextSteering::Mapf(float value, float oldMin, float oldMax, float newMin, float newMax)
{
	return (value - oldMin) / (oldMax - oldMin) * (newMax - newMin) + newMin;  
}

void ContextSteering::s_SetDirectionsMap() 
{
	float increment = 360.0f / NUMBER_OF_DIRECTIONS; 

	for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++) 
		directionsMap[i] = vec2::FromAngle(increment * i); 
}
