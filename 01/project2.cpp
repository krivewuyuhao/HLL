#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class TeamLeader {
public:
    //将记录的时间放在容器里储存
    void recordAnswerTime(double timeTaken) {
        answerTimes.push_back(timeTaken);                   
    }

    //计算平均用时
    double calculateAverageTime() const {
        if (answerTimes.empty()) {
            return 0.0;
        }
        double sum = 0.0;
        for (double time : answerTimes) {
            sum += time;
        }
        return sum / answerTimes.size();
    }

    double getShortestTime() const {
        if (answerTimes.empty()) {
            return 0.0;
        }
        return *std::min_element(answerTimes.begin(), answerTimes.end());
    }

    double getLongtestTime() const {
        if (answerTimes.empty()){
            return 0.0;
        }
        return *std::max_element(answerTimes.begin(), answerTimes.end());
        
    }

private:
    std::vector<double> answerTimes;
};

int main() {
    srand((unsigned int)time(NULL));
    int correctcount = 0;
    int wrongcount = 0;
    vector<pair<string, int>> wronganswers; // 用于存储答错的题目和正确答案

    TeamLeader teamLeader;  // 创建 TeamLeader 对象

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
        char symbol = rand() % 2 == 0 ? '+' : '-';  // 随机加减法
        cout << i << symbol << j << "=" << endl;

        // 记录开始时间
        time_t startTime = time(NULL);

        cin >> result;

        // 记录结束时间
        time_t endTime = time(NULL);
        double timeTaken = difftime(endTime, startTime);

        if (answer == result) ++correctcount;
        if (answer != result) {
            ++wrongcount;
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