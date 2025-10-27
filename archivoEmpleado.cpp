#include <iostream>
using namespace std;
#include "Empleado.h"
#include "archivoEmpleado.h"

bool cargarRegistroEmpleado() {


    Empleado nuevo;
    nuevo.cargar();

    FILE* f = fopen("empleado.dat", "ab");
    if (f == nullptr) {
        cout << "No Se Puede Abrir El Archivo" << endl;
        return false;
    }

    bool ok = fwrite(&nuevo, sizeof(Empleado), 1, f);

    fclose(f);

    if (ok) {
        cout << "empleado guardado correctamente." << endl;
    } else {
        cout << "Error al guardar el empleado." << endl;
    }

    return ok;
}

 void listarRegistrosEmpleado(){
    Empleado c;
    FILE* f = fopen("empleado.dat", "rb");
    if (f == nullptr) {
        cout <<"No Se Puede Abrir El Archivo"<< endl;
        return;
    }

    int pos = 1;
    cout << "=== LISTADO DE Empleado ===" << endl << endl;

    while (fread(&c, sizeof(Empleado), 1, f) == 1) {
        cout << "Registro #" << pos << endl;
        c.mostrar();
        cout << "--------------------------" << endl;
        pos++;
    }

    fclose(f);
}

int buscarEmpleadoporDNI(const char* DNI) {
    Empleado nuevo;
    int pos = 0;
    int posBuscada = -1;

    FILE* f = fopen("empleado.dat", "rb");
    if (f == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        return -1; //
    }

  while (fread(&nuevo, sizeof(Empleado), 1, f) == 1) {

    if (strcmp(nuevo.getDNI(), DNI) == 0) {
        posBuscada = pos;
        break;
    }
    pos++;
}

    fclose(f);
    return posBuscada;
}

bool altaBajaEmpleado(int posicion){

    bool result;
    bool opcion = false;
    Empleado nuevo;

    FILE* pFile = fopen("empleado.dat","rb+");
    if (pFile == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        exit(4004);
    }

    fseek(pFile, posicion * sizeof(Empleado), SEEK_SET);
    fread(&nuevo, sizeof(Empleado), 1, pFile);

    if (nuevo.getEstado()) {

        cout<<"El Empleado esta Activo"<<endl;
        cout<<"Desea cambiar su estado? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstado(false);
        cout << "Empleado dado de Baja." << endl;
        }
    } else {
        cout<<"El Empleado esta Inactivo"<<endl;
        cout<<"Desea cambiar su estado? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstado(true);
        cout << "Empleado dado de Alta" << endl;
        }
    }
    fseek(pFile, posicion * sizeof(Empleado), SEEK_SET);
    result = fwrite(&nuevo, sizeof(Empleado), 1, pFile);

    fclose(pFile);

    return result;
}
