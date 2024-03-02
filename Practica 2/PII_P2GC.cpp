#include <iostream>
#include <vector>

using namespace std;

//Trabajo realizado por Juan Manuel Muñoz y Francisco Gonzalez Prieto

class CVector{

private:

    int size;
    vector<float> nums;

public:

    CVector(): size(0){}

    CVector(int siz){
        setSize(siz);

    }
  /*  CVector(const int & siz){
        size = siz;
    }*/

   int getSize() const{
        return size;
    }

   int getNum(int pos) const{
       try{
       return nums.at(pos);
       }catch(exception e){
           throw 1;
       }
   }

   void setNum(float num , int pos){
       try {
          nums.at(pos) = num;
       }  catch (exception ex) {
            throw 2;
       }

   }

   void setSize(int siz){
       size = siz;
       nums.resize(siz);
   }



};

CVector operator -(const CVector &c1, const CVector &c2){
        try{
        CVector resta(c1.getSize());
        for(int i=0;i<c1.getSize();i++){
            resta.setNum(c1.getNum(i)-c2.getNum(i),i);

        }
        return resta;

       }catch(exception exc){
        throw 3;
    }

   }

CVector operator --( CVector &c1,int){


    for(int i=0;i<c1.getSize();i++){
        c1.setNum(c1.getNum(i)-1,i);
    }

    return c1;
}


bool operator !=(const CVector &c1, const CVector &c2){

        try{
        for(int i=0;i<c1.getSize();i++){
            if(c1.getNum(i) != c2.getNum(i)){
                return false;
            }else{
                return true;
            }

         }
    }catch(exception exce){
        throw 4;
    }
}


int main()
{

    int num;
    int numv;
    int numersv;
    do{
               cout << "Menu"<< endl;
               cout << "Selecciona una opción:"<< endl;
               cout <<"1. Restar dos vectores componente a componente"<< endl;
               cout << "2. Decrementar cada componente del vector."<< endl;
               cout << "3. Comparar dos vectores por desigualdad."<< endl;
               cout << "0. FIN" << endl;
               cin>>num;


               if(num==1){

                   cout<<"Cuantos numeros deseas introducir en cada vector:";
                   cin>>numersv;
                   cout<<"Introduce los numeros del primer vector:";
                   cout<<"\n";
                   CVector c1(numersv);
                   CVector c2(numersv);
                   CVector res(numersv);
                   for(int i=0;i<numersv;i++){
                       cout<<"Introduce un numero:";
                       cin>>numv;
                       c1.setNum(numv,i);

                   }
                   cout<<"\n";
                   cout<<"Introduce los numeros del segundo vector:";
                   cout<<"\n";
                   for(int j=0;j<numersv;j++){
                       cout<<"Introduce un numero:";
                       cin>>numv;
                       c2.setNum(numv,j);

                   }
                   cout<<"\n";
                   res=c1-c2;
                   cout<<"Vector 1:";
                   cout<<"\n";
                   for(int l=0;l<numersv;l++){

                       cout<<c1.getNum(l)<<",";
                   }
                    cout<<"Vector 2:";
                    cout<<"\n";
                   for(int r=0;r<numersv;r++){

                       cout<<c2.getNum(r)<<",";
                   }
                   cout<<"\n";
                   cout<<"Vector resta:";
                   cout<<"\n";
                   for(int k=0;k<numersv;k++){

                       cout<<res.getNum(k)<<",";
                   }
                   cout<<"\n";

               }else if(num==2){

                   cout<<"Cuantos numeros deseas introducir en cada vector:";
                   cin>>numersv;
                   cout<<"Introduce los numeros del primer vector:";
                   cout<<"\n";

                   CVector c1(numersv);

                   CVector c2(numersv);

                   for(int i=0;i<numersv;i++){
                       cout<<"Introduce un numero:";
                       cin>>numv;
                       c2.setNum(numv,i);

                   }

                   cout<<"Vector Introducido:";
                   cout<<"\n";
                  for(int i=0;i<numersv;i++){

                      cout<<c2.getNum(i)<<",";
                  }

                   c1=c2--;


                   cout<<"\n";
                   cout<<"Vector Final:";
                   cout<<"\n";
                  for(int r=0;r<numersv;r++){

                      cout<<c1.getNum(r)<<",";
                  }

                   cout<<"\n";


               }else if(num==3){

                   cout<<"Cuantos numeros deseas introducir en cada vector:";
                   cin>>numersv;
                   cout<<"Introduce los numeros del primer vector:";
                   cout<<"\n";

                   CVector c1(numersv);
                   CVector c2(numersv);
                   bool res;

                   for(int i=0;i<numersv;i++){
                       cout<<"Introduce un numero:";
                       cin>>numv;
                       c1.setNum(numv,i);

                   }
                   cout<<"\n";
                   cout<<"Introduce los numeros del segundo vector:";
                   cout<<"\n";
                   for(int j=0;j<numersv;j++){
                       cout<<"Introduce un numero:";
                       cin>>numv;
                       c2.setNum(numv,j);

                   }
                   cout<<"\n";
                   res=c1!=c2;

                   cout<<"Vector 1:";
                   cout<<"\n";
                   for(int l=0;l<numersv;l++){

                       cout<<c1.getNum(l)<<",";
                   }
                    cout<<"Vector 2:";
                    cout<<"\n";
                   for(int r=0;r<numersv;r++){

                       cout<<c2.getNum(r)<<",";
                   }
                   cout<<"\n";
                   cout<<"Solución de la operción:";
                   cout<<"\n";

                   cout<<res;
                   cout<<"\n";
               }


    }while(num!=0);

    return 0;
}
