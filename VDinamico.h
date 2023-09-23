//
// Created by ajgar on 19/09/2023.
//
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

template <class T>
VDinamico<T>::~VDinamico() {
    delete[] vector;
}

//Constructor por defecto
template<class T>
VDinamico<T>::VDinamico(unsigned int n) {
    vector = new T[tama = n];
}

//Constructor copia
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
    //Constructor copia, comprobamos que no sea la misma direccion de memoria
        //Eliminamos el vector que teniamos
        delete[] vector;
        //Reservamos en memoria con el tamaño del que vamos a copiar
        vector = new int[tama=origen.tama];
        //Le pasamos cada posicion de memoria del vector origen
        for (int i = 0; i < origen.tama ; ++i) {
            vector[i] =origen.vector[i];
        }
}

//Constructor de copia parcial parametrizado
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned  int posicioninicial, unsigned  int numElementos){

    if(posicioninicial > numElementos){
        throw std::out_of_range("Ha susperado el limite de elementos");
    }
    delete[]vector;
    //Creamos un vector con el tamaño asignado a la diferencia del numero de elementos con la posicion inical
    vector = new int[tama=numElementos-posicioninicial];
    for (int i = 0; i < tama; ++i) {
        vector[i] = origen.vector[posicioninicial+i];
    }

}

//Operador de asignación (=).
template<class T>
VDinamico<T> &VDinamico<T>::operator = (const VDinamico <T> &origen){
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
}

//Operador corchetes []
template <class T>
T &VDinamico<T>::operator[](unsigned  long int pos){
    if(pos >= tama){
        throw std::out_of_range("Ha superado el limite de elementos");
    }
    //En caso contrario devolvemos la posicion
    return vector[pos];
}

//Ordenar de menor a mayor
template <class T>
void VDinamico<T>::ordenar() {
    std::sort(vector,vector + tama);
}

//Ordenar de mayor a menor
template <class T>
void VDinamico<T>::ordenarMayorAmenor(){
    std::sort(vector,vector + tama,std::greater<T>());
}

#endif //PR1_VDINAMICO_H
