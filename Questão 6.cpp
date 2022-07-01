#include <iostream>
using namespace std;
int backT(int input, int qtd, int total, int soma, int P[], int min, int &item, int &casos);
int main() {
    int input, input2, minimo, money, *vet = NULL, result = 0, parametro, item;
    scanf("%d",&input);
    while (input != 0) {
        parametro = 0; item = 0; cin >> input2; 
        vet = (int*)calloc(input2,sizeof(int));
        for (int i = 0; i < input2; i++) {
            cin >> vet[i];}
        cin >> minimo >> money;
        if (minimo == parametro){
            parametro++;
        }
        parametro = backT(0, input2, money, 0, vet, minimo, item, parametro);
        cout << "caso " << result << ": " << parametro << endl; result++; input--;
    }
    return 0;
}
int backT(int input, int tudo, int total, int s, int vet[], int minimo, int &tentativas, int &resultados) {
    
    if (input == tudo){ 
        return 0;
    }
    else{
        if (s + vet[input] <= total){
            tentativas++;
        if (tentativas >= minimo){
            resultados++;
        }
        if(input+1 != tudo){
            backT(input+1, tudo, total, s + vet[input], vet, minimo, tentativas, resultados);
        }
        tentativas--;
    }        
    }
    if (input+1 != tudo)
    {
        backT(input+1, tudo, total, s, vet, minimo, tentativas, resultados);
    }
        return resultados;
}
