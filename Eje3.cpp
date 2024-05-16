#include <iostream>
#include <string>
using namespace std;

//Clase base Movil
class Movil {   
private:        //Atributos de la clase Movil
    string marca;
    string modelo;
    string sistemaOperativo;
public:         //Constructor de la clase Movil
    Movil( string marca, string modelo, string sistemaOperativo): marca(marca), modelo(modelo), sistemaOperativo(sistemaOperativo) {
            cout << "Constructor de Movil" << endl;  //Se imprime un mensaje por pantalla cuando se accede a este constructor
        }
    //Destructor de la clase Movil
    ~Movil() {
        cout << "Destructor de Movil" << endl;  //Se imprime un mensaje por pantalla cuando se accede a este destructor
    }
};  

//Clase telefono heredada de la clase Movil
class Telefono : public Movil {
public:
    //Constructor de la clase Telefono
    Telefono(string marca, string modelo, string sistemaOperativo): Movil(marca, modelo, sistemaOperativo) {
            cout << "Constructor de Telefono" << endl;  //Se imprime un mensaje por pantalla cuando se accede a este constructor
        }
    //Destructor especifico de la clase Telefono
    ~Telefono() {
        cout << "Destructor de Telefono" << endl;   //Se imprime un mensaje por pantalla cuando se accede a este destructor
    }
};

//Clase Tablet heredada de la clase Movil
class Tablet : public Movil {
public:
    //Constructor de la clase Tablet
    Tablet(string marca,string modelo, string sistemaOperativo): Movil(marca, modelo, sistemaOperativo) {
            cout << "Constructor de Tablet" << endl;    //Se imprime un mensaje por pantalla cuando se accede a este constructor
        }
    //Destructor especifico de la clase Tablet
    ~Tablet() {
        cout << "Destructor de Tablet" << endl;  //Se imprime un mensaje por pantalla cuando se accede a este destructor
    }
};

int main() {
    //Creacion de un objeto de la clase Telefono
    Telefono telefono("Samsung", "Galaxy S20", "Android");
    //Creacion de un pbjeto de la clast Tablet
    Tablet tablet("Apple", "iPad Pro", "iOS");

    return 0;
}
