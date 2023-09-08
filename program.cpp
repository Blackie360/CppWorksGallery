#include "terminal_user_input.h" // terminal_user_input.cpp
#include <iostream>

int main() {
    std::cout << "Enter your name: ";
    std::string name = read_string();
    std::cout << "Hello, " << name << "!" << std::endl;

    std::cout << "Enter an integer: ";
    int num = read_integer();
    std::cout << "You entered: " << num << std::endl;

    std::cout << "Enter a double: ";
    double value = read_double();
    std::cout << "You entered: " << value << std::endl;

    return 0;
}
