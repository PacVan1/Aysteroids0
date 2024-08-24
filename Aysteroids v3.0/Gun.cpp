#include "Gun.h"

#include "Environment.h"
#include "HomingMissile.h"
#include "Debug.h" 

Gun::Gun()
{
}

void Gun::Update(const float& dt)
{ 
	firePoint = transform.position; 
	Reload(dt); 

	Attachment::Update(dt);  
}

void Gun::Reload(const float& dt)
{
	if (!loaded)
		currentTime += dt;

	if (currentTime > fireRate)
	{
		currentTime -= fireRate; 
		loaded = true; 
	}
}

void Gun::Equip()
{
	// nothing happens yet
}

void Gun::Unequip()
{
	// nothing happens yet
}

void Gun::Knockback(const vec2& velocity)
{
	owner->rigidbody.Accelarate(velocity * -0.5f);   
}

void Gun::Use()
{
	if (!loaded)
		return; 
	
	HomingMissile* projectile = new HomingMissile(ProjectileProps({ 0.5f, 2.0f }), firePoint, owner->transform.GetRotation() * firePower, shape.getOutlineColor());
	Environment::s_projectiles.push_back(projectile);  
	Knockback(owner->transform.GetRotation() * firePower); 

	loaded = false; 
}
