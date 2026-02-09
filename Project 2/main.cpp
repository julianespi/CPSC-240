//commit from laptop
//commit from computer
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//1. All variables are short type
	short two = 2, four = 4;
	short drinksNum, sandsNum;
	short totalPrice;

	cout << "menu" << endl;
	cout << "Drinks............$2" << endl;
	cout << "sandwich.........$4" << endl;

	cout << "How many drinks?" << endl;
	cin >> drinksNum;
	cout << "How many sandwiches:" << endl;
	cin >> sandsNum;

	_asm
	{
		mov ax, drinksNum;	// ax = drinksNum
		imul ax, two; 		// ax = drinksNum * 2
		mov bx, 0; 			// bx = 0
		add bx, ax; 		// bx = 0 + drinksNum * 2
		mov ax, sandsNum; 	// ax = sandsNum
		imul ax, four; 		// ax = sandsNum * 4
		add bx, ax; 		// bx = drinks * 2 + sandsNum *4
		mov totalPrice, bx; // totalPrice = drinks * 2 + sandsNum *4
	}

	cout << "Your total bill $ " << totalPrice << endl;
	cout << endl << endl;

	//2. All sides are int type
	int a, b, c, h;
	int tArea, tPerimeter;
	int rWidth, rLength;
	int rArea, rPerimeter;
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> h;

	cout << endl;

	cout << "Enter the length and the width of the rectangle: ";
	cin >> rWidth;
	cin >> rLength;

	_asm
	{
		//Logic for triangle
		mov eax, c; 	// eax = c
		imul eax, h; 	// eax = c*h
		cdq;			// extend sign for division
		mov ebx, 2; 	// ebx = 2
		idiv ebx;		// eax/ebx = (c * h)/2
		mov tArea, eax; // tArea = eax/ebx 

		mov eax, a; 			// eax = a
		add eax, b; 			// eax = a + b 
		add eax, c;				// eax = a + b + c
		mov tPerimeter, eax; 	// tPerimeter  = eax

		//Logic for Rectangle
		mov eax, rWidth; 	// eax = rWidth
		imul eax, rLength;	// eax = rWidth * rLength
		mov rArea, eax; 	// rArea = eax

		mov eax, rWidth;		// eax = rWidth
		add eax, rLength;		// eax = rWidth + rLength
		imul eax, 2; 			// eax = 2*(width + length)
		mov rPerimeter, eax;	//rPerimeter = eax

	}

	cout << "Triangle" << endl;
	cout << "\tArea.........." << tArea << endl;
	cout << "\tPerimeter....." << tPerimeter << endl;
	cout << "Rectangle" << endl;
	cout << "\tArea.........." << rArea << endl;
	cout << "\tPerimeter....." << rPerimeter << endl;

	//3. Temperature Conversion
	short fahrenheitInput, celcius;

	cout << "Enter the temperature in Fahrenheit:";
	cin >> fahrenheitInput;

	_asm
	{
		mov ax, fahrenheitInput;	// ax = fahrenheitInput
		sub ax, 32;					// ax = fahrenheitInput - 32
		imul ax, 5;					// ax = 5 * (fahrenheitInput - 32)
		cwd;						// extend sign for division
		mov bx, 9;					// bx = 9
		idiv bx;					// ax = (5 * (fahrenheitInput - 32)) / 9
		mov celcius, ax;			// celcius = (5 * (fahrenheitInput - 32)) / 9
	}

	cout << fahrenheitInput << " F " << "is " << celcius << " C" << endl;

	//4. Adding Digits
	int num, d1, d2, d3, sum;

	cout << "Enter a 3 digit int number: " << endl;
	cin >> num;

	_asm
	{
		//Extract the hundreds digit and store it in d3.
		mov eax, num;	// eax = num
		mov ebx, 100;	// ebx = 100
		cdq;			// extend sign for division
		idiv ebx;		// eax = num/100
		mov d3, eax;	// eax = d3 

		// Retrieving the remainder of the hundreds digit
		mov eax, num;	// eax = num
		mov ebx, 100;	// ebx = 100
		cdq;			// extend sign for division
		idiv ebx;		// eax = eax/ebx
		imul eax, ebx;	// eax = eax * ebx
		mov edx, num;	// edx = num
		sub edx, eax;	// edx = edx - eax

		//Extract the tens digit and store it in d2.
		mov eax, edx;	// eax = edx
		mov ebx, 10;	// ebx = 10
		cdq;			// extend sign for division
		idiv ebx;		// eax = eax/10
		mov d2, eax;	// d2 = eax

		//Extract the ones digit and store it in d1.
		mov eax, edx;	// eax = edx
		mov ebx, 10;	// ebx = 10
		cdq;			// extend sign for division
		idiv ebx;		// eax = eax/ebx
		imul eax, ebx;	// eax = eax * ebx
		sub edx, eax;	// edx = edx - eax
		mov d1, edx;	// d1 = edx

		//Sum the digits.
		mov eax, d1;	// eax = d1
		add eax, d2;	// eax = eax + d2
		add eax, d3;	// eax = eax + d3
		mov sum, eax;	// sum = eax
	}

	cout << "The total of the digits in " << num << " is " << sum << endl;

	return 0;
}