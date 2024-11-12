//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__PROYECTO_H
#define PROYECTO_JNETECH__PROYECTO_H

#include <string>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"
#include "Fecha.h"
#include "ReunionSeguimiento.h"

using namespace std;


class Proyecto{
private:
    string nombre;
    string descripcion;
    Fecha fechaInicio;
    Fecha fechaFin;
    vector<Empleado*>empleados;             // lista de empleados
    vector<Tarea*>tareas;                   // lista de tareas
    vector<ReunionSeguimiento*> reuniones;  // lista de reuniones
    Empleado *gerente;

    // Métodos privados ejecutados exclusivamente por GerenteProyecto (friend)
    void asignarGerente(Empleado *gerente);
    void agregarEmpleado(Empleado *empleado);
    void eliminarEmpleado(Empleado *empleado);
    void agregarTarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado);
    void eliminarTarea(Tarea *tarea);
    void agregarReunion(const Fecha &fecha, const Hora &hora);

public:
    Proyecto(const string &nombre, const string &descripcion, const Fecha &fechaInicio, const Fecha &fechaFin);

    string getNombre() const;
    string getDescripcion() const;
    Fecha getFechaInicio() const;
    Fecha getFechaFin() const;
    Empleado *getGerente() const;

    vector<Empleado*>::const_iterator beginEmpleados() const;
    vector<Empleado*>::const_iterator endEmpleados() const;
    vector<Tarea*>::const_iterator beginTareas() const;
    vector<Tarea*>::const_iterator endTareas() const;
    vector<ReunionSeguimiento*>::const_iterator beginReuniones() const;
    vector<ReunionSeguimiento*>::const_iterator endReuniones() const;
    vector<Empleado*> getEmpleados();

    bool operator<(const Proyecto &otro) const;
    bool operator>(const Proyecto &otro) const;
    bool operator<=(const Proyecto &otro) const;
    bool operator>=(const Proyecto &otro) const;
    bool operator==(const Proyecto &otro) const;
    bool operator!=(const Proyecto &otro) const;

    string toString() const;

    friend class GerenteProyecto;
};

#endif //PROYECTO_JNETECH__PROYECTO_H
