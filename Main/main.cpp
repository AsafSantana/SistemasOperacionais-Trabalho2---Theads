
#include <iostream>

#include "../Controller/Cardapio.h"
#include "../Controller/HostessConect.h"

using namespace std;


int numeroDaMesa = 0;
string pedidoDaMesa = "";


/**
 * Diferencia o pedido e o numero da mesa
 * @param pedidoenumero
 */


void pedido_E_Mesa(string pedidoenumero) {
    bool flag = false;
    string numero;
    string pedido;
    for (int i = 0; i < pedidoenumero.size(); ++i) {
        if (pedidoenumero[i] == ' ' && !flag) {
            flag = true;
            ++i; // para tirar o primeiro espaço
        }

        if (!flag) {
            numero = numero + pedidoenumero[i];

        } else {
            pedido = pedido + pedidoenumero[i];

        }


    }
    numeroDaMesa = stoi(numero);
    pedidoDaMesa = pedido;

}


int main() {


    int numeroDeItens = 0;
    int numeroDeChefes = 0;
    int numeroDeMesas = 0;

    Cardapio cardapio;

    cin >> numeroDeItens;
    cin.ignore();

    // Faz  o cardapio
    for (int i = 1; i <= numeroDeItens; ++i) {

        bool flag = false;
        string itemetempo = "";
        string nomeDoItem = "";
        string tempo = "";

        cout << i << " ";

        getline(cin, itemetempo);


        // separa o item do tempo
        for (int j = 0; j < itemetempo.size(); ++j) {

            if (itemetempo[j] == ' ' && !flag) {
                flag = true;
                ++j; // para tirar o primeiro espaço
            }

            if (!flag) {
                tempo = tempo + itemetempo[j];

            } else {
                nomeDoItem = nomeDoItem + itemetempo[j];

            }
        }


        Item item(i, stoi(tempo), nomeDoItem);
        cardapio.addItem(item);


    }


    cin >> numeroDeChefes >> numeroDeMesas;
    cin.ignore();

    string pedido;
    getline(cin, pedido);

    HostessConect hostess(numeroDeMesas, numeroDeChefes, &cardapio);


    while (pedido != "Fim") {

        pedido_E_Mesa(pedido);

        hostess.fazerPedido(numeroDaMesa, pedidoDaMesa);

        getline(cin, pedido);

        if (pedido == "Fim") {
            hostess.fecharRestaurante();
        }
    }


    return 0;
}