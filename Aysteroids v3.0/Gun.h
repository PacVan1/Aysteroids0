#pragma once

#include "Attachment.h" 

class Gun : public Attachment
{
public: 
	vec2 firePoint = {};
	float firePower = 350.0f;  
	float fireRate = 0.5f; 

private: 
	float currentTime = 0.0f;
	bool loaded = true; 

public: 
	Gun(); 

	void Update(const float& dt) override; 
	void Reload(const float& dt); 
	void Equip() override; 
	void Unequip() override; 
	void Knockback(const vec2& velocity);  
	void Use() override; 
};

