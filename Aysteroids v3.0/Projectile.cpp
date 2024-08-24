#include "Projectile.h"

Projectile::Projectile(const ProjectileProps& projectileProps, const vec2 position, const vec2 velocity, const sf::Color& color) : 
	ISpaceObject(projectileProps.mass, projectileProps.radius, false)   
{
	IDrawable::s_ApplyStyle(shape);
	shape.setRadius(projectileProps.radius); 
	shape.setOrigin({ projectileProps.radius, projectileProps.radius }); 
	shape.setOutlineColor(color);  

	transform.position = position;
	rigidbody.velocity = velocity; 
}

void Projectile::Draw(sf::RenderWindow& window)
{
	shape.setPosition(transform.position.x, transform.position.y);  
	window.draw(shape); 

	ISpaceObject::Draw(window);
}
