/* 
 * File:   main.cpp
 * Author: valeriediaz
 *
 * Created on March 18, 2016, 2:29 PM
 */



//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Declare Variables 
    const int SIZE = 15; 
    float numbers[SIZE]; 
    float total = 0; 
    float mean = 0; 
    int count = 0;

    
    for (count = 0; count < SIZE; count++) {
        total += numbers[count];
       
        
    }
    
    mean = total / count; 
    
    cout << fixed; 
    cout << "The mean is: " << mean; 
    
    
    
    return 0;
}

