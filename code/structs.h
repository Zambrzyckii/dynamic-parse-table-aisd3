#ifndef STRUCTS_H
#define STRUCTS_H
struct Node {
    int value = -1;
    Node** children = nullptr;
    ~Node(){
};
};

#endif //STRUCTS_H
