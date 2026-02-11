#include <iostream>

using namespace std;



//used in question 4
int main()
{
	//Question 1




	//Question 2

	//Question 3

	//Question 4
	short numOfPrinters= 0;
	short numOfFloppyDrives = 0;
	short sizeOfRam =0;
	_asm 
	{
		//00 = 0, 01, = 1, 10, =2
		// number of printers
		mov ax, 1100111010011100b;
		mov bx, 1100000000000000b;
		and ax, bx;
		shr ax, 14;
		mov numOfPrinters, ax;



		//number of floppy drives
		mov ax, 1100111010011100b;
		mov bx, 0000000011000000b;
		and ax, bx;
		shr ax, 6;
		inc ax;
		mov numOfFloppyDrives, ax;

		//add increments of 16
		//size of ram
		mov ax, 1100111010011100b;
		mov bx, 0000000000001100b;
		and ax, bx;
		shr ax, 2;
		mov cx, 0;
		mov bx, 16;
		forLoop: //using for loop;
			cmp cx, ax;
			je done;

			inc cx;
			add bx, 16;
			jmp forLoop;

		done:
			
		mov sizeOfRam, bx;

		
	}

	cout << numOfPrinters << endl;
	cout << numOfFloppyDrives << endl;
	cout << sizeOfRam << endl;


	return 0;
}