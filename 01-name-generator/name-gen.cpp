#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

bool strIsNumber(string &str)
{
	string numbers = "0123456789";
	bool isNum = false;

	for (int i = 0; i < str.length(); i++)
	{
		if (isNum)
			isNum = true;

		for (int j = 0; j < numbers.length(); j++)
		{
			if (str[i] == numbers[j])
			{
				isNum = true;
				break;
			}
		}
		if (isNum == false)
			break;
	}
	cout << str;

	return isNum;
}
int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		char consonants[10] = { 'd' , 'b', 'k', 'f', 'g', 's', 'm', 'v', 'w', 'l'};
		char vowels[5] = { 'a', 'e', 'i', 'o', 'u'};
		string length = argv[1];

		if (strIsNumber(length))
			cout << "works";
		else
			cout << "doesn't work";
		cout << endl;
	}
	else
		cout << "incorrect number of arguments\n";
}
