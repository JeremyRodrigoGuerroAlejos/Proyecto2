//
// Created by utec on 21/06/19.
//

#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include "iostream"
#include "Tipos.h"


class Objeto {
protected:
    TipoString    nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoCaracter tipo;
    TipoString direccion;
    TipoEntero calificacion;
public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
           TipoString& direccion, TipoEntero& calificacion);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    char getColor();
    TipoEntero getPosX();
    TipoEntero getPosY();
    TipoCaracter getTipo();
    TipoString getDireccion();
    TipoEntero getCalificacion();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};



#endif //GAME_OBJETO_H
