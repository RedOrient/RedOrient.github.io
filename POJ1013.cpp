#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//返回1则为重，0则为轻 。 *cf为假币 
int IsCounterfeit(string left[], string right[], string status[], char *cf)
{
    string hy, lt, ev;
    int i = 0, ot = 0, is = 0;
    for(; i<3; i++)
    {
          if (status[i] == "even")
          {
                        ev = ev+left[i]+right[i]; 
          }
          else if (status[i] == "up")
          {
                        if (hy.size() == 0 && lt.size() == 0)
                        {
                                      hy = left[i];
                                      lt = right[i];
                                      continue;
                        }
                        int j;
                        //这里因为erase函数会改变下标，所以控制下标的增加 
                        for(j=0; j<hy.size();)
                        {
                              if(left[i].find(hy[j]) == left[i].npos)
                              {
                                                hy.erase(j, 1);
                              }
                              else
                              {
                                                j++;
                              }
                        }
                        for(j=0; j<lt.size();)
                        {
                              if(right[i].find(lt[j]) == right[i].npos)
                              {
                                                lt.erase(j, 1);
                              }
                              else
                              {
                                                j++;
                              }
                        }
          }
          else
          {
                        if (hy.size() == 0 && lt.size() == 0)
                        {
                                      hy = right[i];
                                      lt = left[i];
                                      continue;
                        }
                        int j;
                        for(j=0; j<hy.size();)
                        {
                              if(right[i].find(hy[j]) == right[i].npos)
                              {
                                               hy.erase(j, 1);
                                               //cout << hy << endl;
                              }
                              else
                              {
                                               j++;
                              }
                        }
                        for(j=0; j<lt.size();)
                        {     
                              if(left[i].find(lt[j]) == left[i].npos)
                              {
                                                lt.erase(j, 1);
                              }
                              else
                              {
                                                j++;
                              }
                        }
         
          }          
    }
    
    //cout << hy << endl << lt << endl;
    //cout << ev << endl;
    //筛选出的疑重币组和疑轻币组都要经过确定真币的再次筛选 
    for(i=0; i<hy.size()&&ev.size()!=0;)
    {
             if(ev.find(hy[i]) != ev.npos)
             {
                               hy.erase(i, 1);
             }
             else
             {
                               i++;
             }
    }
    for(i=0; i<lt.size()&&ev.size()!=0;)
    {
             if (ev.find(lt[i]) != ev.npos)
             {
                                lt.erase(i, 1);
             }
             else
             {
                                i++;
             }
    }
    //cout << hy << endl << lt << endl;
    
    if(hy.size() == 1)
    {
                 *cf = hy[0];
                 return 1;
    }
    if(lt.size() == 1)
    {
                 *cf = lt[0];
                 return 0;
    }
}
int main(void)
{ 
    //m为假币的名称数组，p为轻重状态数组 
    int n, ot = 0, pt = 0, p[100];
    char m[100];
    cin >> n;
    while(n--)
    {
          int i = 0;
          string left[5];
          string right[5];
          string status[5];
          for(i=0; i<3; i++)
          {
                   cin >> left[i];
                   cin >> right[i];
                   cin >> status[i]; 
          }
          p[ot++] = IsCounterfeit(left, right, status, &m[pt++]);    
    }
    
    for(n=0; n<ot; n++)
    {
             if (p[n] == 1)
             {
                      cout << m[n] << " is the counterfeit coin and it is heavy." << endl;
             }
             else
             {
                      cout << m[n] << " is the counterfeit coin and it is light." << endl;
             }
    }
    
    
    system("PAUSE");
    return 0;
}
