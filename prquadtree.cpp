#include "prquadtree.hpp"
#include <list>


PRQuadtree::PRQuadtree(float left, float width, float down, float height, int maxDepth)
:   maxDepth(maxDepth), root(new Node(left, width, down, height))
{}

PRQuadtree::~PRQuadtree(){
    delete root;
}

void PRQuadtree::insert(Point *point){
    Node *nodeTemp = getLeafAt(point->getX(), point->getY());

    nodeTemp->addValue(point);

    if(nodeTemp->getDepth() >= maxDepth)
        return;

    std::list<Node *> list;

    list.push_back(nodeTemp);

    while(!list.empty()){
        nodeTemp = list.back();
        list.pop_back();

        if ((nodeTemp->getLen() > 1) && (nodeTemp->getDepth() < maxDepth)){
            nodeTemp->subdivide(); 
            for(int e = Node::START_CHILD;e <= Node::END_CHILD; e++)
                list.push_back(nodeTemp->getChild(e));
        }
    }
}

Node *PRQuadtree::find(Point *point) const {
    std::list<Node *> list;
    list.push_back(root);

    while (!list.empty()){
        Node *nodeTemp;

        nodeTemp = list.back();
        list.pop_back();

        if (!nodeTemp->hasChildren())
        {
            if (nodeTemp->isInNode(point))
                return nodeTemp;
        }else{
            for (int e = Node::START_CHILD;e <= Node::END_CHILD;e++)
                list.push_back(nodeTemp->getChild(e)); 
        }
    }

    return 0; 
}

Node *PRQuadtree::getLeafAt(float x, float y) const{
    Node *nodeTemp = root;
 
    while (nodeTemp->hasChildren()){
        for (int e = Node::START_CHILD; e <= Node::END_CHILD; e++) {
            if (nodeTemp->getChild(e)->isInRegion(x, y)){
                nodeTemp = nodeTemp->getChild(e);
                break;
            }
        }
    }
    return nodeTemp;
}

