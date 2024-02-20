#ifndef FILEHANDLER_HPP_
#define FILEHANDLER_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "RSA.hpp"

class FileHandler {
public:
	static std::string load_file(std::string path) { //wczytanie pliku do stringu i zwrócenie całego
		std::ifstream file(path);
		std::string line, result;
		while (std::getline(file, line)) {
			result += line;
			if (!file.eof()) result += "\n";
		}
		file.close();
		return result;
	}

	static void crypt_string(std::string message, unsigned long n, int e, std::string name) { //szyfruje string do pliku
		std::ofstream output(name);
		std::string character;

		for (int i=0; i<(int)message.length(); ++i) {
			character = std::to_string((int)message[i]);
			output << RSA::encrypt(std::stoul(character), e, n) << std::endl;
		}
		output.close();
	}

	static void decrypt_string(std::string message, unsigned long n, unsigned long d, std::string name) { //deszyfruje string do pliku
		std::ofstream output(name);
		unsigned long character;
		std::istringstream stream(message);
		std::string line;

		while (std::getline(stream, line)) {
			character = std::stoul(line);
			output << static_cast<char>(RSA::decrypt(character, d, n));
		}
		output.close();
	}
};
#endif /* FILEHANDLER_HPP_ */
