// Write a program in C++ to use map associative container. The keys will be the names of
// states and the values will be the populations of the states. When the program runs, the
// user is prompted to type the name of a state. The program then looks in the map,
// using the state name as an index and returns the population of the state.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names as keys and their populations as values
    map<string, int> statePopulations;

    // Insert some state-population pairs
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 29145505;
    statePopulations["Florida"] = 21538187;
    statePopulations["New York"] = 20201249;
    statePopulations["Illinois"] = 12812508;

    string stateName;

    // Prompt the user for a state name
    cout << "Enter the name of a state: ";
    getline(cin, stateName);

    // Look up the state in the map
    auto it = statePopulations.find(stateName);

    if (it != statePopulations.end()) {
        // State found, print the population
        cout << "The population of " << stateName << " is " << it->second << ".\n";
    } else {
        // State not found
        cout << "State not found in the database.\n";
    }

    return 0;
}



