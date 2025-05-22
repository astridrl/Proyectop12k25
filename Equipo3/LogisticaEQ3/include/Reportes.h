// 9959-24-11603 GE
// Declaraci�n de la clase Reportes, que se encarga de generar distintos
// informes y an�lisis para el sistema log�stico.

#ifndef REPORTES_H
#define REPORTES_H

#include "bitacora.h"   // Para registrar acciones en la bit�cora
#include "usuarios.h"   // Para acceder a informaci�n del usuario actual

// Clase que encapsula las funcionalidades relacionadas con reportes y an�lisis
class Reportes {
public:
    // M�todo principal para generar reportes desde el men�
    void generarReportes();

    // Genera un informe de ventas
    void informeVentas();

    // Realiza un an�lisis de los tiempos de entrega
    void analisisTiemposEntrega();

    // Muestra un reporte del estado actual del inventario
    void reporteInventarios();

    // Eval�a el desempe�o de los proveedores
    void evaluacionProveedores();
};

#endif // REPORTES_H
