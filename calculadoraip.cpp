#include<iostream>
#include<sstream>
#include<math.h>
#include <bitset>



using namespace std;



int main(){
    //Variables
    string ip;
    double ipsegmentada[4];
    string ipbinario[4];
    //Solicitar datos
    cout << "Indicame su direccion IP: " << endl; cin >> ip;



   //Tratado de datos a un array unidimensional
    string delimitador;
    stringstream delimitador2(ip);
    int x = 0;
    while (getline(delimitador2, delimitador, '.'))
    {
        ipsegmentada[x] = stoi(delimitador);
        x++;
    }



   // Pasar a binario la IP
    for (int i = 0; i < 4; i++)
    {
        ipbinario[i] = bitset<8>(ipsegmentada[i]).to_string();
        cout << ipbinario[i] << endl;
    }
    
    
    // Mascara
    double mascara[32];
    double mascaraascii[4]{0,0,0,0};
    int subred;
    cout << "Dame una mascara de red: "; cin >> subred;
    // Pasar la mascara a banario
    for (int i = 0; i < 32; i++) {
        if (i < subred) {
            mascara[i] = 1;    
        } else {
            mascara[i] = 0;
        }
    }
    // Pasar la mascara a decimal
    for (int i = 0; i < 4; i++){
        for (int j = 8 * i; j < (8 * i + 8); j++)
        {
            if (mascara[j] == 1)
            {
                mascaraascii[i] += pow(2, (8 * i + 7) - j);
            }
        }
    }



   int clase = stoi(ipbinario[0].substr(1, 1));
    int clase2 = stoi(ipbinario[0].substr(1, 2));
    switch (clase)
    {
    case 0:
        cout << "Clase a" << endl;
        break;
    case 1:
        switch (clase2)
        {
        case 10:
            cout << "Clase b" << endl;
            break;
        default:
            cout << "Clase c" << endl;
            break;
        }
    break;
    default:
        break;
    }
    
    if (subred <= 8)
    {
        cout << "Hay " << pow(2 , 8 - subred) << " bits prestados" << endl;
    } else if (subred <= 16){
        cout << "Hay " << pow(2 , 16 - subred) << " bits prestados" << endl;
    } else if (subred <= 24){
        cout << "Hay " << pow(2 , 24 - subred) << " bits prestados" << endl;
    } else {
        cout << "Hay " << pow(2 , 32 - subred) << " bits prestados" << endl;
    }
    
    



   cout << endl;
    



}