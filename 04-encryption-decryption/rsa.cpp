#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <bitset>

using namespace std;
 

bitset<1024> genBinary()
{
	bitset<1024> n;
	n[1023] = 1;
	for (int i = 0; i <= 1022; i ++)
		n[i] = rand() % 2;
		
	return n;
}

bool isPrime (bitset<1024> &n)
{
	bool isPrime = true;

	if (n[0]== 0)
		isPrime = false;
	else
	{
		bitset<1024> a = n - 1;
		int counter = 0;
		while (a[0] == 0)
		{
			a / 2;
				
		}		
	}
	return isPrime;

}

bitset<1024> bitDivide(bitset<1024> x, bitset<1024, y)
{
	bitset<1024> z = 0; 
}
bitset<1024> genPrime()
{}
int main(int argc, char** argv)
{
	srand(time(NULL));
	string message = argv[1];
	bitset<1024> n = genBinary();	
	cout << n << endl;
	cout << isPrime(n) << endl;

}

