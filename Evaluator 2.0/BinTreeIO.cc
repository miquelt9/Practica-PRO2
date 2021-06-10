#include "BinTreeIO.hh"

void leer_bintree_problema(BinTree<string>& a)
{
  string x;
  cin >> x;
  if (x != "0"){
  	BinTree<string> l;
  	leer_bintree_problema(l);
  	BinTree<string> r;
  	leer_bintree_problema(r);
  	a=BinTree<string>(x,l,r);
  }
}
void escribir_bintree_problema(const BinTree<string>& a)
{
  if (not a.empty()) {
    string x = a.value();
    cout << "(";
    escribir_bintree_problema(a.left());
    escribir_bintree_problema(a.right());
    cout << x <<  ")";
  }
}
