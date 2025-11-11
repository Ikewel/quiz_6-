#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure for veteran information
struct Veteran {
    string name;
    int age;
    vector<string> medals; // Each veteran can have multiple medals
};

// Function prototypes
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
void removeVeteran(vector<Veteran>& veterans);
void sortVeteransByAge(vector<Veteran>& veterans);

int main() {
    vector<Veteran> veterans;
    int choice;

    displayBanner();

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran and their medals\n";
        cout << "2. Display all veterans and medals\n";
        cout << "3. Search veterans by medal\n";
        cout << "4. Show medal statistics\n";
        cout << "5. Remove a veteran by name\n";
        cout << "6. Sort veterans by age\n";
        cout << "7. Exit\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: addVeteran(veterans); break;
            case 2: displayVeterans(veterans); break;
            case 3: searchByMedal(veterans); break;
            case 4: medalStatistics(veterans); break;
            case 5: removeVeteran(veterans); break;
            case 6: sortVeteransByAge(veterans); break;
            case 7: cout << "Thank you for honoring our veterans!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 7);

    return 0;
}

// TODO: Implement displayBanner()
// Hint: Print program title and Veterans Day tribute

// TODO: Implement addVeteran()
// Hint: Ask for veteran's name, age, number of medals, and names of each medal
// Ensure duplicate medals are NOT allowed

// TODO: Implement displayVeterans()
// Hint: Loop through the vector and print each veteran's name, age, and medals

// TODO: Implement searchByMedal()
// Hint: Ask user for a medal and display all veterans who have it

// TODO: Implement medalStatistics()
// Hint: Count how many times each medal has been awarded and display

// TODO: Implement removeVeteran()
// Hint: Ask user for veteran's name and remove from the vector if found

// TODO: Implement sortVeteransByAge()
// Hint: Sort the vector of veterans in ascending order of age using a lambda or function
