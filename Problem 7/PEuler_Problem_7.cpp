// By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10,001st prime number ?

// Primes occur roughly 13% of the time, so the prime will almost definitely be under 1000000

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int prime = 0;
	vector<bool> checked(1000001, false);

	int i = 0; 
	prime = 2;
	i++;

	int c = 3;
	while (i <= 10000)
	{
		if (!checked[c])
		{
			prime = c;
			i++;
			for (int j = 2 * i; j < checked.size(); j += i) checked[j] = true;
		}
		c += 2;
	}

	cout << prime << endl;

	system("pause");
}