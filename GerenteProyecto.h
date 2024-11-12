//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__GERENTEPROYECTO_H
#define PROYECTO_JNETECH__GERENTEPROYECTO_H

#include "Proyecto.h"
#include "Reporte.h"
using namespace std;

class GerenteProyecto : public Empleado {
private:
    Proyecto *proyecto;

public:
    GerenteProyecto(const string &nombre, Proyecto *proyecto);

    void agregarEmpleado(Empleado *empleado);
    void eliminarEmpleado(Empleado *empleado);

    Proyecto *getProyecto() const;

    // gestión del proyecto
    void agregarTarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado);
    void eliminarTarea(Tarea *tarea);
    void setEstadoTarea(size_t i, const string &estado);
    void setEmpleadoTarea(size_t i, Empleado *empleado);

    // gestión de reuniones
    void agregarReunion(const Fecha &fecha, const Hora &hora);
    void agregarDecision(size_t i, const string &decision);
    void agregarAccion(size_t i, const string &accion);

    virtual string toString() const;

    Reporte *hacerReporte();

};
#endif //PROYECTO_JNETECH__GERENTEPROYECTO_H
