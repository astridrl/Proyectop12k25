#ifndef MENUCLIENTES_H
#define MENUCLIENTES_H

// Evita inclusiones m�ltiples del mismo archivo
// "Include guard" para asegurar que el archivo se incluya solo una vez durante la compilaci�n

#include "Clientes.h"  // Incluye la definici�n de la clase Clientes
#include "usuarios.h"  // Incluye la definici�n de la clase usuarios
#include <vector>      // Necesario para utilizar std::vector

/**
 * @class MenuClientes
 * @brief Clase que gestiona la interfaz del men� de clientes.
 *
 * Esta clase ofrece una funci�n est�tica para mostrar el men� de operaciones
 * relacionadas con los clientes: agregar, mostrar, modificar, eliminar y guardar datos.
 */
class MenuClientes {
public:
    /**
     * @brief Muestra el men� de opciones para la gesti�n de clientes.
     *
     * @param listaClientes Referencia a un vector que contiene la lista de clientes registrados.
     * @param usuarioActual Referencia al objeto que representa al usuario que ha iniciado sesi�n.
     */
    static void mostrar(std::vector<Clientes>& listaClientes, usuarios& usuarioActual);
};

#endif // MENUCLIENTES_H
