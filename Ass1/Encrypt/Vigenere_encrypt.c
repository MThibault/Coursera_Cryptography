/* Code given by Jonathan Katz in the Coursera Cryptography course */
#include <stdio.h>

#define KEY_LENGTH 2 // Can be anything from 1 to 13

int main() {
	unsigned char	ch;
	FILE		*fpIn, *fpOut;
	int		i	= 0;
	unsigned char	key[KEY_LENGTH]	= {0xA1, 0x2F}; // Of course, I did not use the all-0s key to encrypt

	fpIn	= fopen("ptext.txt", "r");
	fpOut	= fopen("ctext.txt", "w");

	while(fscanf(fpIn, "%c", &ch) != EOF) {
		// Avoid encrypting newline characters
		/* In a "real-world" implementation of the Vigenere cipher,
		every ASCII character in the plaintext would be encrypted.
		However, I want to avaid encrypting newlines here because
		it makes recovering the plaintext slightly more difficult...*/
		// ... and my goal is not to create "production-quality" code =)

		if(ch != '\n') {
			fprintf(fpOut, "%02X", ch ^ key[i % KEY_LENGTH]); // ^ is logical XOR
			i++;
		}
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
