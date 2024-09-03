#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>

std::string generator()
{
	int number = random()%6;
	std::string command;
	switch (number)
	{
	case 0: {command = "F " + std::to_string(random()%1001); break;}
	case 1: {command = "B " + std::to_string(random()%1001); break;}
	case 2: {command = "f"; break;}
	case 3: {command = "b"; break;}
	case 4:	{command = "R " + std::to_string(random()%1001) + " " + std::to_string(random()%1001); break;}
	case 5: {command = "S"; break;}
	}
	return command;
}

int main(int argc, char *argv[])
{
	if (argc < 2) std::cerr << "Too few main function arguments" << std::endl;
	int amount = std::stoi(argv[1]);
	srand(time(NULL));

	for (int i=0; i<amount; ++i)
	{
		std::cout << generator() << std::endl;
	}
}
