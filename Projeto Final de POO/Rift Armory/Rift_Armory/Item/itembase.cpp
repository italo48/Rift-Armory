 #include "itembase.h"

ItemBase::ItemBase()
{

}

ItemBase::ItemBase(std::string nome, TipoIt t, float preco, int qtd)
{
    this->nomeI = nome;
    this->tipoit = t;
    this->precoI = preco;
    this->qtdEst = qtd;
}

TipoIt ItemBase::getTipo(){
    return tipoit;
}

