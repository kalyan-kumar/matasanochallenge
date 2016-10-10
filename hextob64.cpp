#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

static const char base_64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int hexToInt(char a)
{
	if(0<=(a-'0') &&  (a-'0')<=9)
		return a-'0';
	else if(0<=(a-'a') && (a-'a')<=5)
		return a-'a'+10;
}

int hexToBase64(char *encoded, const char *string, int len)
{
	int i=0;	
	char *p;
	
	p = encoded;
	if(len%3==1)
	{
		*p++ = 'A';
		*p++ = base_64[hexToInt(string[0])];
		i = 1;
	}
	if(len%3==2)
	{
		*p++ = base_64[(hexToInt(string[0]) >> 2) & 0x3];
		*p++ = base_64[((hexToInt(string[0]) << 4) & 0x30) | ((hexToInt(string[1])) & 0xF)];
		i = 2;
	}

	for(;i<len-2;i+=3)
	{
		*p++ = base_64[((hexToInt(string[i]) << 2) & 0x3C) + ((hexToInt(string[i+1]) >> 2) & 0x3)];
		*p++ = base_64[((hexToInt(string[i+1]) << 4) & 0x30) + ((hexToInt(string[i+2])) & 0xF)];
	}
	*p++ = '\0';

	return p-encoded;
}

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