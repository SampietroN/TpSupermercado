#include <iostream>
using namespace std;
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"
#include "Proveedor.h"
using namespace std;

Proveedor::Proveedor() {
    strcpy(Cuit, "");
}

const char* Proveedor::getCuit() {
     return Cuit;
     }

void Proveedor::setCuit(const char* valor) {
    strncpy(Cuit, valor, sizeof(Cuit));
    Cuit[sizeof(Cuit) - 1] = '\0';
}

void Proveedor::cargar() {

    cout<<"Ingrese los Datos del Proveedor"<<endl;
    cout<<"............................."<<endl;

    autoID();
    char tempCuit[10];
    cout << "CUIT: ";
    cin >> tempCuit;
    setCuit(tempCuit);
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre, 50);
    setNombre(nombre);

    cout << "Razon Social: ";
    cin.getline(apellido, 50);
    setApellido(apellido);

    cout << "Telefono: ";
    cin.getline(telefono, 15);
    setTelefono(telefono);

    cout << "Email: ";
    cin.getline(email, 70);
    setEmail(email);

    direccion.Cargar();

    setEstado(true);



}

void Proveedor::mostrar() {

    cout<<"ID Proveedor: "<<getID() <<endl;
    cout<<"Nombre: " << getNombre() << endl;
    cout<<"Razon Social: " << getApellido() << endl;
    cout<<"Cuit: " << Cuit << endl;
    cout<<"Telefono: " << getTelefono() << endl;
    cout<<"Email: " << getEmail() << endl;
    cout<<"Domicilio"<<endl;
    direccion.Mostrar();
    cout<<"Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
    }

bool Proveedor::escribirDisco(int pos) {

    FILE* p = fopen("proveedor.dat", "rb+");

    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Proveedor), SEEK_SET);
    bool ok = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return ok;
}

bool Proveedor::leerDisco(int pos) {
    FILE* p = fopen("proveedor.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Proveedor), SEEK_SET);
    bool ok = fread(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return ok;

}

bool Proveedor::autoID() {
    FILE* punterF = fopen("proveedor.dat", "rb");

    if (punterF == nullptr) {

      setID(3000);
        return true;
    }

    Proveedor nuevo;
    int ultimoID ;

    while (fread(&nuevo, sizeof(Proveedor), 1, punterF) == 1) {
        ultimoID = nuevo.getID();
    }

    fclose(punterF);

    setID(ultimoID + 1);
    return true;
}
