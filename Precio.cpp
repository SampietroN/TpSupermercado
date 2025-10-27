#include "Precio.h"
#include <iostream>
using namespace std;


Precio::Precio() {
    _IDProducto = 0;
    _IDTipoLista = 0;
    _precio = 0.0;
}

Precio::~Precio() {

}

// Setters
void Precio::setIDProducto(int idProducto) {
    _IDProducto = idProducto;
}

void Precio::setIDTipoLista(int idTipoLista) {
    _IDTipoLista = idTipoLista;
}

void Precio::setPrecio(float precio) {
    _precio = precio;
}

// Getters
int Precio::getIDProducto() const {
    return _IDProducto;
}

int Precio::getIDTipoLista() const {
    return _IDTipoLista;
}

float Precio::getPrecio() const {
    return _precio;
}


void Precio::cargar() {
    int idProd, tipoLista;
    float valor;

    cout << "ID del Producto: ";
    cin >> idProd;
    setIDProducto(idProd);

    cout << "ID del Tipo de Lista: ";
    cin >> tipoLista;
    setIDTipoLista(tipoLista);

    cout << "Precio: ";
    cin >> valor;
    setPrecio(valor);
}


void Precio::mostrar() const {
    cout << "ID Producto: " << getIDProducto() << endl;
    cout << "ID Tipo de Lista: " << getIDTipoLista() << endl;
    cout << "Precio: $" << getPrecio() << endl;
}


bool Precio::escribirDisco(int pos) {
    FILE* p = fopen("precio.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Precio), SEEK_SET);
    bool ok = fwrite(this, sizeof(Precio), 1, p);
    fclose(p);
    return ok;
}


bool Precio::leerDisco(int pos) {
    FILE* p = fopen("precio.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Precio), SEEK_SET);
    bool ok = fread(this, sizeof(Precio), 1, p);
    fclose(p);
    return ok;
}

