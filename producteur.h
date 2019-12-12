#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include <QString>

class Producteur
{
private:
    int id;
    QString nom;
    QString prenom;
    //QVector<Vente> lesVentes;
public:
    Producteur();
    Producteur(int unId, QString unNom, QString unPrenom);
    int getId();
    QString getNomComplet();

};

#endif // PRODUCTEUR_H
