#pragma once
#include"Human.h"

#include<iostream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience


class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;

public:

	const std::string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(unsigned int experience);

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS);
	~Teacher();

	//				Methods:

	void print()const;
};