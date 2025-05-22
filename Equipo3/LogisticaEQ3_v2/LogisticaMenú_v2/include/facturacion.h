// Angoly Araujo Mayo 2025 9959-24-17623


#ifndef FACTURACION_H
#define FACTURACION_H

// Se incluye la biblioteca est�ndar de cadenas de texto
#include <string>
using namespace std;

// Estructura que representa una factura
struct Factura {
    int idFactura;        // Identificador �nico de la factura
    int idCliente;        // Identificador del cliente asociado a la factura
    int idPedido;         // Identificador del pedido asociado a la factura
    float monto;          // Monto total de la factura
    bool pagada;          // Estado de pago de la factura (true = pagada, false = pendiente)
    char cliente[50];     // Nombre del cliente (m�ximo 50 caracteres)
};

// Clase que gestiona las operaciones relacionadas con la facturaci�n
class Facturacion {
public:
    // Crea una nueva factura y la guarda en el archivo
    static void crearFactura();

    // Muestra todas las facturas almacenadas
    static void mostrarFacturas();

    // Permite modificar una factura existente
    static void modificarFactura();

    // Elimina una factura espec�fica del archivo
    static void eliminarFactura();

    // Muestra el men� principal de opciones de facturaci�n
    static void mostrarMenuFacturacion();

private:
    // Genera un ID �nico para una nueva factura
    static int generarIdFactura();

    // Guarda una factura en el archivo correspondiente
    static void guardarEnArchivo(const Factura& factura);

    // Registra una acci�n (crear, modificar, eliminar) en una bit�cora con el usuario que la realiz�
    static void registrarBitacora(const Factura& factura, const string& accion, const string& usuario);
};

#endif // FACTURACION_H
