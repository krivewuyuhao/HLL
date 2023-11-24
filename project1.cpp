#include<iostream>
#include<ctime>
#include<cstdlib>
#include <vector> // 为了存储答错的题目
using namespace std;
//
int main(){
    srand((unsigned int)time(NULL));        //种下随机数的种子
    int correctcount=0;
    int wrongcount=0;
    vector<pair<string, int>> wronganswers; // 用于存储答错的题目和正确答案
    for(int num=1;num<=10;num++)
    {   
        cout<<"第"<<num<<"道"<<endl;
        int answer;
        int result;
        

        int i=rand()%100+1;
        int j=rand()%100+1;
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