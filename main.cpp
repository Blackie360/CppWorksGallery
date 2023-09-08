#include "terminal_user_input.h"
#include <iostream>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    name = read_string();
    std::cout << "Hello, " << name << "!" << std::endl;

    int age;
    std::cout << "Enter your age: ";
    age = read_integer();
    std::cout << "You are " << age << " years old." << std::endl;

    double height;
    std::cout << "Enter your height (in cm): ";
    height = read_double_range(0.0, 300.0);
    std::cout << "Your height is " << height << " cm." << std::endl;

    bool likes_pizza;
    std::cout << "Do you like pizza? (yes/no): ";
    likes_pizza = read_boolean();
    if (likes_pizza) {
        std::cout << "You like pizza!" << std::endl;
    } else {
        std::cout << "You don't like pizza." << std::endl;
    }

    return 0;
}
