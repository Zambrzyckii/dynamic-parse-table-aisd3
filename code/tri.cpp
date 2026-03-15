#include "TRI.h"
#include "Structs.h"
#include "Functions.h"
TRI::TRI(int n, int k)
    : RootSize(n), ChildSize(k) {
    Root = new Node;
}

TRI::~TRI() {
    Clean(0, Root);
}

TRI::TRI(const TRI& other) {
    RootSize = other.RootSize;
    ChildSize = other.ChildSize;
    Root = new Node(*other.Root);
}

TRI& TRI::operator=(const TRI& other) {
    if (this == &other)
        return *this;

    delete Root;
    RootSize = other.RootSize;
    ChildSize = other.ChildSize;
    Root = new Node(*other.Root);
    return *this;
}

int TRI::WielkoscRozgalezienia(int g) const {
    return (g == 0 ? RootSize : ChildSize);
}

void TRI::Clean(int g, const Node* w) {
    if (!w) return;

    int r = WielkoscRozgalezienia(g);
    if (CzyMaDzieci(w)) {
        for (int i = 0; i < r; ++i) {
            Clean(g + 1, w->children[i]);
        
}
        delete[] w->children;
    
}

    delete w;
}
