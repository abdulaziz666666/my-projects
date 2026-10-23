#include <iostream>
#include <cmath>
using namespace std;

//int GetPowerOfN(float Num, float Power)
//{
//    return round(pow(Num, Power));
//}
//
//void PrintResult(int Num)
//{
//    cout << "The powered result is " << Num << endl;
//}

int ReadBase()
{
    int Base;

    cout << "Please enter the Base: ";
    cin >> Base;

    return Base;
}

int ReadPower()
{
    int Power;

    cout << "Please enter the Power: ";
    cin >> Power;

    return Power;
}

int CalculatePower(int Base, int Power)
{ 
    int Result = 1;

    //for (int i = 1; i <= Power; i++)
    //{
    //    Result *= Base;
    //}
    
    int i = 1;

    while (i <= Power)
    {
        Result *= Base;
        i++;
    }

    return Result;
}

int main()
{
    int Base = ReadBase(), Power = ReadPower();

    unsigned Result = CalculatePower(Base, Power);

    cout << Base << "^" << Power << " = " << Result << endl;

    // The Old Way.
    //cout << "Please enter a number: ";
    //cin >> Num;

    //cout << "Please enter the power: ";
    //cin >> Power;

    ////const int Result = round(pow(Num, Power));
    ////cout << "The powered result is " << Result << endl;

    //PrintResult(GetPowerOfN(Num, Power));

    return 0;
}