#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Knight data structure
struct KnightData {
    vector<string> names;
    vector<int> ages;
    vector<string> quests;
    vector<string> weapons;
};

// Knight update options enumeration
enum KnightUpdateOption {
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_QUEST,
    UPDATE_WEAPON,
    UPDATE_BOTH,
    DISPLAY_INFO,
    PRINT_REVERSE, // Added option to print names in reverse
    QUIT_UPDATE
};

// Function to read an integer from the terminal
int readInteger() {
    int value;
    cin >> value;
    cin.ignore(); 
    return value;
}

// Function to read knight data from the terminal
void readKnight(KnightData& knight) {
    cout << "Enter the number of knights: ";
    int numKnights = readInteger();

    for (int i = 0; i < numKnights; ++i) {
        cout << "Enter knight " << i + 1 << "'s name: ";
        string name;
        getline(cin, name);
        knight.names.push_back(name);

        cout << "Enter knight " << i + 1 << "'s age: ";
        int age = readInteger();
        knight.ages.push_back(age);

        cout << "Enter knight " << i + 1 << "'s quest: ";
        string quest;
        getline(cin, quest);
        knight.quests.push_back(quest);

        cout << "Enter knight " << i + 1 << "'s weapon: ";
        string weapon;
        getline(cin, weapon);
        knight.weapons.push_back(weapon);
    }
}

// Function to write knight data to the terminal
void writeKnight(const KnightData& knight) {
    for (size_t i = 0; i < knight.names.size(); ++i) {
        cout << "Knight " << i + 1 << " data:" << endl;
        cout << "Name: " << knight.names[i] << endl;
        cout << "Age: " << knight.ages[i] << endl;
        cout << "Quest: " << knight.quests[i] << endl;
        cout << "Weapon: " << knight.weapons[i] << endl;
    }
}

// Function to print names in reverse order
void print_reverse(const KnightData& knight) {
    cout << "Knight names in reverse order:" << endl;
    for (int i = knight.names.size() - 1; i >= 0; --i) {
        cout << knight.names[i] << endl;
    }
}

// Function to update knight data
void updateKnight(KnightData& knight) {
    KnightUpdateOption option;
    int index; // Added index variable to update specific knight data

    do {
        cout << "Choose an option to update knight's data:" << endl;
        cout << "1. Update name" << endl;
        cout << "2. Update age" << endl;
        cout << "3. Update quest" << endl;
        cout << "4. Update weapon" << endl;
        cout << "5. Update both name and age" << endl;
        cout << "6. Display entered information" << endl;
        cout << "7. Print names in reverse order" << endl; // Added option to print names in reverse
        cout << "8. Quit updating" << endl;
        cout << "Enter option: ";
        int choice = readInteger();
        option = static_cast<KnightUpdateOption>(choice - 1);

        switch (option) {
            case UPDATE_NAME:
                cout << "Enter the knight's index to update name: ";
                index = readInteger();
                if (index >= 1 && index <= static_cast<int>(knight.names.size())) {
                    cout << "Enter new name: ";
                    getline(cin, knight.names[index - 1]);
                } else {
                    cout << "Invalid knight index. Please choose a valid index." << endl;
                }
                break;
            case UPDATE_AGE:
                cout << "Enter the knight's index to update age: ";
                index = readInteger();
                if (index >= 1 && index <= static_cast<int>(knight.ages.size())) {
                    cout << "Enter new age: ";
                    knight.ages[index - 1] = readInteger();
                } else {
                    cout << "Invalid knight index. Please choose a valid index." << endl;
                }
                break;
            case UPDATE_QUEST:
                cout << "Enter the knight's index to update quest: ";
                index = readInteger();
                if (index >= 1 && index <= static_cast<int>(knight.quests.size())) {
                    cout << "Enter new quest: ";
                    getline(cin, knight.quests[index - 1]);
                } else {
                    cout << "Invalid knight index. Please choose a valid index." << endl;
                }
                break;
            case UPDATE_WEAPON:
                cout << "Enter the knight's index to update weapon: ";
                index = readInteger();
                if (index >= 1 && index <= static_cast<int>(knight.weapons.size())) {
                    cout << "Enter new weapon: ";
                    getline(cin, knight.weapons[index - 1]);
                } else {
                    cout << "Invalid knight index. Please choose a valid index." << endl;
                }
                break;
            case UPDATE_BOTH:
                cout << "Enter the knight's index to update both name and age: ";
                index = readInteger();
                if (index >= 1 && index <= static_cast<int>(knight.names.size())) {
                    cout << "Enter new name: ";
                    getline(cin, knight.names[index - 1]);
                    cout << "Enter new age: ";
                    knight.ages[index - 1] = readInteger();
                } else {
                    cout << "Invalid knight index. Please choose a valid index." << endl;
                }
                break;
            case DISPLAY_INFO:
                writeKnight(knight);
                break;
            case PRINT_REVERSE: // Added case to print names in reverse order
                print_reverse(knight);
                break;
            case QUIT_UPDATE:
                break;
            default:
                cout << "Invalid option. Please choose a valid option." << endl;
        }
    } while (option != QUIT_UPDATE);
}

int main() {
    KnightData knight;

    // Read knight data
    readKnight(knight);

    // Write knight data
    cout << "\nKnight's data:" << endl;
    writeKnight(knight);

    // Update knight data
    updateKnight(knight);

    // Write updated knight data
    cout << "\nUpdated knight's data:" << endl;
    writeKnight(knight);

    return 0;
}
