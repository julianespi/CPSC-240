#include <iostream>
using namespace std;

void main1();
void main2();
void main3();
void main4();


int main()
{
	main1();
	main2();
	main3();
	main4();

	return 0;
}

void main1()
{
	//Question 1
	int customers;
	int drinks;
	char kindOfDrink;
	int sandwiches;
	int sandwichesSize;
	int bill;
	
	cout << "----------------------7-11 Convenient Store ----------------------" << endl;
	cout << "Drinks" << endl;
	cout << "  Soda(S)…………………………………………….…$2" << endl;
	cout << "  Water(W)………………………………………….…$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "  10 inches……………………………………………..$3" << endl;
	cout << "  12 inches……………………………………………..$5" << endl;

	cout << "Enter the number of customers" << endl;
	cin >> customers;
	cout << "How many drinks?" << endl;
	cin >> drinks;
	cout << "What kind of drink(S=Soda, W=Water)?" << endl;
	cin >> kindOfDrink;
	cout << "How many sandwiches?" << endl;
	cin >> sandwiches;
	cout << "What size of sandwich (10/12 inches)?" << endl;
	cin >> sandwichesSize;
	cout << "Your total bill= " << bill << endl;
}

void main4()
{
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
	
}
