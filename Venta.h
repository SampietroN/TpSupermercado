#pragma once
#include <iostream>
#include "ClaseFecha.h"
using namespace std;

class Venta {
private:
    int _IDVenta;
    char _DNI[10];
    int _IDEmpleado;
    float _precioTotal;
    Fecha fechaVenta;
    bool _estadoVenta;

public:

    Venta();
    ~Venta();

    // Setters
    void setIDVenta(int id);
    void setDNI(const char* dni);
    void setIDEmpleado(int idEmpleado);
    void setPrecioTotal(float precio);
    void setFechaVenta(Fecha fecha);
    void setEstadoVenta(bool estado);

    // Getters
    int getIDVenta() const;
    const char* getDNI() const;
    int getIDEmpleado() const;
    float getPrecioTotal() const;
    Fecha getFechaVenta() const;
    bool getEstadoVenta() const;

    // Metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};


