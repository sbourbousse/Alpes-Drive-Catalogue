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

