#pragma once 

#include <cmath>

struct vec2
{
	float x;
	float y;

	void Add(const vec2& v);
	void Sub(const vec2& v);
	void Mul(const float factor);
	void Div(const float factor);
	void Normalize();
	void Lerp(const vec2& b, const float& t);  
	vec2 Normalized() const;
	float Mag() const;
	float Heading() const; 
	float Dist(const vec2& v) const; 

	vec2 operator+(const vec2& v) const;
	void operator+=(const vec2& v);
	vec2 operator-(const vec2& v) const;
	void operator-=(const vec2& v);
	vec2 operator*(const float factor) const;
	void operator*=(const float factor);
	vec2 operator/(const float factor) const;
	void operator/=(const float factor);

	static vec2 New(const float x, const float y);
	static vec2 Add(const vec2& a, const vec2& b);
	static vec2 Sub(const vec2& a, const vec2& b);
	static vec2 Mul(const vec2& v, const float factor);
	static vec2 Div(const vec2& v, const float factor);
	static float Dot(const vec2& a, const vec2& b);
	static float Cross(const vec2& a, const vec2& b);
	static vec2 FromAngle(float degrees);
	static vec2 Lerp(const vec2& a, const vec2& b, const float& t); 
	static vec2 DeltaLerp(const vec2& a, const vec2& b, const float& t); 
};

