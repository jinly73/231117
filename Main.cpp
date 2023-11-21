#include <iostream>
#include "SimpleEngine.h"
#include "Player.h"
#include "World.h"
#include <algorithm>


using namespace std;

class NHR
{
public:
	NHR(int NewPlayer) { Money = NewPlayer; }
	virtual ~NHR() {}

	int Money;

	bool operator > (const NHR& RHS) const
	{
		return this->Money > RHS.Money;
	}

	bool operator < (const NHR& RHS) const
	{
		return this->Money < RHS.Money;
	}
};


int compare(const NHR& LHS, const NHR& RHS)
{
	if (LHS.Money > RHS.Money)
	{
		return true;
	}
	return false;
}

int main()
{
	/*
	vector<NHR> NHRS; // sorting Á¤·Ä

	NHRS.push_back(NHR(20));
	NHRS.push_back(NHR(110));
	NHRS.push_back(NHR(40));
	NHRS.push_back(NHR(50));
	//cout << (NHRS[1] > NHRS[2]) << endl;
	sort(NHRS.begin(), NHRS.end(), [](const NHR& LHS, const NHR& RHS)

	
	SimpleEngine* MyEngine = new SimpleEngine();
	MyEngine->LoadLevel("a. smap");
	MyEngine->Run();


	delete MyEngine;
	*/

	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	//SimpleEngine::GetInstance();

	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;


	return 0;
}