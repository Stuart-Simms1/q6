#include <vector>

using namespace std;

class Edge : public Node{
public:
Edge(const Node _n1, const Node _n2);
double getLength() const;
double getAngle() const;
private:
double length;
double angle;
};

class Node{
public:
Node(const double _x, const double _y);
double getPosX() const;
double getPosY() const;
protected:
double x;
double y;
};

class Map : public Node, public Edge{
public:
Map(vector<Node> _Nodes);
private:
vector<Node> Nodes;
vector<Edge> Edges;
};

class Store: public Node{

};

class Robot{

};
