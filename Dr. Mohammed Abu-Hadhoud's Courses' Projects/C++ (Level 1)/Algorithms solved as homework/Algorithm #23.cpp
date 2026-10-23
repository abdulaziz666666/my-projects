#include <iostream>
using namespace std;

int GetCircleAreaInTriangle(float A, float B, float C)
{
    const float PI = 3.14;

    float P = (A + B + C) / 2;
    float Unsquared = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
    float Area = PI * pow(Unsquared, 2);
    Area = round(Area);

    return Area;
}

int main()
{
    float A, B, C;

    cout << "Please enter the triangle sides: " << endl;

    cout << "A: ";
    cin >> A;

    cout << "B: ";
    cin >> B;

    cout << "C: ";
    cin >> C;

    //float P = (A + B + C) / 2; // The Old Way.
    //float Unsquared = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
    //float Area = PI * pow(Unsquared, 2);
    //Area = round(Area);

    cout << "The area is " << GetCircleAreaInTriangle(A, B, C) << endl;

    return 0;
}