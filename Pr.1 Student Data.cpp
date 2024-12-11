//  1. Develop a program in C++ to create a database of student’s information system containing 
// the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact 
// address, Telephone number, Driving license no. and other. Construct the database with suitable
// member functions. Make use of constructor, default constructor, copy constructor, 
// destructor, static member functions, friend class, this pointer, inline code and dynamic
// memory allocation operators-new and delete as well as exception handling.

#include <iostream>
#include <string> //Including <string> in a C++ program provides access to the std::string class, which is part of the C++ Standard Library. 
using namespace std;

class Student {
    string name;
    int rollno;
    string Class;
    char div;
    string dob;
    string blood;
    string contactAddress;
    long int telephone;
    string driving;

public:
    static int count; //Keeping Track of Information .A static member function is a member function that belongs to the class rather than any specific object. It can be called without creating an object of the class.

    // Default Constructor
    Student() {
        Class = "SE";
        div = 'A';
        count++;
    }

    // Parameterized Constructor
    Student(string name, int rollno, string Class, char div, string dob, string blood,
            string contactAddress, long int telephone, string driving) {
        this->name = name;  //To resolve name conflicts between instance variables and parameters.
        this->rollno = rollno;
        this->Class = Class;
        this->div = div;
        this->dob = dob;
        this->blood = blood;
        this->contactAddress = contactAddress;
        this->telephone = telephone;
        this->driving = driving;
        count++;  
    }

    // Copy Constructor
    Student(const Student &s2) {
        name = s2.name;
        rollno = s2.rollno;
        Class = s2.Class;
        div = s2.div;
        dob = s2.dob;
        blood = s2.blood;
        contactAddress = s2.contactAddress;
        telephone = s2.telephone;
        driving = s2.driving;
        count++;
    }

    // Destructor
    ~Student() {
        cout << "\n\t Destructor invoked for student: " << name << endl;
        count--;
    }

    // Member Function to Input Data
    void getData() {
        try {
            cout << "\n\t Enter Name: ";
            cin >> name;
            cout << "\n\t Enter Roll Number: ";
            cin >> rollno;
            cout << "\n\t Enter Date of Birth (dd-mm-yyyy): ";
            cin >> dob;
            cout << "\n\t Enter Blood Group: ";
            cin >> blood;
            cout << "\n\t Enter Contact Address: ";
            cin >> contactAddress;
            cout << "\n\t Enter Telephone Number: ";
            cin >> telephone;
            if (telephone <= 0)
                throw invalid_argument("Invalid telephone number!");
            cout << "\n\t Enter Driving License No.: ";
            cin >> driving;
        } catch (const exception &e) {
            cerr << "\n\t Error: " << e.what() << endl; //: This method is part of the std::exception class, and it returns a descriptive string explaining the error.
        }
    }

    // Member Function to Display Data
    void display() const {
        cout << "\n\t Name: " << name
             << "\n\t Roll No.: " << rollno
             << "\n\t Class: " << Class
             << "\n\t Division: " << div
             << "\n\t Date of Birth: " << dob
             << "\n\t Blood Group: " << blood
             << "\n\t Contact Address: " << contactAddress
             << "\n\t Telephone Number: " << telephone
             << "\n\t Driving License No.: " << driving
             << "\n\t +++++++++++++++++++++++++++++++++++++++++++++";
    }

    // Static Function to Get Total Number of Students
    static int number() {
        return count;
    }

    // Friend Function to Compare Two Students
    friend void compareStudents(const Student &s1, const Student &s2);
};



// Initialize Static Member
int Student::count = 0;

// Friend Function Definition
void compareStudents(const Student &s1, const Student &s2) {
    if (s1.rollno == s2.rollno) {
        cout << "\n\t Both students have the same roll number." << endl;
    } else {
        cout << "\n\t Students have different roll numbers." << endl;
    }
}

int main() {
        // Dynamically allocate memory for students
        Student *s1 = new Student();
        s1->getData();
        s1->display();



        // Copy Constructor
        Student *s2 = new Student(*s1);
        cout << "\n\t Copy Constructor Invoked";
        s2->display();



        // Display Total Students
        cout << "\n\t Total Number of Students: " << Student::number() << endl;



        // Compare Students
        compareStudents(*s1, *s2);



        // Free allocated memory
        delete s1;
        delete s2;



        // Display Total Students After Deletion
        cout << "\n\t Total Number of Students After Deletion: " << Student::number() << endl;

    return 0;
}
