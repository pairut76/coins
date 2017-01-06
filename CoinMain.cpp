//Pairut Dumkuengthanant
//64856070
#include <iostream>
using namespace std;
#include "Coins.h"
const int CENTS_FOR_CANDYBAR = 68;
void presentMenu()
{
	cout <<"   * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
		<< "   *		 PIGGY BANK MENU			 *\n"
		<< "   *							 *\n"
		<< "   * OPTION					ENTER	 *\n"
		<< "   *							 *\n"
		<< "   *   Show Balance (in $)			B or b	 *\n"
		<< "   *   Show Coins in the Bank			C or c	 *\n"
		<< "   *   Deposit Coins				D or d	 *\n"
		<< "   *   Get Coins for Purchase			P or p	 *\n"
		<< "   *							 *\n"
		<< "   *   Quit					Q or q	 *\n"
		<< "   *							 *\n"
		<< "   * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
}

int main()
{
	/*Coins pocket(100, 10, 10, 100);
	Coins change(0, 0, 3, 55);*/
	int const chips = 68;
	//Coins c_found(0,0,0,0);
	Coins pocket(5, 3, 6, 8), piggyBank(50, 50, 50, 50);
	cout << "initial total in bank: " << piggyBank << endl;
	cout << "initial total in pocket: " << pocket << endl;

	Coins pay_chips = pocket.extractChange(chips);
	cout << "after buying chips in pocket: "<<pocket << endl;

	pocket.depositChange(piggyBank);
	piggyBank.extractChange(piggyBank.total);

	cout << "after transfer pocket: " << pocket << endl;
	cout << "after transfer bank: " << piggyBank << endl;

	cout << "coins found: q, d, n, p: ";
	int q, d, n, p;
	cin >> q>> d>> n>> p;
	//cout << q<<d<< n<< p << endl;

	Coins c_found(q, d, n, p);
	cout << "found: "<<c_found << endl;
	piggyBank.depositChange(c_found);
	c_found.extractChange(c_found.total);


	cout << "new bank total in bank: " << piggyBank << endl;
	//cout << c_found;
	//presentMenu();
	return 0;
}
