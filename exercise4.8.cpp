#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
  int tz[3], slp, state;
};
student stus[100];
int num;
int timeless = 1;

void update(student &stus)
{
  stus.state = (timeless + stus.tz[2] - 1) % (stus.tz[1] + stus.tz[0]);
}

int check()
{
  int flag, slpnum = 0, nslpnum = 0;
  for (int i = 0; i < num; i++)
  {
    if (stus[i].slp)
    {
      slpnum++;
    }
    else
    {
      nslpnum++;
    }
  }

  if (slpnum > nslpnum)
  {
    return flag = 1;
  }
  else
  {
    return flag = 0;
  }
}

void sleep(student &s, int che)
{
  if (s.state == (s.tz[0] + 1))
  {
    if (che)
    {
      s.slp = 1;
    }
    else
    {
      s.state = 1;
      s.slp = 0;
    }
  }
  else if (s.state == 1)
  {
    s.slp = 0;
  }
}

int done()
{
  for (int i = 0; i < num; i++)
  {
    if (stus[i].slp)
    {
      return 0;
    }
  }
  return 1;
}
void pristu(student s, int i)
{
  cout << "time:" << timeless;
  if (s.slp)
  {
    cout << "第" << i << "学生睡着了"
         << "  ";
  }
  else
  {
    cout << "第" << i << "学生没睡着"
         << "  ";
  }
}

int main()
{
  scanf("%d", &num);

  for (int i = 0; i < num; i++)
  {
    scanf("%d %d %d", &stus[i].tz[0], &stus[i].tz[1], &stus[i].tz[2]);
    if (stus[i].tz[2] <= stus[i].tz[0])
    {
      stus[i].slp = 0;
    }
    else
    {
      stus[i].slp = 1;
    }
    update(stus[i]);
  }

  int chek = check();
  while (not done())
  {

    timeless += 1;

    for (int i = 0; i < num; i++)
    {
      update(stus[i]);
    }
    for (int i = 0; i < num; i++)
    {
      sleep(stus[i], chek);
      pristu(stus[i], i);
    }
    chek = check();
    cout << endl;
  }

  cout << timeless << endl;
}
