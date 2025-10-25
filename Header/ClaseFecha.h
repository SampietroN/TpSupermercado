#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED
#include <string>
using namespace std;

class Fecha{
private:
    int dia, mes, anio;
    void agregarDia();
    void restarDia();
public:
    Fecha();
    Fecha(int, int, int);
    ~Fecha();

    ///getters
    int getDia();
    int getMes();
    int getAnio();

    ///setters

    void setDia(int);
    void setMes(int);
    void setAnio(int);

    ///extas
    string toString();
    stringToFecha(string);
    void Cargar();
    void Mostrar();


};
#endif // CLASEFECHA_H_INCLUDED
