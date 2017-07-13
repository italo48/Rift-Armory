#ifndef ITEM_H
#define ITEM_H
#include <iostream>
enum TipoIt{DANO_FISICO, DANO_MAGICO, TANK, SUPORTE};
class Item{
public:

    virtual TipoIt getTipo();
    void setTipo(TipoIt t);

    virtual void showIt();

    std::string getNomeI();
    void setNomeI(std::string value);

    int getQtdEst();
    void setQtdEst(int value);

    float getPrecoI();
    void setPrecoI(float value);


protected:
    std::string nomeI;
    TipoIt tipoit;
    float precoI;
    int qtdEst;
};

#endif // ITEM_H
