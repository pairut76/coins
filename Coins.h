//Pairut Dumkuengthanant
//64856070

#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins
{
public:
	int qq, dd, nn, pp;
	Coins(int q, int d, int n, int p) : qq(q), dd(d), nn(n), pp(p) {};
	int total = (qq * 25) + (dd * 10) + (nn * 5) + (pp);

	void conversion(int ntotal)
	{
		//int q, d, n, p;
		qq = ntotal / 25;
		ntotal = ntotal % 25;
		dd = ntotal / 10;
		ntotal = ntotal % 10;
		nn = ntotal / 5;
		ntotal = ntotal % 5;
		pp = ntotal / 1;
		//return Coins(qq, dd, nn, pp);
	}
	void depositChange(Coins c)
	{
		total=total+ (c.qq * 25) + (c.dd * 10) + (c.nn * 5) + c.pp;
		//c.qq, c.dd, c.nn, c.pp = 0;
		conversion(total);
	}
	bool hasSufficientAmount(int amount)
	{
		return total >= amount;
	}
	Coins extractChange(int amount)
	{
		total = total - amount;
		conversion(total);
		return Coins(qq,dd,nn,pp);
	}
	//int total(){ return total; }
	void print(ostream & out)
	{
		out << qq<<" q "<< dd <<" d "<<nn<<" n "<<pp<<" p "<<endl;
		out << "amount total: " << total << endl;;
	}
	
private:
	int quarters, dimes, nickels, pennies;
};
ostream & operator << (ostream & out, Coins & c)
{
	c.print(out);
	return out;
}

