#include <iostream>
using namespace std;
#include "productos.h"
#include <cstring>



Producto::Producto() {
    _IDProducto = 0;
    strcpy(_nombreProducto, "");
    _tipoProducto = 0;
    _stock = 0;
//    _costo = 0.0;
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
/*void Producto::setCosto(float costo) {
     _costo = costo;
     }*/
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
/*float Producto::getCosto() const {
     return _costo;
     }*/
bool Producto::getEstadoProducto() const {
     return _estadoProducto;
      }


void Producto::cargar() {
    int tipo;
    int stock;
   // float costo;
    char nombre [50];
    bool opcion;

    cout<<"Carga de Producto"<<endl;
    cout<<"................."<<endl<<endl;
    cout <<"Tipo de producto"<<endl;
    cout<<"Producto por Tipo"<<endl;
    cout<<"................."<<endl;
    cout << "0. Almacen" << endl;
    cout << "1. Verduleria" << endl;
    cout << "2. Lacteos" << endl;
    cout << "3. Bebidas" << endl;
    cout << "4. Carniceria" << endl;
    cout << "5. Panaderia" << endl;
    cout << "6. Limpieza" << endl;
    cout << "7. Perfumeria" << endl;
    cout << "8. Congelados" << endl;
    cout << "9. Mascotas" << endl<<endl;
    cout << "Ingrese una opcion: ";
    cin >> tipo;
    setTipoProducto(tipo);
    system("cls");

    int neuvoId = generarIDProducto(tipo);
    setIDProducto(neuvoId);
    cin.ignore();

    cout << "Nombre del producto: ";
    cin.getline(nombre,50 );
    setNombreProducto(nombre);

    cout << "Stock: ";
    cin >> stock;
    setStock(stock);

    /*cout << "Costo: ";
    cin >> costo;
    setCosto(costo);*/

    setEstadoProducto(true);
}

void Producto::mostrar() {
    cout << "ID: " << getIDProducto() << endl;
    cout << "Nombre: " << getNombreProducto() << endl;
    cout << "Tipo: " << getTipoProducto() << endl;
    cout << "Stock: " << getStock() << endl;
    //cout << "Costo: $" << getCosto() << endl;
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

int Producto::generarIDProducto(int tipo) {
    FILE* p = fopen("producto.dat", "rb");
    if (p == nullptr) return tipo * 100 + 1;

    Producto prod;
    int ultimoID = tipo * 100;

    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getIDProducto() / 100 == tipo) {
            if (prod.getIDProducto() > ultimoID) {
                ultimoID = prod.getIDProducto();
            }
        }
    }

    fclose(p);
    return ultimoID + 1;
}

void Producto::listarProdcutos(){

    Producto prod;
    int pos = 0;

    cout<<"--- LISTADO DE PRODUCTOS ---" << endl<<endl;

    while (prod.leerDisco(pos)) {

            prod.mostrar();
    cout << "-----------------------------" << endl;

        pos++;
    }
}

bool Producto::guardarEnDisco() {
    FILE* p = fopen("producto.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}







