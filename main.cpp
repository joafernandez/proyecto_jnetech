#include <iostream>
#include <vector>
#include "Fecha.h"
#include "Hora.h"
#include "Cliente.h"
#include "Proyecto.h"
#include "Empleado.h"
#include "Desarrollador.h"
#include "Tester.h"
#include "GerenteProyecto.h"
#include "Tarea.h"
#include "ReunionSeguimiento.h"
#include <sstream>
#include <algorithm>

using namespace std;

void cargarClientes(vector<Cliente*> &clientes) {
    clientes.push_back(new Cliente("Farmacity", "Farmacity", "contacto@gmail.com"));
    clientes.push_back(new Cliente("AnibalTuc", "AnibalTuc", "info@gmail.com"));
    clientes.push_back(new Cliente("FerTec", "FerTec", "fercto@gmail.com"));
    clientes.push_back(new Cliente("TurboTejada", "TurboTejada", "contacto@turbotejada.com"));
    clientes.push_back(new Cliente("DAS", "DAS", "info@das.com"));
    clientes.push_back(new Cliente("Digital Solutions", "Digital Solutions", "digitalsolutions@gamil.com"));
    clientes.push_back(new Cliente("TecnoFe", "TecnoFe", "soporte@tecnofe.com"));
}

void cargarProyectos(vector<Proyecto*> &proyectos) {
    proyectos.push_back(new Proyecto("Portal de Ventas Online", "Desarrollo de un portal de ventas para productos electronicos", Fecha(1,9,2024), Fecha(3,12,2024)));
    proyectos.push_back(new Proyecto("App de Pedidos de Comida", "Desarrollo de una aplicacion movil para pedidos de comida a domicilio", Fecha(3,9,2024), Fecha(1,12,2024)));
    proyectos.push_back(new Proyecto("Sistema de Gestion de Inventarios", "Sistema para gestionar inventarios de una cadena de tiendas", Fecha(7,9,2024), Fecha(6,12,2024)));
    proyectos.push_back(new Proyecto("Automatizacion de Facturacion", "Proyecto para automatizar el proceso de facturacion de la empresa", Fecha(8,9,2024), Fecha(2,12,2024)));
    proyectos.push_back(new Proyecto("Sistema de Soporte Tecnico", "Desarrollo de una plataforma para gestionar solicitudes de soporte tecnico", Fecha(10,9,2024), Fecha(4,12,2024)));
    proyectos.push_back(new Proyecto("Integracion de API de Pagos", "Integracion de una nueva API de pagos para la plataforma de ventas", Fecha(14,9,2024), Fecha(2,12,2024)));
    proyectos.push_back(new Proyecto("Aplicacion de Chat para Atencion al Cliente", "Desarrollo de una aplicacion de chat en tiempo real para atencion al cliente", Fecha(18,9,2024), Fecha(6,12,2024)));
}

void cargarEmpleados(vector<Empleado*> &empleados, vector<Proyecto*> &proyectos) {
    empleados.push_back(new GerenteProyecto("Carlos", proyectos[0]));
    empleados.push_back(new GerenteProyecto("Miguel", proyectos[1]));
    empleados.push_back(new GerenteProyecto("Laura", proyectos[2]));
    empleados.push_back(new GerenteProyecto("German", proyectos[3]));
    empleados.push_back(new GerenteProyecto("Alicia", proyectos[4]));
    empleados.push_back(new GerenteProyecto("Sergio", proyectos[5]));
    empleados.push_back(new GerenteProyecto("Claudia", proyectos[6]));
    empleados.push_back(new Desarrollador("Juan", "C++"));
    empleados.push_back(new Desarrollador("Pedro", "Java"));
    empleados.push_back(new Desarrollador("Luis", "Python"));
    empleados.push_back(new Desarrollador("Ana", "JavaScript"));
    empleados.push_back(new Tester("Maria", "Pruebas de Rendimiento"));
    empleados.push_back(new Tester("Sofia", "Pruebas Funcionales"));
    empleados.push_back(new Tester("Lucia", "Pruebas de Seguridad"));
}

int ingresarEnteroEntre(const string mensaje, int minimo, int maximo) {
    int numero;
    cout << mensaje;
    cin >> numero;
    while(numero < minimo || numero > maximo) {
        cout << "Debe ser entre " << minimo << " y " << maximo << ": ";
        cin >> numero;
    }
    return numero;
}

Fecha ingresarFecha() {
    string strFecha;
    Fecha fecha;
    cout << "Fecha (dd-mm-aaaa): ";
    getline(cin, strFecha);
    while((fecha = Fecha::fromString(strFecha)).esNula()) {
        cout << "Fecha incorrecta: ";
        getline(cin, strFecha);
    }
    return fecha;
}

Hora ingresarHora() {
    string strHora;
    Hora hora;
    cout << "Hora (hh:mm): ";
    getline(cin, strHora);
    while((hora = Hora::fromString(strHora)).esNula()) {
        cout << "Hora incorrecta: ";
        getline(cin, strHora);
    }
    return hora;
}

int menuPrincipal() {
    cout << endl;
    cout << "====== MENU PRINCIPAL ======" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Mostrar clientes" << endl;
    cout << "2. Mostrar proyectos" << endl;
    cout << "3. Mostrar empleados" << endl;
    cout << "4. Agregar tarea" << endl;
    cout << "5. Agregar empleado" << endl;
    cout << "6. Generar reporte" << endl;
    return ingresarEnteroEntre("Ingrese su opcion: ", 0, 6);
}

int menuEmpleados(const vector<Empleado*> &empleados) {
    cout << endl;
    cout << "====== MENU DE EMPLEADOS ======" << endl;
//    cout << "0. Salir" << endl;
    int i = 0;
    for(Empleado *e : empleados) {
        cout << ++i << ". " << e->getNombre() << " (" << e->getPuesto() << ")" << endl;;
    }
    return ingresarEnteroEntre("Seleccione el empleado: ", 1, i);
}

int menuGerentes(const vector<Empleado*> &empleados) {
    cout << endl;
    cout << "====== MENU DE GERENTES ======" << endl;
    cout << "0. Salir" << endl;
    int i = 0;
    for(Empleado *e : empleados) {
        if(e->getPuesto() == "Gerente de proyecto") {
            GerenteProyecto *g = static_cast<GerenteProyecto *>(e);
            cout << ++i << ". " << g->getNombre() << " (" << g->getProyecto()->getNombre() << ")" << endl;
        }
    }
    return ingresarEnteroEntre("Seleccione el gerente: ", 0, i);
}

int menuTareas(const vector<Tarea*> &tareas) {
    cout << endl;
    cout << "====== MENU DE TAREAS ======" << endl;
    cout << "0. Salir" << endl;
    int i = 0;
    for(Tarea *e : tareas) {
        cout << ++i << ". " << e->getNombre() << endl;
    }
    return ingresarEnteroEntre("Seleccione la tarea: ", 0, i);
}

int menuProyectos(const vector<Proyecto*> &proyectos) {
    cout << endl;
    cout << "====== MENU DE PROYECTOS ======" << endl;
    cout << "0. Salir" << endl;
    int i = 0;
    for(Proyecto *p : proyectos) {
        cout << ++i << ". " << p->getNombre() << " (" << p->getGerente()->getNombre() << ")" << endl;;
    }
    return ingresarEnteroEntre("Seleccione el proyecto: ", 0, i);
}

void mostrarClientes(const vector<Cliente*> &clientes) {
    cout << endl;
    cout << "====== LISTA DE CLIENTES ======" << endl;
    for(Cliente *x : clientes) {
        cout << x->toString();
    }
}

void mostrarProyectos(const vector<Proyecto*> &proyectos) {
    cout << endl;
    cout << "====== LISTA DE PROYECTOS ======" << endl;
    for(Proyecto *x : proyectos) {
        cout << x->toString();
    }
}

void mostrarEmpleados(const vector<Empleado*> &empleados) {
    cout << endl;
    cout << "====== LISTA DE EMPLEADOS ======" << endl;
    for(Empleado *x : empleados) {
        cout << x->toString();
    }
}

void agregarTarea(const vector<Proyecto*> &proyectos) {
    int opcion = menuProyectos(proyectos);
    if(opcion != 0) {
        Proyecto *proyecto = proyectos[opcion-1];
        cout << "Proyecto elegido: " << proyecto->getNombre()  << endl;
        GerenteProyecto *gerente = static_cast<GerenteProyecto *>(proyecto->getGerente());
        string nombre;
        cout << "Nombre de la tarea: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Limite de realizacion: " << endl;
        Fecha fecha = ingresarFecha();
        opcion = menuEmpleados(proyecto->getEmpleados());
        Empleado *empleado = proyecto->getEmpleados()[opcion-1];
        gerente->agregarTarea(nombre, fecha, empleado);
    }
}

void agregarEmpleado(const vector<Proyecto*> &proyectos, const vector<Empleado*> &empleados) {
    int opcion = menuProyectos(proyectos);
    if(opcion != 0) {
        Proyecto *proyecto = proyectos[opcion-1];
        cout << "Proyecto elegido: " << proyecto->getNombre()  << endl;
        GerenteProyecto *gerente = static_cast<GerenteProyecto *>(proyecto->getGerente());
        opcion = menuEmpleados(empleados);
        Empleado *empleado = empleados[opcion-1];
        gerente->agregarEmpleado(empleado);
        cout << "Empleado agregado: " << endl << empleado->toString() << endl;
    }
}

void generarReporte(vector<Proyecto*> &proyectos) {
    int opcion = menuProyectos(proyectos);
    if(opcion != 0) {
        Proyecto *proyecto = proyectos[opcion-1];
        GerenteProyecto *gerente = static_cast<GerenteProyecto *>(proyecto->getGerente());
        Reporte *reporte = gerente->hacerReporte();
        reporte->nominaEmpleados();
        reporte->reunionesSeguimiento();
        reporte->tareas();
        reporte->tareasCompletadas();
    }
}

int main() {

    vector<Cliente*> clientes;
    vector<Proyecto*> proyectos;
    vector<Empleado*> empleados;

    cargarClientes(clientes);
    cargarProyectos(proyectos);
    cargarEmpleados(empleados, proyectos);

    int opcion;
    while((opcion = menuPrincipal()) != 0) {
        switch(opcion) {
            case 1:
                mostrarClientes(clientes);
                break;
            case 2:
                mostrarProyectos(proyectos);
                break;
            case 3:
                mostrarEmpleados(empleados);
                break;
            case 4:
                agregarTarea(proyectos);
                break;
            case 5:
                agregarEmpleado(proyectos, empleados);
                break;
            case 6:
                generarReporte(proyectos);
                break;
        }
        cout << endl << "Enter para continuar... ";
        cin.ignore();
        cin.get() ;
        system("cls");
    }
    cout << endl << "FIN DEL PROGRAMA" << endl;
    cout << endl << "Enter para finalizar... ";
    cin.ignore();
    cin.get() ;

    return 0;
}
