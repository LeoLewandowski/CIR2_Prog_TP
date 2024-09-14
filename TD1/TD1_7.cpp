#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main()
{
	int *tab, n;
	printf("Taille du tableau :");
	scanf("%i", &n);

	tab = (int*)malloc(sizeof(int) * n);
	if (tab == NULL) {
		printf("Erreur de mémoire : Impossible de créer le tableau");
		return EXIT_FAILURE;
	}

	srand(time(NULL));

	printf("\n\nTableau avant tri : \n[");
	for (int i = 0; i < n; i++) {
		tab[i] = rand();
		printf(" %i ", tab[i]);
	}
	printf("]\n\n");

	qsort(tab, n, sizeof(int), compare);

	printf("Tableau après tri :\n[");
	for (int i = 0; i < n; i++) {
		printf(" %i ", tab[i]);
	}
	printf("]\n\n");

	return EXIT_SUCCESS;
}

