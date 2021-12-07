//*********************************************************************************************
//* Programme : TPCloche.cpp								Date : 07/12/2021
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
#include "TPCloche.h"

TPCloche::TPCloche(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//Liaison entre le pc et la ETZ510
	socket = new QTcpSocket(this);
	socket->connectToHost("192.168.64.124", 502);
	//Connexion signaux/slots
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
	
	//Ajouts de raccourcis clavier comme signaux
	QShortcut * shortcut = new QShortcut(QKeySequence(Qt::Key_1), this, SLOT(cloche1()));
	shortcut->setAutoRepeat(false);

	QShortcut * shortcut2 = new QShortcut(QKeySequence(Qt::Key_2), this, SLOT(cloche2()));
	shortcut2->setAutoRepeat(false);

	QShortcut * shortcut3 = new QShortcut(QKeySequence(Qt::Key_3), this, SLOT(cloche3()));
	shortcut3->setAutoRepeat(false);

	QShortcut * shortcut4 = new QShortcut(QKeySequence(Qt::Key_4), this, SLOT(cloche4()));
	shortcut4->setAutoRepeat(false);
}
//Message de connexion
void TPCloche::socketConnected() {
	ui.log->addItem("Connecter");
}
//Message de déconnexion
void TPCloche::socketDisconnected()
{
	ui.log->addItem("Deconnecter");
}
//Active et désactive la cloche 1
void TPCloche::cloche1()
{
	ui.log->addItem("Cloche 1 On");
	char Cloche1On[12];
	Cloche1On[0] = 0x00;
	Cloche1On[1] = 0x01;
	Cloche1On[2] = 0x00;
	Cloche1On[3] = 0x00;
	Cloche1On[4] = 0x00;
	Cloche1On[5] = 0x06;
	Cloche1On[6] = 0x11;
	Cloche1On[7] = 0x06;
	Cloche1On[8] = 0x00;
	Cloche1On[9] = 0x02;
	Cloche1On[10] = 0x00;
	Cloche1On[11] = 0x01;
	QByteArray dataOn(Cloche1On, 12);
	socket->write(dataOn);

	ui.log->addItem("Cloche 1 Off");
	char Cloche1Off[12];
	Cloche1Off[0] = 0x00;
	Cloche1Off[1] = 0x01;
	Cloche1Off[2] = 0x00;
	Cloche1Off[3] = 0x00;
	Cloche1Off[4] = 0x00;
	Cloche1Off[5] = 0x06;
	Cloche1Off[6] = 0x11;
	Cloche1Off[7] = 0x06;
	Cloche1Off[8] = 0x00;
	Cloche1Off[9] = 0x02;
	Cloche1Off[10] = 0x00;
	Cloche1Off[11] = 0x00;
	QByteArray dataOff(Cloche1Off, 12);
	socket->write(dataOff);
}

//Active et désactive la cloche 2
void TPCloche::cloche2()
{
	ui.log->addItem("Cloche 2 On");
	char Cloche2On[12];
	Cloche2On[0] = 0x00;
	Cloche2On[1] = 0x01;
	Cloche2On[2] = 0x00;
	Cloche2On[3] = 0x00;
	Cloche2On[4] = 0x00;
	Cloche2On[5] = 0x06;
	Cloche2On[6] = 0x11;
	Cloche2On[7] = 0x06;
	Cloche2On[8] = 0x00;
	Cloche2On[9] = 0x02;
	Cloche2On[10] = 0x00;
	Cloche2On[11] = 0x02;

	QByteArray dataOn(Cloche2On, 12);
	socket->write(dataOn);

	ui.log->addItem("Cloche 2 Off");
	char Cloche2Off[12];
	Cloche2Off[0] = 0x00;
	Cloche2Off[1] = 0x01;
	Cloche2Off[2] = 0x00;
	Cloche2Off[3] = 0x00;
	Cloche2Off[4] = 0x00;
	Cloche2Off[5] = 0x06;
	Cloche2Off[6] = 0x11;
	Cloche2Off[7] = 0x06;
	Cloche2Off[8] = 0x00;
	Cloche2Off[9] = 0x02;
	Cloche2Off[10] = 0x00;
	Cloche2Off[11] = 0x00;

	QByteArray dataOff(Cloche2Off, 12);
	socket->write(dataOff);
}

//Active et désactive la cloche 3
void TPCloche::cloche3()
{
	ui.log->addItem("Cloche 3 On");
	char Cloche3On[12];
	Cloche3On[0] = 0x00;
	Cloche3On[1] = 0x01;
	Cloche3On[2] = 0x00;
	Cloche3On[3] = 0x00;
	Cloche3On[4] = 0x00;
	Cloche3On[5] = 0x06;
	Cloche3On[6] = 0x11;
	Cloche3On[7] = 0x06;
	Cloche3On[8] = 0x00;
	Cloche3On[9] = 0x02;
	Cloche3On[10] = 0x00;
	Cloche3On[11] = 0x04;

	QByteArray dataOn(Cloche3On, 12);
	socket->write(dataOn);

	ui.log->addItem("Cloche 3 Off");
	char Cloche3Off[12];
	Cloche3Off[0] = 0x00;
	Cloche3Off[1] = 0x01;
	Cloche3Off[2] = 0x00;
	Cloche3Off[3] = 0x00;
	Cloche3Off[4] = 0x00;
	Cloche3Off[5] = 0x06;
	Cloche3Off[6] = 0x11;
	Cloche3Off[7] = 0x06;
	Cloche3Off[8] = 0x00;
	Cloche3Off[9] = 0x02;
	Cloche3Off[10] = 0x00;
	Cloche3Off[11] = 0x00;

	QByteArray dataOff(Cloche3Off, 12);
	socket->write(dataOff);
}

//Active et désactive la cloche 4
void TPCloche::cloche4()
{
	ui.log->addItem("Cloche 4 On");
	char Cloche4On[12];
	Cloche4On[0] = 0x00;
	Cloche4On[1] = 0x01;
	Cloche4On[2] = 0x00;
	Cloche4On[3] = 0x00;
	Cloche4On[4] = 0x00;
	Cloche4On[5] = 0x06;
	Cloche4On[6] = 0x11;
	Cloche4On[7] = 0x06;
	Cloche4On[8] = 0x00;
	Cloche4On[9] = 0x02;
	Cloche4On[10] = 0x00;
	Cloche4On[11] = 0x08;

	QByteArray dataOn(Cloche4On, 12);
	socket->write(dataOn);

	ui.log->addItem("Cloche 4 Off");
	char Cloche4Off[12];
	Cloche4Off[0] = 0x00;
	Cloche4Off[1] = 0x01;
	Cloche4Off[2] = 0x00;
	Cloche4Off[3] = 0x00;
	Cloche4Off[4] = 0x00;
	Cloche4Off[5] = 0x06;
	Cloche4Off[6] = 0x11;
	Cloche4Off[7] = 0x06;
	Cloche4Off[8] = 0x00;
	Cloche4Off[9] = 0x02;
	Cloche4Off[10] = 0x00;
	Cloche4Off[11] = 0x00;

	QByteArray dataOff(Cloche4Off, 12);
	socket->write(dataOff);
}
