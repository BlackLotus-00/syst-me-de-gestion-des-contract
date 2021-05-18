#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ContactInfo {
	char Nom[21];
	char Tel[11];
	char email[26];
}contact;

//Creation de l'arbre
struct ArbreNeoud {
	contact info;
	struct ArbreNeoud *avant;
	struct ArbreNeoud *suivant;
};



struct ArbreNeoud * AjouterContact(struct ArbreNeoud *p, contact e);
struct ArbreNeoud * CreationNoeud (struct ArbreNeoud *q, struct ArbreNeoud *r, contact e);
struct ArbreNeoud * SupprimerNoeud (struct ArbreNeoud *p, char NomSupprimer[]);
struct ArbreNeoud * TrouverMin(struct ArbreNeoud *p);
struct ArbreNeoud * ModifierNoeud (struct ArbreNeoud *p, char NomModifier[]);
void RechercheContact(struct ArbreNeoud *p, char NomRechercher[]);
void AfficherArbre(struct ArbreNeoud *p);





int main(void)
{
	int choix = 0; /*Variable for option selection.*/
	contact e;  /*Basic phone book entry*/
	struct ArbreNeoud *p = NULL; /*Basic tree node*/
	char NomFunction[50]; /*Used for deletions, editing, and searching*/


    printf(" ----------------------------------------------------------- \n");
    printf("|                                                           |\n");
    printf("|                   Annuaire telephonique                   |\n");
    printf("|                                                           |\n");
    printf(" ----------------------------------------------------------- \n");



	/*Return to menu after each instruction until the user quits.*/
	while (choix != 6) {
		/*Show user the option menu.*/
		printf("|                            MENU                           |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 1 |                   Nouveau contact                     |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 2 |                Supprimer un contact                   |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 3 |                Modifier un  contact                   |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 4 |                     Rechercher                        |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 5 |            Afficher toutes les contact                |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 6 |                      Quitter                          |\n");
		printf(" ----------------------------------------------------------- \n");

		printf("\nEntrer votre choix : >> ");
		scanf("%d", &choix);
		if (choix == 1) {
			printf("Entrer le nom complet: ");
			scanf("%s", e.Nom);
			printf("Enter le numero: ");
			scanf("%s", e.Tel);
			printf("Entrer the e-mail address: ");
			scanf("%s", e.email);
			p = AjouterContact(p, e);
			printf("Contact ajouter.\n\n");
		}
		else if (choix == 2) {
			printf("Entrer le nom: ");
			scanf("%s", NomFunction);
			p = SupprimerNoeud(p, NomFunction);
		}
		else if (choix == 3) {

			printf("Please enter the last name: ");
			scanf("%s", NomFunction);
			p = ModifierNoeud(p, NomFunction);
		}
		else if (choix == 4) {
			printf("Please enter the last name: ");
			scanf("%s", NomFunction);
			RechercheContact(p, NomFunction);
		}
		else if (choix == 5) {
			AfficherArbre(p);
		}
		else if (choix == 6) {
			break;
		}
		else {
			printf("That option does not exist. Please try again.\n\n");
		}

	}
	return 0;
}


//Ajouter un contact
struct ArbreNeoud * AjouterContact(struct ArbreNeoud *p, contact e) {

	//si l'arbre est vide
	if (p == NULL) {
		//creation
		p = CreationNoeud(NULL, NULL, e);
	}

	//le contact à ajouter sera cree avant
	else if (strcmp(e.Nom, p->info.Nom) < 0) {
		p->avant = AjouterContact(p->avant, e);
	}

	else{
		//le contact à ajouter sera cree après
		p->suivant = AjouterContact(p->suivant, e);
	}

	return p;
}

//creation d'un nouveau Noeud
struct ArbreNeoud * CreationNoeud (struct ArbreNeoud *q, struct ArbreNeoud *r, contact e) {
	struct ArbreNeoud* NouveauNeoud;
	NouveauNeoud = (struct ArbreNeoud*)(malloc(sizeof(struct ArbreNeoud)));
	NouveauNeoud->info = e;
	NouveauNeoud->avant = q;
	NouveauNeoud->suivant = r;
	return NouveauNeoud;
}


//Supprimer noeud
struct ArbreNeoud * SupprimerNoeud (struct ArbreNeoud *p, char NomSupprimer[]) {
    //chercher la position de NomSupprimer
    //le nom se trouve avant
	if (strcmp(NomSupprimer, p->info.Nom) < 0 ) {
		p->avant = SupprimerNoeud(p->avant,NomSupprimer);
	}
	else if (strcmp(NomSupprimer, p->info.Nom) > 0) {
		p->suivant = SupprimerNoeud(p->suivant, NomSupprimer);
	}

	else if (p->avant != NULL && p->avant != NULL) {

		p->info = TrouverMin(p->suivant)->info;
		p->suivant = SupprimerNoeud(p->suivant, NomSupprimer);
		printf("Contact supprimé avec succès .\n\n");
	}

	else if (p->avant != NULL) {

		p = p->avant;

		printf("Contact supprimé avec succès.\n\n");
	}

	else if (p->suivant != NULL) {

		p = p->suivant;

		printf("Contact supprimé avec succès.\n\n");
	}

	else {

		printf("Le contact n'existe pas.\n\n");
	}

	return p;
}

struct ArbreNeoud * TrouverMin(struct ArbreNeoud *p) {

	if (p->avant != NULL) {

		TrouverMin(p->avant);
	}

	return p;
}

struct ArbreNeoud * ModifierNoeud (struct ArbreNeoud*p, char NomModifier[]) {
	char num[11];
	char e[26];
	if (strcmp(NomModifier, p->info.Nom) < 0) {
		//chercher avant
		ModifierNoeud(p->avant,NomModifier);
	}

	else if (strcmp(NomModifier, p->info.Nom) > 0) {
		//chercher suivant
		ModifierNoeud(p->suivant, NomModifier);
	}
	//le contact est trouvé
	else if (strcmp(NomModifier, p->info.Nom) == 0) {

		printf("Voulez vous modifer le numero du contact :(o/n) >>");
		scanf("%s", num);

		if (strcmp(num, "n") == 0) {
			printf("Voulez vous modifer l'adresse mail du contact :(o/n) >>");
			scanf("%s", e);

			if (strcmp(e, "n") == 0) {

				printf("Contact modifier avec succès.\n\n");

				return p;
			}

			else {

				strcpy(p->info.email, e);

				printf("Contact modifier avec succès.\n\n");
			}
		}

		else {

			strcpy(p->info.Tel, num);

			printf("Voulez vous modifer l'adresse mail du contact :(o/n) >>");
			scanf("%s", e);

			if (strcmp(e, "n") == 0) {

				printf("Contact modifier avec succès.\n\n");

				return p;
			}

			else {

				strcpy(p->info.email, e);

				printf("Contact modifier avec succès.\n\n");
			}
		}
	}

	else {

		printf("Contact n'existe pas.\n\n");
	}

	return p;
}

void RechercheContact(struct ArbreNeoud *p, char NomRechercher[]) {
	//La recherche
	if (strcmp(NomRechercher, p->info.Nom) < 0) {

		RechercheContact(p->avant, NomRechercher);
	}

	else if (strcmp(NomRechercher, p->info.Nom) > 0) {

		RechercheContact(p->suivant, NomRechercher);
	}

	//Contact Trouver
	else if (strcmp(NomRechercher, p->info.Nom) == 0) {

		printf("%s, %s, %s\n\n", p->info.Nom, p->info.Tel, p->info.email);
	}
	//Contact non Trouver
	else {

		printf("n'existe pas.\n\n");
	}
}


void AfficherArbre(struct ArbreNeoud *p)
{

	if (p != NULL) {
		AfficherArbre(p->avant);
		printf("*****************************************");
		printf("%s, %s, %s \n\n",p->info.Nom,p->info.Tel, p->info.email );
		AfficherArbre(p->suivant);
	}
}
