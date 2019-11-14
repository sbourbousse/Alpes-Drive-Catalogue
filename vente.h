#ifndef VENTE_H
#define VENTE_H

#include <QString>
#include <QDate>
#include "variete.h"
#include "producteur.h"

class Vente
{
private:
    int id;
    Producteur leProducteur;
    float prix;
    int quantite;
    QDate dateLimiteVente;

public:
    Vente(int unId, Producteur unProducteur, float unPrix, int uneQuantite, QDate uneDateLimiteVente);
    bool verifProd(Producteur unProducteur);
};

#endif // VENTE_H
