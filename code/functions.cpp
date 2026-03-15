#include <cstdio>
#include "Functions.h"
bool CzyNull(const Node* w) {
    return w == nullptr;
}

bool CzyPusty(const Node* w) {
    return w->value == -1;
}

bool SprawdzIstnienie(const int& v, const Node* w) {
    return w->value == v;
}

bool CzyMaDzieci(const Node* w) {
    return w && w->children != nullptr;
}

bool SprawdzIstnienieDziecka(int i, const Node* w) {
    return w && w->children && w->children[i];
}

int MOD(int p, int n) {
    return p % n;
}

int DZIELENIE(int p, int n) {
    return p / n;
}

void Znaleziono(const int& v) {
    printf("%d exist\n", v);
}

void NieZnaleziono(const int& v) {
    printf("%d not exist\n", v);
}

void AlokujWezel(int r, Node* w) {
    w->children = new Node*[r];
    for (int i = 0; i < r; i++) w->children[i] = nullptr;
}

void CzyTrzebZaalokowac(int r, Node* w) {
    if (!CzyMaDzieci(w)) {
        AlokujWezel(r, w);
    
}
}
void UtworzDziecko(int i, const Node* r) {
    r->children[i] = new Node;
}
Node* Dziecko(int i, const Node* r) {
    if (!SprawdzIstnienieDziecka(i, r)) {
        UtworzDziecko(i, r);
    
}
    return r->children[i];
}

void CzyszscWezel(Node*& w) {
    delete w;
    w = nullptr;
}

void PrzypiszWartosc(const int& v, Node* w) {
    w->value = v;
}

void WstawDoWezla(const int& poz, const int& v, const int& n, Node* w, const int& k) {
    if (SprawdzIstnienie(v, w)) {
        Znaleziono(v);
        return;
    
}

    if (CzyPusty(w)) {
        PrzypiszWartosc(v, w);
        return;
    
}

    int m = MOD(poz, n);
    int d = DZIELENIE(poz, n);

    CzyTrzebZaalokowac(n, w);
    Node* dziecko = Dziecko(m, w);
    WstawDoWezla(d, v, k, dziecko, k);
}

void Wstaw(int poz, int n, const int& v, int k, Node* r) {
    WstawDoWezla(poz, v, n, r, k);
}

void Szukaj(const int& v, const Node* w, const int& p, const int& n, const int& k) {
    if (CzyNull(w)) return NieZnaleziono(v);
    if (SprawdzIstnienie(v, w)) return Znaleziono(v);
    if (!CzyMaDzieci(w)) return NieZnaleziono(v);

    int m = MOD(p, n);
    int d = DZIELENIE(p, n);

    if (!SprawdzIstnienieDziecka(m, w)) return NieZnaleziono(v);

    Szukaj(v, w->children[m], d, k, k);
}

void Znajdz(const int& v, int p, int n, const Node* r, int k) {
    Szukaj(v, r, p, n, k);
}
bool SprawdzCzyLisc(const Node* w, int n) {
    if (!CzyMaDzieci(w)) return true;
    for (int i = 0; i < n; ++i)
        if (SprawdzIstnienieDziecka(i, w)) return false;
    return true;
}

bool SzukajLewegoLiscia(int n, int k, Node* w, int g, Node*& r, int& i) {
    if (!CzyMaDzieci(w)) return false;

    int rozg = (g == 0 ? n : k);
    for (int j = 0; j < rozg; ++j) {
        if (SprawdzIstnienieDziecka(j, w)) {
            if (SprawdzCzyLisc(w->children[j], k)) {
                r = w;
                i = j;
                return true;
            
} else if (SzukajLewegoLiscia(n, k, w->children[j], g + 1, r, i)) {
                return true;
            
}
        
}
    
}
    return false;
}

void ZmianaZLewymLisciem(Node* w, int g, int n, int k) {
    Node* r = nullptr;
    int i = -1;
    if (SzukajLewegoLiscia(n, k, w, g + 1, r, i)) {
        Node* lisc = r->children[i];
        w->value = lisc->value;
        CzyszscWezel(lisc);
        r->children[i] = nullptr;
    
} else {
        w->value = -1;
    
}
}

bool Usuwanie(int g, int n, Node*& w, const int& v, int k) {
    if (!SprawdzIstnienie(v, w)) return false;

    int rozg = (g == 0 ? n : k);
    if (SprawdzCzyLisc(w, rozg)) {
        CzyszscWezel(w);
    
} else {
        ZmianaZLewymLisciem(w, g, n, k);
    
}
    return true;
}

bool SzukajIUsun(int g, const int& p, int n, Node*& w, const int& v, int k) {
    if (CzyNull(w)) return false;
    if (Usuwanie(g, n, w, v, k)) return true;
    if (!CzyMaDzieci(w)) return false;

    int m = MOD(p, n);
    int d = DZIELENIE(p, n);

    return SzukajIUsun(g + 1, d, k, w->children[m], v, k);
}

void Usun(const int& v, int p, int n, int k, Node*& r) {
    if (!SzukajIUsun(0, p, n, r, v, k)) {
        NieZnaleziono(v);
    
}
}

void Pokaz(int n, const int& k, const Node* w) {
    if (!w) return;
    printf("%d  ", w->value);
    if (!CzyMaDzieci(w)) return;
    for (int i = 0; i < n; ++i) {
        if (SprawdzIstnienieDziecka(i, w)) Pokaz(k, k, w->children[i]);
    
}
}
