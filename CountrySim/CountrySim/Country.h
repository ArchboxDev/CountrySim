#pragma once
#include <iostream>
#include <string>
#include <vector>


class Country
{
public:
	bool elections;
	std::string ideologyc[4];
	std::string name;
	std::string prefix;
	std::string suffix;
	std::vector<float> thoughtsof;
	std::vector<std::string> edicts;
	std::vector<std::string> passededicts;
	float infantrymight;
	float seamight;
	float airmight;
	float militarymight;
	Country();
	void InitOpnion( std::vector<Country> list);
	int GetStats(int x);
	std::string GetLeader();
	void UpdatePop();
	void Revolution(std::vector<Country> countrylist);
	void RerollIdeology();
	void RerollPrefix();
	void Election();
	void PassEdict();
	void CancelEdict();
	void ImproveThoughts(int index, float amount);
	void SetThoughts(int index, float amount);
	void ResetThoughts(int index, std::vector<Country> list);
	void SetMilitaryStats();
	void SetMightness();
	void MakeEquip();
	void ChangeConscriptionLaw(bool losing);
	std::string GetConscriptionLaw();
	std::string ideology;
	friend bool operator== (const Country &c1, const Country &c2);
	~Country();
private:
	bool fed;
	std::vector<std::string> conscriptionlaws;
	std::string conscriptionlaw;
	int population;
	int stability;
	int teritory;
	float manpower;
	float workers;
	int infantry;
	float armysize;
	float sailors;
	float infantryequip;
	float tanks;
	float pilots;
	float planes;
	float ships;
	float shipsquads;
	std::string strategy;
	std::string leader;
};

