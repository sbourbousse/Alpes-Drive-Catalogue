#include <QApplication>
#include "pdf.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * CONNEXION A LA BASE DE DONNEE
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Alpes_Drive");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();

    //Creer le dossier où mettre les catalogues
    QDir catalogueDir;
    catalogueDir.mkdir("Catalogues");

    PDF* app = new PDF();
    if(app->creerAllCatalogues()==false)
        catalogueDir.rmpath("Catalogues");




    return a.exec();
}
