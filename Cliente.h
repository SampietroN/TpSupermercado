#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "ClasePersona.h"
#include "ClaseDireccion.h"
#include "ClaseFecha.h"

class Cliente : public Persona {
private:
    char dni[10];
    Fecha fechaNacimiento;
    Fecha registroMiembro;
    bool estadoMiembro;

public:
    Cliente();

    // Getters
    const char* getDNI();
    Fecha getFechaNacimiento();
    Fecha getFechaMiembro();
    bool getEstadoMiembro();

    // Setters
    void setDNI(const char* valor);
    void setFechaNacimiento(Fecha valor);
    void setFechaMiembro(Fecha valor);
    void setEstadoMiembro(bool valor);
    //metodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    bool autoID();

};




#endif // CLIENTE_H_INCLUDED
