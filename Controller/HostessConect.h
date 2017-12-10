//
// Created by Asaf Santana on 16/11/2017.
//
#include <iostream>
#include <queue>
#include "Cardapio.h"
#include "../Model/Mesa.h"
#include "Cozinha.h"


#ifndef RESTAURANTEFUTURISTICO_HOSTESSCONECT_H
#define RESTAURANTEFUTURISTICO_HOSTESSCONECT_H

using namespace std;

class HostessConect {

private:
    Cozinha *cozinha;
    Cardapio *cardapio;
    map<int, Mesa> mesasDisponiveis;


public:

    HostessConect(int mesas, int chefes, Cardapio *cardapio) {
        this->cozinha = new Cozinha(chefes);
        this->cardapio = cardapio;

        for (int i = 1; i <= chefes; ++i) {
            criarArquivoDosChefes(i);
        }


        for (int i = 1; i <= mesas; ++i) {
            Mesa mesa(i);
            mesasDisponiveis.emplace(i, mesa);
        }

    }

    void fazerPedido(int numeroDaMesa, string pedidoDaMesa) {

        if (pedidoDaMesa != "fim") {
            mesasDisponiveis.at(numeroDaMesa).setEspereando(1);
            Pedido pedido = Pedido(&mesasDisponiveis.at(numeroDaMesa), cardapio->getItemDoCardapio(stoi(pedidoDaMesa)));
            this->cozinha->adicionarPedido(pedido);
        } else {
            mesasDisponiveis.at(numeroDaMesa).setPediuFim(true);
        }

    }

    void fecharRestaurante(){
        this->cozinha->FimCozinha();
    }


private:

/**
* inicia os arquivos, se existir outro arquivo com o mesmo nome ele zera --wt--
*/
    void criarArquivoDosChefes(int indexDoschefes) {
        char buff[10240];
        sprintf(buff, "ChefeCozinha_%0d.txt", indexDoschefes);

        FILE *arquivo;
        arquivo = fopen(buff, "wt");
        fclose(arquivo);

    }


};


#endif //RESTAURANTEFUTURISTICO_HOSTESSCONECT_H
