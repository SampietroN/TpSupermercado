#include <iostream>
#include <cstring>
#include "ClaseDireccion.h"

using namespace std;

Direccion::Direccion(){
    calle[0] = '\0';
    localidad[0] = '\0';
    provincia[0] = '\0';
    numero = 0;
    piso[0] = '\0';
    departamento[0] = '\0';
    esDepto = false;
}

Direccion::Direccion(char CalleInput[], int NumeroInput, char LocalidadInput[], char ProvinciaInput[], char PisoInput[], char DepartamentoInput[], bool esDeptoInput){
    strcpy(calle,CalleInput);
    strcpy(localidad,LocalidadInput);
    strcpy(provincia,ProvinciaInput);
    numero = NumeroInput;
    strcpy(piso,PisoInput);
    strcpy(departamento,DepartamentoInput);
    esDepto = esDeptoInput;
}

Direccion::~Direccion(){
  //  cout<<"Clase Direccion Finalizada"<<endl;
}

///SETTERS

void Direccion::setCalle(const char calleInput[]){
    strncpy(calle, calleInput, sizeof(calle));
    calle[sizeof(calle) - 1] = '\0';
}

void Direccion::setNumero(int num){
  while (num <= 0) {
        cout << "Numero no valido. Ingrese nuevamente: ";
        cin >> num;
    }
    numero = num;
}

void Direccion::setLocalidad(const char localidadInput[]){
    strncpy(localidad, localidadInput, sizeof(localidad));
    localidad[sizeof(localidad) - 1] = '\0';
}

void Direccion::setPiso (const char pisoInput[]){
    strncpy(piso, pisoInput, sizeof(piso));
    piso[sizeof(piso)-1] = '\0';

}

void Direccion::setDepto(const char departamentoInput[]){
    strncpy(departamento, departamentoInput, sizeof(departamento));
    departamento[sizeof(departamento) - 1] = '\0';
}

void Direccion::setEsDepto(bool esDeptoInput){
    esDepto = esDeptoInput;
}

void Direccion::setProvincia(const char provinciaInput[]){
    strcpy(provincia,provinciaInput);
    provincia[sizeof(provincia) - 1] = '\0';
}

///GETTERS

const char* Direccion::getCalle(){
    return calle;
}

int Direccion::getNumero(){
    return numero;
}

const char* Direccion::getLocalidad(){
    return localidad;
}

const char* Direccion::getPiso(){
    return piso;
}

const char* Direccion::getDepto(){
    return departamento;
}

bool Direccion::getEsDepto(){
    return esDepto;
}

const char* Direccion::getProvincia(){
    return provincia;
}

void Direccion::cargaDepto() {
    char departamentoInput[4], pisoInput[3];

    cout << "Piso: ";
    cin >> pisoInput;
    setPiso(pisoInput);

    cout << "Departamento: ";
    cin >> departamentoInput;
    setDepto(departamentoInput);
}

void Direccion::Cargar() {
    char calleInput[50], localidadInput[50], provinciaInput[50];
    int numeroInput;
    int valor;

    cout<<"Domicilio "<<endl;

    cout << "Calle: ";
    cin.getline(calleInput, 50);
    setCalle(calleInput);

    cout << "Numero: ";
    cin >> numeroInput;
    setNumero(numeroInput);

    cout << "Es edificio (1 = si, 0 = no): ";
    cin >> valor;
    if(valor != 1){
        valor = 0;
    }

    setEsDepto(valor);

    if (valor) {
        cargaDepto();
    }
    else{
        setPiso("No");
        setDepto("No");
    }
    cin.ignore();

    cout << "Localidad: ";
    cin.getline(localidadInput, 50);
    setLocalidad(localidadInput);

    cout << "Provincia: ";
    cin.getline(provinciaInput, 50);
    setProvincia(provinciaInput);

}

void Direccion::Mostrar() {
    cout << "Calle: " << getCalle() << endl;
    cout << "Numero: " << getNumero() << endl;

    if (getEsDepto()==true) {
        cout << "Piso: " << getPiso()<<endl;
        cout << "Departamento: " << getDepto() << endl;
    }

    cout << "Localidad: " << getLocalidad() << endl;
    cout<< "Provincia: "<< getProvincia()<<endl;

}


