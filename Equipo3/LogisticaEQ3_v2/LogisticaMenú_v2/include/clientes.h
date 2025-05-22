//LUIS ANGEL MENDEZ FUENTES
//9959-24-6845
#ifndef CLIENTES_H
#define CLIENTES_H

#include <vector>
#include <string>

/**
 * @class Clientes
 * @brief Representa un cliente y gestiona operaciones CRUD y persistencia de datos.
 */
class Clientes {
private:
    /// Identificador �nico del cliente (formato secuencial, rango permitido: 3107�3157)
    std::string id;

    /// Nombre completo del cliente
    std::string nombre;

    /// Direcci�n f�sica del cliente
    std::string direccion;

    /// N�mero de tel�fono del cliente
    std::string telefono;

    /// N�mero de Identificaci�n Tributaria (NIT) del cliente
    std::string nit;

public:
    // ===================== M�TODOS CRUD =====================

    /**
     * @brief Agrega un nuevo cliente a la lista.
     * @param lista Vector que contiene todos los clientes actuales.
     * @param usuarioActual Nombre de usuario que realiza la acci�n.
     */
    static void agregar(std::vector<Clientes>& lista, const std::string& usuarioActual);

    /**
     * @brief Muestra todos los clientes almacenados en la lista.
     * @param lista Lista de clientes a mostrar.
     */
    static void mostrar(const std::vector<Clientes>& lista);

    /**
     * @brief Modifica un cliente existente por ID.
     * @param lista Lista de clientes donde se buscar� el ID.
     * @param usuarioActual Nombre de usuario que realiza la acci�n.
     * @param id ID del cliente que se desea modificar.
     */
    static void modificar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& idCliente);

    /**
     * @brief Elimina un cliente existente por ID.
     * @param lista Lista de clientes donde se buscar� el ID.
     * @param usuarioActual Nombre de usuario que realiza la acci�n.
     * @param id ID del cliente a eliminar.
     */
    static void eliminar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id);

    // ===================== M�TODOS DE ARCHIVO =====================

    /**
     * @brief Guarda los clientes en formato tabular en Clientes.txt.
     * @param lista Lista de clientes a guardar.
     */
    static void guardarEnArchivo(const std::vector<Clientes>& listaClientes);

    /**
     * @brief Carga los clientes desde el archivo Clientes.txt.
     * @param lista Vector donde se cargar�n los clientes.
     */
    static void cargarDesdeArchivo(std::vector<Clientes>& lista);

    // ===================== M�TODOS DE GESTI�N DE ID =====================

    /**
     * @brief Genera un ID �nico para un nuevo cliente.
     * @param lista Lista de clientes existentes.
     * @return Un ID �nico en formato de string.
     */
    static std::string generarIdUnico(const std::vector<Clientes>& lista);

    /**
     * @brief Verifica si un ID est� disponible en la lista.
     * @param lista Lista de clientes existentes.
     * @param id ID a verificar.
     * @return true si est� disponible, false si ya existe.
     */
    static bool idDisponible(const std::vector<Clientes>& lista, const std::string& id);

    /**
     * @brief Verifica si un ID cumple con el formato v�lido.
     * @param id ID a validar.
     * @return true si el ID es v�lido, false si no lo es.
     */
    static bool esIdValido(const std::string& id);

    // ===================== GETTERS =====================

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getDireccion() const { return direccion; }
    std::string getTelefono() const { return telefono; }
    std::string getNit() const { return nit; }
};

#endif // CLIENTES_H
