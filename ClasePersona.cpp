#include <iostream>
#include <cstring>
#include "ClasePersona.h"
using namespace std;


Persona::Persona(){
    ID = 0;
    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(telefono, "");
    strcpy(email, "");
    estado = true;
    Direccion();
}

Persona::Persona(int IDInput, char NombreInput[], char ApellidoInput[], char TelefonoInput[], char EmailInput[], bool EstadoInput){
    ID = IDInput;
    strcpy(nombre, NombreInput);
    strcpy(apellido, ApellidoInput);
    strcpy(telefono, TelefonoInput);
    strcpy(email, EmailInput);
    estado = EstadoInput;
    Direccion(/*char CalleInput[], int NumeroInput, char LocalidadInput[], char ProvinciaInput[], char PisoInput[], char DepartamentoInput[], bool esDeptoInput*/);
}

Persona::~Persona(){

}

///GETTERS

int Persona::getID(){
    return ID;
}

const char* Persona::getNombre(){
    return nombre;
}

const char* Persona::getApellido(){
    return apellido;
}

const char* Persona::getTelefono(){
    return telefono;
}

const char* Persona::getEmail(){
    return email;
}

Direccion Persona::getDomicilio(){
    return direccion;
}

bool Persona::getEstado(){
    return estado;
}

///SETTERS

void Persona::setID(int IDInput){
    ID = IDInput;
}

void Persona::setNombre(const char* NombreInput){
    strcpy(nombre, NombreInput);
}

void Persona::setApellido(const char* ApellidoInput){
    strcpy(apellido, ApellidoInput);
}

void Persona::setTelefono(const char* TelefonoInput){
    strcpy(telefono, TelefonoInput);
}

void Persona::setEmail(const char* EmailInput){
    strcpy(email, EmailInput);
}

void Persona::setDomicilio(Direccion DireccionInput){
    direccion = DireccionInput;
}

void Persona::setEstado(bool EstadoInput){
    estado = EstadoInput;
}

///Datos

void Persona::cargar() {
    cout << "Nombre: ";
    cin.getline(nombre, 50);

    cout << "Apellido: ";
    cin.getline(apellido, 50);

    cout << "Telefono: ";
    cin.getline(telefono, 15);

    cout << "Email: ";
    cin.getline(email, 70);

    cout<<endl;
    direccion.Cargar();

    estado = true;
    cout<<endl;
}

void Persona::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
    direccion.Mostrar();

    cout << "Estado: ";
    if(estado == true){
        cout<<"Activo"<<endl;
    }
    else{
        cout<<"Inactivo"<<endl;
    }
}



