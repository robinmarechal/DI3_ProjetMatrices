#include "TableauAssociatif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cexception.h"

#define NON_DEFINI 0
#define ENTIER 1
#define REEL 2
#define CHAINE 3

/*

Valeur : {
	double dReel;
	int iEntier;
	char * pcChaine;
} Valeur;

Attributs :
	char ** ppcTABcles;
	Valeur * pvTABvaleurs;
	unsigned int uiTABnbElements;
	unsigned int * puiTypes;
*/


void CTableauAssociatif::TABinit() 
{
	ppcTABcles = NULL;
	pvTABvaleurs = NULL;
	puiTypes = NULL;
	uiTABnbElements = 0;
}

void CTableauAssociatif::TABdetruire() 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		free(ppcTABcles[uiBoucle]);
		if(puiTypes[uiBoucle] == CHAINE)
			free(pvTABvaleurs[uiBoucle].pcChaine);
	}

	free(ppcTABcles);
	free(pvTABvaleurs);
	free(puiTypes);
}

CTableauAssociatif::CTableauAssociatif() 
{
	TABinit();
}

CTableauAssociatif::CTableauAssociatif(CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
	}
}

CTableauAssociatif::~CTableauAssociatif() 
{
	TABdetruire();
}

CTableauAssociatif & CTableauAssociatif::operator=(CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABdetruire();
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
	}

	return *this;
}

// precond : pcCle est bien dans le tableau
Valeur & CTableauAssociatif::operator[](char * pcCle) 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}

void CTableauAssociatif::TABajouter(char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	uiTABnbElements++;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char*));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, uiTABnbElements * sizeof(unsigned int));

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		throw Cexception(0, "TABsupprimerElement() : Echec de reallocation");
	}


	ppcTABcles[uiTABnbElements - 1] = _strdup(pcCle);
	pvTABvaleurs[uiTABnbElements - 1] = vValeur;
	puiTypes[uiTABnbElements - 1] = uiType;
}

bool CTableauAssociatif::TABestNumerique(char * pcVal)
{
	bool bPoint = false;

	// si le pointeur est null, ou la chaine est vide, ce n'est pas un nombre
	if (pcVal == NULL || *pcVal == '\0')
		return false;

	while (*pcVal != '\0')
	{
		// S'il y a un point ou une virgule, on met bPoint � true pour s'assurer qu'il n'y ai qu'un/une
		// Si le charact�re est un point ou une virgule et que bPoint est true, alors ce n'est pas un bombre
		if (*pcVal == '.' || *pcVal == ',')
		{
			if (bPoint)
				return false;
			else
				bPoint = true;
		}
		// Si le caract�re n'est pas un point ou une virgule, et qu'il n'est pas compris
		// entre 0 et 9, alors ce n'est pas un nombre
		else if (*pcVal < '0' || *pcVal > '9')
		{
			return false;
		}

		pcVal++;
	}

	// Tout s'est bien pass�, c'est donc un nombre
	return true;
}

// precond : l'utilisateur a d�j� verifi� que la chaine est un nombre
bool CTableauAssociatif::TABestEntier(char * pcVal)
{
	/*
	// pcCle est un entier s'il n'y a ni point, ni virgule
	if (strchr(pcVal, ',') == NULL && strchr(pcVal, '.') == NULL)
	{
		return true;
	}
	else
	{
		// ...ou si il/elle est plac� � la fin (rien derri�re)
		if (pcVal[strlen(pcVal) - 1] == '.' || pcVal[strlen(pcVal) - 1] == ',')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	*/
	return (strchr(pcVal, ',') == NULL) && (strchr(pcVal, '.') == NULL);
}

void CTableauAssociatif::TABsupprimer(char * pcCle) 
{
	unsigned int uiBoucle;
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	// On d�cale tout ce qui est � droite de uiPos d'une case vers la gauche
	for (uiBoucle = uiPos; uiBoucle < uiTABnbElements - 1; uiBoucle++)
	{
		free(ppcTABcles[uiBoucle]);
		ppcTABcles[uiBoucle] = _strdup(ppcTABcles[uiBoucle + 1]);
		pvTABvaleurs[uiBoucle] = pvTABvaleurs[uiBoucle + 1];
		puiTypes[uiBoucle] = puiTypes[uiBoucle + 1];
	}

	uiTABnbElements--;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char *));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, sizeof(unsigned int) * uiTABnbElements);

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		throw Cexception(0, "TABsupprimerElement() : Echec de reallocation");
	}

}

// precond : pcCle est bien dans le tableau
void CTableauAssociatif::TABmodifier(char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	pvTABvaleurs[uiPos] = vValeur;
	puiTypes[uiPos] = uiType;
}

void CTableauAssociatif::TABajouterEntier(char * pcCle, int iVal) 
{
	Valeur vVal;
	vVal.iEntier = iVal;
	TABajouter(pcCle, vVal, ENTIER);
}

void CTableauAssociatif::TABajouterReel(char * pcCle, double dVal) 
{
	Valeur vVal;
	vVal.dReel = dVal;
	TABajouter(pcCle, vVal, REEL);
}

void CTableauAssociatif::TABajouterChaine(char * pcCle, char * pcVal) 
{
	Valeur vVal;
	vVal.pcChaine = pcVal;
	TABajouter(pcCle, vVal, CHAINE);
}

void CTableauAssociatif::TABajouterAuto(char * pcCle, char * pcVal)
{
	if (TABestNumerique(pcVal))
	{
		// Format : XX
		if (TABestEntier(pcVal))
		{
			// On parse la chaine en int
			int iVal = atoi(pcVal);
			// on l'ajoute au tableau
			TABajouterEntier(pcCle, iVal);
		}
		// Format : XX.XX || XX,XX
		else
		{
			// On rajoute un 0 au d�but et � la fin pour etre sur d'�viter les probl�mes pour convertir
			unsigned int uiBoucle;
			int iTaille = strlen(pcVal);
			char * pcStr = new char[iTaille + 3];

			for (uiBoucle = 0; uiBoucle < iTaille + 2; uiBoucle++)
			{
				pcStr[uiBoucle] = '0';
			}
			pcStr[iTaille + 2] = '\0';

			strcpy(pcStr + 1, pcVal);
			*strchr(pcStr, '\0') = '0';

			// On remplace ',' par '.' s'il faut
			if (strchr(pcStr, ',') != NULL)
				pcStr[strchr(pcStr, ',') - pcStr] = '.';

			// On parse la chaine en double;
			double dVal = atof(pcStr);
			// on l'ajoute au tableau
			TABajouterReel(pcCle, dVal);

			delete[] pcStr;
		}
	}
	else
	{
		// on ajoute simplement la chaine
		TABajouterChaine(pcCle, pcVal);
	}
}

unsigned int CTableauAssociatif::TABgetNbElements() const 
{
	return uiTABnbElements;
}

int CTableauAssociatif::TABgetIndiceCle(char * pcCle) const 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		if (strcmp(ppcTABcles[uiBoucle], pcCle) == 0)
		{
			return uiBoucle;
		}
	}

	return -1;
}

// precond : 0 < uiPos < uiTABnbElements
const char const * CTableauAssociatif::TABgetCle(unsigned int uiPos) const 
{
	return ppcTABcles[uiPos];
}

// precond : pcCle est bien dans le tableau
Valeur CTableauAssociatif::TABgetValeur(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}

// precond : 0 < uiPos < uiTABnbElements
Valeur CTableauAssociatif::TABgetValeurPos(unsigned int uiPos)
{
	return pvTABvaleurs[uiPos];
}

// precond : 0 < uiPos < uiMATnbElements
unsigned int CTableauAssociatif::TABgetValeurType(unsigned int uiPos)
{
	return puiTypes[uiPos];
}

// precond :pcCle est dans le tableau
unsigned int CTableauAssociatif::TABgetValeurType(char * pcCle)
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return TABgetValeurType(uiPos);
}

// precond :pcCle est dans le tableau
int CTableauAssociatif::TABgetValeurEntier(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].iEntier;
}

// precond :pcCle est dans le tableau
double CTableauAssociatif::TABgetValeurReel(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].dReel;
}

// precond :pcCle est dans le tableau
char * CTableauAssociatif::TABgetValeurChaine(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].pcChaine;
}