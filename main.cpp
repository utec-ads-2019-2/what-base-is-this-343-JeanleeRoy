#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int minBase(string str) {
    int minbase = 0, aux;
    for (auto a : str) {
        aux = (a >= 'A') ? (int)a-55 : a-'0';
        if (aux > minbase) minbase = aux;
    }
    return minbase+1;
}

int value (int base, string str) {
    int result = 0, aux, size = str.size(); 
    for (auto s : str) {
        aux = (s >= 'A') ? (int)s-55 : s-'0';
        result += aux*pow(base,--size);
    }
    return result;
}

void comparations(string X, string Y) {
    int baseX = minBase(X), baseY = minBase(Y);
    while (baseX <= 36 || baseY <= 36) {
        int valueX = value(baseX,X), valueY = value(baseY,Y);
        if (valueX == valueY) {
            cout << X << " (base " << baseX << ") = "
                << Y << " (base " << baseY << ")\n";
            return;
        }
        else if (valueX < valueY) {
            ++baseX;
        } else {
            ++baseY;
        }
    }
    cout << X << " is not equal to " 
        << Y << " in any base 2..36\n";
}

int main(int argc, char const *argv[]) {
    string X, Y;
    while (cin) {
        cin >> X >> Y;
        comparations(X,Y);
    }
    return 0;
}
