// Elevator Problem

#include <iostream>
using namespace std;

int main() {
    int people;
    double weight;

    cout << "Enter the number of people: ";
    cin >> people;

    cout << "Enter the total weight: ";
    cin >> weight;

    if (people <= 8 && weight <= 600) {
        cout << "Elevator can start." << endl;
    }
    else if (people > 8) {
        cout << "Too many people." << endl;
    }
    else {
        cout << "Weight limit exceeded." << endl;
    }

    return 0;
}

/*

// Elevator Problem

#include <iostream>
using namespace std;

int main() {
    int people;
    double weight;

    cout << "Enter the number of people: ";
    cin >> people;

    cout << "Enter the total weight: ";
    cin >> weight;

    if people < 8 && weight < 600 {
        cout << "Elevator can start." << endl;
    }
    else (people > 8 || weight > 600) {
        cout << "Too many people." << endl;
    }
    else{
        cout << "Weight limit exceeded." << endl;
    }

    return 0;
}

*/