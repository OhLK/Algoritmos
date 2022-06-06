#include<iostream>

using namespace std;

struct no{
int pos, val;    
no *next = NULL; 
};

struct corpo{
int tam = 0;
no *body = new no[1];
no *skt = body;
};

struct froom{
int pos, val;
corpo fila;
     
};
struct parek{
no *topo = new no[1];
int cont = 0;
};

struct resto_stk{
int x,  y;
parek LK;
};

corpo saco(int pos ,int val ,corpo A);
froom pula(corpo fila);
parek empilhar(int pos ,int val , parek A);
resto_stk retirar(parek A);
no *find(corpo A , int pos_fila);
corpo arredondar(int pos , int val , corpo A);
froom ex(corpo A);
corpo bubble(corpo A);

int main(){
    
    int prima = 0 , input1 , input2; string input =""; parek  pilha;
    corpo fila ,tipoC; froom fila1,filar;
    scanf("%d",&prima);
    while(input != "END"){ 
        cin >> input;    
        
        if(input =="LOAD"){
         
         cin >> input1 >>input2;
         fila = saco(input1 , input2 , fila);
        }
        
        if(input =="UNLD"){ 
            resto_stk pronto = retirar(pilha);pilha = pronto.LK;
            cout <<"UNLD "<<pronto.x <<endl;
        }
        if(input =="PROC"){
            if(tipoC.tam > 0){
                   
               if(tipoC.body->next->val == 0  ){
                    filar = ex(tipoC); tipoC = filar.fila;
                    pilha = empilhar(filar.pos , filar.val , pilha);
            }       
        }
            if(fila.tam > 0){
                fila1 = pula(fila);
                fila = fila1.fila;
                tipoC = arredondar(fila1.pos , fila1.val , tipoC);
            }
            if(tipoC.tam > 0){  
                tipoC.skt->val -= prima;
                if(tipoC.skt->val < 0){
                    tipoC.skt->val = 0 ;
                }               
                cout<<"PROC " <<tipoC.skt->pos <<" "<<tipoC.skt->val <<endl;
                tipoC = bubble(tipoC);    
            }
            else{
                printf("PROC -1 -1\n");
            }     
        }
    
    }   
    return 0;
}
corpo saco(int pos ,int val ,corpo fila){
    corpo q = fila; no *p = new no[1];
    p->pos = pos;p->val = val;q.skt->next = p ;
    q.skt = p;q.tam += 1; 
    return q;
}
froom pula(corpo fila){
    int val;
    no *p;
    froom del;
    if(fila.tam != 1){
        p = fila.body->next;fila.body->next = p->next;
        p->next = nullptr;del.val = p->val;del.pos = p->pos;
        delete [] p;
        fila.tam -= 1 ;
    
    }
    else {   
         p = fila.body->next;
        fila.body->next = p->next;p->next = NULL;
        del.val = p->val;del.pos = p->pos;
        delete [] p;
        fila.skt = fila.body;fila.tam -= 1 ;
    }
    del.fila = fila;
    
    return del;
}
parek empilhar(int pos ,int val , parek fila){ 
    no *novo = new no[1];  
    novo->val = val; novo->pos = pos ; novo->next =fila.topo->next;
    fila.topo->next = novo; fila.cont--;
    return fila ;
}
resto_stk retirar(parek fila){
    resto_stk excl;
    no *point; point = fila.topo->next;
    fila.topo->next = point->next; point->next = nullptr; excl.y = point->val; excl.x = point->pos;
    delete [] point;
    fila.cont--; excl.LK = fila;
    return excl;
}
no *find(corpo fila, int pos_fila){
    int i = 0;
    no *point = fila.body;
    for(i = 0 ; i < pos_fila ; i++){
        point = point->next;   
    }
    return point;
}
corpo arredondar(int pos , int val, corpo fila){
    no *novo = new no[1];
    novo->val = val; novo->pos = pos;
    if(fila.tam != 0 ){
        novo->next = fila.body->next; fila.skt->next = novo;fila.tam++;
    }
    else{

        novo->next = novo;
        fila.body->next =novo; fila.skt = novo; fila.tam++;
    }
    fila.body->next = novo; fila.skt = fila.skt;
    return fila;
}
froom ex(corpo fila){
    no *point = new no[1]; froom excl;
    if(fila.tam != 1){
        point = fila.body->next;
        fila.body->next = point->next; fila.skt->next =point->next;
        excl.pos = point->pos; excl.val = point->val;
        fila.tam--; excl.fila = fila;
        point->next = nullptr;
        delete [] point;
    }
    else{
        point =fila.body->next;
        point->next = nullptr; fila.body->next = nullptr; fila.skt = fila.body;
        fila.tam--;
        excl.pos = point->pos; excl.val = point->val;
        excl.fila = fila;
        delete [] point;
    }
    return excl;    
}
corpo bubble(corpo A){
    no *point;
    if(A.tam > 1){
        point = A.skt; A.skt = find(A,A.tam - 1); A.body->next = point;
    }
    return A;
}
