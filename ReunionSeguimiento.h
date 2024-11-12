//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__REUNIONSEGUIMIENTO_H
#define PROYECTO_JNETECH__REUNIONSEGUIMIENTO_H


#include <string>
#include <vector>
#include "Fecha.h"
#include "Hora.h"
#include "Empleado.h"

using namespace std;

class ReunionSeguimiento {
private:
    Fecha fecha;
    Hora hora;

    vector<Empleado*> asistentes;
    vector<string> temas;
    vector<string> decisiones;
    vector<string> acciones;

    // Métodos privados ejecutados exclusivamente por GerenteProyecto (friend)
    void  agregarAsistente(Empleado *asistente);
    void  agregarTema(string tema);
    void  agregarDecision(string decision);
    void  agregarAccion(string accion);

public:
    ReunionSeguimiento(const Fecha &fecha, const Hora &hora);

    Fecha getFecha() const;
    Hora getHora() const;

    vector<Empleado*>::const_iterator beginAsistentes() const;
    vector<Empleado*>::const_iterator endAsistentes() const;
    vector<string>::const_iterator beginTemas() const;
    vector<string>::const_iterator endTemas() const;
    vector<string>::const_iterator beginDecisiones() const;
    vector<string>::const_iterator endDecisiones() const;
    vector<string>::const_iterator beginAcciones() const;
    vector<string>::const_iterator endAcciones() const;

    bool operator < (const ReunionSeguimiento &otra) const;
    bool operator > (const ReunionSeguimiento &otra) const;
    bool operator <= (const ReunionSeguimiento &otra) const;
    bool operator >= (const ReunionSeguimiento &otra) const;
    bool operator == (const ReunionSeguimiento &otra) const;
    bool operator != (const ReunionSeguimiento &otra) const;

    friend class GerenteProyecto;
};
#endif //PROYECTO_JNETECH__REUNIONSEGUIMIENTO_H
