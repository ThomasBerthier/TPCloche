//*********************************************************************************************
//* Programme : main.cpp								Date : 07/12/2021
//*														Dernière MAJ : 07/12/2021
//*--------------------------------------------------------------------------------------------
//*Programmeurs :	BERTHIER Thomas							Classe : BTSSN2
//*					DUVAL Kylian
//*					LIENARD Romain
//*--------------------------------------------------------------------------------------------
//*
//* BUT : Initialise la classe TPCloche.
//*
//*********************************************************************************************
#include "TPCloche.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPCloche w;
    w.show();
    return a.exec();
}
