// Implement a class Complex which represents the Complex Number data 
// type. Implement the following operations:
// 1. Constructor (including a default constructor which creates the complex number 
// 0+0i).
// 2. Overloaded operator+ to add two complex numbers.
// 3. Overloaded operator* to multiply two complex numbers.
// 4. Overloaded << and >> to print and read Complex Numbers.

#include <iostream>
#include <string>
using namespace std;

class complex {
    int r; // Real part
    int i; // Imaginary part

public:
    // Constructor
    complex() {
        r = 0;
        i = 0;
    }

    // Overload >> to read a complex number
    friend istream& operator>>(istream &in, complex &c) {
        cout << "Enter real and imaginary part: ";
        in >> c.r >> c.i;
        return in;
    }

    // Overload << to print a complex number
    friend ostream& operator<<(ostream &out, const complex &c) {
        out << c.r;
        if (c.i >= 0) {
            out << "+" << c.i << "i";
        } else {
            out << c.i << "i";
        }
        return out;
    }

    // Overload + to add two complex numbers
    complex operator+(const complex &c2) {
        complex c3;
        c3.r = r + c2.r;
        c3.i = i + c2.i;
        return c3;
    }

    // Overload * to multiply two complex numbers
    complex operator*(const complex &c2) {
        complex c3;
        c3.r = (r * c2.r) - (i * c2.i);
        c3.i = (r * c2.i) + (i * c2.r);
        return c3;
    }
};

int main() {
    complex c1, c2;
    
    cout << "Enter first complex number: " << endl;
    cin >> c1;
    
    cout << "Enter second complex number: " << endl;
    cin >> c2;

    cout << "First complex number is: " << c1 << endl;
    cout << "Second complex number is: " << c2 << endl;

    cout << "Addition of two given complex numbers is: " << c1 + c2 << endl;
    cout << "Multiplication of two given complex numbers is: " << c1 * c2 << endl;

    return 0;
}
