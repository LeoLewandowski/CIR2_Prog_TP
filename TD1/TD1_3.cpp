/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>
#include <ctype.h>

char lower() {
	char c;
	printf("Donnez un caract�re majuscule :");
	scanf("%c", &c);
	printf("Le caract�re en minuscule : %c\n\n", tolower(c));
	return c;
}

int main()
{
	lower();
	return EXIT_SUCCESS;
}

