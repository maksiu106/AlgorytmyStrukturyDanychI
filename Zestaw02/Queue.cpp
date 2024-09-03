#include <iostream>
#include <string>

#include "ArrayQueue.hpp"

int main()
{
	Queue kolejka(1000000);
	std::string command;

		while (std::getline(std::cin, command)) //wczytuje komendy az do znaku EOF
		{
			if (command[0] == 'A')
			{
				std::string number = command.substr(2);
				kolejka.push(std::stoi(number));
			}
			else if (command[0] == 'D')
			{
				if (kolejka.empty() == 1) std::cout << "EMPTY" << std::endl;
				else std::cout << kolejka.pop() << std::endl;
			}
			else if (command[0] == 'S')
			{
				std::cout << kolejka.size() << std::endl;
			}
		}
}
