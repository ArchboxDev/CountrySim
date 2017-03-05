#include "Country.h"
#include <Windows.h>
#include <time.h>

//Variables you can change
int sleepl = 777; //Change this to change the sleep length
int everXYearsElection = 4; //Change this to define every which year elections fire
int stabilityThreshold = 50; //Change this to define the stability threshold until revolution
int amountc;
int main() {
	std::cout << "How many countries do you want to make?(Do not set it more than 18 or else it will loop) " << std::endl;
	std::cin >> amountc;
	std::vector<Country> countries(amountc);
	for (int i = 0; i < countries.size(); i++) {
			for (int x = 0; x < countries.size(); x++) {
				if (countries[i].name == countries[x].name) {
					countries[i].RerollPrefix();
				}
			}
		Sleep(sleepl);
	}
	int year = 0;
	while (true) {
		for (int i = 0; i < countries.size(); i++) {
			int stabc = countries[i].GetStats(0);
				if (stabc < 50) {
					countries[i].Revolution();
					Sleep(sleepl);
				}
		}
		if (year % everXYearsElection == 0) {
			for (int i = 0; i < countries.size(); i++) {
				if (countries[i].elections = true) {
					countries[i].Election();
				}
			}
		}
		//DO NOT UNCOMMENT THIS IF YOU CANT FIX THIS! IT WILL JUST CAUSE AN EXCEPTION!
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
		year = year++;
		for (int i = 0; i < countries.size(); i++) {
			std::cout << countries[i].name << " is currently lead by " << countries[i].GetLeader() << " with the stability of " << countries[i].GetStats(0) << "! \nSize: " << countries[i].GetStats(1) << ". Current population: " << countries[i].GetStats(2) << std::endl << std::endl;
		}
		std::cout << "END OF YEAR!" << std::endl;
		std::cin.get();
	}

	return 0;
};
