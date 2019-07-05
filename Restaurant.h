//
// Created by rodri on 4/7/2019.
//

#ifndef PROYECTOFINALPOO_RESTAURANT_H
#define PROYECTOFINALPOO_RESTAURANT_H

#include "Tipos.h"
#include "Objeto.h"

class Restaurant : public Objeto{
private:
    TipoString TipodeComida;
    TipoString Especialidaddia;
public:
    Restaurant();
    Restaurant(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
               TipoString& direccion, TipoEntero& calificacion, TipoString TipodeComida,
               TipoString Especialidaddia);

    void setEspecialidad(TipoString Especialidad);
    void setTipode(TipoString TipodeComida);
    TipoString getTipode();
    TipoString getEspe();
    virtual ~Restaurant(){};
};

#endif //PROYECTOFINALPOO_RESTAURANT_H
