#include "Vector2.h"

vec2 vec2::New(const float x, const float y)
{
	return { x, y };
}

vec2 vec2::Add(const vec2& a, const vec2& b)
{
	return {
		a.x + b.x,
		a.y + b.y
	};
}

vec2 vec2::Sub(const vec2& a, const vec2& b)
{
	return {
		a.x - b.x,
		a.y - b.y
	};
}

vec2 vec2::Mul(const vec2& v, const float factor)
{
	return {
		v.x * factor,
		v.y * factor
	};
}

vec2 vec2::Div(const vec2& v, const float factor)
{
	return {
		v.x / factor,
		v.y / factor
	};
}

float vec2::Dot(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

float vec2::Cross(const vec2& a, const vec2& b)
{
	return a.x * b.y - a.y * b.x;
}

vec2 vec2::FromAngle(float degrees)
{
	degrees /= 180.0f / 3.141592f;
	return { cos(degrees), sin(degrees) };
}

vec2 vec2::Lerp(const vec2& a, const vec2& b, const float& t)
{
	return a + (b - a) * t; 
}

vec2 vec2::DeltaLerp(const vec2& a, const vec2& b, const float& t)
{
	return (b - a) * t; 
}

void vec2::Add(const vec2& v)
{
	x += v.x;
	y += v.y;
}

void vec2::Sub(const vec2& v)
{
	x -= v.x;
	y -= v.y;
}

void vec2::Mul(const float factor)
{
	x *= factor;
	y *= factor;
}

void vec2::Div(const float factor)
{
	x /= factor;
	y /= factor;
}

void vec2::Normalize()
{
	float mag = Mag();
	this->Div(mag);
}

void vec2::Lerp(const vec2& b, const float& t)
{
	*this = Lerp(*this, b, t); 
}

vec2 vec2::Normalized() const
{
	return Div(*this, this->Mag());
}

float vec2::Mag() const
{
	return sqrt((x * x) + (y * y));
}

float vec2::Heading() const
{
	return atan2(y, x) * 180.0f / 3.141592f;
}

float vec2::Dist(const vec2& v) const 
{
	return Sub(*this, v).Mag();     
}

vec2 vec2::operator+(const vec2& v) const
{
	return Add(*this, v);
}

void vec2::operator+=(const vec2& v)
{
	this->Add(v);
}

vec2 vec2::operator-(const vec2& v) const
{
	return Sub(*this, v);
}

void vec2::operator-=(const vec2& v)
{
	this->Sub(v);
}

vec2 vec2::operator*(const float factor) const
{
	return Mul(*this, factor);
}

void vec2::operator*=(const float factor)
{
	this->Mul(factor);
}

vec2 vec2::operator/(const float factor) const
{
	return Div(*this, factor);
}

void vec2::operator/=(const float factor)
{
	this->Div(factor);
}

