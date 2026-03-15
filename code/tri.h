#include "Structs.h"
#ifndef TRI_H
#define TRI_H
class TRI {
public:
    int RootSize;
    int ChildSize;
    Node* Root;

    TRI(int n, int k);
    ~TRI();

    TRI(const TRI& other);
    TRI& operator=(const TRI& other);

private:
    int WielkoscRozgalezienia(int g) const;
    void Clean(int g, const Node* w);
};

#endif //TRI_H
