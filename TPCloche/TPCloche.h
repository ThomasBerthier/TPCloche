//*********************************************************************************************
//* Programme : TPCloche.h								Date : 07/12/2021
//*														Dernière MAJ : 07/12/2021
//*--------------------------------------------------------------------------------------------
//*Programmeurs :	BERTHIER Thomas							Classe : BTSSN2
//*					DUVAL Kylian
//*					LIENARD Romain
//*--------------------------------------------------------------------------------------------
//*
//* BUT : Permet de faire sonner les cloches grace à des boutons sur l'UI ou en appyuant sur des touches du clavier.
//*
//*********************************************************************************************
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TPCloche.h"
#include <qtcpsocket.h>
#include <qshortcut.h>

class TPCloche : public QMainWindow
{
    Q_OBJECT

public:
    TPCloche(QWidget *parent = Q_NULLPTR);

private:
    Ui::TPClocheClass ui;
	QTcpSocket * socket;
	

public slots:
	void socketConnected();
	void socketDisconnected();
	void cloche1();
	void cloche2();
	void cloche3();
	void cloche4();
};
