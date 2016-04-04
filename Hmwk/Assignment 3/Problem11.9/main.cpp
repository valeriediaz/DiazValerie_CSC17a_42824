/* 
 * Author: Valerie Diaz
 * Class: CSC-17A C++ Objects
 * Assignment 3 - Problem 10.4 
 *
 * Created on April 3, 2016, 8:15 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std; 

//User Libraries

//Global Constants

//Function Prototypes 


//Execution Begins Here 
int main(int argc, char** argv) {
    
    //Problem 10.4
    //What is the output of the following statement? 
    
    cout << toupper(tolower('A'));
    
    // Capital A, 
    // A is first put in lower case(tolower), 
    // then with "toupper" is put again in higher case. 

    return 0;
}

