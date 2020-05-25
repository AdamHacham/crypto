#include <stdio.h>
#include <string.h>

// global constant definition
const char * base64char = "+AbCdEfGhIjKlMnOpQrStUvWxYz0123456789ZyXwVuTsRqPoNmLkJiHgFeDcBa/";
const char padding_char = '=';

/* encoding code
 * const unsigned char * sourcedata, source array
 * char * base64 , codeword save
*/
int base64_encode(const unsigned char * sourcedata, char * base64)
{
	int i = 0, j = 0;
	unsigned char trans_index = 0;    // The index is 8 bits, but the upper two bits are 0.
	const int datalength = strlen((const char*)sourcedata);
	for (; i < datalength; i += 3){
		// Encode every three groups
		// the first number of numbers to be encoded
		trans_index = ((sourcedata[i] >> 2) & 0x3f);
		base64[j++] = base64char[(int)trans_index];
		// the second
		trans_index = ((sourcedata[i] << 4) & 0x30);
		if (i + 1 < datalength){
			trans_index |= ((sourcedata[i + 1] >> 4) & 0x0f);
			base64[j++] = base64char[(int)trans_index];
		}
		else{
			base64[j++] = base64char[(int)trans_index];

			base64[j++] = padding_char;

			base64[j++] = padding_char;

			break;   // beyond the total length, you can break directly
		}
		// The third
		trans_index = ((sourcedata[i + 1] << 2) & 0x3c);
		if (i + 2 < datalength){ // If you need to code 2
			trans_index |= ((sourcedata[i + 2] >> 6) & 0x03);
			base64[j++] = base64char[(int)trans_index];

			trans_index = sourcedata[i + 2] & 0x3f;
			base64[j++] = base64char[(int)trans_index];
		}
		else{
			base64[j++] = base64char[(int)trans_index];

			base64[j++] = padding_char;

			break;
		}
	}

	base64[j] = '\0';

	return 0;
}

/** Query a specific character position index in a string
 * const char *str , string
 * char c, the character to find
*/
int num_strchr(const char *str, char c) // 
{
	const char *pindex = strchr(str, c);
	if (NULL == pindex){
		return -1;
	}
	return pindex - str;
}
/* decoding
 * const char * base64 codeword
 * unsigned char * dedata, decoding recovered data
*/
int base64_decode(const char * base64, unsigned char * dedata)
{
	int i = 0, j = 0;
	int trans[4] = { 0, 0, 0, 0 };
	for (; base64[i] != '\0'; i += 4){
		// every four groups, decoded into three characters
		trans[0] = num_strchr(base64char, base64[i]);
		trans[1] = num_strchr(base64char, base64[i + 1]);
		// 1/3
		dedata[j++] = ((trans[0] << 2) & 0xfc) | ((trans[1] >> 4) & 0x03);

		if (base64[i + 2] == '='){
			continue;
		}
		else{
			trans[2] = num_strchr(base64char, base64[i + 2]);
		}
		// 2/3
		dedata[j++] = ((trans[1] << 4) & 0xf0) | ((trans[2] >> 2) & 0x0f);

		if (base64[i + 3] == '='){
			continue;
		}
		else{
			trans[3] = num_strchr(base64char, base64[i + 3]);
		}

		// 3/3
		dedata[j++] = ((trans[2] << 6) & 0xc0) | (trans[3] & 0x3f);
	}

	dedata[j] = '\0';

	return 0;
}

// test
int main()
{
	const unsigned char str[] = "a45rbcd";
	const unsigned char *sourcedata = str;
	char *base64 = "SfU72WQ9YvMZ2GQZYWAmYWUiYvUkxvZkYfUk1yBJ2yUm0fUR0HQ9YWA61HMZxXI62yB8YvNJzvMVYWMknSlLzixo18MilHh" ;
	printf("Code: %s\n", base64);

	char dedata[128];

	base64_decode(base64, (unsigned char*)dedata);

	printf("Decoding: %s", dedata);

	getchar();
	getchar();
	return 0;
}

