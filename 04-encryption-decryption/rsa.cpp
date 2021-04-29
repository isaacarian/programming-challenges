#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

vector<bool> binAdd(vector<bool> &x, vector<bool> &y);
int sizeOfLarger(vector<bool> &x, vector<bool> &y);
void printVector(vector<bool> &x);
vector<bool> returnLarger(vector<bool> &x, vector<bool> &y);
vector<bool> returnSmaller(vector<bool> &x, vector<bool> &y);
vector<bool>genBinary()
{
	vector<bool> n = {};
	n.push_back(1);
	for (int i = 1; i <= 1023; i ++)
		n.push_back(rand() % 2);

	return n;
}

vector<bool>genEmptyBinary(int size)
{
	vector<bool> n = {};
	n.push_back(0);
	for (int i = 1; i <= size - 1; i ++)
		n.push_back(0);

	return n;
}

bool isPrime (vector<bool> &n)
{
	bool isPrime = true;

	if (n[0]== 0)
		isPrime = false;
	else
	{
		vector<bool> a = n;
		int counter = 0;
		//while (a[0] == 0)
		//{

		//}
	}
	return isPrime;

}


vector<bool> binSubtract(vector<bool> x, vector<bool> y)
{ //x-y
	vector<bool> difference = genEmptyBinary(sizeOfLarger(x,y));
	for (int i = sizeOfLarger(x,y); i >= 0; i--)
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
			while (i-counter != -1)
			{
				if (x[i-counter] == 1)
				{
					x[i-counter] = 0;
					difference[i] = 1;
					break;
				}
				else if (x[i-counter] == 0)
				{
					x[i-counter] = 1;
					counter++;
				}
			}

		}

	}
	return difference;
}

vector<bool> binDivision(vector<bool>x)
{}

vector<bool> binMultiply(vector<bool> &x, vector<bool> &y)
{
	vector<bool> smaller = returnSmaller(x, y);
	vector<bool> larger = returnLarger(x, y);

	vector<bool> product = genEmptyBinary(larger.size());
	vector<bool> buffer = genEmptyBinary(larger.size());

	int c = 0;
	for (int i = larger.size() - 1;  i >= 0; i--)
	{
		c = larger.size() - i - 1;
		if (smaller[i] == 1)
		{
			buffer = larger;
			for (int j = 0; j <= c; j++)
				buffer.push_back(0);

			product = binAdd(product, buffer);
		}

	}
	return product;

}

int sizeOfLarger(vector<bool> &x, vector<bool> &y)
{
	int size = 0;
	if (x.size() >= y.size())
		size = x.size();
	else
		size = y.size();
	return size;
}
vector<bool> returnLarger(vector<bool> &x, vector<bool> &y)
{
	vector<bool> larger  = {};
	if (x.size() < y.size())
		larger = y;
	else if (x.size() > y.size())
		larger = x;
	else
	for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == 1 and y[i] == 0)
			{
				larger = x;
				break;
			}
			else if (x[i] == 0 and y[i] == 1)
			{
				larger = y;
				break;
			}
		}

		return larger;
}

vector<bool> returnSmaller(vector<bool> &x, vector<bool> &y)
{
	vector<bool> smaller = {};
	if (x.size() > y.size())
		smaller = y;
	else if (x.size() < y.size())
		smaller = x;
	else
	for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == 1 and y[i] == 0)
			{
				smaller = y;
				break;
			}
			else if (x[i] == 0 and y[i] == 1)
			{
				smaller = x;
				break;
			}
		}

		return smaller;
}

vector<bool> binAdd(vector<bool> &x, vector<bool> &y)
{
	vector<bool> smaller = returnSmaller(x, y);
	vector<bool> larger = returnLarger(x, y);

	vector<bool> sum = genEmptyBinary(larger.size());
	bool r = 0;
	int j = 0;

	for (int i = larger.size() - 1; i >= 0; i--)
	{
		j = smaller.size() - (larger.size() - i);
		if (j >= 0)
		{
			sum[i] = (larger[i]^smaller[j])^r;
			r = (larger[i] + smaller[j] + r) > 1;
		}
		else if (j < 0)
		{
			sum[i]= larger[i]^r;
			r = (larger[i] && r);
		}

		if (i == 0 && larger[i] && r)
		{
			sum.insert(sum.begin(), 1, 1);
		}

	}

	return sum;
}
bool binSmaller(vector<bool> &x, vector<bool>y)
{// is x smaller than y
	bool binSmaller;
	for (int i = 0; i < 1024; i++)
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
vector<bool> bitDivide(vector<bool> &x, vector<bool> &y)
{
	vector<bool> z;
}
vector<bool> genPrime()
{}

void printVector(vector<bool> &x)
{
	for (int i = 0; i < x.size(); i++)
		cout << x[i];
	cout << endl;
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	string message = argv[1];
	vector<bool> n = genBinary();
	vector<bool> b = genBinary();
	vector<bool> l = returnLarger(n,b);
	vector<bool> s = returnSmaller(n,b);
	vector<bool> a = binAdd(n,b);
	vector<bool> m = binMultiply(n,b);
	printVector(n);
	printVector(b);
	printVector(l);
	printVector(s);
	printVector(a);
	printVector(m);
}
