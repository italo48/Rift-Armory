#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "itemfinal.h"
#include <vector>
#include <memory>
class Estoque{
public:
    Estoque();
    bool addItemEstoq(std::shared_ptr<Item> i); //

    bool removerItemEstoq(std::string nomeIt); //Ainda não testado

    std::shared_ptr<Item> findItemPtrEstoq(std::string nomeIt);//Ainda não testado

    int getTamEstoq(); //Acho q funciona

    std::vector<std::shared_ptr<Item> > getProdutos();

private:
    std::vector<std::shared_ptr<Item>> produtos;
};

#endif // ESTOQUE_H
