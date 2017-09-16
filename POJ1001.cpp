#include <cstdlib>
#include <iostream>
#include <math>
#include <stdlib> 
#include <string>
using namespace std;

char *Ddouble(char *cnum, char *tnum)
{

            int clg = strlen(cnum), tlg = strlen(tnum);
            int lg = clg - tlg;
            int i = 0, j = 0;
            //这里使用静态变量是因为局部数组超出生存期后可能会失去作用， 因此此块内存的地址实际为无效 
            static char sum[200];
            static char sumtm[200];
            //使用指针一定要谨慎， 当把sum指针传出去时要注意， 
            //当memset清空sun之后， 接受的sum地址指向全为0 因为地址只是地址， 空间才是根本， 空间值变了， 地址就只能指向新的值 
            memset(sum, '0', sizeof(sum));
            //计算，  传统乘法思想，进位制 
            for(i=clg-1; i>=0; i--)
            {
                         for(j=tlg-1; j>=0; j--)
                         { 
                         
                               //两个数组都是从末尾开始相乘 
                               int pd = (cnum[i]-48)*(tnum[j]-48); 
                               //当前位 
                               int now = i+j+1;
                               int pre = now-1;//进位                 
                               sum[now] += pd%10;
                               sum[pre] += pd/10;
                               //判断是否进位 
                               if (sum[now]-48 >= 10)                           //末尾进位如 19*16  
                               {
                                  sum[pre] += (sum[now]-48)/10;
                                  sum[now] = (sum[now]-48)%10+48;   
                               }      
                         }
            }           
            sum[clg+tlg] = '\0';
            //strcpy函数将后参数数组内容拷贝到前参数中， 并实现了完全替换 
            strcpy(sumtm, sum); 
            return sumtm;      
}
int main(void)
{
    char num[7];
    int a;
    while (cin >> num >> a)
    {
          if(a == 0)
          {
               cout << '1' << endl;
               continue;
          }
          int i = 0, j = 0, cp = 0, cp0 = 0, lg = 0, p = 0;
          char *result = num, *tm = num;
          lg  = strlen(num);
           //获取两数小数点位置
           for(i=lg-1; i>=0; i--)
           {
              if (num[i] == '.')
              {
                          cp0 = lg-i-1;
                          break;
              }
           }
           //为了运算方便， 把整数的后缀零去掉 
          for(i=lg-1; i>=0; i--)
          {
                   //如果是整数 ，即没有小数点 
                   if(cp0 == 0)
                   {
                         break;
                   }
                   if (num[i] == '0')
                   {
                            ;
                   }
                   else//往前推移 不是零的情况 
                   {
                            //.001
                            if (num[i] == '.')
                            {
                                     num[i] = '\0';
                            }
                            else
                            {
                                     num[i+1] = '\0';
                            }
                            break;
                   }
          }
          lg = strlen(num);
           //获取两数小数点位置
           for(i=lg-1; i>=0; i--)
           {
              if (num[i] == '.')
              {
                          cp = lg-i-1;
                          break;
              }
           }
           //将小数点移除
           if (cp != 0)
           {
              for(i=lg-1-cp; i<lg; i++)
              {
                          num[i] = num[i+1];
              }
           } 
          //进行运算 
          for (i=1; i<a; i++)
          {
              result = Ddouble(tm, num);
              tm = result;
          }
          //cout << tm << endl; 
          //将小数点输出到合适的地方并将无用零清掉 
          lg = strlen(result);
          for(i=0, j = i; i<=lg;)
          {
                  
                   //将这段放在这里是为了防止计算0.2之类时会连‘0’和‘。’全都抹掉， 而增加了p=1之后会使得‘。’之后的‘0’照常输出 
                   if(lg-i == a*cp && cp != 0)
                   {
                            p = 1;
                            cout << '.';
                            i++;
                            continue;
                   }
                   
                   //抹掉小数点前面无用零 
                   if (p == 0 && result[i] == '0' && result[i+1] != '\0')
                   {
                         i++;
                         j++;
                   }
                   else 
                   {
                       p = 1;    
                       cout << result[j];
                       i++;
                       j++;
                   }
                   
                   if(i == lg+1)
                   {
                        cout << endl;
                        break;
                   }
          }
          
    }
    
    system("PAUSE");
    return 0;
}
