#ifndef BECAS2022_H
#define BECAS2022_H
#include <cstring>
#include "../estudiante.h"
#include "../examen.h"
#include "../fecha.h"
using namespace std;

class Becas2022
{
private:
    char _nombre[50];
    char _apellido[50];
    float _promedio;

public:
    Becas2022();
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setPromedio(float NP)
    {
        _promedio=NP;
    }
    const char * getNombre()
    {
        return _nombre;
    }
    const char *getApellido()
    {
        return _apellido;
    }
    float getPromedio()
    {
        return _promedio;
    }




    //FUNCIONES DE DISCO
    bool GuardarEnDisco();
    int LeerDeDisco(int pos);



};

#endif // BECAS2022_H
