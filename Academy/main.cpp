// Academy
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"


#include<iostream>
#include<string>
#include<ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
//#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
//
//#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
//#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
//
//#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
//#define TEACHER_GIVE_PARAMETERS speciality, experience

void main()
{
	setlocale(LC_ALL, "");

	Human hm("Тупенко", "Василий", 18);
	hm.print();
	Student st("Pinkman", "Jessie", 28, "Chemistry", "WW_01", 90, 85);
	st.print();
	Teacher t("White", "Walter", 50, "Chemistry", 20);
	t.print();
	Graduate gr("Shrader", "Hulk", 40, "Criminalistic", "OBN", 90, 90, "How to catch Heisenberg");
	gr.print();

}