#include "set.h"
#include <iostream>
using namespace std;

Set::Set(int size)
{
    this->Size=size;
    this->n=new int[size];
    for(int i=0;i<size;i++)
    {
        n[i]=i;
    }
}

Set::~Set()
{
    delete[]n;
}

Set::Set(const Set &other)
{
    this->Size=other.Size;
    this->n=new int[other.Size];
    for(int i=0;i<other.Size;i++)
    {
        this->n[i]=other.n[i];
    }
}


void Set::SetM1(int *m1)
{
        n=m1;
}
void Set::SetM2(int *m2){
        n=m2;
}

bool Set::check_in(int x)
{
        for(int i=0;i<Size;i++)
                if(n[i]==x)
        return true;

            return false;


}

void Set::add(int  x)
{

                if(!check_in(x))
                {
                        n[Size]=x;
                        Size+=1;
                        cout<<("Successfully");
                }
                else
                        cout<<("Unsuccessfully");

}

void Set::del(int x)
{
        bool ok;
        ok=false;
        if(Size!=0)
        {
                for(int i=0;i<Size;i++)
                {
                        if(n[i]==x)
                        {
                                for(int j=i;j<Size;j++)
                                {
                                        n[j]=n[j+1];
                                }
                                Size-=1;
                                ok=true;;
                        }

                }
                if(ok)
                        cout<<("Successfully");
        }
        else
                cout<<("Impossible");
}

void Set::max()
{

    int max = n[0];
    for(int i = 0; i < Size; ++i)
    {
        if(n[i] > max)
        {
            max = n[i];
        }
    }
}

void Set::min()
{
    int min = n[0];
    for(int i = 0; i < Size; ++i)
    {
        if(n[i] < min)
        {
            min = n[i];
        }
    }
}

ostream &operator<<(ostream &s, const Set &p)
{
   if (p.Size!=0){
   s<<"(";
   for (int i=0;i<p.Size-1;i++){
      s<<p.n[i]<<",";
      }
      s<<p.n[p.Size-1];
      }
   return s<<")";
}

istream &operator>>(istream &s, Set &p)
{
  int tmp;
  char c;
  s>>c;

  while(c!=')')
  {
    s>>tmp>> c;
    p.add(tmp);                                 //тут питання з едд
    }
    return s;

  }

std::string Set::get_res()
{
    return std::to_string(n[Size]);
}
