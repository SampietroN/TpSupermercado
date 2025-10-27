#include "Venta.h"
#include "ClaseFecha.h"
#include <iostream>
#include <cstring>
using namespace std;


Venta::Venta() {
    _IDVenta = 0;
    strcpy(_DNI, "");
    _IDEmpleado = 0;
    _precioTotal = 0.0;
    _estadoVenta = true;
}


Venta::~Venta() {}

// Setters
void Venta::setIDVenta(int id) {
    _IDVenta = id;
}

void Venta::setDNI(const char* dni) {
    strncpy(_DNI, dni, sizeof(_DNI));
    _DNI[sizeof(_DNI) - 1] = '\0';
}

void Venta::setIDEmpleado(int idEmpleado) {
    _IDEmpleado = idEmpleado;
}

void Venta::setPrecioTotal(float precio) {
    _precioTotal = precio;
}

void Venta::setFechaVenta(Fecha fecha) {
    fechaVenta = fecha;
}

void Venta::setEstadoVenta(bool estado) {
    _estadoVenta = estado;
}

// Getters
int Venta::getIDVenta() const {
    return _IDVenta;
}

const char* Venta::getDNI() const {
    return _DNI;
}

int Venta::getIDEmpleado() const {
    return _IDEmpleado;
}

float Venta::getPrecioTotal() const {
    return _precioTotal;
}

Fecha Venta::getFechaVenta() const {
    return fechaVenta;
}

bool Venta::getEstadoVenta() const {
    return _estadoVenta;
}


void Venta::cargar() {
    int id, idEmpleado;
    float total;
    char dni[10];
    Fecha fecha;

    cout << "ID de la venta: ";
    cin >> id;
    setIDVenta(id);
    cin.ignore();

    cout << "DNI del cliente: ";
    cin.getline(dni, sizeof(dni));
    setDNI(dni);

    cout << "ID del empleado: ";
    cin >> idEmpleado;
    setIDEmpleado(idEmpleado);

    cout << "Fecha de la venta:" << endl;
    fecha.Cargar();
    setFechaVenta(fecha);

    cout << "Precio total: ";
    cin >> total;
    setPrecioTotal(total);

    setEstadoVenta(true);
}

void Venta::mostrar(){
    cout << "ID Venta: " << getIDVenta() << endl;
    cout << "DNI Cliente: " << getDNI() << endl;
    cout << "ID Empleado: " << getIDEmpleado() << endl;
    cout << "Fecha: ";
    getFechaVenta().Mostrar();
    cout << "Precio Total: $" << getPrecioTotal() << endl;
    cout << "Estado: " << (getEstadoVenta() ? "Activo" : "Inactivo") << endl;
}

bool Venta::escribirDisco(int pos) {
    FILE* p = fopen("venta.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}


bool Venta::leerDisco(int pos) {
    FILE* p = fopen("venta.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}




