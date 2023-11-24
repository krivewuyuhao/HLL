#include<iostream>
#include<ctime>
#include<cstdlib>
#include <vector>                   // 为了存储答错的题目
using namespace std;
 
int main(){
    srand((unsigned int)time(NULL));
    int correctcount=0;
    int wrongcount=0;
    vector<pair<string, int>> wronganswers; // 用于存储答错的题目和正确答案

    int a,b;
    int quantity;
    cout<<"队长你选择的加减法数字区间为a-b"<<endl;
    cout<<"请输入a"<<endl;
    cin>>a;
    cout<<"请输入b"<<endl;
    cin>>b;
    cout<<"队长你选择的题目数量为";
    cin>>quantity;
    for(int num=1;num<=quantity;num++)
    {   
        cout<<"第"<<num<<"道"<<endl;
        int answer;
        int result;
        
        
        int i=rand()% (b-a+1)+a;
        int j=rand()% (b-a+1)+a;
        char symbol=rand() % 2 == 0 ? '+' : '-';  //随机加减法
        cout<<i<<symbol<<j<<"="<<endl;
        cin>>result;
        if(symbol=='+') answer=i+j;
        else if(symbol=='-')  answer=i-j;

        if(answer==result) ++correctcount;
        if(answer!=result) 
        {++wrongcount;
        wronganswers.push_back(make_pair(to_string(i)+ string(1, symbol)+ to_string(j),answer));
        }
    }
    cout<<"队长你答对题目数量"<<correctcount<<"答错题目数量"<<wrongcount<<endl;

    if (wrongcount > 0) {
        cout << "答错的题目和正确答案：" << endl;
        for (const auto & pair : wronganswers) {
            cout << pair.first << " = " << pair.second << endl;
        }
    }
    system("pause");
    return 0;
}