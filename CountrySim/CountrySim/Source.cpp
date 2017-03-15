#include "Country.h"
#include "War.h"
#include <Windows.h>
#include <time.h>
#include <algorithm>

//Variables you can change
int sleepl = 777; //Change this to change the sleep length
int everXYearsElection = 4; //Change this to define every which year elections fire
int stabilityThreshold = 50; //Change this to define the stability threshold until revolution
int amountc;
bool result;
int main() {
	std::cout << "How many countries do you want to make?(Do not set it more than 18 or else it will loop) " << std::endl;
	std::cin >> amountc;
	std::vector<Country> countries(amountc);
	std::vector<War> currentwars;
	for (int i = 0; i < countries.size(); i++) {
			for (int x = 0; x < countries.size(); x++) {
				if (countries[i].name == countries[x].name) {
					countries[i].RerollPrefix();
				}
			}
		countries[i].InitOpnion(countries);
		Sleep(sleepl);
	}
	int year = 0;
	while (true) {
		/*for (int i = 0; i < countries.size(); i++) {
			int stabc = countries[i].GetStats(0);
				if (stabc < 50 && 25 >= rand() % 100 ) {
					countries[i].Revolution();
					for (int x = 0; x < countries.size(); x++) {
						countries[x].ResetThoughts(i, countries);
					}
					Sleep(sleepl);
				}
		}*/
		if (year % everXYearsElection == 0) {
			for (int i = 0; i < countries.size(); i++) {
				if (countries[i].elections = true) {
					countries[i].Election();
					Sleep(sleepl);
				}
			}
		}
		int edictpasser = rand() % countries.size();
		int pass = rand() % 2;
		if (countries[edictpasser].edicts.size() > 1) {
			if (countries[edictpasser].passededicts.size() > 1) {
				if (pass == 1) {
					countries[edictpasser].PassEdict();
				}
				else {
					countries[edictpasser].CancelEdict();
				}
			}
			else {
				countries[edictpasser].PassEdict();
			}
		}
		else {
			countries[edictpasser].CancelEdict();
		}
		for (int i = 0; i < countries.size(); i++) {
			for (int x = 0; x < countries.size(); x++) {
				if (countries[i].ideology == countries[x].ideology) {
					countries[i].ImproveThoughts(x, 5);
				}
				else {
					countries[i].ImproveThoughts(x, -5);
				}
				if (countries[i].ideology == "Democratic" && countries[x].GetConscriptionLaw() != countries[i].GetConscriptionLaw()) {
					countries[i].ImproveThoughts(x, -5);
				}
				if (countries[x].militarymight > countries[i].militarymight && countries[x].thoughtsof[i] < 0) {
					countries[i].ImproveThoughts(x, -20);
				}
			}
		}
		for (int i = 0; i < countries.size(); i++) {
			for (int x = 0; x < countries.size(); x++) {
				if (countries[i].thoughtsof[x] < -50) {
					for (int v = 0; v < currentwars.size(); v++) {
						if ( (std::find(currentwars[v].Agressors.begin(), currentwars[v].Agressors.end(), countries[i]) != currentwars[v].Agressors.end() || std::find(currentwars[v].Defenders.begin(), currentwars[v].Defenders.end(), countries[i]) != currentwars[v].Defenders.end()) && (std::find(currentwars[v].Agressors.begin(), currentwars[v].Agressors.end(), countries[x]) != currentwars[v].Agressors.end() || std::find(currentwars[v].Defenders.begin(), currentwars[v].Defenders.end(), countries[x]) != currentwars[v].Defenders.end()) ) {
							result = true;
						}
						else {
							result = false;
						}
					}
					if (!result) {
						War war(countries[i], countries[x]);
						currentwars.push_back(war);
					}
				}
			}
		}
		for (int v = 0; v < currentwars.size(); v++) {
			currentwars[v].UpdateWarStats();
		}
		year = year++;
		for (int i = 0; i < countries.size(); i++) {
			std::cout << countries[i].name << " is currently lead by " << countries[i].GetLeader() << " with the stability of " << countries[i].GetStats(0) << "! \nSize: " << countries[i].GetStats(1) << ". Current population: " << countries[i].GetStats(2) << std::endl << std::endl;
		}
		std::cout << "END OF YEAR!" << std::endl;
		std::cin.get();
	}

	return 0;
};
