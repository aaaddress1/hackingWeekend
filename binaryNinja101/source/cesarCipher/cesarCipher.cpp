#include "stdafx.h"
#include <iostream>

void caesar_cipher(char *str, int offset) {
	int chr_index = 0;
	char chr = '\x00';

	for (int i = 0; i < strlen(str); i++) {
		chr = str[i];

		if (chr >= 'a' && chr <= 'z') {
			chr_index = chr - 'a';
			chr_index += offset;
			chr_index = chr_index > 26 ? chr_index - 26 : chr_index;
			str[i] = 'a' + chr_index;
			continue;
		}
		
		if (chr >= 'A' && chr <= 'Z') {
			chr_index = chr - 'A';
			chr_index += offset;
			chr_index = chr_index > 26 ? chr_index - 26 : chr_index;
			str[i] = 'A' + chr_index;
			continue;
		}
	}
}


char buffer[256];
int  offset = -1;

bool user_input() {

	puts("=== welcome to uncrackable encrypt system ===");
	puts("!! give me your plantext !!");
	scanf("%255s", &buffer);

	puts("");

	puts("!! give me your key !!");
	puts("(should be a number, between 0 and 26)");
	scanf("%i", &offset);

	if (offset < 0 || offset > 26) {
		puts("key is incorrect!");
		return false;
	}

	return true;
}

void save_secret(char *str) {
	if (FILE *fp = fopen("secret.txt", "w")) {
		fprintf(fp, "%s", str);
		puts("your secret have been stored in 'secret.txt' :)");
	}
	else
		puts("oh...no...something wrong....");

}

int main(int argc, char* argv[])
{
	if (user_input()) {
		caesar_cipher(buffer, offset);
		save_secret(buffer);
	}

	puts("");
	system("PAUSE");
	return 0;
}

