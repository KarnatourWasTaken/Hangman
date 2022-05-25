#pragma comment(lib, "winmm.lib")//hudba

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

void singleplayer(void);
void multiplayer(void);
void otevreni_obrazku(int cislo);
void nacteni_slova(void);

char slovo_prave[7] = { 0 };

int main() {

	int volba, reset;
	srand(time(NULL));
	PlaySound(TEXT("hudba.wav"),NULL, SND_ASYNC | SND_LOOP);
	printf("Doporucuji dat aplikaci na celou obrazovku\n\n");
	printf("1. Hra pro jednoho hrace(fungujou pouze anglicka slova)\n");
	printf("2. Hra pro vice hracu (jeden urci slovo druhy hada)\n");
	printf("\n\n\nZdrojovy kod lze najit na: https://github.com/KarnatourWasTaken/Hangman");
	do {
		scanf("%d", &volba);
		switch (volba) {
		case 1:
			reset = 1;
			system("cls");
			singleplayer();
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

void singleplayer() {
	char uhadnuti[7] = { 0 }, pismeno, kontrola[7] = { 0 };
	int i, x = 0, spatne = 0, zbyvajici = 0, obrazek = 0, smrt = 0,delka=5,overeni;
	bool uhadnuto_s, unikatni_s;
	nacteni_slova();
	zbyvajici = delka;
	for (i = 0; i < delka; i++) {
		kontrola[i] = slovo_prave[i];
	}

	for (i = 0; i < delka; i++) {
		uhadnuti[i] = '_';
	}

	printf("%s\n", uhadnuti);
	do {
		uhadnuto_s = false;
		do {
			unikatni_s = true;
			printf("Zadejte pismeno\n");
			scanf(" %c", &pismeno);
			for (i = 0; i < 6; i++) {
				if (uhadnuti[i] == pismeno) {
					printf("Toto pismeno uz bylo zadano\n");
					unikatni_s = false;
				}
			}
		} while (!unikatni_s);

		spatne = 0;

		for (i = 0; i < delka; i++) {
			if (pismeno == slovo_prave[i]) {
			}
			else {
				spatne++;
			}
		}

		for (i = 0; i < delka; i++) {
			if (slovo_prave[i] == pismeno) {
				uhadnuti[i] = slovo_prave[i];
			}
		}

		for (i = 0; i < delka; i++) {
			if (uhadnuti[i] == kontrola[i]) {
				kontrola[i] = 'x';
				zbyvajici--;
			}
			if (zbyvajici == 0)uhadnuto_s = true;
		}

		system("cls");

		if (spatne == delka) {
			obrazek++;
			otevreni_obrazku(obrazek);
		}
		else {
			otevreni_obrazku(obrazek);
		}

		if (obrazek == 7) {
			uhadnuto_s = true;
			smrt = 1;
		}

		printf("%s\n", uhadnuti);

	} while (!uhadnuto_s);
	system("cls");
	if (smrt == 1) {
		printf("Dosli ti pokusy :(\n");
		printf("Hadane slovo bylo %s\n", slovo_prave);
	}
	else {
		printf("Slovo bylo uhadnuto !");
	}
}

void multiplayer() {
	char uhadnuti[60] = { 0 },pismeno, kontrola[60] = { 0 }, slovo[30] = { 0 };
	;
	int i, x = 0, spatne = 0,zbyvajici=0, delka, obrazek=0,smrt=0;
	bool uhadnuto, unikatni;
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
		uhadnuti[i] = '_';
	}
	puts(uhadnuti);
	do {
		uhadnuto = false;
		do {
			unikatni = true;
			printf("Zadejte pismeno\n");
			scanf(" %c", &pismeno);
			for (i = 0; i < delka; i++) {
				if (uhadnuti[i] == pismeno) {
					printf("Toto pismeno uz bylo zadano\n");
					unikatni = false;
				}
			}
		} while (!unikatni);
		spatne=0;
		
		for	(i=0; i < delka; i++){
			if(pismeno == slovo[i]){
			}
			else{
				spatne++;
			}
		}
		
		for (i = 0; i < delka; i++) {
			if (slovo[i] == pismeno) {
					uhadnuti[i] = slovo[i];
			}
		}
		

		for (i = 0; i < delka; i++) {
			if (uhadnuti[i] == kontrola[i]) {
				kontrola[i] = 'x';
				zbyvajici--;
			}
			if (zbyvajici == 0)uhadnuto = true;
		}

		system("cls");

		if (spatne == delka) {
			obrazek++;
			otevreni_obrazku(obrazek);
		}
		else {
			otevreni_obrazku(obrazek);
		}
		
		if (obrazek == 7) {
			uhadnuto = true;
			smrt = 1;
		}

		printf("%s\n", uhadnuti);
		
	} while (!uhadnuto);
	system("cls");
	if (smrt == 1) {
		printf("Dosli ti pokusy :(\n");
		printf("Hadane slovo bylo %s\n", slovo);
	}
	else {
		printf("Slovo bylo uhadnuto !\n");
		printf("Hadane slovo bylo %s\n", slovo);
	}
	
}

void nacteni_slova() {
	FILE* file;
	char slovo[7] = { 0 };
	int radek1, radek2=0;
	radek1 = rand() % 2039;
	file = fopen("slova.txt", "r");
	if (file == NULL) {
		printf("Soubor nelze otevrit zkontrolujte ze nazev souboru je: 'slova.txt'");
	}
	while (fgets(slovo, 7, file))
		if (radek1 == radek2) {
			strcpy(slovo_prave, slovo);
			radek2++;
		}
		else {
			radek2++;
		}
	fclose(file);

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
		printf("\n\n\n");
		fclose(file);
	}
}
