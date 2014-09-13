#include"Sales_data.h"
#include<iostream>
using namespace std;
//构造函数
Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}
//类成员函数
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
//非成员函数
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream & print(ostream &os, const Sales_data &item)
{
	os <<"ISBN："<< item.isbn() << " 销量：" << item.units_sold 
		<< " 收入："<< item.revenue << " 平均价格：" <<item.avg_price();
	return os;
}
istream & read(istream &is, Sales_data &item)
{
	double price = 0;
	//cout << "请输入ISBN编号、销量和单价" << endl;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}