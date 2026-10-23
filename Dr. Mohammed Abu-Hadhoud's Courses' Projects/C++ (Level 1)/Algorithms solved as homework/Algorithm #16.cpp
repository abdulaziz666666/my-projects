#include <iostream>
#include <cmath>
using namespace std;

float GetRectangleAreaByDiagonal(float Diagonal, float Side)
{
    return Side * sqrt(pow(Diagonal, 2) - pow(Side, 2));
}

int main()
{
    float Diagonal, Side;

    cout << "Please enter the diagonal length: ";
    cin >> Diagonal;

    cout << "Please enter the side length: ";
    cin >> Side;

    cout << endl;

    //float Area = Side * sqrt(pow(Diagonal, 2) - pow(Side, 2)); // The Old Way.
    cout << "The area is " << GetRectangleAreaByDiagonal(Diagonal, Side) << endl;

    return 0;
}