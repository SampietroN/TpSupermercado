#include <iostream>
#include "ClaseFecha.h"
#include <ctime>
using namespace std;

Fecha::Fecha(){
    /*
    time_t MarcaDeTiempo = time(&MarcaDeTiempo);
    struct tm FechaActual = *localtime(&MarcaDeTiempo);
    dia = FechaActual.tm_mday;
    mes = FechaActual.tm_mon;
    anio = FechaActual.tm_year;
    */
    dia = 1;
    mes = 1;
    anio = 2025;

}

Fecha::Fecha(int diaInput, int mesInput, int anioInput){
    if(anioInput>2000){     //revision año
        if(mesInput<13 && mesInput>0){    //revision de mes
            if(diaInput>0 && diaInput<32){    //revision de dias
                if(diaInput==31){    //meses de 30 dias
                    if(mesInput==4 || mesInput==6 || mesInput==9 || mesInput==11){
                        dia = 1;
                        mes = 1;
                        anio = 2025;
                    }
                    else{
                        dia = diaInput;
                        mes = mesInput;
                        anio = anioInput;
                    }
                }
                else if(diaInput >28 && mesInput==2){ //febrero y biciestos
                    if(diaInput == 29 && anioInput%4==0){
                        dia = diaInput;
                        mes = mesInput;
                        anio = anioInput;
                    }
                    else{
                        dia = 1;
                        mes = 1;
                        anio = 2025;
                    }
                }
                else{
                    dia = diaInput;
                    mes = mesInput;
                    anio = anioInput;
                }
            }
            else{
                dia = 1;
                mes = 1;
                anio = 2025;
            }
        }
        else{
            dia = 1;
            mes = 1;
            anio = 2025;
        }
    }
    else{
        dia = 1;
        mes = 1;
        anio = 2025;
    }
}

Fecha::~Fecha(){
//cout<<"fin de la fecha"<<endl;
}

///GETTERS

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

///SETTERS

void Fecha::setDia(int diaInput){
    dia = diaInput;
}

void Fecha::setMes(int mesInput){
    mes = mesInput;
}

void Fecha::setAnio(int anioInput){
    anio = anioInput;
}

///EXTRAS

string Fecha::toString(){
    string fechaString;
    if(dia<=9){
        if(mes<=9){
            fechaString = "0" + to_string(dia) + "/" + "0" + to_string(mes) + "/" + to_string(anio);
        }
        else{
            fechaString = "0" + to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
        }
    }
    else if(mes<=9){
        fechaString = to_string(dia) + "/" + "0" + to_string(mes) + "/" + to_string(anio);
    }
    else{
    fechaString = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    }
    return fechaString;

}

Fecha::stringToFecha(string fechaString){

    int Tam = fechaString.size();

    char* fechaChar = new char[Tam];
    fechaString.copy(fechaChar, Tam);

    dia = (((int)fechaChar[0]-48)*10)+((int)fechaChar[1]-48);
    mes = (((int)fechaChar[3]-48)*10)+((int)fechaChar[4]-48);
    anio = (((int)fechaChar[6]-48)*1000)+(((int)fechaChar[7]-48)*100)+(((int)fechaChar[8]-48)*10)+((int)fechaChar[9]-48);

    delete[] fechaChar;
}

void Fecha::Cargar(){

    int diaInput, mesInput, anioInput;

    cout << "Dia: ";
    cin >> diaInput;
    cout << "Mes: ";
    cin >> mesInput;
    cout << "Anio: ";
    cin >> anioInput;

    if(anioInput>2000){     //revision anio
        if(mesInput<13 && mesInput>0){    //revision de mes
            if(diaInput>0 && diaInput<32){    //revision de dias
                if(diaInput==31){    //meses de 30 dias
                    if(mesInput==4 || mesInput==6 || mesInput==9 || mesInput==11){
                        dia = 1;
                        mes = 1;
                        anio = 2025;
                    }
                    else{
                        dia = diaInput;
                        mes = mesInput;
                        anio = anioInput;
                    }
                }
                else if(diaInput >28 && mesInput==2){ //febrero y biciestos
                    if(diaInput == 29 && anioInput%4==0){
                        dia = diaInput;
                        mes = mesInput;
                        anio = anioInput;
                    }
                    else{
                        dia = 1;
                        mes = 1;
                        anio = 2025;
                    }
                }
                else{
                    dia = diaInput;
                    mes = mesInput;
                    anio = anioInput;
                }
            }
            else{
                dia = 1;
                mes = 1;
                anio = 2025;
            }
        }
        else{
            dia = 1;
            mes = 1;
            anio = 2025;
        }
    }
    else{
        dia = 1;
        mes = 1;
        anio = 2025;
    }

}

void Fecha::Mostrar(){
    cout<<toString()<<endl;
}
