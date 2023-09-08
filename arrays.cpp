#include <iostream>
#include <string>
using namespace std;

// Input validation functions
string read_string() {
    string input;
    getline(cin, input);
    return input;
}

int read_integer() {
    int input;
    cin >> input;
    return input;
}

double read_double() {
    double input;
    cin >> input;
    return input;
}

// Function to find the index of a given name in the array
int index_of(string value, string data[], int size) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1; // Return -1 if not found
}

// Procedure to print summary information
void print_summary(string data[], int size, string search_name) {
    cout << "List of Names:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << data[i] << endl;
    }

    // Calculate total length and shortest name
    int total_length = 0;
    string shortest_name = data[0];
    for (int i = 0; i < size; ++i) {
        total_length += data[i].length();
        if (data[i].length() < shortest_name.length()) {
            shortest_name = data[i];
        }
    }
    
    cout << "Total length of all names: " << total_length << endl;
    cout << "Shortest name: " << shortest_name << endl;

    // Search for a given name
    int index = index_of(search_name, data, size);
    if (index != -1) {
        cout << "The name " << search_name << " is in the list at index " << index << endl;
    } else {
        cout << "The name " << search_name << " is not in the list." << endl;
    }
}

int main() {
    const int size = 5;
    string names[size] = {"Alice", "Bob", "Charlie", "David", "Emily"};
    
    string search_name;
    cout << "Enter a name to search for: ";
    search_name = read_string();

    // Call the print_summary procedure
    print_summary(names, size, search_name);

    return 0;
}
