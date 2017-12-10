//
// Created by Asaf Santana on 19/09/2017.
//

#ifndef COZINHASISTEMASOPERACIONAIS_MESA_H
#define COZINHASISTEMASOPERACIONAIS_MESA_H

#include <iostream>
#include <queue>

using namespace std;

class Mesa {


private:
    int INDEX;
    bool pediuFim = false;
    int esperando = 0;
public:


    Mesa(int index) {
        this->INDEX = index;
    }


    bool getPediuFim() {
        return this->pediuFim;
    }


    void setPediuFim(bool fim) {
        this->pediuFim = fim;
    }


    int getINDEX() {
        return this->INDEX;
    }

/**
*  retorna verdadeiro de ele estiver esperando e falso se nao estiver esperando
* @return
*/
    bool getEsperando() {
        if (esperando > 0) {
            return true;
        } else {
            return false;
        }
    }

    void setEspereando(int i) {
        this->esperando + (i);
    }


};

#endif //COZINHASISTEMASOPERACIONAIS_CHEFECOZINHA_H
