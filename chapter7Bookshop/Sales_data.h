#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
using namespace std;
class Sales_data
{
	//数据成员
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0; 
public:
	//构造函数
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s){}
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n){}
	Sales_data(istream &);
	//成员函数
	string isbn() const{ return bookNo; }
	bool combine(const Sales_data &);
private:
	double avg_price() const;
friend Sales_data add(const Sales_data &, const Sales_data &);
friend ostream & print(ostream &, const Sales_data &);
friend	istream & read(istream &, Sales_data &);
};
//作为接口的非成员函数
Sales_data add(const Sales_data &,const Sales_data &);
ostream & print(ostream &,const Sales_data &);
istream & read(istream &,Sales_data &); 
#endif