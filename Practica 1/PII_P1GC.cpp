#include <iostream>
#include <vector>
#include <array>
using namespace std;


//Trabajo realizado por Juan Manuel Muñoz del Cerro y Francisco Gonzalez Prieto
//Revisar la clase constructor de Pelicula, al introducir una nueva pelicula da error, y parece que no hay errores.
//El error sucede al llamar al constructor desde el main y introducir los parametros.

class Fecha{

private:

    int dia;
    int mes;
    int anio;

public:

    Fecha():dia(0),mes(0),anio(0){};

    Fecha(int d,int m,int a){

        if(d==31 && (m==1 ||m==3||m==5||m==7||m==8||m==10||m==12)){
            setdia(d);
            setmes(m);
            setanio(a);
        }else if(d==30 && (m==4 ||m==6||m==9||m==11)){
            setdia(d);
            setmes(m);
            setanio(a);
        }else if(d==28 && m==2){
            setdia(d);
            setmes(m);
            setanio(a);
        }

    }

    int getdia()const{
        return dia;
    }

    int getMes()const{
        return mes;
    }

    int getanio()const{
        return anio;
    }

    void setdia(int d){
        dia=d;
    }

    void setmes(int m){


        if(m>0 && m<=12){
        mes=m;
        }else{
            throw string{"Mes no valido"};
        }
    }

    void setanio(int a){

        anio=a;
    }

    void mostrarfecha(){
        cout<<dia<<" / "<<mes<<" / "<<anio;
    }

};

class Premio{

public:

    Premio():descripcionPremio(0),nombre(0){};

    Premio(string des, string nom){
        setDescripcionPremio(des);

        setNombre(nom);

    }

    void setDescripcionPremio(string des){
        descripcionPremio = des;
    }
    string getDescripcionPremio()const{
        return descripcionPremio;
    }


    void setNombre(string nom){
        nombre = nom;
    }
    string getNombre()const{
        return nombre;
    }


    void printPremio(){
        cout << descripcionPremio << " " << nombre << endl;
    }


    void ModificarPremio(string des, string nom){
        setDescripcionPremio(des);
        setNombre(nom);

    }

private:
    string descripcionPremio;
    string nombre;


};

class Pelicula{

 public:

    Pelicula():titulo(""),director(""),apellidodirec(""){};

    Pelicula(string tit, string dir, string ap, Fecha f){

        settit(tit);
        setdir(dir);
        setape(ap);

        //setfecha(f);

        //setpremios(pe);

     }


    string gettit()const{
        return titulo;
    }

    string getdir()const{
        return director;
    }

    string getapelli()const{
        return apellidodirec;
    }

    void settit(string t){

        titulo=t;
    }

    void setdir(string d){

        director=d;
    }

    void setape(string a){
        apellidodirec=a;

    }

    Fecha getfecha()const{
        return fecha;
    }

    void setfecha(Fecha f){
        fecha.setdia(f.getdia());
        fecha.setmes(f.getMes());
        fecha.setanio(f.getanio());


    }

    array<Premio,6> getpre()const{
        return premios;
    }

    void setpremios(array<Premio,6> pe){

          for(int i{0}; i < 6;++i){
            premios.at(i).setDescripcionPremio(pe.at(i).getDescripcionPremio());
            premios.at(i).setNombre(pe.at(i).getNombre());
        }
    }

    void mostrarf(){
        fecha.mostrarfecha();

    }
    void mostrarpremio(){

        for(int i=0;i<premios.size();i++){
            premios.at(i).printPremio();
        }
    }



 private:
    string titulo;
    string director;
    string apellidodirec;
    array<Premio,6>premios;
    Fecha fecha;



};

int main()
{
       Fecha f;
       vector<Pelicula> festival;

       string pelicula;
       string director;
       string apellido;

       //array<Premio,6> premios;

       bool op=false;
       int d;
       int a;
       int m;

       int selec=0;



       while(selec != 4){

           cout << "Elige una de las siguientes opciones:" << endl;
           cout << "1-Incorporar una nueva pelicula al festival" << endl << endl;
           cout << "2-Buscar una pelicula del festival" << endl << endl;
           cout << "3-Mostrar todas las peliculas del festival" << endl << endl;
           cout << "4-Salir" << endl;

           cin >> selec;

           switch(selec){


           case 1:{

               cout<<"Introduce nombre de pelicula:";
               cin>>pelicula;

               for(auto elem:festival){

                   if(elem.gettit()==pelicula){
                       op=true;
                   }

               }


               if(op==false){

                   cout<<"Introduce solo el nombre del director: "<<"\n";
                   cin>>director;

                   cout<<"Introduce su apellido: "<<"\n";
                   cin>>apellido;

                   cout<<"Introduce la fecha de estreno: "<<"\n"<<"Introduce el dia:";
                   cin>>d;
                   f.setdia(d);

                   cout<<"Introduce el mes:"<<"\n";
                   cin>>m;
                   f.setmes(m);

                   cout<<"Introduce el anio:"<<"\n";
                   cin>>a;
                   f.setanio(a);

                   //cout<<"Introduce los premios"<<"\n";

                   /*for(auto elem:premios){
                       string Descri;
                       cin >> Descri;
                       string nom;
                       cin >> nom;
                       elem.setDescripcionPremio(Descri);
                       elem.setNombre(nom);
                   }*/


                  // Pelicula p(pelicula,director,apellido,f);
                  //festival.push_back(p);


               }

               break;
           }
           case 2:{

               cout<<"¿Que deseas buscar?";
               cin>>pelicula;

               if(festival.size()==0){
                   cout<<"No se ha encontrado nada "<<endl;
               }else{

                   for(auto elem:festival){

                       if(elem.gettit()==pelicula){
                           cout<<elem.gettit()<< "Director"<<elem.getdir()<<elem.getapelli();
                           cout<<"Fecha :";
                            elem.mostrarf();
                           cout<<"\n"<<"Premios:";
                            elem.mostrarpremio();
                           cout<<"\n";
                       }else{
                           cout<<"No se ha encontrado nada ";
                       }

                   }


               }


               break;

           }
           case 3:{

               if(festival.size()==0){
                   cout<<"No hay peliculas disponibles"<<endl<<endl;
               }else{

                   for(int i=0;i<festival.size();i++){
                       cout<<festival.at(i).gettit()<< "Director"<<festival.at(i).getdir()<<festival.at(i).getapelli();
                       cout<<"Fecha :";
                        festival.at(i).mostrarf();
                       cout<<"\n"<<"Premios:";
                       festival.at(i).mostrarpremio();
                       cout<<"\n";
                   }

               }

              break;
           }
           default:{
               cout << "OPCION NO VALIDA";
               break;
           }

         }
       }


}
