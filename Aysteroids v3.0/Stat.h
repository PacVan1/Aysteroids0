#pragma once

class Stat
{
public:
	float current;
	float max;

public:
	Stat(const float max);

	void Increase(const float increment);
	virtual void Decrease(const float decrement);
};