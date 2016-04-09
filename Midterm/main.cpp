//Valerie Diaz
//April 8, 2016
//Midterm 
//CSC-17A-42824

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//Structures
struct EmployeeProb2 {				//Problem #2
	string name;
	int addressNo;
	string streetName;
	float hours;
	float pay;
	float gross;
};
struct statsResult {				//Problem #3
	float avg;
	float median;
	int *mode;	 //array containing the modes
	int nModes;	 //number of modes in the array
	int maxFreq; //max frequency of modes
};

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
float calcPay(float, float);
void printCheck(EmployeeProb2);
void words(int);
void problem3();
statsResult *avgMedMode(int *, int);
void Sort(int *, int);
void minPos(int *, int, int);
void printStat(statsResult, statsResult *, int);
void problem4();
void problem5();
void problem6();

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
	//PROBLEM 1
	cout << "In problem #1 " << endl << endl;
	cout << "There's nothing here..." << endl << endl;

}

void problem2(){
	//PROBLEM 2
	cout << "In problem #2 - Paycheck " << endl << endl;

	//Declaration;
	EmployeeProb2 *info;
	float hoursWorked;
	float payRate;
	string empName;
	int addressTemp;
	string streetTemp;
	int employeeTotal = 1;
	int count = 0;

	info = new EmployeeProb2[employeeTotal];
	do {
		//Prompt user for info
		cin.ignore();
		cout << "Enter your name: ";
		getline(cin, empName);
		cout << "Enter your address #: ";
		cin >> addressTemp;
		cin.ignore();
		cout << "Enter your street name: ";
		getline(cin, streetTemp);
		cout << "Enter rate of pay: ";
		cin >> payRate;
		cin.ignore();
		cout << "Enter total hours worked: ";
		cin >> hoursWorked;
		cin.ignore();
		cout << endl << endl;

		//Input validation and call functions
		if ((hoursWorked > 0.0) && (payRate > 0.0)) {
			info[count].name = empName;
			info[count].addressNo = addressTemp;
			info[count].streetName = streetTemp;
			info[count].pay = payRate;
			info[count].hours = hoursWorked;
			info[count].gross = calcPay(hoursWorked, payRate);
			printCheck(info[count]);
			count++;
		}
	}while((hoursWorked > 0.0) && (payRate > 0.0) && (count < employeeTotal));

	//Deallocate memory
	delete []info;
}

//Function for calculating gross pay
float calcPay(float hours, float payRate) {
	//Declaration
	float doubleTime = 2.0;
	float tripleTime = 3.0;
	float doubleHours = 40;
	float tripleHours = 50;
	float totalPay = 0.0;

	//Calculate gross pay - based on hours worked
	if (hours > tripleHours) {
		totalPay += ((hours - tripleHours) * (tripleTime * payRate));
		hours -= (hours - tripleHours);
	}
	if (hours > doubleHours && hours < tripleHours) {
		totalPay += ((hours - doubleHours) * (doubleTime * payRate));
		hours -= (hours - doubleHours);
	}
	if (hours > 0.0) {
		totalPay += hours * payRate;
	}
	return totalPay;
}

//Function that generates check
void printCheck(EmployeeProb2 emp) {
	//Declaration
	int dollars;
	int cents;
	string checkDollars;

	//Calculate dollars and cents based on gross pay from structure
	dollars = static_cast<int>(emp.gross);
	cents = static_cast<int>((emp.gross-static_cast<float>(dollars))*100);

	//Output to check
	cout << "EMPLOYEE PAYCHECK " << endl << endl;
	cout << "PAY TO: " << emp.name << setw(40) << "AMOUNT: $" << emp.gross;
	cout << endl;
	cout << setw(8) << " " << emp.addressNo << " " << emp.streetName;
	cout << endl << endl;
	words(dollars);
	cout << " & " << cents/10 << cents % 10 << "/100 DOLLARS" << endl << endl;
}

//Function for converting check value to text
void words(int checkValue) {
	const char * const singles[20] = {
			"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
			"EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN",
			"FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN",
			"NINETEEN"
	};
	const char * const tens[10] = {
			"", "TEN", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY"
			"SEVENTY", "EIGHTY", "NINETY"
	};
	if (checkValue >= 1000) {
		words(checkValue / 1000);
		cout << "THOUSAND";
		if (checkValue % 1000) {
			if (checkValue % 1000 < 100) {
				cout << " AND";
			}
			cout << " ";
			words(checkValue % 1000);
		}
	}
	else if (checkValue >= 100) {
		words(checkValue / 100);
		cout << " HUNDRED";
		if (checkValue % 100) {
			cout << " AND ";
			words(checkValue % 100);
		}
	}
	else if (checkValue >= 20) {
		cout << tens[checkValue / 10];
		if (checkValue % 10) {
			cout << " ";
			words(checkValue % 10);
		}
	}
	else {
		cout << singles[checkValue];
	}
}

void problem3(){
	//PROBLEM 3
	cout << "In problem #3 - Average, Median, Mode " << endl << endl;

	//Declaration
	int size;

	//Prompt user for size of array
	cout << "What is the size of the array? ";
	cin >> size;

	//Fill array
	int array[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter the value of the array: ";
		cin >> array[i];
	}
	//Call avgMedMode function
	avgMedMode(array, size);
	cout << endl;
}

//Function that calculates average, median, and mode
statsResult *avgMedMode(int *a, int num) {
	//Declaration
	statsResult result;
	float total = 0;
	int medianA, medianB, medianOdd, middle;

	//Calculate average
	for (int i = 0; i < num; i++) {
		total = total + a[i];
	}
	cout << setprecision(2) << fixed;
	result.avg = total / num;
	//Sort array
	Sort(a, num);
	for (int i = 0; i < num; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	//Calculate median - if even
	if (num % 2 == 0) {
		medianA = (num / 2) - 1;
		medianB = num / 2;
		middle = (a[medianA] + a[medianB]) / 2;
		result.median = middle;
	}
	//Calculate median - if odd
	else {
		medianOdd = num / 2;
		result.median = a[medianOdd];
	}
	//Calculate max Frequency
	result.nModes = 1;
	int max = 1;
	//Loop and compare
	for (int i = 1; i < num; i++) {
		if (a[i - 1] == a[i]) {
			result.nModes++;
			if (result.nModes > max)max = result.nModes;
		}
		else {
			result.nModes = 1;
		}
	}
	result.maxFreq = max;
	result.nModes = 0;
	//Calculate mode
	statsResult *c = new statsResult;
	c->mode = new int [num];
	int temp = a[1];
	for (int i = 0; i < num - 1; i++) {
		if (a[i] == temp) {
			result.nModes++;
			if (result.nModes == result.maxFreq) {
				c->mode[i] = a[i];
				result.nModes = 0;
				temp = a[i + 1];
			}
		}
	if (a[i] ==! temp) {
		result.nModes = 0;
		temp = a[i + 1];
		}
	}
	printStat(result, c, num);
	cout << endl;

	//Deallocate memory
	delete []c->mode;
	delete []c;
}

//Function that sorts array
void Sort(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		minPos(a, n, i);
	}
}

//Function used for sort
void minPos(int *a, int n, int pos) {
	for(int i = pos + 1; i < n; i++) {
		if (*(a + pos) > *(a + i)) swap (*(a + pos), *(a + i));
	}
}

//Function that outputs results
void printStat(statsResult r, statsResult *c, int n) {
	cout << endl;
	cout << "Average: " << r.avg << endl;
	cout << "Median: " << r.median << endl;
	cout << "Max Frequency " << r.maxFreq << endl;
	cout << "Modes: ";
	for (int i = 0; i < n; i++) {
		cout << c->mode[i] << " ";
	}
}

void problem4(){
    //PROBLEM 4
	cout << "In problem #4 - Encryption/Decryption " << endl << endl;

    //Declaration
    int number;
    int num1, num2, num3, num4;
    int encrypt1, encrypt2, encrypt3, encrypt4;
    int temp;
    bool fourdigit = false;
    bool zerothroughseven = false;

    //ENCRYPTION//
    do {
        //Prompt user for input
        cout << "Please enter the four digit number to be encrypted: ";
        cin >> number;
        //Check if number is four digits
        if (number > 9999) {
            cout << "That is not a four digit number." << endl;
        }
        else {
            fourdigit = true;
        }
        //Find value of each digit
        num1 = number/1000;
        num2 = (number % 1000)/100;
        num3 = ((number % 1000) % 100)/10;
        num4 = (((number % 1000)) % 100) % 10;
        //Check if each digit is between 0 and 7
        if (fourdigit == true){
            if (num1 < 0 || num1 > 7) {
                cout << "Each digit must be between 0 and 7." << endl;
            }
            else if (num2 < 0 || num2 > 7) {
                cout << "Each digit must be between 0 and 7." << endl;
            }
            else if (num3 < 0 || num3 > 7) {
                cout << "Each digit must be between 0 and 7." << endl;
            }
            else if (num4 < 0 || num4 > 7) {
                cout << "Each digit must be between 0 and 7." << endl;
            }
            else {
                zerothroughseven = true;
            }
        }
    } while(fourdigit == false || zerothroughseven == false);
    //Set values to encryption variables
    encrypt1 = num1;
    encrypt2 = num2;
    encrypt3 = num3;
    encrypt4 = num4;
    //Encryption - add 5, mod 8
    encrypt1 = (encrypt1 + 5) % 8;
    encrypt2 = (encrypt2 + 5) % 8;
    encrypt3 = (encrypt3 + 5) % 8;
    encrypt4 = (encrypt4 + 5) % 8;
    //Encryption - swap
    temp = encrypt1;
    encrypt1 = encrypt4;
    encrypt4 = temp;
    temp = encrypt2;
    encrypt2 = encrypt3;
    encrypt3 = temp;
    //Output encrypted number
    cout << "Your encrypted number is: "
         << encrypt1 << encrypt2 << encrypt3 << encrypt4 <<endl<<endl;

    //DECRYPTION//
    cout << "Please enter the four digit number to be decrypted: ";
    cin >> number;

    encrypt1 = number/1000;
    encrypt2 = (number % 1000)/100;
    encrypt3 = ((number % 1000) % 100)/10;
    encrypt4 = (((number % 1000)) % 100) % 10;

    //Decryption - swap
    temp = encrypt1;
    encrypt1 = encrypt4;
    encrypt4 = temp;
    temp = encrypt2;
    encrypt2 = encrypt3;
    encrypt3 = temp;
    //Decryption - reverse mod 8, add 5
    encrypt1 = (encrypt1 - 5 + 8) % 8;
    encrypt2 = (encrypt2 - 5 + 8) % 8;
    encrypt3 = (encrypt3 - 5 + 8) % 8;
    encrypt4 = (encrypt4 - 5 + 8) % 8;

    //Output decrypted number
    cout << "Your decrypted number is: "
         << encrypt1 << encrypt2 << encrypt3 << encrypt4 <<endl<<endl;
}

void problem5(){
    //PROBLEM 5
	cout << "In problem 5 - Factorials " << endl << endl;

	double x = 1;
	int factorial = 170;
	for (int i = 1; i <= factorial; i++) {
		x = x * i;
	}

	cout << "Data Type: Double" << endl;
	cout << "The largest factorial for double: ";
	cout << "170! = " << x << endl << endl;
}

void problem6(){
	//PROBLEM 6
	cout << "In problem 6 - Conversions " << endl << endl;

	cout << "2.125" << endl;
	cout << "Binary: 10.001" << endl;
	cout << "Octal: 2.1" << endl;
	cout << "Hex: 2.2" << endl << endl;
	cout << "-2.125" << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
