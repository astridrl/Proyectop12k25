// Angoly Araujo Mayo 2025 9959-24-17623


#ifndef MENUPROVEEDORES_H
#define MENUPROVEEDORES_H
#pragma once  // Previene inclusiones m�ltiples del archivo de encabezado

#include <vector>          // Para manejar listas de proveedores
#include "proveedor.h"     // Encabezado de la clase Proveedor
#include "usuarios.h"      // Encabezado de la clase usuarios (usuario actual)

/*
 * Clase MenuProveedores
 * Encapsula el men� de opciones relacionadas con la gesti�n de proveedores.
 */
class MenuProveedores {
public:
    static void mostrar(std::vector<Proveedor>& lista, usuarios& usuarioActual);
};

#endif // MENUPROVEEDORES_H

