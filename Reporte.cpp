//
// Created by joana on 12/11/2024.
//

#include "Reporte.h"
#include <iostream>
using namespace std;

Reporte::Reporte(Proyecto *proyecto) {
    this->proyecto = proyecto;
}

void Reporte::nominaEmpleados() {
    cout << endl;
    cout << "Nomina de empleados del proyecto " << proyecto->getNombre() << endl;
    for(auto r = proyecto->beginEmpleados(); r != proyecto->endEmpleados(); r++) {
        cout << (*r)->toString();
    }
}

void Reporte::reunionesSeguimiento() {
    cout << endl;
    cout << "Reporte de reuniones del proyecto " << proyecto->getNombre() << endl;
    for(auto r = proyecto->beginReuniones(); r != proyecto->endReuniones(); r++) {
        cout << endl;
        cout << "Reunion del " << (*r)->getFecha().toString() << " a las " << (*r)->getHora().toString() << endl;
        cout << "Asistentes" << endl;
        for(auto a = (*r)->beginAsistentes(); a != (*r)->endAsistentes(); a++) {
            cout << (*a)->toString();
        }
        cout << "Temas" << endl;
        for(auto a = (*r)->beginTemas(); a != (*r)->endTemas(); a++) {
            cout << *r << endl;
        }
        cout << "Decisiones" << endl;
        for(auto a = (*r)->beginDecisiones(); a != (*r)->endDecisiones(); a++) {
            cout << *r << endl;
        }
        cout << "Acciones" << endl;
        for(auto a = (*r)->beginAcciones(); a != (*r)->endAcciones(); a++) {
            cout << *r << endl;
        }
    }
}

void Reporte::tareas() {
    cout << endl;
    cout << "Reporte de todas las tareas del proyecto " << proyecto->getNombre() << endl;
    for(auto r = proyecto->beginTareas(); r != proyecto->endTareas(); r++) {
        cout << (*r)->getNombre() << endl;
    }
}

void Reporte::tareasCompletadas() {
    cout << endl;
    cout << "Reporte de tareas completadas del proyecto " << proyecto->getNombre() << endl;
    for(auto r = proyecto->beginTareas(); r != proyecto->endTareas(); r++) {
        if((*r)->getEstado() == "Finalizada") {
            cout << (*r)->getNombre() << endl;
        }
    }
}
