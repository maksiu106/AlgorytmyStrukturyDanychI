#include <iostream>
#include <vector>
#include <math.h>

#include "ArrayQueue.hpp"

//funkcja wykonująca sortowanie pozycyjne wektora v
void radix(std::vector<int>& v)
{
	Queue kolejka[10]; //tworzymy tablicę 10 kolejek

	for (int n=0; n<10; n++) //główna pętla - bada n-tą cyfrę i na tej podstawie dorzuca do odpowiedniej kolejki
	{
		for (const auto& i : v) //przebiega po elementach w wektorze
		{
			int x = (int)(i/pow(10, n))%10; //sprawdzanie aktualnie badanej cyfry dziesiętnej - od ostatniej
			kolejka[x].push(i); //dodawanie elementu wektora do odpowiedniej kolejki
		}

		v.clear(); //czyszczenie wektora

		for (int i=0; i<10; i++) //wrzucanie do wektora liczb już posortowanych wg n-tego znaku
		{
			while (kolejka[i].empty()!=1) //każda z kolejek zostaje po kolei w pełni wypisana i wrzucona do wektora
			{
				v.push_back(kolejka[i].pop());
			}
		}
	}
}

int main()
{
	std::vector<int> v;
	int arg;

	while (std::cin >> arg)
	{
		v.push_back(arg); //wczytywanie argumentów do wektora
	}

	radix(v); //sortowanie pozycyjne

	for (const auto& i : v) std::cout << i << std::endl; //wypisanie wektora
}
