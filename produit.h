#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include<QVector>
#include "variete.h"

class Produit
{
private:
    int id;
    QString libelle;
    QString image;
    QVector<Variete> lesVarietes;
public:
    Produit(int unId, QString unLibelle, QString uneImage, QVector<Variete> collectionVarietes);
    QString getLibelle();
};

#endif // PRODUIT_H
