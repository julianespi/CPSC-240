#include <iostream>
using namespace std;

int main()
{
	//1.
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
	
	return 0;
}
