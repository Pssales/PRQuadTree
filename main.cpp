#include "prquadtree.hpp"
#include <vector>

using namespace std;

void printInfo(Node * node){
    cout << "----------------" << endl;

    cout << "Depth : " << node->getDepth() << endl;
    cout << "Length : " << node->getLen() << endl;
    for (size_t i = 0; i < node->getLen(); i++)
    {
        cout << "Value : " << node->getVal()[i]->getValue() << endl;
        cout << "x : " << node->getVal()[i]->getX() << endl;
        cout << "y : " << node->getVal()[i]->getY() << endl << endl;
    }

}

int main(){
    
    PRQuadtree prquadtree (0.0, 100.0, 0.0, 100.0, 20);

    Point a (25.0,40.0,10);
    Point b (25.0,80.0,20);
    Point c (60.0,10.0,30);
    Point d (60.0,40.0,40);
    Point e (70.0,30.0,50);
    Point f (70.0,30.0,60);

    prquadtree.insert(&a);
    prquadtree.insert(&b);
    prquadtree.insert(&c);    
    prquadtree.insert(&d);
    prquadtree.insert(&e);
    
    printInfo(prquadtree.find(&a));
    printInfo(prquadtree.find(&c));
    printInfo(prquadtree.find(&d));

    return 0;
}




