#include "util.h"

int hexToInt(char a)
{
	if(0<=(a-'0') &&  (a-'0')<=9)
		return a-'0';
	else if(0<=(a-'a') && (a-'a')<=5)
		return a-'a'+10;
}

int hexToBase64(char *encoded, const char *string, int len)
{
	int i = 0;	
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

int oneByteXor(char *out, const char *string, int len, const char key)
{
	int i = 0;
	char *p = out;

	if(len%2==1)
	{
		*p++ = hex[(key & 0xf)^hexToInt(string[0])];
		i=1;
	}

	for(;i<len;i+=2)
	{
		*p++ = hex[((key >> 4) & 0xf)^hexToInt(string[i])];
		*p++ = hex[(key & 0xf)^hexToInt(string[i+1])];
	}
	*p++ = '\0';

	return p-out;
}