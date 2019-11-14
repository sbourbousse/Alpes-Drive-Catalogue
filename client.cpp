#include "client.h"
#include <QSqlQuery>

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

    QString recupererProducteursClient = "select producteur.prodId, prodNom, prodPrenom from choisir natural join point_relais natural join proposer natural join producteur where producteur.supprime=false and pointRelais.supprime=false and clientId="+id.toString();
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
