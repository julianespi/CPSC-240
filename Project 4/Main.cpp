#include <iostream>
#include <iomanip>
using namespace std;

int main1();
int main2();
int main3();
int main4();
int main5();
int main6();

int main()
{
    //main1();
    //main2();
    //main3();
    //main4();
    //main5();
    main6();

    return 0;
}

//Question 1
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
}
//Q1 DONE

//Question 2
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
    cout << "Let's compute your score's average " << endl;

    _asm {
    scoreLoop:
        call readDataQ2;
        cmp score, -1;
        je checkZero;       //if the user enters -1, check if nothing else was entered
                            //before calculating the average.
        mov eax, score;		//eax=score
        add total, eax;		//total=total+score
        inc scoreCtr;		//scoreCtr++
        jmp scoreLoop;		//repeat loop

    checkZero:
        cmp scoreCtr, 0;    //check if the user entered any scores before typing -1
        je skipAvg;         //if not, skip the division to prevent a crash
        call calcAvg;       //otherwise, calculate the average

    skipAvg:
    }
}
//Q2 DONE

//Question 3
char c;
int upperCount = 0;
int lowerCount = 0;

void readCharacter() {
    c = cin.get();     //gets one character
}

int main3() {
    //this clears the buffer in case the enter key is stuck in the buffer from Q2,
    //which will result in Q3 not running.
    _asm {
    clearBuffer:
        call readCharacter;
        mov al, c;
        cmp al, 10;       //10 is the ASCII for the enter key
        jne clearBuffer;
    }

    cout << "Enter a sentence: ";

    _asm {
    charLoop:
        call readCharacter;
        mov al, c;           //al=c
        cmp al, '\n';
        je done;             //jump to done if c is the enter key

        //Here we will check if the character is between uppercase A-Z
        cmp al, 'A';
        jl checkLower;       //if ASCII value of c < ASCII value of A, it is
                             //not uppercase, so jump to check if it is lowercase.
        cmp al, 'Z';
        jg checkLower;       //if c is > Z, it is not uppercase, so jump to checkLower
        inc upperCount;      //otherwise, it is uppercase A-Z, so increment upperCount
        jmp charLoop;        //get the next character

    checkLower:
        //Here we will check if the character is between lowercase a-z
        cmp al, 'a';
        jl charLoop;         //if c < 'a', then c is not a letter, so get the next character
        cmp al, 'z';
        jg charLoop;         //if c > 'z', it is not a letter, so get next char
        inc lowerCount;      //otherwise, it is a lowercase letter, so increment lowerCount
        jmp charLoop;        //get the next character

    done:
    }

    cout << "No. of uppercase letters = " << upperCount << endl;
    cout << "No. of lowercase letters = " << lowerCount << endl;

    return 0;
}
//Q3 DONE

//Question 4 Part 1:
int main4() 
{
        short numOfPrinters = 0;
        short numOfFloppyDrives = 0;
        short sizeOfRam = 0;

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
        forLoop:					    //using for loop;
            cmp cx, ax;				    //compare cx (the counter) to ax the limit for the loop
            je done;				    // if cx == ax, break the loop

            inc cx;					//cx++
            add bx, 16;				//bx += 16
            jmp forLoop;			//restarts the for loop

        done:						//break

            mov sizeOfRam, bx;		//sizeOfRam = bx


        }

        cout << endl;
        cout << "The number of printers connected to the computer: " << numOfPrinters << endl;
        cout << "The number of floppy drives: " << numOfFloppyDrives << endl;
        cout << "The size of the RAM: " << sizeOfRam << " GB RAM" << endl;
}
//Q4 P1 done

void iseven()
{
    cout << " is a valid ID for the family" << endl;
}

void isOdd()
{
    cout << " is not a valid ID for the family" << endl;
}

void checkPIN(short pin, string name)
{
    short sum;              
    cout << name;           //This will be part of the output, e.g.: "BEEF is valid" where BEEF is name

    _asm
    {
        mov sum, 0;         //sum=0
        mov ax, pin;        //ax=pin. In binary, B=1011, E=1110, F=1111, so ax= 1011 1110 1110 1111.
        and ax, 0xF000;     //This masks everything except the first digit.
                            //We have 1011 1110 1110 1111 AND 1111 0000 0000 0000,
                            //so ax= 1011 0000 0000 0000

        shr ax, 12;         //ax= 0000 0000 0000 1011 = 11
        add sum, ax;        //sum=11

        mov ax, pin;        //ax=1011 1110 1110 1111
        and ax, 0x0F00;     //ax=0000 1110 0000 0000
        shr ax, 8;          //ax= 0000 0000 0000 1110 = 14
        add sum, ax;        //sum = 11+14= 25

        mov ax, pin;        //ax=1011 1110 1110 1111
        and ax, 0x00F0;     //ax=0000 0000 1110 0000
        shr ax, 4;          //ax= 0000 0000 0000 1110 = 14
        add sum, ax;        //sum=25+14= 39

        mov ax, pin;        //ax=1011 1110 1110 1111
        and ax, 0x000F;     //ax=0000 0000 0000 1111 = 15
        add sum, ax;        //sum=39+15= 54

        mov bx, 2;          //bx=2
        mov ax, sum;        //ax=54
        cwd;    
        idiv bx;            //dx:ax= 54/2 =27

        cmp dx, 0;          //check if the remainder is zero
        je even_label;      //if so, then the number is even. jump to even_label
        call isOdd;         //if the remainder is not zero, the number is odd. call isOdd.
        jmp done;           //ends the process if the number was odd

        even_label :
        call iseven;        //this is called if the number was even

            done : 
    }
}                           //now this will repeat for FADE and CABE

int main5()
{
    checkPIN(0xBEEF, "BEEF");
    checkPIN(0xFADE, "FADE");
    checkPIN(0xCABE, "CABE");

    return 0;
}
//Q4 DONE



//for Q5
short a, counter = 0;
short b[16];
void Base2()
{
    short x = 1 << 15, t, n = a;
    for (int i = 1; i <= 16; ++i)
    {
        t = n & x;
        if (t == 0)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
        if (i % 4 == 0)
        {
            cout << " ";
        }
        n = n << 1;
    }
    a = n; //save the original value of a
    cout << endl;
}

void displayArray()
{
    for (int i = 15; i >= 0; i--)
    {
        if (b[i] != 0)
        {
            cout << b[i] << " ";
        }
    }
}

//important note cl is the only regiester that can bit wise shifting
int main6()
{
    cout << "AX = ";
    _asm {
        //displays the regestier
        mov ax, 0110101000101111b;  //ax = 0110 1010 0010 1111
        mov a, ax;                  //a = 0110 1010 0010 1111
        call Base2;                 //displays the binary 

        lea esi, [b];               //esi = address of array b

        mov bx, 0000000000000001b;  //bx = 0000 0000 0000 0001 
        mov cl, 0;                  //cl = counter

    forloop:
        mov ax, 0110101000101111b;  //ax = 0110 1010 0010 1111
        cmp cl, 16;                 //if cl == 16
        jge done                    //jmp to done

        and ax, bx;                 //0110 1010 0010 1111 and bx(which will be shifted as the loop iterates)
        shr ax, cl;                 //the and result is shifted by the number of iterations
        shl bx, 1;                  //the bx is sifted to the left one time per iteration to prepare for the next and


        cmp ax, 0;                  //if ax = 0
        je isOff;                   //sprinkler is turned off.

        inc counter;                //counter++ for working sprinklers
        inc cl;                     //cl += 1

        jmp forLoop;

    isOff:
        //for evey iteration of the loop i need to multiply that by two to get the index of the array I want to add to
        //this works but not sure if movzx is a something the professor will allow
        movzx eax, cl;
        mov ch, cl;                 //ch = the counte cl
        inc ch;                     //ch ++ so that it represents the sprinklers not the index in the array
        mov[esi + eax * 2], ch;       //write to the index of the array that spot

        inc cl;                     //  cl += 1
        jmp forLoop;

    done:
    }

    cout << counter << " sprinklers are ON" << endl;
    cout << "Defective sprinklers: ";
    displayArray();

}
