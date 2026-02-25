#include <iomanip>
using namespace std;

int main1();
int main2();

int main() {
	main1();
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
		fld rectLength;
		fld rectWidth;
		fmul;
		fstp rectArea;

		//Rectangle perimeter
		fld rectLength;
		fld two;
		fmul;
		fld rectWidth;
		fld two;
		fmul;
		fadd;
		fstp rectPerim;

		//Triangle area
		fld c;
		fld h;
		fmul;
		fld two;
		fdiv;
		fstp triArea;

		//Triangle perimeter
		fld a;
		fld b;
		fadd;
		fld c;
		fadd;
		fstp triPerim;
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
