#include "Country.h"
#include "Faction.h"
#include <vector>
#include <string>
#pragma once

class War
{
public:
	War(Country aggresor, Country defender);
	void UpdateWarStats();
	void CallToArms(Faction called, bool deforatk);
	void CallToArms(Country called, bool deforatk);
	std::vector<Country> Agressors;
	std::vector<Country> Defenders;
	void AdvanceWar();
	bool warend;
	~War();
private:
	float totalmight;
	float AggressorMilitaryMight;
	float ANavyMight;
	float AAMight;
	float AAirMight;
	float DefenderMilitaryMight;
	float DNavyMight;
	float DAMight;
	float DAirMight;
	int DVic;
	int AVic;
	std::vector<Country> Capitulated;
	std::vector<float> warscoreA;
	std::vector<float> warscoreD;
	std::string wargoal;
};

