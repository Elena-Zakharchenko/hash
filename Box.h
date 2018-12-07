#pragma once
#include<string>
#include"hash.h"

struct Box
{
	int hash = 0;
	std::string nameofbook;
	Box(std::string name)
	{
		this->nameofbook = name;
		this->hash = generetichash(nameofbook);
	}
};
