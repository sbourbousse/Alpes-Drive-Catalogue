#ifndef VARIETE_H
#define VARIETE_H

#include <QString>
#include <QVector>
#include "vente.h"

class Variete
{
private:
    int id;
    QString libelle;
    int uniteQuantite;
    QString lettreUnite;
    QVector<Vente> lesVentes;

public:
    Variete(int unId, QString unLibelle, int uneUniteQuantiteVente, QString uneLettreUnite, QVector<Vente> collectionVentes);
    bool isEnVente(Producteur unProducteur);
    int nbVente();
    QString afficherVariete();
    void chargerVenteDuClient(QVector<Producteur> desProducteurs);
};

#endif // VARIETE_H
