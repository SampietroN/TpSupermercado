#pragma once
#include <iostream>
using namespace std;

class ProductoXProveedor {
private:
    int _IDProducto;
    int _IDProveedor;
    float _precioCosto;

public:
    ProductoXProveedor();
    ~ProductoXProveedor();

    // Setters
    void setIDProducto(int idProducto);
    void setIDProveedor(int idProveedor);
    void setPrecioCosto(float costo);

    // Getters
    int getIDProducto() const;
    int getIDProveedor() const;
    float getPrecioCosto() const;

    // Funcionales
    void cargar();
    void mostrar() const;
    bool escribirDisco();
    bool leerDisco(int pos);
};




