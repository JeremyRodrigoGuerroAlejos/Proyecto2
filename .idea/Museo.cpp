//
// Created by rodri on 4/7/2019.
//

#include "Museo.h"


Museo::Museo(): Exposicion{}{}

Museo::Museo(const TipoString& nombre, TipoCaracter color,
             TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
             TipoString& direccion, TipoEntero& calificacion,TipoString Exposicion):
             Objeto(nombre,color,posX,posY,tipo,direccion,calificacion){
    this->Exposicion=Exposicion;
}

void Museo::setExposicion(TipoString Exposicion) {this->Exposicion=Exposicion;}

TipoString Museo::getExposicion() {return(Exposicion);}
