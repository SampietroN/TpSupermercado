#include <iostream>
#include "archivoProveedor.h"
#include "Proveedor.h"

using namespace std;

bool cargarRegistroProveedor() {


    Proveedor nuevo;
    nuevo.cargar();

    FILE* f = fopen("proveedor.dat", "ab");
    if (f == nullptr) {
        cout << "No Se Puede Abrir El Archivo" << endl;
        return false;
    }

    bool ok = fwrite(&nuevo, sizeof(Proveedor), 1, f);

    fclose(f);

    if (ok) {
        cout << "Proveedor guardado correctamente." << endl;
    } else {
        cout << "Error al guardar el Proveedor." << endl;
    }

    return ok;
}

void listarRegistrosProveedor(){
    Proveedor c;
    FILE* f = fopen("proveedor.dat", "rb");
    if (f == nullptr) {
        cout <<"No Se Puede Abrir El Archivo"<< endl;
        return;
    }

    int pos = 1;
    cout << "=== LISTADO DE Proveedor ===" << endl << endl;

    while (fread(&c, sizeof(Proveedor), 1, f) == 1) {
        cout << "Registro #" << pos << endl;
        c.mostrar();
        cout << "--------------------------" << endl;
        pos++;
    }

    fclose(f);
}

int buscarEProveedorCuit(const char* Cuit) {
    Proveedor nuevo;
    int pos = 0;
    int posBuscada = -1;

    FILE* f = fopen("proveedor.dat", "rb");
    if (f == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        return -1; //
    }

  while (fread(&nuevo, sizeof(Proveedor), 1, f) == 1) {

    if (strcmp(nuevo.getCuit(), Cuit) == 0) {
        posBuscada = pos;
        break;
    }
    pos++;
}

    fclose(f);
    return posBuscada;
}

bool altaBajaProveedor(int posicion){

    bool result;
    bool opcion = false;
    Proveedor nuevo;

    FILE* pFile = fopen("proveedor.dat","rb+");
    if (pFile == nullptr) {
        cout << "No se puede abrir el archivo." << endl;
        exit(4004);
    }

    fseek(pFile, posicion * sizeof(Proveedor), SEEK_SET);
    fread(&nuevo, sizeof(Proveedor), 1, pFile);

    if (nuevo.getEstado()) {

        cout<<"El Proveedor "<<nuevo.getNombre()<<" esta Activo"<<endl;
        cout<<"Desea darlo de Baja? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstado(false);
        cout << "Proveedor dado de Baja." << endl;
        }
    } else {
        cout<<"El Proveedor "<<nuevo.getNombre()<<" esta Inactivo"<<endl;
        cout<<"Desea darle el Alta? (si=1 no =0)"<<endl;
        cin>>opcion;
        if (opcion){
        nuevo.setEstado(true);
        cout << "Proveedor dado de Alta" << endl;
        }
    }
    fseek(pFile, posicion * sizeof(Proveedor), SEEK_SET);
    result = fwrite(&nuevo, sizeof(Proveedor), 1, pFile);

    fclose(pFile);

    return result;
}

