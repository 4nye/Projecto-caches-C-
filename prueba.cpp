#include<iostream>
#include<fstream>
#include<stdlib.h>
#define n 1000 //variar el n si el archivo contiene mas de 1000 números

using namespace std;

 void cdirect(int x[], int y, ofstream &result);    
 void asosiativa(int x[], int y, ofstream &result);
 void casosiativa(int x[], int y, ofstream &result);

int main(){
 int cant=0, sec[n];
 ifstream arch;
 ofstream tablas;

  arch.open("dm.txt",ios::in);
  tablas.open("tablas.txt",ios::out);
 

    if(arch.fail()){
        cout<<"error en el archivo";
        //si salta este error cree un archivo de texto llamado dm.txt e introduzca las direcciones de memoria de forma manual
        exit(1);
    }

    while(!arch.eof()){
      arch>>sec[cant];
      cant+=1; 
    }
   
   cdirect(sec, cant, tablas);
   asosiativa(sec,cant,tablas);
   casosiativa(sec,cant,tablas);
   arch.close();
   tablas.close();
}

 void cdirect(int x[], int y, ofstream &result){
    int mods[n], blocks, val;
    

     if(result.fail()){
        cout<<"error en el archivo";
        exit(1);
     }
     result<<"[Correspondecia Directa]"<<endl;
 
   do{
    cout<<"[Correspondencia Directa]"<<endl<<"Ingrese el numero de bloques de la cache"<<endl;
    cin>>blocks;
    system("cls");
   } while (blocks<1);
   
   
   
   result<<"| D.bloques |"<<"| Acc |";       
     for(int i=0; i<blocks; i++){
            mods[i]=-1;
            
            result<<"|    "<<i<<"    |";

    }
    
    result<<endl;

    for( int j=0;j <y-1 ;j++){
         val=x[j]%blocks;
         
        if(x[j]<10){
        
         result<<"|    "<<x[j]<<"      |";
        }
        else{
            if(x[j]<99){
            
            result<<"|    "<<x[j]<<"     |";

            }
            else{
                
                result<<"|    "<<x[j]<<"    |";
            }
        }

         if(mods[val]!=x[j] || mods[val]==-1){
            
            result<<"|  F  |";
            mods[val]=x[j];
         }
         else{
            
            result<<"|  A  |";
         }
        
        for (int i=0; i<blocks;i++){
        
        if(mods[i]==-1){
         
          result<<"|         |";
        }
        else{
            if( mods[i]<10){
            
            result<<"|  M["<<mods[i]<<"]   |";
            }
            else{
                if(mods[i]<99){
                     
                     result<<"| M["<<mods[i]<<"]   |";
                }
                else{

                     
                     result<<"| M["<<mods[i]<<"]  |";
                }
            
            }
        }
        }
        
      
        result<<endl;

    }
    result<<endl;
}  
 void asosiativa(int x[], int y, ofstream &result){
 int mods [n][2], hits[n], conj,val,ac;

   if(result.fail()){
        cout<<"error en el archivo";
        exit(1);
     }
      result<<"[Asociativa por Conjuntos]"<<endl;
    do{
     cout<<"[Asociativa por Conjuntos]"<<endl<<"Ingrese el numero de conjuntos disponibles (al menos 2)"<<endl;
     cin>>conj;
     system("cls");
   } while (conj<2);
  
   result<<"| D.bloques |"<<"| Acc |";       
     for(int i=0; i<conj; i++){
         hits[i]=-1;
         result<<"|    "<<i<<"    |"<<"|    "<<i<<"    |";
        for(int j=0;j<2;j++){
            mods[i][j]=-1;
         }
    }
    
    result<<endl;
    
     for( int j=0;j <y-1 ;j++){
        ac=0;
        val=x[j]%conj;
         
     if(x[j]<10){
        
          result<<"|    "<<x[j]<<"      |";
     }
        else{
            if(x[j]<99){
            
             result<<"|    "<<x[j]<<"     |";

        }
           else{
                
               result<<"|    "<<x[j]<<"    |";
           }
       }
       

          for(int k=0; k<2;k++){
             if(mods[val][k]==x[j]){
                  result<<"|  A  |";
                 hits[val]=x[j];
                ac=1;
             }
             
          }
         if(ac==0){
          result<<"|  F  |";
                 if(mods[val][0]==hits[val]&&mods[val][0]!=-1){
                 mods[val][1]=x[j];
                 }
                  else{
                      mods[val][0]=x[j];
                  }
                  hits[val]=x[j];
          }

         
          for (int i=0; i<conj;i++){
             for(int j=0;j<2;j++){
        if(mods[i][j]==-1){
         
          result<<"|         |";
        }
        else{
            if( mods[i][j]<10){
            
            result<<"|  M["<<mods[i][j]<<"]   |";
            }
            else{
                if(mods[i][j]<99){
                     
                     result<<"| M["<<mods[i][j]<<"]   |";
                }
                else{

                     
                     result<<"| M["<<mods[i][j]<<"]  |";
                }
            
            }
        }
             }
        }

          result<<endl;
         }
     
       result<<endl;

}

 void casosiativa(int x[], int y, ofstream &result){
  int mods [n], conj=0, bnd=0, ac=0, mrk=-1;

   if(result.fail()){
        cout<<"error en el archivo";
        exit(1);
     }
      result<<"[Completamente Asociativa por Conjuntos]"<<endl;
    do{
     cout<<"[Completamente Asociativa por Conjuntos]"<<endl<<"Ingrese el numero de conjuntos disponibles"<<endl;
     cin>>conj;
     system("cls");
   } while (conj<1);
    conj*=4;
    result<<"| D.bloques |"<<"| Acc |";       
     for(int i=0; i<(conj); i++){
            mods[i]=-1;
            
            result<<"|    "<<i<<"    |";

    }
    
    result<<endl;

    for( int j=0;j <y-1 ;j++){
         
        
        if(x[j]<10){
        
         result<<"|    "<<x[j]<<"      |";
        }
        else{
            if(x[j]<99){
            
            result<<"|    "<<x[j]<<"     |";

            }
            else{
                
                result<<"|    "<<x[j]<<"    |";
            }
        }
      
           while(mods[ac]!=-1 && bnd!=1 && ac<conj){
                  if(mods[ac]==x[j]){
                     result<<"|  A  |";
                     bnd=1;
                  }
                  ac+=1;
           }
            
           if(bnd!=1){
               result<<"|  F  |";
               mrk++;
               ac=mrk%conj;
               mods[ac]=x[j];
               }
           
           ac=0;
           bnd=0;
           
           for (int i=0; i<conj;i++){
        
        if(mods[i]==-1){
         
          result<<"|         |";
        }
        else{
            if( mods[i]<10){
            
            result<<"|  M["<<mods[i]<<"]   |";
            }
            else{
                if(mods[i]<99){
                     
                     result<<"| M["<<mods[i]<<"]   |";
                }
                else{

                     
                     result<<"| M["<<mods[i]<<"]  |";
                }
            
            }
        }
        }
         result<<endl;
}
 } 
  
    
