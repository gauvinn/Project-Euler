// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned long long> primeGen(unsigned long long);

int main(void)
{
	unsigned long long number = 600851475143;
	unsigned long long max = (unsigned long long)sqrt((double)number) + 1;

	vector<unsigned long long> primes = primeGen(max);

	unsigned long long largestPF = 0, i = primes.size() - 1;
	while (largestPF == 0)
	{
		if (number%primes[i] == 0) largestPF = primes[i];
		else i--;
	}

	cout << largestPF << endl;

	system("pause");
}

vector<unsigned long long> primeGen(unsigned long long max)
{
	vector<unsigned long long> primes;
	vector<bool> checked(max+1,false);
	primes.push_back(2);
	
	for (unsigned long long i = 3; i <= max; i += 2)
	{
		if (!checked[i])
		{
			primes.push_back(i);
			for (unsigned long long j = 2; j*i < checked.size(); j++) checked[j*i] = true;
		}
	}

	return primes;
}
