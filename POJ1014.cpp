/*有分别价值为1,2,3,4,5,6的6种物品，输入6个数字，表示相应价值的物品的数量，
问一下能不能将物品分成两份，是两份的总价值相等，其中一个物品不能切开，
只能分给其中的某一方，当输入六个0是（即没有物品了），这程序结束，
总物品的总个数不超过20000*/ 
#include <cstdlib>
#include <iostream>

using namespace std;

int n[7];           //宝石数目数组
bool flag;
int halfnum, num; 
/*深度遍历功能：检测数组n中能否分成等价的两部分*/ 
/*检测到一个halfnum即可，因为形成一个，剩下的就是第二个*/
void DFS(int value, int pre)
{
   if(flag)
    return;
   
   if(value == halfnum) 
   { 
        flag = true;
        return;
    }
   
   int i;
   for(i=pre; i>=1; i--)
   {
        //n[i] 不为0 
        if(n[i])
        {
            //如果小于平均值，继续深度遍历 
            if(value+i <= halfnum)
            {   
                cout << i << endl; 
                n[i]--;             //下面合成要使用一个，所以减一个 
                
                DFS(value+i, i);    //合成，继续深度 
                
                if(flag)
                    break;
            }
            
            
        }
            
    } 
    
    return;
} 

int main(int argc, char *argv[])
{
    int test = 1;
    while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6])
    {
        int i = 1;
        num = 0;
        for(; i<=6; i++)
            num += i*n[i];
        //控制结束输入 
        if(num == 0)
            break;  
        if(num%2 != 0)
        {
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can't be divided."<<endl<<endl;    //注意有空行  
            continue;  
        }
        
        halfnum = num/2;
        flag = false;
        DFS(0, 6);    
        
        if(flag)
        {
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can be divided."<<endl<<endl;    //注意有空行
            continue;  
        } 
        else
        {
            cout<<"Collection #"<<test++<<':'<<endl;  
            cout<<"Can't be divided."<<endl<<endl;    //注意有空行  
            continue;
        }
    }
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
