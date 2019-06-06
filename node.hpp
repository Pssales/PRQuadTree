#ifndef __NODE__
#define __NODE__

#include <vector> 
#include <assert.h>

#include "point.hpp"
class Node
{
    public:
        // Constructor of root.
        Node(float left, float width, float down, float height);
        ~Node();

        float getDown()   const ;
        float getLeft()   const ; 
        float getWidth()  const ;
        float getHeigth() const ;
        float getDepth()  const ;


        static const int START_CHILD = 0; 
        static const int NE = 0;         
        static const int NW = 1;         
        static const int SW = 2;         
        static const int SE = 3;         
        static const int END_CHILD = 3;   


        Node *getChild(int e) const;

        bool hasChildren() const;

        // Checks for dados in node.
        bool isInNode(Point *) const;

        // Checks if coordinate is inside region.
        bool isInRegion(float, float) const;

        // Subdivides the node and distributes any data stored.
        void subdivide();

        // Adds data to the node.
        void addValue(Point *);
        
        // Return The amount of points in the region.
        int getLen() const;

        Point ** getVal() const;

    private:

        //Private constructor to create non-root node.
        Node(int depth, float left, float width, float down, float height);

        bool isLeaf; 

        // Distance from root.
        const int depth;                      

        // Bounds of region.
        const float left, down, width, height; 
        union
        {
            struct
            {
                Node *child[4];
            };
            struct
            {
                Point **val;
                int len;
            };
        };

};

#endif