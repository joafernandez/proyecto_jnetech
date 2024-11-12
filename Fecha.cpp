//
// Created by joana on 12/11/2024.
//

#include "Fecha.h"
#include <stdexcept>      // std::invalid_argument

Fecha::Fecha(int d, int m, int a) {
    if(fechaValida(d, m, a)) {
        fecha = a*10000 + m*100 + d ;
    } else {
        fecha = -1;
    }
}

Fecha::Fecha() : fecha(-1) { }

bool Fecha::fechaValida(int d, int m, int a) {
    bool valida = a > 0 && m >= 1 && m <= 12 && d >= 1;
    if(valida) {
        int dias[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if(bisiesto(a)) {
            dias[1] = 29;
        }
        valida = d <= dias[m-1];
    }
    return valida;
}

bool Fecha::bisiesto(int a) {
    return a%4 == 0 && (a%100 != 0 || a%400 == 0);
}

Fecha Fecha::fromString(string strFecha) {
    int d = 0, m = 0, a = 0;
    size_t pos;
    try {
        d = stoi(strFecha, &pos);
        strFecha.erase(0,pos+1);
        m = stoi(strFecha, &pos);
        strFecha.erase(0,pos+1);
        a = stoi(strFecha, &pos);
    } catch (const invalid_argument &arg) { }
    return Fecha(d, m, a);
}

int Fecha::getFecha() const {
    return fecha;
}

string Fecha::toString() const {
    int d = fecha % 100;
    int m = (fecha/100) % 100;
    int a = fecha / 10000;
    return to_string(d) + "-" + to_string(m) + "-" + to_string(a);
}

bool Fecha::esNula() const {
    return fecha == -1;
}

bool Fecha::operator < (const Fecha &otra) const {
    return fecha < otra.fecha;
}

bool Fecha::operator > (const Fecha &otra) const {
    return fecha > otra.fecha;
}

bool Fecha::operator <= (const Fecha &otra) const {
    return fecha <= otra.fecha;
}

bool Fecha::operator >= (const Fecha &otra) const {
    return fecha >= otra.fecha;
}

bool Fecha::operator == (const Fecha &otra) const {
    return fecha == otra.fecha;
}

bool Fecha::operator != (const Fecha &otra) const {
    return fecha != otra.fecha;
}
