#include<iostream>
#include <cmath>
using namespace std;
int main()
{
    char a;
    double b,c,d;
    while (true)
    {
        cin >> b >> a >> c;
        if (a== '-'){
            cout << b << "+" <<  c << "=" << b - c;
        }
        if (a == '+'){
            cout << b << "+" <<  c << "=" << b + c;
        }
        if (a == '*'){
            cout << b << "*" <<  c << "=" <<  b * c;
        }
        if (a == '/'){
	        if (c == 0){
                cout << "error";
            }
            else {
	            cout << b << "/" <<  c << "=" <<  b / c;    
	        }
        }
        d=1;
        if (a == '^'){
	        for (double i = c; i > 0; i--) {
	            d = d * b;
	        }
	        cout << b << "^" <<  c << "=" << d;
	    }
    }
    
}