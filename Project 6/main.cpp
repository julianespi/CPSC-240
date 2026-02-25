#include <iostream>
using namespace std;

int main1();
int main2();


int main()
{
	main2();
}

int main1()
{
	float a, b, c, h;
	float tArea, tPerimeter;
	float length, width;
	float two = 2;

	double d = 20.1;

	cout << "Enter the values of a,b,c, and h for the triangle: ";
	cin >> a >> b >> c >> h;

	cout << "Enter the length and the width of the rectangle: ";
	cin >> length >> width;

	_asm
	{
		//find area and perimeter of tirangel and sqaure
		fld h;
		fld c;

		fmul;

		fld two;
		fdiv;

		fstp tArea;

		fld a;
		fld b;
		fld c;

		fadd;
		fadd;

		fstp tPerimeter;
	}

	cout << tArea;

	return 0;
}

int main2()
{

	float a = 2.1, b = 4.5, c = 1.7;
	float answer; 
	float four =4;
	_asm
	{
		fld b;
		fld b;

		fmul; //b^2

		fld four;
		fld a;
		fld c;

		fmul;
		fmul;
		fsub;

		fstp answer;


	}

	cout << answer;

	return 0;
}