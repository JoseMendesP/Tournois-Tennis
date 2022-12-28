#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "string.h"
#pragma warning (disable: 4996)

#define MIN_TOURNOIS 1
#define MAX_TOURNOIS 10
#define NB_MATCHS_PAR_TOURNOI 127
#define NB_JOUEUSES_PAR_TOURNOI 128
#define LGMOT 30

typedef char Mot[LGMOT + 1];

typedef struct {
    unsigned int indexGagnante;
    unsigned int indexPerdante;
}Match;

typedef struct {
    int points;
    char nom[LGMOT + 1];
}Joueuse;

typedef struct {
    Mot nomTournoi;
    Mot date;
    Match matchs[NB_MATCHS_PAR_TOURNOI];
}Tournoi;

typedef struct {
    int indexTournoi;
    Tournoi dTournois[MAX_TOURNOIS];
    Joueuse dJoueuses[NB_JOUEUSES_PAR_TOURNOI * MAX_TOURNOIS];
    Match dataMatch[NB_MATCHS_PAR_TOURNOI];
} tournoisWTA;

int definir_nombre_tournois() {
    int nbreTournois;
    scanf_s("%i", &nbreTournois);
    assert(nbreTournois >= MIN_TOURNOIS && nbreTournois <= MAX_TOURNOIS);
    return nbreTournois;
}


void enregistrement_tournoi(Tournoi* ins) {
    tournoisWTA tournois;
    Joueuse j1, j2;

    j1.points = 0;
    j2.points = 0;

    scanf_s("%s %i", &ins->nomTournoi, &ins->date);

    strcpy(tournois.dTournois[tournois.indexTournoi].nomTournoi, ins->nomTournoi);
    strcpy(tournois.dTournois[tournois.indexTournoi].date, ins->date);

    tournois.indexTournoi++;

    for (int i = 0; i < NB_JOUEUSES_PAR_TOURNOI; i + 2) {
        scanf_s("%s %s", &j1.nom, &j2.nom);
        strcpy(tournois.dJoueuses[i].nom, j1.nom);
        strcpy(tournois.dJoueuses[i+1].nom, j2.nom);
        tournois.dJoueuses[i].points = j1.points;
        tournois.dJoueuses[i+1].points = j2.points;
    }
}

void afficher_match_tournoi(const tournoisWTA *ins){
    Mot nomDeTournoi, dateTournoi;
    int longueur = definir_nombre_tournois();
    for(int i = 0; i < longueur; i++){
        if(strcmp(ins->dTournois[i].nomTournoi, nomDeTournoi) == 0){
            if(strcmp(ins->dTournois[i].date, dateTournoi) == 0){
                for(int j = 0; j < NB_MATCHS_PAR_TOURNOI; j++){

                    printf("%s %s", ins->dJoueuses[j].nom, ins->dJoueuses[j+1]);
                }
                break;
            }
        }
    }
}

int main() {
    Mot mot;
    while (1) {
        scanf_s("%s", mot);
        if (strcmp(mot, "exit") == 0) {
            exit(1);
        }
        else if (strcmp(mot, "definir_nombre_tournois") == 0) {
            definir_nombre_tournois();
            continue;
        }
        else if (strcmp(mot, "enregistrement_tournois")) {
            continue;
        }
        else if (strcmp(mot, "afficher_matchs_tournois")) {
            afficher_match_tournoi();
            continue;
        }
        else {
            printf("Erreur. Instruction inconnue >%s<");
        }
    }
}

int definir_nombre_tournois();

void enregistrement_tournois(Tournoi* ins);
