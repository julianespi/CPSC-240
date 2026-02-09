//Julian Espinoza
//Sara Amintinat
#include <iostream>
using namespace std;

int main()
{
	short a, b, c, d, e, f;
	short X, Y;
	cout << "This program solves the system: " << endl;
	cout << "\taX + bY = c" << endl;
	cout << "\tdX + eY = f" << endl;

	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;

	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;

	_asm 
	{
		// solves for the numerator of Y
		mov ax, c;	//ax = c
		imul d;		//ax = c * d

		mov bx, ax;	//bx = c * d

		mov ax, a;	//ax = a
		imul f;		//ax = a * f

		sub ax, bx;	//ax = a * f - c * d
		
		//save for later
		mov cx, ax; //cx = a * f - c * d

		// solves for the denominator of Y
		mov ax, b;	//ax = b
		imul d;		//ax = b * d

		mov bx, ax;	//bx = b * d

		mov ax, a;	//ax = a
		imul e;		//ax = a * e

		sub ax, bx;	//ax = a * e - b * d

		//save for later
		mov bx, ax; //dx = a * f - c * d

		//solve for Y
		mov ax, cx;
		cwd;		//this cahnges any - to a zero
		idiv bx;	//so if it is zero it crashes here
		mov Y, ax;	//mov to y for display



		// solves for the numerator of X

		mov ax, b;	//ax = b
		imul f;		//ax = b * f

		mov bx, ax;	//bx = b * f

		mov ax, c;	//ax = c
		imul e;		//ax = c * e


		sub ax, bx;	//ax = c * e - b * f

		//save for later
		mov cx, ax; //cx = c * e - b * f

		// solves for the denominator of X
		mov ax, b;	//ax = b
		imul d;		//ax = b * d

		mov bx, ax;	//bx = b * d

		mov ax, a;	//ax = a
		imul e;		//ax = a * e

		sub ax, bx;	//ax = a * e - b * d

		//save for later
		mov bx, ax; //bx = a * e - b * d

		//solve for X
		mov ax, cx;	//ax = c * e - b * f
		cwd;		//expand for division 
		idiv bx;	//ax = c * e - b * f / a * e - b * d
		mov X, ax;	//mov to X for display

	}

	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;

	return 0;
}
