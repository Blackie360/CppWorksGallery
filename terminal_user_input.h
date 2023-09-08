// terminal_user_input.h

#ifndef TERMINAL_USER_INPUT_H
#define TERMINAL_USER_INPUT_H

#include <string>

std::string read_string();
int read_integer();
double read_double();
double read_double_range(double min, double max);
bool read_boolean();

#endif // TERMINAL_USER_INPUT_H
