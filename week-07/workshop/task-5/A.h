#pragma once

#include <string>

class A
{
private:
	std::string *name;
public:
	A(const std::string &n): name(new std::string(n)) {}
	A(const A &a): A(*a.name) {}
	~A();
	void setName(const std::string &n);
	void printName();
};
