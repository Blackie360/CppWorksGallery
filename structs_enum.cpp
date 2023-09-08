#include <iostream>
#include <string>

// Knight data structure
struct KnightData {
    std::string name;
    int age;
    std::string quest;
    std::string weapon;
};

// Knight update options enumeration
enum KnightUpdateOption {
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_QUEST,
    UPDATE_WEAPON,
    UPDATE_BOTH,
    DISPLAY_INFO,
    QUIT_UPDATE
};

// Function to read knight data from the terminal
KnightData readKnight() {
    KnightData knight;
    std::cout << "Enter knight's name: ";
    std::getline(std::cin, knight.name);
    std::cout << "Enter knight's age: ";
    std::cin >> knight.age;
    std::cin.ignore(); // Ignore newline character in buffer
    std::cout << "Enter knight's quest: ";
    std::getline(std::cin, knight.quest);
    std::cout << "Enter knight's weapon: ";
    std::getline(std::cin, knight.weapon);
    return knight;
}

// function to write knight data to the terminal
void writeKnight(const KnightData& knight) {
    std::cout << "Knight's name: " << knight.name << std::endl;
    std::cout << "Knight's age: " << knight.age << std::endl;
    std::cout << "Knight's quest: " << knight.quest << std::endl;
    std::cout << "Knight's weapon: " << knight.weapon << std::endl;
}

// function to update knight data
void updateKnight(KnightData& knight) {
    KnightUpdateOption option;
    do {
        std::cout << "Choose an option to update knight's data:" << std::endl;
        std::cout << "1. Update name" << std::endl;
        std::cout << "2. Update age" << std::endl;
        std::cout << "3. Update quest" << std::endl;
        std::cout << "4. Update weapon" << std::endl;
        std::cout << "5. Update both name and age" << std::endl;
        std::cout << "6. Display entered information" << std::endl;
        std::cout << "7. Quit updating" << std::endl;
        std::cout << "Enter option: ";
        int choice;
        std::cin >> choice;
        option = static_cast<KnightUpdateOption>(choice - 1);
        std::cin.ignore(); // Ignore newline character in buffer

        switch (option) {
            case UPDATE_NAME:
                std::cout << "Enter new name: ";
                std::getline(std::cin, knight.name);
                break;
            case UPDATE_AGE:
                std::cout << "Enter new age: ";
                std::cin >> knight.age;
                std::cin.ignore(); // Ignore newline character in buffer
                break;
            case UPDATE_QUEST:
                std::cout << "Enter new quest: ";
                std::getline(std::cin, knight.quest);
                break;
            case UPDATE_WEAPON:
                std::cout << "Enter new weapon: ";
                std::getline(std::cin, knight.weapon);
                break;
            case UPDATE_BOTH:
                std::cout << "Enter new name: ";
                std::getline(std::cin, knight.name);
                std::cout << "Enter new age: ";
                std::cin >> knight.age;
                std::cin.ignore(); // Ignore newline character in buffer
                std::cout << "Enter new quest: ";
                std::getline(std::cin, knight.quest);
                std::cout << "Enter new weapon: ";
                std::getline(std::cin, knight.weapon);
                break;
            case DISPLAY_INFO:
                writeKnight(knight);
                break;
            case QUIT_UPDATE:
                break;
            default:
                std::cout << "Invalid option. Please choose a valid option." << std::endl;
        }
    } while (option != QUIT_UPDATE);
}

int main() {
    KnightData knight;

    // Read knight data
    knight = readKnight();

    // Write knight data
    std::cout << "\nKnight's data:" << std::endl;
    writeKnight(knight);

    // Update knight data
    updateKnight(knight);

    // Write updated knight data
    std::cout << "\nUpdated knight's data:" << std::endl;
    writeKnight(knight);

    return 0;
}
