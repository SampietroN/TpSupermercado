#include <iostream>
#include "cliente.h"
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"
#include <cstring>

using namespace std;

Cliente::Cliente() {
    strcpy(dni, "");
    estadoMiembro = true;
}

const char* Cliente::getDNI() {
     return dni;
     }

Fecha Cliente::getFechaNacimiento() {
    return fechaNacimiento;
    }

Fecha Cliente::getFechaMiembro() {
    return registroMiembro;
     }

bool Cliente::getEstadoMiembro() {
    return estadoMiembro;
    }

void Cliente::setDNI(const char* valor) {
    strncpy(dni, valor, sizeof(dni));
    dni[sizeof(dni) - 1] = '\0';
}

void Cliente::setFechaNacimiento(Fecha valor) {
    fechaNacimiento = valor;
}

void Cliente::setFechaMiembro(Fecha valor) {
    registroMiembro = valor;
}

void Cliente::setEstadoMiembro(bool valor) {
    estadoMiembro = valor;
}

void Cliente::cargar() {

    cout<<"Ingrese los Datos del Cliente"<<endl;
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

    setEstado(true);

    //Persona::cargar();

    cout << "Estado miembro? (1 = activo, 0 = inactivo): ";
    cin >> estadoMiembro;

    cin.ignore();

    while (estadoMiembro != 0 && estadoMiembro != 1) {
    cout << "Valor inválido. Ingrese 1 (activo) o 0 (inactivo): ";
    cin >> estadoMiembro;
}


    if (estadoMiembro){
    cout << "Ingrese Fecha de registro Miembro:" << endl;
    registroMiembro.Cargar();

    }else{
   // registroMiembro.setFechaDefault();

    }
}

void Cliente::mostrar() {

    cout<<"ID Cliente: "<<getID() <<endl;
    cout<<"Nombre: " << getNombre() << endl;
    cout<<"Apellido: " << getApellido() << endl;
    cout<<"DNI: " << dni << endl;
    cout<<"Fecha de nacimiento: ";
    fechaNacimiento.Mostrar();
    cout<<"Telefono: " << getTelefono() << endl;
    cout<<"Email: " << getEmail() << endl;
    cout<<"Domicilio"<<endl;
    direccion.Mostrar();
    cout<<"Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
    cout<<"Estado de membresia: " << (estadoMiembro ? "Activo" : "Inactivo") << endl;
    if (estadoMiembro){
    cout << "Registro de membresia: ";
    registroMiembro.Mostrar();
    }
}

bool Cliente::escribirDisco(int pos) {

    FILE* p = fopen("cliente.dat", "rb+");

    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool Cliente::leerDisco(int pos) {
    FILE* p = fopen("cliente.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fread(this, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;

}

bool Cliente::autoID() {
    FILE* punterF = fopen("cliente.dat", "rb");

    if (punterF == nullptr) {

      setID(1000);
        return true;
    }

    Cliente nuevo;
    int ultimoID ;

    while (fread(&nuevo, sizeof(Cliente), 1, punterF) == 1) {
        ultimoID = nuevo.getID();
    }

    fclose(punterF);

    setID(ultimoID + 1);
    return true;
}





