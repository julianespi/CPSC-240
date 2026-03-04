#include <iostream>
#include <iomanip>
using namespace std;

void main1();
void getInfo();
void main2();

int main()
{
	main1();
	main2();
}

string name;
int age;
char gender;
float fee;
char option;
float mAdult = 3.75, mTeen = 17.20, mChild = 3.10;
float fAdult = 2.10, fTeen = 06.15, fChild = 4.00;


void getInfo()
{
	cout << "what is your name? ";
	cin >> name;

	cout << name << ", enter your age and gender: ";
	cin >> age >> gender;
	cout << endl;
}

void getChoice()
{
	cout << "CONTINUE(y/n)? ";
	cin >> option;
	cout << endl;
}

void getBill()
{
	cout << fixed << setprecision(2) << endl;
	cout << name << ", your membership is " << fee << endl;
}

void main1()
{
	cout << "------------24 / 7 SPORTS CLUB---------" << endl;
	cout << "Adults(age >= 20)" << endl;
	cout << "\tMale................3.75" << endl;
	cout << "\tFemale..............2.10" << endl;
	cout << "Teenagers(13 <= age <= 19)" << endl;
	cout << "\tMale................17.20" << endl;
	cout << "\tFemale..............6.15" << endl;
	cout << "Children(age <= 12)" << endl;
	cout << "\tMale................3.10" << endl;
	cout << "\tFemale..............4.00" << endl;

	_asm
	{

	loop1:
		
		call getInfo;

		cmp gender, 'm';
		je male;

		cmp gender, 'M';
		je male;

		cmp gender, 'f';
		je female;

		cmp gender, 'F';
		je female;

	male:
		cmp age, 13;
		jl mchild;

		cmp age, 20;
		jl mteen;

	madult:
		fild age;
		fld mAdult;
		fmul;
 		fstp fee;
		jmp choice;
	mteen:
		fild age;
		fld mTeen;
		fmul;
		fstp fee;
		jmp choice;
	mchild:
		fild age;
		fld mChild;
		fmul;
		fstp fee;
		jmp choice;

	//split 


	female:
		cmp age, 13;
		jl fchild;

		cmp age, 20;
		jl fteen;

	fadult:
		fild age;
		fld fAdult;
		fmul;
		fstp fee;
		jmp choice;
	fteen:
		fild age;
		fld fTeen;
		fmul;
		fstp fee;
		jmp choice;
	fchild:
		fild age;
		fld fChild;
		fmul;
		fstp fee;
		jmp choice;


	choice:
		call getBill;
		call getChoice;

		cmp option, 'y';
		je loop1;

		cmp option, 'Y';
		je loop1;

		cmp option, 'n';
		je done1;

		cmp option, 'N';
		je done1;

		jmp loop1;

	done1:
		
	}
}

float cylinderRadius, cylinderHeight, cylinderSurface, cylinderVolume;
float a, b, c, cubeSurface, cubeVolume;
float two = 2;

void getCylinder()
{
	cout << "Enter the values of radius and height: ";
	cin >> cylinderRadius >> cylinderHeight;
}

void getCylinderResults()
{	
	cout << fixed << setprecision(2) << endl;
	cout << "\tSurface Area = " << cylinderSurface << endl;
	cout << "\tVolume = " << cylinderVolume << endl;
}

void getCube()
{
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
}

void getCubeResults()
{
	cout << fixed << setprecision(2) << endl;
	cout << "\tSurface Area = " << cubeSurface << endl;
	cout << "\tVolume = " << cubeSurface << endl;
}

void main2()
{	
	_asm
	{
	call getCylinder;
	
	//clyinder surface area
	fld cylinderHeight;
	fld cylinderRadius;
	fldpi;
	fld two;

	fmul;
	fmul;
	fmul;
	fstp cylinderSurface;

	//clyinder volume
	fld cylinderRadius;
	fld cylinderRadius;
	fmul;

	fldpi;
	fld cylinderHeight;
	fmul;
	fmul;

	fstp cylinderVolume;

	call getCylinderResults;

	call getCube;


	//cube surface
	fld a
	fld b
	fmul;	//ab
	fld two
	fmul;	//2ab

	fld a
	fld c
	fmul;	//ac
	fld two
	fmul;	//2ac
	fadd;	//2ab + 2ac

	fld b
	fld c
	fmul;	//bc
	fld two
	fmul;	//2bc
	fadd;	//2ab + 2ac + 2bc

	fstp cubeSurface;

	fld a;
	fld b;
	fld c;

	fmul;
	fmul;

	fstp cubeVolume;

	call getCubeResults;

	}



}