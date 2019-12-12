#include "categorie.h"

Categorie::Categorie()
{

}

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

QString Categorie::afficherCategorie()
{
    //A faire : ajouter les images

    QString text = "<div ><center class=\"test\"><h1><u>"+libelle+"</u></h1></center>";

    for(int i = 0 ; i<lesProduits.size() ; i++)
    {
        text += lesProduits[i].afficherProduit();
    }

    text+= "</div>";

    return text;
}

void Categorie::chargerProduitDuClient(QVector<Producteur> desProducteurs)
{
    QVector<Produit> produitDuClient;

    bool produitAjoute;

    for(int i = 0 ; i<lesProduits.size() ; i++)
    {
        produitAjoute=false;
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if((lesProduits[i].isEnVente(desProducteurs[j]))&&(produitAjoute==false))
            {
                produitDuClient.push_back(lesProduits[i]);
                produitDuClient.last().chargerVarieteDuClient(desProducteurs);
                produitAjoute=true;
            }
        }
    }
    lesProduits=produitDuClient;
}

