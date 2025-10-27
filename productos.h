#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Producto
{
public:
    Producto();

    // Setters
    void setIDProducto(int id);
    void setNombreProducto(const char* nombre);
    void setTipoProducto(int tipo);
    void setStock(int stock);
   // void setCosto(float costo);
    void setEstadoProducto(bool estado);

    // Getters
    int getIDProducto() const;
    const char* getNombreProducto() const;
    int getTipoProducto() const;
    int getStock() const;
   // float getCosto() const;
    bool getEstadoProducto() const;
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    bool autoID();
    int generarIDProducto(int tipo);
    void listarProdcutos();
    bool guardarEnDisco() ;


    ~Producto();

private:
    int _IDProducto;
    char _nombreProducto[50];
    int _tipoProducto;
    int _stock;
  //  float _costo;
    bool _estadoProducto;

};


#endif // PRODUCTOS_H_INCLUDED
