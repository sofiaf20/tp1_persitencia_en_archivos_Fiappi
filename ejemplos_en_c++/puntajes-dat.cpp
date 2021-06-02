#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
struct Puntajes{
  string nombre;
  int puntaje;
  string tiempo;
};
void guardar_puntajes();
void recuperar_puntajes();

int main(int argc, char *argv[])
{
    guardar_puntajes();
    recuperar_puntajes();

    system("PAUSE");
    return 0;
}
void guardar_puntajes(){

   ofstream archivo;
   Puntajes alumno[3];
    alumno[1].nombre = "Pepe";
    alumno[2].nombre = "Juana";
    alumno[1].puntaje = 108;
    alumno[2].puntaje = 2315;
    alumno[1].tiempo = "4:16";
    alumno[2].tiempo = "8:42";

   archivo.open("puntajes.dat",ios::binary | ios::out);

   if(archivo.fail()){
      cout <<"error archivo no existe";
      exit(1);
   }
   for(int i = 0; i < 3; i++){
   archivo << alumno[i].nombre<<" "<< alumno[i].puntaje <<" "<< alumno[i].tiempo << endl;
   }
   archivo.close();

}
void recuperar_puntajes(){
   ifstream archivo;
   string texto;
   archivo.open("puntajes.dat",ios::binary | ios::in);

   if(archivo.fail()){
      cout <<"error archivo no existe";
      exit(1);
   }
   while(!archivo.eof()){
    getline(archivo,texto);
    cout << texto;
   }
   archivo.close();
}
