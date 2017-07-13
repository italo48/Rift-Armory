#include "item.h"


std::string Item::getNomeI()
{
    return nomeI;
}

void Item::setNomeI(std::string value)
{
    nomeI = value;
}
int Item::getQtdEst()
{
    return qtdEst;
}

void Item::setQtdEst(int value)
{
    qtdEst = value;
}
float Item::getPrecoI()
{
    return precoI;
}

void Item::setPrecoI(float value)
{
    precoI = value;
}

TipoIt Item::getTipo(){
    return tipoit;
}

void Item::setTipo(TipoIt t){
    tipoit = t;
}

void Item::showIt(){
    std::string tipoStr;
    if(tipoit == 0)
        tipoStr = "Dano Fisico";
    if(tipoit == 1)
        tipoStr = "Dano Magico";
    if(tipoit == 2)
        tipoStr = "Tank";
    if(tipoit == 3)
        tipoStr = "Suporte";

    std::cout << "\t\t" << "| " << nomeI << " | " << tipoStr << " | " << precoI << " £ | " << qtdEst << std::endl;
}




