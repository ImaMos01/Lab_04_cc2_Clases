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
    void setDatos(){
        cout<<"ingrese nombre: ";getline(cin,nombre);
        cout<<"ingrese codigo: ";getline(cin,codigo);
        cout<<"ingrese nro de alumnos: ";cin>>alumno;
        cin.ignore();
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

class ArregloDeCursos{
    curso *curs;
    int tam;
    public:
    ArregloDeCursos(const curso cursos[], const int tam){ ///constructor
        curs=new curso[tam];
        this->tam=tam;
        for (int i=0; i<tam; i++)
            curs[i]=cursos[i];
    }
    
    ArregloDeCursos(const ArregloDeCursos &o, ArregloDeCursos a[]){ //copia
        a->curs=new curso[o.tam];
        this->tam=o.tam;
        for(int i=0; i<tam; i++)
            curs[i]=a->curs[i];
    }
    ~ArregloDeCursos(){ //delete
        delete[] curs;
    }
    

    void redimensionar(int n){ //cambiar el tamaño del arreglo
        curso *aux=new curso[n]; 
        for (int i=0; i<tam; i++)
            aux[i]=curs[i];
        delete[] curs;
        curs=aux;
        tam=n;
    }
    
    void pushBack(const curso &p){ //agrgar un valor a la ultima posición
        int s=tam+1;
        curso *au=new curso[s]; 
        for (int i=0; i<tam; i++)
            au[i]=curs[i];
        delete[] curs;
        curs=au;
        tam=s;
        curs[tam-1]=p;
    }
    
    void insert(const int poscicion, const curso &p){ //insertar un curso
        for (int i=0; i<tam; i++){
            if(i==poscicion)
                curs[i]=p;
        }
    }
    
    void remove(const int pos){ //eliminar un curso
        for(int i=0; i<tam; i++)
            if(i==pos)
                for(int j=i; j<tam-1; j++)
                    curs[j]=curs[j+1];
        tam--;
    }
    
    const int getsize(){ //tamaño del arreglo
        cout<<"el tamano es: "<<tam<<"\n";
        return tam; 
    }
    void clear(){ //limpiar el arreglo
        delete[] curs;
        curs=new curso[tam];
    }
    void mostrar(){
        cout<<"\n........................\n";
        for(int i=0; i<tam; i++){
            cout<<"-----------\n";
            curs[i].getNombre();
            curs[i].getCodigo();
            curs[i].getNroAlumnos();
            cout<<"-----------\n";
        }
        cout<<"\n........................\n";
    }
};

int main(){
    int tam=2;
    curso arreglo[tam];
    cout<<"llenar el arreglo de cursos:\n";
    for(int i=0; i<2;i++){
        arreglo[i].setDatos();
    }
    ArregloDeCursos a(arreglo,tam);
    ArregloDeCursos b=a;
    cout<<"arreglo copia:\n";
    b.mostrar();
    cout<<"\narreglo original:\n";
    a.mostrar();
    
    cout<<"\nredimensionar a tamaño 3: \n";
    a.redimensionar(3);
    a.mostrar();

    cout<<"\nllenar el curso c\n";
    curso c;
    c.setDatos();
    cout<<"\ninsertar al final:\n";
    a.pushBack(c);
    a.mostrar();
    cout<<"\ninsertar en la posicion 2:\n";
    a.insert(2,c);
    a.mostrar();

    cout<<"\nremover la posicion 1:\n";
    a.remove(1);
    a.mostrar();
    a.getsize();

    cout<<"\nlimpiar arreglo:\n";
    a.clear();
    a.mostrar();
    return 0;
}