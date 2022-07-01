#include <iostream>

using namespace std;

struct nud
{
  nud *right = NULL;
  nud *left = NULL;
  int n = 0;
};

nud* inserir(nud *n, int t){

  nud *p = NULL;

  if (n == NULL)
  {
     p = new nud[1];
     p->n = t;
     return p;   
  }else if (t > n->n)
  {
    n->right = inserir(n->right,t);

  }else{

    n->left = inserir(n->left,t);
  }

  return n;
}

nud* rotateE(nud *n){

  nud *r = NULL;
  nud *rl = NULL;

  r = n->right;
  rl = r->left;
  r->left = n;
  n->right = rl;

  return r;
}

nud* rotateD(nud *n){

  nud *r = NULL;
  nud *rd = NULL;

  r = n->left;
  rd = r->right;
  r->right = n;
  n->left = rd;

  return r;
}


int alt(nud *n){

  int altD = 0;
  int altL = 0;
  if (n == NULL)
  {
    return 0;
  }

  altL = alt(n->left);
  altD = alt(n->right);
  return 1 + max(altL,altD);
}

void imprimir(nud *n,int *lilk, int tam){

  if (n == NULL)
  {
    return;
  }
  
  imprimir(n->left,lilk,tam);
  imprimir(n->right,lilk,tam);

  if (*lilk < tam)
  {
    cout << n->n << " ";
    *lilk = *lilk + 1;
  }else{
    cout << n->n;
  }
  
  

}

nud* et1(nud *n, int *kl){

  if(n == NULL){

    return n;
  }

  while(n->right != NULL){

    n = rotateE(n);
    *kl = *kl + 1;
  }
  n->left = et1(n->left, kl); 
  
  return n;

}
nud* et2(nud *n, int *kl, int *lk2){

  int LK; 

  if (n == NULL)
  {
    return n;
  }
  
  if(n->right == NULL){

    cin >> LK;
    while(n->n != LK){

      n = rotateD(n);
      *lk2 = *lk2 + 1;
    } 
  
  }else{

    cin >> LK;
    while(n->n != LK){

      n = rotateE(n);
      *kl = *kl + 1;
    } 

  }

  n->left = et2(n->left,kl,lk2);
  n->right = et2(n->right,kl,lk2);

  return n;
}

void avl(nud *n, bool *rt){

  if (alt(n->right) - alt(n->left) > 1 || alt(n->right) - alt(n->left) < -1 )
  {
    *rt = false;
  }
  if (n->left != NULL)
  {
    avl(n->left, rt);  
  }
   if (n->right != NULL)
   {
      avl(n->right, rt);
     
   }

  return ;
}
int main(){

  
  int tam = 0;
  

  while(scanf("%d", &tam) != EOF){
  int lilk = 1;
  int kl = 0, lk2 = 0;
  int vall = 0;
  bool tl = true;
  nud *n = NULL;

  for (int i = 0; i < tam; i++)
  {
    cin >> vall;
    n = inserir(n,vall);
  }
  n = et1(n,&kl);
  n = et2(n,&kl,&lk2);
  cout << kl << " " << lk2 << endl;
  imprimir(n,&lilk,tam);
  avl(n,&tl);
  if (tl == true)
  {
    cout << endl << "true" << endl << endl;
  }else
    cout << endl << "false" << endl << endl;
  }

  return 0;
}
