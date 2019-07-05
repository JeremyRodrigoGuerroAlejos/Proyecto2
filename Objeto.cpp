//
// Created by utec on 21/06/19.
//

#include "Objeto.h"
#include "Tierra.h"


Objeto::Objeto(): color{}, tipo{}, posX{}, posY{}  {}

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
               TipoString& direccion, TipoEntero& calificacion){
        this->nombre=nombre;
        this->color=color;
        this->posX=posX;
        this->posY=posY;
        this->tipo=tipo;
        this->direccion=direccion;
        this->calificacion=calificacion;
}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {posX=x, posY=y;} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
TipoCaracter Objeto::getTipo() { return tipo; }
TipoString  Objeto::getDireccion() { return direccion;}
TipoEntero Objeto::getCalificacion() { return calificacion;}

TipoString Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
}
