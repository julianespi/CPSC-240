#include <iostream>
using namespace std;

void isequal()
{
	cout << "is eqaul" << endl;
}

void isnotequal()
{
	cout << "is not equal" << endl;
}

int main()
{
	int a[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int allsum = 0, diagonal1 = 0, diagonals2 = 0;
	int i = 0;

	_asm
	{
		lea esi, [a];
		mov eax, 0;

	allloop:
		cmp i, 16;
		je alldone;

		add eax, [esi];
		add esi, 4;

		inc i;
		jmp allloop;
		
	alldone:
		mov allsum, eax;

		lea esi, [a];
		mov eax, 0;
		mov i, 0;


	diagonal1loop:
		cmp i, 4;
		je diagonal1done;

		add eax, [esi];
		add esi, 20;

		inc i;
		jmp diagonal1loop;

	diagonal1done:
		mov diagonal1, eax;

		lea esi, [a];
		mov eax, 0;
		mov i, 0;
		add esi, 12;

	diagonals2loop:
		cmp i, 4;
		je diagonals2done;

		add eax, [esi];
		add esi, 12;

		inc i;
		jmp diagonals2loop;

	diagonals2done:

		mov diagonals2, eax;


		cmp diagonal1, eax;
		je isEqual;

	isNotEqual:
		call isnotequal;
		jmp done;

	isEqual:
		call isequal;
		jmp done;


	done:




	}

	cout << allsum << endl;
	cout << diagonal1 << endl;
	cout << diagonals2 << endl;

	return 0;
}