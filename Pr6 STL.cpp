// Aim: Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    string dob;
    string telephone;

    Person(string n, string d, string t) : name(n), dob(d), telephone(t) {}
};

bool compareByName(const Person &a, const Person &b) {
    return a.name < b.name;
}

void displayRecords(const vector<Person>& records) {
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Telephone: " << record.telephone << endl;
    }
}

int main() {
    vector<Person> records;
    int n;
    cout << "Enter number of records: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name, dob, telephone;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter DOB (DD-MM-YYYY): ";
        cin >> dob;
        cout << "Enter Telephone: ";
        cin >> telephone;
        records.push_back(Person(name, dob, telephone));
    }

    sort(records.begin(), records.end(), compareByName);
    
    cout << "\nSorted records by name:\n";
    displayRecords(records);

    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;
    auto it = find_if(records.begin(), records.end(), [&searchName](const Person& p) {
        return p.name == searchName;
    });

    if (it != records.end()) {
        cout << "Record found: Name: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephone << endl;
    } else {
        cout << "Record not found!" << endl;
    }

    return 0;
}
