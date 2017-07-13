#include "itemfinal.h"
ItemFinal::ItemFinal(){

}

ItemFinal::ItemFinal(std::string nome, TipoIt t, float preco, int qtd, std::string nB, std::string nE){
    this->nomeI = nome;
    this->tipoit = t;
    this->precoI = preco;
    this->qtdEst = qtd;
    this->nomeIB = nB;
    this->nomeIE = nE;
}

void ItemFinal::showIt(){
    std::string tipoStr;
    if(tipoit == 0)
        tipoStr = "Dano Fisico";
    if(tipoit == 1)
        tipoStr = "Dano Magico";
    if(tipoit == 2)
        tipoStr = "Tank";
    if(tipoit == 3)
        tipoStr = "Suporte";
    std::cout << "\t\t| "<< nomeI << " | " << tipoStr << " | " << precoI << " £ | " << qtdEst << std::endl;
    std::cout << "\t\t\tConstrução" << std::endl;
    std::cout << "\t\t| IB - " << nomeIB << " | " << "IE - " << nomeIE << std::endl;
}
std::string ItemFinal::getNomeIE()
{
    return nomeIE;
}

void ItemFinal::setNomeIE(std::string value)
{
    nomeIE = value;
}
std::string ItemFinal::getNomeIB()
{
    return nomeIB;
}

void ItemFinal::setNomeIB(std::string value)
{
    nomeIB = value;
}



