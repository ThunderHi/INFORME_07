#include <iostream>
#include <string>
using namespace std;

class Persona { //declaramos la clase Persona
    protected: //atributo protegido "email"
    string email;
    public: //atributos publicos nombre, edad y salario
    string nombre;
    int edad;
    float salario;

    Persona(string nom, int ed, float sal, string correo) //constructor extendido de la clase Persona
        :nombre(nom), edad(ed), salario(sal), email(correo) {} //inicializacion de los atributos

    void mostrarInfo() { //funcion miembro publica para mostrar la informacion de cada Persona
        cout<< "Nombre: "<<nombre << endl;
        cout<< "Edad: "<<edad << endl;
        cout<<"Salario: "<<salario << endl; 
        //no agregamos el atributo "email" porque se accederá a dicho atributo desde las clases derivadas
    }
};

class Empleado : public Persona { //clase Empleado heredada de la clase Persona
public:
    Empleado(string nom, int ed, float sal, string correo) //constructor de la clase Empleado
        :Persona(nom, ed, sal, correo) {}
        
    string getCorreo() { //metodo getter para obtener acceso al atributo protegido email
        return email;
    }
};

class Cliente : public Persona { //clase Cliente heredada de la clase Persona
public:
    Cliente(string nom, int ed, float sal, string correo) //constructor de la clase Cliente
        :Persona(nom, ed, sal, correo) {}
        
    string getCorreo() { //metodo getter para obtener acceso al atributo protegido email
        return email;
    }    
};

int main() { //creamos objetos emp1 y cl1 de las clases Empleado y Cliente respectivamente
    Empleado emp1("Nylder", 20, 1500, "nylderff@gmail.com");
    Cliente cl1("Thunder", 23, 0, "thundergod@gmail.com");
    //mostramos la informacion de ambos objetos
    emp1.mostrarInfo();
    cout<<"Correo: "<<emp1.getCorreo()<<endl;
    cout<<endl;
    cl1.mostrarInfo();
    cout<<"Correo: "<< cl1.getCorreo()<<endl;
    return 0;
}
