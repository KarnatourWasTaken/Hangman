//TODO Zamezit davat velke pismena do stringu(multiplayer)
#pragma comment(lib, "winmm.lib")//hudba

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

char slovo[30] = { 0 };

void singleplayer(void);
void multiplayer(void);
void otevreni_obrazku(int cislo);

int main() {

	int volba, reset;
	//PlaySound(TEXT("hudba.wav"),NULL, SND_ASYNC | SND_LOOP);//hudba
	printf("1. Hra pro jednoho hrace(fungujou pouze anglicka slova)\n");
	printf("2. Hra pro vice hracu (jeden urci slovo druhy hada)\n");
	do {
		scanf("%d", &volba);
		switch (volba) {
		case 1:
			reset = 1;
			system("cls");
			break;
		case 2:
			reset = 1;
			system("cls");
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
	int i, x = 0, spatne = 0,zbyvajici=0, delka;
	bool uhadnuto,unikatni;
	printf("Zadejte slovo (maximalne 30 znaku)\n");
	fflush(stdout);
	scanf("%s", slovo);
	system("cls");
	delka = strlen(slovo);
	zbyvajici = delka;
	
	//Pokud uživatel zadá velká písmena pøevedou se na malé
	for (i = 0; i < delka; i++) { 
		slovo[i] = tolower(slovo[i]);
	}

	for (i = 0; i < delka; i++) {
		kontrola[i] = slovo[i];
	}

	for (i = 0; i < delka; i++) {
		uhadnuti[i] = '*';
	}
	puts(uhadnuti);
	printf("Zadejte pismeno\n");
	do {
		uhadnuto = false;
		do {
			unikatni = true;
			scanf(" %c", &pismeno);
			for (i = 0; i < delka; i++) {
				if (uhadnuti[i] == pismeno) {
					printf("Toto pismeno uz bylo zadano\n");
					break;
				}
			}
		} while (!unikatni);

		for (i = 0; i < delka; i++) {
			if (uhadnuti[i] == kontrola[i]) {
				kontrola[i] = 'x';
				zbyvajici--;
			}
			if (zbyvajici == 0)uhadnuto = true;
		}

		for (i = 0; i < delka; i++) {
			if (slovo[i] == pismeno) {
					uhadnuti[i] = slovo[i];
			}
		}
		printf("%s", uhadnuti);
	} while (!uhadnuto);
	system("cls");
	printf("Slovo bylo uhadnuto!");
}

void otevreni_obrazku(int cislo) {

	int c;
	char soubor[20];
	sprintf(soubor, ".\\obesenec\\%d.txt", cislo);
	FILE* file;
	file = fopen(soubor, "r");
	if (file) {
		while ((c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
}
