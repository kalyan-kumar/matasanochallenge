#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		cout << "Usage: " << argv[0] << " <hex-string-to-convert-to-base64>" << endl;
		return 0;
	}
	
	int len = strlen(argv[1]), x = len/3, y;
	if(len%3!=0)
		x++;

	char *out = (char *)malloc((2*x)*sizeof(char));

	y = hexToBase64(out, argv[1], len);

	cout << out << endl;

	return 0;
}