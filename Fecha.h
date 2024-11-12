//
// Created by joana on 12/11/2024.
//

#ifndef PROYECTO_JNETECH__FECHA_H
#define PROYECTO_JNETECH__FECHA_H

#include <string>
using namespace std;

class Fecha {
private:
    int fecha;      // formato aaaammdd

public:
    Fecha();
    Fecha(int d, int m, int a);

    int getFecha() const;
    string toString() const;
    bool esNula() const;

    bool operator < (const Fecha &otra) const;
    bool operator > (const Fecha &otra) const;
    bool operator <= (const Fecha &otra) const;
    bool operator >= (const Fecha &otra) const;
    bool operator == (const Fecha &otra) const;
    bool operator != (const Fecha &otra) const;

    static bool fechaValida(int d, int m, int a);
    static bool bisiesto(int a);
    static Fecha fromString(string strFecha);
};

#endif //PROYECTO_JNETECH__FECHA_H
