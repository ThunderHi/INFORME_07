#include <iostream>
using namespace std;
class Cliente{
    protected:
        string nombre;
        string direccion;
        string numeroTarjeta;
        string contraseña;
    public:
        Cliente(string _nombre, string _direccion, string _numeroTarjeta, string _contraseña){
            
        }
};
class ClienteSeguro:public Cliente{

};