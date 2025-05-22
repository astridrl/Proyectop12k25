 #include "menu_general.h"
#include "menu_cliente.h"
#include "menu_producto.h"
#include "menu_compra.h"
#include "menu_archivo.h"
#include <iostream>

using namespace std;

void mostrarMenuGeneral() {
    int opcion;
    do {
        cout << "\n=== MEN� PRINCIPAL ==="
             << "\n1. Gesti�n de Clientes"
             << "\n2. Gesti�n de Productos"
             << "\n3. Gesti�n de Compras"
             << "\n4. Herramientas de Archivo"
             << "\n5. Cerrar sesi�n"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: mostrarMenuCliente(); break;
            case 2: mostrarMenuProducto(); break;
            case 3: mostrarMenuCompra(); break;
            case 4: menuArchivo(); break;
            case 5: cout << "Cerrando sesi�n...\n"; break;
            default: cerr << "Opci�n inv�lida\n";
        }
    } while(opcion != 5);
}
