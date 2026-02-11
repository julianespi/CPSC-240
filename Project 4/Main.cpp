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

//Q1
int loopCounter;
int customers;
int drinkNum;
char drinkType;
int sandType;
int sandNum;
int bill = 0, one = 1, three = 3, five = 5, two = 2;

void readData() {
    cout << "How many drinks? ";
    cin >> drinkNum;
    cout << "What kind of drink(S=Soda, W=Water)? ";
    cin >> drinkType;
    cout << "How many sandwiches? ";
    cin >> sandNum;
    cout << "What size of sandwich (10/12 inches)? ";
    cin >> sandType;
}

void totalBill() {
    cout << endl;
    cout << "Bill: " << bill << endl;
}

//Q1 int main()
void main1()
{

    cout << setfill('-') << setw(10) << " " << "7-11 Convenient Store" << " " << setfill('-') << setw(10) << endl;
    cout << "Drinks" << endl;
    cout << "Soda(S)....................$2" << endl;
    cout << "Water(W)....................$1" << endl;
    cout << "Sandwiches" << endl;
    cout << "10 inches....................$3" << endl;
    cout << "12 inches....................$5" << endl;

    cout << "Enter the number of customers: ";
    cin >> customers;

    _asm {

        //Input: 1 customer, 1 drink, w or s,  1 sandwich, 10 o4 12 inches

    storeLoop:
        cmp customers, 0;
        je done;
        call readData;
        mov bill, 0;
        cmp drinkType, 'W';
        je itIsWater;
        cmp drinkType, 'S';
        je itIsSoda;

        //water
    itIsWater:
        cmp sandType, 10;
        je itIs10; //jump to itis10 if it is water and 10 inches

        //water and 12 inches

        mov eax, drinkNum; //if its 12, put 1 into eax for 1 drink
        imul eax, one; //multiply 1 times 1 bc 1 water and it costs a dollar(one)
        mov bill, eax; // move the drink cost, so 1, into bill. bill = 1
        mov eax, sandNum; // move 1, sandnum, into eax
        imul eax, five; //multiply sandnum by the cost of a sandwich 12 inch, so in this case its 5
        add bill, eax; //we add 5 to the bill. so now the bill is 5+1=6
        //eax has the bill
        call totalBill;
        dec customers;
        jmp storeLoop;

    itIs10:
        //water and 10 inches
        mov eax, drinkNum; // if its 10, put 1 into eax for 1 drink
        imul eax, one; //multiply 1 times 1 bc 1 water costs a dollar(one)
        mov bill, eax; //bill=1
        mov eax, sandNum; // mov 1, sandnum, into eax
        imul eax, three; // multiply sandnum by the cost of a 10 inch sandwich, in this case its 3
        add bill, eax; // we add 3 to the bill so now its 3+1=4
        call totalBill;
        dec customers;
        jmp storeLoop;


        //soda
    itIsSoda:
        cmp sandType, 10;
        je itIs10Soda; //jump to itis10 if it is soda and 10 inches

        //soda and 12 inches

        mov eax, drinkNum; //if its 12 inches, put 1 into eax for 1 drink
        imul eax, two; //multiply 1 times 2 bc one soda and it costs two dolla(two)
        mov bill, eax; // move the drink cost, so 2, into bill. bill = 2
        mov eax, sandNum; // move 1, sandnum, into eax
        imul eax, five; //multiply sandnum by the cost of a sandwich 12 inch, so in this case its 5
        add bill, eax; //we add 5 to the bill. so now the bill is 5+2=7
        call totalBill;
        dec customers;
        jmp storeLoop;

    itIs10Soda:
        //water and 10 inches
        mov eax, drinkNum; // if its 10, put 1 into eax for 1 drink
        imul eax, two; //multiply 1 times 2 bc 1 soda and it cost two dollars (two)
        mov bill, eax; //bill=2
        mov eax, sandNum; // mov 1, sandnum, into eax
        imul eax, three; // multiply sandnum by the cost of a 10 inch sandwich, in this case its 3
        add bill, eax; // we add 3 to the bill so now its 3+2=5
        call totalBill;
        dec customers;
        jmp storeLoop;


    done:
      
    }
    return 0;
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
