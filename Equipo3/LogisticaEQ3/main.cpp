// 9959-24-11603
// Programa principal que integra los m�dulos de usuarios, pedidos, inventario, env�os, facturaci�n, reportes y bit�cora.
// Incluye autenticaci�n de usuario y men� general de navegaci�n del sistema.

#include <iostream>
#include "usuarios.h"
#include "pedidos.h"
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"
#include "bitacora.h"

using namespace std;

// Instancias de clases globales para gestionar los distintos m�dulos
usuarios usuarioRegistrado;
bitacora auditoria;
Pedidos gestorPedidos;
Inventario gestorInventario;
Envios gestorEnvios;
Facturacion gestorFacturacion;
Reportes gestorReportes;

// Prototipo del men� principal
void menuGeneral();

int main() {
    bool accessUsuarios;

    // Inicio de sesi�n del usuario
    accessUsuarios = usuarioRegistrado.loginUsuarios();

    // Si el login es exitoso, se muestra el men� principal
    if (accessUsuarios) {
        menuGeneral();
    }

    // Mensaje de despedida al salir
    system("cls");
    cout << "** Hasta la pr�xima **";
    return 0;
}

// Funci�n que muestra el men� general del sistema
void menuGeneral() {
    int choice;
    do {
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t|     SISTEMA DE GESTI�N LOG�STICA     |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t| Usuario: " << usuarioRegistrado.getNombre() << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Gesti�n de Pedidos" << endl;
        cout << "\t\t 2. Control de Inventario" << endl;
        cout << "\t\t 3. Env�os y Transportes" << endl;
        cout << "\t\t 4. Facturaci�n y An�lisis" << endl;
        cout << "\t\t 5. Reportes y An�lisis" << endl;
        cout << "\t\t 6. Salir del Sistema" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpci�n a escoger: [1/2/3/4/5/6]" << endl;
        cout << "\t\tIngresa tu opci�n: ";
        cin >> choice;

        switch(choice) {
            case 1:
                gestorPedidos.gestionPedidos();
                break;
            case 2:
                gestorInventario.controlInventario();
                break;
            case 3:
                gestorEnvios.gestionEnvios();
                break;
            case 4:
                gestorFacturacion.gestionFacturacion();
                break;
            case 5:
                gestorReportes.generarReportes();
                break;
            case 6: break;
            default:
                cout << "\n\t\tOpci�n inv�lida... Intenta de nuevo...";
                cin.get();
        }
    } while(choice != 6);
}
