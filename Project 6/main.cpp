#include <iostream>
#include <iomanip>
using namespace std;

int main1();
int main2();

int main() {
	//main1();
	main2();
}

//Question 1
float triArea, triPerim, rectArea, rectPerim;
float a, b, c, d, h;
float two = 2;
float rectLength;
float rectWidth;

void readData() {
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> rectLength >> rectWidth;
}

int main1() {

	_asm {
    call readData;           

    //Rectangle area
    fld rectLength;          //push rect length onto stack
    fld rectWidth;           //push rect width onto stack
    fmul;                    //multiply top two values on stack
    fstp rectArea;           //pop result from stack to rect area

    //Rectangle perimeter
    fld rectLength;          //push rect length onto stack
    fld two;                 //push 2 onto stack
    fmul;                    //multiply top two (2*length)
    fld rectWidth;           //push rect width onto stack
    fld two;                 //push 2 onto stack
    fmul;                    //multiply top two (2*width)
    fadd;                    //add top two values on stack (2*length + 2*width)
    fstp rectPerim;          //pop result from stack to rect perimeter

    //Triangle area
    fld c;                   //push base onto stack
    fld h;                   //push height onto stack
    fmul;                    //multiply them
    fld two;                 //push 2 onto stack
    fdiv;                    //divide by 2 (base*height / 2)
    fstp triArea;            //pop result from stack to triangle area

    //Triangle perimeter
    fld a;                   //push side a onto stack
    fld b;                   //push side b onto stack
    fadd;                    //add top two values on stack (a + b)
    fld c;                   //push side c onto stack
    fadd;                    //add top two values on stack (a + b + c)
    fstp triPerim;           //pop result from stack to triangle perimeter
	}

	cout << "  Triangle " << endl;
	cout << fixed << setprecision(2);
	cout << "        Area............ " << triArea << endl;
	cout << "        Perimeter......." << triPerim << endl; 

	cout << "  Rectangle " << endl;
	cout << "        Area............ " << rectArea << endl;
	cout << "        Perimeter......." << rectPerim << endl;
}
//Q1 DONE

//Question 2
int main2()
{

	float a, b, c;
	float x2; 
	float x1;
	float two = 2;
	float four = 4;
	float neg = -1;

	cout << "To see the two real roots of aX^2+ bX + c=0, enter the a,b, and c values:  ";
	cin >> a >> b >> c;
	_asm
	{
		// calculate x2
		fld b;		//b
		fld neg;	//-1 b

		fmul;

		fld b;		//b -b
		fld b;		//b b -b

		fmul;		//b^2 -b

		fld four;	//4 b^2 -b 
		fld a;		//a 4 b^2 -b
		fld c;		//c a 4 b^2 -b

		fmul;		//ac 4 b^2 -b 
		fmul;		//4ac b^2 -b
		fsub;		//b^2-4ac -b

		fsqrt;		//\sqrt{b^2 - 4ac} -b

		fld neg;	//-1 \sqrt{b^2 - 4ac} -b

		fmul;		//-\sqrt{b^2 - 4ac} -b

		fadd;		//-b-\sqrt{b^2 - 4ac}

		fld two;	//2 -b-\sqrt{b^2 - 4ac}

		fld a;		//a 2 -b-\sqrt{b^2 - 4ac}

		fmul;		//2a -b-\sqrt{b^2 - 4ac}

		fdiv;		//(-b-\sqrt{b^2 - 4ac})/(2a)

		fstp x2;	//x2 = (-b-\sqrt{b^2 - 4ac})/(2a)

		//calculate x1

		fld b;		//b
		fld neg;	// -1 b

		fmul;

		fld b;		//b -b
		fld b;		//b b -b

		fmul;		//b^2 -b

		fld four;	// 4 b^2 -b 
		fld a;		// a 4 b^2 -b
		fld c;		// c a 4 b^2 -b

		fmul;		//ac 4 b^2 -b 
		fmul;		//4ac b^2 -b
		fsub;		//b^2-4ac -b

		fsqrt;		//\sqrt{b^2-4ac} -b

		fadd;		//-b+\sqrt{b^2-4ac}

		fld two;	//2 -b+\sqrt{b^2 - 4ac}

		fld a;		//a 2 -b+\sqrt{b^2 - 4ac}

		fmul;		//2a -b+\sqrt{b^2 - 4ac}

		fdiv;		//(-b+\sqrt{b^2 - 4ac})/(2a)

		fstp x1;	//x2 = (-b+\sqrt{b^2 - 4ac})/(2a)


	}

	cout << fixed << setprecision(2) << endl;
	cout << "X1: " << x1 << "  X2: " << x2 << endl;

	return 0;
}
