/*
Name: young cheol ko
Class: CS52
Lab #: 6
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 3/28 19:24
Date and Time of when program verified all test results: 3/28 12:43
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Quadratic
{
private:
	int A;
	int B;
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
	Quadratic();
	Quadratic(int in_a, int in_b, int in_c);
	int getCeffXSquare() const;
	int getCoeffOfX()const;
	int getConstant() const;
	void getRealRoots(double &root1, double & root2)const;
	void getRealPartAndImagPart(double & Real, double & Imag)const;
	const string toString() const;
	friend const Quadratic operator + (const Quadratic & left,
		const Quadratic & right);
	friend const Quadratic operator - (const Quadratic & left,
		const Quadratic & right);
	friend const Quadratic operator *(int multiplier, const  Quadratic & Original);
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
		const Quadratic & right);
	/*
	 friend function operator !=
	 This will be just one line of code.
	 */
	friend bool operator != (const Quadratic & left,
		const Quadratic & right);
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
	A = 0;
	B = 0;
	C = 0;
	isLinear = false;
	isEquation = false;
}
Quadratic::Quadratic(int in_a, int in_b, int in_c)
{
	A = in_a;
	B = in_b;
	C = in_c;
	if (A != 0 || B != 0) {
		isEquation = true;
	}
	else if (A == 0 && B != 0) {
		isLinear = true;
	}
}
int Quadratic::getCeffXSquare()const
{
	return A;
}
int   Quadratic::getCoeffOfX()const
{
	return B;
}

int Quadratic::getConstant() const
{
	return C;
}
void Quadratic::getRealRoots(double & root1, double & root2)const
{
	/*
 Description of member function getRealRoots:
 if discriminant = B^2  - 4*A*C >=0 then equation has real roots.
 If discriminant> 0 then root1 and root2 returned by reference
 have two real values.
 Use these two equations to find root1 and root2.[C++ form of both are needed]
 root1 = (-B +(B^2 – 4*A*C)^0.5)/(2*A)
 root2 = (-B - (B^2 – 4*A*C)^0.5)/(2*A)
 If discriminant = 0, then root1 = root2 and roots have a real value.
 In that case root = (-B)/(2*A)
 But both B, 2, and A are integers. You need to cast at least on
 operand to double type to get the floating-point root.
 */
	double D = (pow(B, 2) - (4 * A * C));
	if (D>0) {
		root1 = (-B + sqrt(D)) / static_cast<double>(2 * A);
		root2 = (-B - sqrt(D)) / static_cast<double>(2 * A);
	}
	else if (D == 0) {
		root1 = (-B + sqrt(D)) / static_cast<double>(2 * A);
		root2 = root1;
	}
}
void Quadratic::getRealPartAndImagPart(double & Real, double & Imag)const
{
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
	double D = (pow(B, 2) - (4 * A * C));
	if (D < 0) {
		Real = (-B) / static_cast<double>(2 * A);
		Imag = sqrt(abs(D)) / static_cast<double>(2 * A);
	}
}

const string Quadratic::toString() const
{
	ostringstream buffer;
	buffer << fixed << showpoint << setprecision(6)
		<< "The original Equation :" << endl
		<< getCeffXSquare() << "*X^2 ";
	if (B > 0) {
		buffer <<"+"<< getCoeffOfX() << "X ";
	}
	else {
		buffer << getCoeffOfX() << " X ";
	}
	if (C > 0) {
		buffer << "+" << getConstant();
	}
	else {
		buffer << getConstant();
	}
	buffer << " = 0" << endl;

	double D = (pow(B, 2) - (4 * A * C));
	if (D > 0) {
		buffer << "Two Positive roots are :" << endl
			<< "X1 = " << endl
			<< "X2 = " << endl;
		}
	else if (D == 0) {
		buffer << "One Positive root is :" << endl
			<< "X1 = " << endl;
	}
	else if (D < 0) {
		buffer << "Two complex number roots are" << endl
			<< "X1 = " << " " << "- I * ( " << " " << ")" << endl
			<< "X2 = " << " " << "+ I * ( " << " " << ")" << endl;
	}
	buffer << "======================== = " << endl;
		
	return buffer.str();
}
const Quadratic operator + (const Quadratic & left, const Quadratic & right)
{
	Quadratic Q;
	Q.A = left.A + right.A;
	Q.B = left.B + right.B;
	Q.C = left.C + right.C;
	return Q;
}
const Quadratic operator - (const Quadratic & left, const Quadratic & right)
{
	Quadratic Q;
	Q.A = left.A - right.A;
	Q.B = left.B - right.B;
	Q.C = left.C - right.C;
	return Q;
}
const Quadratic operator *(int multiplier, const  Quadratic & Original)
{
	Quadratic Q;
	Q.A = Original.A * multiplier;
	Q.B = Original.B * multiplier;
	Q.C = Original.C * multiplier;
	return Q;
}
double Quadratic::Value(double IN_X)const
{
	double x;
	x = A * (IN_X * IN_X) + B * IN_X + C;
	return x;
}
int Quadratic::GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	int c;
	while (true) {
		c = a % b;
		if (0 == c)
			break;
		a = b;
		b = c;
	}
	return b;
}
bool operator == (const Quadratic & left, const Quadratic & right)
{

	return (left.A == right.A && left.B == right.B && left.C == right.C);
}
bool operator != (const Quadratic & left, const Quadratic & right)
{
	return !(left == right);
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
		cout << Q1.toString();
		Quadratic Q2(2, -5, 4);
		cout << Q2.toString();
		Quadratic Q3(1, -8, 16);
		cout << Q3.toString();
		Quadratic Q4(4, 0, 0);
		cout << Q4.toString();
		Quadratic Q5(4, 0, 25);
		cout << Q5.toString();
		Quadratic Q6(0, 2, -7);
		cout << Q6.toString();
		Quadratic Q7(0, 0, -7);
		cout << Q7.toString();
		Quadratic Q8(2, 4, 0);
		cout << Q8.toString();
		Quadratic Q9(1, 1, 1);
		cout << Q9.toString();
		Quadratic Q10 = Q1 + Q2;
		cout << Q10.toString();
		Quadratic Q11 = 5 * Q1;
		cout << Q11.toString();
		Quadratic Q12 = Q2 - Q3;
		cout << Q12.toString();
		cout << Q1.Value(1) << endl;
		Quadratic Q13(0, 1, 2);
		Quadratic Q14 = Q13 + Q1;
		cout << Q14.toString();
		Quadratic Q15(0, 3, 4);
		cout << Q15.toString();
		Quadratic Q16 = Q13 + Q15;
		cout << "Q16 = Q13 + Q15" << endl;
		cout << Q16.toString();
		Quadratic Q17(0, -5, 0);
		cout << Q17.toString();
		Quadratic Q18(0, 6, 0);
		cout << Q18.toString();
		//GCD tests
		cout << "+++ GCD Tests+++++++++++++\n";
		int gcd1 = Quadratic::GCD(1, 2);
		cout << "GCD of 1, 2 = " << gcd1 << endl;
		int gcd2 = Quadratic::GCD(3, 6);
		cout << "GCD of 3, 6 = " << gcd2 << endl;
		int gcd3 = Quadratic::GCD(-12, 24);
		cout << "GCD of -12, 24 = " << gcd3 << endl;
		int gcd4 = Quadratic::GCD(-12, -24);
		cout << "GCD of -12, -24 = " << gcd4 << endl;
		int gcd5 = Quadratic::GCD(12, -24);
		cout << "GCD of 12, -24 = " << gcd5 << endl;
		cout << boolalpha;
		cout << (Q1 == Q11) << endl;
		cout << (Q1 == Q1) << endl;
		cout << (Q1 == Q2) << endl;

		cout << (Q1 != Q11) << endl;
		cout << (Q1 != Q1) << endl;
		cout << (Q1 != Q2) << endl;
	}
	catch (...)
	{
		cout << "An exception has been thrown. This will disappear when all class member function bodies are filled and throw statement is removed." << endl;
	}
	system("pause");

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
