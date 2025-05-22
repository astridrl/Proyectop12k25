#ifndef MENUPRODUCTOS_H
#define MENUPRODUCTOS_H
//JENNIFER BARRIOS COORD: EQ3
//MAYO 2025
// Inclusi�n de dependencias necesarias
#include <vector>          // Para usar std::vector
#include "Producto.h"      // Para la clase Producto
#include "usuarios.h"      // Para la clase usuarios

// Clase que gestiona el men� de productos
class MenuProductos {
public:
    // Muestra el men� de opciones para productos
    // @param listaProductos Referencia al vector de productos existentes
    // @param usuarioActual Referencia al usuario que est� usando el sistema
    static void mostrar(std::vector<Producto>& listaProductos, usuarios& usuarioActual);
};

#endif
