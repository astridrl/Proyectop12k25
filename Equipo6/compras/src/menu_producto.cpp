#include "menu_producto.h"
#include "producto.h"
#include <iostream>

using namespace std;

void mostrarMenuProducto() {
    int opcion;
    do {
        cout << "\n=== GESTI�N DE PRODUCTOS ==="
             << "\n1. Registrar nuevo producto"
             << "\n2. Listar productos"
             << "\n3. Modificar producto"
             << "\n4. Eliminar producto"
             << "\n5. Volver al men� principal"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: ingresarProducto(); break;
            case 2: consultarProductos(); break;
            case 3: modificarProducto(); break;
            case 4: borrarProducto(); break;
            case 5: cout << "Volviendo...\n"; break;
            default: cerr << "Opci�n inv�lida\n";
        }
    } while(opcion != 5);
}
