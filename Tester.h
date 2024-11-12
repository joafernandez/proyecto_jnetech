//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__TESTER_H
#define PROYECTO_JNETECH__TESTER_H

#include "Empleado.h"
#include <string>

using namespace std;

class Tester : public Empleado {
private:
    string especialidadPruebas;  // Especialidad en pruebas (funcionales, de rendimiento, etc.)

public:
    Tester(const string &nombre, const string &especialidadPruebas);

    string getEspecialidadPruebas() const;
    void setEspecialidadPruebas(const string &especialidadPruebas);
    virtual string to_String();
};

#endif //PROYECTO_JNETECH__TESTER_H
