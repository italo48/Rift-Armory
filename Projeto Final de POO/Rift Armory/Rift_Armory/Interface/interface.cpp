#include "interface.h"

Interface::Interface(Sistema *sis){
    mainSistem = sis;
}

void Interface::op(std::string func){
    std::cout << "( "<< func << " )"<<"opção: ";
}

void Interface::menuInicial(){
    std::cout << "\t\t\t\t Rift Armory" << std::endl;
    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Venda" << std::endl;
    std::cout << "2 - Buscar Produto" << std::endl;
    std::cout << "3 - Gerenciar Estoque" << std::endl;
    std::cout << "4 - Gerenciar Clientes" << std::endl;
    std::cout << "5 - Mostrar menu" << std::endl;
}

void Interface::menuEst(){
    std::cout << "\t\t\t\t CRUD Estoque" << std::endl;
    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Inserir Produto" << std::endl;
    std::cout << "2 - Remover Produto" << std::endl;
    std::cout << "3 - Alterar Produto" << std::endl;
    std::cout << "4 - Mostrar Estoque" << std::endl;
    std::cout << "5 - Mostrar menu" << std::endl;
}


void Interface::menuCliente(){
    std::cout << "\t\t\t\t CRUD Participantes" << std::endl;
    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Inserir Participante" << std::endl;
    std::cout << "2 - Remove Participante" << std::endl;
    std::cout << "3 - Buscar Participante" << std::endl;
    std::cout << "4 - Mostrar Participantes" << std::endl;
    std::cout << "5 - Mostrar menu" << std::endl;
}

void Interface::menuBuscar(){
    std::cout << "\t\t\t\t# Busca de Item #" << std::endl;
    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Buscar por Nome" << std::endl;
    std::cout << "2 - Buscar por Categoria (Tank, Suporte, Dano_Magico, Dano_Fisico)" << std::endl;
    std::cout << "3 - Buscar por Classe (Item base, Item Encantado, Item Final)" << std::endl;
    std::cout << "4 - Buscar por Categoria e Classe" << std::endl;
    std::cout << "5 - Mostrar menu" << std::endl;
}

void Interface::menuAltera(){
    std::cout << "\t\t\t\t# Alterar item #" << std::endl;
    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Alterar preço" << std::endl;
    std::cout << "2 - Alterar quantidade em estoque" << std::endl;
}

void Interface::menuVender(){
    std::cout << std::endl;

    std::cout << "0 - sair" << std::endl;
    std::cout << "1 - Buscar por item" << std::endl;
}

void Interface::crudEstoWindow(){
    menuEst();
    int opcrud = -1;
    while (opcrud != 0) {
        op("Gerenciar Estoque");
        std::cin >> opcrud;
        if(opcrud == 1){
            try{
                std::string nomeProd, opProd, tipoProd;
                int qtd;
                float preco;
                std::cout << "\t\t\t\t# Inserir Novo Produto #" << std::endl;

                std::cout << "\tIB - Item Base | IE - Item Encantado | IF - Item Final" << std::endl;
                op("Gerenciar Estoque (Digite uma opção valida)");
                std::cin >> opProd;
                //              Aviso: quando se insere umam op q n é nenhuma das ai de cima, ele recebe
                if(opProd == "IB"){

                    std::cout << "Nome: ";
                    std::cin >> nomeProd;

                    std::cout << "Tipo: ";
                    std::cin >> tipoProd;
                    TipoIt t = mainSistem->toTipoIt(tipoProd);

                    std::cout << "Quantidade: ";
                    std::cin >> qtd;

                    std::cout << "Preço: ";
                    std::cin >> preco;

                    std::shared_ptr<Item> itemB(new ItemBase(nomeProd, t, preco, qtd));

                    if(mainSistem->addItem(itemB)){
                        std::cout << "Item Adicionado " << std::endl;
                    }else{
                        std::cout << "Erro ao Adicionar " << std::endl;
                    }
                }
                else if(opProd == "IE"){

                    std::cout << "Nome: ";
                    std::cin >> nomeProd;

                    std::cout << "Tipo: ";
                    std::cin >> tipoProd;
                    TipoIt t = mainSistem->toTipoIt(tipoProd);

                    std::cout << "Quantidade: ";
                    std::cin >> qtd;

                    std::cout << "Preço: ";
                    std::cin >> preco;

                    std::shared_ptr<Item> itemE(new ItemEncantado(nomeProd, t, preco, qtd));
                    if(mainSistem->addItem(itemE)){
                        std::cout << "Item Adicionado " << std::endl;
                    }else{
                        std::cout << "Erro ao Adicionar " << std::endl;
                    }
                }
                else if(opProd == "IF"){

                    std::cout << "Nome: ";
                    std::cin >> nomeProd;

                    std::cout << "Tipo: ";
                    std::cin >> tipoProd;
                    TipoIt t = mainSistem->toTipoIt(tipoProd);

                    std::cout << "Quantidade: ";
                    std::cin >> qtd;

                    std::cout << "Preço: ";
                    std::cin >> preco;

                    std::string ib, ie;

                    std::cout << "Item base: ";
                    std::cin >> ib;

                    std::cout << "Item Encantado: ";
                    std::cin >> ie;

                    std::shared_ptr<Item>itemFinal(new ItemFinal(nomeProd, t, preco, qtd, ib, ie));

                    if(mainSistem->addItem(itemFinal)){
                        std::cout << "Item Adicionado " << std::endl;
                    }else{
                        std::cout << "Erro ao Adicionar " << std::endl;
                    }
                }
            }catch(const char* stra){
                std::cout << "Erro: " << stra << std::endl;
            }
        }
        else if(opcrud == 2){
            std::string nome;
            std::cout << "\t\t\t\t# Remover Produto #" << std::endl;
            std::cout << "Nome:";
            std::cin >> nome;
            if(mainSistem->removerItem(nome)){
                std::cout << "Removido com Sucesso" << std::endl;
            }else{
                std::cout << "Erro ao Remover" << std::endl;
            }
        }
        else if(opcrud == 3){
            int opAlt = -1;
            std::string nomep;
            std::cout << "\t\t\t\t# Alterar Produto #" << std::endl;

            std::cout << "Nome do produto a ser alterado: ";
            std::cin >> nomep;
            std::shared_ptr<Item> prodAlter = mainSistem->findItem(nomep);
            std::cout << "1 - preço | 2 - quantidade" << std::endl;
            std::cout << "O que deseja alterar: ";
            std::cin >> opAlt;
            if(opAlt == 1){
                std::cout << "Novo Preço: ";
                if(mainSistem->alterarItem(prodAlter, opAlt)){
                    std::cout << "Alterado com sucesso" << std::endl;
                }else{
                    std::cout << "Erro ao Alterar" << std::endl;
                }
            }else{
                std::cout << "Nova Quantidade: ";
                if(mainSistem->alterarItem(prodAlter, opAlt)){
                    std::cout << "Alterado com sucesso" << std::endl;
                }else{
                    std::cout << "Erro ao Alterar" << std::endl;
                }
            }
        }
        else if(opcrud == 4){
            std::cout << "\t\t\t\t# Estoque #" << std::endl;
            mainSistem->mostrarEst();
        }
        else if(opcrud == 5){
            menuEst();
        }
        else if(opcrud != 0){
            std::cout << "Opção invalida" << std::endl;
        }
    }
    menuInicial();
}

void Interface::vendaWindow(){
    int opv = -1, opC = -1;
    std::string nomePart, nomeItem;

    std::cout << "\t\t\t\t # Vender #" << std::endl;
    try{
        std::cout << "Nome do participante: ";
        std::cin >> nomePart;

        Cliente* comprador = mainSistem->findCliente(nomePart);
        std::cout << std::endl;
        std::cout << "Inventario(" << (int)comprador->getBag().size()<< ") - "<< comprador->getNomeCliente() << std::endl;
        comprador->mostrarBag();
        std::cout << comprador->getEtherium() << " £" << std::endl;


        while(opv != 0){
            menuVender();
            op("Venda");
            std::cin >> opv;
            if(opv == 1){
                std::cout << "\t\t\t\t # Buscar #" << std::endl;
                std::cout << "Nome: ";
                std::cin >> nomeItem;

                std::cout << "Item" << std::endl;
                std::shared_ptr<Item> itf = mainSistem->findItem(nomeItem);
                itf.get()->showIt();

                std::cout << std::endl;

                std::cout << "0 - sair" << std::endl;
                std::cout << "1 - comprar" << std::endl;
                if(std::shared_ptr<ItemFinal> itemFinal = std::dynamic_pointer_cast<ItemFinal>(itf)){
                    std::cout << "2 - comprar item base" << std::endl;
                    std::cout << "3 - comprar item encantado" << std::endl;
                }
                op("Venda");
                std::cin >> opC;
                if(opC == 0)
                    continue;

                if(opC == 1 || opC == 2 || opC == 3){
                    if(mainSistem->vender(itf, comprador)){
                        std::cout << std::endl;
                        std::cout << "Item adicionado ao inventario" << std::endl;
                        std::cout << "Inventario(" << (int)comprador->getBag().size()<< ") - "<< comprador->getNomeCliente() << std::endl;
                        comprador->mostrarBag();
                        std::cout << comprador->getEtherium() << " £" << std::endl;
                    }else{
                        std::cout << "Ocorreu um erro na venda" << std::endl;
                    }
                }
            }


        }
    }catch(const char* str){
        std::cout << "Erro: "<< str << std::endl;
    }
    menuInicial();
}

void Interface::buscarProdWindow(){
    int opBusc = -1;

    menuBuscar();

    while(opBusc != 0){
        op("Buscar");
        std::cin >> opBusc;
        if(opBusc == 1){
            std::string nomeI;
            std::cout << "\t\t\t\t # Busca por Nome #" << std::endl;
            std::cout << "Nome: ";
            std::cin >> nomeI;

            try{
                if(std::shared_ptr<Item> finded = mainSistem->findItem(nomeI)){
                    std::cout << "Achado!!" << std::endl;
                    finded->showIt();
                }else{
                    std::cout << "Não existe na loja" << std::endl;
                }
            }catch(const char* str){
                std::cout << "Erro: " << str << std::endl;
            }
        }
        else if(opBusc == 2){
            std::cout << "\t\t\t\t # Busca por Categoria #" << std::endl;
            std::string cate;
            std::cout << "Categoria: ";
            std::cout << "(Tank - Suporte - Dano_Fisico, Dano_Magico)" << std::endl;
            std::cin >> cate;

            try{
                mainSistem->showForCat(cate);
            }catch(const char* str){
                std::cout << str << std::endl;
            }
        }
        else if(opBusc == 3){
            std::cout << "\t\t\t\t # Busca por Classe #" << std::endl;
            std::cout << "IB - Item Base | IE - Item Encantado | IF - Item Final" << std::endl;
            std::string classe;
            std::cout << "Classe: ";
            std::cin >> classe;

            try{
                mainSistem->showForClass(classe);
            }catch(const char* str){
                std::cout << str << std::endl;
            }
        }
        else if(opBusc == 4){
            std::string cate, classe;
            std::cout << "\t\t\t\t # Busca por Categoria e Classe #" << std::endl;
            std::cout <<"IB | IE | IF" << std::endl;
            std::cout << "Classe: ";
            std::cin >> classe;
            std::cout << "(Tank - Suporte - Dano_Fisico, Dano_Magico)" << std::endl;
            std::cout << "Categoria: ";
            std::cin >> cate;
            try{
                mainSistem->showForCatAndClass(classe, cate);
            }catch(const char* str){
                std::cout << str << std::endl;
            }
        }
        else if(opBusc == 5){
            menuBuscar();
        }
    }
    menuInicial();
}

void Interface::mainWindow(){
    beginWindow();

    int opc = -1;
    menuInicial();
    while(opc != 0){
        op("Rift Armory");
        std::cin >> opc;
        if(opc == 1){
            vendaWindow();

        }
        else if(opc == 2){
            buscarProdWindow();
        }
        else if(opc == 3){
            crudEstoWindow();
        }
        else if(opc == 4){
            beginWindow();
            menuInicial();
        }
        else if(opc == 5){
            menuInicial();
        }
    }
}

void Interface::beginWindow(){
    int opi = -1;
    std::string nome, tipo;
    menuCliente();
    while(opi != 0){
        op("Inicio");
        std::cin >> opi;
        if(opi == 1){
            std::cout << std::endl;
            std::cout << "\t\t\t\t # Cadastro #" << std::endl;
            std::cout << "Primeiro nome: ";
            std::cin >> nome;
            std::cout << "Tipo de itens que utiliza: ";
            std::cout << "(Tank - Dano_Fisico - Dano_Magico - Suporte)" << std::endl;
            std::cin >> tipo;
            TipoIt t = mainSistem->toTipoIt(tipo);
            Cliente cliente(nome, t);

            if(mainSistem->addCliente(cliente)){
                std::cout << std::endl;
                std::cout << "Participante adicionado com sucesso" << std::endl;
                std::cout << "\t\tDados" << std::endl;
                mainSistem->mostrarCliente(nome);
            }else{
                std::cout << "Erro ao adicionar o participante" << std::endl;
            }
        }
        else if (opi == 2){
            std::cout << std::endl;
            std::cout << "\t\t\t\t # Remover #" << std::endl;
            mainSistem->showAllClientes();
            std::cout << "Primeiro nome: ";
            std::cin >> nome;
            if(mainSistem->removerCliente(nome)){
                std::cout << "Sucesso ao remover" << std::endl;
            }else{
                std::cout << "Erro ao remover" << std::endl;
            }
        }

        else if(opi == 3){
            std::cout << std::endl;
            std::cout << "\t\t\t\t # Buscar Participante #" << std::endl;
            std::cout << "Primeiro nome: ";
            std::cin >> nome;

            if(mainSistem->mostrarCliente(nome)){
                std::cout << "Participante encontrado!!" << std::endl;
            }else{
                std::cout << "Participante não encontrado!!" << std::endl;
            }

        }

        else if(opi == 4){
            std::cout << std::endl;
            std::cout << "\t\t\t\t # Participantes #" << std::endl;
            try{
                mainSistem->showAllClientes();
            }catch(const char* str){
                std::cout << str << std::endl;
            }
        }
        else if(opi == 5){
            menuCliente();
        }
    }
}
