#include "Compra.h"
#include <iostream>
using namespace std;


Compra::Compra() {
    _IDCompra = 0;
    _IDProveedor = 0;
    _totalCompra = 0.0;
    _estadoCompra = true;
}


Compra::~Compra() {}

// Setters
void Compra::setIDCompra(int id) {
    _IDCompra = id;
}

void Compra::setIDProveedor(int idProv) {
    _IDProveedor = idProv;
}

void Compra::setFechaCompra(Fecha fecha) {
    fechaCompra = fecha;
}

void Compra::setTotalCompra(float total) {
    _totalCompra = total;
}

void Compra::setEstadoCompra(bool estado) {
    _estadoCompra = estado;
}

// Getters
int Compra::getIDCompra() const {
    return _IDCompra;
}

int Compra::getIDProveedor() const {
    return _IDProveedor;
}

Fecha Compra::getFechaCompra() const {
    return fechaCompra;
}

float Compra::getTotalCompra() const {
    return _totalCompra;
}

bool Compra::getEstadoCompra() const {
    return _estadoCompra;
}


void Compra::cargar() {
    int id, idProv;
    float total;
    Fecha fecha;

    cout << "ID de la compra: ";
    cin >> id;
    setIDCompra(id);

    cout << "ID del proveedor: ";
    cin >> idProv;
    setIDProveedor(idProv);

    cout << "Fecha de la compra:" << endl;
    fecha.Cargar();
    setFechaCompra(fecha);

    cout << "Total de la compra: ";
    cin >> total;
    setTotalCompra(total);

    setEstadoCompra(true);
}


void Compra::mostrar(){
    cout << "ID Compra: " << getIDCompra() << endl;
    cout << "Fecha: ";
    getFechaCompra().Mostrar();
    cout << "Total: $" << getTotalCompra() << endl;
    cout << "Estado: " << (getEstadoCompra() ? "Activo" : "Inactivo") << endl;
}




bool Compra::escribirDisco() {
    FILE* p = fopen("compra.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(this, sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}


bool Compra::leerDisco(int pos) {
    FILE* p = fopen("compra.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Compra), SEEK_SET);
    bool ok = fread(this, sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}
