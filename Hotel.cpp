//
// Created by rodri on 4/7/2019.
//

#include "Hotel.h"


Hotel::Hotel(): Estrellas{}, Disponibilidad{}{}

Hotel::Hotel(const TipoString& nombre, TipoCaracter color,
             TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
             TipoString& direccion, TipoEntero& calificacion,TipoEntero Estrellas,
             TipoString Disponibilidad):
        Objeto(nombre,color,posX,posY,tipo,direccion,calificacion){
    this->Estrellas=Estrellas;
    this->Disponibilidad=Disponibilidad;
}

void Hotel::setEstrellas(TipoEntero Estrellas) {this->Estrellas=Estrellas;}
void Hotel::setDisponibilidad(TipoEntero Disponibilidad){this->Disponibilidad=Disponibilidad;}


TipoEntero Hotel::getEstrellas() {return(Estrellas);}
TipoString Hotel::getDisponibilidad() {return(Disponibilidad);}

