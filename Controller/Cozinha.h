//
// Created by Asaf Santana on 23/11/2017.
//

#ifndef RESTAURANTEFUTURISTICO_COZINHA_H
#define RESTAURANTEFUTURISTICO_COZINHA_H

#include <iostream>
#include "Pedido.h"


#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include <mutex>

using namespace std;

class Cozinha {

private:
    bool fimCozinha = true;
    queue<Pedido> pedidosEmEspera;
    sem_t pedido, fimDaCozinha;

    mutex preparando;
public:

   /**
    * sincroniza o metodo coma thread
    * @param arg
    * @return
    */
    static void *sincronizar(void *arg) {
        static int i = 0;
        Cozinha *c = (Cozinha *) arg;
        c->cozinheirosCozinhando(++i);
    }

    /**
     *
     * @param numeroDeCozinheiros
     */
    Cozinha(int numeroDeCozinheiros) {
        sem_init(&pedido, 0, 0);
        sem_init(&fimDaCozinha, 0, 0);
        int i;


        pthread_t cozinheiro_id[numeroDeCozinheiros];

        for (i = 0; i < numeroDeCozinheiros; i++) {
            pthread_create(&cozinheiro_id[i], NULL, &sincronizar, (void *) this);
        }


        for (i = 0; i >= numeroDeCozinheiros; --i) {
            pthread_join(cozinheiro_id[i], NULL);
        }
    }


/**
 * verdadeiro = cozinha aberta,  falso = cozinha fechada
 * @param fim
 */
    void FimCozinha() {
        sem_wait(&fimDaCozinha);
        this->fimCozinha = false;
        sem_destroy(&pedido);
        preparando.~mutex();
    }

    void adicionarPedido(Pedido ped) {
        this->pedidosEmEspera.push(ped);
        sem_post(&pedido);
    }

    void *cozinheirosCozinhando(int id) {

        while (fimCozinha || pedidosEmEspera.size() != 0) {

            sem_wait(&pedido);
            preparando.lock();
            char buff[10240]; // onde ele vai escrever
            sprintf(buff, "ChefeCozinha_%0d.txt", id);

            FILE *arquivo;
            arquivo = fopen(buff, "a");

            pedidosEmEspera.front().escreverMesaAtendida(id); // trava

            fprintf(arquivo, "     - %s \r\n", pedidosEmEspera.front().getPedido().c_str());
            fclose(arquivo);
            sleep(pedidosEmEspera.front().TempoDePreparo());

            pedidosEmEspera.front().pedidoFeito();

            pedidosEmEspera.pop();

            if (pedidosEmEspera.size() == 0) {
                sem_post(&fimDaCozinha);
            }
            preparando.unlock(); // destrava
        }

        return NULL;
    }

};


#endif //RESTAURANTEFUTURISTICO_COZINHA_H
