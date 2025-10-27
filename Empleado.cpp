#include <iostream>
#include "Empleado.h"
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"
using namespace std;

Empleado::Empleado() {
    strcpy(dni, "");

}

const char* Empleado::getDNI() {
     return dni;
     }

Fecha Empleado::getFechaNacimiento() {
    return fechaNacimiento;
    }

Fecha Empleado::getFechaIngreso() {
    return fechaIngreso;
     }

void Empleado::setDNI(const char* valor) {
    strncpy(dni, valor, sizeof(dni));
    dni[sizeof(dni) - 1] = '\0';
}

void Empleado::setFechaNacimiento(Fecha valor) {
    fechaIngreso = valor;
}

void Empleado::setFechaIngreso(Fecha valor) {
    fechaIngreso = valor;
}

void Empleado::cargar() {

    cout<<"Ingrese los Datos del Empleado"<<endl;
    cout<<"............................."<<endl;

    autoID();
    char tempDNI[10];
    cout << "DNI: ";
    cin >> tempDNI;
    setDNI(tempDNI);
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre, 50);
    setNombre(nombre);

    cout << "Apellido: ";
    cin.getline(apellido, 50);
    setApellido(apellido);

    cout << "Fecha de nacimiento:" << endl;
    fechaNacimiento.Cargar();

    cin.ignore();

    cout << "Telefono: ";
    cin.getline(telefono, 15);

    cout << "Email: ";
    cin.getline(email, 70);

    direccion.Cargar();

    cout<<"Fecha de Ingreso: ";

    fechaIngreso.Cargar();

    setEstado(true);



}

void Empleado::mostrar() {

    cout<<"Legajo: "<<getID() <<endl;
    cout<<"Nombre: " << getNombre() << endl;
    cout<<"Apellido: " << getApellido() << endl;
    cout<<"DNI: " << dni << endl;
    cout<<"Fecha de nacimiento: ";
    fechaNacimiento.Mostrar();
    cout<<"Telefono: " << getTelefono() << endl;
    cout<<"Email: " << getEmail() << endl;
    cout<<"Domicilio"<<endl;
    direccion.Mostrar();
    cout<<"Fecha de Ingreso: ";
    fechaIngreso.Mostrar();
    cout<<"Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
    }

bool Empleado::escribirDisco(int pos) {

    FILE* p = fopen("empleado.dat", "rb+");

    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Empleado), SEEK_SET);
    bool ok = fwrite(this, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

bool Empleado::leerDisco(int pos) {
    FILE* p = fopen("empleado.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Empleado), SEEK_SET);
    bool ok = fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;

}

bool Empleado::autoID() {
    FILE* punterF = fopen("empleado.dat", "rb");

    if (punterF == nullptr) {

      setID(2000);
        return true;
    }

    Empleado nuevo;
    int ultimoID ;

    while (fread(&nuevo, sizeof(Empleado), 1, punterF) == 1) {
        ultimoID = nuevo.getID();
    }

    fclose(punterF);

    setID(ultimoID + 1);
    return true;
}
