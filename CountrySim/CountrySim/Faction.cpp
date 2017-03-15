#include "Faction.h"
#include "Country.h"


Faction::Faction(Country creator, Country cocreator)
{
	fcreator = creator;
	suffix = "Aliance";
	if (creator.ideology == "Communist") {
		suffix = " international pact of defense against common enemies";
	}
	else if (creator.ideology == "Democratic") {
		suffix = " treaty of defense";
	}
	else if (creator.ideology == "Monarchic") {
		suffix = " the royal signatory of country friendship";
	}
	else if (creator.ideology == "Facist") {
		suffix = " Axis";
	}
	name = creator.name + " and " + cocreator.name + " " + suffix;
	members.push_back(creator);
	members.push_back(cocreator);
	std::cout << name << " has been created! Does this faction mean the preparation of war?";
}

void Faction::OnJoin(Country member)
{
	if (member.ideology == fcreator.ideology) {
		members.push_back(member);
	}
}


Faction::~Faction()
{
}
