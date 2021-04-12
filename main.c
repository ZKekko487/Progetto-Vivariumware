/***************************************
*Project: B0ss_Fight
*Version: 1.1.1
*Author: Francesco Contini, Matteo Boffa
*Last Modified: 17/03/2021
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int selez;
int hpboss = 30; //vita del boss
int hpplayer = 20; // vita del giocatore
int atkboss = 4; // attacco boss
int randboss;
int atkplayer = 3; // attacco player
int crit; // variabile per verificare colpo critico
int dmgcrit = 3; // danno critico
int cura = 6; // cura del player
int def; // variabile random
char nome [50]; // nome dell'utente

void nomepg (void); // dichiarazione funzione della richiesta nome
void logo (void); // dichiarazione della funzione logo
int selezione (void); // dichiarazione della  funzione della scelta del giocatore
int attboss (void); // dichiarazione della funzione dell attacco del boss
void intro (void); // dichiarazione della funzione della storia

int main(int argc, char *argv[]) {
	
	srand(time(NULL));

	logo(); // stampa del logo a schermo
	
	nomepg(); // funzione richiesta nome

	intro(); //stampa della storia a schermo

	do {
		selezione();
		attboss();
	} while(hpplayer != 0 && hpboss != 0);
	
	if(hpplayer <= 0) {
		printf("Sei stato sconfitto!\nRitenta chiudendo il gioco e riaprendolo.\nGrazie per aver giocato <3");
	} else if(hpboss <= 0) {
		printf("Hai sconfitto il boss, complimenti!\nOra puoi continuare il tuo viaggio a Luxastra.\nGrazie per aver giocato <3");
	}
	return 0;
}

// Logo
void logo (void) {
printf("________                                     ________              ___               \n");
printf("`MMMMMMMb.                                   `MMMMMMM  8b          `MM               \n");
printf(" MM    `Mb                                    MM    \   89           MM         /    \n");
printf(" MM     MM   _____     ____     ____          MM       __   __      MM  __    /M     \n");	
printf(" MM    .M9  6MMMMMb   6MMMMb\   6MMMMb\         MM       MM  6MMbm    MM 6MMb  /MMMMM\n");
printf(" MMMMMMM(  6M'   `Mb MM'    ` MM'    `        MMMMMM   MM 6M'`Mb    MMM  `Mb  MM     \n");	
printf(" MM    `Mb MM     MM YM.      YM.             MM       MM MM  MM    MM'   MM  MM     \n");
printf(" MM     MM MM     MM  YMMMMb   YMMMMb         MM       MM YM.,M9    MM    MM  MM     \n");
printf(" MM     MM MM     MM      `Mb      `Mb        MM       MM  YMM9     MM    MM  MM     \n");	
printf(" MM    .M9 YM.   ,M9 L    ,MM L    ,MM        MM       MM (M        MM    MM  YM.  , \n");	
printf("_MMMMMMM9'  YMMMMM9  MYMMMM9' MYMMMM9'       _MM_     _MM_6YMMMMb. _MM_  _MM_  YMMM9 \n");	
printf("                                                          6M    Yb                   \n");	
printf("                                                          YM.   d9                   \n");	
printf("                                                           YMMMM9                    \n");
printf("-------------------------------------------------------------------------------------\n");
}

// Funzione selezione player
int selezione (void) {
	
	printf("Vita %s: %d		Vita Kailor: %d\n\n", nome, hpplayer, hpboss); // stampa a video della vita
	printf("Seleziona un azione (1 attacco, 2 difesa, 3 cura): ");
	scanf("%d", &selez);
	if(selez > 3 || selez < 1) {	// controllo dell input per verificare che non sia < di 0 o > di 3
		printf("\nNon puoi selezionare questo numero.");
		sleep(2);
		system("cls");
		hpplayer = hpplayer + atkboss; //aggiunta del danno boss per evitare perdita di vita
	}
	
	if(selez == 1) {	// attacco
		crit = rand()%2;
		if (crit == 0) {
			hpboss = hpboss - atkplayer;
			printf("\nHai fatto 3 danni al boss.\n");
			getchar();
			return hpboss;
		} else {
			atkplayer = atkplayer + dmgcrit; // aggiunta del danno critico
			hpboss = hpboss - atkplayer; // applicaizone del danno critico
			atkplayer = atkplayer - dmgcrit; // rimozione del danno critico
			printf("\nHai fatto colpo critico al boss, 6 danni!\n");
			getchar();
		}
	} else if(selez == 2) {	// difesa
		def = rand()%2;
		if (def == 0) {
		printf("\nLa tua difesa non e' stata sufficiente!\n");
		getchar();	
	} else {  
		hpplayer = hpplayer + atkboss;
		printf("\nTi sei difeso con successo!\n");
		getchar();
		}
	} else if(selez == 3) {	// cura
		printf("\nTi stai curando...\n");
		hpplayer = hpplayer + cura;
		if (hpplayer >= 20) { // verifica della vita superiore a 20
			hpplayer = 20;
		}
		sleep(2);
		printf("\nTi sei curato.\n");
		getchar();
	} else if(selez == 13) { // easter egg instawin
		hpboss = hpboss - hpboss;
	}
}


//funzione attacco boss
int attboss (void) {
	
	randboss = rand()%3;
	if (randboss == 0 || randboss == 1) {
		sleep(1);
		printf("\nIl boss ti ha attaccato.");
		hpplayer = hpplayer - atkboss;
		getchar();
		system("cls");
	} else if (randboss == 2 || def != 0) {
		sleep(1);
		printf("\nChe fortuna! Il boss ti ha mancato.");
		getchar();
		system("cls");
	}

}

//storia
void intro (void) {
	printf("\n%s, un giovane ragazzo amante dell'avventura, decise di intraprendere un lungo viaggio nelle terre\n", nome);
	sleep(3);
	printf("desolate della punta Nord di Luxastra, conosciute per il clima estremo e per le pericolose creature che vi abitano.\n");
	sleep(3);
	printf("Girovagando di qua e di la il giovane si imbatte in una grotta e decise di esplorarla.\n");
	sleep(2);
	printf("Non poteva sapere che alla fine della grotta lo attendeva un pericolosissimo Kailor,\n");
	sleep(2);
	printf("zoriade dalle fattezze lucertoloidi, con scaglie robuste e un enorme spada di pietra. \n");
	sleep(2);
	printf("%s sa che dovra sconfiggere la creatura, se vuole continuare il suo viaggio verso Preladia...\n", nome);
	sleep(2);
	printf("\n");
	printf("Cosi inizio' la battaglia.");
	getchar();
	system("cls");
}

// funzione nome custom
void nomepg (void) {
	   printf("Inserisci il nome desiderato: ");
	   gets(nome);
}
