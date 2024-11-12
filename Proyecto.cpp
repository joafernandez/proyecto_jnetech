//
// Created by joana on 12/11/2024.
//

#include "Proyecto.h"
#include <iostream>
#include "algorithm"

Proyecto::Proyecto(const string &nombre, const string &descripcion, const Fecha &fechaInicio, const Fecha &fechaFin)
        : nombre(nombre), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

void Proyecto::asignarGerente(Empleado *gerente) {
    this->gerente = gerente;
}

Empleado *Proyecto::getGerente() const {
    return gerente;
}

string Proyecto::getNombre() const {
    return nombre;
}

string Proyecto::getDescripcion() const {
    return descripcion;
}

Fecha Proyecto::getFechaInicio() const {
    return fechaInicio;
}

Fecha Proyecto::getFechaFin() const {
    return fechaFin;
}

vector<Empleado*> Proyecto::getEmpleados() {
    return empleados;
}

void Proyecto::agregarEmpleado(Empleado *empleado) {
    empleados.push_back(empleado);
    empleado->asignarProyecto();
}

void Proyecto::eliminarEmpleado(Empleado *empleado) {
    empleados.erase(find(empleados.begin(), empleados.end(), empleado));
}

void Proyecto::agregarTarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado) {
    tareas.push_back(new Tarea(nombre, fechaLimite, empleadoAsignado));
}

void Proyecto::agregarReunion(const Fecha &fecha, const Hora &hora) {
    reuniones.push_back(new ReunionSeguimiento(fecha, hora));
}

void Proyecto::eliminarTarea(Tarea *tarea) {
    tareas.erase(find(tareas.begin(), tareas.end(), tarea));
}

// Métodos para iteradores personalizados
vector<Empleado*>::const_iterator Proyecto::beginEmpleados() const {
    return empleados.begin();
}

vector<Empleado*>::const_iterator Proyecto::endEmpleados() const {
    return empleados.end();
}

vector<Tarea*>::const_iterator Proyecto::beginTareas() const {
    return tareas.begin();
}

vector<Tarea*>::const_iterator Proyecto::endTareas() const {
    return tareas.end();
}

vector<ReunionSeguimiento*>::const_iterator Proyecto::beginReuniones() const {
    return reuniones.begin();
}

vector<ReunionSeguimiento*>::const_iterator Proyecto::endReuniones() const {
    return reuniones.end();
}

bool Proyecto::operator<(const Proyecto &otro) const {
    return fechaFin < otro.fechaFin;
}

bool Proyecto::operator>(const Proyecto &otro) const {
    return this->fechaFin > otro.fechaFin;
}

bool Proyecto::operator<=(const Proyecto &otro) const {
    return this->fechaFin <= otro.fechaFin;
}

bool Proyecto::operator>=(const Proyecto &otro) const {
    return this->fechaFin >= otro.fechaFin;
}

bool Proyecto::operator==(const Proyecto &otro) const {
    return this->fechaFin == otro.fechaFin;
}

bool Proyecto::operator!=(const Proyecto &otro) const {
    return this->fechaFin != otro.fechaFin;
}

string Proyecto::toString() const {
    return
            "\nNombre: " + nombre +
            "\nDescripcion: " + descripcion +
            "\nInicio: " + fechaInicio.toString() +
            "\nFin: " + fechaFin.toString() +
            "\nGerente: " + gerente->getNombre() + "\n";
}
