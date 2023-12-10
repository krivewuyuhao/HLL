#include <iostream>
using namespace std;
typedef int ElemType; // 简单的数据类型
struct LNode {
    ElemType data;   // 数据域
    LNode *prior;    // 指向直接前驱节点
    LNode *next;     // 指向直接后继节点
};

typedef LNode *LinkList;   // LNode为双链表结构体类型，LinkList为双链表指针类型

class LinkedList {
private:
    LinkList head;  // 指向头结点的指针

public:
    int n;        //含有n个成员
    LinkedList(); // 构造函数
    static void input(ElemType *ep); // 输入函数
    void CreateLinkF(int n, void(*input)(ElemType*)); // 头插法创建链表
    void CreateLinkR(int n, void(*input)(ElemType*)); // 尾插法创建链表
    void DestroyList(); // 销毁链表
    bool isEmpty(); // 判断链表是否为空
    void visit(ElemType *ep); // 遍历链表时访问节点的函数
    void ListTraverse(); // 遍历链表
    void ListReverseTraverse(); // 从后往前遍历链表
    static int compare(ElemType *ep1, ElemType *ep2); // 比较两个数据元素关系的函数
    int LocateElem(ElemType e, int(*compare)(ElemType*, ElemType*)); // 查找节点
    int LinkInsert(int i, ElemType e); // 在第i个位置之前插入元素e
    int ListDelete(int i, ElemType *ep); // 删除第i个位置的元素
    ~LinkedList(); // 析构函数
};

LinkedList::LinkedList() {
    head = new LNode; // 创建头结点
    head->prior = nullptr;
    head->next = nullptr;
}

void LinkedList::input(ElemType *ep) {
    cin >> *ep;
}

void LinkedList::CreateLinkF(int n, void(*input)(ElemType*)) {
    LinkList s;
    LNode *p = head;
    for (; n > 0; n--) {
        s = new LNode; // 创建新的结点
        input(&s->data); // 输入数据域
        s->next = p->next;
        if (p->next != nullptr) {
            p->next->prior = s;
        }
        s->prior = p;
        p->next = s; // 将s增加到开始结点之前
    }
}

void LinkedList::CreateLinkR(int n, void(*input)(ElemType*)) {
    LinkList p, s;
    p = head;
    for (; n > 0; n--) {
        s = new LNode; // 创建新结点
        input(&s->data); // 输入数据域
        s->next = p->next;
        if (p->next != nullptr) {
            p->next->prior = s;
        }
        s->prior = p;
        p->next = s; // 将s插入到当前链表末尾
        p = s;
    }
    p->next = nullptr; // 尾结点
}

void LinkedList::DestroyList() {
    LinkList q, p = head->next;
    while (p != nullptr) {
        q = p->next; // 指向直接后继结点
        delete p; // 释放结点内存空间
        p = q; // 直接后继结点
    }
    head->next = nullptr; // 置为空表
}

bool LinkedList::isEmpty() {
    return head->next == nullptr;
}

void LinkedList::visit(ElemType *ep) {
    cout << *ep << endl; // 输出数据域
}

void LinkedList::ListTraverse() {
    LinkList p = head->next; // p指向开始结点
    while (p != nullptr) {
        visit(&(p->data)); // 访问结点
        p = p->next; // 结点往后
    }
}

void LinkedList::ListReverseTraverse() {
    LinkList p = head;
    while (p->next != nullptr) {
        p = p->next;  // 移动到最后一个节点
    }
    while (p != head) {
        visit(&(p->data));  // 访问节点
        p = p->prior;  // 前移一个节点
    }
}

int LinkedList::compare(ElemType *ep1, ElemType *ep2) {
    if (*ep1 == *ep2) {
        return 1;
    } else {
        return 0;
    }
}

int LinkedList::LocateElem(ElemType e, int(*compare)(ElemType*, ElemType*)) {
    int i = 0;
    LinkList p = head->next;
    while (p != nullptr) {
        i++;
        if (compare(&(p->data), &e)) return i;
        p = p->next; // 结点往后
    }
    return 0;
}

int LinkedList::LinkInsert(int i, ElemType e) {
    LinkList s, p = head; // p指向头指针
    int j = 0;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr || j > i - 1) {
        return 0; // 插入位置不合理
    }
    s = new LNode; // 创建新节点
    s->data = e; // 赋值
    s->next = p->next;
    if (p->next != nullptr) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return 1;
}

int LinkedList::ListDelete(int i, ElemType *ep) {
    if (i < 1 || i > n) {
        return 0; // 删除位置不合理
    }
    LinkList p = head;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }
    LinkList q = p->next; // 要删除的节点
    *ep = q->data; // 保存数据域
    p->next = q->next; // 从链表中移除节点
    if (q->next != nullptr) {
        q->next->prior = p;
    }
    delete q; // 释放节点内存
    n--; // 链表节点数减一
    return 1;
}

LinkedList::~LinkedList() {
    DestroyList();
}

int main() {
    //创建一个类的成员
    LinkedList list;
    cout << "请输入你想创建链表长度" << '\n';
    cin >> list.n;
    cout << "逐个输入成员元素" << endl;
    // list.CreateLinkF(list.n, &LinkedList::input);   //头插法
    list.CreateLinkR(list.n, &LinkedList::input);   //尾插法
    //插入成员
    list.LinkInsert(4,99);
    //删除成员
    int p;          //保存删除的成员
    list.ListDelete(2,&p);      //删除结点2
    cout << "输出删除成员" << p << endl;
    //遍历成员并且输出
    cout << "遍历成员并且输出" << endl;
    list.ListTraverse();
    //从后往前遍历
    cout << "从后往前遍历" << endl;
    list.ListReverseTraverse();
    //判断是否为空,0为非空，1为空
    cout << "该链表是否为空" << list.isEmpty() << endl;
    //查找元素
    int e;
    cin >> e;
    cout << list.LocateElem(e, &LinkedList::compare) << endl;
    //测试销毁
    list.DestroyList();
    //判断是否为空，0为非空，1为空
    cout << "该链表是否为空" << list.isEmpty() << endl;
    return 0;
}
