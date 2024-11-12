//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__CLIENTE_H
#define PROYECTO_JNETECH__CLIENTE_H

#include <string>
#include "GerenteProyecto.h"

using namespace std;

class Cliente {
private:
    string nombre;
    string empresa;
    string contacto;

public:
    Cliente(const string &nombre, const string &empresa, const string &contacto);

    // Getters y Setters
    string getNombre() const;
    string getEmpresa() const;
    string getContacto() const;

    string toString() const;

    Reporte *solicitarReporte(GerenteProyecto *gerente) const;
};
#endif //PROYECTO_JNETECH__CLIENTE_H
