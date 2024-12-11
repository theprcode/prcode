// // Write a C++ program that creates an output file, writes information to it, 
// closes the file and open it again as an input file and read the information from 
// the file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

//Creating and writing in file
    ofstream outFile("Data.txt");
    if(!outFile){
        cout<<"Error: Could not create a file";
        return 1;
    }
    outFile<<"Hello, My name is therampatil";
    outFile.close();
    cout<<"Data written succesfully"<<endl;


//Reading the file
    ifstream inFile("Data.txt");
    if (!inFile) {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    string line;
    cout<<"Reading the data from the file ::"<<endl;
    while(getline(inFile,line)){
        cout<<line<<endl;
    }
    inFile.close();
    return 0;
}


