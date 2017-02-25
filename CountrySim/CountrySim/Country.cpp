#include "Country.h"
#include <stdlib.h>
#include <time.h>






Country::Country()
{	
	srand( time(NULL) );
	stability = 100;
	std::string edicts[14] = { "Save Nature", "Industrialization", "Curfews", "Country-wide firewall", "Invasion of Privacy act", "Equal wages", "Support of local buisnesses", "Probation for every crime", "Allow death sentences", "Independence of foreign politics act", "Schools teach all subjects", "Travel ban", "Obligatory military service", "Religious oath of devotion" };
	std::string passededicts[1] = { "Emergency services" };
	int RandIndex = rand() % 10;
	int RandIndex2 = rand() % 10;
	std::string names[18] = { "Bill", "Bob", "Adolf", "Joseph", "Andrej", "Ivan", "Hans", "Nicolas", "Jacques", "David", "Barry", "Boris", "Julius", "Augustus", "Basil", "Stephen", "Huis", "Hugues" };
	std::string snames[15] = { "Dickson", "Treehanger", "Hitler", "Stalin", "Sokolov", "Ivanovich", "Heinemann", "Bernard", "Thomas", "Cameron", "Calvin", "Capet", "Hugo", "Farel", "Lefevre" };
	leader = names[RandIndex] + " " + snames[RandIndex2];
	std::string  namespre[17] = { "Russian", "German", "French", "Polish", "British", "Latvian", "Lithuanian", "Spanish", "Chinese", "Swedish", "Ukrainian", "Nigerian", "Soviet", "Rebel", "Nazi", "American", "Canadian" };
	RandIndex = rand() % 11;
	prefix = namespre[RandIndex];
	teritory = rand() % 1000000000;
	std::string ideologyc[4] = { "Communist", "Democratic", "Monarchic", "Facist" };
	RandIndex = rand() % 4;
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
	name = prefix + suffix;
	std::cout << "A new country with the name " << name << " has been created under the \nleadership of " << leader << "'s " << ideology << " regime!" << std::endl;
}

int Country::GetStats(int x)
{
	int stats[3] = { stability, teritory, population };
	return stats[x];
}

void Country::Revolution()
{
	stability = 100;
	std::string temp = leader;
	srand( time(NULL) );
	int RandIndex = rand() % 10;
	int RandIndex2 = rand() % 10;
	std::string names[10] = { "Bill", "Bob", "Adolf", "Joseph", "Andrej", "Ivan", "Hans", "Nicolas", "Jacques", "David" };
	std::string snames[10] = { "Dickson", "Treehanger", "Hitler", "Stalin", "Sokolov", "Ivanovich", "Heinemann", "Bernard", "Thomas", "Cameron" };
	leader = names[RandIndex] + " " + snames[RandIndex2];
	RerollIdeology();
	std::cout << "A revolution has happened! Leader " << temp << " is replaced by \n" << leader << "'s " << ideology << " regime!!" << std::endl;
}

void Country::RerollIdeology()
{
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
	std::cout << ideology << std::endl;
	name = prefix + suffix;
}

void Country::RerollSuffix()
{
	srand(time(NULL));
	std::string  namespre[11] = { "Russian", "German", "French", "Polish", "British", "Latvian", "Soviet", "Rebel", "Nazi", "American", "Canadian" };
	int RandIndex = rand() % 11;
	prefix = namespre[RandIndex];
	name = prefix + suffix;
	std::cout << "Changed " << name << "'s name to prevent duplicates." << std::endl;
}


void Country::Election()
{
	srand(time(NULL));
	stability = stability-rand() % 100;
	std::string temp = leader;
	srand( time(NULL) );
	int RandIndex = rand() % 10;
	int RandIndex2 = rand() % 10;
	std::string names[10] = { "Bill", "Bob", "Adolf", "Joseph", "Andrej", "Ivan", "Hans", "Nicolas", "Jacques", "David" };
	std::string snames[10] = { "Dickson", "Treehanger", "Hitler", "Stalin", "Sokolov", "Ivanovich", "Heinemann", "Bernard", "Thomas", "Cameron" };
	leader = names[RandIndex] + " " + snames[RandIndex2];
	std::cout << "An election has happened! Leader " << temp << " is replaced by \n"<< leader << "!" << std::endl;
}

void Country::PassEdict()
{
	/*srand(time(NULL));
	int stabilityaffected = rand() % 2;
	switch (stabilityaffected) {
	case 1:
		stability = stability - rand() % 10;
		break;
	case 2:
		stability = stability + rand() % 10;
		break;
	}
	int edict = rand() % sizeof(edicts);
	std::string tmp = edicts[edict];
	edicts[edict] = "";
	for (int i = edict; i < sizeof(edicts); i++) {
		edicts[edict] = edicts[edict + 1];
		edicts[i - 1] = "";
	}
	passededicts[sizeof(passededicts)-1] = tmp;
	std::cout << name << " has passed edict: " << tmp << std::endl;
	 WARNING: This part is broken and will throw an exception!*/
}



Country::~Country()
{
	std::cout << name << " has fallen!" << std::endl;
}
