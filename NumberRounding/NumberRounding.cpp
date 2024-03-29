// NumberRounding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

double RoundUp(double NumberToBeRounded,int Decimalplaces)
{
	ostringstream output_stream;
	cout << "OG NumberToBeRounded " << NumberToBeRounded << endl;
	output_stream << fixed << setprecision(Decimalplaces + 1) << NumberToBeRounded;
	string NumberString = output_stream.str();
	stringstream(NumberString) >> NumberToBeRounded;
	string WholeNumber = NumberString.substr(0, NumberString.find('.'));
	string FractionString = NumberString.substr(NumberString.find('.')+1, string::npos);

	// Now we need to construct this number as if it were a pure integer but remember where the radix point goes.
	int HSDs = atoi(WholeNumber.c_str());
	double Fraction = atof(FractionString.c_str())/pow(10,Decimalplaces+1);
	double RoundedNumber = 0;
	int LSD = atoi(FractionString.substr(FractionString.length()-1,1).c_str());
	// When using the stringstream you have to use a string a character will give you inconsistent results
	//stringstream(FractionString.substr(FractionString.length()-1,1)) >> LSD;
	int FracInt = 0;
	if (LSD >= 5)
	{
		cout << "Fraction Before = " << Fraction << endl;
		Fraction = Fraction + ((10-LSD) / pow(10, Decimalplaces + 1));
		FracInt = Fraction * pow(10, Decimalplaces);
		cout << "Fraction After = " << Fraction << endl;
	}
	//if (Fraction >= 1)
	//{
	//	HSDs = HSDs + (int)Fraction;
	//	Fraction = Fraction - (int)Fraction;
	//}
	string RoundedString = to_string(HSDs);

	
	RoundedNumber = HSDs + Fraction;

	//output_stream.clear();
	//output_stream << fixed << setprecision(Decimalplaces) << RoundedNumber;
	//RoundedNumber = atof(output_stream.str().c_str());
	//stringstream(output_stream.str()) >> RoundedNumber;
	cout << "HSDs = " << HSDs << endl;
	cout << "Fraction = " << Fraction << endl;
	cout << "Rounded Number to " << fixed << setprecision(Decimalplaces) << " Decimal Places Is = " << RoundedNumber << endl;


	return RoundedNumber;
	
	
}

int main()
{
	vector<double> TestNumbers = { 3.45615, 4.89781, 3.2108, 4.3879, 3.14125 };
	RoundUp(TestNumbers.at(1),3);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
