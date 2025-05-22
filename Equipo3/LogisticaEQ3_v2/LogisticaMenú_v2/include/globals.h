// Prevenci�n de inclusi�n m�ltiple del archivo de cabecera
#ifndef GLOBALS_H
#define GLOBALS_H

//JENNIFER ALBA DAYAMI BARRIOS FLORES
//9959-24-10016
//MAYO 2025

// Inclusi�n de bibliotecas necesarias
#include <vector>          // Para usar std::vector
#include "usuarios.h"      // Manejo de usuarios del sistema
#include "bitacora.h"      // Registro de actividades (auditor�a)
#include "reportes.h"      // Generaci�n de reportes
#include "envios.h"        // Gesti�n de env�os
#include "facturacion.h"   // Procesos de facturaci�n
#include "transportistas.h"// Manejo de transportistas
#include "pedidos.h"       // Gesti�n de pedidos
#include "inventario.h"    // Control de inventario

// Declaraciones de variables globales (definidas en otro archivo .cpp)

// Gestor principal de pedidos del sistema
extern Pedidos gestorPedidos;

// Gestor principal del inventario de productos
extern Inventario gestorInventario;

// Gestor principal de env�os y log�stica
extern Envios gestorEnvios;

// Gestor principal de facturaci�n y cobros
extern Facturacion gestorFacturacion;

// Gestor principal para generaci�n de reportes
extern Reportes gestorReportes;

// Usuario actualmente registrado en el sistema
extern usuarios usuarioRegistrado;

// Sistema de registro de actividades (bit�cora/auditor�a)
extern bitacora auditoria;

// Lista de transportistas disponibles (usando vector en lugar de array)
extern std::vector<Transportistas> listaTransportistas;

// Fin de la definici�n del archivo de cabecera
#endif // GLOBALS_H
