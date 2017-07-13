#ifndef ITEMENCANTADO_H
#define ITEMENCANTADO_H

#include "item.h"
class ItemEncantado : public Item{
public:
    ItemEncantado();
    ItemEncantado(std::string nome, TipoIt t, float preco, int qtd);
    TipoIt getTipo();

private:
};

#endif // ITEMENCANTADO_H
