#include "Country.h"
#include <Windows.h>
#include <time.h>

//Variables you can change
int sleepl = 777; //Change this to change the sleep length
int everXYearsElection = 4; //Change this to define every which year elections fire
int stabilityThreshold = 50; //Change this to define the stability threshold until revolution


int main() {
	Country a; //Define countries, you can add more if you want.
	Sleep(sleepl);
	Country b;
	while (true) {
		b.RerollPrefix();
		Sleep(sleepl);
		if (b.prefix != a.prefix) {
			break;
		}
	}
	Country c;
	while (true) {
		c.RerollPrefix();
		Sleep(sleepl);
		if (c.prefix != a.prefix && c.prefix != a.prefix) {
			break;
		}
	}
	Country d;
	while (true) {
		d.RerollPrefix();
		Sleep(sleepl);
		if (d.prefix != a.prefix && d.prefix != a.prefix && d.prefix != c.prefix) {
			break;
		}
	}
	int year = 0;
	while (true) {
		int staba = a.GetStats(0); //Setup all countries to retrieve stats like first 4 example ones
		int stabb = b.GetStats(0);
		int stabc = c.GetStats(0);
		int stabd = d.GetStats(0);
		if (staba < 50) {
			a.Revolution();
			Sleep(sleepl);
		}
		if (stabb < 50) {
			b.Revolution();
			Sleep(sleepl);
		}
		if (stabc < 50) {
			c.Revolution();
			Sleep(sleepl);
		}
		if (stabd < 50) {
			d.Revolution();
			Sleep(sleepl);
		}
		if (year % everXYearsElection == 0) {
			a.Election();
			Sleep(sleepl);
			b.Election();
			Sleep(sleepl);
			c.Election();
			Sleep(sleepl);
			d.Election();
			Sleep(sleepl);
		}
		//DO NOT UNCOMMENT THIS IF YOU CANT FIX THIS! IT WILL JUST CAUSE AN EXCEPTION!
		int edictpasser = rand() % 4;
		int passorcancel = rand() % 2;
		switch (edictpasser) {
		case 1:
			a.PassEdict();
			break;
		case 2:
			b.PassEdict();
			break;
		case 3:
			c.PassEdict();
			break;
		case 4:
			d.PassEdict();
			break;
		}
		year = year++;
		std::cout << a.name << " is currently lead by " << a.GetLeader() << " with the stability of " << staba << "! \nSize: " << a.GetStats(1) << ". Current population: " << a.GetStats(2) << std::endl << std::endl;
		std::cout << b.name << " is currently lead by " << b.GetLeader() << " with the stability of " << stabb << "! \nSize: " << b.GetStats(1) << ". Current population: " << b.GetStats(2) << std::endl << std::endl;
		std::cout << c.name << " is currently lead by " << c.GetLeader() << " with the stability of " << stabc << "! \nSize: " << c.GetStats(1) << ". Current population: " << c.GetStats(2) << std::endl << std::endl;
		std::cout << d.name << " is currently lead by " << d.GetLeader() << " with the stability of " << stabd << "! \nSize: " << d.GetStats(1) << ". Current population: " << d.GetStats(2) << std::endl << std::endl;
		std::cout << "END OF YEAR!" << std::endl;
		std::cin.get();
	}

	return 0;
};
