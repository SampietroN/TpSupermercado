#pragma once
#include <iostream>
using namespace std;

class DetalleCompra {
private:
    int _IDCompra;
    int _IDProducto;
    int _cantidad;
    float _precioUnitario;
    bool _estadoDetalleCompra;

public:

    DetalleCompra();
    ~DetalleCompra();

    // Setters
    void setIDCompra(int idCompra);
    void setIDProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setEstadoDetalleCompra(bool estado);

    // Getters
    int getIDCompra() const;
    int getIDProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    bool getEstadoDetalleCompra() const;

    // Metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};



