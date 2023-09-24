#include <iostream>
#include "stdexcept"
#include "stdlib.h"
#include "time.h"
#include "VDinamico.h"
/**
 * @brief Crear un vector dinamico de tamaño 1 millon y almacena valores aleatorios no repetidos
 * Ademas de eso en funcion de lo que queramos ordena el vector
 * @return
 */
int main() {
    int limite = 100000;
    //Definimos el vector dinamico con limite de elementos
    VDinamico<int> v(limite);
    int i =0;
    //Inicializo un semilla aleatoria
    srand(time(NULL));
    try{
        do{
            //Flag para meter el valor dentro del vector
            bool mete = true;
            //Obtenemos el numero aleatorio entre 1 y 1000000
            int x = rand() %1000000 + 1;
            //Si el numero esta en el vector
            if(v[i] == x){
                mete = false;
            }
            //Si no esta en el vector
            if(mete){
                v[i] = x;
            }
            //Incrementa
            i++;
        } while (i < limite);
    }catch(std::bad_alloc &e){
        std::cerr << "No hay suficiente espacio de memoria disponible" <<std::endl;
    }
    //region Imprimo el vector menor a mayor
    /*
        for (int j = 0; j <20 ; ++j) {
            v.ordenar();
            std::cout<<v[j]<<std::endl;
        }
    */
    //endregion
    //region Imprimo el vector mayor a menor
    for (int j = 0; j <20 ; ++j) {
        v.ordenarMayorAmenor();
        std::cout<<v[j]<<std::endl;
    }
    //endregion
}
