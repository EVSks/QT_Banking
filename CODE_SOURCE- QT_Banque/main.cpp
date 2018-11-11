#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget Dw; //Permet de récupérer les informations de l'écran

    double w_width = Dw.width() * 0.2;
    double w_height = Dw.height() * 0.2;
    connexion w;

    w.setFixedSize(w_width, w_height);
    w.setWindowTitle("Connexion");
    w.show();

    return a.exec();
}
