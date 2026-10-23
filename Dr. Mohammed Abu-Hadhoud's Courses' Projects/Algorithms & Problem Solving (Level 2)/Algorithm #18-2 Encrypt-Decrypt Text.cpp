#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
	string Text;
	
	cout << "Please enter any text: ";
	getline(cin, Text); 

	return Text;
}

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}
// Dr.Mohammed named it "EncryptText". I'm not sure which is better as the 
// parameter "Text" shows it is text encryption
//string Encrypt(string Text, int EncryptionShiftingAmount)
string EncryptText(string Text, short EncryptionShiftingAmount)
{
	// At first i thought i have to make another variable; Thinking strings are immutable.
	//string EncryptedText = "";

	for (int i = 0; i < Text.length(); i++)
	{
		//EncryptedText += char(int(Text[i]) + EncryptionShiftingAmount);
		Text[i] = char(int(Text[i]) + EncryptionShiftingAmount);
	}

	return Text;
}

// Dr.Mohammed named it "DecryptText".
//string Decrypt(string EncryptedText, int EncryptionShiftingAmount)
string DecryptText(string EncryptedText, short EncryptionShiftingAmount)
{
	// At first i thought i have to make another variable; Thinking strings are immutable.
	//string DecryptedText = "";

	for (int i = 0; i < EncryptedText.length(); i++)
	{
		//DecryptedText += char(int(EncryptedText[i]) - EncryptionShiftingAmount);
		EncryptedText[i] = char(int(EncryptedText[i]) - EncryptionShiftingAmount);
	}

	return EncryptedText;
}

void PrintEncryptionResult(string Text, short EncryptionShiftingAmount)
{
	string EncryptedText = EncryptText(Text, EncryptionShiftingAmount);
	string DecryptedText = DecryptText(EncryptedText, EncryptionShiftingAmount);

	cout << endl; 
	cout << "Text Before Encryption:\t" << Text << endl;
	cout << "Text After Encryption:\t" << EncryptedText << endl;
	cout << "Text After Decryption:\t" << DecryptedText << endl;
}

int main()
{
	string Text = ReadText();
	// Dr.Mohammed treated the EncryptionShiftingAmount as a constant, which is right,
	// but not convenient for a encryption\decryption program.
	// The program should be dynamic by asking the user to enter the letters shifting amount.
	// Overall, that is my opinion and no one is wrong, we are on the same page.
	short EncryptionShiftingAmount = ReadPositiveNumber("Please enter encryption shifting amount");

	PrintEncryptionResult(Text, EncryptionShiftingAmount);

	return 0;
}