#include <iostream>
using namespace std;

class Clientes{
    public:
        string cliente;
};

class Cuentas{
    public:
        virtual void cargarSaldo() = 0;
        virtual void retirar(float) = 0;
};

class Cta_deb: public Cuentas, public Clientes{
    public:
        float saldo;
        virtual void cargarSaldo() override{
            this->saldo = 0;
        }
        virtual void retirar(float _r) override{
          //Validación implementada para verificar corecto retiro
            if (saldo < _r)
                cout<<"Saldo insuficiente"<<endl;
            else
                this->saldo =saldo -_r;
        }
};

class Cta_cred: public Cuentas, public Clientes{
    public:
        float saldo;
        virtual void cargarSaldo() override{
            this->saldo = 5000;
        }
        virtual void retirar(float _r) override{
            cout<<"Operacion no disponible";
        }
};

int main(){
    Cta_deb cta1;
    cta1.cargarSaldo();
    cout<<"La cuenta tiene saldo: "<<cta1.saldo<<endl;
    cta1.retirar(50);
    cout<<"La cuenta tiene saldo: "<<cta1.saldo<<endl;

    Cta_cred cta2;
    cta2.cargarSaldo();
    cout<<"La cuenta tiene saldo: "<<cta2.saldo<<endl;
    cta2.retirar(50);
    //cout<<"La cuenta tiene saldo: "<<cta2.saldo<<endl;
    //Cuentas cta3;
}
