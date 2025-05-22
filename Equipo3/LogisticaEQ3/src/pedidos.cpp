#include "pedidos.h"
 #include <iostream>
 using namespace std;

 //Jennifer Barrios Coordinadora Equipo 3
 //9959-24-10016
 //MAYO 2025

// Se hace referencia externa a las variables globales 'usuarioRegistrado' y 'auditoria'
// 'usuarioRegistrado' representa al usuario actual del sistema
// 'auditoria' representa el sistema de bit�cora que registra actividades
extern usuarios usuarioRegistrado;
extern bitacora auditoria;

// M�todo principal de la clase 'Pedidos' para gestionar las distintas operaciones relacionadas a pedidos
void Pedidos::gestionPedidos() {
    int opcion;
    do {
        // Limpia la pantalla (solo funciona en sistemas Windows)
        system("cls");

        // Muestra el men� de opciones para la gesti�n de pedidos
        cout << "\t\t========================================" << endl;
        cout << "\t\t| GESTION DE PEDIDOS - LOGISTICA       |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Crear nuevo pedido" << endl;
        cout << "\t\t 2. Consultar pedidos" << endl;
        cout << "\t\t 3. Modificar pedido" << endl;
        cout << "\t\t 4. Cancelar pedido" << endl;
        cout << "\t\t 5. Historial de pedidos" << endl;
        cout << "\t\t 6. Volver al menu anterior" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: ";
        cin >> opcion;

        // Ejecuta la funci�n correspondiente seg�n la opci�n seleccionada
        switch(opcion) {
            case 1: crearPedido(); break;
            case 2: consultarPedidos(); break;
            case 3: modificarPedido(); break;
            case 4: cancelarPedido(); break;
            case 5: verHistorial(); break;
            case 6: break; // Sale del bucle para volver al men� anterior
            default:
                cout << "\n\t\tOpcion invalida!";
                cin.get(); // Espera una tecla para continuar
        }
    } while(opcion != 6); // Repite hasta que el usuario elija salir
}

// Crea un nuevo pedido y registra la acci�n en la bit�cora
void Pedidos::crearPedido() {
    cout << "\n\t\t[Creando nuevo pedido...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "100", "NUEVO PEDIDO");
    system("pause");
}

// Consulta los pedidos existentes y registra la acci�n en la bit�cora
void Pedidos::consultarPedidos() {
    cout << "\n\t\t[Consultando nuevo pedido...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "101", "CONSULTA PEDIDO");
    system("pause");
}

// Permite modificar un pedido existente y registra la acci�n
void Pedidos::modificarPedido() {
    cout << "\n\t\t[Modificando pedido...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "102", "MODIFICANDO PEDIDO");
    system("pause");
}

// Cancela un pedido y registra la acci�n en la bit�cora
void Pedidos::cancelarPedido() {
    cout << "\n\t\t[Cancelando pedido...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "103", "PEDIDO CANCELADO");
    system("pause");
}

// Muestra el historial de pedidos y registra la acci�n
void Pedidos::verHistorial() {
    cout << "\n\t\t[Viendo el Historial de pedidos...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "104", "HISTORIAL PEDIDOS");
    system("pause");
}
