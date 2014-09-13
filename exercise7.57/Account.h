#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
using namespace std;
class Account
{
public:
	Account() = default;
	Account(const string &s, double d) :owner(s), amount(d)
	{
		//initRate();
	}
	void calculate(){ amount += amount*interestRate; }
	static double rate(){ return interestRate; }
	static void rate(double);
private:
	string owner;
	double amount = 0;
	static double interestRate;
	static double initRate();
};
#endif