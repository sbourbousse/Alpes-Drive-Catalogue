#include "variete.h"

Variete::Variete(int unId, QString unLibelle, int uneUniteQuantiteVente, QString uneLettreUnite, QVector<Vente> collectionVentes)
{
    id=unId;
    libelle=unLibelle;
    uniteQuantite=uneUniteQuantiteVente;
    lettreUnite=uneLettreUnite;
    lesVentes=collectionVentes;
}

bool Variete::isEnVente(Producteur unProducteur)
{
    bool valid= false;
    //Si la variete est en vente au moins une fois (return true)
    if(nbVente()>0)
    {
        //Si la vente correspond au moins un fois au producteur en parametre (return true)
        for(int i = 0 ; i<nbVente() ; i++)
        {
            if(lesVentes[i].verifProd(unProducteur) == true)
                valid = true;
        }
    }

    return valid;
}

int Variete::nbVente()
{
    return lesVentes.size();
}

QString Variete::afficherVariete()
{
    QString text = "<div><h1>"+libelle+"</h1>";
    for(int i = 0 ; i <nbVente() ; i++)
    {
        //text+=lesVentes[i].afficherVente();
    }
    text+="</div>";

    return text;
}

void Variete::chargerVenteDuClient(QVector<Producteur> desProducteurs)
{
    QVector<Vente> venteDuClient;

    for(int i = 0 ; i<lesVentes.size() ; i++)
    {
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if(lesVentes[i].verifProd(desProducteurs[i]))
            {
                venteDuClient.push_back(lesVentes[i]);
            }
        }
    }
    lesVentes=venteDuClient;
}
