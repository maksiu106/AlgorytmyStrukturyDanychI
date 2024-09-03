#include <iostream>
#include <string>

#include "ArrayStack.hpp"

//ten program przyjmie na standardowe wejscie komendy generowane przez program "generator.x"
int main()
{
	Stack stos(1000000);
	std::string command;

	while (std::getline(std::cin, command)) //wczytuje komendy az do znaku EOF
	{
		if (command[0] == 'A')
		{
			std::string number = command.substr(2);
			stos.push(std::stoi(number));
		}
		else if (command[0] == 'D')
		{
			if (stos.empty() == 1) std::cout << "EMPTY" << std::endl;
			else std::cout << stos.pop() << std::endl;
		}
		else if (command[0] == 'S')
		{
			std::cout << stos.size() << std::endl;
		}
	}
}
