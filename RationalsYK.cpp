#include "RationalsYK.h"

//namespace that has my initals as its name
namespace YK{
    //Constructor with no parameters that sets the numerator to 0 and the denominator to 1
    Rationals::Rationals(){
        numerator = 0;
        denominator = 1;
    }

    //Constructor with 1 parameter, that sets the numerator to the only parameter, and the denominator is set to 1
    Rationals::Rationals(int Newnumerator){
        numerator = Newnumerator;
        denominator = 1;
    }

    //Constructor with 2 parameters, it sets both the numerator and denominator to values that the user inputs,
    //also callse the simplify function so that the simplification is done at an earlier time.
    Rationals::Rationals(int Newnumerator, int Newdenominator){
        numerator = Newnumerator;
        denominator = Newdenominator;
        simplify();
    }

    //Uses recurssion to go through both the numbers until the gcd is found, which is found when the denominator is equal to 0
    int Rationals::gcd(int numerator,int denominator){
        //once the denominator ==0 the gcd is found
        if(denominator==0)
            return numerator;
        //repeatedly calling the function till the gcd is found
        return gcd(denominator, numerator % denominator);
    }

    void Rationals::simplify(){
        //returns 0/1 if the numerator is 1
        if(numerator==0){
            denominator = 1;
            return;
        }

        //the gcd function is called here to find the gcd which is then set to the integer MutualFactor
        int MutualFactor = gcd(numerator,denominator);
        numerator /= MutualFactor;
        denominator /= MutualFactor;

        //Made to make the code look better, so that only the numerator is negative making it look like -1/2 instead of 1/-2
        //(Personal preference from me)
        if(denominator < 0){
            numerator *= -1;
            denominator *= -1; 
        }
    }

    //overloaded input operator, 
    std::istream& operator>>(std::istream& inFS,Rationals& rational){
        //create a character to store the / input by the user
        char slash;
    
        //Gets the numerator and checks if there is a '/' after the numerator so that the user has the choice to 
        //input fractions or whole numbers, the peek function looks at the next thing the input operator takes in
        //and if the next thing is a '/' the rest of the fraction is taken in, and simplified, else the numerator is taken in
        inFS >> rational.numerator;
        if(inFS.peek() == '/'){
            inFS >> slash >> rational.denominator;
            rational.simplify();
        }else{
            rational.denominator = 1;
        }

        //This makes sure nothing is being divided by 0, which is undefined, the code shuts down if a value /0 or 0/0 is input.
        if((rational.numerator == 0 && rational.denominator == 0) || (rational.denominator == 0)){
            std::cout << "Undefined number, try again" << std::endl;
            exit(0);
        }
        return inFS;
    }

    //Overloaded output operator, it outputs the rational numbers
    std::ostream& operator<<(std::ostream& outFS, const Rationals& rational){
        //if the numerator is divisible by the denominator and the result is the numerator it is /1 making it a solid integer
        //if the numerator is also 0, the rational number will also be a solid integer of 0
        if(((rational.numerator / rational.denominator) == rational.numerator) || (rational.numerator == 0)){
            outFS << rational.numerator;
            return outFS;
        }
        //if none of those conditions are met, the fraction is output the way it was intended to
        outFS << rational.numerator << "/" << rational.denominator;
        return outFS;
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator==(const Rationals& Orational){
            return(((numerator * Orational.denominator) == (denominator * Orational.numerator)));
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator<(const Rationals& Orational){
        return((numerator*Orational.denominator) < (denominator * Orational.numerator));
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator>(const Rationals& Orational){
        return(((numerator*Orational.denominator) > (denominator * Orational.numerator)));
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator>=(const Rationals& Orational){
        return((numerator*Orational.denominator) >= (denominator * Orational.numerator));
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator<=(const Rationals& Orational){
        return((numerator*Orational.denominator) <= (denominator * Orational.numerator));
    }

    //returns a boolean value based on whether it is true or not according to the graph given 
    bool Rationals::operator!=(const Rationals& Orational){
        return!(*this == Orational);
    }

    //Overloaded + operator that adds up the rationals together by using the formula in the assignment pdf.
    //it then returns the new values
    Rationals Rationals::operator+(const Rationals& Orational){
        int NewDenominator = denominator * Orational.denominator;
        int NewNumerator = ((denominator * Orational.numerator)+(Orational.denominator * numerator));
        return Rationals(NewNumerator,NewDenominator);
    }

    //Overloaded - operator that subtracts the rationals together by using the formula in the assignment pdf.
    //it then returns the new values
    Rationals Rationals::operator-(const Rationals& Orational){
        int NewDenominator = (Orational.denominator * denominator);
        int NewNumerator = ((Orational.denominator * numerator) - (Orational.numerator * denominator));
        return Rationals(NewNumerator,NewDenominator);
    }

    //Overloaded * operator that multiplies the rationals together by using the formula in the assignment pdf.
    //it then returns the new values
    Rationals Rationals::operator*(const Rationals& Orational){
        int NewDenominator = (Orational.denominator * denominator);
        int NewNumerator = (Orational.numerator * numerator);
        return Rationals(NewNumerator,NewDenominator);
    }

    //Overloaded / operator that divides the rationals together by using the formula in the assignment pdf.
    //it then returns the new values
    Rationals Rationals::operator/(const Rationals& Orational){
        int Newnumerator = (numerator * Orational.denominator);
        int NewDenominator = (Orational.numerator * denominator); 
        return Rationals(Newnumerator,NewDenominator);
    }

    //Overloaded unary operator that changes how it works based on the values of the numerator and denominator, 
    //Makes sure to correctly change their sign.
    Rationals Rationals::operator-(){
        if(numerator > 0 && denominator > 0)
            return Rationals(-numerator, denominator);
        if(numerator > 0 && denominator < 0)
            return Rationals(numerator,-denominator);
        if(numerator < 0 && denominator > 0)
            return Rationals(-numerator,denominator);
        if(numerator < 0 && denominator < 0)
            return Rationals(-numerator,-denominator);

        return 0;
    }
}