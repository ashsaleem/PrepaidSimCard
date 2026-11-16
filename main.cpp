#include<iostream>
#include"SimCard.h"
#include"StringFunc.h"
using namespace std;

int main()
{
	cout << "Test Case 1: Defult construct a SIM " << endl;

	PrePaidSimCard a;
	a.displayStatus();
	
	cout << endl;

	cout << "Test Case 2: Construct a Sim with number only" << endl;

	PrePaidSimCard b("03334379767");
	b.displayStatus();

	cout << endl;

	cout << "Test Case 3: Construct a SIM explicitly with initialBalance = 0; confirm it stayed Blocked despite using the activating constructor" << endl;

	PrePaidSimCard b1("03334379767",0);
	b1.displayStatus();

	cout << endl;

	cout << "Test Case 4 : Call recharge(15) - an invalid denomination - and confirm rejection." << endl;

	cout << a.recharge(15);

	cout << endl;

	cout << "Test Case 5 : Call recharge(100) on the active SIM; print validityDays before and after to confirm both balance and validity changed." << endl;

	PrePaidSimCard c("03334379767", 0);
	cout << c.getValidityDays() << endl;
	cout << c.recharge(100) << endl;
	cout << c.getValidityDays() << endl;

	cout << endl;

	cout << "Test Case 6 : Call consumeData() for an amount within the current allowance; confirm plain deduction." << endl;

	cout << c.consumeData(2) << endl;
	cout << c.getBalance() << endl;
	cout << c.getValidityDays() << endl;
	cout << c.getDataRemainingGB() << endl;

	cout << endl;

	cout << "Test Case 7 : Call consumeData() for an amount exceeding the allowance but payable from balance; print balance before and after to prove the overage was actually billed." << endl;

	cout << c.getBalance() << endl;
	cout << c.consumeData(2) << endl;
	cout << c.getBalance() << endl;
	cout << c.getValidityDays() << endl;
	cout << c.getDataRemainingGB() << endl;

	cout << endl;

	cout << "Test Case 8 : Call consumeData() for an amount exceeding both allowance and balance; confirm clean failure with no partial state change." << endl;

	cout << c.getBalance() << endl;
	cout << c.consumeData(2) << endl;
	cout << c.getBalance() << endl;
	cout << c.getValidityDays() << endl;
	cout << c.getDataRemainingGB() << endl;

	cout << endl;

	cout << "Test Case 9 : On the still-Blocked SIM from step 3, call unblock() (should be denied), then recharge() it, then unblock() again (should succeed)." << endl;

	cout << b1.unblock() << endl;
	cout << b1.recharge(100) << endl;
	cout << b1.unblock() << endl;

	cout << endl;

	return 0;
}