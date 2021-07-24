/*
Your ID block here
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
/*
 A qudratic equation has a form A*X^2 + B*X + C = 0.
 In the above equation A, B, C are constants. X is the variable.
 Please watch my video on quadratic equations to learn more about them.
 When A =0, the equation becomes a linear one as B*X + C = 0.
 And ofcourse with both A and B being zero, there is no equation.
 More on quadratic equations:
 The solution to the quadratic equation Ax2 + Bx  + C  = 0
 may be calculated using the quadratic formulae:
 
 X1 = (-B +(B^2 – 4*A*C)^0.5)/(2*A)
 or    X2 = (-B - (B^2 – 4*A*C)^0.5)/(2*A)
 
 These formulae may be used, of course, only if the leading coefficient,
 A is not zero. With A = 0, the equation adapts a linear form.
 The number and type of solutions is determined by the value
 of the expression under the square root (power  ½  ),
 B^2  - 4*A*C, also known as discriminant.
 Table below gives describes various possible solutions related to the discriminant value.
 =====================================================================
 Value of Discriminant    Number of Solutions    Nature of Solutions
 ======================================================================
 Positive                       2                   Real
 Zero                           1                   Real
 Negative                       2                   Imaginary
 ======================================================================
 Imaginary solutionss would be of the form
 X1 = a + (I*)b  ............. Eq1
 X2 = a - (I*)b .............. Eq2
 In mathematics I = (-1)^0.5 or square root of -1,
 Since programming language does not provide the imaginary numbers
 and the facility to output them, you will have to take
 appropriate steps to give imaginary results in the form shown
 in the output from main function and respective member functions.
 Just remember that a pair of real numbers determines
 every imaginary number. X1 and X2 in Eq1 and Eq2, a is the real part.
 (I*)b is the imaginary part, but b is ordinary real number. Both
 a, and b are floating-point numbers.
 
 Class stores values of A, B, C are data members.(See description).
 if A is not zero, then equation is always a quadratic equation.
 If A = 0, and B != 0 then equation is linear equation.
 Equation then will be:
 B*X + C = 0
 And one linear solution will be
 X = -C/B [Both C and B are integers, so casting of numerator or denominator
 to double type will be needed to get floating-point ratio].
 If both A and B are zero then there is no equation.
 Class has constructors and member functions to find roots of quadratic
 form and solution to linear form.
 
 You are NOT required to write a main function, but tailor all class
 member functions, so that main I have provided gives the output that
 my program produces.
 
 Description of each class member is described in comments, just above
 the member declaration.
 */
class Quadratic
{
private:
    /*
     Coefficient of X square. Can be zero. In that case equation can be linear
     but if B is also zero then there is no equation.
     */
    int A;
    /*
     Coefficient of X . Can be zero. if A is also zero then there is no equation.
     */
    int B;
    /*
     Constant. Can be zero, positive, or negative.
     */
    int C;
    /*
     isLinear gets a true value if A = 0, but B!=0. It gets a false
     value, if equation is quadratic.
     */
    bool isLinear;
    /*
     isEquation gets a true value if equation formed by A, B, C is
     either quadratic, or linear. Otherwise it gets a false value.
     */
    bool isEquation;
public:
    /*
     Default Constructor:
     Sets A, B, and C to zero and isLinear and isEquation to false.
     */
    Quadratic();
    /*
     Explicit constructor:
     First initializes class data members A, B, and C to in_a, in_b, and in_c
     respectively. Then properly sets isLinear and isEquation to true or
     false depending upon values of A, B, and C.
     */
    Quadratic(int in_a  , int in_b  , int in_c );
    
    /*
     returns A, the coefficient of X^2. This is just one line of code.
     */
   int getCeffXSquare() const;
    /*
     returns B, the coefficient of X. This is just one line of code.
     */
   int getCoeffOfX()const;
    /*
     returns C, the constant. This is just one line of code.
     */
   int getConstant() const;

   void getRealRoots(double &root1, double & root2)const;
    /*
     Description of member function getRealPartAndImagPart:
     When discriminant or B^2  - 4*A*C <0, then solution is a complex
     number. You can read about complex numbers on the link below:
     https://en.wikipedia.org/wiki/Complex_number
     The root will contain a real part (Called Real), which is given as
     Real = (-B)/(2*A)
     But both B, 2, and A are integers. You need to cast at least on
     operand to double type to get the floating-point value for Real.
     The imaginary part Imag is computed as follows:
     Imag = sqrt(abs(discriminant))/(2*A).
     */
   void getRealPartAndImagPart(double & Real , double & Imag)const;
    /*
     Description of member function toString:
     This will be the hardest function to write. I, however, feel that
     you will learn lot of programming by mastering this function.
     This function cannot be finished in one code writing session and
     you may have to write fair amount of algorithm on paper to get
     practice with all it's moving parts. All output in this function is done to
     ostringstream object. You had some practice with that in last lab.
     All the ostringstream references provided in last lab are still
     very useful in this case.
     
     My tostring function has about 101 lines of code. I am not saying that
     it cannot be done in less lines, but that is what I have at this
     point. That of course includes {  and } having their own lines
     and blank lines.
     
     Function returns a string, that contains the equation and then it's
     roots, be they be real, complex number or linear. Or function will
     return a string that there is no equation, if there is none.
     Output from our main function is a vivid demonstration of how this function
     works. We will just give few examples of code and output here.
     For rest, you have to rummage through the code in main function
     and output from the main function.
     =======================
     Code -------------------
     Quadratic Q1(2, -5, -3);
     cout<<Q1.toString();
     Output ----------------
     The original Equation:
     2*X^2   - 5X  - 3 = 0
     Two Positive roots are:
     X1 = 3.0000e+00
     X2 = -5.0000e-01
     =========================
     code -------------------
     Quadratic Q2(2, -5, 4);
     cout<<Q2.toString();
     Output ------------------
     The original Equation:
     2*X^2   - 5X  + 4 = 0
     Two complex number roots are
     X1 = 1.2500e+00 - I* (6.6144e-01 )
     X2 = 1.2500e+00 + I* (6.6144e-01 )
     ===================================
     code -------------------------
     Quadratic Q3(1, -8, 16);
     cout<<Q3.toString();
     Output -----------------------
     The original Equation:
     X^2   - 8X  + 16 = 0
     One Positive root is:
     X1 = 4.0000e+00
     ==================================
     code ---------------------------
     Quadratic Q6(0, 2, -7);
     cout<<Q6.toString();
     output --------------------------
     The original Equation:
     2*X -7 = 0
     Linear Solution is: X1 = 3.5000e+00
     =====================================
     Please see code in main function and output from main function
     to see other examples of output from toString function, that
     is printed to console.
     */
   const string toString() const;
    /* friend function operator +
     This friend function takes two Qudratic class objects,
     left and right and sums them up and returns their sum.
     Look up relevant examples of overloading + operators
     in Savitch or in my ebook chapter at the link below
     https://sites.google.com/site/cplusplussmc/10-c-data-structure/00---operator-overloading-and-class-friends
     I may upload this chapter in our module as well.
     */
   friend const Quadratic operator + (const Quadratic & left,
                                    const Quadratic & right );
    /* friend function operator -
     This friend function takes two Qudratic class objects,
     left and right and subtracts right from left and returns the new
     Qudratic object.
     Look up relevant examples of overloading - operators
     in Savitch or in my ebook chapter at the link below
     https://sites.google.com/site/cplusplussmc/10-c-data-structure/00---operator-overloading-and-class-friends
     */
    friend const Quadratic operator - (const Quadratic & left,
                                       const Quadratic & right );
    /*
     friend function operator *
     This one is simple. The argument multiplier multiplies to
     A, B, C and new Qudratic object is returned. I did this in
     just one line of code.
     */
   friend const Quadratic operator *(int multiplier, const  Quadratic & Original);
   /*
    Member function Value plugs in for X in the equation, the numerical
    value IN_X and returns the evaluated floating-point value. Code and
    output example is shown below:
    =====================================
    Code............................
    Quadratic Q1(2, -5, -3);
     cout<<Q1.Value(1)<<endl;
    Output..................
    -6
    =====================================
    */
    double Value(double IN_X)const;
    /*
     friend function operator ==
     This function reyurn true if both Qudratic objects left and right
     are identical equations. Otherwise it would return false.
     This function would be simple if A, B, and C values in objects
     left and right are same. But undderstand that following two equations
     are mathematically identical.
     X^2 + X + 1 = 0
     2X^2 + 2X + 2 = 0
     But merely comparing their numerical coefficients using == operator
     will not show them to be same. Littel bis later you have to write
     a GCD function and make use of that to ascertain overloaded operator
     == shows above two equations to be the same. Code examples and outputs
     are shown below:
     =====================================
     Code.................
      Quadratic Q1(2, -5, -3);
      Quadratic Q11 = 5*Q1;
     cout<<boolalpha;
     cout<<(Q1 == Q11)<<endl;
     Output....................
     true
     */
    friend bool operator == (const Quadratic & left,
                             const Quadratic & right );
    /*
     friend function operator !=
     This will be just one line of code.
     */
    friend bool operator != (const Quadratic & left,
                             const Quadratic & right );
    /*
     Static member function GCD returns GCD of integers
     a, and b. It uses Euclid's algorithm. Link to Euclid's algorithm is below
     https://en.wikipedia.org/wiki/Euclidean_algorithm
     This could be hard or easy depending upon your previous math
     background. This function would be used inside overloaded
     operator ==
     */
    static int GCD(int a, int b);
};
Quadratic::Quadratic()
{
   
}
Quadratic::Quadratic(int in_a, int in_b, int in_c)
{
  
}
int Quadratic::getCeffXSquare()const
{
    throw "To be completed";
   
}
int   Quadratic::getCoeffOfX()const
{
    throw "To be completed";
   
}

 int Quadratic::getConstant() const
{
     throw "To be completed";
    
}
void Quadratic::getRealRoots(double & root1, double & root2)const
{
  
}
void Quadratic::getRealPartAndImagPart(double & Real , double & Imag)const
{
   
}

const string Quadratic::toString() const
{
    throw "To be completed";
   

}
const Quadratic operator + (const Quadratic & left, const Quadratic & right )
{
   
    throw "To be completed";
}
const Quadratic operator - (const Quadratic & left, const Quadratic & right )
{
    throw "To be completed";
    
}
const Quadratic operator *(int multiplier, const  Quadratic & Original)
{
    throw "To be completed";
   
}
double Quadratic::Value(double IN_X)const
{
     throw "To be completed";
    
}
int Quadratic::GCD(int a, int b)
{
   throw "to be completed";
    
}
bool operator == (const Quadratic & left, const Quadratic & right )
{
    
    throw "to complete";
}
bool operator != (const Quadratic & left,
                  const Quadratic & right )
{
    throw "to complete";
}
/*
 Once you have filled out the body of class member and friend
 functions. Use the main function below and ascertain that
 output matches the output shown right after the main function.
 */
int main(int argc, const char * argv[]) 
{
try
{
    Quadratic Q1(2, -5, -3);
    cout<<Q1.toString();
    Quadratic Q2(2, -5, 4);
    cout<<Q2.toString();
    Quadratic Q3(1, -8, 16);
    cout<<Q3.toString();
    Quadratic Q4(4, 0, 0);
    cout<<Q4.toString();
    Quadratic Q5(4, 0, 25);
    cout<<Q5.toString();
    Quadratic Q6(0, 2, -7);
    cout<<Q6.toString();
    Quadratic Q7(0, 0, -7);
    cout<<Q7.toString();
    Quadratic Q8(2, 4, 0);
    cout<<Q8.toString();
    Quadratic Q9(1, 1, 1);
    cout<<Q9.toString();
    Quadratic Q10 = Q1 + Q2;
    cout<<Q10.toString();
    Quadratic Q11 = 5*Q1;
    cout<<Q11.toString();
    Quadratic Q12 = Q2 - Q3;
    cout<<Q12.toString();
    cout<<Q1.Value(1)<<endl;
    Quadratic Q13(0, 1, 2);
    Quadratic Q14 = Q13 + Q1;
    cout<<Q14.toString();
    Quadratic Q15(0, 3, 4);
    cout<<Q15.toString();
    Quadratic Q16 = Q13 + Q15;
    cout<<"Q16 = Q13 + Q15"<<endl;
    cout<<Q16.toString();
    Quadratic Q17(0, -5, 0);
    cout<<Q17.toString();
    Quadratic Q18(0, 6, 0);
    cout<<Q18.toString();
    //GCD tests
    cout<<"+++ GCD Tests+++++++++++++\n";
    int gcd1 = Quadratic::GCD(1,2);
    cout<<"GCD of 1, 2 = "<<gcd1<<endl;
    int gcd2 = Quadratic::GCD(3,6);
    cout<<"GCD of 3, 6 = "<<gcd2<<endl;
    int gcd3 = Quadratic::GCD(-12,24);
    cout<<"GCD of -12, 24 = "<<gcd3<<endl;
    int gcd4 = Quadratic::GCD(-12,-24);
    cout<<"GCD of -12, -24 = "<<gcd4<<endl;
    int gcd5 = Quadratic::GCD(12,-24);
    cout<<"GCD of 12, -24 = "<<gcd5<<endl;
    cout<<boolalpha;
    cout<<(Q1 == Q11)<<endl;
    cout<<(Q1 == Q1)<<endl;
    cout<<(Q1 == Q2)<<endl;
    
    cout<<(Q1 != Q11)<<endl;
    cout<<(Q1 != Q1)<<endl;
    cout<<(Q1 != Q2)<<endl;
    }
    catch(...)
    {
        cout<<"An exception has been thrown. This will disappear when all class member function bodies are filled and throw statement is removed."<<endl;
    }
    
    return 0;
}
/*
 Outut
 The original Equation:
 2*X^2   - 5X  - 3 = 0
 Two Positive roots are:
 X1 = 3.0000e+00
 X2 = -5.0000e-01
 ==========================================
 The original Equation:
 2*X^2   - 5X  + 4 = 0
 Two complex number roots are
 X1 = 1.2500e+00 - I* (6.6144e-01 )
 X2 = 1.2500e+00 + I* (6.6144e-01 )
 
 ==========================================
 The original Equation:
 X^2   - 8X  + 16 = 0
 One Positive root is:
 X1 = 4.0000e+00
 ==========================================
 The original Equation:
 4*X^2   + 0*X   + 0 = 0
 One Positive root is:
 X1 = 0.0000e+00
 ==========================================
 The original Equation:
 4*X^2   + 0*X   + 25 = 0
 Two complex number roots are
 X1 = 0.0000e+00 - I* (2.5000e+00 )
 X2 = 0.0000e+00 + I* (2.5000e+00 )
 
 ==========================================
 The original Equation:
 2*X -7 = 0
 Linear Solution is: X1 = 3.5000e+00
 ==========================================
 You do not have an equation.
 ==========================================
 The original Equation:
 2*X^2   + 4*X   + 0 = 0
 Two Positive roots are:
 X1 = 0.0000e+00
 X2 = -2.0000e+00
 ==========================================
 The original Equation:
 X^2   + X  + 1 = 0
 Two complex number roots are
 X1 = -5.0000e-01 - I* (8.6603e-01 )
 X2 = -5.0000e-01 + I* (8.6603e-01 )
 
 ==========================================
 The original Equation:
 4*X^2   - 10X  + 1 = 0
 Two Positive roots are:
 X1 = 2.3956e+00
 X2 = 1.0436e-01
 ==========================================
 The original Equation:
 10*X^2   - 25X  - 15 = 0
 Two Positive roots are:
 X1 = 3.0000e+00
 X2 = -5.0000e-01
 ==========================================
 The original Equation:
 X^2   + 3*X   - 12 = 0
 Two Positive roots are:
 X1 = 2.2749e+00
 X2 = -5.2749e+00
 ==========================================
 -6
 The original Equation:
 2*X^2   - 4X  - 1 = 0
 Two Positive roots are:
 X1 = 2.2247e+00
 X2 = -2.2474e-01
 ==========================================
 The original Equation:
 3*X  + 4 = 0
 Linear Solution is: X1 = -1.3333e+00
 ==========================================
 Q16 = Q13 + Q15
 The original Equation:
 4*X  + 6 = 0
 Linear Solution is: X1 = -1.5000e+00
 ==========================================
 The original Equation:
 -5*X  + 0 = 0
 Linear Solution is: X1 = -0.0000e+00
 ==========================================
 The original Equation:   
 6*X  + 0 = 0
 Linear Solution is: X1 = 0.0000e+00
 ==========================================
 +++ GCD Tests+++++++++++++
 GCD of 1, 2 = 1
 GCD of 3, 6 = 3
 GCD of -12, 24 = 12
 GCD of -12, -24 = 12
 GCD of 12, -24 = 12
 true
 true
 false
 false
 false
 true
 */
