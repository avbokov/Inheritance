#include"Teacher.h"
#include"Human.h"

const std::string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}

void Teacher::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}

Teacher::Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}

Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}

//				Methods:

void Teacher::print()const
{
	Human::print();
	cout << speciality << " " << experience << endl;
}