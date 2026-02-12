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

//For Q1
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

int main1()
{
    //Question 1
    cout << setfill('-') << setw(10) << ""
        << "7-11 Convenient Store"
        << setw(10) << "" << endl;
    cout << "Drinks" << endl;
    cout << "Soda(S)....................$2" << endl;
    cout << "Water(W)....................$1" << endl;
    cout << "Sandwiches" << endl;
    cout << "10 inches....................$3" << endl;
    cout << "12 inches....................$5" << endl;

    cout << "Enter the number of customers: ";
    cin >> customers;

    _asm {
    storeLoop:
        cmp customers, 0;
        je done; 				//if customers=0, jump to done
        call readData;
        mov bill, 0;			//clear the bill before calculating the next customer's bill
        cmp drinkType, 'W';
        je itIsWater;			//if W, jump to itIsWater
        cmp drinkType, 'S';
        je itIsSoda;			//if S, jump to itIsSoda

        //Water
    itIsWater:
        cmp sandType, 10;
        je itIs10; 				//in the case of W and 10 inch sandwich, jump to itIs10

        //In the case of Water and 12 inch sandwich
        mov eax, drinkNum; 		//eax=drinkNum
        imul eax, one; 			//eax=drinkNum * 1 (since water is one dollar)
        mov bill, eax; 			//bill=drinkNum * 1
        mov eax, sandNum; 		//eax=sandNum
        imul eax, five; 		//eax=sandNum * 5 (since a 12 inch sandwich is $5)
        add bill, eax; 			//bill=(drinkNum * 1) + (sandNum * 5)
        call totalBill;			//print the bill for this customer
        dec customers;			//their bill is complete; decrement one customer count
        jmp storeLoop;			//loop back to start

    itIs10:
        //Water and 10 inches
        mov eax, drinkNum; 		//eax=drinkNum
        imul eax, one; 			//eax=drinkNum * 1 (since Water is one dollar)
        mov bill, eax; 			//bill=drinkNum * 1
        mov eax, sandNum; 		//eax=sandNum
        imul eax, three; 		//eax=sandNum * 3 (since a 10 inch sandwich is $3)
        add bill, eax; 			//bill=(drinkNum * 1) + (sandNum * 3)
        call totalBill;			//print the bill for this customer
        dec customers;			//their bill is complete; decrement one customer count
        jmp storeLoop;			//loop back to the start

        //Soda
    itIsSoda:
        cmp sandType, 10;
        je itIs10Soda; 			//in the case of S and 10 inch sandwich, jump to itIs10

        //In the case of Soda and 12 inch sandwich
        mov eax, drinkNum; 		//eax=drinkNum
        imul eax, two; 			//eax=drinkNum * 2 (since soda is $2)
        mov bill, eax; 			//bill=drinkNum * 2
        mov eax, sandNum; 		//eax=sandNum
        imul eax, five; 		//eax=sandNum * 5 (since a 12 inch sandwich is $5)
        add bill, eax; 			//bill=(drinkNum * 2) + (sandNum * 5)
        call totalBill;			//print the bill for this customer
        dec customers;			//their bill is complete; decrement one customer count
        jmp storeLoop;			//loop back to the start

    itIs10Soda:
        //Soda and 10 inches
        mov eax, drinkNum; 		//eax=drinkNum
        imul eax, two; 			//eax=drinkNum * 2 (since soda is $2)
        mov bill, eax; 			//bill=drinkNum * 2
        mov eax, sandNum;		//eax=sandNum
        imul eax, three; 		//eax=sandNum * 3 (since a 10 inch sandwich is $3)
        add bill, eax; 			//bill=(drinkNum * 2) + (sandNum * 3)
        call totalBill;			//print the bill for this customer
        dec customers;			//their bill is complete; decrement one customer count
        jmp storeLoop;			//loop back to the start

    done:
    }
    return 0;
}

//For Q2
int scoreCtr = 0;
int avg;
int total = 0;
int score;

void readDataQ2() {
    cout << "Enter a score (-1) to stop: ";
    cin >> score;
    cout << endl;
}

void calcAvg() {
    avg = total / scoreCtr;
    cout << "Your average is: " << avg << endl;
}

int main2() {
    //Question 2
    cout << "Let's compute your score's average: ";

    _asm {
    scoreLoop:
        call readDataQ2;
        cmp score, -1;
        je done;			//if -1 is entered, jump to done
        mov eax, score;		//eax=score
        add total, eax;		//total=total+score
        inc scoreCtr;		//scoreCtr++
        jmp scoreLoop;		//repeat loop

    done:
        call calcAvg;
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
