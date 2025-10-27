#include "DetalleVenta.h"
#include <iostream>
using namespace std;

DetalleVenta::DetalleVenta() {
    _IDVenta = 0;
    _IDProducto = 0;
    _IDListaPrecio = 0;
    _precioUnitario = 0.0;
    _cantidad = 0;
    _estadoDetalleVenta = true;
}


DetalleVenta::~DetalleVenta() {}


void DetalleVenta::setIDVenta(int idVenta) {
    _IDVenta = idVenta;
}

void DetalleVenta::setIDProducto(int idProducto) {
    _IDProducto = idProducto;
}

void DetalleVenta::setIDListaPrecio(int idLista) {
    _IDListaPrecio = idLista;
}

void DetalleVenta::setPrecioUnitario(float precio) {
    _precioUnitario = precio;
}

void DetalleVenta::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleVenta::setEstadoDetalleVenta(bool estado) {
    _estadoDetalleVenta = estado;
}

// Getters
int DetalleVenta::getIDVenta() const {
    return _IDVenta;
}

int DetalleVenta::getIDProducto() const {
    return _IDProducto;
}

int DetalleVenta::getIDListaPrecio() const {
    return _IDListaPrecio;
}

float DetalleVenta::getPrecioUnitario() const {
    return _precioUnitario;
}

int DetalleVenta::getCantidad() const {
    return _cantidad;
}

bool DetalleVenta::getEstadoDetalleVenta() const {
    return _estadoDetalleVenta;
}

void DetalleVenta::cargar() {
    int idVenta, idProducto, idLista, cantidad;
    float precio;

    cout << "ID de la venta: ";
    cin >> idVenta;
    setIDVenta(idVenta);

    cout << "ID del producto: ";
    cin >> idProducto;
    setIDProducto(idProducto);

    cout << "ID de la lista de precio: ";
    cin >> idLista;
    setIDListaPrecio(idLista);

    cout << "Precio unitario: ";
    cin >> precio;
    setPrecioUnitario(precio);

    cout << "Cantidad: ";
    cin >> cantidad;
    setCantidad(cantidad);

    setEstadoDetalleVenta(true);
}
void DetalleVenta::mostrar(){
    cout << "ID Venta: " << getIDVenta() << endl;
    cout << "ID Producto: " << getIDProducto() << endl;
    cout << "ID Lista Precio: " << getIDListaPrecio() << endl;
    cout << "Precio Unitario: $" << getPrecioUnitario() << endl;
    cout << "Cantidad: " << getCantidad() << endl;
    cout << "Estado: " << (getEstadoDetalleVenta() ? "Activo" : "Inactivo") << endl;
}

bool DetalleVenta::escribirDisco(int pos) {
    FILE* p = fopen("detalleventa.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleVenta), SEEK_SET);
    bool ok = fwrite(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

bool DetalleVenta::leerDisco(int pos) {
    FILE* p = fopen("detalleventa.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleVenta), SEEK_SET);
    bool ok = fread(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return ok;
}

