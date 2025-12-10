#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);

int main() {
	vector<string> heroicDeeds;
	vector<string> serviceBranches;
	int choice;

	// Display program banner
	displayBanner();

	do {
		// Main menu
		cout << "\n=== MAIN MENU ===\n";
		cout << "1. Add a veteran's heroic deed\n";
		cout << "2. Display all heroic deeds\n";
		cout << "3. Show tribute statistics\n";
		cout << "4. Create patriotic pattern\n";
		cout << "5. Search deeds by branch\n";
		cout << "6. Exit\n";
		cout << "Choose an option (1-6): ";
		cin >> choice;
		cin.ignore();  // clear newline

		switch(choice) {
		case 1:
			// TODO: Implement addHeroicDeed()
			addHeroicDeed(heroicDeeds, serviceBranches);
			break;
		case 2:
			// TODO: Implement displayDeeds()
			displayDeeds(heroicDeeds, serviceBranches);
			break;
		case 3:
			// TODO: Implement displayStatistics()
			displayStatistics(heroicDeeds, serviceBranches);
			break;
		case 4:
			// TODO: Implement createPatrioticPattern()
			createPatrioticPattern();
			break;
		case 5:
			// TODO: Implement searchByBranch()
			searchByBranch(heroicDeeds, serviceBranches);
			break;
		case 6:
			cout << "Thank you for honoring our veterans!\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while(choice != 6);

	return 0;
}

// TODO: Implement the displayBanner() function
void displayBanner() {
	cout << "========================================\n";
	cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
	cout << "========================================\n";
	cout << "   Honoring Those Who Served Our Nation\n";
	cout << "========================================\n\n";
}

// TODO: Implement addHeroicDeed() function
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
	string branch, deed;
	cout << "Please enter branch od service: ";
	getline(cin, branch);
	cout << "Describe the deed: ";
	getline(cin, deed);
	deeds.push_back(deed);
	branches.push_back(branch);
	cout << "Imput Succesful" << endl;
	// Steps:
	// 1. Ask user to enter branch
	// 2. Ask user to describe heroic deed
	// 3. Store data in vectors
}

// TODO: Implement displayDeeds() function
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
	if (deeds.empty()) {
		cout << "no deeds have been logged yet" << endl;
		return;
	}
	cout << "RECORDED DEEDS \n";
	for (int i=0; i < deeds.size(); i++) {
		cout << i + 1 << " " << branches[i] << " " << deeds[i] << endl;
	}
	// Steps:
	// 1. Check if vectors are empty
	// 2. Loop through vectors and print deeds with branch
}

// TODO: Implement displayStatistics() function
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
	if (deeds.empty()) {
		cout << "No stats logged" << endl;
		return;
	}
	int Army = 0;
	int Navy = 0;
	int Airforce = 0;
	int Marines = 0;
	int Coastguard = 0;

	for(string B : branches) {
		if (B == "Army") Army++;
		else if (B == "Navy") Navy++;
		else if (B == "Airforce") Airforce++;
		else if (B == "Marines") Marines++;
		else if (B == "Coastgaurd") Coastguard++;
	}
	cout << "\nSTATS\n";
	cout << "Total deeds logged: " << deeds.size() << "\n";
	cout << "Army: " << Army << "\n";
	cout << "Navy: " << Navy << "\n";
	cout << "Airforce: " << Airforce << "\n";
	cout << "Marines: " << Marines << "\n";
	cout << "Coastgaurd: " << Coastguard << "\n";
	// Steps:
	// 1. Count total deeds
	// 2. Count deeds by branch
	// 3. Display results
}

// TODO: Implement createPatrioticPattern() function
void createPatrioticPattern() {
	int rows;
	cout << "please enter number of rows ;): ";
	cin >> rows;
	cin.ignore();

	for (int i = 1; i <= rows; i++) {
		for(int j = 1; j <= i; j++) {
			if (i % 3 == 1) {
				cout << "b ";
			}
			else if (i % 3 == 2) {
				cout << "b2 ";
			}
			else {
				cout << "b ";
			}



		}
		cout << "\n";
	}
	// Steps:
	// 1. Ask user for number of rows
	// 2. Use loops to print a pattern (b, b, b2)
}

// TODO: Implement searchByBranch() function
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
	string searchbranch;
	cout << "enter a branch: ";
	getline(cin, searchbranch);

	bool found = false;

	cout << "Results: \n" << searchbranch << endl;
	for (int i = 0; i < branches.size(); i++) {
		if (branches[i] == searchbranch) {
			cout << "- " << deeds[i] << endl;
			found = true;
		}
	}
	// Steps:
	// 1. Ask user for branch to search
	// 2. Loop through branches vector and display matching deeds
}