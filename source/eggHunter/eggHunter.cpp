#include "stdafx.h"
#include <stdio.h>
#include <iostream>

int main(void) {
	int tmp = 0;
	int arr[] = {543647589, 1953396072, 544434464, 560887142, 0};

	if (FILE *fp = fopen("./4re_u_a_bunny/egg.txt", "w")) {
		puts("good job! you found my egg.");

		for(int *ptr = arr; *ptr;) {
			tmp = *(ptr++);
			fprintf(fp, "%.4s", (char *)&tmp);
		}
	}
	else
		puts("sorry, you're not a hunter. :(");

	system("PAUSE");
	return 0;
}
