#include "variete.h"

Variete::Variete(int unId, QString unLibelle, int uneUniteQuantiteVente, QString uneLettreUnite, QVector<Vente> collectionVentes)
{
    id=unId;
    libelle=unLibelle;
    uniteQuantite=uneUniteQuantiteVente;
    lettreUnite=uneLettreUnite;
    lesVentes=collectionVentes;
}

bool Variete::isEnVente()
{
    //Si la variete est en vente au moins une fois (return true)
}
