#include "reportes.h"
#include <iostream>

//Clases con informes
#include "pago.h"
#include "factura.h"
//...otros

using namespace std;
reportes::reportes()
{
    //ctor
}

void reportes::menuInformes() {
    pago pag;

    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMen� de Reportes" << endl;
        cout << "\t\t-----------------------------" << endl;
        cout << "\t\t1. Listado de Cuentas por Pagar" << endl;
        cout << "\t\t2. Listado de Cuentas por Cobrar" << endl;
        cout << "\t\t3. Reporte de Pagos Realizados" << endl;
        cout << "\t\t4. Reporte de Ingresos Recibidos" << endl;
        cout << "\t\t5. Reporte de Transacciones Bancarias" << endl;
        cout << "\t\t9. Volver al men� principal" << endl;
        cout << "\n\t\tIngresa tu Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pag.reporteCuentasPorPagar(); //Muestra todas las facturas pendientes de pago
                break;
            case 2:
                //reporte Cuentas Por Cobrar
                break;
            case 3:
                pag.reportePagos(); //Muestra todos los pagos registrados por acreedores/proveedores
                break;
            case 4:
                //reporteIngresos() ---pagos de clientes
                break;
            case 5:
                //pag.reporteTransaccionesBancarias(); Este creo que no
                break;
            case 6:
                break;
            default:
                cout << "\t\tOpci�n inv�lida..." << endl;
                system("pause");
        }
    } while (opcion != 6);
}

void reportes::menuFactura() {
    menuReporteFactura;

    int opcion;
    do {
        system("cls");
        cout << "\n\t\tMenu de Facturas" << endl;
        cout << "\t\t-----------------------------" << endl;
        cout << "\t\t1. Factura de Cliente" << endl;
        cout << "\t\t2. Factura de Proveedor" << endl;
        cout << "\t\t3. Factura de Acreedor" << endl;
        cout << "\t\t4. Reportes Factura " << endl;
        cout << "\t\t5. Volver al menu anterior" << endl;
        cout << "\n\t\tSeleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                menuReporteFactura();
                break;
            case 5:
                break;
            default:
                cout << "\t\tOpci�n inv�lida." << endl;
                system("pause");
        }
    } while (opcion != 5);
}
