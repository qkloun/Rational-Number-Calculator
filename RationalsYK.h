#ifndef RationalsYK_H
#define RATIONALSYK_H

#include <iostream>

//Declaring the namespace with my initials that holds my class
namespace YK{
    class Rationals{
        //Making the numerator and denominator as the private variables in my class
        private:

            int numerator;
            int denominator;

            //These 2 functions are here for encapsulation, so that the user can't change or interefere with
            //what these 2 functions will produce to find the simplified version of the fractions.
            void simplify();
            int gcd(int numerator, int denominator);

        public:
        //Declaring the functions, constructors and overloaded operators here.

        //Constructors needed for the code to work.
        Rationals();
        Rationals(int numerator);
        Rationals(int numerator,int denominator);


        //Friend functions that control what is inputted and outputted.
        //Friend functions are given access to the private values in a class
        friend std::istream& operator>>(std::istream& inFS, Rationals& rational);
        friend std::ostream& operator<<(std::ostream& outFS, const Rationals& rational);

        //Overloaded operators for the code.

        //These return boolean values.
        bool operator==(const Rationals& Orational);
        bool operator<(const Rationals& Orational);
        bool operator>(const Rationals& Orational);
        bool operator>=(const Rationals& Orational);
        bool operator<=(const Rationals& Orational);
        bool operator!=(const Rationals& Orational);

        //these functions return objects of class Rationals.
        Rationals operator+(const Rationals& Orational);
        Rationals operator-(const Rationals& Orational);
        Rationals operator*(const Rationals& Orational);
        Rationals operator/(const Rationals& Orational);
        Rationals operator-();

    };
}

#endif