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
	std::vector<std::string> edicts;
	std::vector<std::string> passededicts;
	Country();
	int GetStats(int x);
	std::string GetLeader();
	void UpdatePop();
	void Revolution();
	void RerollIdeology();
	void RerollPrefix();
	void Election();
	void PassEdict();
	void CancelEdict();
	~Country();
private:
	bool fed;
	int population;
	int stability;
	int teritory;
	std::string leader;
	std::string ideology;
};

