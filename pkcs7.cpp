#include <iostream>
#include <string.h>

using namespace std;

int stringToInt(char A[], int n)
{
	int res=0;
	for(int i=0;i<n;i++)
		res = (10*res)+(A[i]-'0');
	return res;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout << "Usage: " << argv[0] << " <string1> <string2>" << endl;
		return 0;
	}

	int i, x=strlen(argv[1]), y=stringToInt(argv[2], strlen(argv[2])), pad;
	cout << "y=" << y << endl;

	pad = y-(x%y);
	char pad_char = (char)pad;

	cout << argv[1];
	for(i=0;i<pad;i++)
		cout << pad_char;
	cout << endl;
	return 0;
}