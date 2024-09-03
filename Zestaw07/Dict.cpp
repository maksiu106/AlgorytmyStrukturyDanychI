#include <iostream>
#include <fstream>
#include <utility>

#include "Dict.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
	std::string name = argv[1];

	Dict<std::string, std::string> dictionary;

	std::ifstream file(name);
	std::string line, first, second;

	while(std::getline(file, line)) { //wprowadzanie słów do słownika
		std::istringstream modifier(line);
		modifier >> first >> second;
		std::pair<std::string, std::string> input = std::make_pair(first, second);
		dictionary.insert(input);
	}

	file.close();

	std::string argument;
	while (std::cin >> argument) {
		if (dictionary.find(argument)) std::cout << dictionary[argument] << std::endl;
		else std::cout << "-" << std::endl;
	}
}
