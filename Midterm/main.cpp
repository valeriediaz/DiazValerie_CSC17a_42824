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
        cout<<"In problem # 2"<<endl<<endl;
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
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
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
