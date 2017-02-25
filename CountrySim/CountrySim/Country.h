#pragma once
#include <iostream>
#include <string>


class Country
{
public:
	std::string ideologyc[4];
	std::string name;
	std::string prefix;
	std::string suffix;
	std::string edicts[10];
	std::string passededicts[1];
	Country();
	int GetStats(int x);
	void Revolution();
	void RerollIdeology();
	void RerollSuffix();
	void Election();
	void PassEdict();
	~Country();
private:
	bool fed;
	int population;
	int stability;
	int teritory;
	std::string leader;
	std::string ideology;
};

