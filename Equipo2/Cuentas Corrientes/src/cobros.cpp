//Programado y documentado por Dulce Mart�nez
#include "Cobros.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "usuarios.h"
#include "bitacora.h"

using namespace std;

extern usuarios usuariosrRegistrado;

void GestionCobros::menuCobros() {
    GestionCobros gc;
    int opcion;

    while (true) {
        system("cls");
        cout << "\n\n\t\t========= MEN� DE COBROS =========\n";
        cout << "\t\t1. Ver Cuentas por Cobrar\n";
        cout << "\t\t2. Registrar Cobro\n";
        cout << "\t\t3. Ver Historial de Cobros\n";
        cout << "\t\t4. Buscar Cobro por Factura\n";
        cout << "\t\t5. Listar Cobros por Cliente\n";
        cout << "\t\t6. Volver al Men� Principal\n";
        cout << "==================================\n";
        cout << "Ingrese una opci�n: ";
        cin >> opcion;

        if (opcion == 6) {
            break;
        }

        switch (opcion) {
            case 1:
                gc.listarCuentasPorCobrar();
                break;
            case 2:
                gc.registrarCobro();
                break;
            case 3:
                gc.listarHistorialCobros();
                break;
            case 4: {
                int id;
                cout << "Ingrese ID de factura: ";
                cin >> id;
                gc.buscarCobroPorFactura(id);
                break;
            }
            case 5: {
                string id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                gc.listarCobrosPorCliente(id);
                break;
            }

            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
                break;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get(); // Este solo espera Enter, pero no limpia buffer (y es opcional)
        cin.get(); // Lo puedes quitar si te da problemas
    }
}

void GestionCobros::listarCuentasPorCobrar() {
    ifstream fileFacturas("facturas.bin");
    if (!fileFacturas) {
        cout << "No se pudo abrir el archivo de facturas." << endl;
        system("pause");
        return;
    }

    string linea;
    string idFactura, nombre, cuenta, montoStr, fecha, hora, tipo, clasificacion, estado;
    float montoTotal, saldoPendiente;

    cout << "------ Listado de Cuentas por Cobrar ------\n";
    cout << "ID Factura | Cliente | Monto Total | Saldo Pendiente | Estado\n";
    cout << "-------------------------------------------------------------\n";

    while (getline(fileFacturas, linea)) {
        stringstream ss(linea);
        getline(ss, idFactura, ',');
        getline(ss, nombre, ',');
        getline(ss, cuenta, ',');
        getline(ss, montoStr, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, tipo, ',');
        getline(ss, clasificacion, ',');
        getline(ss, estado);

        montoTotal = stof(montoStr);

        // Calcular saldo pendiente con base en cobros
        saldoPendiente = montoTotal;
        ifstream fileCobros("cobros.bin");
        string lineaCobro;
        while (getline(fileCobros, lineaCobro)) {
            stringstream ssCobro(lineaCobro);
            string idCobro, idFacturaCobro, fechaCobro, montoCobroStr, metodo, nit, tipoEntidad, estadoCobro;
            getline(ssCobro, idCobro, ',');
            getline(ssCobro, idFacturaCobro, ',');
            getline(ssCobro, fechaCobro, ',');
            getline(ssCobro, montoCobroStr, ',');
            getline(ssCobro, metodo, ',');
            getline(ssCobro, nit, ',');
            getline(ssCobro, tipoEntidad, ',');
            getline(ssCobro, estadoCobro);

            if (idFacturaCobro == idFactura && estadoCobro == "ejecutado") {
                saldoPendiente -= stof(montoCobroStr);
            }
        }
        fileCobros.close();

        if (estado != "solvente" && estado != "pagada") {
            cout << idFactura << " | " << nombre << " | Q" << fixed << setprecision(2) << montoTotal
                 << " | Q" << saldoPendiente << " | " << estado << endl;
        }
    }

    fileFacturas.close();
    system("pause");
}

void GestionCobros::registrarCobro() {
    bitacora auditoria;

    // Archivos
    fstream fileFacturas, fileCobros, fileTemporal;

    // Variables de factura
    string lineaFactura;
    string idFactura, nombre, nitCliente, montoStr, fecha, hora, tipo, clasificacion, estado;
    float montoTotal, saldoPendiente, montoAcumulado = 0;
    string idFacturaRegistrada;

    // Variables del cobro
    string idCobro, fechaCobro, metodoCobro, estadoCobro;
    float montoCobro = 0;

    // Control
    bool facturaExiste = false;
    char confirmar;

    system("cls");
    cout << "\n------------- Registrar Nuevo Cobro -------------\n";
    cout << "\n\t\tIngrese el ID de la factura: ";
    cin >> idFacturaRegistrada;

    fileFacturas.open("facturas.bin", ios::in);
    fileTemporal.open("facturas_temporal.bin", ios::app | ios::out);

    if (!fileFacturas) {
        cout << "No se encontr� el archivo de facturas.\n";
        system("pause");
        return;
    }

    // Buscar la factura y calcular cobros anteriores
    while (getline(fileFacturas, lineaFactura)) {
        stringstream ss(lineaFactura);
        getline(ss, idFactura, ',');
        getline(ss, nombre, ',');
        getline(ss, nitCliente, ',');
        getline(ss, montoStr, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, tipo, ',');
        getline(ss, clasificacion, ',');
        getline(ss, estado);

        montoTotal = stof(montoStr);
        saldoPendiente = montoTotal;

        if (idFactura == idFacturaRegistrada && tipo == "Cliente" &&
            clasificacion == "Por cobrar" &&
            (estado == "Pendiente" || estado == "cobrado_parcial")) {

            // Calcular monto acumulado de cobros anteriores
            fileCobros.open("cobros.bin", ios::in);
            string lineaCobro, idCobroTemp, idFacturaTemp, fechaTemp, metodoTemp, nitTemp, tipoTemp, estadoTemp;
            float montoTemp;

            while (getline(fileCobros, lineaCobro)) {
                stringstream ssCobro(lineaCobro);
                getline(ssCobro, idCobroTemp, ',');
                getline(ssCobro, idFacturaTemp, ',');
                getline(ssCobro, fechaTemp, ',');
                ssCobro >> montoTemp;
                ssCobro.ignore(); // Ignora la coma
                getline(ssCobro, metodoTemp, ',');
                getline(ssCobro, nitTemp, ',');
                getline(ssCobro, tipoTemp, ',');
                getline(ssCobro, estadoTemp);

                if (idFacturaTemp == idFacturaRegistrada && estadoTemp == "ejecutado") {
                    montoAcumulado += montoTemp;
                }
            }
            fileCobros.close();

            saldoPendiente = montoTotal - montoAcumulado;

            facturaExiste = true;

            cout << "\nFactura encontrada - Saldo pendiente: Q" << fixed << setprecision(2) << saldoPendiente << endl;
            cout << "\n------------------------------------------------\n";
            cout << "Ingrese ID del cobro    : "; cin >> idCobro;
            cout << "Ingrese fecha del cobro : "; cin >> fechaCobro;
            cout << "Ingrese monto recibido  : Q "; cin >> montoCobro;
            cout << "Ingrese m�todo de cobro : "; cin >> metodoCobro;

            system("cls");
            cout << "\n--------- Resumen de la informaci�n ingresada ---------\n";
            cout << "ID Cobro        : " << idCobro << endl;
            cout << "ID Factura      : " << idFactura << endl;
            cout << "Fecha del cobro : " << fechaCobro << endl;
            cout << "M�todo de cobro : " << metodoCobro << endl;
            cout << "Monto recibido  : Q" << fixed << setprecision(2) << montoCobro << endl;
            cout << "Saldo Actual    : Q" << saldoPendiente << endl;
            cout << "NIT del cliente : " << nitCliente << endl;
            cout << "Tipo Entidad    : Cliente" << endl;

            cout << "\n�Est� seguro de guardar esta informaci�n? (S/N): ";
            cin >> confirmar;

            if (confirmar == 's' || confirmar == 'S') {
                if (montoCobro > saldoPendiente) {
                    cout << "El monto ingresado excede el saldo pendiente (Q" << saldoPendiente << ")\n";
                    estadoCobro = "rechazado";
                    montoCobro = 0;
                } else if (montoCobro < 0) {
                    cout << "El monto no puede ser menor a cero.\n";
                    estadoCobro = "rechazado";
                    montoCobro = 0;
                } else {
                    saldoPendiente -= montoCobro;

                    if (saldoPendiente == 0) {
                        estado = "solvente";
                        estadoCobro = "ejecutado";
                    } else {
                        estado = "cobrado_parcial";
                        estadoCobro = "ejecutado";
                    }

                    auditoria.insertar(usuariosrRegistrado.getNombre(), "8300", "UPDF"); // Actualizar facturas
                }
            } else {
                estadoCobro = "rechazado";
                montoCobro = 0;
            }
        }

        // Guardar la factura (actualizada o no)
        fileTemporal << idFactura << "," << nombre << "," << nitCliente << ","
                     << fixed << setprecision(2) << montoTotal << "," << fecha << "," << hora << ","
                     << tipo << "," << clasificacion << "," << estado << "\n";
    }

    fileFacturas.close();
    fileTemporal.close();

    if (!facturaExiste) {
        cout << "\nFactura no v�lida, ya solvente o no corresponde a un cliente.\n";
        remove("facturas_temporal.bin");
        system("pause");
        return;
    }

    // Reemplaza el archivo original
    remove("facturas.bin");
    rename("facturas_temporal.bin", "facturas.bin");

    // Guardar el cobro
    fileCobros.open("cobros.bin", ios::app | ios::out);
    if (!fileCobros) {
        cout << "No se encontr� el archivo de cobros.\n";
        system("pause");
        return;
    }

    fileCobros << idCobro << "," << idFacturaRegistrada << "," << fechaCobro << ","
               << fixed << setprecision(2) << montoCobro << "," << metodoCobro << ","
               << nitCliente << "," << "Cliente" << "," << estadoCobro << endl;

    fileCobros.close();

    if (estadoCobro == "rechazado") {
        cout << "\nEl cobro fue rechazado y registrado como tal.\n";
    } else {
        cout << "\nCobro registrado exitosamente.\n";
    }

    system("pause");
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8300", "AddC"); // Registrar cobro
}

void GestionCobros::listarHistorialCobros() {
    ifstream file("cobros.bin");
    string linea;

    if (!file) {
        cout << "No se encontr� el archivo de cobros.\n";
        return;
    }

    cout << "\n----------- Historial de Cobros (Clientes) -----------\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);

        if (tipo == "Cliente") {
            cout << "\nID Cobro   : " << idCobro
                 << "\nFactura    : " << idFactura
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nM�todo     : " << metodo
                 << "\nNIT Cliente: " << nit
                 << "\nEstado     : " << estado << endl;
        }
    }

    file.close();
    system("pause");
}

void GestionCobros::buscarCobroPorFactura(int idFactura) {
    string facturaBuscada;
    cout << "\nIngrese el ID de la factura: ";
    cin >> facturaBuscada;

    ifstream file("cobros.bin");
    string linea;
    bool encontrado = false;

    if (!file) {
        cout << "No se encontr� el archivo de cobros.\n";
        return;
    }

    cout << "\n--- Cobros para Factura: " << facturaBuscada << " ---\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);

        if (tipo == "Cliente" && idFactura == facturaBuscada) {
            encontrado = true;
            cout << "\nID Cobro   : " << idCobro
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nM�todo     : " << metodo
                 << "\nEstado     : " << estado << endl;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontraron cobros para esta factura.\n";
    }

    file.close();
    system("pause");
}

void GestionCobros::listarCobrosPorCliente(string nitCliente) {
    string nitBuscado;
    cout << "\nIngrese el NIT del cliente: ";
    cin >> nitBuscado;

    ifstream file("cobros.bin");
    string linea;
    bool encontrado = false;

    if (!file) {
        cout << "No se encontr� el archivo de cobros.\n";
        return;
    }

    cout << "\n--- Cobros del Cliente con NIT: " << nitBuscado << " ---\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);

        if (tipo == "Cliente" && nit == nitBuscado) {
            encontrado = true;
            cout << "\nID Cobro   : " << idCobro
                 << "\nFactura    : " << idFactura
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nM�todo     : " << metodo
                 << "\nEstado     : " << estado << endl;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontraron cobros para este cliente.\n";
    }

    file.close();
    system("pause");
}
