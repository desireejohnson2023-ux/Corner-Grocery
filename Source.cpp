#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

    bool OpenFile(ifstream& inFS) {
        inFS.open("CS210_Project_Three_Input_File.txt");

        if (!inFS.is_open()) {
            inFS.open("Debug/CS210_Project_Three_Input_File.txt");
        }

        if (!inFS.is_open()) {
            inFS.open("../CS210_Project_Three_Input_File.txt");
        }

        return inFS.is_open();
    }

    string ToLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    GroceryTracker() {
        LoadDataFromFile();
        BackupDataToFile();
    }

    void LoadDataFromFile() {
        ifstream inFS;
        string item;

        if (!OpenFile(inFS)) {
            cout << "ERROR: Could not open input file.\n";
            cout << "Make sure 'CS210_Project_Three_Input_File.txt' exists.\n";
            exit(1);
        }

        while (getline(inFS, item)) {
            if (!item.empty()) {
                item = ToLower(item);
                itemFrequency[item]++;
            }
        }

        inFS.close();
    }

    void BackupDataToFile() {
        ofstream outFS("frequency.dat");

        for (auto& pair : itemFrequency) {
            outFS << setw(15) << left << pair.first
                << pair.second << endl;
        }

        outFS.close();
    }

    void GetItemFrequency() {
        string item;
        cout << "Enter item to search: ";
        getline(cin, item);

        item = ToLower(item);

        if (itemFrequency.count(item)) {
            cout << item << " was purchased "
                << itemFrequency[item] << " times.\n";
        }
        else {
            cout << item << " was not found.\n";
        }
    }

    void PrintAllFrequencies() {
        for (auto& pair : itemFrequency) {
            cout << setw(15) << left << pair.first
                << pair.second << endl;
        }
    }

    void PrintHistogram() {
        size_t maxLength = 0;

        for (auto& pair : itemFrequency) {
            if (pair.first.length() > maxLength) {
                maxLength = pair.first.length();
            }
        }

        for (auto& pair : itemFrequency) {
            cout << setw(maxLength + 2) << left << pair.first;
            cout << string(pair.second, '*') << endl;
        }
    }
};

void DisplayMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Search for item frequency\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

void Pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int main() {
    GroceryTracker tracker;
    int choice = 0;
    string input;

    do {
        DisplayMenu();
        getline(cin, input);

        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            tracker.GetItemFrequency();
            Pause();
            break;
        case 2:
            tracker.PrintAllFrequencies();
            Pause();
            break;
        case 3:
            tracker.PrintHistogram();
            Pause();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}

