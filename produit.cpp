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

QVector<Variete> Produit::getVarietes()
{
    return lesVarietes;
}

int Produit::nbVariete()
{
    return lesVarietes.size();
}

bool Produit::isEnVente(Producteur unProducteur)
{
    bool valid=false;
    if(nbVariete()>0)
    {
        for(int i = 0 ; i<nbVariete() ; i++)
        {
            if(lesVarietes[i].isEnVente(unProducteur)==true)
                valid=true;
        }
    }

    return valid;
}

void Produit::chargerVarieteDuClient(QVector<Producteur> desProducteurs)
{
    QVector<Variete> varieteDuClient;

    for(int i = 0 ; i<lesVarietes ; i++)
    {
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if(lesVarietes[i].isEnVente(desProducteurs[i]))
            {
                varieteDuClient.push_back(lesProduit[i]);
                varieteDuClient.last().chargerVenteDuClient(desProducteurs);
            }
        }
    }
    lesVarietes=varieteDuClient;
}

/*QString Produit::afficherProduit()
{
    QString text = "<div><h1>"+libelle+"</h1>";
    for(int i = 0 ; i<nbVariete() ; i++)
    {

    }
}*/
