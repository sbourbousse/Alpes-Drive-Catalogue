#include "produit.h"

Produit::Produit()
{

}

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

    bool varieteAjoute;

    for(int i = 0 ; i<lesVarietes.size() ; i++)
    {
        varieteAjoute=false;
        for(int j = 0 ; j<desProducteurs.size() ; j++)
        {
            if((lesVarietes[i].isEnVente(desProducteurs[j]))&& (varieteAjoute==false))
            {
                varieteDuClient.push_back(lesVarietes[i]);
                varieteDuClient.last().chargerVenteDuClient(desProducteurs);
                varieteAjoute=true;
            }
        }
    }
    lesVarietes=varieteDuClient;

}

QString Produit::afficherProduit()
{
    QString text = "<table class=\"tableauVarietes\"><tbody><tr><td width=\"90\"><div><h2>"+libelle+"</h2></div><div>"
                   "<img width=\"70\" src=\"img/"+image+"\"></div></td>";
    for(int i = 0 ; i<lesVarietes.size() ; i++)
    {
        //Si on affiche la premiere ligne (à part car on affiche le titre du produit sur la meme ligne)
        if(i<4)
        {
            //Fin de la première ligne , on ferme la balise <tr>
            if(i==3)
                text+="<td width=\"150\">"+lesVarietes[i].afficherVariete()+"</td></tr>";
            //sinon on ajoute juste la case
            else
                text+="<td width=\"150\">"+lesVarietes[i].afficherVariete()+"</td>";
        }
        //Si on affiche plus de la deuxieme ligne (4 variétés par ligne)
        else if(i>3)
        {
            //Fin des variétés on ferme la ligne
            if(i==lesVarietes.size())
                text+="<td>"+lesVarietes[i].afficherVariete()+"</td></tr>";
            //Si la variable compteur i(+1 car initialisé à 0) est un multiple de 4 , nouvelle ligne
            else if(((i+1)%4)==0)
                text+="<td>"+lesVarietes[i].afficherVariete()+"</td></tr><tr>";
            //sinon on ajoute juste la case
            else
                text+="<td>"+lesVarietes[i].afficherVariete()+"</td>";
        }

    }
    text+="</tbody></table>";

    return text;
}
