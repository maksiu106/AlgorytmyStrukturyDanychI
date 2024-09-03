#include <iostream>
#include <string>

#include "ArrayList.hpp"

int main()
{
	std::string command;
	ArrayList<int> lista;

	while (std::getline(std::cin, command)) //wczytuje komendy az do znaku EOF
	{
		if (lista.size() > 1000) throw std::out_of_range("Too much elements in your list");

		if (command[0] == 'F') {
			std::string number = command.substr(2);
			lista.push_front(std::stoi(number));
		}
		else if (command[0] == 'B') {
			std::string number = command.substr(2);
			lista.push_back(std::stoi(number));
		}
		else if (command[0] == 'f') {
			if (lista.empty()) std::cout << "EMPTY" << std::endl;
			else std::cout << lista.pop_front() << std::endl;
		}
		else if (command[0] == 'b') {
			if (lista.empty()) std::cout << "EMPTY" << std::endl;
			else std::cout << lista.pop_back() << std::endl;
		}
		else if (command[0] == 'R') {
			int number1 = std::stoi(command.substr(2));
			int number2 = std::stoi(command.substr(command.find(" ", 2)));
			int i = lista.find(number1);
			if (i == -1) std::cout << "FALSE" << std::endl;
			else {
				lista.erase(i);
				lista.insert(i, number2);
				std::cout << "TRUE" << std::endl;
			}
		}
		else if (command[0] == 'S') std::cout << lista.size() << std::endl;
	}
}
