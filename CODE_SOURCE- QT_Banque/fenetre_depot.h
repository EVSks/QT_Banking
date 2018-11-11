#ifndef fenetre_depot_H
#define fenetre_depot_H

#include "import.h"

class fenetre_depot : public QDialog
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
    fenetre_depot();

    void process_depot();
};

#endif // fenetre_depot_H
