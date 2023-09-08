// terminal_user_input.cpp

#include "terminal_user_input.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <algorithm>

std::string read_string() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int read_integer() {
    int input;
    std::cin >> input;
    return input;
}

double read_double() {
    double input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number: ";
    }
    return input;
}

double read_double_range(double min, double max) {
    double input;
    do {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        input = read_double();

        if (input < min || input > max) {
            std::cout << "Input must be between " << min << " and " << max << ". Try again." << std::endl;
        }
    } while (input < min || input > max);
    return input;
}

bool read_boolean() {
    std::string input;
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return (input == "yes" || input == "y");
}
