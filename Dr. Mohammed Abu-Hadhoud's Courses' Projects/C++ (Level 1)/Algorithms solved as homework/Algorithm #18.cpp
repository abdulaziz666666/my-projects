#include <iostream>
#include <cmath>
using namespace std;

int GetCircleArea(float Radius)
{
    const float PI = 3.14;

    float Area = PI * pow(Radius, 2); 
    Area = ceil(Area);

    return Area;
}

void PrintCircleArea(float Area)
{
    cout << "The area is " << Area << endl;
}

int main()
{
    float Radius;

    cout << "Please enter the radius: ";
    cin >> Radius;

    cout << endl;

    //float Area = PI * pow(Radius, 2); // The Old Way.
    //Area = ceil(Area);
    //cout << "The area is " << Area << endl;

    PrintCircleArea(GetCircleArea(Radius));

    return 0;
}