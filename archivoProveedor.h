#ifndef ARCHIVOPROVEEDOR_H_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED

bool cargarRegistroProveedor();
void listarRegistrosProveedor();
int buscarEProveedorCuit(const char* Cuit);
bool altaBajaProveedor(int posicion);

#endif // ARCHIVOPROVEEDOR_H_INCLUDED
