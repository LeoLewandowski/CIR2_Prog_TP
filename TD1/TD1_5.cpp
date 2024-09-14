#define _CRT_SECURE_NO_WARNINGS
/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Le plus long mot de la langue française fait 27 lettres de long, +1 pour le caractère de fin
#define MAX_LENGTH 28
#define SPEC_CHAR '_'

// Supprime les inputs en trop après un scanf
void flush() {
	int c = 'a';
	while (c = getchar() != '\n' && c != EOF);
}

int main()
{
	char *word, *displayWord, guess = '0', triesLeft = 10;
	word = (char*)calloc(MAX_LENGTH, sizeof(char));
	displayWord = (char*)calloc(MAX_LENGTH, sizeof(char));

	if (word == NULL || displayWord == NULL) {
		printf("Memory error : not enough memory to allocate to character buffers");
		return EXIT_FAILURE;
	}

	printf("-------- Jeu du pendu --------\n\nChoisissez un mot (27 lettres max, sans accents)\n > ");
	scanf("%s", word);
	flush();

	for (char i = 0; word[i]; i++) {
		word[i] = toupper(word[i]);
		displayWord[i] = SPEC_CHAR;
	}

	while (triesLeft > 0 && strcmp(word, displayWord)) {
		system("cls");
		printf("-------- Jeu du pendu --------\n\nMot a deviner :\n%s\nErreurs restantes : %i\nEntrez un caractere : ", displayWord, triesLeft);
		scanf("%c", &guess);
		printf("Okok");
		flush();

		guess = toupper(guess);
		char isValid = 0;

		for (char i = 0; word[i]; i++) {
			if (word[i] == guess) {
				isValid = 1;
				displayWord[i] = word[i];
			}
		}
		if (!isValid) triesLeft--;
	}
	system("cls");
	printf("-------- Jeu du pendu --------\n\nMot a deviner :\n%s\nErreurs restantes : %i\nEntrez un caractere : ", displayWord, triesLeft);
	
	if (triesLeft > 0) printf("\n\nBien joue ! Vous avez trouve le mot");
	else printf("\n\nVous avez perdu. Tant pis !");

	return EXIT_SUCCESS;
}

