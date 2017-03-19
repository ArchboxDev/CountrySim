#include "War.h"
#include "Country.h"



War::War(Country aggresor, Country defender)
{
	std::string arrayw[2] = { "Teritory", "None" };

	Agressors.push_back(aggresor);
	Defenders.push_back(defender);

	if (Agressors[0].GetStats(1) < Defenders[0].GetStats(1)) {
		wargoal = arrayw[1];
	}
	else {
		wargoal = arrayw[0];
	}
	std::cout << "War has been declared! " << aggresor.name << " and " << defender.name << std::endl;
}


void War::UpdateWarStats()
{
	AggressorMilitaryMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		AggressorMilitaryMight = AggressorMilitaryMight + Agressors[i].militarymight;
	}
	AAirMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		AAirMight = AAirMight + Agressors[i].airmight;
	}
	ANavyMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		ANavyMight = ANavyMight + Agressors[i].airmight;
	}
	AAMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		AAMight = AAMight + Agressors[i].airmight;
	}
	DefenderMilitaryMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		DefenderMilitaryMight = DefenderMilitaryMight + Agressors[i].militarymight;
	}
	DAirMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		DAirMight = DAirMight + Agressors[i].airmight;
	}
	DNavyMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		DNavyMight = DNavyMight + Agressors[i].airmight;
	}
	DAMight = 0;
	for (int i = 0; i < Agressors.size(); i++) {
		DAMight = DAMight + Agressors[i].airmight;
	}
	AdvanceWar();
}


void War::CallToArms(Faction called, bool deforatk)
{
	if (deforatk = true) {
		for (int i = 0; i < called.members.size(); i++) {
			Agressors.push_back(called.members[i]);
		}
	}
	else {
		for (int i = 0; i < called.members.size(); i++) {
			Defenders.push_back(called.members[i]);
		}
	}
}

void War::CallToArms(Country called, bool deforatk)
{
	if (deforatk = true) {
		Agressors.push_back(called);
	}
	else {
		Defenders.push_back(called);
	}
}

void War::AdvanceWar()
{
	if (!(DVic > 10 || AVic > 10)) {
		int totalmight = AggressorMilitaryMight + DefenderMilitaryMight;
		float AChance = AggressorMilitaryMight / totalmight;
		float DChance = DefenderMilitaryMight / totalmight;
		float randindex = rand() % totalmight;
		if (randindex > AChance && AChance < DChance) {
			DVic = DVic + 1;
			return;
		}
		else {
			AVic = AVic + 1;
			return;
		}
		if (randindex > DChance && DChance < AChance) {
			AVic = AVic + 1;
			return;
		}
		else {
			DVic = DVic + 1;
			return;
		}
	}
	else {
		warend = true;
		return;
	}
}


War::~War()
{
	if (DVic > AVic) {
		int pceffects = DVic - AVic;
		for (int i = 0; i < Agressors.size(); i++) {
			//Ok so basically it will be, Attackers teritory scaled to Defenders victory overhead, divided between victors
			int tmp = Defenders.size();
			float avaivablet = Agressors[i].teritory / (100 * (pceffects / tmp));
			for (int b = 0; b < Defenders.size(); b++) {
				Defenders[b].teritory = Defenders[b].teritory + avaivablet;
				Agressors[i].teritory = Agressors[i].teritory - avaivablet;
			}
			Agressors[i].teritory = Agressors[i].teritory - (avaivablet * tmp);
			if (Agressors[i].teritory < 0) {
				std::cout << Agressors[i].name << " was annexed!" << std::endl << std::endl;
			}
		}
		std::cout << "A war has ended!" << std::endl << std::endl;
	}
	if (AVic > DVic) {
		int pceffects = AVic - DVic;
		for (int i = 0; i < Defenders.size(); i++) {
			//Ok so basically it will be, Attackers teritory scaled to Defenders victory overhead, divided between victors
			int tmp = Agressors.size();
			float avaivablet = Agressors[i].teritory / (100 * (pceffects / tmp));
			for (int b = 0; b < Agressors.size(); b++) {
				Agressors[b].teritory = Agressors[b].teritory + avaivablet;
				Defenders[i].teritory = Defenders[i].teritory - avaivablet;
			}
			Defenders[i].teritory = Defenders[i].teritory - (avaivablet * tmp);
			if (Defenders[i].teritory < 0) {
				std::cout << Agressors[i].name << " was annexed!" << std::endl << std::endl;
			}
		}
		std::cout << "A war has ended!" << std::endl << std::endl;
	}
}
