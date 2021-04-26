#include <iostream>
#include <typeinfo>
#include <string>
#include <time.h>

using namespace std;

bool strIsNumber(string &str)
{//checks to see if a string contains only numbers
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

	return isNum;
}

int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		char consonants[15] = { 'd' , 'b', 'k', 'f', 'g', 's', 'm', 'v', 'w', 'l', 'n', 'q', 'y'};
		char vowels[5] = { 'a', 'e', 'i', 'o', 'u'};
		string str_length = argv[1];
		string name = "";
		if (strIsNumber(str_length))
		{
			srand(time(NULL));
			int length = stoi(str_length);
			for (int i = 0; i < length;i++)
			{
				for (int j = 0; j < (rand() % 5 + 3) ; j++)
				{
					name += consonants[rand() % 15];
					name += vowels[rand() % 5];
				}
				cout << name << endl;
				name = "";
			}	
		}	


	}
	else
		cout << "incorrect number of arguments\n";
}
