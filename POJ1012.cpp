#include <cstdlib>
#include <iostream>

/*

2016/10/30/18:32 AC
解题报告：
1.求解m是否要求的结果时，通过k次的运算，算出每次被杀的第m个人在当时队列中的 位置，
如果每次都是 坏人，则是，否则不是
2.注意，当我采取输入一个数据输出一个结果的方法时，时间超时，原因是因为输入一次，就等待Circle函数运行一次，，
当数据大的时候，等待时间会很长；但是当我采用先将1-13的数据的对应m求出来之后存入一个数组，然后输入一个数据就
直接输出对应数组下标数据时，成功AC，这给我的启发时，当数据范围较小时，如本题1-13时，可以采用这样的方法，答案
可以达到秒出，有一种更好的用户体验。 
*/
using namespace std;

bool Circle(int k, int m)
{
    int i, n[15];
    n[0] = 0;
    for(i=1; i<=k; i++)
    {
        int po = k-i+1;
        int sum = po+k;
        //被杀的人的相对与最后一个人的位置 
        int re = sum - (m-n[i-1])%sum;
        if(re == sum)
        {
            re = 0;   
            
        }
        n[i] = re;
        //被杀的是坏人 
        if(n[i] >= 0 && n[i] < po)
            ;
        else
            return false;
        
    }   
    
    
    return true;
}
int main(int argc, char *argv[])
{
    int i = 0, j = 1, k, m, result[14];
    for(k=1; k<=13; k++)
    {

        for(m=k+1; 1; m++)
        {
            if(Circle(k, m))
            {
                result[k-1] = m;
                break;
            }
        }
    }
    
    while(1)
    {
        cin >> k;
        if(k == 0)
            break;
        else
            cout << result[k-1] << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
