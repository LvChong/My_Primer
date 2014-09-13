#define _SCL_SECURE_NO_WARNINGS

#include"StrVec.h"
#include<algorithm>
#include<iostream>
using namespace std;

allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &s)
{
	auto p = alloc.allocate(s.size());
	auto q = uninitialized_copy(s.cbegin(), s.cend(), p);
	free();
	begin_iter = p;
	end_iter = q;
	cap = q;
}

StrVec::StrVec(initializer_list<string> il)
{
	reallocate(il.size());
	auto p = begin_iter;
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		alloc.construct(p++, *beg);
	end_iter = p;
}

StrVec& StrVec::operator=(const StrVec &s)
{
	auto p = alloc.allocate(s.size());
	auto q = uninitialized_copy(s.cbegin(), s.cend(), p);
	free();
	begin_iter = p;
	end_iter = q;
	cap = q;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &str)
{
	prepare_space();
	alloc.construct(end_iter++, str);
}

void StrVec::reserve(size_t new_capacity)
{
		reallocate(new_capacity);
}

void StrVec::resize(size_t newsize,const string &str)
{
	if (newsize <= size())
	{
		auto q = end_iter;
		auto p = begin_iter + newsize;
		while (q != p)
			alloc.destroy(--q);
	}
	else
	{
		if (newsize > capacity())
			reallocate(newsize);
		auto p = end_iter;
		auto q = begin_iter + newsize;
		while (p != q)
			alloc.construct(p++, str);
	}
	end_iter = begin_iter + newsize;
}

void StrVec::print()
{
	if (!begin_iter)
		cout << "empty StrVec!" << endl;
	else
	{
		for (auto iter = begin_iter; iter!=end_iter; ++iter)
			cout << *iter << " ";
		cout << endl;
	}
}

void StrVec::free()
{
	if (begin_iter)
	{
		
		for (auto iter = end_iter; iter != begin_iter;)
			alloc.destroy(--iter);
		alloc.deallocate(begin_iter, capacity());
		
		/*
		auto q = &begin_iter;
		for_each(begin_iter, end_iter, [this](string &p){alloc.destroy(&p); });
		alloc.deallocate(begin_iter, capacity());
		*/
		
	}
}

void StrVec::prepare_space()
{
	if (end_iter == cap)
		reallocate();
}

void StrVec::reallocate()
{
	size_t newcapacity = begin_iter ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = begin_iter;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, move(*elem++));
	free();
	begin_iter = newdata;
	end_iter = dest;
	cap = begin_iter + newcapacity;
}

void StrVec::reallocate(size_t newcapacity)
{
	if (newcapacity > capacity())
	{
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = begin_iter;
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, move(*elem++));
		free();
		begin_iter = newdata;
		end_iter = dest;
		cap = begin_iter + newcapacity;
	}
}
