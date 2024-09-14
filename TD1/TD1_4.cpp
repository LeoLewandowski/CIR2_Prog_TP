/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>

typedef unsigned long (*functionType)(unsigned long);

unsigned long factorialWhile(unsigned long n) {
	unsigned long current = 2, total = 1;
	while (current <= n) {
		total *= current;
		current++;
	}
	return total;
}

unsigned long factorialFor(unsigned long n) {
	unsigned long total = 1;
	for (unsigned long current = 2; current <= n; current++) total *= current;
	return total;
}

unsigned long factorialRecursive__(unsigned long n, unsigned long current) {
	printf("%lu %lu", current, n);
	if (current >= n) return n;
	return current * factorialRecursive__(n, current + 1);
}

unsigned long factorialRecursive(unsigned long n) {
	return factorialRecursive__(n, 2);
}

// Supprime les inputs en trop après un scanf
void flush() {
	int c = 'a';
	while (c = getchar() != '\n' && c != EOF);
}

int main()
{
	char c = 'a';
	functionType func;
	unsigned int n;

	while (c != 'q') {
		printf("Choisissez la méthode de calcul ou `q` pour quitter :\n 1. Boucle while\n 2. Boucle for\n 3. Fonction récursive\n > ");
		scanf("%c", &c);
		flush();


		switch (c)
		{
		case '1': func = factorialWhile; break;
		case '2': func = factorialFor; break;
		case '3': func = factorialRecursive; break;
		case 'q': return EXIT_SUCCESS;
		default:
			printf("Ce choix n'est pas valide !");
			continue;
		}

			printf("Choisissez le nombre entier positif : ");
			scanf("%u", &n);
			flush();

			printf("La factorielle de %i est %lu\n\n", n, func(n));
	}

	return EXIT_SUCCESS;
}

