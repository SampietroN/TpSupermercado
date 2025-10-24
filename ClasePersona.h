#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "ClaseFecha.h"
#include "ClaseDireccion.h"

class Persona {

protected:
    int ID;
    char nombre[50];
    char apellido[50];
    char telefono[15];
    char email[70];
    Direccion direccion;
    bool estado;

public:

    Persona();
    Persona(int, char*, char*, char*, char*, bool);
    ~Persona();

    //getters
    int getID();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getEmail();
    Direccion getDomicilio();
    bool getEstado();

    //setters
    void setID(int);
    void setNombre(const char*);
    void setApellido(const char*);
    void setTelefono(const char*);
    void setEmail(const char*);
    void setDomicilio(Direccion);
    void setEstado(bool);

    //datos
    void cargar();
    void mostrar();

};





#endif // PERSONA_H_INCLUDED
