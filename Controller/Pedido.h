//
// Created by Asaf Santana on 23/11/2017.
//

#ifndef RESTAURANTEFUTURISTICO_PEDIDO_H
#define RESTAURANTEFUTURISTICO_PEDIDO_H


#include <iostream>
#include <string>
#include "../Model/Mesa.h"
#include "../Model/Item.h"

using namespace std;

class Pedido {


private:
    Mesa *mesa;
    Item *item;


public:
    Pedido(Mesa *mesa, Item *item) {
        this->item = item;
        this->mesa = mesa;
        this->mesa->setEspereando(true);
    }

    void pedidoFeito() {
        mesa->setEspereando(-1);
    }

    string getPedido() {
        return this->item->getItem();
    }

    int TempoDePreparo() {
        return this->item->getTempo();
    }

    int numeroDaMesa() {
        return this->mesa->getINDEX();
    }


/**
* Escreve no txt a mesa que vai ser atendida pelo chefe
*/
    void escreverMesaAtendida(int indexDoschefes) {

        char buff[10240]; // onde ele vai escrever
        sprintf(buff, "ChefeCozinha_%0d.txt", indexDoschefes);

        FILE *arquivo;
        arquivo = fopen(buff, "a");

        char mesa[30]; // escreve o nome da mesa

        sprintf(mesa, "Mesa %d:", this->numeroDaMesa());

        fprintf(arquivo, "%s \r\n", mesa);
        fclose(arquivo);


    }

};


#endif //RESTAURANTEFUTURISTICO_PEDIDO_H
