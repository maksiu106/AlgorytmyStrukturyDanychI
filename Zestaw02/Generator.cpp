#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>

//generator komend zgodnych z szablonem podanym w skrypcie
std::string generator()
{
	int number = random()%3;
	std::string command;
	switch (number)
	{
	case 0: {command = "A " + std::to_string(random()%10000); break;}
	case 1: {command = "D"; break;}
	case 2: {command = "S"; break;}
	}
	return command;
}

//ten program przyjmie na wejscie ilosc komend do programu "stack.x", ktora ma wygenerowac losowo
int main(int argc, char *argv[])
{
	if (argc < 2) std::cerr << "Too few main function arguments" << std::endl;
	int amount = std::stoi(argv[1]);
	srand(time(NULL));

	for (int i=0; i<amount; ++i)
	{
		std::cout << generator() << std::endl;
		usleep(1000);
	}
}
