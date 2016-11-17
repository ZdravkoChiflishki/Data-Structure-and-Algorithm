/*Група 1
Вашата мила и добра леля Гинка ви звъни и ви казва, колко трудности изпитва нейната
комшийка с научаването на колите, и подредбите им, и ви моли за помощ. Тя отчаяно
желае вие да к напишете програма на С++ с която тя да може да вкарва в своята база
данни / просто текстово файлче/ структури от тип Съсед с член данни {име, тел. номер
и кола}. Също така тя иска да може да паркира кола, но колите могат да се паркират
само една зад друга, като в задънена улица/ само с един изход/. Но най – важното е, че
тя иска когато някоя кола е запушена, то по колата, тя да може да провери в своя файл,
на кого е колата, и какъв е номерът му/можете да го изкарате в стандартния изход/, за
да може човекът да си извади колата ( да, ще ви трябва и функция за изваждане на
коли). Тя ще ви бъде много благодарна ако го направите ! Единственото нещо, което
иска от вас е да го направите за по – малко от два часа. Добрите ви асистенти са ви
предали всичко, затова няма от какво да се притеснявате. И накрая, но не на последно
място, тя ви пожелава успех !*/
#include<cstring>
#include<iostream>
using namespace std;
const int Max_Person_Name = 100;
const int Max_Car_Number = 100;
class Neighborhood {
	char *PersonName;
	char *CarNumber;
	int PersonPhoneNumber;
public:
	Neighborhood(const char *_PersonName = " ", const char *_CarNumber = " ", int _PersonPhoneNumber = 0) {
		PersonName = new char[Max_Person_Name];
		if (!PersonName) {
			cerr << "Error!";
			exit(1);
		}
		strcpy(PersonName, _PersonName);
		CarNumber = new char[Max_Car_Number];
		if (!CarNumber) {
			cerr << "Error!";
			exit(1);
		}
		strcpy(CarNumber, _CarNumber);
		PersonPhoneNumber = _PersonPhoneNumber;
	}
	Neighborhood(const Neighborhood &other) {
		PersonName = new char[Max_Person_Name];
		if (!PersonName) {
			cerr << "Error";
			exit(1);
		}
		strcpy(PersonName, other.PersonName);
		CarNumber = new char[Max_Car_Number];
		if (!CarNumber) {
			cerr << "Error";
			exit(1);
		}
		strcpy(CarNumber, other.CarNumber);
		PersonPhoneNumber = other.PersonPhoneNumber;
	}
	~Neighborhood() {
		delete[] PersonName;
		delete[] CarNumber;
	}
	char *getPersonName() const {
		return PersonName;
	}
	char *getCarName() const {
		return CarNumber;
	}
	int getPersonPhoneNumber() const {
		return PersonPhoneNumber;
	}
	void PrintPerson() const {
		cout << "Person Name:" << PersonName << endl;
		cout << "Person Car Number:" << CarNumber << endl;
		cout << "Person Phone Number:" << PersonPhoneNumber << endl;
	}
	Neighborhood &operator=(const Neighborhood& other) {
		if (this != &other) {
			PersonName = other.PersonName;
			CarNumber = other.CarNumber;
			PersonPhoneNumber = other.PersonPhoneNumber;
		}
		return *this;
	}
	friend istream &operator>>(istream& istr, Neighborhood &obj) {
		return (istr >> obj.PersonPhoneNumber).getline(obj.PersonName, Max_Person_Name).getline(obj.CarNumber,Max_Car_Number);
	}
	friend ostream &operator<<(ostream& ostr, Neighborhood &obj) {
		return ostr << "Person Name: " << obj.PersonName
			<< "Person Car Number : " << obj.CarNumber
			<< "Person Phone Number : " << obj.PersonPhoneNumber;

	}	
};
