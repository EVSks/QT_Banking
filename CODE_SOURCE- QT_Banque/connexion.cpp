#include "connexion.h"
#include "menu_principal.h"

//Constructeur de la fenetre de connexion
connexion::connexion(QWidget *parent)
    : QMainWindow(parent)
{

    //Instanciation des widgets
    this->in_id = new QLabel("ID : ", this);
    this->in_pass = new QLabel("Code : ", this);

    this->enter_id = new QLineEdit(this);
    enter_id->setMaximumWidth(200);
    this->enter_pass = new QLineEdit(this);
    enter_pass->setMaximumWidth(200);
    enter_pass->setEchoMode(QLineEdit::Password); //Permet de cacher le texte insérer lors de la saisie

    this->validate = new QPushButton("Valider", this);
    validate->setMaximumWidth(100);
    validate->setDefault(false);

    //Instanciation des layouts
    QVBoxLayout *m_vertical = new QVBoxLayout;
    QHBoxLayout *secondtLine = new QHBoxLayout;
    QHBoxLayout *thirdLine = new QHBoxLayout;
    QHBoxLayout *fourthLine = new QHBoxLayout;

    QWidget *fenetre = new QWidget(this);

    //Ajout des widgets aux layouts
    secondtLine->addWidget(in_id);
    secondtLine->addWidget(enter_id);
    thirdLine->addWidget(in_pass);
    thirdLine->addWidget(enter_pass);
    fourthLine->addWidget(validate);

    //Ajout des layout au layout principal
    m_vertical->addLayout(secondtLine);
    m_vertical->addLayout(thirdLine);
    m_vertical->addLayout(fourthLine);

    //Application du layout principal à la fenetre
    fenetre->setLayout(m_vertical);
    this->setCentralWidget(fenetre);

    //Appel la fonction permettant de vérifier la connexion suite au clic sur le bouton valider
    connect(this->validate, SIGNAL(clicked()), this, SLOT(does_exist()));


}

connexion::~connexion()
{

}

//Définition de la méthode vérifiant si les champs sont remplis et si le compte existe
void connexion::does_exist()
{

    //On vérifie d'abord si les champs sont bien remplis
    if((enter_id->text().isEmpty() || enter_pass->text().isEmpty()))    //Si non, on affiche un message demandant de le faire
    {
        QMessageBox no_inputs;
        no_inputs.setText("Veuillez remplir les champs nécessaires.");
        no_inputs.setStandardButtons(QMessageBox::Ok);
        no_inputs.exec();
    } else

    if(enter_id->text() == "test" && enter_pass->text() == "1234")     //Si oui, on l'indique puis on affiche le menu principal
    {
        QString str = "Vous venez de vous connecter au compte : " + QString("%1").arg(test_name);

        QMessageBox welcome;
        welcome.setText(str);
        welcome.setStandardButtons(QMessageBox::Ok);
        welcome.exec();
       afficher_menu();
    }
    else
    {
        //Affiche une fenetre indiquant que le compte n'existe pas quand on se demande à se connecter
        QMessageBox::StandardButton No_Account = QMessageBox::critical
                                                 ( this, "Erreur de connexion",
                                                   "Ce compte n'existe pas dans notre base de données. Vérifiez votre identifiant et votre code.",
                                                   QMessageBox::Ok | QMessageBox::NoButton );
    }
}

//Cache la fenetre de connexion et ouvre la fenetre du menu principal
void connexion::afficher_menu()
{

    hide();
    menu_principal*menu = new menu_principal;
    QDesktopWidget Dw;
    menu->setFixedSize(Dw.width() * 0.18, Dw.height() * 0.15);
    menu->setWindowTitle("Banque");
    menu->show();

}
