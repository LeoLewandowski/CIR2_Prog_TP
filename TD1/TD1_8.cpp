#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main()
{
	int** tab, n, m;

	printf("Veuillez donner n :");
	scanf("%i", &n);

	printf("Veuillez donner m :");
	scanf("%i", &m);

	tab = (int**)malloc(m * sizeof(int*));

	if (tab == NULL) {
		printf("Problème lors de la création du tableau");
		return EXIT_FAILURE;
	}

	srand(time(NULL));

	printf("Tableau avant tri par colonnes :\n");

	for (int i = 0; i < m; i++) {
		tab[i] = (int*)malloc(n * sizeof(int));

		if (tab[i] == NULL) {
			printf("Problème lors de la création du tableau");
			return EXIT_FAILURE;
		}

		for (int j = 0; j < n; j++) {
			tab[i][j] = rand();
			printf("|%6i ", tab[i][j]);
		}

		printf("|\n");
	}

	printf("Tableau après tri :\n");

	for (int x = 0; x < n; x++) {
		int* col = (int*)malloc(n * sizeof(int));

		if (col == NULL) {
			printf("Problème de mémoire lors du tri du tableau");
			return EXIT_FAILURE;
		}

		for (int y = 0; y < m; y++) col[y] = tab[y][x];

		qsort(col, m, sizeof(int), compare);

		for (int y = 0; y < m; y++) tab[y][x] = col[y];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) printf("|%6i ", tab[i][j]);
		printf("|\n");
	}

	return EXIT_SUCCESS;
}

