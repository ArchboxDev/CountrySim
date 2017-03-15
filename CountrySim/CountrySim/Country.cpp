#include "Country.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
std::string claws[5] = { "None", "Volunteer only", "Limited Conscription", "Full Conscription", "Every adult serves" };
std::string arraye[15] = { "Save Nature","Industrialization","Curfews","Country-wide firewall","Invasion of Privacy act","Equal wages","Support of local buisnesses","Probation for every crime","Allow death sentences","Independence of foreign politics act","Schools teach all subjects","Travel ban","Religious oath of devotion" };

Country::Country()
{	
	// The Country Constructor. Defines everything thats needed
	srand( time(NULL) ); //Sets the Random seed to current time(in seconds from Jan 1, 1970
	int RandIndex = rand() % 2;
	switch (RandIndex) {
	case 1:
		elections = true;
		break;
	case 2:
		elections = false;
		break;
	}
	//Above defines if nation has elections or no
	conscriptionlaws.insert (conscriptionlaws.end(), claws, claws+5); //avaivable conscription laws
	RandIndex = rand() % size(conscriptionlaws);
	conscriptionlaw = conscriptionlaws[RandIndex]; //Chooses conscription law
	population = rand() % 1000000000 + 1000; //Sets population between 1 Billion and 1 Thousand
	stability = 100; //Sets the stability
	edicts.insert (edicts.end(), arraye, arraye+15 );
	//These 2 string vectors (edicts and edictspassed) define the edicts system which currently doesn't work
	passededicts.push_back ( "Emergency services" );
	 RandIndex = rand() % 18; //Gets a random number
	int RandIndex2 = rand() % 15; //Gets a random number
	std::string names[18] = { "Bill", "Bob", "Adolf", "Joseph", "Andrej", "Ivan", "Hans", "Nicolas", "Jacques", "David", "Barry", "Boris", "Julius", "Augustus", "Basil", "Stephen", "Huis", "Hugues" };
	//These 2 arrays (names and snames) define the avaivable leader name and surename combinations. Change the RandIndex and RandIndex2 above them if you add or remove items
	std::string snames[15] = { "Dickson", "Treehanger", "Hitler", "Stalin", "Sokolov", "Ivanovich", "Heinemann", "Bernard", "Thomas", "Cameron", "Calvin", "Capet", "Hugo", "Farel", "Lefevre" };
	leader = names[RandIndex] + " " + snames[RandIndex2]; //Defines the leader name
	//namespre defines the avaivable country prefixes (i.e. French Republic where French is the prefix)
	std::string  namespre[18] = { "Russian", "German", "French", "Polish", "British", "Latvian", "Lithuanian", "Spanish", "Chinese", "Swedish", "Ukrainian", "Nigerian", "Soviet", "Cuban", "Somalian", "American", "Canadian", "Estonian" };
	RandIndex = rand() % 18; //Gets a random number
	prefix = namespre[RandIndex]; //Defines a random prefix
	teritory = rand() % 1000000000 + population/10; //Generates the teritory of the country between 1 billion and the population amount(10 km^2 on 1 citizen)
	std::string ideologyc[4] = { "Communist", "Democratic", "Monarchic", "Facist" }; //Avaivable ideologies, you can add more just remember to change RandIndex below
	RandIndex = rand() % 4; //Gets a random number
	ideology = ideologyc[RandIndex]; //Gets the ideology chosen
	if (ideology == "Communist") { //If ideology is communist then set suffix to Union
		suffix = " Union";
	}
	else if (ideology == "Democratic" && teritory > 500000) { //If ideology is Democratic AND teritory 500 thousand then set suffix to Federation
		suffix = " Federation";
	}
	else if (ideology == "Facist") { //If ideology is Facist then set suffix to Country
		suffix = " Country";
	}
	else if (ideology == "Monarchic") { //If ideology is Monarchic then set suffix to Empire
		suffix = " Empire";
	}
	else if (ideology == "Democratic") { //If ideology is Democratic and it didn't fit the Federation criteria then set suffix to Republic
		suffix = " Republic";
	}
	name = prefix + suffix; //Create the name
	SetMilitaryStats();
	std::cout << "A new country with the name " << name << " has been created under the \nleadership of " << leader << "'s " << ideology << " regime!" << "\nHas elections: " << elections << std::endl << std::endl; //Message
	Sleep(666);
}

void Country::InitOpnion(std::vector<Country> list)
{
	float opinion = 0;
	for (int p = 0; p < list.size(); p++) {
		if (ideology == list[p].ideology) {
			opinion = 10;
		}
		else {
			opinion = -10;
		}
		thoughtsof.push_back(opinion);
	}
}

int Country::GetStats(int x)
{
	//Get stats
	//If input is 0 then gets stability
	//If input is 1 then gets teritory
	//If input is 2 then gets population
	int stats[3] = { stability, teritory, population };
	return stats[x];
}

std::string Country::GetLeader()
{
	//Gets the leader
	return leader;
}

void Country::UpdatePop()
{
	//Updates the population
	srand(time(NULL));
	int populationgrowth = rand() % 2; // 1 = population shrinks, 2 = population grows
	switch (populationgrowth) {
	case 1:
		stability = population - rand() % 10000 + 100;
		break;
	case 2:
		stability = stability + rand() % 10000 + 100;
		break;
	}
	SetMilitaryStats();
}

void Country::Revolution(std::vector<Country> countrylist)
{
	//Revolution event. Fired when stability is less than 50 (Check source.cpp to change the threshold)
	//Most of this is code equal to the contructor
	//THIS IS NOW POINTLESS AS IT IS ABOUT TO BE REVAMPED!
	//In an another update
	//CivilWarCountry rebel1;
	//CivilWarCountry rebel2;
	//CivilWar CivilWar(rebel1, rebel2);
	//std::cout << "A revolution has happened! Leader " << temp << " is replaced by \n" << leader << "'s " << ideology << " regime!!" << " Has elections: " << elections << std::endl << std::endl;
}

void Country::RerollIdeology()
{
	//Reroll ideology. Changes the ideology when called
	int RandIndex = rand() % 4;
	ideology = ideologyc[RandIndex];
	if (ideology == "Communist") {
		suffix = " Union";
	}
	else if (ideology == "Democratic" && teritory > 500000) {
		suffix = " Federation";
	}
	else if (ideology == "Facist") {
		suffix = " Country";
	}
	else if (ideology == "Monarchic") {
		suffix = " Empire";
	}
	else if (ideology == "Democratic") {
		suffix = " Republic";
	}
	std::cout << ideology << std::endl << std::endl;
	name = prefix + suffix;
}

void Country::RerollPrefix()
{
	//Changes the prefix to prevent duplicates. Called in Source.cpp
	srand(time(NULL));
	std::string tmp = name;
	std::string  namespre[11] = { "Russian", "German", "French", "Polish", "British", "Latvian", "Soviet", "Rebel", "Nazi", "American", "Canadian" };
	int RandIndex = rand() % 11;
	prefix = namespre[RandIndex];
	name = prefix + suffix;
	std::cout << "Changed " << tmp << "'s name to " << name << " to prevent duplicates." << std::endl << std::endl;
}


void Country::Election()
{
	if (elections == true) {
		//Election event. It's like the revolution one but doesn't change ideology
		srand(time(NULL));
		stability = stability - rand() % 100;
		std::string temp = leader;
		srand(time(NULL));
		int RandIndex = rand() % 10;
		int RandIndex2 = rand() % 10;
		std::string names[10] = { "Bill", "Bob", "Adolf", "Joseph", "Andrej", "Ivan", "Hans", "Nicolas", "Jacques", "David" };
		std::string snames[10] = { "Dickson", "Treehanger", "Hitler", "Stalin", "Sokolov", "Ivanovich", "Heinemann", "Bernard", "Thomas", "Cameron" };
		leader = names[RandIndex] + " " + snames[RandIndex2];
		std::cout << "An election has happened! Leader " << temp << " is replaced by \n" << leader << "!" << std::endl << std::endl;
	}
	else {
		stability = stability - 1;
	}
}

void Country::PassEdict()
{
	//Pass edict. Will pass edict on call
			srand(time(NULL));
			int stabilityaffected = rand() % 2;
			switch (stabilityaffected) {
			case 1:
				stability = stability - rand() % 10;
				break;
			case 2:
				stability = stability + rand() % 10;
				break;
			}
			int edict = rand() % (edicts.size()-1);
			std::string tmp = edicts[edict];
			edicts.erase (edicts.begin() + edict);
			passededicts.push_back(tmp);
			std::cout << name << " has passed edict: " << tmp << std::endl << std::endl;
}

void Country::CancelEdict()
{
	//Cancels an edict
	srand(time(NULL));
	int stabilityaffected = rand() % 2;
	switch (stabilityaffected) {
	case 1:
		stability = stability - rand() % 10;
		break;
	case 2:
		stability = stability + rand() % 10;
		break;
	}
	int edict = rand() % (passededicts.size()-1);
	std::string tmp = passededicts[edict];
	passededicts.erase(passededicts.begin() + edict);
	edicts.push_back(tmp);
	std::cout << name << " has canceled edict: " << tmp << std::endl << std::endl;
}

void Country::ImproveThoughts(int index, float amount)
{
	thoughtsof[index] = thoughtsof[index] + amount;
}

void Country::SetThoughts(int index, float amount)
{
	thoughtsof[index] = amount;
}

void Country::ResetThoughts(int index, std::vector<Country> list) {
	float opinion = 0;
	if (ideology == list[index].ideology) {
		opinion = 10;
	}
	else {
		opinion = -10;
	}
	thoughtsof[index] = opinion;
}

void Country::SetMilitaryStats()
{
	if (conscriptionlaw == "None") {
		manpower = population / 100 * 1;
	}
	else if (conscriptionlaw == "Volunteer only") {
		manpower = population / 100 * 2;
	}
	else if (conscriptionlaw == "Limited Conscription") {
		manpower = population / 100 * 5;
	}
	else if (conscriptionlaw == "Full Conscription") {
		manpower = population / 100 * 10;
	}
	else if (conscriptionlaw == "Every adult serves") {
		manpower = population / 100 * 50;
	}
	workers = population - manpower;
	MakeEquip();

}

void Country::SetMightness()
{
	infantry = manpower / 3;
	pilots = manpower / 3;
	sailors = manpower / 3;
	if (infantry > infantryequip + (4 * tanks)) {
		armysize = armysize + infantryequip + tanks;
		infantry = infantry - (infantryequip + (4 * tanks));
		infantryequip = infantryequip - infantryequip;
		tanks = tanks - tanks;
	}
	else {
		armysize = armysize + infantry;
		infantryequip = infantryequip - infantry;
		tanks = tanks - infantry;
		infantry = infantry - infantry;
	}
	if (pilots > planes) {
		airmight = airmight + planes;
		pilots = pilots - planes;
		planes = planes - planes;
	}
	else {
		airmight = airmight + pilots;
		planes = planes - pilots;
		pilots = pilots - pilots;
	}
	if (sailors > ships) {
		seamight = seamight + ships;
		sailors = sailors - ships;
		ships = 0;
	}
	else {
		seamight = seamight + sailors;
		ships = ships - sailors;
		sailors = 0;
	}
}

void Country::MakeEquip()
{
	infantryequip = infantryequip + (1000000000000 / population * workers);
	tanks = tanks + (1000000000000 / population * workers);
	planes = planes + (1000000000000 / population * workers);
	ships = ships + (1000000000000 / population * workers);
	SetMightness();
}

void Country::ChangeConscriptionLaw(bool losing)
{
	std::vector<std::string>::iterator currentlaw = std::find(conscriptionlaws.begin(), conscriptionlaws.end(), conscriptionlaw);
	if (losing == true) {
		conscriptionlaw = *(currentlaw + 1);
	}
	else {
		conscriptionlaw = *(currentlaw - 1);
	}
	SetMilitaryStats();
}

std::string Country::GetConscriptionLaw()
{
	return conscriptionlaw;
}

bool operator== (const Country &c1, const Country &c2) {
	return c1.prefix == c2.prefix && c1.suffix == c2.suffix;
}

Country::~Country()
{
	//Country destructor
	//tbh this really is pointless
}
