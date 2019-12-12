#include "vente.h"

Vente::Vente()
{

}

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
    if (unProducteur.getId()==leProducteur.getId())
        return true;
    else
        return false;
}

QString Vente::afficherVente()
{
    QString text = "<tr><td>"+leProducteur.getNomComplet()+"</td><td>"+QString::number(prix)+"</td><td>"+QString::number(quantite)+"</td></tr>";
    return text;
}
