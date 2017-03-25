#include <iostream>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include <signal.h>

// pour desactiver les tests : #define NDEBUG
// #define NDEBUG

#ifndef NDEBUG

#include "TestCMatrice.h"

#endif

void handleSIGABRT(int iSignNb)
{
	cout << "TESTS ECHOUES !" << endl;
}


void gregoire()
{
	//CMatrice <double> m = CParseur::PARparserFichier("..\\JePasse\\fichier04.txt");
	//m.MATafficher();
}

void robin()
{
	CMatrice<int> m(2, 2);

	m(0, 0) = 1;
	m(0, 1) = 2;
	m(1, 0) = 3;
	m(1, 1) = 4;

	cout << m << endl;

	m.MATsetNbColonnes(3);

	cout << m << endl;

	// Passent :
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier00.txt");
		cout << m << endl;
		CMatrice <double> m1 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier01.txt");
		cout << m1 << endl;
		CMatrice <double> m2 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier02.txt");
		cout << m2 << endl;
		CMatrice <double> m3 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier03.txt");
		cout << m3 << endl;
		CMatrice <double> m4 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier04.txt");
		cout << m4 << endl;
		CMatrice <double> m5 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier05.txt");
		cout << m5 << endl;
		CMatrice <double> m6 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier06.txt");
		cout << m6 << endl;
		CMatrice <double> m7 = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePasse\\fichier07.txt");
		cout << m7 << endl;
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}

	// Passent pas :
	
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier10.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier11.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier12.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier13.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier14.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier15.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier16.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier17.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier18.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier19.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier110.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier111.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier112.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}
	

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier113.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier114.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier115.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier116.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier117.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier118.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier119.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier120.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier121.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier122.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier123.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

#ifndef NDEBUG

	// Permet d'�viter les messages de crash en cas d'appel a la fonction abort() par assert.h
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	// R�cup�re le signal SIGABRT envoy� par la fonction abort() et fait quelque chose... (un cout en l'occurrence)
	signal(SIGABRT, &handleSIGABRT);

	// Lancement des tests unitaires
	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}