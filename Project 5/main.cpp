#include <iostream>
using namespace std;

int main1();
//int main2();
//int main3();

int main() {
	main1();
	//main2();
	//main3();
	return 0;
}

//Question 1
int shirt[4][4] = { 
	{10, 20, 30, 40},	// Red row 
	{20, 10, 40, 30},	// Green row 
	{5, 15, 20, 25},	// Blue row 
	{30, 25, 20, 15}	// Black row 
	};					//4 rows, 4 cols

int main1()
{
	int allShirts = 0;
	int mShirts = 0;
	int bShirts = 0;
	int i = 0;

	_asm
	{
		//all shirts
		lea esi, [shirt];	//esi = memory address of shirt[0][0] (esi is our pointer walking through the array)
		mov eax, 0;			//eax = 0. eax will hold our sum (running total of all shirts being added)
	allforloop:
		cmp i, 16;			
		je alldone;			//if i = 16, jmp to done

		add eax, [esi];		//add current element. on the first iteration it will be eax = eax + 10
							//since shirt[0][0] = 10.
		add esi, 4;			//move 4 bytes forward to access the next int in memory

		inc i;				//inc the counter i

		jmp allforloop;		//jmp to the start of the loop
	alldone:
		mov allShirts, eax;	//move the sum in eax to the variable allShirts
		//all shirts done

		//medium shirts
		//restart address and eax for medium loop
		lea esi, [shirt];	//esi = memory address of shirt[0][0]
		mov eax, 0;			//eax = 0. eax will hold our sum
		mov i, 0;			//i=0 (i is our counter)

		add esi, 4;			//this moves it to the first medium shirt (shirt[0][1]).
							//now that we are in the correct column, we will loop through this Medium column only.
							//we will check shirt[0][1], shirt [1][1], shirt[2][1] and shirt[3][1].
	mediumforloop:
		cmp i, 4;			
		je mediumdone;		//there are only 4 medium shirts, one for each color. we start at i=0
							//and go to i=3. once i=4, jump to mediumdone.

		add eax, [esi];		//eax = [esi] + eax. adds current element to running total.
		add esi, 16;		//move 4 elements (16 bytes) forward to get from shirt[0][1] to shirt[1][1] etc.

		inc i;				//increment counter

		jmp mediumforloop;
	mediumdone:
		mov mShirts, eax;	//move the sum in eax into mShirts
		//medium shirts done

		//blue shirts
		//restart address and eax for blue loop
		lea esi, [shirt];	//esi=shirt[0][0]
		mov eax, 0;			//eax = 0. eax will hold our sum
		mov i, 0;			//i=0 (i is our counter)

		add esi, 32;		//there are two rows before the blue row, each 16 bytes. so we move
							//32 bytes forward from shirt[0][0] to get to the blue row.

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
	//blue shirts done

	cout << "Number of all shirts: " << allShirts << endl;
	cout << "Number of Medium shirts: " << mShirts << endl;
	cout << "Number of blue shirts: " << bShirts << endl;
	return 0;
}
//Q1 DONE

//Question 2
//I need to add comments still
int main2() {
		int a[5] = {9, 3, 22, 8, 1}; 
		int n = 5; 

		cout << "Original array a: "; 
		for (int i = 0; i < n; i++) { 
			cout << a[i] << " ";     
		} 

		_asm {
			mov ecx, n;
			dec ecx; 
			mov eax, 0; 

		outerloop:
			cmp eax, ecx;
			jge donesorting; 
			mov ebx, 0; 

		innerloop: 
			cmp ebx, ecx; 
			jge nextouter; 
			mov edx, [a + ebx * 4]; 
			mov esi, [a + ebx * 4 + 4]; 
			cmp edx, esi; 
			jle noswap; 
			mov[a + ebx * 4], esi;
			mov[a + ebx * 4 + 4], edx; 

		noswap: 
			inc ebx; 
			jmp innerloop; 

		nextouter: 
			inc eax; 
			jmp outerloop; 

		donesorting: 
		}

		cout << endl;
		cout << "Sorted array a: "; 
		for (int i = 0; i < n; i++) { 
			cout << a[i] << " ";      
		}
		cout << endl;                
		return 0; 
	}
