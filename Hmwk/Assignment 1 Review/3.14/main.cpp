/* 
 * Author: Valerie Diaz
 * Problem: 3.12 
 */

/*
 * Complete the following program skeleton so it asks the user to enter
 * a character. Store the character in the variable letter. Use a type
 * case expression with the variable in a cout statement to display the
 * character's ASCII code on the screen. 
 */

#include <cstdlib>
#include <iostream>
using namespace std;
int main() 
{
    char letter;
    
    //Prompt the user to enter a letter 
    cout << "Please enter a letter: ";
    cin >> letter; 
    cout << endl; 
    //Output the ASCII code for the letter using type cast 
    cout << "The ASCII code for the letter entered is: "
         << static_cast<int>(letter);
    
    
    return 0;
}

