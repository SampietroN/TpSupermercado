#include <iostream>
using namespace std;
#include "productos.h"
#include <cstring>



Producto::Producto() {
    _IDProducto = 0;
    strcpy(_nombreProducto, "");
    _tipoProducto = 0;
    _stock = 0;
    _costo = 0.0;
    _estadoProducto = true;
}


Producto::~Producto() {

}

// Setters
void Producto::setIDProducto(int id) {
    _IDProducto = id;
    }

void Producto::setNombreProducto(const char* nombre) {
    strncpy(_nombreProducto, nombre, sizeof(_nombreProducto));
    _nombreProducto[sizeof(_nombreProducto) - 1] = '\0';
}
void Producto::setTipoProducto(int tipo) {
     _tipoProducto = tipo;
     }
void Producto::setStock(int stock) {
     _stock = stock;
     }
void Producto::setCosto(float costo) {
     _costo = costo;
     }
void Producto::setEstadoProducto(bool estado) {
     _estadoProducto = estado;
      }

// Getters
int Producto::getIDProducto() const {
    return _IDProducto;
    }
const char* Producto::getNombreProducto() const {
    return _nombreProducto;
     }
int Producto::getTipoProducto() const {
    return _tipoProducto;
    }
int Producto::getStock() const {
    return _stock;
     }
float Producto::getCosto() const {
     return _costo;
     }
bool Producto::getEstadoProducto() const {
     return _estadoProducto;
      }


void Producto::cargar() {
    int id ;
    int tipo;
    int stock;
    float costo;
    char nombre [50];


    cout << "ID del producto: ";
    cin >> id;
    setIDProducto(id);
    cin.ignore();

    cout << "Nombre del producto: ";
    cin.getline(nombre,50 );

    cout << "Tipo de producto: ";
    cin >> tipo;
    setTipoProducto(tipo);

    cout << "Stock: ";
    cin >> stock;
    setStock(stock);

    cout << "Costo: ";
    cin >> costo;
    setCosto(costo);

    setEstadoProducto(true);
}

void Producto::mostrar() {
    cout << "ID: " << getIDProducto() << endl;
    cout << "Nombre: " << getNombreProducto() << endl;
    cout << "Tipo: " << getTipoProducto() << endl;
    cout << "Stock: " << getStock() << endl;
    cout << "Costo: $" << getCosto() << endl;
    cout << "Estado: " << (getEstadoProducto() ? "Activo" : "Inactivo") << endl;
}


bool Producto::leerDisco(int pos) {

    FILE* p = fopen("producto.dat", "rb");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Producto), SEEK_SET);
    bool ok = fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return ok;

}
bool Producto::escribirDisco(int pos) {

    FILE* p = fopen("producto.dat", "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Producto), SEEK_SET);
    bool ok = fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}


