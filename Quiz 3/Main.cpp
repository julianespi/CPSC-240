#include <iostream>
using namespace std;

short numOfAs = 0;
short numOfBs = 0;
short numOfCs = 0;
short numOfDs = 0;
short numOfFs = 0;
char c;

void readChar()
{
	c = cin.get();
}


int main()
{
	cout << "Enter a number of grades: ";
	_asm
	{
		start:
			call readChar;
			cmp c, '\n';
			je done;
			cmp c, 'A';
			je incA;
			cmp c, 'B';
			je incB;
			cmp c, 'C';
			je incC;
			cmp c, 'D';
			je incD;
			cmp c, 'F';
			je incF;
		incA:
			inc numOfAs;
			jmp start;
		incB:
			inc numOfBs;
			jmp start;

		incC:
			inc numOfCs;
			jmp start;

		incD:
			inc numOfDs;
			jmp start;

		incF:
			inc numOfFs;
			jmp start;

		done:

	}


	cout << "No. of A's = " << numOfAs << endl;
	cout << "No. of B's = " << numOfBs << endl;
	cout << "No. of C's = " << numOfCs << endl;
	cout << "No. of D's = " << numOfDs << endl;
	cout << "No. of F's = " << numOfFs << endl;
	return 0;
}