#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

void print_welcome() {
	puts("/*******************************/");
	puts("* 1nte1's                       *");
	puts("* Active Management Technology  *");
	puts("/*******************************/");
	puts("");
}

void chk_login(char *usr, char *pas) {
	char rand_password[8];

	if (strncmp(usr, "root", 4)) {
		puts("sorry, this feature only allow 'root' user to use,");
		printf("you log on as '%s' user.\n", usr);
		return;
	}
	
	srand(time(NULL));
	sprintf(rand_password, "%i", rand());
	if (strncmp(pas, rand_password, strlen(pas))) {
		puts("oh, no! you got the wrong password?");
		printf("the password of 'root' is '%s'\n", rand_password);
		return;
	}

	puts("login sucessed!");
	puts("this is your flag: {CVE_2017_5689_SO_EASY}");
}

int main(int argc, char* argv[])
{
	char user[64];
	char pass[64];

	print_welcome();

	printf("User: ");
	fgets(user, 64, stdin);
	user[strlen(user) - 1] = '\x00';

	printf("Password: ");
	fgets(pass, 64, stdin);
	pass[strlen(pass) - 1] = '\x00';

	chk_login(user, pass);

	puts("");
	system("PAUSE");
	return 0;
}

