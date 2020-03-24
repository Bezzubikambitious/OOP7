#ifndef SET_H
#define SET_H
#include <fstream>
#include <QTextEdit>
#include <QLabel>
#include <string>
using namespace std;

class Set
{
    int *n;
    int Size;
public:
    Set(int size);
    Set(const Set &other);//copy constructor
    ~Set();

    bool check_in(int x);//check for availability
    void add(int x);//adding
    void del(int x);//deleting
    void max();//maximum
    void min();//minimum

    void SetM1(int *m1);//set1
    void SetM2(int *m2);//set2
    std::string get_res();

    friend ostream& operator<<(ostream &, const Set &);//out
    friend istream& operator>>(istream &s, Set &);//in
};

#endif // SET_H
