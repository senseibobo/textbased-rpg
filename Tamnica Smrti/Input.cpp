#include "Input.h"

int Input::getIntInput(int min, int max) {
	int n;
	while (true) {
		std::cout << "Enter number: ";
		std::cin >> n;
		if (n < min or n > max) {
			std::cout << "Wrong input. Enter a number between " << min << " and " << max << "\n";
			continue;
		}
		break;
	}
	return n;
}