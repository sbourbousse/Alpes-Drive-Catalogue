#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>
#include <QVector>
#include "produit.h"

class Categorie
{
private:
    int id;
    QString libelle;
    QString image;
    QVector<Produit> lesProduits;
public:
    Categorie(int unId, QString unLibelle, QString uneImage, QVector<Produit> collectionProduits);
    QString getLibelle();
};

#endif // CATEGORIE_H
