#include <iostream>
#include <string.h>

using namespace std;

class curso{
    string nombre, codigo;
    int alumno;
    public:
    curso(){
        nombre="o";
        codigo="o";
        alumno=0;
    }
    curso(string nombre, string codigo, int alumno){
        this->nombre=nombre;
        this->codigo=codigo;
        this->alumno=alumno;
    }
    void setNombre(const string nombre){
        this->nombre=nombre;
    }
    void setCodigo(const  string codigo){
        this->codigo=codigo;
    }
    void setNroAlumnos(const int alumno){
        this->alumno=alumno;
    }

    const string getNombre(){
        cout<<"Nombre:\n"<<nombre<<"\n";
        return nombre;
    }
    const string getCodigo(){
        cout<<"codigo:\n"<<codigo<<"\n";
        return codigo;
    }
    const int getNroAlumnos(){
        cout<<"numero de alumnos:\n"<<alumno<<"\n";
        return alumno;
    }
};

int main(){
    curso a;
    curso b("mat","87c7",30);
    string nom, cod;
    int num;

    cout<<"clase a:\n";
    a.getNombre();
    a.getCodigo();
    a.getNroAlumnos();
    cout<<"----------\n";

    cout<<"clase b:\n";
    b.getNombre();
    b.getCodigo();
    b.getNroAlumnos();
    cout<<"----------\n";

    cout<<"ingrese nombre: \n";
    getline(cin,nom);
    a.setNombre(nom);
    a.getNombre();

    cout<<"ingrese codigo: \n";
    getline(cin,cod);
    a.setCodigo(cod);
    a.getCodigo();

    cout<<"ingrese nro alumnos: \n";
    cin>>num;
    a.setNroAlumnos(num);
    a.getNroAlumnos();
    return 0;
}