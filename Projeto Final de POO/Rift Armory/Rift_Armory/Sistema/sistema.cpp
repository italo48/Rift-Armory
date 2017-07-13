#include "sistema.h"

bool Sistema::addItem(std::shared_ptr<Item> item){
    return estoque.addItemEstoq(item);
}

bool Sistema::removerItem(std::string nomeIt){
    if(this->estoque.removerItemEstoq(nomeIt))
        return true;
    return false;
}

bool Sistema::alterarItem(std::shared_ptr<Item> ite, int op){
    int p = 0;
    std::cin >> p;
    if(op == 1){
        if(p < 0) return false;
        //ou um throw é melhor??
        ite.get()->setPrecoI(p);
        return true;
    }
    else if(op == 2){
        if(p < 0) return false;
        ite.get()->setQtdEst(p);
        return true;
    }
    return false;
    //    ou um throw??
}

void Sistema::mostrarEst(){
    for(std::shared_ptr<Item> item : this->estoque.getProdutos())
        item.get()->showIt();
}

bool Sistema::vender(std::shared_ptr<Item> itemVenda, Cliente *client){
    if(client->getEtherium() > 0){
        if(std::shared_ptr<ItemFinal> itf = std::dynamic_pointer_cast<ItemFinal>(itemVenda)){
            ItemFinal itemFInv = findItemFinal(itemVenda.get()->getNomeI());
            ItemBase itemBBag = findItemBase(itf.get()->getNomeIB());
            ItemEncantado itemEBag = findItemEncantado(itf.get()->getNomeIE());

            if(client->consumirItemBase(itemBBag.getNomeI()) && client->cosumirItemEnc(itemEBag.getNomeI())){
                this->notify(1, &itemFInv, itemBBag.getPrecoI(), itemEBag.getPrecoI());
            }
            if(client->consumirItemBase(itemBBag.getNomeI())){
                this->notify(2, &itemFInv, itemBBag.getPrecoI(), itemEBag.getPrecoI());
            }
            if(client->cosumirItemEnc(itemEBag.getNomeI())){
                this->notify(3, &itemFInv, itemBBag.getPrecoI(), itemEBag.getPrecoI());
            }
            client->setEtherium(client->getEtherium() - itemFInv.getPrecoI());
            client->addInBag(itemFInv);
            itemVenda.get()->setQtdEst(itemVenda.get()->getQtdEst() - 1);

        }else{
            Item itemCliente = findItemCopy(itemVenda.get()->getNomeI());
            itemCliente.setQtdEst(1);
            client->setEtherium(client->getEtherium() - itemCliente.getPrecoI());
            client->addInBag(itemCliente);

            itemVenda.get()->setQtdEst(itemVenda.get()->getQtdEst() - 1);

        }
        return true;
    }
    return false;
}

bool Sistema::addCliente(Cliente c){
    for(Cliente clie : participantes)
        if(clie.getNomeCliente() == c.getNomeCliente())
            return false;
    participantes.push_back(c);
    return true;
}

bool Sistema::removerCliente(std::string nomeCli){
    for(int i = 0; i < (int)participantes.size(); i++){
        if(participantes[i].getNomeCliente() == nomeCli){
            participantes.erase(participantes.begin() + i);
            return true;
        }
    }
    return false;
}

bool Sistema::mostrarCliente(std::string nomeCli){
    for(Cliente c : participantes)
        if(c.getNomeCliente() == nomeCli){
            c.show();
            std::cout << "Inventario" << std::endl;
            c.mostrarBag();
            return true;
        }
    return false;
}

Cliente *Sistema::findCliente(std::string nomeCli){
    for(Cliente& c : participantes)
        if(c.getNomeCliente() == nomeCli)
            return &c;
    throw "Cliente não encontrado";
}

void Sistema::showAllClientes(){
    for(Cliente c : participantes)
        c.show();
    if((int)participantes.size() == 0)
        throw "Não há participantes";
}



std::shared_ptr<Item> Sistema::findItem(std::string nome){
    std::shared_ptr<Item> findedP = this->estoque.findItemPtrEstoq(nome);
    return findedP;
}

//Realmente necessario??
Item Sistema::findItemCopy(std::string nome){
    for(std::shared_ptr<Item> i : estoque.getProdutos()){
        if(i.get()->getNomeI() == nome){
            Item achado;
            achado.setNomeI(i.get()->getNomeI());
            achado.setPrecoI(i.get()->getPrecoI());
            achado.setQtdEst(i.get()->getQtdEst());
            achado.setTipo(i.get()->getTipo());
            return achado;
        }
    }
    throw "Item não encontrado";
}

void Sistema::showForCat(std::string categoria){
    TipoIt cat = toTipoIt(categoria);

    if(this->estoque.getTamEstoq() == 0)
        throw "Não há itens";

    for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
        if(item.get()->getTipo() == cat)
            item.get()->showIt();
    }
}

void Sistema::showForClass(std::string classe){

    if(this->estoque.getTamEstoq() == 0)
        throw "Não há itens";

    if(classe == "IB"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemBase> it = std::dynamic_pointer_cast<ItemBase>(item)){
                it.get()->showIt();
            }
        }
    }

    if(classe == "IE"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemEncantado> ite = std::dynamic_pointer_cast<ItemEncantado>(item)){
                ite.get()->showIt();
            }
        }
    }

    if(classe == "IF"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemFinal> itf = std::dynamic_pointer_cast<ItemFinal>(item)){
                itf.get()->showIt();
            }
        }
    }
}

void Sistema::showForCatAndClass(std::string classe, std::string categoria){

    if(this->estoque.getTamEstoq() == 0)
        throw "Não há itens";

    if(classe == "IB"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemBase> it = std::dynamic_pointer_cast<ItemBase>(item)){
                if(it.get()->getTipo() == toTipoIt(categoria)){
                    it.get()->showIt();
                }
            }
        }
    }

    if(classe == "IE"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemEncantado> ite = std::dynamic_pointer_cast<ItemEncantado>(item)){
                if(ite.get()->getTipo() == toTipoIt(categoria)){
                    ite.get()->showIt();
                }
            }
        }
    }

    if(classe == "IF"){
        for(std::shared_ptr<Item> item : this->estoque.getProdutos()){
            if(std::shared_ptr<ItemFinal> itf = std::dynamic_pointer_cast<ItemFinal>(item)){
                if(itf.get()->getTipo() == toTipoIt(categoria)){
                    itf.get()->showIt();
                }
            }
        }
    }

}


ItemBase Sistema::findItemBase(std::string nome){
    std::shared_ptr<Item> procurado = findItem(nome);
    if(std::shared_ptr<ItemBase> itb = std::dynamic_pointer_cast<ItemBase>(procurado)){
        ItemBase achado;
        achado.setNomeI(itb.get()->getNomeI());
        achado.setPrecoI(itb.get()->getPrecoI());
        achado.setQtdEst(itb.get()->getQtdEst());
        achado.setTipo(itb.get()->getTipo());
        return achado;
    }
    throw 0;
}

ItemEncantado Sistema::findItemEncantado(std::string nome){
    std::shared_ptr<Item> procurado = findItem(nome);
    if(std::shared_ptr<ItemEncantado> ite = std::dynamic_pointer_cast<ItemEncantado>(procurado)){
        ItemEncantado achado;
        achado.setNomeI(ite.get()->getNomeI());
        achado.setPrecoI(ite.get()->getPrecoI());
        achado.setQtdEst(ite.get()->getQtdEst());
        achado.setTipo(ite.get()->getTipo());
        return achado;
    }
    throw 0;
}

ItemFinal Sistema::findItemFinal(std::string nome){
    std::shared_ptr<Item> procurado = findItem(nome);
    if(std::shared_ptr<ItemFinal> itb = std::dynamic_pointer_cast<ItemFinal>(procurado)){
        ItemFinal achado;
        achado.setNomeI(itb.get()->getNomeI());
        achado.setPrecoI(itb.get()->getPrecoI());
        achado.setQtdEst(itb.get()->getQtdEst());
        achado.setTipo(itb.get()->getTipo());
        achado.setNomeIB(itb.get()->getNomeIB());
        achado.setNomeIE(itb.get()->getNomeIE());
        return achado;
    }
    throw 0;
}

//Desnecessario??
//std::vector<Item> Sistema::getProdutos(){
//    return this->estoque->getProdutos();
//}

TipoIt Sistema::toTipoIt(std::string tipoStr){
    if(tipoStr == "Tank")
        return TANK;
    if(tipoStr == "Suporte")
        return SUPORTE;
    if(tipoStr == "Dano_Fisico")
        return DANO_FISICO;
    if(tipoStr == "Dano_Magico")
        return DANO_MAGICO;
    else
        throw "tipo invalido";
}


