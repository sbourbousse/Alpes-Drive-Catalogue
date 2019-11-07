#include "passerelle.h"
#include <QDebug>

QVector<Categorie> Passerelle::chargerLesCategories()
{
    QVector<Categorie> lesCategories;

    QString recupererLesCategories = "select categorieId,categorieLibelle,categorieImage from categorie";
    QSqlQuery requeteCategories(recupererLesCategories);
    qDebug()<<recupererLesCategories;

    while(requeteCategories.next())
    {
        lesCategories.push_back(Categorie(requeteCategories.value("categorieId").toInt(),
                                          requeteCategorie.value("categorieLibelle").toString(),
                                          requeteCategorie.value("categorieImage").toString(),
                                          chargerLesProduits(requeteCategories.value("categorieId").toInt())));
    }

    recupererLesCategories.clear();

    return lesCategories;
}

QVector<Produit> Passerelle::chargerLesProduits(int idCategorie)
{
    QVector<Produit> lesProduits;

    QString recupererLesProduits = "select produitId, produitLibelle, produitImage from produit where categorieId="+QString::number(idCategorie);

    QSqlQuery requeteProduits(recupereLesProduits);

    while(requeteProduits.next())
    {
        lesProduits.push_back(Produit(requeteProduits.value("produitId").toInt(),
                                      requeteProduits.value("produitLibelle").toString(),
                                      requeteProduits.value("produitImage").toString(),
                                      chargerLesVarietes(requeteProduits.value("produitId").toInt())));
    }

    recupererLesProduits.clear();

    return lesProduits;
}

QVector<Variete> Passerelle::chargerLesVarietes(int idProduit)
{
    QVector<Variete> lesVarietes;

    QString recupererLesVarietes = "select varieteId, varieteLibelle, uniteQuantiteVente, uniteLettre from variete natural join Unite where varieteId="+QString::number(idProduit);

    QSqlQuery requeteVarietes(recupererLesVarietes);

    while(requeteVarietes.next())
    {
        lesVarietes.push_back(Variete(requeteVarietes.value("varieteId").toInt(),
                                      requeteVarietes.value("varieteLibelle").toString(),
                                      equeteVarietes.value("uniteQuantiteVente").toInt(),
                                      equeteVarietes.value("uniteLettre").toString(),
                                      chargerLesVentes(requeteVarietes.value("varieteId").toInt())));
    }

    recupererLesVarietes.clear();

    return lesVarietes;
}

QVector<Vente> Passerelle::chargerLesVentes(int idVariete)
{
    QVector<Vente> lesVentes;

    //Producteur()

    QString recupererLesVentes = "select venteId, prix, quantite, dateLimiteVente from Vente";

    qDebug()<<recupererLesVentes;

    QSqlQuery requeteVentes(recupererLesVentes);

    while(requeteVentes.next())
    {
        //Je récupère les informations du producteur qui propose la variété
        QString recupererProducteurVente="select prodId, prodPrenom, prodNom";
        qDebug()<<recupererProducteurVente;
        QSqlQuery requeteProducteurVente(recupererProducteurVente);

        requeteProducteurVente.first();

        Producteur monProducteur(requeteProducteurVente.value("prodId").toInt(),
                                 requeteProducteurVente.value("prodPrenom").toString(),
                                 requeteProducteurVente.value("prodNom").toString());


        lesVentes.push_back(Vente(requeteProducteurVente.value("venteId")));//A FINIR
    }
}
