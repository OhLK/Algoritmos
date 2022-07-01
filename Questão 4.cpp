#include <iostream>
#include <math.h>
using namespace std;

struct Hospital
{
    int id = 0, casos = 0;
};
struct Heap 
{
    Hospital *ref;
    int pos = 0, tt = 0;
};
bool comparador(Hospital esq, Hospital dir);
Heap bubbleDown(int p, Heap heap, int *vet, int tam);
Heap bubbleUp(int p, Heap x, int *vet);
Heap buildHeap(int tam, Heap heap, int *vet);

int main()
{
    Heap vector;
    int tam,id, soma = 0, casos = 0, lk = 0,*vet = NULL;
    string input = "";
    cin >> tam;
    vet = (int*)calloc(tam, sizeof(int));
    vector.ref = (Hospital*)calloc(tam, sizeof(Hospital));
    while(lk !=tam){
            cin >> casos;
            soma += casos, vector.pos++, vector.tt++;
            vet[lk] = lk, vector.ref[lk].id = lk, vector.ref[lk].casos = casos;
            lk++;
    }
    vector = buildHeap(vector.pos, vector, vet);
    while (input != "A")
    {
        cin >> input;
        if (input == "NEW")
        {   
            int id = 0;
            cin >> id;
            cin >> casos;
            tam++;
            vet = (int*)realloc(vet,tam*sizeof(int));
            vet[tam-1] = id, soma += casos;
            if (vector.tt == vector.pos)
            {
                vector.pos *= 2;
                vector.ref = (Hospital*)realloc(vector.ref,sizeof(Hospital) * vector.pos);
                vector.ref[vector.tt].id = id, vector.ref[vector.tt].casos = casos, vector.tt++;
                bubbleUp(vector.tt - 1, vector, vet);
            }else{
                vector.ref[vector.tt].id = id, vector.ref[vector.tt].casos = casos, vector.tt++;
                bubbleUp(vector.tt - 1,vector, vet);
            }
            printf("%d %d\n",vector.ref[0].id,vector.ref[0].casos);
        }
        else if (input == "DEL")
        {
            cin >> id;
            soma -= vector.ref[vet[id]].casos;
            vector.ref[vet[id]].casos = 0;
            bubbleDown(vet[id], vector,vet, tam);
            if (soma != 0)
                printf("%d %d\n",vector.ref[0].id,vector.ref[0].casos);
            if (soma == 0)
               cout << "-1 -1" << endl;    
        }
        else if (input == "IN")
        {   
            cin >> id, cin >> casos;
            vector.ref[vet[id]].casos += casos, soma += casos;
            printf("%d\n",vector.ref[vet[id]].casos);
            bubbleUp(vet[id], vector,vet);
        }
        else if (input == "OUT")
        {
            cin >> id;
            cin >> casos;
            vector.ref[vet[id]].casos -= casos, soma -= casos;
            printf("%d\n",vector.ref[vet[id]].casos);
            bubbleDown(vet[id], vector, vet, tam);
        }
        else if (input == "PAY")
        { 
            int pay, aux, money;
            cin >> pay;
            aux = pay;
            for(int i = 0; pay>0 && vector.ref[0].casos > 0 ;i++,pay--, soma--)
            {
                vector.ref[0].casos--;
                bubbleDown(0,vector,vet, tam);
            }
            money = aux - pay;
            printf("%d\n", money);
        }else if(input == "END"){
            cout << soma << endl;
            input = "A";
        }
    }
    return 0;
}
bool comparador(Hospital esq, Hospital dir){
    if(esq.casos < dir.casos)
        return false;
    else{
        if(esq.casos != dir.casos)
            return true;
        else{
            if(esq.id<=dir.id)
                return false;
            else
                return true;
        }
    }
}
Heap bubbleDown(int p, Heap heap, int *vet, int tam){
    int dir,esq , meio;
    Hospital hep2;
    esq = 2*p + 1;
    dir = 2*p +2;
    meio = p;
    if(esq < tam && comparador(heap.ref[esq], heap.ref[meio]))
        meio = esq;
    if(dir < tam && comparador(heap.ref[dir], heap.ref[meio]))
        meio = dir;
    if(meio != p){
        hep2 = heap.ref[meio];
        heap.ref[meio] = heap.ref[p];
        heap.ref[p] = hep2;
        vet[heap.ref[meio].id] = meio;
        vet[heap.ref[p].id] = p;
        return bubbleDown(meio, heap, vet, tam);
    }
    return heap;
}
Heap bubbleUp(int p, Heap x, int *vet){
    int l = p;
    Hospital help;
    while(l>0 && comparador(x.ref[l], x.ref[(l-1)/2])){
        help = x.ref[l];
        vet[x.ref[l].id] = (l-1)/2;
        vet[x.ref[(l-1)/2].id] = l;
        x.ref[l] = x.ref[(l-1)/2];
        x.ref[(l-1)/2] = help;
        l = (l-1)/2;
    }
    return x;
    
}
Heap buildHeap(int tam, Heap heap, int *vet){

    for (int i = floor(tam/2) - 1; i >=  0; i--)
        heap = bubbleDown(i, heap, vet, tam);
    return heap;
}
