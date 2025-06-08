#include<iostream>
using namespace std;

int busqueda_posicion_mayor(int x[], int n)
{
   int i, mayor=0, posicion_del_mayor;

for ( i = 0; i < n; i++)
{
    if (x[i]>mayor)
    {
        mayor=x[i];
        posicion_del_mayor=i;
    }
    
}

return posicion_del_mayor; 
}

int busqueda_posicion_menor(int x[], int n)
{
   int i, menor=100;

for ( i = 0; i < n; i++)
{
    if (x[i]<menor)
    {
        menor=x[i];
        posicion_del_menor=i;
    }
    
}

return posicion_del_menor; 
}

void imprimir_alias(string nombres[], int x[], int n)
{
    int i,menor=999,posicion_menor;
    string nombremenor;
    
    
    for ( i = 0; i < n; i++)
    {
        if (x[i]<menor)
        {
            menor=x[i];
            nombremenor=nombres[i];
        }
        
    }
    
    
cout<<"5) El jugador de menor de edad es el jugador "<<nombremenor<<endl;


}

float promediomuertes(int x[], float n){

int i;

float promedio=0;

for ( i = 0; i < n; i++)
{
    promedio=promedio+x[i];
}

promedio=promedio/n;

return promedio;

}




int main(){



int n,i,sumabajas=0,sumaminutos=0,totalbajas100_200=0;

cout<<"Bienvenido a la recopilacion del juego Quake 3 Arena"<<endl;

cout<<endl;

cout<<"Cuantas personas desea registrar informacion del juego?"<<endl;
cin>>n;

int asesinatos[n],armas[n],bajas[n],edad[n],minutos[n];
string alias[n];

for ( i = 0; i < n; i++)
{
    cout<<"Ponga el alias del jugador "<<i+1<<endl;
    cin>>alias[i];

    cout<<"Ingrese cuantos asesinatos hizo el jugador "<<alias[i]<<endl;
    cin>>asesinatos[i];

    cout<<"ingrese cuantas armas utilizo el jugador "<<alias[i]<<endl;
    cin>>armas[i];

    cout<<"Ingrese el numero de bajas que tuvo el jugador "<<alias[i]<<endl;
    cin>>bajas[i];

    sumabajas=sumabajas+bajas[i];

    cout<<"Ingrese la edad del jugador "<<alias[i]<<endl;
    cin>>edad[i];

    cout<<"ingrese cuantos minutos estuvo el jugador "<<alias[i]<<endl;
    cin>>minutos[i];
    sumaminutos=sumaminutos+minutos[i];

}

// Empecemos a procesar los datos

cout<<"Estadisticas:"<<endl;

cout<<"1) El jugador que asesino mas enemigos fue "<< alias[busqueda_posicion_mayor(asesinatos,n)] << endl;
cout<<"2) El jugador que tuvo mas bajas, jugo " << minutos[busqueda_posicion_mayor(bajas,n)]<<" minutos"<<endl;


//3- % de muertes de los jugadores que tuvieron entre 100 y 200 minutos jugando.

totalbajas100_200=0;

for(i=0; i<n; i++)
{
    if(minutos[i]>=100 && minutos[i]<=200)
    {
        totalbajas100_200=totalbajas100_200+bajas[i];
    }

}
cout<<"3) El procentaje de muertes de los jugadores que estuvieron jugando entre 100 y 200 minutos fue del "<<((float)totalbajas100_200/(float)sumabajas)*100<<"%"<<endl;

//4-cantidad de asesinatos que tuvo el jugador de mayor edad.

cout<<"4) La cantidad de asesinatos que tuvo el jugador de mayor edad fue: " << asesinatos[busqueda_posicion_mayor(edad,n)]<<endl;

//5-alias del jugador de menor edad.

imprimir_alias(alias,edad,n);

//6-cantidad de muertes en promedio durante el juego

cout<<"6) El promedio de muertes es "<<promediomuertes(bajas,n)<<endl;

//7-edad del jugador que menos asesinatos tuvo durante el juego.
cout<<"7) La edad del jugador con menos asesinatos tiene "<<edad[busqueda_posicion_menor(asesinatos,n)]<<endl;
}
