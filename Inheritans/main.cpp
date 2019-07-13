#include <iostream>
#include <string>
using namespace std;

class Human
{
	string name;
	unsigned int age;
public:
	const string& get_name() const
	{
		return this->name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_name(string& name)
	{
		this->name = name;
    }
	void set_age(unsigned int age)
	{
	    this->age = age;
	}
	Human(string name, unsigned int age) : name(name), age(age)
	{
		cout << "HConstructor:\t" <<this<< endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" <<this<< endl;
	}
	//Metod
	void info()
	{
		cout << name << " " << age << " лет\n" << endl;
	}
};
class Student :public Human
{
	string specialty;
	unsigned int year; //год обучения.
	int karma; //успеваемость.
public:
	const string& get_specialty() const
	{
		return this->specialty;
  }
	unsigned int get_year() const
	{
		return this->year;
	}
	int get_karma() const
	{
		return this->karma;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	unsigned int set_year(unsigned int year)
	{
		return this->year = year;
	}
	int set_karma(int karma)
	{
		return this->karma = karma;
	}
	//Constructor:
	Student(
		const string& name, unsigned int age,
	    const string& specialty, unsigned int year = 1, int karma = 0 
	)
		:Human (name,age)

	{
		this->specialty = specialty;
		this->year = year;
		this->karma = karma;
		cout << "SConstruktor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDefconstruktor:\t" << this << endl;
	}
//Metods:
	void info()
	{
		Human::info();
		cout << "Специальность " << specialty << " ,"<< year <<"-й курс, успеваемость =" << karma << "!"<< endl;
	}

};
class Teacher :public Human
{
	string specialty;
	int evil; //уровень злости
	int xp;
public:
	const string& get_specialty() const
	{
		return this -> specialty;
	}
	unsigned int get_xp() const
	{
		return this->xp;
	}
	unsigned int get_evil() const
	{
		return this->evil;
	}
	const string& set_specialty(const string& specialty) 
	{
		return this->specialty= specialty;
	}
	unsigned int set_xp(unsigned int xp) 
	{
		return this->xp=xp;
	}
	unsigned int sett_evil(int evil) 
	{
		return this->evil=evil;
	}
	//Construktor
	Teacher
	(const string& name, unsigned int age, const string&specialty, unsigned int xp = 0, int evil = 0)
		:Human(name, age)
	{
		this->specialty = specialty;
		this->xp = xp;
		this->evil = evil;
		cout << "TConstruktor:\t" << this << endl;
		
	}
		~Teacher()
	{
		cout << "TDefconstruktor:\t" << this << endl;
	}

	//Metods
	void info()
	{
		Human::info();
		cout << "Специальность: " << specialty << " , опыт преподавания " << xp << " лет, " << "уровень злости:" << evil<<"%" << endl;
	}
};
class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme() const
	{
		return this->diploma_theme;
	}
	const string& set_diploma_theme(const string& diplom_theme)
	{
		return this->diploma_theme= diploma_theme;
	}
	// Construktors:
	Graduate
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int year, int karma,
		const string& diploma_theme
	) :Student(name, age, specialty, year, karma)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstruktor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDefconstruktor:\t" << this << endl;
	}
	//Metods:
	void info()
	{
		Student::info();
		cout << "Тема дипломного проэкта:" << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human h("Василий", 20);
	h.info();
	Student durko("Дурко Василий", 20, "pro");
	durko.info();
	Teacher pablo("Pablo Escobar", 40, "Распространение норкотиков", 25, 50);
	pablo.info();
	Graduate tony("Antonio Montana", 22, " Распространение норкотиков", 5, 90, " Работа с проблемной задолженностью");
	tony.info();
}