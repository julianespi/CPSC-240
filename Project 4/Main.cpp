#include <iostream>
using namespace std;

void main1();
void main2();
void main3();
void main4();


int main()
{
	main1();

	//main2();
	//main3();

	cout << endl << endl << "Problem 4" << endl;
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
	int bill =0;
	
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
		// number of printers
		mov ax, 1100111010011100b;	//ax = 1100 1110 1001 1100
		mov bx, 1100000000000000b;	//bx = 1100 0000 0000 0000
		and ax, bx;					//ax = 1100 1110 1001 1100 AND 1100 0000 0000 0000
		shr ax, 14;					//ax = 1100 0000 0000 0000 shifted to 0000 0000 0000 0011
		mov numOfPrinters, ax;		//numOfPrinters = 0000 0000 0000 0011 = 3



		//number of floppy drives
		mov ax, 1100111010011100b;	//ax = 1100 1110 1001 1100
		mov bx, 0000000011000000b;	//bx = 0000 0000 1100 0000
		and ax, bx;					//ax = 1100 1110 1001 1100 AND 0000 0000 1100 0000
		shr ax, 6;					//ax = 0000 0000 1000 0000 shifted to 0000 0000 0000 0010
		inc ax;						//ax = 0000 0000 0000 0010 + 1 = 2 + 1; 
		mov numOfFloppyDrives, ax;	//numOfFloppyDirves = ax

		//size of ram
		mov ax, 1100111010011100b;	//ax = 1100 1110 1001 1100
		mov bx, 0000000000001100b;	//bx = 0000 0000 0000 1100
		and ax, bx;					//ax = 1100 1110 1001 1100 AND 0000 0000 0000 1100
		shr ax, 2;					//ax = 0000 0000 0000 1100 shifted to 0000 0000 0000 0011
		mov cx, 0;					//cx = 0 will be used as loop counter
		mov bx, 16;					//bx will hold the sum of ram
		forLoop:					//using for loop;
			cmp cx, ax;				//compare cx (the counter) to ax the limit for the loop
			je done;				// if cs == ax break loop

			inc cx;					//cx++
			add bx, 16;				//bx += 16
			jmp forLoop;			//restarts the for loop

		done:						//break
			
		mov sizeOfRam, bx;			//sizeOfRam = bx

		
	}

	cout << "The number of printers connected to the computer: " << numOfPrinters << endl;
	cout << "The number of floppy drives: " << numOfFloppyDrives << endl;
	cout << "The size of the RAM: " << sizeOfRam << " GB RAM" << endl;
	
}
