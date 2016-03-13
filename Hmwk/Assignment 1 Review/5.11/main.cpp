/* 
 * Author: Valerie Diaz
 * Problem: 5.11
 */

/*
 * Write a for loop that displays every fifth number, zero through 100. 
 */

#include <cstdlib>
#include <iostream>

using namespace std;
int main() 
{
    for (int count = 0; count <= 100; count += 5)
    {
        cout << count << endl; 
    }

    
    return 0;
}

