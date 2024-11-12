
#include "Cliente.h"
#include <iostream>

Cliente::Cliente(const string &nombre, const string &empresa, const string &contacto)
        : nombre(nombre), empresa(empresa), contacto(contacto) {}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getEmpresa() const {
    return empresa;
}

string Cliente::getContacto() const {
    return contacto;
}

Reporte *Cliente::solicitarReporte(GerenteProyecto *gerente) const {
    return gerente->hacerReporte();
}

string Cliente::toString() const {
    return
            "\nNombre: " + nombre +
            "\nEmpresa: " + empresa +
            "\nContacto: " + contacto + "\n";
}

