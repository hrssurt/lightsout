#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  // You will need to make changes this code.

  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
    }
    else if (cmd == "init") {
      int a;
      int b;
      while (true) {
        cin >> a >> b;
        if (a == -1 || b == -1) break;
        else {
          g.turnOn(a,b);
        }
      }
      cout << g;
    }
    else if (cmd == "game") {
      cin >> moves;
      cout << moves << " moves left" << endl;
    }
    else if (cmd == "switch") {
      int r = 0, c = 0;
      cin >> r >> c;
      g.toggle(r,c);
      --moves;
      cout << moves << " moves left" << endl;
      cout << g;
    }
  }
}
