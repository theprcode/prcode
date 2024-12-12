// Aim: Write C++ program using STL for sorting and searching user 
//defined records such as personal records (Name, DOB, Telephone number etc) using vector container. 


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct record{
	string Name,DOB,Telephone;
	//< operator for sorting
	bool operator<(const record &other) const {
		return Name < other.Name ;
		}
};

int main(){

	//define vector container
	vector<record>records;
	int n;
	cout<<"Enter the number of records :: ";
	cin>>n;

	//Take input from user
	for(int i=0;i<n;i++){
		record temp;
		cout<<"Enter name, DOB,telephone number of person :: ";
		cin>>ws;
		getline(cin,temp.Name);
		getline(cin,temp.DOB);
		getline(cin,temp.Telephone);
		records.push_back(temp);
	}

	//sort records
	sort(records.begin(),records.end());
	for (const auto &r:records)
		cout<<r.Name<<" "<<r.DOB<<" "<<r.Telephone<<endl;

	//Search Records
	string SearchName;
	cout<<"Enter the name to search :: ";
	cin>>ws;
	getline(cin,SearchName);
	
	auto it=lower_bound(records.begin(),records.end(),record{SearchName," "," "});
	if (it != records.end() && it->Name == SearchName)
        cout << "Found: " << it->Name << " " << it->DOB << " " << it->Telephone << endl;
    else
        cout << "Not found." << endl;
	
	return 0;
}
