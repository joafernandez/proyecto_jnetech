//
// Created by joana on 12/11/2024.
//

#include "Tester.h"
#include <iostream>

Tester::Tester(const string &nombre, const string &especialidadPruebas)
        : Empleado(nombre, "Tester"), especialidadPruebas(especialidadPruebas) {}

string Tester::getEspecialidadPruebas() const {
    return especialidadPruebas;
}

void Tester::setEspecialidadPruebas(const string &especialidadPruebas) {
    this->especialidadPruebas = especialidadPruebas;
}

string Tester::to_String() {
    return
            Empleado::toString() +
            "Especialidad: " + especialidadPruebas + "\n";
}

