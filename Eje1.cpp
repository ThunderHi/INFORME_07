#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;
    double precio;

public:
    Vehiculo(string marca, string modelo, int anio, double precio)
        : marca(marca), modelo(modelo), anio(anio), precio(precio) {}

    void mostrar_info() {
        cout<<"Marca: "<<marca<<endl;
        cout<<"Modelo: "<<modelo<<endl;
        cout<<"Año: "<<anio<<endl;
        cout<<"Precio: "<<precio<<endl;
    }
};

class Automovil : public Vehiculo {
private:
    int num_puertas;
    string tipo_combustible;

public:
    Automovil(string marca, string modelo, int anio, double precio, int num_puertas, string tipo_combustible)
        : Vehiculo(marca, modelo, anio, precio), num_puertas(num_puertas), tipo_combustible(tipo_combustible) {}

    void mostrar_info() {
        Vehiculo::mostrar_info();
        cout<<"Numero de puertas: "<<num_puertas<<endl;
        cout<<"Tipo de combustible: "<<tipo_combustible<<endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string marca, string modelo, int anio, double precio, int cilindrada)
        : Vehiculo(marca, modelo, anio, precio), cilindrada(cilindrada) {}

    void mostrar_info() {
        Vehiculo::mostrar_info();
        cout<<"Cilindrada: "<<cilindrada<<endl;
    }
};

int main() {
    Automovil auto1("Toyota", "Corolla", 2020, 25000, 4, "Gasolina");
    auto1.mostrar_info();
    cout<<endl;

    Motocicleta moto1("Honda", "CBR600RR", 2018, 12000, 599);
    moto1.mostrar_info();

    return 0;
}


//Aun esta en prueba xd
