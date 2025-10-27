#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED


bool cargarFacturas();
bool existeProducto(int idBuscado);
bool existeProveedor(int idBuscado);
bool existePoductoDelProveedor(int idProd, int idProv);
float PrecioProductoXProveedor(int idProd, int idProv) ;
void cargarFacturaCompra();
void mostrarFacturasCompra();


#endif // FUNCIONESGLOBALES_H_INCLUDED
