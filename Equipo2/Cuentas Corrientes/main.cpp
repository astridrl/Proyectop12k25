////Menu modificado por Astrid Ru�z 9959 24 2976 - Agregu� menu de seguridad para usuarios y agregu� backup
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "usuarios.h"
#include "catalogos.h"
#include "procesos.h"
#include "bitacora.h"
#include <limits>

using namespace std;

void menuGeneral ();
void menuInicio();
void menuUsuarios();
void menuBackup();

//Objetos
usuarios usuariosrRegistrado;
Catalogos catalogo;
bitacora auditorias;

int main()
{
    menuInicio();

    system("cls");
    cout << "\n\t\tSALIENDO DEL SISTEMA...\n";
    return 0;
}

void menuInicio() {
    int opcion;
    bool accesoUsuarios;

    do {
        system("cls");
        cout << "\n\t\t--------------------------------------" << endl;
        cout << "\t\t   SISTEMA DE USUARIOS - MENU ARCHIVOS  " << endl;
        cout << "\t\t--------------------------------------" << endl << endl;
        cout << "\t\t1. Iniciar Sesion" << endl;
        cout << "\t\t2. Registrarse" << endl; //para que el usuario tenga oportunidad de registrarse si no tiene user
        cout << "\t\t3. Gestion de Usuarios" << endl; //CRUD USUARIOS
        cout << "\t\t4. Backup y Respaldo" << endl;
        cout << "\t\t5. Salir" << endl;
        cout << "\t\tSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                accesoUsuarios = usuariosrRegistrado.loginUsuarios();
                if (accesoUsuarios) {
                    menuGeneral();
                    return;
                }
                break;
            case 2:
                system ("cls");
                usuariosrRegistrado.registrarUsuario();
                 break;
            case 3: //Se requiere que el usuario inicie sesi�n antes por seguridad
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesi�n para acceder a esta funci�n." << endl;
                     system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesi�n fallido. No se puede acceder a Gesti�n de Usuarios." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuUsuarios(); // ya est� autenticado aqu�
                break;
            case 4: //Se requiere que el usuario inicie sesi�n antes por seguridad
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesi�n para acceder a esta funci�n." << endl;
                    system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesi�n fallido. No se puede acceder a Backup." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuBackup();
                break;
            case 5:
                return; // Salir del programa
            default:
                cout << "\n\t\tOpci�n inv�lida. Intente de nuevo." << endl;
                system("pause");
        }
    } while (opcion != 5);
}

void menuUsuarios() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t | SISTEMA GESTION DE SEGURIDAD - Usuarios |" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingreso Usuarios" << endl;
        cout << "\t\t\t 2. Consulta Usuarios" << endl;
        cout << "\t\t\t 3. Modificaci�n Usuarios" << endl;
        cout << "\t\t\t 4. Eliminaci�n Usuarios" << endl;
        cout << "\t\t\t 5. Retornar al men� anterior" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\tIngrese una opci�n: ";
        cin >> choice;

        switch (choice) {
        case 1:
            usuariosrRegistrado.registrarUsuario();
            break;
        case 2:
            usuariosrRegistrado.consultarUsuarios();
            system("pause"); // <-- Pausa para que se lean los mensajes
            break;
        case 3:
            usuariosrRegistrado.modificarUsuario();
            system("pause");
            break;
        case 4:
            usuariosrRegistrado.eliminarUsuario();
            system("pause");
            break;
        case 5:
            break;
        default:
            cout << "n\t\tOpci�n no v�lida. Intente de nuevo" << endl;
        }

    } while (choice != 5);
}


void menuBackup() {
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t---------------------------------" << endl;
        cout << "\t\t  MEN� DE BACKUP Y RESPALDO     " << endl;
        cout << "\t\t---------------------------------" << endl << endl;
        cout << "\t\t1. Realizar backup de usuarios" << endl;
        cout << "\t\t2. Restaurar desde backup" << endl;
        cout << "\t\t3. Retornar al men� anterior" << endl;
        cout << "\t\tSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                usuariosrRegistrado.backupUsuarios();
                break;
            case 2:
                usuariosrRegistrado.restaurarBackup();
                break;
            case 3:
                break;
            default:
                cout << "\n\t\tOpci�n inv�lida. Intente de nuevo." << endl;
        }

        if (opcion != 3) {
            cout << "\n\t\tPresione Enter para continuar...";
            cin.get();
        }
    } while (opcion != 3);
}

void menuGeneral(){
    int opciones;
    do{
        system("cls"); // Limpia la pantalla
        cout << "\t\t\t---------------------- " << endl;
        cout << "\t\t\t | CUENTAS POR COBRAR |" << endl;
        cout << "\t\t\t-----------------------" << endl;
        cout << "\t\t1. Menu de Catalogos" << endl;
        cout << "\t\t2. Menu de Procesos" << endl;
        cout << "\t\t3. Menu de Reportes" << endl;
        cout << "\t\t4. Menu de Configuracion" << endl;
        cout << "\t\t5. Menu de Bitacora" << endl;
        cout << "\t\t6. Menu de Archivos (Usuarios)" << endl; //Astrid agreg� men� para los archivos
        cout << "\t\t7. Salir" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                catalogo.menuCatalogos();
                break;
            case 2:
                menuProcesos();
                break;
            case 3:
                //menuReportes();
                break;
            case 4:
                //menuConfiguracion();
                break;
            case 5:
                auditorias.menu();
                break;
            case 6:
                menuInicio();
                break;
            case 7:
                cout << "\n\n\t\tSaliendo del sistema...\n" << endl;
                break;
            default:
                cout << "n\t\tOpci�n no v�lida. Intente de nuevo" << endl;
        }
    } while (opciones != 7); // Repite el men� hasta que el usuario quiera salir

}
