#include <iostream>
#include <string.h>
#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Usage: " << argv[0] << " <hex-encoded-string-to-decode>" << endl;
		return 0;
	}

	int i=0, n=strlen(argv[1]);

	cout << endl;

	return 0;
}