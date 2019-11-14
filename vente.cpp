#include "vente.h"

Vente::Vente(int unId, Producteur unProducteur, float unPrix, int uneQuantite, QDate uneDateLimiteVente)
{
    id=unId;
    leProducteur=unProducteur;
    prix=unPrix,
    quantite=uneQuantite;
    dateLimiteVente=uneDateLimiteVente;
}

bool Vente::verifProd(Producteur unProducteur)
{
    if (unProducteur==leProducteur)
        return true;
    else
        return false;
}
