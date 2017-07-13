#include <iostream>
#include "Interface/interface.h"

//povoa o sistema para consultas de teste
void iniciar(Sistema* sis){
    std::shared_ptr<Item> ib1(new ItemBase("Bota", TANK, 300, 10));
    std::shared_ptr<Item> ib2(new ItemBase("Cristal_Rubi", TANK, 400, 10));
    std::shared_ptr<Item> ib3(new ItemBase("Agada", DANO_FISICO, 300, 10));
    std::shared_ptr<Item> ib4(new ItemBase("Cota_de_Pano", TANK, 300, 10));
    std::shared_ptr<Item> ib5(new ItemBase("Anel_de_Doran", DANO_MAGICO, 400, 10));
    std::shared_ptr<Item> ib6(new ItemBase("Escudo_de_Doran", TANK, 4500, 10));
    std::shared_ptr<Item> ib7(new ItemBase("Cristal_de_Safira", DANO_MAGICO, 350, 10));
    std::shared_ptr<Item> ib8(new ItemBase("Moeda_Antiga", SUPORTE, 350, 10));
    std::shared_ptr<Item> ib9(new ItemBase("Bracadeira_Targon", TANK, 350, 10));
    std::shared_ptr<Item> ib10(new ItemBase("Tomo_Amplificador", DANO_MAGICO, 450, 10));

    std::shared_ptr<Item> ie2(new ItemEncantado("Capitulo_Perdido", DANO_MAGICO, 900, 10));
    std::shared_ptr<Item> ie1(new ItemEncantado("Codex_Demoniaco", DANO_MAGICO, 900, 10));
    std::shared_ptr<Item> ie3(new ItemEncantado("Fago", DANO_FISICO, 1250, 10));
    std::shared_ptr<Item> ie4(new ItemEncantado("Warhammer", DANO_FISICO, 1100, 10));
    std::shared_ptr<Item> ie5(new ItemEncantado("Espada_GPC", DANO_FISICO, 1300, 10));
    std::shared_ptr<Item> ie6(new ItemEncantado("Idolo_Proibido", SUPORTE, 800, 10));
    std::shared_ptr<Item> ie7(new ItemEncantado("Gema_Ardente", SUPORTE, 800, 10));
    std::shared_ptr<Item> ie8(new ItemEncantado("Cota_de_Malha", TANK, 800, 10));
    std::shared_ptr<Item> ie9(new ItemEncantado("Capa_Negratron", SUPORTE, 720, 10));
    std::shared_ptr<Item> ie10(new ItemEncantado("Cetro_Vampirico", DANO_FISICO, 900, 10));

    std::shared_ptr<Item> if1(new ItemFinal("Cutelo_Negro", DANO_FISICO, 3200, 20, "Cristal_Rubi", "Fago"));
    std::shared_ptr<Item> if2(new ItemFinal("Gume_do_Infinito", DANO_FISICO, 3600, 20, "Espada_GPC", "Picareta"));
    std::shared_ptr<Item> if3(new ItemFinal("Sedenta_por_Sangue", DANO_FISICO, 3700, 20, "Espada_GPC", "Cetro_Vampirico"));
    std::shared_ptr<Item> if4(new ItemFinal("Warmorg", TANK, 2850, 20, "Cristal_Rubi", "Cinto_do_Gigante"));
    std::shared_ptr<Item> if5(new ItemFinal("Capa_de_Fogo", TANK, 2900, 20, "Cota_de_Pano", "Brasa_de_Bami"));
    std::shared_ptr<Item> if6(new ItemFinal("Solari", SUPORTE, 2200, 20, "Manto_AM", "Egide_da_Legian"));
    std::shared_ptr<Item> if7(new ItemFinal("Tornmail", TANK, 3200, 20, "Cota_de_Pano", "Cota_de_Malha"));
    std::shared_ptr<Item> if8(new ItemFinal("Liandry", DANO_MAGICO, 3100, 20, "Varinha_Explosiva", "Mascara_Assustadora"));
    std::shared_ptr<Item> if9(new ItemFinal("Rabbadon", DANO_MAGICO, 3800, 30, "Tomo_Amplificador", "Bastao_Desnecessariamente_Grande"));
    std::shared_ptr<Item> if10(new ItemFinal("Cajado_do_Vazio", DANO_MAGICO, 2650, 10, "Tomo_Amplificador", "Codex_Demoniaco"));

    Cliente c1("Darius", DANO_FISICO);
    c1.setEtherium(33401);
    Cliente c2("Thresh", SUPORTE);
    c2.setEtherium(5607);
    Cliente c3("Graves", DANO_FISICO);
    c3.setEtherium(1200);
    Cliente c4("Viktor", DANO_FISICO);
    c4.setEtherium(6789);
    Cliente c5("Sion", TANK);
    c5.setEtherium(3456);

//    itens base
    sis->addItem(ib1);
    sis->addItem(ib2);
    sis->addItem(ib3);
    sis->addItem(ib4);
    sis->addItem(ib5);
    sis->addItem(ib6);
    sis->addItem(ib7);
    sis->addItem(ib8);
    sis->addItem(ib9);
    sis->addItem(ib10);

//    itens encantados
    sis->addItem(ie1);
    sis->addItem(ie2);
    sis->addItem(ie3);
    sis->addItem(ie4);
    sis->addItem(ie5);
    sis->addItem(ie6);
    sis->addItem(ie7);
    sis->addItem(ie8);
    sis->addItem(ie9);
    sis->addItem(ie10);

//   itens finais
    sis->addItem(if1);
    sis->addItem(if2);
    sis->addItem(if3);
    sis->addItem(if4);
    sis->addItem(if5);
    sis->addItem(if6);
    sis->addItem(if7);
    sis->addItem(if8);
    sis->addItem(if9);
    sis->addItem(if10);


//    add clientes
    sis->addCliente(c1);
    sis->addCliente(c2);
    sis->addCliente(c3);
    sis->addCliente(c4);
    sis->addCliente(c5);
    Cliente* c = sis->findCliente(c1.getNomeCliente());
    sis->vender(ie3, c);
}


int main(){
    Sistema sis;

    Interface app(&sis);

    iniciar(&sis);

    app.mainWindow();
    return 0;
}

