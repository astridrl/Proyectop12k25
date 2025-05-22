// LUIS ANGEL MENDEZ FUENTES 9959-24-6845
#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <fstream>
using namespace std;

// Clase 'bitacora': Maneja el registro de acciones realizadas en el sistema.
class bitacora {
private:
    string nombreUsuario;   // Nombre del usuario que realiza la acci�n
    string codigoAccion;    // C�digo que identifica la acci�n
    string descripcion;     // Descripci�n de la acci�n realizada
public:
    // Inserta una nueva entrada en la bit�cora con los datos proporcionados
    void insertar(string usuario, string codigo, string accion);

    // Muestra las entradas registradas en la bit�cora
    void desplegar();

    // Muestra un men� para acceder a la bit�cora (solo desde administraci�n)
    void menuBitacora();
};

#endif // BITACORA_H
