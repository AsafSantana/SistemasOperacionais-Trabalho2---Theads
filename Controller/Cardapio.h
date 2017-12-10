//
// Created by Asaf Santana on 09/11/2017.
//

#ifndef RESTAURANTEFUTURISTICO_CARDAPIO_H
#define RESTAURANTEFUTURISTICO_CARDAPIO_H

#include <iostream>
#include <string>
#include <map>
#include "../Model/Item.h"


using namespace std;

/**
 * Classe para manipular itens do cardapio
 */

class Cardapio {

private:

    map<int, Item> itensDoCardapio;

public:

    void addItem(const Item &item) {
        int cont = itensDoCardapio.size() + 1;
        itensDoCardapio.emplace(cont, item);

    }

    Item* getItemDoCardapio(int id){

         return &itensDoCardapio.at(id);
    }
};


#endif //RESTAURANTEFUTURISTICO_CARDAPIO_H
