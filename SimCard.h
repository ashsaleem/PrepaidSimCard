#include<iostream>
using namespace std;
#include"StringFunc.h"
#ifndef SIM_CARD_H
#define SIM_CARD_H

class PrePaidSimCard
{
	char simNumber[14];
	double balance;
	double dataAllowenceMB;
	int validityDays;
	bool simLockFlag;
	bool setDataAllowanceMB(double gb);
public:
	PrePaidSimCard();
	PrePaidSimCard(const char* number, double initialBalanace = 50.0);
	void displayStatus();
	double getBalance();
	double getDataRemainingGB();
	int getValidityDays();
	bool isCardBlocked();
	bool recharge(double amount);
	bool unblock();
	bool setDataAllowanceGB(double gb);
	bool consumeData(double mb);
	

};
#endif
