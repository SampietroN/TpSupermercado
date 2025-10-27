#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "cliente.h"
#include "ClaseFecha.h"
#include <cstring>

bool cargarRegistroCliente();
void listarRegistrosCliente();
int buscarRegistroporDNI(const char* DNI);
bool altaBajaMiembro(int posicion);

#endif // ARCHIVOCLIENTE_H_INCLUDED
