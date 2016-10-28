static const char base_64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char hex[] = "0123456789abcdef";

int hexToInt(char a);
int hexToBase64(char *encoded, const char *string, int len);
int oneByteXor(char *out, const char *string, int len, const char key);