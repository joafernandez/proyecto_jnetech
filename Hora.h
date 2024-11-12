//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__HORA_H
#define PROYECTO_JNETECH__HORA_H

#include <string>
using namespace std;

class Hora {
private:
    int hora;      // formato hhmm

public:
    Hora();
    Hora(int h, int m);

    int getHora() const;
    string toString() const;
    bool esNula() const;

    bool operator < (const Hora &otra) const;
    bool operator > (const Hora &otra) const;
    bool operator <= (const Hora &otra) const;
    bool operator >= (const Hora &otra) const;
    bool operator == (const Hora &otra) const;
    bool operator != (const Hora &otra) const;

    static bool horaValida(int h, int m);
    static Hora fromString(string strHora);
};
#endif //PROYECTO_JNETECH__HORA_H
