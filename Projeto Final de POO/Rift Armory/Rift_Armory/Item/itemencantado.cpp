#include "itemencantado.h"

ItemEncantado::ItemEncantado()
{

}

ItemEncantado::ItemEncantado(std::string nome, TipoIt t, float preco, int qtd)
{
    this->nomeI = nome;
    this->tipoit = t;
    this->precoI = preco;
    this->qtdEst = qtd;
}

TipoIt ItemEncantado::getTipo(){
    return tipoit;
}

