#include "menu_principal.h"
#include "fenetre_depot.h"
#include "fenetre_retrait.h"
#include "fenetre_solde.h"
#include "connexion.h"

//Constructeur du menu principal
menu_principal::menu_principal(QWidget *parent) : QWidget(parent)
{
    //Instanciation des widgets
    QString wlcm = "Bienvenue ";                //Message de bienvenu
    this->welcome_msg = new QLabel(wlcm, this);

    this->bDepot = new QPushButton("Dépôt", this);
    this->bRetrait = new QPushButton("Retrait", this);
    this->bAfficherSolde = new QPushButton("Solde actuel", this);
    this->bDeconnexion = new QPushButton("Déconnexion", this);


    //On définit la taille maximum (en largeur) des boutons
    bDepot->setMaximumWidth(140);
    bRetrait->setMaximumWidth(140);
    bAfficherSolde->setMaximumWidth(140);
    bDeconnexion->setMaximumWidth(140);

    //Instanciation des layouts
    QVBoxLayout *m_vertical = new QVBoxLayout;
    QHBoxLayout *firstLine = new QHBoxLayout;
    QHBoxLayout *secondLine = new QHBoxLayout;
    QHBoxLayout *thirdLine = new QHBoxLayout;


    QWidget *fenetre = new QWidget(this);

    //Ajout des widgets aux layouts
    firstLine->addWidget(welcome_msg);

    secondLine->addWidget(bDepot);
    secondLine->addWidget(bRetrait);

    thirdLine->addWidget(bAfficherSolde);
    thirdLine->addWidget(bDeconnexion);

    //Ajout des layouts secondaires au layout principal
    m_vertical->addLayout(firstLine);
    m_vertical->addLayout(secondLine);
    m_vertical->addLayout(thirdLine);

    fenetre->setLayout(m_vertical);

    //Liaison entre les widgets et les slots
    connect(this->bDeconnexion,     SIGNAL(clicked()), this,    SLOT(disconnect()));
    connect(this->bDepot,           SIGNAL(clicked()), this,    SLOT(func_Depot()));
    connect(this->bRetrait,         SIGNAL(clicked()), this,    SLOT(func_Retrait()));
    connect(this->bAfficherSolde,   SIGNAL(clicked()), this,    SLOT(func_Solde()));
}


//Avertis le fait que l'utilisateur est bien déconnecté
void menu_principal::disconnect()
{
    QMessageBox deco;
    deco.setText("Votre compte vient d'être déconnecté.");
    deco.setStandardButtons(QMessageBox::Ok);
    deco.exec();

    close();
}


//Créer une fenetre pour le dépot et l'affiche
void menu_principal::func_Depot()
{
    fenetre_depot *fd = new fenetre_depot;

    QDesktopWidget Dw;
    fd->setModal(true);
    fd->setFixedSize(Dw.width() * 0.2, Dw.height() * 0.13);
    fd->setWindowTitle("Dépôt");
    fd->exec();
}


//Créer une fenetre pour le dépot et l'affiche
void menu_principal::func_Retrait()
{
    fenetre_retrait *fr = new fenetre_retrait;

    QDesktopWidget Dw;
    fr->setModal(true);
    fr->setFixedSize(Dw.width() * 0.2, Dw.height() * 0.13);
    fr->setWindowTitle("Retrait");
    fr->exec();
}


//Créer une fenetre pour afficher le solde
void menu_principal::func_Solde()
{
    fenetre_solde *fs = new fenetre_solde;

    QDesktopWidget Dw;
    fs->setModal(true);
    fs->setFixedSize(Dw.width() * 0.2, Dw.height() * 0.5);
    fs->setWindowTitle("Solde");
    fs->exec();
}

