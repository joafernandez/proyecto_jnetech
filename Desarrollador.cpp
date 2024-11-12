//
// Created by joana on 12/11/2024.
//

#include "Desarrollador.h"
#include <iostream>

Desarrollador::Desarrollador(const string &nombre, const string &lenguajeDominado)
        : Empleado(nombre, "Desarrollador"), lenguajeDominado(lenguajeDominado) {}

// Getter y Setter
string Desarrollador::getLenguajeDominado() const {
    return lenguajeDominado;
}

void Desarrollador::setLenguajeDominado(const string &lenguajeDominado) {
    this->lenguajeDominado = lenguajeDominado;
}

string Desarrollador::toString() const {
    return
            Empleado::toString() +
            "Lenguaje: " + lenguajeDominado + "\n";
}
