//
// Created by joana on 12/11/2024.
//

#include "Hora.h"
#include <stdexcept>      //

Hora::Hora(int h, int m) {
    if(horaValida(h, m)) {
        hora = h*100 + m ;
    } else {
        hora = -1;
    }
}

Hora::Hora() {
    hora = -1;
}

bool Hora::horaValida(int h, int m) {
    return h >= 0 && h < 24 && m >= 0 && m < 60;
}

Hora Hora::fromString(string strHora) {
    int h = -1, m = -1;
    size_t pos;
    try {
        h = stoi(strHora, &pos);
        strHora.erase(0,pos+1);
        m = stoi(strHora, &pos);
    } catch (const invalid_argument &arg) { }
    return Hora(h, m);
}

int Hora::getHora() const {
    return hora;
}

string Hora::toString() const {
    int h = hora / 100;
    int m = hora % 100;
    return to_string(h) + ":" + to_string(m);
}

bool Hora::esNula() const {
    return hora == -1;
}

bool Hora::operator < (const Hora &otra) const {
    return hora < otra.hora;
}

bool Hora::operator > (const Hora &otra) const {
    return hora > otra.hora;
}

bool Hora::operator <= (const Hora &otra) const {
    return hora <= otra.hora;
}

bool Hora::operator >= (const Hora &otra) const {
    return hora >= otra.hora;
}

bool Hora::operator == (const Hora &otra) const {
    return hora == otra.hora;
}

bool Hora::operator != (const Hora &otra) const {
    return hora != otra.hora;
}
