#include <iostream>
#include <cstring>

using namespace std;

struct som{
    string nome;
    int tempo = 0;
    int tempoT = 0;
    int chave = -1;
};

struct listahash{
    int tam = 0.0;
    int ocup = 0.0;
    som *music;
};


int hashchave(string musica){

  
 int tam = musica.size();
 int key = 0;

 for (int i = 0; i < tam; i++)
 {
     int n = musica[i];
     key += n * i;
 }
    return key;
}

int Fhash(listahash *hash, som musica){

    int key = hashchave(musica.nome); 
    int H0, flagg = 1;
    H0 = key % (hash->tam);
    int aux = H0;
    int i = 1;

    while (hash->music[aux].chave != 0){
        
        aux = (H0 + i) % hash->tam;
        i++;

    }
    return aux;
}

int inserir(listahash *hash, som musica){
    
    int posi = Fhash(hash,musica);
    hash->music[posi] = musica;
    hash->ocup += 1;
    return posi;
}

void rehash(listahash *hash){

    listahash hash2;
    int tam = (hash->tam * 2) +1;
    hash2.music = (som*)calloc(tam,sizeof(som));
    hash2.tam = tam;
    for (int i = 0; i < hash->tam; i++)
    {   
        if (hash->music[i].chave != 0)
            inserir(&hash2,hash->music[i]); 
    }
    free(hash->music);
    *hash = hash2;
}


int main(){

    som musica, buscar;
    int tam, pos;
    string entrada = " ";
    listahash hash;

    cin >> tam;
    hash.tam = tam;
    hash.music = (som*) calloc(tam, sizeof(som));

    while(entrada != "END"){

        cin >> entrada;

        if (entrada == "ADD")
        {     
                    
            if (hash.ocup - 1 >= hash.tam / 2)
            {
                rehash(&hash); 
            }
            cin >> musica.nome >> musica.tempo;
            pos = inserir(&hash, musica);
            cout << musica.nome << " " << pos << endl;

        }
        if (entrada == "PLAY")
        {      
            int k, p;
            bool flag = false;
            cin >> musica.nome;
            k = hashchave(musica.nome);
            int i = 0;
            while (flag != true)
            {   
                p = (k + i) % hash.tam;
                if (musica.nome == hash.music[p].nome)
                {   

                    hash.music[p].tempoT +=  hash.music[p].tempo;
                    cout << musica.nome << " " << hash.music[p].tempoT << endl;
                    flag = true;
                }
                i++;
            }
        }
        
        if(entrada == "TIME")
        {
            int k, p;
            bool flag = false;
            cin >> musica.nome;
            k = hashchave(musica.nome);
            int i = 0;
            while (flag != true)
            {   
                p = (k + i) % hash.tam;
                if (musica.nome == hash.music[p].nome)
                {
                    cout << musica.nome << " " << hash.music[p].tempoT << endl;
                    flag = true;
                }
                i++;
            }
        }
    }

}
