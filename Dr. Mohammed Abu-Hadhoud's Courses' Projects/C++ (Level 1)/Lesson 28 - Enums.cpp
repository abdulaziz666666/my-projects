#include <iostream>
using namespace std;

enum Color {Red, Green, Blue};
enum Direction {North, East, South, West};
enum Week {Sat=1, Sun, Mon, Tue, Wed, Thu, Fri}; // I can assign the first value to decide what they start with.
enum Gender {Male, Female};
enum Status {Single, Married};

int main()
{
    Color MyColor;
    Direction MyDirection;
    Week Today;
    Gender MyGender;
    Status MyStatus;

    MyColor = Color::Blue;
    MyDirection = Direction::East;
    Today = Week::Mon;
    MyGender = Gender::Male;
    MyStatus = Status::Married;

    return 0;
}