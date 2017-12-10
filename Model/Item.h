//
// Created by Asaf Santana on 09/11/2017.
//

#ifndef RESTAURANTEFUTURISTICO_ITEM_H
#define RESTAURANTEFUTURISTICO_ITEM_H

#include <iostream>
#include <string>
#include <map>

/**
 * Classe que representa um item
 *
 */

using namespace std;

class Item {

private:
    string item;
    int tempo;
    int id;
public:
    Item(int id, int tempo, string item) {
        setId(id);
        setItem(item);
        setTempo(tempo);
    }


    void setItem(string item) {
        this->item = item;
    }

    string getItem() {
        return this->item;
    }

    void setTempo(int tempo) {
        this->tempo = tempo;
    }

    int getTempo() {
        return this->tempo;
    }

    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return this->id;
    }


};


#endif //RESTAURANTEFUTURISTICO_ITEM_H
