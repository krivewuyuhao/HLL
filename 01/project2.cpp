#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
/*
*没有使用枚举来列出难度，且没有乘除法，
*乘除法的选择也可以根据随机数的方式来随机用switch语句
*封装函数，进行分文件编写，在vscode中至今不会
*/
//类
class TeamLeader {                                              
public:
    //将记录的时间放在容器里储存
    //使用常量函数，保证外部只读取外部的数据而不进行修改
    void recordAnswerTime(double timeTaken) {
        answerTimes.push_back(timeTaken);                   
    }

    //计算平均用时
    double calculateAverageTime() const {
        if (answerTimes.empty()) {               //在容器的头文件中作为布尔函数如果时间为空返回1，不为空为0，且empty比size耗时更短
            return 0.0;
        }
        double sum = 0.0;
        for (double time : answerTimes) {        //逐一把容器中的数字给time进行循环
            sum += time;
        }
        return sum / answerTimes.size();         //用size函数来确定容器中数量的多少
    }

    double getShortestTime() const {
        if (answerTimes.empty()) {
            return 0.0;
        }
        return *std::min_element(answerTimes.begin(), answerTimes.end());   //返回容器中的最小值
    }

    double getLongtestTime() const {
        if (answerTimes.empty()){
            return 0.0;
        }
        return *std::max_element(answerTimes.begin(), answerTimes.end()); //返回容器中的最大值
        
    }
//设置为私有，计算时间
private:
    std::vector<double> answerTimes;
};

int main() {
    srand((unsigned int)time(NULL));
    int correctcount = 0;
    int wrongcount = 0;
    //用pair来讲两组数据合成一组数据
    vector<pair<string, int>> wronganswers;             // 用于存储答错的题目和正确答案

    TeamLeader teamLeader;                              // 创建 TeamLeader 对象

    int a, b;
    int quantity;
    cout << "队长你选择的加减法数字为a-b" << endl;
    cout << "请输入a" << endl;
    cin >> a;
    cout << "请输入b" << endl;
    cin >> b;
    cout << "队长你选择的题目数量为";
    cin >> quantity;

    for (int num = 1; num <= quantity; num++) {
        cout << "第" << num << "道" << endl;
        int answer;
        int result;

        int i = rand() % (b - a + 1) + a;
        int j = rand() % (b - a + 1) + a;
        char symbol = rand() % 2 == 0 ? '+' : '-';  // 随机值为0，1，用三目运算符加减法   
        cout << i << symbol << j << "=" << endl;

        // 记录开始时间
        time_t startTime = time(NULL);              
        cin >> result;

        // 记录结束时间
        time_t endTime = time(NULL);
        double timeTaken = difftime(endTime, startTime);       //计算时间差 相当于endTime-startTime

        if(symbol=='+') answer=i+j;
        else if(symbol=='-')  answer=i-j;

        if (answer == result) ++correctcount;
        if (answer != result) {
            ++wrongcount;
            //将错误的题目存储到容器之中，用make_pair将其连接后存储,t0_string用于强制转化
            wronganswers.push_back(make_pair(to_string(i) + string(1, symbol) + to_string(j), answer)); 
        }

        // 记录答题用时
        teamLeader.recordAnswerTime(timeTaken);
    }

    cout << "队长你答对题目数量" << correctcount << "答错题目数量" << wrongcount << endl;

    if (wrongcount > 0) {
        cout << "答错的题目和正确答案：" << endl;
        for (const auto &pair : wronganswers) {
            cout << pair.first << " = " << pair.second << endl;
        }
    }

    // 输出队长答题的平均用时和最短用时
    cout << "队长答题平均用时：" << teamLeader.calculateAverageTime() << " 秒\n";
    cout << "队长答题最短用时：" << teamLeader.getShortestTime() << " 秒\n";
    cout << "队长答题最长用时：" << teamLeader.getLongtestTime() << "秒\n";

    system("pause");
    return 0;
}