#include <iostream>
#include "menues.h"
#include "Cliente.h"
#include "archivoCliente.h"
#include "Empleado.h"
#include "archivoEmpleado.h"
#include "Proveedor.h"
#include "archivoProveedor.h"
using namespace std;



void MenuPricipal(){



int opcion;

    do
    {
        system("cls");
    cout<<"=====-----------======"<<endl;
	cout<<"=== Menu Principal ==="<<endl;
	cout<<"=== Super  Mercado ==="<<endl;
	cout<<"=====-----------======"<<endl;

	cout<<"1. ABML Clientes "<<endl;
	cout<<"2. ABML Empleados "<<endl;
	cout<<"3. ABML Productos "<<endl;
	cout<<"4. ABML Proveedor "<<endl;
	cout<<"5. ABML FACturas "<<endl;
    cout<<"6. Menu Listados"<<endl;
	cout<<"7. Menu Reportes"<<endl;
    cout<<"0. Fin del Programa"<<endl<<endl;

    cout<<"Ingrese una Opcion: ";
    cin>>opcion;


    switch (opcion)
    {
        case 1:ABMLCliente();
            break;
        case 2:ABMLEmpleado();
            break;
        case 3: ABMLProd();
            break;
        case 4:ABMLProveedor();
            break;
        case 5:ABMLFacturas();
            break;
        case 6:
             break;
        case 7:
            break;
        case 0:
            cout<<"--------"<<endl;
            cout<<"Saliendo"<<endl;
            cout<<"--------"<<endl;


            break;

        default: cout<<"Opcion incorrecta intente nuevamente."<<endl;
                system("pause");
            break;
    }

} while (opcion != 0);


}

void ABMLCliente(){
int opc;
Cliente nuevo;
    do
    {
        system("cls");
        cout << "****** ABML CLIENTES ******" << endl<<endl;

        cout << "1. Alta Cliente "<< endl;
        cout << "2. Alta/Baja Cliente Miembro" << endl;
        cout << "3. Listado de Clientes " << endl;
        cout << "0. Volver Al Menu Anterior" << endl;
        cout << endl;
        cout << "Seleccione una Opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:cargarRegistroCliente();
                    break;

            case 2:
                    cout<<"Alta o baja del cliente"<<endl;
                    cout<<endl;
                    char DNI[10];

                    cout<<"Ingrese el DNI del Cliente: ";
                    cin>>DNI;
                    cout<<"............."<<endl;

                    altaBajaMiembro(buscarRegistroporDNI(DNI));

                    break;
            case 3:listarRegistrosCliente();
                    break;

            case 0:
                    cout<<"=========================="<<endl;
                    cout<<"==Volviendo al Principal=="<<endl;
                    cout<<"=========================="<<endl;
                    break;
            default: cout<<"La Seleccion No es Correcta"<<endl;

        }
        system("pause");
        } while (opc !=0);

}

void ABMLEmpleado(){
int opc;
    do
    {
        system("cls");
        cout << "****** ABML Empleado ******" << endl<<endl;

        cout << "1. Alta Empleado " << endl;
        cout << "2. Baja/Alta Empleado" << endl;
        cout << "3. Listado de Empleado " << endl;
        cout << "0. Volver Al Menu Anterior" << endl;
        cout << endl;
        cout << "Seleccione una Opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarRegistroEmpleado();
                    break;
            case 2: cout<<"Alta o baja de Empleado"<<endl;
                    cout<<endl;
                    char DNI[10];

                    cout<<"Ingrese el DNI del Empleado: ";
                    cin>>DNI;
                    cout<<"............................"<<endl;
                    if (buscarEmpleadoporDNI(DNI)>= 0){
                    cout<<"Empleado Econtrado"<<endl;
                    altaBajaEmpleado(buscarEmpleadoporDNI(DNI));
                    }else {
                    cout<<"...................................."<<endl;
                    cout<<"No se Econtro el Registro Solicitado"<<endl;
                    cout<<"...................................."<<endl;
                    }

                    break;
            case 3:listarRegistrosEmpleado();

                    break;

            case 0:
                    cout<<"=========================="<<endl;
                    cout<<"==Volviendo al Principal=="<<endl;
                    cout<<"=========================="<<endl;
                    break;
            default: cout<<"La Seleccion No es Correcta"<<endl;

        }
        system("pause");
        } while (opc !=0);

}

void ABMLProveedor(){
int opc;
    do
    {
        system("cls");
        cout << "****** ABML Proveedor ******" << endl<<endl;

        cout << "1. Alta Proveedor " << endl;
        cout << "2. Baja/Alta Proveedor" << endl;
        cout << "3. Listado de Proveedor " << endl;
        cout << "0. Volver Al Menu Anterior" << endl;
        cout << endl;
        cout << "Seleccione una Opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarRegistroProveedor();
                    break;
            case 2: cout<<"Alta o baja de Proveedor"<<endl;
                    cout<<endl;
                    char cuit[10];

                    cout<<"Ingrese el Cuit del Proveedor: ";
                    cin>>cuit;
                    cout<<"............................"<<endl;
                    if (buscarEProveedorCuit(cuit)>= 0){
                    cout<<"Proveedor Econtrado"<<endl;
                    altaBajaProveedor(buscarEProveedorCuit(cuit));
                    }else {
                    cout<<"...................................."<<endl;
                    cout<<"No se Econtro el Registro Solicitado"<<endl;
                    cout<<"...................................."<<endl;
                    }
                    break;
            case 3:listarRegistrosProveedor();

                    break;

            case 0:
                    cout<<"=========================="<<endl;
                    cout<<"==Volviendo al Principal=="<<endl;
                    cout<<"=========================="<<endl;
                    break;
            default: cout<<"La Seleccion No es Correcta"<<endl;

        }
        system("pause");
        } while (opc !=0);

}

void ABMLProd(){

int opc;
    do
    {
        system("cls");
        cout << "****** ABML Producto ******" << endl<<endl;

        cout << "1. Alta Producto " << endl;
        cout << "2. Baja Producto" << endl;
        cout << "3. Modificar Stock "<<endl;
        cout << "4. Listado de Producto " << endl;
        cout << "0. Volver Al Menu Anterior" << endl;
        cout << endl;
        cout << "Seleccione una Opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: //if() cout<<"Registro Agregado "<<endl;
                    //else cout<<"No se Pudo Agreagar el Registro" <<endl;
                    break;
            case 2: //if() cout<<"Registro Eliminado "<<endl;
                    //else cout<<"No se Puedo Eliminar el Registro"<<endl;
                    break;
            case 3: //if() cout<<"Stock Modificado"<<endl;
                    //else cout<<"No se Puedo Eliminar el Registro"<<endl;
                    break;
            case 4:

                    break;

            case 0:
                    cout<<"=========================="<<endl;
                    cout<<"==Volviendo al Principal=="<<endl;
                    cout<<"=========================="<<endl;
                    break;
            default: cout<<"La Seleccion No es Correcta"<<endl;

        }
        system("pause");
        } while (opc !=0);

}

void ABMLFacturas(){
int opc;
    do
    {
        system("cls");
        cout << "****** Facturacion ******" << endl<<endl;

        cout << "1. Alta Factura"<< endl;
        cout << "2. Baja Factura" << endl;
        cout << "3. Listado de Faturas " << endl;
        cout << "0. Volver Al Menu Anterior" << endl;
        cout << endl;
        cout << "Seleccione una Opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                int opcion;
               do
               {
                cout<<"Factura Venta o Compra" <<endl;
                cout<<"Venta (1)"<<endl;
                cout<<"Compra (2)"<<endl;
                cout<<"Ingrese una opcion: ";
                cin>>opcion;

                 if(opcion == 1){

                    cout<<"Factura Cargada "<<endl;
                 }
                 if(opcion == 2){

                    cout<<"Factura Cargada "<<endl;
                 }
                 if (opcion <1 || opcion >2){

                    cout<<"Ingrese una Opcion Valida"<<endl;
                 }
                 } while (opcion <1 || opcion >2);

                    break;
            case 2: //if() cout<<"Registro Eliminado "<<endl;
                    //else cout<<"No se Puedo Eliminar el Registro"<<endl;
                    break;
            case 3:

                    break;

            case 0:
                    cout<<"=========================="<<endl;
                    cout<<"==Volviendo al Principal=="<<endl;
                    cout<<"=========================="<<endl;
                    break;
            default: cout<<"La Seleccion No es Correcta"<<endl;

        }
        system("pause");
        } while (opc !=0);

}

void MenuListadosClientes(){

    int opc;
        do
        {
            system("cls");
            cout << "<<<<<   Reportes Clientes   >>>>>" << endl<<endl;

            cout << "1. Clientes Activos" << endl;
            cout << "2. Clientes Inactivos" << endl;
            cout << "3. Clientes Miembros " << endl;
            cout << "4. Clientes con mas de 10 Compras en el Anio " << endl;
            cout << "5. Clientes con Compras Superiores a $ 500.000 " << endl;
            cout << "0. Volver Al Menu Anterior" << endl;
            cout << endl;
            cout << "Seleccione una Opcion: ";
            cin>>opc;

            system("cls");

            switch(opc){

                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;

                case 0:
                        cout<<"=========================="<<endl;
                        cout<<"==Volviendo al Principal=="<<endl;
                        cout<<"=========================="<<endl;
                    break;
                default: cout<<"La Seleccion No es Correcta"<<endl;

            }
            system("pause");
            } while (opc !=0);

}

void MenuListadosEmpleados(){

    int opc;
        do
        {
            system("cls");
            cout << "<<<<<   Reportes Empleados   >>>>>" << endl<<endl;

            cout << "1. Empleados Activos" << endl;
            cout << "2. Empleados Inactivos" << endl;
            cout << "3. Empleado Con Mas Horas Trabajadas en el Anio" << endl;
            cout << "4. Empleado Con Mas Facturas Relizadas" << endl;
            cout << "5. Lista de 10 Empleados con Menos Horas Trabajadas en el Anio" << endl;
            cout << "0. Volver Al Menu Anterior" << endl;
            cout << endl;
            cout << "Seleccione una Opcion: ";
            cin>>opc;

            system("cls");

            switch(opc){

                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;

                case 0:
                        cout<<"=========================="<<endl;
                        cout<<"==Volviendo al Principal=="<<endl;
                        cout<<"=========================="<<endl;
                    break;
                default: cout<<"La Seleccion No es Correcta"<<endl;

            }
            system("pause");
            } while (opc !=0);

}

void MenuListadosProovedores(){

    int opc;
        do
        {
            system("cls");
            cout << "<<<<<   Reportes Proveedores   >>>>>" << endl<<endl;

            cout << "1. Proveedor Activos" << endl;
            cout << "2. Proveedor Inactivos" << endl;
            cout << "3. Proveedores por Tipo de Producto " << endl;
            cout << "4. Proveedor con mas Productos Comprados " << endl;
            cout << "5. Proveedor con Mayor Facturacion   " << endl;
            cout << "0. Volver Al Menu Anterior" << endl;
            cout << endl;
            cout << "Seleccione una Opcion: ";
            cin>>opc;

            system("cls");

            switch(opc){

                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    int tipoproducto;

                    do {
                        cout << "Ingrese por el Tipo de Producto que desea buscar" << endl << endl;
                        cout << " 1 - Almacen" << endl;
                        cout << " 2 - Bebidas" << endl;
                        cout << " 3 - Carniceria" << endl;
                        cout << " 4 - Congelados" << endl;
                        cout << " 5 - Fiambreria" << endl;
                        cout << " 6 - Higiene Personal" << endl;
                        cout << " 7 - Lacteos" << endl;
                        cout << " 8 - Limpieza" << endl;
                        cout << " 9 - Mascotas" << endl;
                        cout << "10 - Pescaderia" << endl;
                        cout << "11 - Verduleria" << endl << endl;
                        cout << "Ingrese una Opcion: ";
                        cin >> tipoproducto;

                        if (tipoproducto < 1 || tipoproducto > 11) {
                            cout << "Opcion invalida. Intente Nuevamente." << endl << endl;
                        }

                    } while (tipoproducto < 1 || tipoproducto > 11);


                    break;
                case 4:
                    break;
                case 5:
                    break;

                case 0:
                        cout<<"=========================="<<endl;
                        cout<<"==Volviendo al Principal=="<<endl;
                        cout<<"=========================="<<endl;
                    break;
                default: cout<<"La Seleccion No es Correcta"<<endl;

            }
            system("pause");
            } while (opc !=0);

}

void MenuListadosProductos(){

    int opc;
        do
        {
            system("cls");
            cout << "<<<<<   Reportes Prodcutos   >>>>>" << endl<<endl;

            cout << "1. Prodcutos Activos" << endl;
            cout << "2. Productos Inactivos" << endl;
            cout << "3. Productos Con Mayor Ganancia" << endl;
            cout << "4. Lista de 5 Productos Menos Vendidos" << endl;
            cout << "5. Lista de 5 Prodcutos Mas Vendidos" << endl;
            cout << "0. Volver Al Menu Anterior" << endl;
            cout << endl;
            cout << "Seleccione una Opcion: ";
            cin>>opc;

            system("cls");

            switch(opc){

                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;

                case 0:
                        cout<<"=========================="<<endl;
                        cout<<"==Volviendo al Principal=="<<endl;
                        cout<<"=========================="<<endl;
                    break;
                default: cout<<"La Seleccion No es Correcta"<<endl;

            }
            system("pause");
            } while (opc !=0);

}

void Listados(){

int opcion;

    do
    {
        system("cls");

	cout<<"=== Menu Informes ==="<<endl;
	cout<<"=====-----------======"<<endl;

	cout<<"1. Clientes "<<endl;
	cout<<"2. Empleados "<<endl;
	cout<<"3. Productos "<<endl;
	cout<<"4. Proveedor "<<endl;
	cout<<"5. Facturas "<<endl;
    cout<<"0. Salir"<<endl<<endl;

    cout<<"Ingrese una Opcion: ";
    cin>>opcion;


    switch (opcion)
    {
        case 1:MenuListadosClientes();
            break;
        case 2:MenuListadosEmpleados();
            break;
        case 3: MenuListadosProductos();
            break;
        case 4:MenuListadosProovedores();
            break;
        case 5:
            break;
        case 0:
            cout<<"--------"<<endl;
            cout<<"Saliendo"<<endl;
            cout<<"--------"<<endl;
            break;

        default: cout<<"Opcion incorrecta intente nuevamente."<<endl;
                system("pause");
            break;
    }

} while (opcion != 0);


}





