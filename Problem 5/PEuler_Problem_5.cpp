// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

#include <iostream>
#include <vector>

using namespace std;

vector<int> primeGen(int);

int main(void)
{
	vector<int> primes = primeGen(20);
	vector<int> minNumPrimes(primes.size(), 1);

	for (int i = 0; i < primes.size(); i++)
	{
		int j = primes[i];
		while (j*primes[i] <= 20)
		{
			j *= primes[i];
			minNumPrimes[i]++;
		}
	}

	int answer = 1;
	for (int i = 0; i < minNumPrimes.size(); i++)
	{
		for (int j = 0; j < minNumPrimes[i]; j++) answer *= primes[i];
	}

	cout << answer << endl;

	system("pause");
}

vector<int> primeGen(int max)
{
	vector<int> primes;
	vector<bool> checked(max + 1, false);
	primes.push_back(2);

	for (int i = 3; i <= max; i += 2)
	{
		if (!checked[i])
		{
			primes.push_back(i);
			for (int j = 2; j*i < checked.size(); j++) checked[j*i] = true;
		}
	}

	return primes;
}
