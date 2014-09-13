#include"Account.h"

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}

double Account::initRate()
{
	interestRate = 0.1;
	return interestRate;
}