#include "Structs.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
bool CzyNull(const Node* w);
bool CzyPusty(const Node* w);
bool SprawdzIstnienie(const int& v, const Node* w);
bool CzyMaDzieci(const Node* w);
bool SprawdzIstnienieDziecka(int i, const Node* w);
bool SprawdzCzyLisc(const Node* w, int n);
int MOD(int p, int n);
int DZIELENIE(int p, int n);
void Znaleziono(const int& v);
void NieZnaleziono(const int& v);
void AlokujWezel(int r, Node* w);
void CzyTrzebZaalokowac(int r, Node* w);
void UtworzDziecko(int i, const Node* r);
Node* Dziecko(int i, const Node* r);
void CzyszscWezel(Node*& w);
void PrzypiszWartosc(const int& v, Node* w);
void WstawDoWezla(const int& poz, const int& v, const int& n, Node* w, const int& k);
void Wstaw(int poz, int n, const int& v, int k, Node* r);
void Szukaj(const int& v, const Node* w, const int& p, const int& n, const int& k);
void Znajdz(const int& v, int p, int n, const Node* r, int k);
bool Usuwanie(int g, int n, Node*& w, const int& v, int k);
void ZmianaZLewymLisciem(Node* w, int g, int n, int k);
bool SzukajLewegoLiscia(int n, int k, Node* w, int g, Node*& r, int& i);
bool SzukajIUsun(int g, const int& p, int n, Node*& w, const int& v, int k);
void Usun(const int& v, int p, int n, int k, Node*& r);
void Pokaz(int n, const int& k, const Node* w);

#endif //FUNCTIONS_H
