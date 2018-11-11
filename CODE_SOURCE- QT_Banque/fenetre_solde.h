#ifndef fenetre_solde_H
#define fenetre_solde_H

#include "import.h"

class fenetre_solde : public QDialog
{

    Q_OBJECT

    QLabel *nom;
    QLabel *soldeDisponible;
    QLabel *transactions;

    QLabel *separateur, *separateur2;

    QString spliter = "";

    QVBoxLayout *vertical;

public:
    //Constructeur
    fenetre_solde();

    void affiche_transactions();
};

#endif // fenetre_solde_H
