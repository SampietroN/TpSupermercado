#include <iostream>
#include "FuncionesAuxiliares.h"
#include "productos.h"
#include "Proveedor.h"
#include "ProductoXproveedor.h"
#include "Compra.h"
#include "DetalleCompra.h"
using namespace std;


void cargarFacturaCompra() {
    Compra nueva;
    DetalleCompra nuevoDetalle;
    int Idcompra, IDprov;
    float total = 0;
    float totalProducto = 0;
    char continuar = 's';

    cout << "----Factura----" << endl;
    cout << "----------------" << endl;

    cout << "ID Compra: ";
    cin >> Idcompra;
    nueva.setIDCompra(Idcompra);

    Fecha fecha;
    cout << "Fecha de la compra:" << endl;
    fecha.Cargar();
    nueva.setFechaCompra(fecha);

    cout << "ID Proveedor: ";
    cin >> IDprov;
    while (!existeProveedor(IDprov)) {
        cout << "El ID del Proveedor no existe" << endl;
        cout << "Intente Nuevamente: ";
        cin >> IDprov;
    }
    nueva.setIDProveedor(IDprov);


    while (continuar == 's' || continuar == 'S') {
        nuevoDetalle.cargarBucle(Idcompra, IDprov);

        nuevoDetalle.escribirDisco();

        totalProducto = nuevoDetalle.getCantidad() * nuevoDetalle.getPrecioUnitario();
        total += totalProducto;

        cout <<"Cargar mas Productos? (s/n): ";
        cin >> continuar;
    }

    nueva.setTotalCompra(total);
    nueva.setEstadoCompra(true);
    nueva.escribirDisco();
}

void mostrarFacturasCompra() {
    Compra nueva;
    DetalleCompra nuevoDetalle;
    int posCompra = 0;

    cout << "=== LISTADO DE COMPRAS ===" << endl;

    while (nueva.leerDisco(posCompra)) {
        cout << "ID de Compra: " << nueva.getIDCompra() << endl;
        cout<< "ID Proveedor: "<<nueva.getIDProveedor()<<endl;
        cout << "Fecha: ";
        nueva.getFechaCompra().Mostrar();
        cout << endl;


        cout << "--- Detalles ---" << endl;
        int posDetalle = 0;
        while (nuevoDetalle.leerDisco(posDetalle)) {
            if (nuevoDetalle.getIDCompra() == nueva.getIDCompra()) {
                nuevoDetalle.mostrar();
                cout << "----------------" << endl;
            }
            posDetalle++;
        }

        cout << "Total: $" << nueva.getTotalCompra() << endl;
        cout << "==========================" << endl;
        posCompra++;
    }
}

bool existeProducto(int idBuscado) {
    Producto prod;
    int pos = 0;
    while (prod.leerDisco(pos)) {
        if (prod.getIDProducto() == idBuscado && prod.getEstadoProducto()) {
            return true;
        }
        pos++;
    }
    return false;
}

bool existeProveedor(int idBuscado) {
    Proveedor prov;
    int pos = 0;
    while (prov.leerDisco(pos)) {
        if (prov.getID() == idBuscado && prov.getEstado()) {
            return true;
        }
        pos++;
    }
    return false;
}

bool existePoductoDelProveedor(int idProd, int idProv) {
    ProductoXProveedor relacion;
    int pos = 0;
    while (relacion.leerDisco(pos)) {
        if (relacion.getIDProducto() == idProd && relacion.getIDProveedor() == idProv) {
            return true;
        }
        pos++;
    }
    return false;
}

float PrecioProductoXProveedor(int idProd, int idProv) {
    ProductoXProveedor relacion;
    int pos = 0;

    while (relacion.leerDisco(pos)) {
        if (relacion.getIDProducto() == idProd && relacion.getIDProveedor() == idProv) {
            return relacion.getPrecioCosto();
        }
        pos++;
    }


    return -1.0;
}









