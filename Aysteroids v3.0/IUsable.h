#pragma once

#include "IItem.h"

class IUsable : public IItem
{
public: 
	void Use() override = 0; 

protected: 
	IUsable(const ItemProps& itemProps, const SpaceObjectProps& spaceObjectProps); 
};

