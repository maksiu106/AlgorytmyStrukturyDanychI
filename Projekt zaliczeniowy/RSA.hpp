#ifndef RSA_HPP_
#define RSA_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#include "LinkedList.hpp"

class RSA {
public:
	static void generate_keys() {
		LinkedList<int> primes;
		for (int i = 20000; i<=50000; ++i) { //stworzenie wektora z liczbami pierwszymi z zakresu
			if (is_prime(i)) primes.push_back(i);
		}

		std::random_device rand;
		std::mt19937 generator(rand()); // Inicjalizacja generatora liczb losowych
		std::uniform_int_distribution<int> distribution(0, primes.size()-1); // Zakres

		//losowanie liczb p oraz q
		unsigned long p = primes.get(distribution(generator));
		unsigned long q = 0;
		do {
			q = primes.get(distribution(generator));
		} while (p == q);

		//generowanie modułu oraz tocjenta iloczynu liczb
		unsigned long long n = p*q;
		unsigned long long tocjent = (p-1)*(q-1);

		//szukanie liczby e
		std::uniform_int_distribution<unsigned long long> distribution2((tocjent/2), (3/4*tocjent));
		unsigned long long e = 65537;

		//szukanie liczby d
		unsigned long long d = reversed_modulo(e, tocjent);

		std::cout << "\nKlucz publiczny:\n\tPubliczny wykladnik e = " << e << "\n\tModul n = " << n << std::endl;
		std::cout << "Klucz prywatny:\n\tPrywatny wykladnik d = " << d << "\n\tModul n = " << n << std::endl;
	}

	static unsigned long long encrypt(unsigned long long input, int e, unsigned long long n) { //funkcja szyfrująca, a więc licząca potęgę modulo inputu
		unsigned long long result = 1;
		input = input%n;
		while (e > 0) {
			if (e % 2 == 1) result = (result*input)%n;
			e /= 2;
			input = (input * input)%n;
		}
		return result%n;
	}

	static unsigned long long decrypt(unsigned long long input, unsigned long long d, unsigned long long n) { //funkcja deszyfrująca
		unsigned long long result = 1;
		input = input%n;
		while (d > 0) {
			if (d % 2 == 1) result = (result*input)%n;
			d /= 2;
			input = (input*input) % n;
		}
		return result%n;
	}

private:
	static bool is_prime(int x) { //sprawdza, czy podana liczba jest pierwsza
		for (int i=2; i<=sqrt(x); ++i) {
			if (x%i == 0) return false;
		}
		return true;
	}

	static int nwd(unsigned long long a, unsigned long long b) { //liczy największy wspólny dzielnik dwóch liczb używając algorytmu Euklidesa
		unsigned long long temp;
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	static unsigned long long reversed_modulo(unsigned long long e, unsigned long long tocjent) {
		//funkcja liczy odwrotność modulo dla liczby e względem tocjenta za pomocą rozszerzonego algorytmu Euklidesa
		//w ten sposób, aby wyznaczyc liczbe x w rownaniu [ ex % (tocjent) = 1 ]

		long long y = 0; //wspolczynnik rozwiniecia przy tocjencie
		long long x = 1; //wspolczynnik rozwiniecia przy e
		long long temp; //zmienna tymczasowa
		long long last_e = tocjent;
		long long iloraz  = tocjent / e;
		long long reszta  = tocjent % e;

		while(reszta > 0) {
			temp = y - iloraz * x;

			if( temp >= 0 ) temp = temp%tocjent;
			else temp = tocjent - ((-temp)%tocjent);

			y = x;
			x = temp;
			last_e = e;
			e = reszta;

			iloraz  = last_e / e;
			reszta  = last_e % e;
		}

		return x;
	}
};

#endif
