// ATM Withdrawal & Fee Evaluator (Flawed Code)
#include <iostream>
using namespace std;

int main() {
    int accountActive = 0;   // 1 for Active, 0 for Suspended
    int accountTier = 3;     // 1: Regular, 2: Premium, 3: VIP
    double accountBalance = 1500.0;
    double dailyLimit = 500.0;
    double withdrawal = 100.0;
    double fee = 0.0;

    cout << "--- ATM Transaction Evaluator ---" << endl;

    // Check account status and withdrawal request
    if (accountActive == 1)
    {
        if (withdrawal <= accountBalance) {
            if (withdrawal < dailyLimit) {
                cout << "Withdrawal Approved." << endl;

                // Determine transaction fee based on account tier
                switch (accountTier) {
                case 1:
                    fee = 5.0;
                    break;
                case 2:
                    fee = 2.0;
                    break;
                case 3:
                    fee = 0.0;
                    break;
                default:
                    fee = 10.0;
                }
                cout << "Transaction Fee charged: SAR " << fee << endl;
            }
            else {
                cout << "Error: Withdrawal exceeds daily limit!" << endl;
            }
        }
    }
    else {
        cout << "Error: Account is suspended." << endl;
    }

    return 0;
}