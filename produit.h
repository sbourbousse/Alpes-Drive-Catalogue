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
    Produit();
    Produit(int unId, QString unLibelle, QString uneImage, QVector<Variete> collectionVarietes);
    QString getLibelle();
    QVector<Variete> getVarietes();
    int nbVariete();
    bool isEnVente(Producteur unProducteur);
    QString afficherProduit();
    void chargerVarieteDuClient(QVector<Producteur> desProducteurs);
};

#endif // PRODUIT_H
