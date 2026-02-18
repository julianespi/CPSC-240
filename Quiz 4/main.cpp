#include <iostream>
using namespace std;

int main()
{
	short counter = 0;
	short doorsOpen = 0;

	_asm
	{
		mov bx, 0000000000000001b;
		mov cl, 0;
	forloop:
		mov ax, 1010111110111011b;
		and ax, bx;

		shl bx, 1;
		shr ax, cl;

		inc cl;

		cmp ax, 1;
		je isOne;

		cmp cl, 16;
		jge doorsCount;

		jmp forloop;

	isone:
		inc counter;
		jmp forloop;

	doorsCount:
		mov ax, 1010111110111011b;
		mov bx, 0000000001111000b;
		and ax, bx;
		shr ax, 3;
		mov doorsOpen, ax;


	}

	cout << counter << endl;
	cout << doorsOpen << endl;

	return 0;
}