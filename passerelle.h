#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QSqlQuery>
#include <QVector>
#include <categorie.h>
#include <produit.h>
#include <variete.h>

class Passerelle
{
public:
    static QVector<Categorie> chargerLesCategories();
    static QVector<Produit> chargerLesProduits(int idCategorie);
    static QVector<Variete> chargerLesVarietes(int idProduit);
    static QVector<Vente> chargerLesVentes(int idVariete);
};

#endif // PASSERELLE_H
