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
    Set();
    Set(int size);
    Set(int *array, int size );
    Set(const Set &other);//copy constructor
    ~Set();

    bool check_in(int x);//check for availability
    int force();//potyzh
    void add(int x);//adding
    void del(int x);//deleting
    void max();//maximum
    void min();//minimum

    int GetLength();
    void SetLength();
    int* Get_Set();

    Set operator+(Set m1);
    Set operator-(Set m1);
    int operator==(Set m1);

    void SetM1(int *m1);//set1
    void SetM2(int *m2);//set2
    std::string get_res();

    friend ostream& operator<<(ostream &, const Set &);//out
    friend istream& operator>>(istream &s, Set &);//in
};

#endif // SET_H
