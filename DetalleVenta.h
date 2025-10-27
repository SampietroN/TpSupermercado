#pragma once
#include <iostream>
using namespace std;

class DetalleVenta {
private:
    int _IDVenta;
    int _IDProducto;
    int _IDListaPrecio;
    float _precioUnitario;
    int _cantidad;
    bool _estadoDetalleVenta;

public:

    DetalleVenta();
    ~DetalleVenta();

    // Setters
    void setIDVenta(int idVenta);
    void setIDProducto(int idProducto);
    void setIDListaPrecio(int idLista);
    void setPrecioUnitario(float precio);
    void setCantidad(int cantidad);
    void setEstadoDetalleVenta(bool estado);

    // Getters
    int getIDVenta() const;
    int getIDProducto() const;
    int getIDListaPrecio() const;
    float getPrecioUnitario() const;
    int getCantidad() const;
    bool getEstadoDetalleVenta() const;

    // Metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};

