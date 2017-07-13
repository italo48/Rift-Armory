#ifndef VENDAITEMFINAL_H
#define VENDAITEMFINAL_H
#include "observer.h"
class VendaItemFinal : public Observer{
public:
    VendaItemFinal() :
        Observer()
    {}
    /*
     *  Logica de negocio do desconto
     *  caso 1 = a construção completa
     *      descontoTotal = 5% value ib + 10% value do ie
     *      total -  descontoTotal
     *  caso 2
     *      total - desconto do item base
     *  caso 3
     *      total - desconto do item encantado
    */
    void updade(int caso, ItemFinal* itf, float pIB, float pIE){
        float percentIB = 5.0;
        float percenteIE = 10.0;
        float cem = 100.0;

        float descItB = (percentIB/cem) * pIB;
        float descItE = (percenteIE/cem) * pIE;
        float descTotal = ((percentIB/cem) * pIB) + ((percenteIE/cem) * pIE);

        switch (caso) {
        case 1:
            itf->setPrecoI(itf->getPrecoI() - descTotal);
            break;
        case 2:
            itf->setPrecoI(itf->getPrecoI() - descItB);
            break;
        case 3:
            itf->setPrecoI(itf->getPrecoI() - descItE);
            break;
        default:
            break;
        }
    }
};

#endif // VENDAITEMFINAL_H
