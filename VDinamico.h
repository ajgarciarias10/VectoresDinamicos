//
// Created by ajgar on 19/09/2023.
//
/**
 * @file VDinamico.h
 * @date 24/09/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @title Vector Dinamico
 */
#include "stdexcept"
#ifndef PR1_VDINAMICO_H
#define PR1_VDINAMICO_H
#include "algorithm"
template<class T>
class VDinamico {
    private:
        //Puntero a tipo generico
        T *vector;
        //Tamaño del vector sin signo long el entero mas grande
        unsigned long int tama;
    public :
            //Constructor por defecto
            VDinamico(unsigned  int n);
            //Constructor de copia
            VDinamico(const VDinamico<T>& origen);
            //Constructor de copia por trozos
            VDinamico(const VDinamico<T> &origen, unsigned  int posicioninicial, unsigned  int numElementos);
            //Destructor
            ~VDinamico();
            //Operator igual
            VDinamico<T> &operator = (const VDinamico <T> &origen);
            //Operator corchetes se usa para acceder al vector
            T &operator[](unsigned  long int pos);
            //Ordenar de menor a mayor
            void ordenar();
            //Ordenar de mayor a menor
            void ordenarMayorAmenor();
    };


/**
 * @brief Constructor por defecto del vector dinamico
 * @tparam T
 * @param n Tamaño asignado al vector
 */
template<class T>
VDinamico<T>::VDinamico(unsigned int n) {
    vector = new T[tama = n];
}
/**
 * @brief Constructor copia
 * @tparam T
 * @param origen Direccion de memoria del vector dinamico
 *
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
        //Reservamos en memoria con el tamaño del que vamos a copiar
        vector = new T[tama=origen.tama];
        //Le pasamos cada posicion de memoria del vector origen
        for (int i = 0; i < origen.tama ; ++i) {
            vector[i] =origen.vector[i];
        }
}
/**
 * @brief Constructor de copia parcial
 * @tparam T
 * @param origen Direccion de memoria del vector dinamico
 * @param posicioninicial   Posicion inicial del vector dinamico
 * @param numElementos      Le pasamos el numero de elementos maximo que vamos a utilizar en el main
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned  int posicioninicial, unsigned  int numElementos){
    //Comprobamos si la posicion inicial supera el numero de elementos
    if(posicioninicial > numElementos){
        throw std::out_of_range("Ha susperado el limite de elementos");
    }
    //Eliminamos el vector
    delete[]vector;
    //Creamos un vector con el tamaño asignado a la diferencia del numero de elementos con la posicion inical
    vector = new int[tama=numElementos-posicioninicial];
    for (int i = 0; i < tama; ++i) {
        vector[i] = origen.vector[posicioninicial+i];
    }
}
/**
 * @brief Destructor del vector dinamico
 * @tparam T
 */
template <class T>
VDinamico<T>::~VDinamico() {
    //Borramos el vector
    delete[] vector;
}
/**
 * @brief Operator igual pasamos la posicion memoria del vector de origen al vector dinamico
 * @tparam T
 * @param origen
 * @return
 */

template<class T>
VDinamico<T> &VDinamico<T>::operator = (const VDinamico <T> &origen){
    //Comprobamos que no sea la misma direccion de memoria
    if(this!=origen) {
        //Eliminamos el vector que teniamos
        delete[] vector;
        //Reservamos en memoria con el tamaño del que vamos a copiar
        vector = new int[tama = origen.tama];
        //Le pasamos cada posicion de memoria del vector origen
        for (int i = 0; i < origen.tama; ++i) {
            vector[i] = origen.vector[i];
        }
    }
    return *this;
}

/**
 * @brief Operator corchete devuelve el contenido del  vector
 * @tparam T
 * @param pos Parametro en el que utilizamos la posicion del vector para poder obtener el contenido del vector
 * @return
 */
template <class T>
T &VDinamico<T>::operator[](unsigned  long int pos){
    //Comprobamos si la posicion supera el tamaño
    if(pos >= tama){
        throw std::out_of_range("Ha superado el limite de elementos");
    }
    //En caso contrario devolvemos la posicion
    return vector[pos];
}

/**
 * @brief Ordena el vector de menor a mayor con la funcion sort
 * @tparam T
 */
template <class T>
void VDinamico<T>::ordenar() {
    std::sort(vector,vector + tama);
}

/**
 * @brief Ordena el vector de mayor a menor
 * @tparam T
 */
template <class T>
void VDinamico<T>::ordenarMayorAmenor(){
    std::sort(vector,vector + tama,std::greater<T>());
}

#endif //PR1_VDINAMICO_H

