//
// Created by joana on 12/11/2024.
//


#include "ReunionSeguimiento.h"
#include <iostream>

ReunionSeguimiento::ReunionSeguimiento(const Fecha &fecha, const Hora &hora)
        : fecha(fecha), hora(hora) {}

Fecha ReunionSeguimiento::getFecha() const {
    return fecha;
}

Hora ReunionSeguimiento::getHora() const {
    return hora;
}

void ReunionSeguimiento::agregarAsistente(Empleado *asistente) {
    asistentes.push_back(asistente);
}

void ReunionSeguimiento::agregarTema(string tema) {
    temas.push_back(tema);
}

void ReunionSeguimiento::agregarDecision(string decision) {
    decisiones.push_back(decision);
}

void ReunionSeguimiento::agregarAccion(string accion) {
    acciones.push_back(accion);
}

vector<Empleado*>::const_iterator ReunionSeguimiento::beginAsistentes() const {
    return asistentes.begin();
}

vector<Empleado*>::const_iterator ReunionSeguimiento::endAsistentes() const {
    return asistentes.end();
}

vector<string>::const_iterator ReunionSeguimiento::beginTemas() const {
    return temas.begin();
}

vector<string>::const_iterator ReunionSeguimiento::endTemas() const {
    return temas.end();
}

vector<string>::const_iterator ReunionSeguimiento::beginDecisiones() const {
    return decisiones.begin();
}

vector<string>::const_iterator ReunionSeguimiento::endDecisiones() const {
    return decisiones.end();
}

vector<string>::const_iterator ReunionSeguimiento::beginAcciones() const {
    return acciones.begin();
}

vector<string>::const_iterator ReunionSeguimiento::endAcciones() const {
    return acciones.end();
}

bool ReunionSeguimiento::operator<(const ReunionSeguimiento &otra) const {
    return fecha < otra.fecha || (fecha == otra.fecha && hora < otra.hora);
}

bool ReunionSeguimiento::operator>(const ReunionSeguimiento &otra) const {
    return fecha > otra.fecha || (fecha == otra.fecha && hora < otra.hora);
}

bool ReunionSeguimiento::operator<=(const ReunionSeguimiento &otra) const {
    return fecha < otra.fecha || (fecha == otra.fecha && hora <= otra.hora);
}

bool ReunionSeguimiento::operator>=(const ReunionSeguimiento &otra) const {
    return fecha > otra.fecha || (fecha == otra.fecha && hora <= otra.hora);
}

bool ReunionSeguimiento::operator==(const ReunionSeguimiento &otra) const {
    return fecha == otra.fecha && hora == otra.hora;
}

bool ReunionSeguimiento::operator!=(const ReunionSeguimiento &otra) const {
    return fecha != otra.fecha || hora != otra.hora;
}