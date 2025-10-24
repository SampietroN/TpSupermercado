#pragma once
#include <iostream>
#include "ClaseFecha.h"
using namespace std;

class Compra {
private:
    int _IDCompra;
    int _IDProveedor;
    Fecha fechaCompra;
    float _totalCompra;
    bool _estadoCompra;

public:

    Compra();
    ~Compra();

    // Setters
    void setIDCompra(int id);
    void setIDProveedor(int idProv);
    void setFechaCompra(Fecha fecha);
    void setTotalCompra(float total);
    void setEstadoCompra(bool estado);

    // Getters
    int getIDCompra() const;
    int getIDProveedor() const;
    Fecha getFechaCompra() const;
    float getTotalCompra() const;
    bool getEstadoCompra() const;

    // Metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};


