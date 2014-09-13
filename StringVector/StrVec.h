#ifndef STRVEC_H
#define STRVEC_H

#include<memory>
#include<initializer_list>
#include<string>
using namespace std;
class StrVec
{
public:
	StrVec() :begin_iter(nullptr), end_iter(nullptr), cap(nullptr){}
	StrVec(initializer_list<string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	string* begin(){ return begin_iter; }
	const string* cbegin() const{ return begin_iter; }
	string* end(){ return end_iter; }
	const string* cend() const{ return end_iter; }
	void push_back(const string&);
	size_t size() const{ return end_iter - begin_iter; }
	size_t capacity() const{ return cap - begin_iter; }
	void reserve(size_t);
	void resize(size_t, const string &str = "");
	void print();
private:
	static allocator<string> alloc;
	string* begin_iter;
	string* end_iter;
	string* cap;

	void free();
	void prepare_space();
	void reallocate();
	void reallocate(size_t);
};

#endif