#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include "import.h"

class menu_principal : public QWidget
{
    Q_OBJECT

    QLabel *welcome_msg;
    QLabel *explainations;

    QPushButton *bDepot, *bRetrait, *bAfficherSolde, *bDeconnexion;
    QHBoxLayout *firstLine, *secondLine, *thirdLine, *fourthLine;
    QVBoxLayout *m_vertical;


public:
    //Constructeur
    menu_principal(QWidget *parent = nullptr);


signals:

public slots:
    void disconnect();
    void func_Depot();
    void func_Retrait();
    void func_Solde();
};

#endif // MENU_PRINCIPAL_H
