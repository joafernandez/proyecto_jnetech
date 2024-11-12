//
// Created by joana on 12/11/2024.
//

#include "Tarea.h"

#include <iostream>

Tarea::Tarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado)
        : nombre(nombre), estado("Pendiente"), fechaLimite(fechaLimite), empleadoAsignado(empleadoAsignado) {}

string Tarea::getNombre() const {
    return nombre;
}

string Tarea::getEstado() const {
    return estado;
}

Fecha Tarea::getFechaLimite() const {
    return fechaLimite;
}

Empleado* Tarea::getEmpleadoAsignado() const {
    return empleadoAsignado;
}

void Tarea::setEstado(const string &estado) {
    this->estado = estado;
}

void Tarea::setEmpleadoAsignado(Empleado *empleado) {
    this->empleadoAsignado = empleado;
}

// Sobrecarga de operadores para comparar fechas límite de tareas
bool Tarea::operator<(const Tarea &otra) const {
    return fechaLimite < otra.fechaLimite;
}

bool Tarea::operator>(const Tarea &otra) const {
    return fechaLimite > otra.fechaLimite;
}

bool Tarea::operator<=(const Tarea &otra) const {
    return fechaLimite <= otra.fechaLimite;
}

bool Tarea::operator>=(const Tarea &otra) const {
    return fechaLimite >= otra.fechaLimite;
}

bool Tarea::operator==(const Tarea &otra) const {
    return fechaLimite == otra.fechaLimite;
}

bool Tarea::operator!=(const Tarea &otra) const {
    return fechaLimite != otra.fechaLimite;
}

string Tarea::toString() const {
    return
            "\nNombre: " + nombre +
            "\nEstado: " + estado +
            "\nFecha: " + fechaLimite.toString() +
            "\nEmpleado: " + empleadoAsignado->toString();
}

