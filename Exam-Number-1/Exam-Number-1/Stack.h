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
#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
using namespace std;

const int MAX = 100;
const int EMPTY_STACK = -1;

template <typename T>
class Stack
{
	T a[MAX];
	int topIndex;
public:
	Stack();
	bool empty() const;
	bool full() const;

	T top() const;
	void push(T const&);
	T pop();
};

template <typename T>
Stack<T>::Stack() : topIndex(EMPTY_STACK) {}

template <typename T>
bool Stack<T>::empty() const
{
	return topIndex == EMPTY_STACK;
}

template <typename T>
bool Stack<T>::full() const
{
	return topIndex == MAX - 1;
}

template <typename T>
T Stack<T>::pop()
{
	if (empty()) {
		std::cout << "Empty stack!\n";
		return T();
	}
	return a[topIndex--];
}

template <typename T>
void Stack<T>::push(T const& rhs)
{
	if (full()) {
		std::cout << "Full stack!\n";
	}
	else
		a[++topIndex] = rhs;
}

template <typename T>
T Stack<T>::top() const
{
	if (empty()) {
		std::cout << "Empty stack\n";
		return T();
	}

	return a[topIndex];
}