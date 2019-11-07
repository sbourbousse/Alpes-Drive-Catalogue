#include "vente.h"

Vente::Vente(int unId, Producteur unProducteur, float unPrix, int uneQuantite, QDate uneDateLimiteVente)
{
    id=unId;
    leProducteur=unProducteur;
    prix=unPrix,
    quantite=uneQuantite;
    dateLimiteVente=uneDateLimiteVente;
}
