//inlcude the files I need
#include <iostream>
#include "RationalsYK.h"

//include my own namespace and std
using namespace std;
using namespace YK;

int main(){
    //Create the objects of class Rationals
    Rationals Num1,Num2;

    //Telling the user to enter 2 rational numbers
    std::cout << "Enter 2 rational numbers: " << endl;

    //The overloaded input operator is called so that the numbers are inserted properly.
    cin >> Num1 >> Num2;

    //The overloaded output operator is called to output the object properly
    std::cout << "First rational number: " << Num1 << endl;
    std::cout << "Second rational number:  " << Num2 << endl;

    //Multiple conditions to check whether the 2 numbers are equal, greater than or less than each other.
    //if the conditions are met the statement is printed out.
    if(Num1 == Num2)
        std::cout << "The rationals are equal" << endl; 
    if(Num1 != Num2)
        std::cout << "The rationals are not equal" << endl;
    if(Num1 < Num2)
        std::cout << "The rational " <<Num1 << " is less than " << Num2 << endl;
    if(Num1 <= Num2)
         std::cout << "The rational " <<Num1 << " is less than or equal to " << Num2 << endl;
    if(Num1 > Num2)
        std::cout << "The rational " <<Num1 << " is greater than " << Num2 << endl;
    if(Num1 >= Num2)
        std::cout << "The rational " <<Num1 << " is greater than or equal to " << Num2 << endl;

    //These functions call the overloaded +,-,*, and / operators, which do the calculations for those 2 numbers
    //The answer is then outputted here
    std::cout << Num1 <<" + " <<Num2 <<" = " << Num1 + Num2 << endl;
    std::cout << Num1 <<" - " <<Num2 <<" = " << Num1 - Num2 << endl;
    std::cout << Num1 <<" * " <<Num2 <<" = " << Num1 * Num2 << endl;
    std::cout << Num1 <<" / " <<Num2 <<" = " << Num1 / Num2 << endl;

    //Calls the overloaded - unary operator so the value's sign changed based on the actual value.
    std::cout << "-Rational 1: " << -Num1 << endl;
    std::cout << "-Rational 2: " << -Num2 << endl;
    
    return 0;
}
