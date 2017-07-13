#ifndef SISTEMA_H
#define SISTEMA_H

#include "Item/estoque.h"
#include "Cliente/cliente.h"
#include "subject.h"

class Sistema : public Subject{
public:
    //    -------Ocultas para o usuario-------

    std::shared_ptr<Item> findItem(std::string nome);

    Item findItemCopy(std::string nome);

    void showForCat(std::string categoria);

    void showForClass(std::string classe);

    void showForCatAndClass(std::string classe, std::string categoria);

    ItemBase findItemBase(std::string nome);

    ItemEncantado findItemEncantado(std::string nome);

    ItemFinal findItemFinal(std::string nome);

//    std::vector<Item> getProdutos();

    TipoIt toTipoIt(std::string tipoStr);

    //    ---------CRUD itens------------
    bool addItem(std::shared_ptr<Item> item);

    bool removerItem(std::string nomeIt);

    bool alterarItem(std::shared_ptr<Item> ite, int op);//Ainda não testei

    void mostrarEst();

    //    -------Abertas para o usuario------

    bool vender(std::shared_ptr<Item> itemVenda, Cliente* client);

    //    ---------CRUD Cliente------------
    bool addCliente(Cliente c);

    bool removerCliente(std::string nomeCli);

    bool mostrarCliente(std::string nomeCli);

    Cliente* findCliente(std::string nomeCli);

    void showAllClientes();

private:
    Estoque estoque;
    std::vector<Cliente> participantes;
};

#endif // SISTEMA_H
