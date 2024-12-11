// Write a function template for selection sort. Write a program that inputs, sorts and 
// outputs an integer array and a float array.

#include <iostream>
using namespace std;

class sorting {
    int N; // Number of elements

public:
    // Template function to get data
    template <typename T>
    void getdata(T arr[]) {
        cout << "Enter the number of inputs: ";
        cin >> N;

        cout << "Enter the numbers:\n";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    }

    // Template function to perform selection sort
    template <typename T>
    void selectionsort(T arr[]) {
        for (int i = 0; i < N - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Swap the minimum element with the current element
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
            }
        }
    }

    // Template function to display the sorted array
    template <typename T>
    void display(T arr[]) {
        cout << "Sorted elements: ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    sorting s1;

    // Sorting integer array
    cout << "For integer inputs:\n";
    int intArr[50];
    s1.getdata(intArr);
    s1.selectionsort(intArr);
    s1.display(intArr);

    // Sorting float array
    cout << "\nFor float inputs:\n";
    float floatArr[50];
    s1.getdata(floatArr);
    s1.selectionsort(floatArr);
    s1.display(floatArr);

    return 0;
}





