//Pairut Dumkuengthanant
//64856070

#include<iostream>
using namespace std;
#include "Coins.h"
void presentMenu()
{
	cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
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
int eval_Cmd(Coins & myCoins, char choice)
{
	switch (choice)
	{
	case 'B': case 'b': cout <<myCoins.total << endl;
		break;

	case 'C': case 'c':
		cout << myCoins.qq << " q " << myCoins.dd << " d " << myCoins.nn << " n " << myCoins.pp << " p " << endl;
		break;

	case 'D': case 'd':
	{


		cout << "coins deposit: q, d, n, p: ";
		int q, d, n, p;
		cin >> q >> d >> n >> p;
		//cout << q << d << n << p << endl;
		Coins c_deposit(q, d, n, p);
		myCoins.depositChange(c_deposit);
		c_deposit.extractChange(c_deposit.total);
		break;
	}
	case 'P':case'p':
		int pchase;
		cout << "how much do you need: ";
		cin >> pchase;
		if (myCoins.hasSufficientAmount(pchase)) {
			myCoins.extractChange(pchase);
			break;
		}
		cout << "not enough money!" << endl;
		break;
	case 'Q': case'q':
		return -1;
	default:
		cout << "wrong input choose from menu!" << endl;
		break;
	}
}
int main()
{
	Coins myCoins(0, 0, 0, 0);
	char x;
	int val=0;
	while (val!=-1)
	{
		presentMenu();
		cout << "Enter choice: ";
		cin >> x;
		val=eval_Cmd(myCoins, x);
	}

}
