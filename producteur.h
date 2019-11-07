#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include <QString>

class Producteur
{
private:
    int id;
    QString nom;
    QString prenom;
public:
    Producteur(int unId, QString unNom, QString unPrenom);
};

#endif // PRODUCTEUR_H
