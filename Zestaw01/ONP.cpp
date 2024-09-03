#include <iostream>
#include <string>

#include "ArrayStack.hpp"

int main()
{
	Stack stos(1000);
	std::string result = "";
	std::string arg;
	while (std::cin >> arg)
	{
		if (arg == "(") stos.push(int('(')); //nawias otwierajacy idzie na stos; -1 jest jego oznaczeniem
		else if (arg == ")") //przy nawiasie zamykajacym trzeba wyrzucic ze stosu wszystkie operatory az nie usunie sie z niego jakiegos nawiasu otwierajacego
		{
			char to_out;
			do
			{
				to_out = char(stos.pop());
				if (to_out!='(') result = result + to_out + ' ';
			}while (to_out != '(');
		}
		else if (arg == "+" || arg == "-" || arg == "*" || arg == "/") //jesli jest to operacja, wrzucamy ja na stos
		{
			stos.push(int(arg[0]));
		}
		else result = result + arg + ' '; //jesli liczba albo zmienna
		if (std::cin.get() == '\n') break; //sprawdzenie, czy wprowadzono znak konca linii - a wiec konca rownania
	}
	while (stos.size()!=0) result = result + char(stos.pop()) + ' '; //na koncu oprozniamy stos
	result.pop_back();
	std::cout << result << std::endl;
}
