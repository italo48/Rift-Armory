#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Item/itemfinal.h"


class Cliente{
public:
    Cliente(std::string nome, TipoIt recomendados);
    void show();//mostra o nome e o Etherium

    bool consumirItemBase(std::string ib); // apaga o item base na bag

    bool cosumirItemEnc(std::string ie); // apaga o item encantado na bag

    void mostrarBag(); // mostra todos os item do cliente

    bool addInBag(Item i); //adiciona um item no vector de itens do cliente


//    getters e setters
    std::string getNomeCliente();
    void setNomeCliente(std::string &value);

    TipoIt getRecomends();
    void setRecomends(TipoIt &value);

    std::vector<Item> getBag();

    float getEtherium();
    void setEtherium(float value);

private:
    std::string nomeCliente;
    TipoIt recomends;
    float etherium;
    std::vector<Item>bag;
};

#endif // CLIENTE_H
