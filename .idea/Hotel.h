//
// Created by rodri on 4/7/2019.
//

#ifndef PROYECTOFINALPOO_HOTEL_H
#define PROYECTOFINALPOO_HOTEL_H

#include "Objeto.h"
#include "Tipos.h"

class Hotel: public Objeto{
private:
    TipoEntero Estrellas;
    TipoString Disponibilidad;
public:
    Hotel();
    Hotel(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
          TipoString& direccion, TipoEntero& calificacion,TipoEntero Estrellas,
          TipoString Disponibilidad);
    void setEstrellas(TipoEntero Estrellas);
    TipoEntero getEstrellas();
    void setDisponibilidad(TipoEntero Disponibilidad);
    TipoString getDisponibilidad();
    virtual ~Hotel(){};
};

#endif //PROYECTOFINALPOO_HOTEL_H
