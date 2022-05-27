// MATIAS FALDUTI

#include<iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Becas2022.h"

Becas2022::Becas2022(){
    strcpy(_nombre, "/");
    strcpy(_apellido,"/");
    _promedio=0;
}

void Becas2022::setNombre(string nombre){
    strcpy(_nombre, nombre.c_str());
}
void Becas2022::setApellido(string apellido){
    strcpy(_apellido, apellido.c_str());
}

bool Becas2022::GuardarEnDisco()
{
    FILE *p;
    p=fopen("becas2022.dat","wb");
    if(p==NULL)
    {
        cout<< "Error de Archivo"<<endl;
        return 0;
    }

    bool ok=fwrite(this,sizeof(Becas2022),1,p);
    if(ok==true)
    {
        cout<< "REGISTRO GUARDADO";
        cout<<endl;
    }
    else
    {
        cout<<"NO SE PUDO ABRIE EL ARCHIVO";
    }
    fclose(p);
    return ok;

}


int  Becas2022::LeerDeDisco(int pos){
    FILE *p;
    p = fopen("becas2022.dat","rb");
    if ( p == NULL )
    {
        cout << "No se pudo abrir el archivo"<<endl;
        cout<< "error";
        return false;
    }

    fseek ( p, pos* sizeof(Becas2022), 0 );
    int leyo = fread( this, sizeof(Becas2022), 1, p);
    fclose(p);
    return leyo;
 }




