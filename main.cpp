#include <iostream>
#include <vector>
#include "Functor.h"

void printHeader();

// перегружаю оператор << для cout (чтобы выводить std::vector<VType>)
template <typename VType>
std::ostream& operator<< (std::ostream& out, const std::vector<VType>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

int main()
{
	printHeader();

	std::vector<int> v{4, 1, 3, 6, 25, 54};
	Functor f;
	f(v);
	std::cout << "[IN]: " << v << std::endl;
	std::cout << "[OUT]: get_sum() = " << f.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << f.get_count() << std::endl;

	return 0;
}

// функции
// заголовок 
void printHeader()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   // задаём русский текст
	system("chcp 1251");            // настраиваем кодировку консоли
	std::system("cls");
	cout << "Задача 3. Счётчик чисел\n"
		 << "-----------------------\n" << endl;
}