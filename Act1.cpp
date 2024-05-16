#include <iostream>
using namespace std;
//Clase cliente de entidad bancaria
class Cliente{
    //Atributos protegidos
    protected:
        string nombre;  
        string direccion;
        string numeroTarjeta;
        string contraseña;
    public:
        //Constructor
        Cliente(string _nombre, string _direccion, string _numeroTarjeta, string _contraseña){
            this->nombre = _nombre;
            this->nombre = _direccion;
            this->nombre = _numeroTarjeta;
            this->nombre = _contraseña;
        }
};

//Clase derivada de Cliente
class ClienteSeguro:public Cliente{     //La clase hija puede acceder a lo publico de padre
    

};