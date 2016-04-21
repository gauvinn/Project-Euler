// A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.

#include <iostream>

using namespace std;

bool isPalindromic(int);

int main(void)
{
	int palindrome = 0;

	for (int i = 999; i*i > palindrome; i--)
	{
		for (int j = i; i*j > palindrome; j--)
		{
			if (isPalindromic(i*j))
			{
				palindrome = i*j;
				break;
			}
		}
	}

	cout << palindrome << endl;

	system("pause");
}

bool isPalindromic(int n)
{
	char num[10];
	itoa(n, num, 10);

	string pal = string(num);

	for (int i = 0; i < pal.size() / 2; i++)
	{
		if (pal[i] != pal[pal.size() - 1 - i]) return false;
	}

	return true;
}