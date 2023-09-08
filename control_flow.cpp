#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string read_string(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

double read_double(string prompt) {
    double input;
    cout << prompt;
    cin >> input;
    cin.ignore(); // Consume the newline character
    return input;
}

int read_integer(string prompt) {
    int input;
    cout << prompt;
    cin >> input;
    cin.ignore(); // Consume the newline character
    return input;
}

bool login() {
    string username = read_string("Enter your username: ");
    string password = read_string("Enter your password: ");

    // Replace with actual username and password checks
    if (username == "Sheldon" && password == "Sheldon123") {
        return true;
    } else {
        return false;
    }
}

void custom_messages() {
    string names[] = {"Alice", "Bob", "Charlie", "John", "Eve"};
    
    string name = read_string("Enter a name: ");
    bool found = false;
    
    for (string n : names) {
        if (name == n) {
            found = true;
            if (name == "Alice") {
                cout << "Hello, Alice! You're a great friend." << endl;
            } else if (name == "Bob") {
                cout << "Hey, Bob! Thanks for being awesome." << endl;
            } else if (name == "Charlie") {
                cout << "Hi, Charlie! You're a fantastic teacher." << endl;
            } else {
                cout << "Hello, " << name << "! It's nice to know you." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "I don't have a special message for that name." << endl;
    }
}

void guess_the_number() {
    srand(time(0));
    
    int number_to_guess = rand() % 100 + 1;
    int attempts = 0;
    
    while (true) {
        int guess = read_integer("Guess a number between 1 and 100: ");
        attempts++;
        
        if (guess < number_to_guess) {
            cout << "Try higher." << endl;
        } else if (guess > number_to_guess) {
            cout << "Try lower." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << number_to_guess << " in " << attempts << " attempts." << endl;
            break;
        }
    }
}

void multiplication_table() {
    int number = read_integer("Enter a number for the multiplication table: ");
    int limit = read_integer("Enter the limit for the table: ");
    
    cout << "Multiplication table for " << number << " up to " << limit << ":" << endl;
    
    for (int i = 1; i <= limit; i++) {
        int result = number * i;
        cout << number << " * " << i << " = " << result << endl;
    }
}

int main() {
    if (!login()) {
        cout << "Invalid login. Exiting." << endl;
        return 0;
    }
    
    cout << "Login successful. Welcome!" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Custom Messages" << endl;
        cout << "2. Guess the Number" << endl;
        cout << "3. Multiplication Table" << endl;
        cout << "4. Quit" << endl;
        
        int choice = read_integer("Enter your choice: ");
        
        if (choice == 1) {
            custom_messages();
        } else if (choice == 2) {
            guess_the_number();
        } else if (choice == 3) {
            multiplication_table();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
