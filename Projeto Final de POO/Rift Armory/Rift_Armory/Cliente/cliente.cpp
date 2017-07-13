#include "cliente.h"

Cliente::Cliente(std::string nome, TipoIt recomendados){
    this->nomeCliente = nome;
    this->recomends = recomendados;
    this->etherium = 0;
}

void Cliente::show(){
    std::cout << "\t\t" << nomeCliente << " | £:" << etherium << std::endl;
}


bool Cliente::consumirItemBase(std::string ib){
    for(int i = 0; i < (int)bag.size(); i++){
        if(bag[i].getNomeI() == ib){
            bag.erase(bag.begin() + i);
            return true;
        }
    }
    return false;
}

bool Cliente::cosumirItemEnc(std::string ie){
    for(int i = 0; i < (int)bag.size(); i++){
        if(bag[i].getNomeI() == ie){
            bag.erase(bag.begin() + i);
            return true;
        }
    }
    return false;
}

void Cliente::mostrarBag(){
    for(Item i : bag)
        i.showIt();
}

bool Cliente::addInBag(Item i){
    for(Item batata : bag)
        if(batata.getNomeI() == i.getNomeI())
            return false;
    bag.push_back(i);
    return true;
}
std::string Cliente::getNomeCliente()
{
    return nomeCliente;
}

void Cliente::setNomeCliente(std::string &value)
{
    nomeCliente = value;
}

std::vector<Item> Cliente::getBag()
{
    return bag;
}

float Cliente::getEtherium()
{
    return etherium;
}

void Cliente::setEtherium(float value)
{
    etherium = value;
}




