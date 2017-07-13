#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Sistema/sistema.h"


class Interface{
public:
    Interface(Sistema* sis);
    void op(std::string func);  // exibe uma string "opção"

    void menuInicial();         // exibe as opções da janela principal
    void menuEst();             // exibe as opções CRUD de itens
    void menuCliente();         // exibe as opções CRUD de clientes
    void menuBuscar();          // exibe as opções de busca de um item
    void menuAltera();          // exibe as opções da tela de alterar a
                                // qtd ou o preço de um item

    void menuVender();          // exibe as opções da janela de venda

    void vendaWindow();         // UI de vendas
    void buscarProdWindow();    // UI de busca
    void mainWindow();          // UI principal
    void crudEstoWindow();      // UI de estoque
    void beginWindow();         // UI de clientes

private:
    Sistema* mainSistem;
    Estoque* estoke;
};

#endif // INTERFACE_H
