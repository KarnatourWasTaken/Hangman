	//TODO Zamezit davat velke pismena do stringu(multiplayer)

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdbool.h>

	char slovo[30] = { 0 };

	void singleplayer(void);
	void multiplayer(void);

	int main() {

		int volba, reset;
		printf("1. Hra pro jednoho hrace(fungujou pouze anglicka slova)\n");
		printf("2. Hra pro vice hracu (jeden urci slovo druhy hada)\n");
		do {
			scanf("%d", &volba);
			switch (volba) {
			case 1:
				reset = 1;
				break;
			case 2:
				reset = 1;
				multiplayer();
				break;

			default:
				reset = 2;
				printf("Tato volba neexistuje\n");
				break;
			}
		} while (reset != 1);

		system("pause");
		return 0;
	}

	void multiplayer() {
		char uhadnuti[60] = { 0 },pismeno, kontrola[60] = { 0 };
		int i, x = 0, spatne = 0, delka;
		bool uhadnuto;
		printf("Zadejte slovo (maximalne 30 znaku)");
		fflush(stdout);
		scanf("%s", slovo);
		delka = strlen(slovo);
		
		for (i = 0; i < delka; i++) {
			uhadnuti[i] = '*';
		}
		puts(uhadnuti);
		printf("Zadejte pismeno\n");
		do {
			uhadnuto = false;
			for (i = 0; i < delka; i++) {
				if (uhadnuti[i] != '*') {
				}
			}
			scanf(" %c", &pismeno);
			for (i = 0; i < delka; i++) {
				if (slovo[i] == pismeno) {
					uhadnuti[i] = slovo[i];
				}
				else {
					spatne++;
				}
			}
			puts(uhadnuti);
		} while (!uhadnuto);
		system("cls");
		printf("Slovo bylo uhadnuto!");

	}

