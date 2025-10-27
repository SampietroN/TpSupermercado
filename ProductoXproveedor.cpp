#include "ProductoXProveedor.h"
#include "funcionesGlobales.h"
#include <iostream>
using namespace std;


ProductoXProveedor::ProductoXProveedor() {
    _IDProducto = 0;
    _IDProveedor = 0;
    _precioCosto = 0.0;
}


ProductoXProveedor::~ProductoXProveedor() {}

// Setters
void ProductoXProveedor::setIDProducto(int idProducto) {
    _IDProducto = idProducto;
}

void ProductoXProveedor::setIDProveedor(int idProveedor) {
    _IDProveedor = idProveedor;
}

void ProductoXProveedor::setPrecioCosto(float costo) {
    _precioCosto = costo;
}

// Getters
int ProductoXProveedor::getIDProducto() const {
    return _IDProducto;
}

int ProductoXProveedor::getIDProveedor() const {
    return _IDProveedor;
}

float ProductoXProveedor::getPrecioCosto() const {
    return _precioCosto;
}


void ProductoXProveedor::cargar() {
    int idProd;
    int idProv;
    float costo;

    cout << "ID del Producto: ";
    cin >> idProd;
    while(!existeProducto(idProd)){

        cout<<"El ID del Producto no existe"<<endl;
        cout<<"Intente Nuevamente: ";
        cin>> idProd;
    }
    setIDProducto(idProd);

    cout << "ID del Proveedor: ";
    cin >> idProv;
    while(!existeProveedor(idProv)){

        cout<<"El ID del Proveedor no existe"<<endl;
        cout<<"Intente Nuevamente: ";
        cin>> idProv;
    }
    setIDProveedor(idProv);

    if (existePoductoDelProveedor(idProd, idProv)) {
        cout << "El producto ya esta registrado para ese proveedor." << endl;
        cout << "Volviendo al menu" << endl;
        return;
    }

    cout << "Precio de costo ofrecido por el proveedor: ";
    cin >> costo;
    setPrecioCosto(costo);
}




void ProductoXProveedor::mostrar() const {
    cout << "ID Producto: " << getIDProducto() << endl;
    cout << "ID Proveedor: " << getIDProveedor() << endl;
    cout << "Precio Costo: $" << getPrecioCosto() << endl;
}



bool ProductoXProveedor::escribirDisco() {
    FILE* p = fopen("productoXproveedor.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(this, sizeof(ProductoXProveedor), 1, p);
    fclose(p);
    return ok;
}


bool ProductoXProveedor::leerDisco(int pos) {
    FILE* p = fopen("productoXproveedor.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(ProductoXProveedor), SEEK_SET);
    bool ok = fread(this, sizeof(ProductoXProveedor), 1, p);
    fclose(p);
    return ok;
}



