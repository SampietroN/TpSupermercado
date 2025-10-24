#ifndef ARCHIVOEMPLEADO_H_INCLUDED
#define ARCHIVOEMPLEADO_H_INCLUDED

bool cargarRegistroEmpleado();
void listarRegistrosEmpleado();
int buscarEmpleadoporDNI(const char* DNI);
bool altaBajaEmpleado(int posicion);

#endif // ARCHIVOEMPLEADO_H_INCLUDED
