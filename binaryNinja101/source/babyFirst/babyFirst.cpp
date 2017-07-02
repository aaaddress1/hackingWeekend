#include "stdafx.h"
#include <iostream>

int add(int a, int b, int c) {
	int tmp = (a + b + c);
	return tmp;
}

int sum(int num_in) {
	int i = 0, sum = 0;

	for (i = 1; i <= num_in; i++)
		sum += i;
	
	return sum;
}

int main(int argc, char* argv[])
{
	printf("sum: %i\n", sum(add(1, 2, 3)));
	system("PAUSE");
	return 0;
}