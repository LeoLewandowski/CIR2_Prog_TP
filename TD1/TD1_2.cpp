/* Premier programme en C */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main()
{
	float a, b, c;

	printf("\nRésolution de l'expression ax² + bx + c :");
	printf("\nDonnez a : ");
	scanf("%f", &a);

	printf("Donnez b : ");
	scanf("%f", &b);

	printf("Donnez c : ");
	scanf("%f", &c);

	float delta = b * b - 4 * a * c;

	if (delta < 0) {
		printf("\nAucune racine réelle pour la fonction %fx^2 %+fx %+f\n\n", a, b, c);
		return EXIT_SUCCESS;
	}
	else if (delta == 0) {
		printf("\nFonction : %fx^2 %+fx %+f\nRacine : %f\n\n", a, b, c, b / 2 * a);
		return EXIT_SUCCESS;
	}

	float x1 = (-b - sqrt(delta)) / (2 * a),
		x2 = (-b + sqrt(delta)) / (2 * a);
	printf("\nFonction : %fx^2 %+fx %+f\nRacines :\n    %f\n    %f\n\n", a, b, c, x1, x2);
	return EXIT_SUCCESS;
}