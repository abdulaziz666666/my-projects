#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	unsigned short int ParkingHours;
	float PurchaseAmount;

	cout << "Enter parking hours: ";
	cin >> ParkingHours;

	cout << "Enter amount spent at the mall: ";
	cin >> PurchaseAmount;

	if (ParkingHours < 1 || ParkingHours > 24)
	{
		cout << endl;
		cout << "Wrong value of parking hours." << endl;
		cout << "It should be between 1-24 hours" << endl;
	}
	else
	{
		
		float ParkingFee, Discount, ParkingFeeAfterDiscount;

		if (ParkingHours <= 2)
		{
			ParkingFee = 0;
			Discount = 0;
			ParkingFeeAfterDiscount = 0;
		}
		else if (ParkingHours > 2 && ParkingHours <= 5)
		{
			ParkingFee = ParkingHours * 5;
			Discount = 0;
			ParkingFeeAfterDiscount = 0;
		}
		else if (ParkingHours > 5 && PurchaseAmount >= 200)
		{
			ParkingFee = ParkingHours * 5;
			Discount = 0.15 * ParkingFee;
			ParkingFeeAfterDiscount = ParkingFee - Discount;
		}
		else // more than 5 hours of parking, but without paying 200 SAR.
		{
			ParkingFee = ParkingHours * 5;
			Discount = 0;
			ParkingFeeAfterDiscount = ParkingFee;
		}

		cout << endl;
		cout << setprecision(2) << fixed; // to set the precision to 2 places.
		cout << "Parking Fee: "  << ParkingFee << " SAR\n";
		cout << "Discount: " << Discount << " SAR\n";
		cout << "Total cost after discount: " << ParkingFeeAfterDiscount << " SAR\n";
	}

	return 0;
}