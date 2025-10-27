#include "cliente.h"
#include <iostream>
#include <cstdio>
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"
using namespace std;

bool cargarRegistroCliente() {

    Cliente nuevo;
    nuevo.cargar();

    FILE* f = fopen("cliente.dat", "ab");
    if (f == nullptr) {
        cout << "No Se Puede Abrir El Archivo" << endl;
        return false;
    }

    bool ok = fwrite(&nuevo, sizeof(Cliente), 1, f);

    fclose(f);

    if (ok) {
        cout << "Cliente guardado correctamente." << endl;
    } else {
        cout << "Error al guardar el cliente." << endl;
    }

    return ok;
}

void listarRegistrosCliente() {
    Cliente c;
    FILE* f = fopen("cliente.dat", "rb");
    if (f == nullptr) {
        cout <<"No Se Puede Abrir El Archivo"<< endl;
        return;
    }

    int pos = 1;
    cout << "=== LISTADO DE CLIENTES ===" << endl << endl;

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        cout << "Registro #" << pos << endl;
        c.mostrar();
        cout << "--------------------------" << endl;
        pos++;
    }

    fclose(f);
}

int buscarRegistroporDNI(const char* DNI) {
    Cliente c;
    int pos = 0;
    int posBuscada = -1;

    FILE* f = fopen("cliente.dat", "rb");
    if (f == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        return -1; //
    }

  while (fread(&c, sizeof(Cliente), 1, f) == 1) {

    if (strcmp(c.getDNI(), DNI) == 0) {
        posBuscada = pos;
        break;
    }
    pos++;
}

    fclose(f);
    return posBuscada;
}

bool altaBajaMiembro(int posicion){

    bool result;
    bool opcion = false;
    Cliente nuevo;

    FILE* pFile = fopen("cliente.dat","rb+");
    if (pFile == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        exit(4004);
    }

    fseek(pFile, posicion * sizeof(Cliente), SEEK_SET);
    fread(&nuevo, sizeof(Cliente), 1, pFile);

    if (nuevo.getEstadoMiembro()) {

        cout<<"El Cliente Miembro esta Activo"<<endl;
        cout<<"Desea dar de baja al miembro? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstadoMiembro(false);
        cout << "Miembro dado de baja." << endl;
        }
    } else {
        cout<<"El Cliente Miembro esta Inactivo"<<endl;
        cout<<"Desea dar de alta al miembro? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstadoMiembro(true);
        cout << "Miembro Activado." << endl;
        cout<<"....................."<<endl;
        cout<<"Ingrese Fecha"<<endl;
        Fecha miembroNuevo;
        miembroNuevo.Cargar();
        nuevo.setFechaMiembro(miembroNuevo);

        }
    }
    fseek(pFile, posicion * sizeof(Cliente), SEEK_SET);
    result = fwrite(&nuevo, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return result;
}

