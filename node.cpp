#include "node.hpp"

//public Constructor root
Node::Node(float l, float w, float d, float h)
:   left(l), width(w), down(d), height(h), isLeaf(true), depth(0), len(0)
{}

//Private Constructor, creating node.
Node::Node(int de, float l, float w, float d, float h)
:   left(l), width(w), down(d), height(h), isLeaf(true), depth(de), len(0)
{}

//Recursive destructor.
Node::~Node()
{
    if ( !isLeaf ){
        for (int e = START_CHILD; e <= END_CHILD; e++)
            delete child[e];
    }else{
        if (len)
            delete[] val;
    }

}

// Get Methods
float Node::getDown()   const { 
    return down;   
}

float Node::getLeft()   const { 
    return left;   
}

float Node::getWidth()  const { 
    return width;  
}

float Node::getHeigth() const { 
    return height; 
}

float Node::getDepth()  const { 
    return depth;  
}


Node * Node::getChild(int e) const {
    assert( !isLeaf ); 
    return child[e]; 
}

bool Node::hasChildren() const { 
    return !isLeaf; 
}


//Checks if point is in node.
bool Node::isInNode(Point *point) const {
    assert( isLeaf );

    for (int i = 0; i < len; i++){
        if (val[i] == point)
            return true;
    }

    return false;
}

//Checks if point (x, y) is inside region.
bool Node::isInRegion(float x, float y) const{
    return ((x >= left) &&  (x < left + width) && (y >= down) && (y < down + height));
}

//Adds a point to node.
void Node::addValue(Point *point){
    assert( isLeaf );

    Point **pointTemp = new Point *[len + 1];

    for (int i = 0; i < len; i++)
        pointTemp[i] = val[i];

    pointTemp[len] = point;

    if ( len > 0 )
        delete[] val;

    val = pointTemp;
    len++;
}

int Node::getLen() const { 
    assert( isLeaf );
    return len; 
}

Point ** Node::getVal() const { 
    return val; 
}

//Subdivides the region and puts the corresponding values in children's region.
void Node::subdivide()
{

    Node *newChild[4] =
    {
        //NE 
        new Node(depth + 1, left + width/2.0f, width/2.0f,   down + height/2.0f, height/2.0f),
        //NW 
        new Node(depth + 1, left, width/2.0f, down + height/2.0f, height/2.0f),
        //SW 
        new Node(depth + 1, left, width/2.0f, down, height/2.0f),
        //SE 
        new Node(depth + 1, left + width/2.0f, width/2.0f, down, height/2.0f)
    };

    for(int i = 0; i < len; i++){
        for (int e = START_CHILD; e <= END_CHILD; e++){
            if ( newChild[e]->isInRegion(val[i]->getX(), val[i]->getY()) )
                newChild[e]->addValue(val[i]);
        }
    }

    //All values are copied, remove original values.
    if (len)
        delete[] val;

    isLeaf = false;

    for (int e = START_CHILD; e <= END_CHILD; e++)
        child[e] = newChild[e];
}


