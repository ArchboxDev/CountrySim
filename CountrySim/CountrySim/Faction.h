#include <vector>
#include <string>
#include "Country.h"
#pragma once
class Faction
{
public:
	Faction(Country creator, Country cocreator);
	void OnJoin(Country member);
	std::vector<Country> members;
	Country fcreator;
	std::string name;
	std::string suffix;
	~Faction();
};

