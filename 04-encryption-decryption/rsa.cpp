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
		bitset<1024> a = n;
		int counter = 0;
		//while (a[0] == 0)
		//{
				
		//}		
	}
	return isPrime;

}

bitset<1024> binSubtract(bitset<1024> x, bitset<1024> y)
{ //x-y
	bitset<1024> difference;
	for (int i = 0; i < 1024; i++)
	{
		if (x[i] == 1 and y[i] == 1)
			difference[i] = 0;
		else if (x[i] == 1 and y[i] == 0)
			difference[i] = 1;
		else if (x[i] == 0 and y[i] == 0)
			difference[i] = 0;
		else if (x[i] == 0 and y[i] == 1)
		{
			int counter = 1;
			while (true)
			{
				if (x[i+counter] == 1)
				{
					x[i+counter] = 0;
					difference[i] = 1;
					break;
				}
				else if (x[i+counter] == 0)
				{
					x[i+counter] = 1;
					counter++;
				}
			}
			
		}
			
	}	
	return difference;
}

bitset<1024> binDivision(bitset<1024>x)
{}
bool binSmaller(bitset<1024> &x, bitset<1024>y)
{// is x smaller than y
	bool binSmaller;
	for (int i = 1023; i >= 0; i--)
	{
		if (x[i] == 1 and y[i] == 0)
		{
			binSmaller = true;
			break;
		}
		else if (x[i] == 0 and y[i] == 1)
		{
			binSmaller = false;
			break;
		}

	}
	
	return binSmaller;
}
bitset<1024> bitDivide(bitset<1024> &x, bitset<1024> &y)
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
	bitset<1024> b = genBinary();
	if (binSmaller(n, b))
	{
		bitset<1024> d = binSubtract(n,b);
		cout << d << endl;
	}
	cout << n << endl;
	cout << b << endl;

}

