#ifndef fenetre_retrait_H
#define fenetre_retrait_H

#include "import.h"

class fenetre_retrait : public QDialog
{

    Q_OBJECT

    QLabel *soldeDisponible;
    QLabel *montant;

    QLineEdit *in_montant;

    QPushButton *bValider, *bRetour;

    QVBoxLayout *vertical;
    QHBoxLayout *h1, *h2, *h3;

public:
    //Constructeur
    fenetre_retrait();

    void process_retrait();
};

#endif // fenetre_retrait_H
