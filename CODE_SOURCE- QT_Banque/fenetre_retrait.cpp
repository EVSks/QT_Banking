#include "fenetre_retrait.h"

fenetre_retrait::fenetre_retrait()
{
    //Instanciation des widgets
    this->soldeDisponible = new QLabel("Vous disposez de x €", this);
    this->montant = new QLabel("Montant à retirer :", this);

    this->in_montant = new QLineEdit(this);

    this->bValider = new QPushButton("Valider", this);
    this->bRetour = new QPushButton("Retour", this);

    //Instanciation des layouts
    vertical = new QVBoxLayout();
    h1 = new QHBoxLayout();
    h2 = new QHBoxLayout();
    h3 = new QHBoxLayout();

    //Ajout des widgets aux layouts
    h1->addWidget(montant);
    h1->addWidget(in_montant);
    h2->addWidget(bValider);
    h2->addWidget(bRetour);

    h3->addWidget(soldeDisponible);

    //Ajout des layouts au layout principal
    vertical->addLayout(h3);
    vertical->addLayout(h1);
    vertical->addLayout(h2);

    //On définis cette fenetre comme étant une interface utilisateur
    QWidget *fenetre;
    fenetre = new QWidget(this);

    //Définis vertical comme étant le layout principal
    fenetre->setLayout(vertical);

    connect(this->bRetour, SIGNAL(clicked()), this, SLOT(close())); //On ferme la fenetre quand on clique sur Retour

}

void fenetre_retrait::process_retrait()
{
    /**Code permettant de retirer le montant saisie au solde
        Il faudra vérifier si ce qui est saisi est bien un nombre de type float
        On indiquera le fait que le solde a bien été modifié
      **/
}
