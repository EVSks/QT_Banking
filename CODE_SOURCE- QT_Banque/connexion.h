#ifndef connexion_H
#define connexion_H

#include "import.h"

class connexion : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *instructions;
    QLabel *in_id;
    QLabel *in_pass;

    QLineEdit *enter_id;
    QLineEdit *enter_pass;

    QPushButton *validate;

    QVBoxLayout *m_vertical;

    QHBoxLayout *firstLine;
    QHBoxLayout *secondtLine;
    QHBoxLayout *thirdLine;
    QHBoxLayout *fourthLine;

    QWidget *fenetre;

public slots:
        void afficher_menu();
        void does_exist();

public:

        //Initialisation des variables de test
        QString test_name = "test";
        QString pass = "1234";

    //Constructeur
    connexion(QWidget *parent = 0);

    //Destructeur
    ~connexion();

};

#endif // connexion_H
