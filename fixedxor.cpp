#include <iostream>
#include <string.h>
#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout << "Usage: " << argv[0] << " <string1> <string2>" << endl;
		return 0;
	}

	int i, n = strlen(argv[1]), x;

	if(n!=strlen(argv[2]))
	{
		cout << "Enter strings of same length" << endl;
		return 0;
	}

	for(i=0;i<n;i++)
	{
		x = ((hexToInt(argv[1][i])^hexToInt(argv[2][i])) & 0xF);
		cout << intToHex(x);
	}
	cout << endl;
	return 0;
}