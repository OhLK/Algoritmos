#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct local{
    int coord1 = 0;
    int coord2 = 0;
    int m = 0;
    int d2;
};
struct Jogo{
    int lado;
    double size;
    int fase;
};

void escopo(int pos, int linhas,vector <Jogo> p[]);
double papito(local lk[], int p, int p2);

int main (){

    int teste;
    int estruturas;
    int qtmoeda, coins, vizitos, valor = 0;
    int opr;
    int meta = 0;
    cin >> teste;
    while(teste){
        cin >> estruturas;
        local lk[estruturas];vector <Jogo> jogo[estruturas];
        for (int i = 0; i < estruturas; i++){cin >> lk[i].coord1 >> lk[i].coord2;}cin >> qtmoeda;
        for (;meta < qtmoeda;)
        {
            cin >> coins;
            lk[coins].m = 1; meta++;
        }
        for(int i = 0; i < estruturas; i++){
            cin >> opr;
            for (int j = 0; j < opr; j++)
            {
                cin >> vizitos;
                Jogo pk;
                pk.lado = vizitos;
                pk.size = papito(lk,i,vizitos);jogo[i].push_back(pk);
            }
        }
        escopo(0,estruturas,jogo);
        printf("\n");teste --;meta = 0;
    }

}

void escopo(int pos, int parametro, vector <Jogo> p[]){

    int guia[parametro];
    int way[parametro];
    int s  = 0;double v[parametro], vet2[parametro];
    for (int i = 0; i < parametro; i++){guia[i] = -1;vet2[i] = INT_MAX;}
    vet2[pos] = 0;
    for (int i = 1; i < parametro; i++)
    {
       for (int j = 0; j < parametro; j++)v[j] = vet2[j];
            
       for (int j = 0; j < parametro; j++)
       {
           for (int k = 0; k < p[j].size(); k++)
           {
             int lado = p[j][k].lado;
             double peso = p[j][k].size;
                if((v[j] + peso) < vet2[lado]){
                    vet2[lado] = v[j]+peso;
                    guia[lado] = j; 
                }
           }   
       }  
    }
    for(int i = 0; i < parametro; i++){
        for (int j = 0; j < p[i].size(); j++){
             int lado = p[i][j].lado;double peso = p[i][j].size;
                if((vet2[i] + peso) < v[lado]){
                    printf("LOOP");
                    return;
                }
        }
    }
    cout << vet2[parametro-1] << " ";
    for (int i = parametro-1; i < parametro;)
    {
        way[s] = i;i = guia[i];s++;
        if(i == 0){
            s--;
            break;
        }
    }
    printf("0 ");
    while(s > -1){

        if(s != 0){
            s--; cout << way[s+1] << " ";

        }else{
            s--;printf("%d",way[s+1]); 
        } 
        

    }
}
double papito(local lk[],int p, int p2){
    double papi; 
    papi = pow((lk[p2].coord1 - lk[p].coord1),2) + pow((lk[p2].coord2 - lk[p].coord2),2);if (lk[p2].m == 1)papi *= -1;
    return papi;
}
