#pragma once

class Random
{
public: 
	static void s_SetSeed();
	static int s_Int(int min = 0, int max = 100);  
	static int s_Float(float min = 0.0f, float max = 1.0f); 
};

