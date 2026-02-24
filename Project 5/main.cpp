#include <iostream>
using namespace std;

int main1();
int main2();
int main3();

int main() {
	main1();
	main2();
	main3();
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
	cout << endl;
	return 0;
}
//Q1 DONE

//Question 2
int main2() {
	int a[5] = { 9, 3, 22, 8, 1 }; 		//the given array
	int n = 5; 							//array size

	cout << "Original array a: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";     		//prints out every element of the given array
	}

	_asm {
		mov ecx, n;						//ecx= n = 5 
		dec ecx; 						//ecx = 4 because bubble sort only needs n-1 comparisons per pass
		mov eax, 0; 					//eax=0 (outer loop counter counts # of passes)

	outerloop:
		cmp eax, ecx;					//check if we have done 4 passes	
		jge donesorting; 				//if so, jump to donesorting
		mov ebx, 0; 					//ebx=0 (inner loop counter for pair comparisons)

	innerloop:
		cmp ebx, ecx;
		jge nextouter; 					//if ebx >= ecx, jump to nextouter since pair comparisons are done
		mov edx, [a + ebx * 4]; 		//finding the first element for our current comparison
		mov esi, [a + ebx * 4 + 4]; 	//finding the second element for our current comparison
		cmp edx, esi;
		jle noswap; 					//if the first element <= second element, do not swap
		mov[a + ebx * 4], esi;			//otherwise, move esi (smaller #) to first position
		mov[a + ebx * 4 + 4], edx; 		//move edx (larger #) to second position

	noswap:
		inc ebx; 						//move onto next pair 
		jmp innerloop;

	nextouter:
		inc eax; 						//eax++ because we have completed a full pass
		jmp outerloop; 					//starts the next pass

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
//Q2 DONE

//Question 3
int a[3][3][2] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};

int main3()
{
	int allShirts = 0;	
	int mShirts = 0;	
	int sShirts = 0;	
	int rshirts = 0;	
	int i = 0;			//counter for loop iterations

	_asm
	{
		//total shirts and short sleeves
		lea esi, [a];	//esi=address of first element a[0][0][0]
		mov ebx, 0;	//ebx=0

	allforloop:
		cmp i, 18;
		je alldone;	//if i=18, jump to alldone since there are 18 elements

		mov eax, i;	//eax=i (current index)
		cdq;
		mov ecx, 2;	//ecx = 2
		idiv ecx;	//eax = quotient, edx = remainder (0 means even, 1 means odd)

		inc i;		//one element covered, so increment i
		cmp edx, 0;	//check remainder from division to see if i is odd or even
		je alloddloop;	//if remainder = 1, jump to alloddloop

	allevenloop:
		mov ebx, allShirts;	//ebx = allShirts
		add ebx, [esi];		//ebx = ebx + value at current array element
		mov allShirts, ebx;	//allShirts = ebx

		add esi, 4;		//move esi to next element (next shirt)
		jmp allforloop;	//repeat loop

	alloddloop:
		mov ebx, allShirts;	//ebx = allShirts
		add ebx, [esi];		//add current value to total shirts
		mov allShirts, ebx;	//allShirts = ebx

		mov ebx, sShirts;	//ebx = sShirts
		add ebx, [esi];		//ebx = ebx + current array value
		mov sShirts, ebx;	//sShirts = ebx

		add esi, 4;		//move to next element
		jmp allforloop;	//repeat loop

	alldone:

		//medium shirts
		lea esi, [a];	//reset esi to address of a[0][0][0] again
		mov ebx, 0;		//ebx = 0
		mov i, 0;		//i = 0, loop counter

		add esi, 8;		//esi = start at index 2 (medium shirts)

	mediumloop:
		cmp i, 6;		//compare i to 6 (number of medium shirts to sum)
		je mediumdone;	//if i = 6, jump to medium done since we are done 
//summing medium shirts

		add ebx, [esi];	//add current medium shirt value to ebx

		mov eax, i;		//eax = i
		mov ecx, 2;		//ecx = 2
		cwd;				
		idiv ecx;			

		inc i;				
		cmp edx, 1;			
		je oddloop;		//if the remainder is odd, jump to oddloop

	evenloop:
		add esi, 4;		//move pointer to next medium shirt 
		jmp mediumloop;	//repeat loop

	oddloop:
		add esi, 20;	//skip to the next relevant medium shirt in memory
		jmp mediumloop;	//repeat loop

	mediumdone:
		mov mShirts, ebx;	//store total medium shirts

		//red shirts
		lea esi, [a];	//esi = address of the first element again
		mov ebx, 0;		//ebx = 0
		mov i, 0;		//i = 0

	redloop:
		cmp i, 6;		//compare i to 6 (number of red shirts)
		je reddone;		//if done, exit loop

		add ebx, [esi];	//add current red shirt value to ebx
		add esi, 4;		//move pointer to next element
		inc i;			//increment i
		jmp redloop;	//repeat loop

	reddone:
		mov rshirts, ebx;	//store total red shirts
	}

	cout << endl;
	cout << "All shirts: " << allShirts << endl;
	cout << "Medium size shirts: " << mShirts << endl;
	cout << "Short sleeves shirts: " << sShirts << endl;
	cout << "Red shirts: " << rshirts << endl;
}
//Q3 DONE
