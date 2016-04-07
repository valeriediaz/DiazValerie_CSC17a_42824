//Valerie Diaz
//April 7, 2016 
//Midterm

//System Libraries 
#include <iostream>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

//Execution
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
        case 7:    problem7();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=7);
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
    /* Develop an application using structures for a customer that will
     * determine if he/she has exceeded his/her checking account balance.
     * For each customer, the following facts are available:
     * 
     * a. Name
     * b. Address
     * c. Account number (Five digits only, test for this)
     * d. Balance at the beginning of the month
     * e. Total of all checks written by this customer this month
     *      - Loop until customer is through entering checks
     * f. Total of all deposits credited to this customer's account this month
     *      - Loop until customer is through entering deposits 
     * 
     * - Dynamically create the structure
     * - Input each of these facts (a-f) from input dialogs 
     * - Store in a structure, calculate new balance, display new balance
     * and debit the account $15 if overdrawn 
     * - If overdrawn, tell the customer the additional $15 fee has been 
     * accessed and what the balance would be with this fee included. 
     * - Make sure to output the contents of the structure (a-f) 
     */
    
}

void problem2(){
    /* Develop an application using an array of structures that will 
     * determine the gross pay for any number of employees input. 
     * The company pays "straight-time" for the first 40hrs worked, 
     * double time for all hours worked in excess of 40hrs but less than 50hrs, 
     * and triple time for any hours worked over 50hrs
     * 
     * - Program should loop and input the employee's name, hours worked, and
     * rate of pay. ($/hr) 
     * - Output information including the gross pay in the form of a paycheck
     * - Process starts again until you input an invalid rate of pay or hrs
     * worked. This means negative rate of pay or negative number of hrs worked
     * is not acceptable. 
     * 
     * Paycheck 
     * Company
     * Address
     * Name:    Amount: numerical
     * Amount: English
     * Signature: 
     */
}

void problem3(){
     /*Write a function using the following structure and prototype.

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

statsResult *avgMedMode(int *,int); 

The function takes in an integer array and the size of the array.
Then returns a pointer to a structure containing the average, median
and mode.  You will then write a printStat() function that will print
the results contained in the stats structure.  I will input a small 
array to test this out so ask for how many inputs to fill the array, 
then the values to place into the array.  Make sure you delete the 
dynamic array creation for the mode when you exit the problem.

      */
}

void problem4(){
    //PROBLEM 4
    
    //Declaration  
    int number;
    int num1, num2, num3, num4; 
    int encrypt1, encrypt2, encrypt3, encrypt4; 
    int temp;
    bool fourdigit = false;
    bool zerothroughseven = false;
 
    //ENCRYPTION PROGRAM*******************************************************/ 
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
    
    //DECRYPTION PROGRAM*******************************************************/
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
    /* a) Using a byte variable, what is the largest factorial that can 
be calculated.  A factorial is simply 

n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

b)  What would be the largest factorial using short, int, long, float, 
double, etc...  Use all the primitive data types that you are familiar 
with signed as well as unsigned.

Note:  I want you to have fun investigating this and the program you 
turn in should just print "cout" the final results.  You don't know 
how to capture errors yet so run each till it overflows then back off by 1.
Don't need the program that tests for this.
     */
}

void problem6(){
  /*
    a)  Convert the following 2 numbers to binary, octal and hex.
	2.125, 0.1328125
        When done, convert the following to a float representation
        by the definition in class. In other words, I want an 8 digit hex 
	number representation using the 4 byte float specification
        defined in class.  
   b)  Do the same for a) given they are negative values.
   c)  Convert the float representations of the following into 
	the decimal number given the definition in class.
	46666601, 46666602, B9999AFE

Note:  This doesn't require a program, however, I want you to write a 
simple function that outputs the answers you did by hand with "cout".
   */
}

void problem7(){
    //EXTRA CREDIT 
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
