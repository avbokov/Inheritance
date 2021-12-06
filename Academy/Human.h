#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:

	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	unsigned int get_age()const;
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(unsigned int age);

	//				Constructors:

	Human(const std::string& last_name, const std::string& first_name, unsigned int age);
	~Human();

	//				Methods:

	void print()const;
};