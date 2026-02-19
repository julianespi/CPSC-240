#include <iostream>
using namespace std;

void main1();
void main2();
void main3();

int main()
{
	main1();
	main2();
	main3();

	return 0;
}

short shirt[4][4] = {	{10,20,30,40}, 
						{20,10,40,30}, 
						{ 5,15,20,25}, 
						{30,25,20,15} };

void main1() 
{
	short allshirts = 0;
	short mShirts = 0;
	short bShirts = 0;
	short i = 0;

	_asm
	{
		lea esi, [shirt];
		mov ax, 0;
	forloop:
		cmp i, 16;
		je done;
		add ax, 

		jmp forloop;
	done:

	}

}

int a[5] = { 9,3,22,8,1 };

void main2()
{

}

int shirts2[3][3][2] = {	{ { 1, 2},{ 3, 4},{ 5, 6} },
							{ { 7, 8},{ 9,10},{11,12} },
							{ {13,14},{15,16},{17,18} } };

void main3()
{

}