#include <string>

using namespace std;

// Defini��o da classe node
class node {
private:
	 string info;
     node *prox;
public:
     node();
	 node(string);
	 void setinfo(string);
	 void setprox(node *);
	 node *getprox();
	 string getinfo();
};
