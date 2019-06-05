#ifndef __PRQUADTREE__
#define __PRQUADTREE__

#include "node.hpp"
class PRQuadtree
{
    public:
        // Constructor
        PRQuadtree(float left, float width, float down, float height, int maxDepth);
        
        // Destructor.
        ~PRQuadtree();

        void insert(Point *);
       
        Node *getLeafAt(float x, float y)  const;
      
        //Return the node if found, else null (0).
        Node *find(Point *) const;

        Node *root;

        const int maxDepth;
};

#endif