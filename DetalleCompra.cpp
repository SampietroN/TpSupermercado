#include "DetalleCompra.h"
#include "funcionesGlobales.h"
#include <iostream>
using namespace std;


DetalleCompra::DetalleCompra() {
    _IDCompra = 0;
    _IDProducto = 0;
    _IDProveedor = 0;
    _cantidad = 0;
    _precioUnitario = 0.0;
    _estadoDetalleCompra = true;
}


DetalleCompra::~DetalleCompra() {}

// Setters
void DetalleCompra::setIDCompra(int idCompra) {
    _IDCompra = idCompra;
}

void DetalleCompra::setIDProveedor(int idProv) {
    _IDProveedor = idProv;
}

void DetalleCompra::setIDProducto(int idProducto) {
    _IDProducto = idProducto;
}

void DetalleCompra::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleCompra::setPrecioUnitario(float precio) {
    _precioUnitario = precio;
}

void DetalleCompra::setEstadoDetalleCompra(bool estado) {
    _estadoDetalleCompra = estado;
}

// Getters
int DetalleCompra::getIDCompra() const {

    return _IDCompra;
}
int DetalleCompra::getIDProveedor() const {
    return _IDProveedor;
}

int DetalleCompra::getIDProducto() const {
    return _IDProducto;
}

int DetalleCompra::getCantidad() const {
    return _cantidad;
}

float DetalleCompra::getPrecioUnitario() const {
    return _precioUnitario;
}

bool DetalleCompra::getEstadoDetalleCompra() const {
    return _estadoDetalleCompra;
}


void DetalleCompra::cargar() {
    int idCompra, idProducto, cantidad, idProv;
    float precio;

    cout << "ID de la compra: ";
    cin >> idCompra;
    setIDCompra(idCompra);


    cout << "ID del Producto: ";
    cin >> idProducto;
    while(!existeProducto(idProducto)){

        cout<<"El ID del Producto no existe"<<endl;
        cout<<"Intente Nuevamente: ";
        cin>> idProducto;
    }
    setIDProducto(idProducto);

    cout << "ID del Proveedor: ";
    cin >> idProv;
    while(!existeProveedor(idProv)){

        cout<<"El ID del Proveedor no existe"<<endl;
        cout<<"Intente Nuevamente: ";
        cin>> idProv;
    }
    setIDProveedor(idProv);

    if (!existePoductoDelProveedor(idProducto, idProv)) {
        cout<<"El proveedor no ofrece ese producto. No se puede continuar." << endl;
        return;
    }

    cout << "Precio unitario: $";
    precio = PrecioProductoXProveedor(idProducto,idProv);
    cout<< precio;
    setPrecioUnitario(precio);

    cout << "Cantidad: ";
    cin >> cantidad;
    setCantidad(cantidad);

    setEstadoDetalleCompra(true);
}

void DetalleCompra::cargarBucle(int idCompra, int idProv ) {
    int  idProducto, cantidad;
    float precio;


    setIDCompra(idCompra);


    cout << "ID del Producto: ";
    cin >> idProducto;
    while(!existeProducto(idProducto)){

        cout<<"El ID del Producto no existe"<<endl;
        cout<<"Intente Nuevamente: ";
        cin>> idProducto;
    }
    setIDProducto(idProducto);

    setIDProveedor(idProv);

    if (!existePoductoDelProveedor(idProducto, idProv)) {
        cout<<"El proveedor no ofrece ese producto. No se puede continuar." << endl;
        return;
    }

    cout << "Precio unitario: $";
    precio = PrecioProductoXProveedor(idProducto,idProv);
    cout<< precio <<endl;
    setPrecioUnitario(precio);

    cout << "Cantidad: ";
    cin >> cantidad;
    setCantidad(cantidad);

    setEstadoDetalleCompra(true);
}

void DetalleCompra::mostrar() {
   // cout << "ID Compra: " << getIDCompra() << endl;
    //cout << "ID Proveedor: " << getIDProveedor() << endl;
    cout << "ID Producto: " << getIDProducto() << endl;
    cout << "Cantidad: " << getCantidad() << endl;
    cout << "Precio Unitario: $" << getPrecioUnitario() << endl;
    //cout << "Estado: " << (getEstadoDetalleCompra() ? "Activo" : "Inactivo") << endl;
}


/*bool DetalleCompra::escribirDisco(int pos) {
    FILE* p = fopen("detallecompra.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleCompra), SEEK_SET);
    bool ok = fwrite(this, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return ok;
}*/

bool DetalleCompra::escribirDisco() {
    FILE* p = fopen("detallecompra.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(this, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return ok;
}


bool DetalleCompra::leerDisco(int pos) {
    FILE* p = fopen("detallecompra.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(DetalleCompra), SEEK_SET);
    bool ok = fread(this, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return ok;
}

