/*
 * @Author: Mohit Pathak
 * @Date: 2021-08-30 18:39:56
 * @Last Modified by:   MOHIT PATHAK
 * @Last Modified time: 2021-08-31 09:34:09
 */

#include <iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class complex {
    int real, img;
public:
    complex() {
        real = 0;
        img = 0;
    }
    complex(int r, int i) {
        real = r;
        img = i;
    }
    int getReal() const {
        return real;
    }
    int getImg() const {
        return img;
    }
    void setReal(int r) {
        real = r;
    }
    void setImg(int i) {
        img = i;
    }
    void print() const {
        if (img < 0) {
            cout << real << " - " << -1 * img << "i" << endll;
        } else {
            cout << real << " + " << img << "i" << endll;
        }
    }
    complex operator+(const complex&b) {
        complex temp;
        temp.real = real + b.real;
        temp.img = img + b.img;
        return temp;
    }
};

ostream& operator<<(ostream& os, complex&c) {
    c.print();
    return os;
}

istream& operator>>(istream& is, complex&c ) {
    int i, r;
    is >> r >> i;
    c.setReal(r);
    c.setImg(i);
    return is;
}




//==========================================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================
    complex c1(10, 20), c2;
    c2.setReal(9);
    c2.setImg(-9);
    c1.print();
    c2.print();
    complex c3;
    c3 = c1 + c2;
    c1.print();
    c2.print();
    c3.print();
    return 0;
}