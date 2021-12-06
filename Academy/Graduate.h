#pragma once
//#include"Human.h"
#include"Student.h"

#include<iostream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Graduate :public Student
{
	std::string subject;

public:

	const std::string& get_subject()const;
	void set_subject(const std::string& subject);

	//			Constructors:

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject);

	~Graduate();

	//				Methods:

	void print()const;
};