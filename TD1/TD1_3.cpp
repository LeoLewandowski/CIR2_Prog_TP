/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>
#include <ctype.h>


int main()
{
	lower();
	return EXIT_SUCCESS;
}

char lower() {
	char c;
	printf("Donnez un caractère majuscule :");
	scanf("%c", &c);
	printf("Le caractère en minuscule : %c\n\n", tolower(c));
	return c;
}

