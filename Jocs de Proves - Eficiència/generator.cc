#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

//Pre:  Cert
//Post: Funció que + que noms genera un string random de caracters que actuan com usuaris
string generar_nom()
{
  string u;
  u.push_back(rand()%25 + 'A');
  int i = rand()%25;
  while(rand()%25 and rand()%25 and rand()%25 and rand()%25)
  {
    u.push_back(rand()%25+'a');
    ++i;
    i = rand()%25;
  }
  return u;
}

//Pre:  Cert
//Post: Imprimeix n usuaris bàsicament per dificultar la tasca d'accedir a un usuari
void print_usuarios(int n)
{
  for (int i = 0; i < n; ++i)
  {
    cout << " " << generar_nom();
  }
  cout << endl;
}

//Pre:  Cert
//Post: S'imprimeixen tants envios com n de l'usuari u als problemes amb prefix c
//      però amb la condució que el nº va de 2^n fins 2^n+1
void print_envios(int n, string u, char c)
{
  int r;
  int ini, fi;
  ini = pow(2, n);
  fi = pow(2, n+1);
  for (int i = ini; i <= fi-1; ++i)
  {
    r = rand() % 10;
    r %= 2;
    cout << "e " << u << " " << c << i-1 << " " << r << endl;
    if (r == 0) --i;
  }
}

//Pre:  Cert
//Post: S'imprimeix una sesio amb n nivells on x es el prefix dels problemes de
//      l'últim nivell i c la resta (nota: n nivells requerirà de 2^n problemes)
void print_sesio(int n, int& p, char c, char x)
{
  if (n == 1)
  {
    cout << " " << x << p << " 0 0";
    ++p;
  }
  else
  {
    cout << " " << c << p;
    ++p;
    print_sesio(n-1, p, c, x);
    print_sesio(n-1, p, c, x);
  }
}

//Pre:  Cert
//Post: Imprimeix n problemes amb prefix c
void print_problemes(int n, char c)
{
  cout << n +1 << endl;
  for (int i = 0; i <= n; ++i)
  {
    cout << " " << c << i;
    if (i%100 == 0 and i != 0) cout << endl;
  }
  cout << endl;
}

//Pre:  Cert
//Post: Imprimeix n instruccions de sesio_problema amb problema prefix c,
//      sesio random per tant problemes com n
void print_sesio_prob(int n, char c, int l)
{
	for (int i = 0; i < n; i += rand()%10)
	{
		cout << " sp " << (i+rand()%10)%l << " " << c << i << endl;
	}
}

int main()
{
  srand(time(NULL));
  int l;
  int zero = 0;
  char c = 'A';
  cerr << "Sent el nombre de problemes generats 2^n, indica la n : ";
  cin >> l;
  // problemes
  int problemes = pow(2, l);
  print_problemes(problemes, c);
  // sesio
  cout << "1" << endl << "sesion1";
  print_sesio(1, zero, c, c);
  zero = 0;
  // curs
  cout << endl << "1" << endl << "1 sesion1" << endl;
  // usuaris
  string u;
  cerr << "Indica com vols que es digui el teu usuari principal : ";
  cin >> u;
  int us;
  cerr << "Indica quants usuaris vols generar : ";
  cin >> us;
  cout << us+1 << endl << u;
  print_usuarios(us);
  //resolem el primer curs
  cout << "i " << u << " 1" << endl;
  print_envios(0, u , c);

  for (int i = 2; i <= l; ++i)
  {
    cout << "ns sesion" << i;;
    zero = 0;
    print_sesio(i, zero, c, c);
    cout << endl << "nc 1 sesion" << i << endl;
    cout << "i " << u << " " << i << endl;
    print_envios(i-1, u , c);
  }
  print_sesio_prob(problemes, c, l);
  cout << endl << "listar_problemas" << endl << "escribir_usuario " << u << endl;
  cout << "fin" << endl;
}
