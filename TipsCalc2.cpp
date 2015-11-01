//Kim Lien Chu
//COP2000.0M1
/*Gratuity Calculator
//This program will : Calculate the gratuity on a restaurant meal
//     
//     1.  Create class Tips
//     2.  Use user input for taxRate or default taxRate .065
//     3.  Validate user input of tax rate
//     4.  Use user input of total bill amount
//     5.  Validate user input of total bill amount
       6.  Has public function: computeTips
       7.  Calculate the tip base on cost of meal before tax
       8.  Calculate the cost of meal at different tip rates
       9.  Calculate the total cost of meal after tax
       10. Loop to calculate as many meals as the user want
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/*****************************************/
//      class Tips
/****************************************/
class Tips
{
	//member variable : taxRate
private:
	double taxRate;
public:
	Tips()                 //default constructor
	{
		taxRate = .065;
	};
	Tips(double t)            //overloaded constructor
	{
		taxRate = t;
	};

	//prototypes for member functions

	double computeTips(double, double);
	

};

// /***************Method definition****************************/



double Tips::computeTips(double billTotal, double tipRate)
{
	
	double mealTotal;
	double tipTotal;
	mealTotal = billTotal / (1 + taxRate);
	
	tipTotal = (tipRate / 100) * (mealTotal);
	return tipTotal;
}
//To do
// get tax rate
//create an object of the class
// get input user total bill

/******************/
//prototypes
void   validateOpCalc(string&);
double getTaxRate();
void   validateOption(string&);
void   validateTaxRate(double&);
double getBillTotal();
void   validateBillTotal(double&);
void   displayTipTable(double);

int main()
{
	string yesCalc;
	
	cout << "\n\n                 Welcome to the Gratuity Calculator \n\n";
	cout << "           Would you like to calculate the gratuity for a meal?  ";
	getline(cin, yesCalc);
	validateOpCalc(yesCalc);

		while (yesCalc == "y" )
		{
			string yesCalcAgain;
			double tipRate;
			double totalCost;
			double tipCalc;

			double billTotal;
			double tax;
			string yOrN;
			cout << "\n\n           Is the tax rate 6.5%: (enter y or n):  ";
			getline(cin, yOrN);
			//validate user input of valid option y or n
			validateOption(yOrN);
			Tips tipObj;
			if (yOrN == "n")
			{
				tax = getTaxRate();
				tipObj = Tips(tax);
			}
			else 
			{
				tipObj = Tips();
			}


			//get total bill amount
			billTotal = getBillTotal();
			//calculate total bill: tax + meal + tips
			tipRate = 10.0;

			cout << "\n\n                  TIP TABLE  \n\n";
			cout << "      TIP (%)       \t  TIP TOTAL($)   \t  \t   MEAL TOTAL($) \n";
			cout << "                                                     (meal cost + tax + tip) \n\n";
			do
			{
				tipCalc = tipObj.computeTips(billTotal, tipRate);
				totalCost = tipCalc + billTotal;
				cout << showpoint << setprecision(2) << fixed << "     " << tipRate << " % "
					<< "        \t  $\t" << tipCalc
					<< "              \t  $\t " << totalCost << " \n";
				tipRate = tipRate + 5;
			} while (tipRate <= 25);

			cout << "\n\n            Gratuity Calculation Completed   \n\n";
			cout << "\n\n     Would you like to calculate the Gratuity for another meal?";
			getline(cin, yesCalc);
			validateOpCalc(yesCalc);

		} 
	return 0;
}
void validateOpCalc(string& yC)
{
	while (!cin || (yC != "y" && yC != "n"))
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again (enter y or n):  ";
		cin >> yC;
	}


}


double getTaxRate()
{
	double taxInput;
	double taxFraction;
	// get tax rate or default rate  
	cout << "\n\n           Enter the tax rate \n";
	cout << "    (enter a positive tax rate 5.5 % is entered as:  5.5 ):   ";
	cin >> taxInput;
	//  validate user input valid tax rate
	validateTaxRate(taxInput);
	// calculate tax rate for calculation
	taxFraction = taxInput / 100;
	// send tax rate back
	return taxFraction;
}

void validateOption(string& o)
{
	while (!cin ||( o != "y" && o != "n"))
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again (enter y or n):  ";
		cin >> o;
	}
	
	
}
//validate taxRate input
void validateTaxRate(double& t)
{
	while (!cin  || t < 0)
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again "
			 << "\n    (a positive tax rate of 4.5% is entered as:  4.5 ):   ";
		cin >> t;
	}
}

//get billTotal from user input
double getBillTotal()
{
	double billTotal;
	//prompt user for bill total
	cout << "\n\n           Enter the bill total  \n";
	cout << "    (a positive bill cost of $54.5 is entered as: 54.5 ):  ";
	cin >> billTotal;
	//validate user input of valid option y or n
	validateBillTotal(billTotal);
	return billTotal;
}
void validateBillTotal(double& b)
{
	while (!cin || b < 0)
	{
		cin.sync();
		cin.clear();
		cout << "\n           Invalid input, try again \n";
		cout << "    (a positive bill cost of $54.5 is entered as: 54.5):   ";
		cin >> b;
	}
}


