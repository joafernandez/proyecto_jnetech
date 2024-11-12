//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__DESARROLLADOR_H
#define PROYECTO_JNETECH__DESARROLLADOR_H

#include "Empleado.h"

#include <string>


class Desarrollador : public Empleado {
private:
    string lenguajeDominado;                    // Lenguaje de programación en el que se especializa el desarrollador

public:
    // Constructor
    Desarrollador(const string &nombre, const string &lenguajeDominado);

    // Getter y Setter
    string getLenguajeDominado() const;
    void setLenguajeDominado(const string &lenguajeDominado);

    virtual string toString() const;

};


#endif //PROYECTO_JNETECH__DESARROLLADOR_H
