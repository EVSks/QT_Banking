#include "fenetre_solde.h"

fenetre_solde::fenetre_solde()
{

    QDesktopWidget Dw; //Permet de récupérer les informations de l'écran

    //Permet de générer des tirets selon la largeur de la fenetre créé
    int splitter_size = 0;
    while(splitter_size < (Dw.width() * 0.2) )
    {
        spliter = spliter + "-  ";
        splitter_size += 15;
    }

    //Instanciation des widgets
    this->nom = new QLabel("Nom : ", this);
    this->soldeDisponible = new QLabel("Solde actuel :", this);
    this->transactions = new QLabel("5 dernières transactions : ", this);

    this->separateur = new QLabel(spliter, this);
    this->separateur2 = new QLabel(spliter, this);

    //Instanciation des layouts
    vertical = new QVBoxLayout;

    //Ajout des widgets aux layouts
    vertical->addWidget(nom);
    vertical->addWidget(separateur);
    vertical->addWidget(soldeDisponible);
    vertical->addWidget(separateur2);
    vertical->addWidget(transactions);

    //On définis cette fenetre comme étant une interface utilisateur
    QWidget *fenetre;
    fenetre = new QWidget(this);

    //Définis vertical comme étant le layout principal
    fenetre->setLayout(vertical);
}

void fenetre_solde()
{
    /**Code permettant d'afficher les 5 dernières transactions effectuées
      **/
}
