#include <iostream>
using namespace std;

short n;
short onCounter = 0;
short frontOn, backOn;

int main1();
void Base2();
void displayOnCounter();
void frontIsMore();
void backIsMore();

int main2();


int main()
{
	main1();
	cout << endl;
	main2();
}



int main1()
{


	_asm
	{
		mov bx, 0000000000000001b;
		mov cl, 0;

	loop1:
		mov ax, 1100111111011100b;
		cmp cl, 16;
		je done1;

		and ax, bx;
		shr ax, cl;
		shl bx, 1;
		inc cl;

		cmp ax, 0000000000000001b;
		je isBitOn;

		
		jmp loop1;


	isBitOn:
		inc onCounter;
		jmp loop1;

	done1:

		call displayOnCounter;

		mov ax, 1100111111011100b;
		mov bx, 1111111100111111b;

		and ax, bx;

		mov n, ax;
		call Base2;

	done2:

		mov ax, 1100111111011100b;
		mov bx, 0000000000011100b;

		and ax, bx;
		shr ax, 2;
		mov frontOn, ax;

		mov ax, 1100111111011100b;
		mov bx, 0111000000000000b;

		and ax, bx;
		shr ax, 12;

		cmp frontOn, ax;
		jl backMore;

	frontMore:
		call frontIsMore;
		jmp alldone;

	backMore:
		call backIsMore;


	alldone:

	}
}

void displayOnCounter()
{
	cout << onCounter << endl;

}

void Base2()
{
	short x = 1 << 15, t;
	for (int i = 1; i <= 16; ++i)
	{
		 t = n & x;
		 if (t == 0) cout << 0;
		 else cout << 1;
		 if (i % 4 == 0) cout << " ";
		 n = n << 1;
	}
  cout << endl;
} // end of Base2

void frontIsMore()
{
	cout << "Front uses more water" << endl;
}

void backIsMore()
{
	cout << "back uses more water" << endl;
}

int students[4][3] = { 33,31,20,18,23,22,23,31,10,20,30,40 };
int freshman, sophmore, junior, senior;
int i = 0;
int main2()
{

	_asm
	{
		lea esi, [students];
		mov eax, 0;
	floop:
		cmp i, 3;
		je fdone;

		add eax, [esi];
		add esi, 16;

		inc i;
		jmp floop;
	fdone:
		mov freshman, eax;

		lea esi, [students];
		mov eax, 0;
		mov i, 0;

		add esi, 4;
	soloop:
		cmp i, 4;
		je sodone;

		add eax, [esi];
		add esi, 16;

		inc i;
		jmp soloop;
	sodone:
		mov sophmore, eax;

		lea esi, [students];
		mov eax, 0;
		mov i, 0;

		add esi, 8;
	jloop:
		cmp i, 8;
		je jdone;

		add eax, [esi];
		add esi, 16;

		inc i;
		jmp jloop;
	jdone:
		mov junior, eax;

		lea esi, [students];
		mov eax, 0;
		mov i, 0;

		add esi, 12;
	sloop:
		cmp i, 8;
		je sdone;

		add eax, [esi];
		add esi, 16;

		inc i;
		jmp sloop;
	sdone:
		mov senior, eax;



	}

	cout << freshman << endl;
	cout << sophmore << endl;
	cout << junior << endl;
	cout << senior << endl;
}