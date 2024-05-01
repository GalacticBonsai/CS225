#include <iostream>
#include <string>

// Created a function to make exiting on invalid input easier.
int process_number(std::string number_name)
{
	// Bounds check to prevent referencing invalid memory.
	if (number_name.length() < 7)
	{
		std::cout << "Phone number is not long enough" << std::endl;
		return 1;
	}

	// Only loop for 7 numbers.
	for (int i = 0; i <= 7; i++)
	{
		switch (std::tolower(number_name[i]))
		{
		case 'a':
		case 'b':
		case 'c':
			std::cout << 2;
			break;
		case 'd':
		case 'e':
		case 'f':
			std::cout << 3;
			break;
		case 'g':
		case 'h':
		case 'i':
			std::cout << 4;
			break;
		case 'j':
		case 'k':
		case 'l':
			std::cout << 5;
			break;
		case 'm':
		case 'n':
		case 'o':
			std::cout << 6;
			break;
		case 'p':
		case 'q':
		case 'r':
		case 's':
			std::cout << 7;
			break;
		case 't':
		case 'u':
		case 'v':
			std::cout << 8;
			break;
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			std::cout << 9;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			std::cout << number_name[i];
		case ' ':
			break;
		default:
			std::cout << "invalid input" << std::endl;
			return 1;
		}

		// Insert hyphen after 3rd print. Using 2 because arrays start at 0.
		if (i == 2) {
			std::cout << "-";
		}
	}
	std::cout << std::endl;

	// Alls well that ends well, no errors, return 0.
	return 0;
}

int main(int argc, char** argv) {
  
	// Interactive program requires a loop. Alt+F4 is a common application ender.
	while (1) {
		std::string input;
		std::cout << "Enter a phase to convert to a telephone number.\n Press Alt+F4 to end..." << std::endl;
		getline(std::cin, input);

		// Don't check output because we want to always loop.
		process_number(input);
	}
  return 0;
}