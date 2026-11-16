#include<iostream>
using namespace std;
#include"SimCard.h"
#include"StringFunc.h"

PrePaidSimCard::PrePaidSimCard()
{
	copyString(simNumber , "9999999999");
	balance = 0;
	dataAllowenceMB = 0;
	validityDays = 0;
	simLockFlag = true;
}
PrePaidSimCard::PrePaidSimCard(const char * number, double initialBalance)
{
	copyString(simNumber, number);
	if (initialBalance > 0)
	{
		balance = initialBalance;
		simLockFlag = false;
		dataAllowenceMB = 1024;
		validityDays = 30;
	}
	else
	{
		balance = 0;
		dataAllowenceMB = 0;
		validityDays = 0;
		simLockFlag = true;
	}
}
void PrePaidSimCard::displayStatus()
{
	cout << " Your Current Balance :  " << balance << endl;
	cout << " Remaining Data in GB : " << dataAllowenceMB / 1024 << endl; 
	cout << " Validity Period in days : " << validityDays << endl;
	if (simLockFlag == true)
	{
		cout << " Sim is blocked " << endl ; 
	}
	else
	{
		cout << " Sim is Active" << endl;
	}
}
double PrePaidSimCard::getBalance()
{
	return balance;
}
double PrePaidSimCard::getDataRemainingGB()
{
	return dataAllowenceMB / 1024;
}
int PrePaidSimCard::getValidityDays()
{
	return validityDays;
}
bool PrePaidSimCard::isCardBlocked()
{
	return simLockFlag;
}
bool PrePaidSimCard::recharge(double amount)
{
	if (amount == 10 || amount == 20 || amount == 50 || amount == 100 || amount == 200 || amount == 500)
	{
		balance =balance+ amount;
		validityDays = validityDays+(int)(amount / 100) * 30;
		return true;
	}
	return false;
}
bool PrePaidSimCard::unblock()
{
	if (balance > 0)
	{
		simLockFlag = false;
		return true;
	}
	else
	{
		
		cout << "ERROR ( balance is zero )" << endl;
		return false;
	}
}
bool PrePaidSimCard::setDataAllowanceGB(double gb)
{
	return setDataAllowanceMB(gb * 1024);
}
bool PrePaidSimCard::setDataAllowanceMB(double mb)
{
	if (mb >= 0 && mb <= 102400)
	{
		dataAllowenceMB = mb;
		return true;
	}
	cout << "ERROR (data must be between 0 and 102400 MB)" << endl;
	return false;
}
bool PrePaidSimCard::consumeData(double mb)
{
	double shortFall;
	double overageCost;
	if (simLockFlag == true)
	{
		return false;
	}
	else if (dataAllowenceMB >= mb)
	{
		dataAllowenceMB = dataAllowenceMB - mb;
		return true;
	}
	else
	{
		shortFall = mb - dataAllowenceMB;
		overageCost = shortFall * 0.01;
		if (balance >= overageCost)
		{
			dataAllowenceMB = 0;
			balance = balance - overageCost;
			return true;
		}
		else
		{
			return false;
		}
	}
}