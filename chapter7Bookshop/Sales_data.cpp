#include"Sales_data.h"
#include<iostream>
using namespace std;
//���캯��
Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}
//���Ա����
inline
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

bool Sales_data::combine(const Sales_data &rhs)
{
	try{
		if (isbn() == rhs.isbn())
		{
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return true;
		}
		else
			throw runtime_error("Data must refer to the same ISBN");
	}
	catch (runtime_error err)
	{
		cout << err.what() << endl;
		cout << "Fail to combine !" << endl;
		return false;
	}
}
//�ǳ�Ա����
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream & print(ostream &os, const Sales_data &item)
{
	os <<"ISBN��"<< item.isbn() << " ������" << item.units_sold 
		<< " ���룺"<< item.revenue << " ƽ���۸�" <<item.avg_price();
	return os;
}
istream & read(istream &is, Sales_data &item)
{
	double price = 0;
	//cout << "������ISBN��š������͵���" << endl;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}