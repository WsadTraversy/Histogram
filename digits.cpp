#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include "digits.h"

void digits::load() {
	std::string loaded_values;
	char character;

	while (std::cin.get(character) && character != '$') {
		if (std::isdigit(character)) {
			loaded_values += character;
		}
		else if (character == '$') {
			break;
		}
		else {
			throw std::invalid_argument("received invalid character");
		}
	}

	stored_digits += loaded_values;
	menu_main();
}

void digits::change_values(std::string value) {
	stored_digits = value;
}

std::string digits::stored() const {
	return stored_digits;
}

void digits::menu_main() {
	system("clear");
	int switch_on;
	std::cout << "1. Draw histogram" << std::endl;
	std::cout << "2. Ammount of digits and median" << std::endl;
	std::cout << "3. Minimum and maximum" << std::endl;
	std::cout << "To end session press any key" << std::endl;
	std::cout << "Choose an option: ";
	std::cin >> switch_on;
	switch (switch_on)
	{
	case 1:
		system("clear");
		draw_histogram();
		menu_second();
		break;
	case 2:
		system("clear");
		std::cout << "Amount of digits: " << digits_ammount() << std::endl;
		std::cout << "Median: " << median_min_max(1) << std::endl;
		menu_second();
	case 3:
		system("clear");
		std::cout << "Minimum: " << median_min_max(2) << std::endl;
		std::cout << "Maximum: " << median_min_max(3) << std::endl;
		menu_second();
		break;
	default:
		break;
	}
}

void digits::menu_second() {
	int switch_on;
	std::cout << std::endl;
	std::cout << "1. Back to main menu" << std::endl;
	std::cout << "To end session press any key" << std::endl;
	std::cout << "Choose an option: ";
	std::cin >> switch_on;
	switch (switch_on)
	{
	case 1:
		menu_main();
		break;
	default:
		break;
	}
}

long int digits::digits_ammount() const {
	return stored().size();
}

int digits::median_min_max(int n) const {
	std::vector<int> data;
	for (long int i = 0; i < digits_ammount(); ++i) {
		data.push_back((int)stored()[i] - 48);
	}

	std::sort(data.begin(), data.end());
	if (n == 1) {
		if (data.size() % 2 == 0) {
			return data[data.size() / 2];
		}
		else {
			return (data[data.size() / 2 - 1] + data[data.size() / 2 + 1]) / 2;
		}
	}
	else if (n == 2) {
		return data[0];
	}
	else if (n == 3) {
		return data[data.size() - 1];
	}
	else {
		return 0;
	}
}

std::map<int, std::string> digits::prepare_values() {
	std::map<int, std::string> values;
	for (long int i = 0; i < digits_ammount(); ++i) {
		if (stored()[i] == '0')
			values[0] += "@";
		else if (stored()[i] == '1')
			values[1] += "@";
		else if (stored()[i] == '2')
			values[2] += "@";
		else if (stored()[i] == '3')
			values[3] += "@";
		else if (stored()[i] == '4')
			values[4] += "@";
		else if (stored()[i] == '5')
			values[5] += "@";
		else if (stored()[i] == '6')
			values[6] += "@";
		else if (stored()[i] == '7')
			values[7] += "@";
		else if (stored()[i] == '8')
			values[8] += "@";
		else if (stored()[i] == '9')
			values[9] += "@";
	}
	return values;
}

void digits::draw_histogram() {
	std::map<int, std::string> values = prepare_values();
	int ammount = 0;
	for (int i = 0; i < 10; ++i) {
		ammount = values[i].size();
		if (ammount < 20) {
			std::cout << i << ": " << values[i] << "  ";
			std::cout << std::endl;
		}
		else {
			std::cout << i << ": limit reached | " << ammount << std::endl;
		}
		ammount = 0;
	}
}