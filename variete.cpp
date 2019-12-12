#include "variete.h"

Variete::Variete()
{

}

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
    QString text = "<div class=\"vente\"><center><h3>"+libelle+"</h3></center><font size=\"-8\"><table  width=\"150\" class=\"tableauVentes\"><tbody>"
                   "<tr><th>Producteur</th><th>Prix</th><th>Quantite</th></tr>";
    for(int i = 0 ; i <lesVentes.size() ; i++)
    {
        text+=lesVentes[i].afficherVente();
    }
    text+="</tbody></table></font></div>";

    return text;
}

void Variete::chargerVenteDuClient(QVector<Producteur> desProducteurs)
{
    QVector<Vente> venteDuClient;
    bool venteAjoute;

    for(int i = 0 ; i<lesVentes.size() ; i++)
    {
        venteAjoute=false;
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if((lesVentes[i].verifProd(desProducteurs[j]))&&(venteAjoute==false))
            {
                venteDuClient.push_back(lesVentes[i]);
                venteAjoute=true;
            }
        }
    }
    lesVentes=venteDuClient;

}
