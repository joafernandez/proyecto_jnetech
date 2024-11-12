//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__TAREA_H
#define PROYECTO_JNETECH__TAREA_H


#include <string>
#include "Empleado.h"
#include "Fecha.h"

using namespace std;

class Tarea {
private:
    string nombre;
    string estado;  //Ppendiente, En progreso, Finalizada
    Fecha fechaLimite;
    Empleado *empleadoAsignado;

    // Métodos privados ejecutados exclusivamente por GerenteProyecto (friend)
    void setEstado(const string &estado);
    void setEmpleadoAsignado(Empleado *empleado);

public:
    Tarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado);

    // Getters y Setters
    string getNombre() const;
    string getEstado() const;
    Fecha getFechaLimite() const;
    Empleado *getEmpleadoAsignado() const;

    bool operator<(const Tarea &otra) const;
    bool operator>(const Tarea &otra) const;
    bool operator<=(const Tarea &otra) const;
    bool operator>=(const Tarea &otra) const;
    bool operator==(const Tarea &otra) const;
    bool operator!=(const Tarea &otra) const;

    string toString() const;

    friend class GerenteProyecto;
};
#endif //PROYECTO_JNETECH__TAREA_H
