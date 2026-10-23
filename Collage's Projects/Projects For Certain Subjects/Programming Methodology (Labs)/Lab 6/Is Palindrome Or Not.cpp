#include <iostream>
using namespace std;

int main()
{
    // Unlike SecurityCode, ReversedCode's value won't be from the user.
    // Thats why it needs to have an initializing value.
    int SecurityCode, ReversedCode = 0; 

    cout << "Please enter the security code: ";
    cin >> SecurityCode;

    // that is a possible way. 
    int Temp = SecurityCode;
    while (Temp > 0)
    {
        ReversedCode = (ReversedCode * 10) + Temp % 10;
        Temp /= 10;
    }

    if (SecurityCode == ReversedCode)
        cout << "The security code is a palindrome.\n";
    else
        cout << "The security code is NOT a palindrome.\n";

    return 0;
}