#pragma once
#include <iostream>
using namespace std;

class Precio {
private:
    int _IDProducto;
    int _IDTipoLista;
    float _precio;

public:

    Precio();
    ~Precio();

    // Setters
    void setIDProducto(int idProducto);
    void setIDTipoLista(int idTipoLista);
    void setPrecio(float precio);

    // Getters
    int getIDProducto() const;
    int getIDTipoLista() const;
    float getPrecio() const;

    // Metodos
    void cargar();
    void mostrar() const;
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};



