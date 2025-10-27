#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"

class   Proveedor : public Persona {
private:
    char Cuit[10];

public:
    Proveedor();

    // Getters
    const char* getCuit();

    // Setters
    void setCuit(const char* valor);

    //metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    bool autoID();

};


#endif // PROVEEDOR_H_INCLUDED
