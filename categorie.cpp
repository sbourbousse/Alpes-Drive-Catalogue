#include "categorie.h"

Categorie::Categorie(int unId, QString unLibelle, QString uneImage, QVector<Produit> collectionProduits)
{
    id=unId;
    libelle=unLibelle;
    image=uneImage;
    lesProduits=collectionProduits;
}

QString Categorie::getLibelle()
{
    //Renvoie la catégorie sous forme HTML
    return libelle;
}

QVector<Produit> Categorie::getProduits()
{
    return lesProduits;
}

bool Categorie::isEnVente(Producteur unProducteur)
{
    bool valid = false;
    if(nbProduit()>0)
    {
        for(int i = 0 ; i<nbProduit() ; i++)
        {
            if(lesProduits[i].isEnVente(unProducteur)==true)
                valid=true;
        }
    }

    return true;
}

int Categorie::nbProduit()
{
    return lesProduits.size();
}

void Categorie::chargerProduitDuClient(QVector<Producteur> desProducteurs)
{
    QVector<Produit> produitDuClient;

    for(int i = 0 ; i<lesProduits.size() ; i++)
    {
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if(lesProduits[i].isEnVente(desProducteurs[i]))
            {
                produitDuClient.push_back(lesProduit[i]);
                produitDuClient.last().chargerVarieteDuClient(desProducteurs);
            }
        }
    }
    lesProduits=produitDuClient;
}

