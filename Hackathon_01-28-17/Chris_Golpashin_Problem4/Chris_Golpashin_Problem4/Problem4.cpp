/*
Chris Golpashin
Problem 4

January 28, 2017
MJC CSC Hackathon
*/

#include <iostream>
using namespace std;

double Option1(double AmountPayed);
double Option2(double price, double NumberOfBooks, double AuthorPayed);
double Option3(double price, double NumberOfBooks, double AuthorPayed);

int main()
{
	double BookNetPrice = 0;
	double NumOfCopies = 0;
	double AmountPayedToAuthor = 0;

	cout << "This program computers the royalties for your book as the author." << endl;
	cout << "Please enter the net price of each copy of your book: ";

	cin >> BookNetPrice;

	if (BookNetPrice <= 0) // Stops the user from entering an invalid amount for the price.
	{
		cout << "Please enter a price that is above $0." << endl;

		return 0;
	}

	cout << "Please enter how many copies will be sold: ";

	cin >> NumOfCopies;

	if (NumOfCopies <= 0) // Stops the user from entering an invalid amount of books.
	{
		cout << "Please enter an amount of books above 0." << endl;

		return 0;
	}
	
	// Calling option 1
	Option1(AmountPayedToAuthor);
	cout << endl;

	// Calling option 2
	Option2(BookNetPrice, NumOfCopies, AmountPayedToAuthor);
	cout << endl;
	
	// Calling option 3
	Option3(BookNetPrice, NumOfCopies, AmountPayedToAuthor);

	cout << endl;
	cout << endl;

	return 0;
}

// Option 1
double Option1(double AuthorPayed)
{
	AuthorPayed = 25000.00;

	cout << endl;
	cout << "In the first option, you are paid $5,000 upon delivery of the final manuscript and $20,000 when the novel is published." << endl;
	cout << "In the first option, you earn	";
	cout << AuthorPayed;

	return AuthorPayed;
}

// Option 2
double Option2(double price, double NumberOfBooks, double AuthorPayed)
{
	double TotalProfit; // The total profit generated from the possible sales.

	TotalProfit = (price*NumberOfBooks);
	AuthorPayed = (TotalProfit*.125);

	cout << endl;
	cout << "In the second option, you are paid 12.5% of the net price of the novel for each copy of the novel sold." << endl;
	cout << "In the second option, you earn	";
	cout << AuthorPayed;

	return AuthorPayed;
}

// Option 3
double Option3(double price, double NumberOfBooks, double AuthorPayed)
{
	double FirstFourThousand = 0; // first four thousand of books.
	double AfterFourThousand = 0; // The amount of books after taking the 4000 other books.
	double TotalProfit;	// The total profit generated from the possible sales.

	if (NumberOfBooks == 4000) 
	{
		TotalProfit = (NumberOfBooks*price);
		AuthorPayed = (TotalProfit*.10);

		cout << endl;
		cout << "In the third option, you are paid 10% of the net price of the first 4000 copies sold, and 14% of the net price for the copies sold over 4000." << endl;
		cout << "In the third option, you earn	";
		cout << AuthorPayed;
	}

	else if (NumberOfBooks < 4000 && NumberOfBooks > 0)
	{
		TotalProfit = (NumberOfBooks*price);
		AuthorPayed = (TotalProfit*.10);

		cout << endl;
		cout << "In the third option, you are paid 10% of the net price of the first 4000 copies sold, and 14% of the net price for the copies sold over 4000." << endl;
		cout << "In the third option, you earn	";
		cout << AuthorPayed;
	}
	else if (NumberOfBooks > 4000)
	{
		FirstFourThousand = 4000;
		NumberOfBooks -= 4000;
		AfterFourThousand += NumberOfBooks;

		FirstFourThousand *= price;
		AfterFourThousand *= price;
		
		AuthorPayed += (FirstFourThousand*.10);
		AuthorPayed += (AfterFourThousand*.14);

		cout << endl;
		cout << "In the third option, you are paid 10% of the net price of the first 4000 copies sold, and 14% of the net price for the copies sold over 4000." << endl;
		cout << "In the third option, you earn	";
		cout << AuthorPayed;
	}
	else
	{
		cout << endl;
		cout << "Please enter an amount of books that is atleast above 0." << endl;
	}

	return AuthorPayed;
}