#include <mapClasses.hpp>
#include <vector>
#include <cmath>

using namespace std;

class Edge : public Node{
public:
Edge(const Node n1, const Node n2) : length(), angle() {
    double xDiff = n2.getPosX() - n1.getPosX();
    double yDiff = n2.getPosY() - n1.getPosY();
    length = sqrt(abs(xDiff)*abs(xDiff) + abs(yDiff)*abs(yDiff));
    angle = atan(yDiff/xDiff);
};
double getLength() const{
    return length;
};
double getAngle() const{
    return angle;
};
private:
double length;
double angle;
};

class Node{
public:
Node(const double _x, const double _y) : x(_x), y(_y) { };
double getPosX() const{
    return x;
};
double getPosY() const{
    return y;
};
protected:
double x;
double y;
};

class Map : public Node, public Edge{
public:
Map(vector<Node> _Nodes) : Nodes(_Nodes), Edges() {
    for(size_t i = 1; i <= Nodes.size(); i+=2){
        Edge e(Nodes[i],Nodes[i+1]);
        Edges[i] = e;
    };
};
private:
vector<Node> Nodes;
vector<Edge> Edges;
};