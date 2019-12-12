#include "client.h"
#include <QSqlQuery>
#include <QDebug>

Client::Client()
{

}

Client::Client(int unId, QString unNom, QString unPrenom)
{
    id = unId;
    nom = unNom;
    prenom = unPrenom;
    lesProducteurs = chargerProducteurs();
}

QVector<Producteur> Client::chargerProducteurs()
{
    //Je recupere un vecteur des ids des points relais auxquelle est inscrit le client
    QVector<Producteur> listeDeProducteurs;

    QString recupererProducteursClient = "select distinct producteur.prodId, prodNom, prodPrenom from choisir natural join point_relais natural join proposer inner join producteur on proposer.prodId=producteur.prodId where producteur.supprime=false and point_relais.supprime=false and clientId="+QString::number(id);
    qDebug()<<recupererProducteursClient;
    QSqlQuery requeteProducteursClient(recupererProducteursClient);

    while(requeteProducteursClient.next())
    {
        listeDeProducteurs.push_back(Producteur(requeteProducteursClient.value("prodId").toInt(),
                                                requeteProducteursClient.value("prodNom").toString(),
                                                requeteProducteursClient.value("prodPrenom").toString()));
    }

    requeteProducteursClient.clear();

    return listeDeProducteurs;
}

QVector<Producteur> Client::getProducteurs()
{
    return lesProducteurs;
}

int Client::getId()
{
    return id;
}
