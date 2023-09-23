#include <iostream>
#include "stdexcept"
#include "stdlib.h"
#include "time.h"
#include "VDinamico.h"

int main() {
    int limite = 10000;
    //Definimos el vector dinamico con limite de elementos
    VDinamico<int> v(limite);
    int i =0;
    //Flag para meter el valor dentro del vector
    bool mete;
    //Inicializo un semilla aleatoria
    srand(time(NULL));
    do{
        //Obtenemos el numero aleatorio entre 1 y 1000000
        int x = rand() %1000000 + 1;
       //Si el numero esta en el vector
        if(v[i] == x){
            mete = true;
        }
        //Si no esta en el vector
        if(!mete){
            v[i] = x;
        }
        //Incrementa
        i++;
    } while (i < limite);
    //Imprimo el vector menor a mayor
    for (int j = 0; j <20 ; ++j) {
        v.ordenar();
        std::cout<<v[j]<<std::endl;
    }
    /*
    //Imprimo el vector mayor a menor
    for (int j = 0; j <i ; ++j) {
        v.ordenarMayorAmenor();
        std::cout<<v[j]<<std::endl;
    }
*/
}
