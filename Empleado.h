//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__EMPLEADO_H
#define PROYECTO_JNETECH__EMPLEADO_H

#include "string"
#include "iostream"

using namespace std;

class Empleado {
private:
    string nombre;
    string puesto;
    int numProyectos; //cantidad de proyectos.contador
public:                                             //declaro el contructor
    Empleado(const string &nom, const string &pues);

    string getNombre() const;
    string getPuesto() const;
    int getNumProyectos() const;

    void asignarProyecto();
    void finalizarTarea();
    virtual string toString() const;

    // para comparar empleados
    bool operator<(const Empleado &otro) const;
    bool operator>(const Empleado &otro) const;
    bool operator<=(const Empleado &otro) const;
    bool operator>=(const Empleado &otro) const;
    bool operator==(const Empleado &otro) const;
    bool operator!=(const Empleado &otro) const;
};
#endif //PROYECTO_JNETECH__EMPLEADO_H
