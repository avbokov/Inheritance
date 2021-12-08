#include<iostream>
using namespace std;

class Weapon
{
	int damage; // наносимый урон
	int size;	// размер в У.Е.

public:
	Weapon(int damage, int size) :damage(damage), size(size)
	{
	}
	virtual ~Weapon()
	{
	}
	virtual void apply() = 0; // чисто виртуальный метод (=0 - нет определения)
	// как раз этот чисто виртуальный метод и делать класс абстрактным
	virtual void info()
	{
		cout << "Damage:\t" << damage << endl;
		cout << "Size:\t" << size << endl;
	}

};

class ColdArms :public Weapon
{
public:
	ColdArms(int damage, int size) : Weapon(damage, size) {}
	~ColdArms() {}
	// этот класс НЕ определяет чисто виртуальный метод apply,
	// а просто наследует его читсую виртуальность и следовательно,
	// этот класс также является абстрактным.
};

class Knife :public ColdArms
{
public:
	Knife(int damage, int size) :ColdArms(damage, size) {}
	~Knife() {}
	// этот класс уже является конкретным,
	// поскольку он реализует чисто виртуальную функцию apply
	void apply()
	{
		cout << "Чистить картошку, резать яблоки" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

class Machete : public ColdArms
{
public:
	Machete(int damage, int size) :ColdArms(damage, size) {}
	~Machete() {}

	void apply()
	{
		cout << "Отлично рубит сахарный тростник, также очень удобен для стрижки деревьев" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Weapon w(20, 5); w.info(); // создать экземпляр этого класса нельзя, поскольку он является абстрактным

	//ColdArms ca(20, 5); // создать экземпляр этого класса нельзя, поскольку он тоже является абстрактным

	Knife kn(20, 5); kn.info();
	Machete m(50, 25); m.info();
}