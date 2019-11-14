#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include "producteur.h"

class Client
{
private:
    int id;
    QString nom;
    QString prenom;
    QVector<Producteur> lesProducteurs;


public:
    Client(int unId, QString unNom, QString unPrenom);
    QVector<Producteur> chargerProducteurs();
    QVector<Producteur> getProducteurs();
};

#endif // CLIENT_H
