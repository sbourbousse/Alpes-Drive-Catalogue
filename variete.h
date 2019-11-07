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
    bool isEnVente();
};

#endif // VARIETE_H
