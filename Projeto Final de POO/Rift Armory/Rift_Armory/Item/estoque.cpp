#include "estoque.h"

Estoque::Estoque()
{
}

bool Estoque::addItemEstoq(std::shared_ptr<Item> i){
    for(std::shared_ptr<Item> item : produtos){
        if(item.get()->getNomeI() == i.get()->getNomeI()){
            return false;
        }
    }
    produtos.push_back(i);
    return true;
}

bool Estoque::removerItemEstoq(std::string nomeIt){
    for(int i = 0; i < (int)produtos.size(); i++){
        if(produtos[i].get()->getNomeI() == nomeIt){
            produtos.erase(produtos.begin() + i);
            return true;
        }
    }
    return false;
}

std::shared_ptr<Item> Estoque::findItemPtrEstoq(std::string nomeIt){
    for(std::shared_ptr<Item> finded : produtos){
        if(finded.get()->getNomeI() == nomeIt){
            return finded;
        }
    }
    throw "Produto nao encontrado";
}

int Estoque::getTamEstoq(){
    return (int)produtos.size();
}
std::vector<std::shared_ptr<Item> > Estoque::getProdutos()
{
    return produtos;
}


