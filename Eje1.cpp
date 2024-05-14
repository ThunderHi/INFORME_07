#include <iostream>
#include <string>

using namespace std;

//Clase base Vehiculo
class Vehiculo {
protected:
    //Atributos protegidos de la clase Vehiculo
    string marca;
    string modelo;
    int anio;
    double precio;

public:
    //Constructor de la clase Vehiculo
    Vehiculo(string marca, string modelo, int anio, double precio)
        : marca(marca), modelo(modelo), anio(anio), precio(precio) {}

    //Método para mostrar información del vehículo
    void mostrar_info() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Precio: " << precio << endl;
    }
};

//Clase Automovil heredada de Vehiculo
class Automovil : public Vehiculo {
private:
    //Atributos específicos de la clase Automovil
    int num_puertas;
    string tipo_combustible;

public:
    //Constructor de la clase Automovil
    Automovil(string marca, string modelo, int anio, double precio, int num_puertas, string tipo_combustible)
        : Vehiculo(marca, modelo, anio, precio), num_puertas(num_puertas), tipo_combustible(tipo_combustible) {}

    //Método para mostrar información del automóvil
    void mostrar_info() {
        //Llamamos al método mostrar_info de la clase base Vehiculo
        Vehiculo::mostrar_info();
        cout << "Número de puertas: " << num_puertas << endl;
        cout << "Tipo de combustible: " << tipo_combustible << endl;
    }
};

//Clase Motocicleta heredada de Vehiculo
class Motocicleta : public Vehiculo {
private:
    //Atributo específico de la clase Motocicleta
    int cilindrada;

public:
    //Constructor de la clase Motocicleta
    Motocicleta(string marca, string modelo, int anio, double precio, int cilindrada)
        : Vehiculo(marca, modelo, anio, precio), cilindrada(cilindrada) {}

    //Método para mostrar información de la motocicleta
    void mostrar_info() {
        //Llamamos al método mostrar_info de la clase base Vehiculo
        Vehiculo::mostrar_info();
        cout << "Cilindrada: " << cilindrada << endl;
    }
};

int main() {
    //Creamos un objeto de la clase Automovil
    Automovil auto1("Toyota", "Corolla", 2020, 25000, 4, "Gasolina");
    //Mostramos la información del automóvil
    auto1.mostrar_info();
    cout << endl;

    //Creamos un objeto de la clase Motocicleta
    Motocicleta moto1("Honda", "CBR600RR", 2018, 12000, 599);
    //Mostramos la información de la motocicleta
    moto1.mostrar_info();

    return 0;
}
