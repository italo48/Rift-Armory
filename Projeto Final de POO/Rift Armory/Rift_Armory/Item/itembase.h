#ifndef ITEMBASE_H
#define ITEMBASE_H
#include "item.h"
class ItemBase : public Item{
public:
    ItemBase();
    ItemBase(std::string nome, TipoIt t,float preco, int qtd);
    TipoIt getTipo();

//    void showIt(){
//        std::string tipoStr;
//        if(tipoit == 0)
//            tipoStr = "Dano Fisico";
//        if(tipoit == 1)
//            tipoStr = "Dano Magico";
//        if(tipoit == 2)
//            tipoStr = "Tank";
//        if(tipoit == 3)
//            tipoStr = "Suporte";

//        std::cout << "\t\t" << "| " << nomeI << " | " << tipoStr << " | " << precoI << " £ | " << qtdEst << std::endl;
//    }

private:
};

#endif // ITEMBASE_H
