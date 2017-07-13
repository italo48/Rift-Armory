#ifndef ITEMFINAL_H
#define ITEMFINAL_H

#include "itembase.h"
#include "itemencantado.h"
#include <vector>

class ItemFinal : public Item{
public:
    ItemFinal();
    ItemFinal(std::string nome, TipoIt t, float preco, int qtd, std::string nB, std::string nE);
    void showIt();

    std::string getNomeIE();
    void setNomeIE(std::string value);

    std::string getNomeIB();
    void setNomeIB(std::string value);

private:
    std::string nomeIE;
    std::string nomeIB;
};

#endif // ITEMFINAL_H
