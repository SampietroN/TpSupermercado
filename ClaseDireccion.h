#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED
#include <cstring>


class Direccion{
    private:
        char calle[50], localidad[50], provincia[50];
        int numero;
        char departamento[4], piso[3];
        bool esDepto;

    public:
        Direccion();
        Direccion(char*, int, char*, char*, char*, char*, bool);
        ~Direccion();

        ///setters
        void setCalle(const char*);
        void setNumero(int);
        void setLocalidad(const char*);
        void setPiso (const char*);
        void setDepto(const char*);
        void setEsDepto(bool);
        void setProvincia(const char*);

        ///getters
        const char* getCalle();
        int  getNumero();
        const char* getLocalidad();
        const char* getPiso();
        const char* getDepto();
        bool getEsDepto();
        const char* getProvincia();

        ///modos
        void Cargar();
        void Mostrar();
        void cargaDepto();

};



#endif // DOMICILIO_H_INCLUDED
