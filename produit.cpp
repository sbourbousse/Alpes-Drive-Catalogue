#include "produit.h"

Produit::Produit(int unId, QString unLibelle, QString uneImage, QVector<Variete> collectionVarietes)
{
    id=unId;
    libelle=unLibelle;
    image=uneImage;
    lesVarietes=collectionVarietes;
}


QString Produit::getLibelle()
{
    return libelle;
}
