//
// Created by joana on 12/11/2024.
//

#include "GerenteProyecto.h"


GerenteProyecto::GerenteProyecto(const string &nombre, Proyecto *proyecto)
        : Empleado(nombre, "Gerente de proyecto"), proyecto(proyecto) {
    proyecto->agregarEmpleado(this);
    proyecto->asignarGerente(this);
}

Proyecto *GerenteProyecto::getProyecto() const {
    return proyecto;
}

void GerenteProyecto::agregarEmpleado(Empleado *empleado) {
    proyecto->agregarEmpleado(empleado);
}

void GerenteProyecto::eliminarEmpleado(Empleado *empleado) {
    proyecto->eliminarEmpleado(empleado);
}

void GerenteProyecto::agregarTarea(const string &nombre, const Fecha &fechaLimite, Empleado *empleadoAsignado) {
    proyecto->agregarTarea(nombre, fechaLimite, empleadoAsignado);
}

void GerenteProyecto::eliminarTarea(Tarea *tarea) {
    proyecto->eliminarTarea(tarea);
}

void GerenteProyecto::setEstadoTarea(size_t i, const string &estado) {
    if(i < proyecto->tareas.size()) {
        proyecto->tareas[i]->setEstado(estado);
    }
}

void GerenteProyecto::setEmpleadoTarea(size_t i, Empleado *empleado) {
    if(i < proyecto->tareas.size()) {
        proyecto->tareas[i]->setEmpleadoAsignado(empleado);
    }
}

void GerenteProyecto::agregarReunion(const Fecha &fecha, const Hora &hora) {
    proyecto->agregarReunion(fecha, hora);
}

void GerenteProyecto::agregarDecision(size_t i, const string &decision) {
    if(i < proyecto->reuniones.size()) {
        proyecto->reuniones[i]->agregarDecision(decision);
    }
}

void GerenteProyecto::agregarAccion(size_t i, const string &accion) {
    if(i < proyecto->reuniones.size()) {
        proyecto->reuniones[i]->agregarAccion(accion);
    }
}

Reporte *GerenteProyecto::hacerReporte() {
    return new Reporte(proyecto);
}

string GerenteProyecto::toString() const {
    return
            Empleado::toString() +
            "Proyecto: " + proyecto->toString() + "\n";
}

