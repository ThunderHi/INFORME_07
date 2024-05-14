#include <iostream>
#include <string>
using namespace std;

class Movil {
public:
    string marca;
    string modelo;
    string sistemaOperativo;

    Movil(){ }
    Movil( string marca, string modelo, string sistemaOperativo): marca(marca), modelo(modelo), sistemaOperativo(sistemaOperativo) {
            cout << "Constructor de Movil" << endl;
        }

    ~Movil() {
        cout << "Destructor de Movil" << endl;
    }
};  

class Telefono : public Movil {
public:
    Telefono(string marca, string modelo, string sistemaOperativo): Movil(marca, modelo, sistemaOperativo) {
            cout << "Constructor de Telefono" << endl;
        }

    ~Telefono() {
        cout << "Destructor de Telefono" << endl;
    }
};

class Tablet : public Movil {
public:
    Tablet(string marca,string modelo, string sistemaOperativo): Movil(marca, modelo, sistemaOperativo) {
            cout << "Constructor de Tablet" << endl;
        }

    ~Tablet() {
        cout << "Destructor de Tablet" << endl;
    }
};

int main() {
    Telefono telefono("Samsung", "Galaxy S20", "Android");
    Tablet tablet("Apple", "iPad Pro", "iOS");

    return 0;
}
