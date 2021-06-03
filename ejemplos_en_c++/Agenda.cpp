#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Contacto{
  string nombre;
  string apellido;
  string movil;
};
Contacto persona[2];
int contador = 0;

void agregar();
void guardar();
void mostrar();

int main(int argc, char *argv[])
{
    int opcion;
    do{
    cout<<"AGENDA: "<<endl;
    cout<<"1.Agregar."<<endl;
    cout<<"2.Mostrar."<<endl;
    cout<<"0.Salir."<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:
       agregar();
       guardar();
    break;
    case 2:
       mostrar();
    break;
    case 0:
        cout<<"Fin del programa"<<endl;
    break;
    default:
        cout<<"Error en el menu"<<endl;
    break;
    }
    }while(opcion != 0);

    system("PAUSE");
    return 0;
}

void agregar(){
   if( contador < 3){
    cout<<"Nombre: "; cin>> persona[contador].nombre;
    cout<<"Apellido: "; cin>> persona[contador].apellido;
    cout<<"Movil: "; cin>> persona[contador].movil;
    cout<<endl;
    contador++;
   }else{
       cout<<"supero cantidad maxima de contactos(2)"<<endl;
   }

}
void guardar(){
   ofstream archivo;
   archivo.open("Agenda.txt",ios::out);
   if(archivo.is_open()){
    for(int i = 0; i < contador; i++){
    archivo<< persona[i].nombre <<" "<< persona[i].apellido <<" "<< persona[i].movil << endl;
    }
   }
   archivo.close();

}
void mostrar(){
   ifstream archivo_m;
   string texto;
   archivo_m.open("Agenda.txt",ios::in);

   if(archivo_m.fail()){
      cout <<"error archivo no existe";
      exit(1);
   }
   while(!archivo_m.eof()){
    getline(archivo_m,texto);
    cout << texto<<endl;
   }
   archivo_m.close();
}