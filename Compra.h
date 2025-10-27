#pragma once
#include <iostream>
#include "ClaseFecha.h"
using namespace std;

class Compra {
private:
    int _IDCompra;
    Fecha fechaCompra;
    float _totalCompra;
    int _IDProveedor;
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
    bool escribirDisco();
    bool leerDisco(int pos);
};

