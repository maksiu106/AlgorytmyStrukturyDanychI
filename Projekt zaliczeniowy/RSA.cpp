#include <iostream>

#include "RSA.hpp"
#include "FileHandler.hpp"

int main() {
	std::cout << "Witam w programie sluzacym do szyfrowania plikow metoda RSA. Jaka czynnosc chcesz wykonac?" << std::endl;
	std::cout << "\t(a) Wygeneruj klucze RSA\n\t(b) Zaszyfruj plik tekstowy\n\t(c) Deszyfruj plik tekstowy\n\t(d) Wyjdz z programu" << std::endl;
	std::cout << "Wybierz dzialanie: " << std::flush;
	char decision;
	std::cin >> decision;

	while (decision != 'd') {
		if (decision == 'a') {
			RSA::generate_keys();
		} else if (decision == 'b') {
			std::string file, name;
			std::cout << "Wprowadz sciezke do pliku, ktory chcesz zaszyfrowac: " << std::flush;
			std::cin >> file;
			std::cout << "Wprowadz nazwe, pod ktora chcesz zapisac zaszyfrowany plik: " << std::flush;
			std::cin >> name;

			std::string message = FileHandler::load_file(file);

			int e;
			unsigned long long n;
			std::cout << "Podaj wartosc modulu n: " << std::flush;
			std::cin >> n;
			std::cout << "Podaj wartosc wykladnika e: " << std::flush;
			std::cin >> e;

			FileHandler::crypt_string(message, n, e, name);

			std::cout << "Wiadomosc zostala pomyslnie zaszyfrowana i zapisana w pliku o nazwie " << name << std::endl;
		} else if (decision == 'c') {
			std::string file, name;
			std::cout << "Wprowadz sciezke do pliku, ktory chcesz odszyfrowac: " << std::flush;
			std::cin >> file;
			std::cout << "Wprowadz nazwe, pod ktora chcesz zapisac odszyfrowany plik: " << std::flush;
			std::cin >> name;

			std::string message = FileHandler::load_file(file);

			unsigned long long n, d;
			std::cout << "Podaj wartosc modulu n: " << std::flush;
			std::cin >> n;
			std::cout << "Podaj wartosc wykladnika d: " << std::flush;
			std::cin >> d;

			FileHandler::decrypt_string(message, n, d, name);

			std::cout << "Wiadomosc zostala odszyfrowana i zapisana w pliku o nazwie " << name << std::endl;
		}
		std::cout << "\nWybierz kolejne dzialanie: " << std::flush;
		std::cin >> decision;
	}
	std::cout << "\nDziekuje za skorzystanie z programu!" << std::endl;
}
