#include "Country.h"
#include <Windows.h>
#include <time.h>

int main() {
	Country a; //Define countries, you can add more if you want.
	Sleep(777);
	Country b;
	while (true) {
		b.RerollSuffix();
		Sleep(777);
		if (b.prefix != a.prefix) {
			break;
		}
	}
	Country c;
	while (true) {
		c.RerollSuffix();
		Sleep(777);
		if (c.prefix != a.prefix && c.prefix != a.prefix) {
			break;
		}
	}
	Country d;
	while (true) {
		d.RerollSuffix();
		Sleep(777);
		if (d.prefix != a.prefix && d.prefix != a.prefix && d.prefix != c.prefix) {
			break;
		}
	}
	int year = 0;
	while (true) {
		int staba = a.GetStats(1); //Setup all countries to retrieve stats like first 4 example ones
		int stabb = b.GetStats(1);
		int stabc = c.GetStats(1);
		int stabd = d.GetStats(1);
		if (staba < 50) {
			a.Revolution();
			Sleep(777);
		}
		if (stabb < 50) {
			b.Revolution();
			Sleep(777);
		}
		if (stabc < 50) {
			c.Revolution();
			Sleep(777);
		}
		if (stabd < 50) {
			d.Revolution();
			Sleep(777);
		}
		if (year % 4 == 0) {
			a.Election();
			Sleep(777);
			b.Election();
			Sleep(777);
			c.Election();
			Sleep(777);
			d.Election();
			Sleep(777);
		}
		/*int edictpasser = rand() % 4;
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
		}*/
		year = year++;
		std::cout << "END OF YEAR!" << std::endl;
		std::cin.get();
	}

	return 0;
};
