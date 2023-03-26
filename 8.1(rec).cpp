#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool AvailableElements(char* str,int i);
char* Change(char* dest, const char* str, char* t, int i);

int main()
{
	char str[101];
	cout << "Enter string: " << endl;
	cin.getline(str, 100);

	if (AvailableElements(str,0))
	{
		cout << "There are \"AGA\" or \"OGO\" in string " << endl;
	}
	else
		cout << "No \"AGA\" or \"OGO\" in string " << endl;

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);

	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	return 0;
}

bool AvailableElements(char* str,int i)
{
	if (str[i + 1] != 0)
	{
		if (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A' || str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O')
		{
			return true;
		}
		AvailableElements(str, i + 1);
	}
	else return false;

}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A' || str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O')
		{
			strcat(t, "**");
			return Change(dest, str, t + 2, i + 3);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
