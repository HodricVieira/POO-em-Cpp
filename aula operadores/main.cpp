#include <iostream>
using namespace std;

class ponto {
  int x;
  int y;
  int z;
public:
  ponto(int n, int m, int p){x = n; y = m; z = p;}

  ponto operator+(ponto const &opr){
    return ponto (x + opr.x, y + opr.y, z + opr.z);
  }

  ponto operator-(ponto const &opr){
    return ponto (x - opr.x, y - opr.y, z - opr.z);
  }

  ponto operator*(ponto const &opr){
   return ponto (x * opr.x, y * opr.y, z * opr.z);
  }

  ponto operator/(ponto const &opr){
   return ponto (x / opr.x, y / opr.y, z / opr.z);
  }

  void operator=(ponto const &opr){
    x = opr.x;
    y = opr.y;
    z = opr.z;
  }

  ponto operator++(int){
    this->x++;
    this->y++;
    this->z++;
    return *this;
  }

  ponto operator--(int){
    this->x--;
    this->y--;
    this->z--;
    return *this;
  }

  bool operator==(ponto const &opr){
    return (x == opr.x) && (y == opr.y) && (z == opr.z);
  }
};

int main() {
  ponto p1(1, 2, 3), p2(2, 2, 2), p3(3, 2, 1);
}