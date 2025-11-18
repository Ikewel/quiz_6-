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
		cout << "5. Exit\n";
		cout << "Choose an option (1-5): ";
		cin >> choice;
		cin.ignore(); // clear newline

		switch(choice) {
		case 1:
			addVeteran(veterans);
			break;
		case 2:
			displayVeterans(veterans);
			break;
		case 3:
			searchByMedal(veterans);
			break;
		case 4:
			medalStatistics(veterans);
			break;
		case 5:
			cout << "Thank you for honoring our veterans!\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while(choice != 7);

	return 0;
}
void displayBanner() {
	cout << "VETERANS MEDAL OF HONOR TRACKER" << "\n";
	cout << "Honoring our veterans who served our nation" << endl;
}
// TODO: Implement displayBanner()
// Hint: Print program title and Veterans Day tribute

// TODO: Implement addVeteran()
// Hint: Ask for veteran's name, age, number of medals, and names of each medal
// Ensure duplicate medals are NOT allowed
void addVeteran(vector<Veteran>& veterans) {
	Veteran v;
	cout << "Please enter a veterans name: ";
	getline(cin, v.name);
	cin.ignore();

	cout << "Please enter age: ";
	cin >> v.age;
	cin.ignore();

	int nummedals;
	cout << "Number of medals in possession: ";
	cin >> nummedals;
	cin.ignore();

	for (int i = 0; i < nummedals; i++) {
		string medal;
		cout << "Please enter medal name: " << " ";
		getline(cin, medal);

		bool duplicate = false;
		for (const string& m : v.medals) {
			if (m == medal) {
				cout << "this was already logged";
				duplicate = true;
				break;
			}
		}
		if (!duplicate) {
			v.medals.push_back(medal);
		}
		veterans.push_back(v);
		cout << "successfully logged" << endl;
	}
}

// TODO: Implement displayVeterans()
// Hint: Loop through the vector and print each veteran's name, age, and medals
void displayVeterans(const vector<Veteran>& veterans) {
	for (int i = 0; i < veterans.size(); ++i) {
		const Veteran& v = veterans[i];
		cout << i + 1 << " name: " << v.name << "\n";
		cout << " age: " << v.age << "\n";
		cout << " medals: " << endl;
		if (v.medals.empty()) {
			cout << "none logged";
		}
		else {
			for (int j = 0; j < v.medals.size(); ++j) {
				cout << v.medals[j];
				if (j + 1 < v.medals.size()) {
					cout << ", ";
				}
			}
		}
		cout << "\n";
	}
}

// TODO: Implement searchByMedal()
// Hint: Ask user for a medal and display all veterans who have it
void searchByMedal(const vector<Veteran>& veterans) {
	string medalsearch;
	cout << "enter medal name: ";
	getline(cin, medalsearch);

	bool foundany = false;
	cout << "vets who have the medal" << medalsearch << endl;
	for (const Veteran& v : veterans) {
		bool hasmedal = false;
		for (const string& m : v.medals) {
			if (m == medalsearch) {
				hasmedal = true;
				break;
			}
		}
		if (hasmedal) {
			cout << " " << v.name << "(age " << v.age << ")" << endl;
			foundany = true;
		}
	}
	if (!foundany) {
		cout << "nothing here sorry" << endl;
	}
}
void medalStatistics(const vector<Veteran>& veterans) {
	vector<string> medalnames;
	vector<int> medalcounts;
	for (const Veteran& v : veterans) {
		for (const string& medal : v.medals) {
			bool found = false;
			int index = -1;

			for (int i = 0; i < medalnames.size(); i++) {
				if (medalnames[i] == medal) {
					found = true;
					index = i;
					break;
				}
			}
			if (found) {
				medalcounts[index]++;
			}
			else {
				medalnames.push_back(medal);
				medalcounts.push_back(1);
			}
		}
	}
	cout << "Medal stats" << "\n";
	cout << "total vets: " << veterans.size() << "\n";
	cout << "awarded medals: " << endl;
	for(int i = 0; i < medalnames.size(); i++) {
		cout << " " << medalnames[i] << " " << medalcounts[i] << endl;
	}
}
// TODO: Implement medalStatistics()
// Hint: Count how many times each medal has been awarded and display


