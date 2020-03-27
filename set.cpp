#include "set.h"
#include "math.h"
#include <iostream>
using namespace std;

Set::Set(){}

Set::Set(int size)
{
    this->Size=size;
    this->n=new int[size];
    for(int i=0;i<size;i++)
    {
        n[i]=0;
    }
}
Set::Set(int *array, int size )
{
    this->Size=size;
    this->n=new int[size];
    for(int i=0;i<size;i++)
    {
        n[i]=array[i];
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


int GetValue(int i)
{
    return n[i];
}

bool Set::check_in(int x)
{
    for(int i = 0; i<this->Size; i++)
            {
                if(x == this->n[i])
                {
                    return 1;
                }
            }
            return 0;
        }




int Set::force()
{
    int power = this->Size;
    int bulean = pow(2, power);
    return bulean;
}


void Set::add(int  x)
{

    int check_in = 0;
    for(int i = 0; i<this->Size; i++)
    {
        if(this->check_in(x))
        {
            check_in = 1;
        }
    }
    if(!check_in)
    {
        this->Size = this->Size+1;
        this->n[this->Size-1] = x;
    }


}

void Set::del(int x)
{ 
    Set *m1 = new Set(this->GetLength()-1);
            int k = 0;
            for(int i = 0; i<this->Size; i++)
            {
                if(this->n[i] != x)
                {
                    m1->n[k] = this->n[i];
                    k++;
                }
            }
            m1->SetLength(k);
            return m1;
}

int* Get_Set()
    {
        int *set = this->n;
        return set;
    }


int GetLength()
{
    int length = this->Size;
    return length;
}

void SetLength(int length)
{
    this->Size = length;
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

Set operator+(Set m1)
  {
      Set *m2 = new Set(this->Size + m1.Size);
      for(int i = 0; i<this->Size; i++)
      {
          if(!(m2->check_in(this->n[i])))
          {
              m2->n[k] = this->n[i];
              k++;
          }
       }
      for(int j = 0; j < m1.Size; j++)
      {
          if(!m2->Check_in(m1.n[j]))
          {
               m2->n[k] = m1.n[j];
               k++;
          }
      }
      m2->Size = k;
      return *m2;
  }

  Set operator-(Set m1)
  {
      Set *m2 = new Set(this->Size);
      int k =0;
      for(int i = 0; i<this->Size; i++)
      {
          for(int j = 0; j<m1.Size; j++)
          {
              if(this->n[i] == m1.n[j])
              {
                  m2->n[k] = this->n[i];
                  k++;
                  break;
              }
          }
      }
      m2->Size = k;
      return *m2;
  }

  int operator==(Set m1)
  {
      int check_in = 0;
      if(this->Size != m1.Size)
          return 0;
      for(int i = 0; i<this->Size; i++)
      {
          for(int j = 0; j<m1.Size; j++)
          {
              if(this->n[i] == m1.n[j])
              {
                  check_in++;
              }
          }
      }
      if(check_in == this->Size)
          return 1;
      else
          return 0;
  }
/*
  Set& operator=(const Set& obj1)
      {
      if (m_num != obj1.m_num)
          {
          if (obj1.m_length != m_length)
             {
              delete[] m_num; // Видаляємо старі елементи
              m_length = obj1.m_length;  // встановлюєм новий розмір масиву
              m_num = new int[obj1.m_length];  // виділяємо нову памёять для нашого масиву
             }
          // Копіюємо елементи в потрібний нам масив
          int *p = m_num + m_length;
          int *q = obj1.m_num + m_length;
          while (p > m_num)
               *--p = *--q;
          }
      return *this;
      }
*/




std::string Set::get_res()
{
    return std::to_string(n[Size]);
}
