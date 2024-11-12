//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__REPORTE_H
#define PROYECTO_JNETECH__REPORTE_H


#include <string>
#include <vector>
#include "ReunionSeguimiento.h"
#include "Proyecto.h"

using namespace std;

class Reporte {;
private:
    Proyecto *proyecto;

public:
    Reporte(Proyecto *proyecto);

    void nominaEmpleados();
    void reunionesSeguimiento();
    void tareas();
    void tareasCompletadas();

};

#endif //PROYECTO_JNETECH__REPORTE_H
