//
// Created by joana on 12/11/2024.
//

#include "Empleado.h"


Empleado::Empleado(const string &nom, const string &pues) :
        nombre(nom), puesto(pues), numProyectos(0) {}

string Empleado::getNombre() const {
    return nombre;
}

string Empleado::getPuesto() const {
    return puesto;
}

int Empleado::getNumProyectos() const {
    return numProyectos;
}

void Empleado::asignarProyecto() {
    numProyectos++;
}

void Empleado::finalizarTarea() {
    if (numProyectos > 0) {
        numProyectos--;
    }
}

string Empleado::toString() const {
    return
            "\nNombre: " + nombre +
            "\nPuesto: " + puesto +
            "\nProyectos: " + to_string(numProyectos) + "\n";
}

bool Empleado::operator<(const Empleado &otro) const {
    return this->numProyectos < otro.numProyectos;
}

bool Empleado::operator>(const Empleado &otro) const {
    return this->numProyectos > otro.numProyectos;
}

bool Empleado::operator<=(const Empleado &otro) const {
    return this->numProyectos <= otro.numProyectos;
}

bool Empleado::operator>=(const Empleado &otro) const {
    return this->numProyectos >= otro.numProyectos;
}

bool Empleado::operator==(const Empleado &otro) const {
    return this->numProyectos == otro.numProyectos;
}

bool Empleado::operator!=(const Empleado &otro) const {
    return this->numProyectos != otro.numProyectos;
}
