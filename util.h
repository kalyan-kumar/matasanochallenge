static const char base_64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int hexToInt(char a);
int hexToBase64(char *encoded, const char *string, int len);