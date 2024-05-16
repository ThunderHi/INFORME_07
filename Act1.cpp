#include <iostream>
#include <string>

using namespace std;
//Clase Base Cliente
class Cliente {
    protected:  //Atributos y metodos protegidos
        string nombre;  //Nombre del cliente
        string direccion;   //dirección del cliente
        float saldo; // Saldo del cliente
        string numeroTarjeta;   //Número de tarjeta del cliente
        string contrasena;  //Contrasena del cliente

        //Declaración de métodos virtuales
        virtual string encriptarTarjeta() = 0;
        virtual string encriptarContrasena() = 0;

    public:
        //Constructor de clase
        Cliente(string nom, string direc, float saldo, string tarjeta, string pass) {
            //Asignacion de parametros a atributos
            this->nombre = nom;   
            this->direccion = direc;
            this->saldo = saldo;
            this->numeroTarjeta = tarjeta;
            this->contrasena = pass;
        }
        //Destructor de clase
        ~Cliente(){}

        //Método para mostrar datos auténticos del cliente
        void mostrarDatos() {
            cout << "Nombre: " << nombre << endl;
            cout << "Direccion: "<< direccion<<endl;
            cout << "Saldo: " << saldo <<endl;
            cout << "Numero de tarjeta: " << numeroTarjeta << endl;
            cout << "Contrasena: " << contrasena << endl;
        }
};

class ClienteSeguro : public Cliente {
    public:
        //Constructor inicializando contructor base y herencia
        ClienteSeguro(string nom, string direc, float saldo, string tarjeta, string pass) : Cliente(nom, direc, saldo, tarjeta, pass) {}

        //Destructor
        ~ClienteSeguro(){}

        //Encriptacion de numero de tarjeta con sobreescritura
        string encriptarTarjeta() override{
            //se crea una copia de numeroTarjeta
            string temp = numeroTarjeta;
            string encriptado = "";

            //Se recorre todos los caracteres de contrasena
            for (int i = 0; i < temp.length(); i++) {
                //Se maneja el caso del último digito
                if (temp[i]=='9')   //en caso de '9' se coloca un '0'
                    temp[i]='0';
                else
                    temp[i]+= 1;    //caso contrario suma una posicion en ASCII
                encriptado += temp[i];  //Se almacena en variable string
            }
            return encriptado;
        }

        //Encriptación de contrasena con sobreescritura
        string encriptarContrasena() override{
            string temp = contrasena;
            string encriptado = "";

            //Se recorre todos los caracteres de contrasena
            for (int i = 0; i < temp.length(); i++) {
                
                //Se manejan los casos de los ultimos valores de numeros y letras
                switch (contrasena[i])
                {
                    case '9':   //en caso de '9' se coloca un '0'
                        temp[i] = '0';
                        break;
                    case 'z':   //en caso de 'z' se coloca un 'a'
                        temp[i] = 'a';
                        break;
                    case 'Z':   //en caso de 'Z' se coloca un 'A'
                        temp[i] = 'A';
                        break;
                    default:    //caso contrario suma una posicion en ASCII
                        temp[i]+= 1;
                        break;
                }
                encriptado += temp[i];  //Se almacena en variable string
            }
            return encriptado;
        }

        //Método para mostrar datos encriptados
        void mostrarEncriptacion(){
            cout<<"DATOS ENCRIPTADOS DEL CLIENTE:"<<endl;
            cout << "Numero de tarjeta: " << encriptarTarjeta() << endl;
            cout << "Contrasena: " << encriptarContrasena()<< endl;
        }

        //Método para verificar autenticidad
        bool autenticar(string tarjeta, string pass) {
            return numeroTarjeta == tarjeta and contrasena == pass;
        }
};

int main() {
    //Instancia de clase derivada
    ClienteSeguro cliente("Juan Perez", "Av. Ejercito 1010", 5000.00, "1234567890", "abc123");

    //Se encripta datos del cliente
    cliente.encriptarTarjeta();
    cliente.encriptarContrasena();

    //Se muestra datos encriptados
    cliente.mostrarEncriptacion();

    //Creación de variables para el ingreso por teclado
    string tarjeta, pass;
    cout << "Ingrese numero de tarjeta: ";
    cin >> tarjeta;
    cout << "Ingrese contrasena: ";
    cin >> pass;

    //Se verifica que los datos sean correctos
    if (cliente.autenticar(tarjeta, pass)) {
        cout << "Autenticacion exitosa" << endl;
        //Se muestra los datos reales del cliente
        cliente.mostrarDatos();
    } else
        cout << "Autenticacion fallida" << endl;

    return 0;
}
