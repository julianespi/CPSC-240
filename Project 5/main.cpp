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

int shirt[4][4] = { 10,20,30,40,20,10,40,30,5,15,20,25,30,25,20,15 };

void main1() 
{
	int allshirts = 0;
	int mShirts = 0;
	int bShirts = 0;
	int i = 0;

	_asm
	{
		lea esi, [shirt];	// esi holds address to shirts
		mov eax, 0;			//eax = 0 eax will hold our sum
	allforloop:
		cmp i, 16;			//if i =16
		je alldone;			//jmp to done

		add eax, [esi];		//eax = the value at address esi
		add esi, 4;			//add 4 to increment to the next index in the array
		//inc by 4 becasue int are 4 bytes

		inc i;				//inc the counter i

		jmp allforloop;		// jmp to the start of the loop
	alldone:
		mov allshirts, eax;	// move the sum in eax to the variable allshirts

		//restart address and eax for medium loop
		lea esi, [shirt];	// esi holds address to shirts
		mov eax, 0;			//eax = 0 eax will hold our sum
		mov i, 0;

		add esi, 4;

	mediumforloop:
		cmp i, 4;
		je mediumdone;

		add eax, [esi];
		add esi, 16;

		inc i;

		jmp mediumforloop;
	mediumdone:
		mov mShirts, eax;

		//restart address and eax for blue loop
		lea esi, [shirt];	// esi holds address to shirts
		mov eax, 0;			//eax = 0 eax will hold our sum
		mov i, 0;

		add esi, 32;

	blueforloop:
		cmp i, 4;
		je bluedone;
		
		add eax, [esi];		//eax = the value at address esi
		add esi, 4;			//add 4 to increment to the next index in the array
		inc i;

		jmp blueforloop;
	bluedone:
		mov bShirts, eax;
	}
	cout << allshirts << endl;
	cout << mShirts << endl;
	cout << bShirts << endl;
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