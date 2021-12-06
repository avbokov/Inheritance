#pragma once
#include"Human.h"

#include<iostream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance

class Student :public Human // показываем компилятору, что хотим унаследовать все свой ства класса Human 
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const;
	const std::string& get_group()const;
	double get_rating()const;
	double get_attendance()const;
	void set_speciality(const std::string& speciality);
	void set_group(const std::string& group);
	void set_rating(double rating);
	void set_attendance(double attendence);

	//				Constructors:

	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS);
	~Student();

	//				Methods:

	void print()const;
};