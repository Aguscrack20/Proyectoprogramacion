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

float promedio_bajas_15_20(int edad[], int bajas[], int n) {
    int suma = 0, contador = 0;
    for (int i = 0; i < n; i++) {
        if (edad[i] >= 15 && edad[i] <= 20) {
            suma += bajas[i];
            contador++;
        }
    }
    return (contador > 0) ? (float)suma / contador : 0;
}

string alias_mas_armas(string alias[], int armas[], int n) {
    return alias[busqueda_posicion_mayor(armas, n)];
}

float promedio_bajas_menores_20(int edad[], int bajas[], int n) {
    int suma = 0, contador = 0;
    for (int i = 0; i < n; i++) {
        if (edad[i] < 20) {
            suma += bajas[i];
            contador++;
        }
    }
    return (contador > 0) ? (float)suma / contador : 0;
}

float porcentaje_bajas_18_22(int edad[], int bajas[], int n, int total_bajas) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (edad[i] >= 18 && edad[i] <= 22) {
            suma += bajas[i];
        }
    }
    return (total_bajas > 0) ? (float)suma / total_bajas * 100 : 0;
}

int minutos_mas_30_asesinatos(int asesinatos[], int minutos[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (asesinatos[i] > 30) {
            suma += minutos[i];
        }
    }
    return suma;
}

int jugadores_mas_bajas_que_asesinatos(int asesinatos[], int bajas[], int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (bajas[i] > asesinatos[i]) {
            contador++;
        }
    }
    return contador;
}

float porcentaje_mas_asesinatos_que_bajas(int asesinatos[], int bajas[], int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (asesinatos[i] > bajas[i]) {
            contador++;
        }
    }
    return (n > 0) ? (float)contador / n * 100 : 0;
}

void alias_menos_armas(string alias[], int armas[], int n) {
    return alias[busqueda_posicion_menor(armas, n)];
   cout << "15) El jugador que menos armas utilizó fue " <<alias[busqueda_posicion_menor(armas, n)]<<endl;
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

cout << "8) Promedio de bajas de jugadores entre 15 y 20 años: " << promedio_bajas_15_20(edad, bajas, n) << endl;
cout << "9) El jugador que más armas utilizó fue " << alias_mas_armas(alias, armas, n) << endl;
cout << "10) Número promedio de bajas en jugadores menores de 20 años: " << promedio_bajas_menores_20(edad, bajas, n) << endl;
cout << "11) Porcentaje de bajas de jugadores entre 18 y 22 años: " << porcentaje_bajas_18_22(edad, bajas, n, sumabajas) << "%" << endl;
cout << "12) Acumulado de minutos de jugadores con más de 30 asesinatos: " << minutos_mas_30_asesinatos(asesinatos, minutos, n) << endl;
cout << "13) Cantidad de jugadores con más bajas que asesinatos: " << jugadores_mas_bajas_que_asesinatos(asesinatos, bajas, n) << endl;
cout << "14) Porcentaje de jugadores con más asesinatos que bajas: " << porcentaje_mas_asesinatos_que_bajas(asesinatos, bajas, n) << "%" << endl;
alias_menos_armas(alias, armas, n);

}




