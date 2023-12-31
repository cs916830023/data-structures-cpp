﻿/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#include "test.h"
#include "linked_queue.h"
#include "circular_queue.h"
#include "double_ended_queue.h"


/*!
 * @brief **测试-链式队列-长度**
 * @note
 * 测试-链式队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 *
 *
 * ---------------
 */
void Test_LinkedQueue_Length() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test LinkedQueue Length                 |" << endl;
    cout << "|                     测试-链式队列-长度                    |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    LinkedQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

    string old_memory[12] = { "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月" };

    for (int i = 0; i < 12; i++) {
        cout << "old_memory_queue enqueue: " << old_memory[i] << endl;
        old_memory_queue.EnQueue(old_memory[i]);
    }

    // ---------- 3 打印队列长度 ----------

    cout << endl << "队列old_memory_queue的长度: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-入队**
 * @note
 * 测试-链式队列-入队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 *
 * ---------------
 */
void Test_LinkedQueue_EnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test LinkedQueue Enqueue                 |" << endl;
    cout << "|                     测试-链式队列-入队                    |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    LinkedQueue<int> int_queue;

    // ---------- 2 数据入队队列 ----------

    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.EnQueue(1);
    int_queue.EnQueue(2);
    int_queue.EnQueue(3);
    int_queue.EnQueue(4);

    // ---------- 3 打印队列 ----------

    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-出队**
 * @note
 * 测试-链式队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 *
 *
 * ---------------
 */
void Test_LinkedQueue_DeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test LinkedQueue Dequeue                 |" << endl;
    cout << "|                     测试-链式队列-出队                    |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    LinkedQueue<double> double_queue;

    // ---------- 2 数据入队队列 ----------

    cout << "double_queue入队4个数: 1.1, 2.2, 3.3, 4.4" << endl << endl;

    double_queue.EnQueue(1.1);
    double_queue.EnQueue(2.2);
    double_queue.EnQueue(3.3);
    double_queue.EnQueue(4.4);

    cout << double_queue << endl;

    // ---------- 3 队头出队 ----------

    cout << "double_queue队头出队" << endl << endl;

    double frontData;
    double_queue.DeQueue(frontData);

    // ---------- 4 打印队列 ----------

    cout << double_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-获取队头/队尾数据**
 * @note
 * 测试-链式队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 *
 *
 * --------------------------
 */
void Test_LinkedQueue_GetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test Queue Front & Rear                  |" << endl;
    cout << "|              测试-链式队列-获取队头/获取队尾              |" << endl << endl << endl;

    LinkedQueue<string> string_queue;

    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    string front_data;
    string rear_data;

    string_queue.Front(front_data);
    string_queue.Rear(rear_data);

    cout << "The front of the queue: " << front_data << endl;
    cout << "The rear of the queue: " << rear_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-清空**
 * @note
 * 测试-链式队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 清空**\n
 *
 *
 * ---------------
 */
void Test_LinkedQueue_IsEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test LinkedQueue Clear                  |" << endl;
    cout << "|                     测试-链式队列-清空                    |" << endl << endl << endl;
    LinkedQueue<string> LinkinPark_song_queue;

    LinkinPark_song_queue.EnQueue("<In the end>");
    LinkinPark_song_queue.EnQueue("<Crawling>");
    LinkinPark_song_queue.EnQueue("<One more light>");

    bool is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << endl << "call function Clear." << endl << endl;

    LinkinPark_song_queue.Clear();

    is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-打印**
 * @note
 * 测试-链式队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 *
 * ---------------
 */
void Test_LinkedQueue_Print() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test LinkedQueue Operator<<                |" << endl;
    cout << "|                  测试-链式队列-operator<<                 |" << endl << endl << endl;

    LinkedQueue<string> string_queue;

    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    cout << string_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-长度**
 * @note
 * 测试-循环队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 *
 *
 * ---------------
 */
void Test_CircularQueue_Length() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularQueue Length                 |" << endl;
    cout << "|                     测试-循环队列-长度                    |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    CircularQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

    string old_memory[12] = { "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月" };

    for (int i = 0; i < 12; i++) {
        cout << "Old memory enqueue: " << old_memory[i] << endl;
        old_memory_queue.EnQueue(old_memory[i]);
    }

    // ---------- 3 打印队列长度 ----------

    cout << endl << "Old memory queue length: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-入队**
 * @note
 * 测试-循环队列-入队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 * ---------------
 */
void Test_CircularQueue_EnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularQueue Enqueue                |" << endl;
    cout << "|                     测试-循环队列-入队                    |" << endl << endl << endl;

    // 1 声明队列
    CircularQueue<int> int_queue;

    // 2 数据入队队列
    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.EnQueue(1);
    int_queue.EnQueue(2);
    int_queue.EnQueue(3);
    int_queue.EnQueue(4);

    // 3 打印队列
    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-出队**
 * @note
 * 测试-循环队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 *
 *
 * ---------------
 */
void Test_CircularQueue_DeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularQueue Dequeue                |" << endl;
    cout << "|                     测试-循环队列-出队                    |" << endl << endl << endl;

    // 1 声明队列
    CircularQueue<double> double_queue;

    // 2 数据入队队列
    cout << "double_queue enqueue 4 numbers." << endl;

    double_queue.EnQueue(1.1);
    double_queue.EnQueue(2.2);
    double_queue.EnQueue(3.3);
    double_queue.EnQueue(4.4);

    cout << double_queue << endl;

    cout << "double_queue dequeue." << endl << endl;

    // 3 队头出队
    double frontData;
    double_queue.DeQueue(frontData);

    cout << double_queue;
    double_queue.DeQueue(frontData);
    double_queue.DeQueue(frontData);
    double_queue.DeQueue(frontData);

    // 4 打印队列
    cout << double_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-获取队头/队尾数据**
 * @note
 * 测试-循环队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 *
 *
 * --------------------------
 */
void Test_CircularQueue_GetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test CircularQueue Front & Rear             |" << endl;
    cout << "|               测试-循环队列-获取队头/获取队尾             |" << endl << endl << endl;

    // 1 声明队列
    CircularQueue<string> string_queue;

    // 2 数据入队队列
    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    // 3 打印队头/队尾数据
    string front_data;
    string rear_data;

    string_queue.Front(front_data);
    string_queue.Rear(rear_data);

    cout << "The front of the queue: " << front_data << endl;
    cout << "The rear of the queue: " << rear_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-清空**
 * @note
 * 测试-循环队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 测试队列是否为空**\n
 * + **4 清空**\n
 * + **5 测试队列是否为空**\n
 *
 *
 * ---------------
 */
void Test_CircularQueue_Clear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test CircularQueue Clear                 |" << endl;
    cout << "|                     测试-循环队列-清空                    |" << endl << endl << endl;

    // 1 声明队列
    CircularQueue<string> LinkinPark_song_queue;

    // 2 数据入队队列
    LinkinPark_song_queue.EnQueue("<In the end>");
    LinkinPark_song_queue.EnQueue("<Crawling>");
    LinkinPark_song_queue.EnQueue("<One more light>");

    // 3 测试队列是否为空
    bool is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << endl << "call function Clear." << endl << endl;

    // 4 清空
    LinkinPark_song_queue.Clear();

    // 5 测试队列是否为空
    is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-打印**
 * @note
 * 测试-循环队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 *
 * ---------------
 */
void Test_CircularQueue_Print() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test CircularQueue Operator<<              |" << endl;
    cout << "|                  测试-循环队列-operator<<                 |" << endl << endl << endl;

    // 1 声明队列
    LinkedQueue<string> string_queue;

    // 2 数据入队队列
    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    // 3 打印队列
    cout << string_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双端队列-长度**
 * @note
 * 测试-双端队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 *
 *
 * ---------------
 */
void Test_DoubleEndedQueue_Length() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoubleEndedQueue Length               |" << endl;
    cout << "|                    测试-双端队列-长度                     |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    DoubleEndedQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

    string old_memory[12] = { "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月" };

    for (int i = 0; i < 12; i++) {
        cout << "Old memory enqueue: " << old_memory[i] << endl;
        old_memory_queue.PushBack(old_memory[i]);
    }

    // ---------- 3 打印队列长度 ----------

    cout << endl << "Old memory queue length: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双端队列-尾部入队**
 * @note
 * 测试-双端队列-尾部入队
 * -------------------
 * -------------------
 *
 * -------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 *
 * -------------------
 */
void Test_DoubleEndedQueue_EnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test DoubleEndedQueue PushBack              |" << endl;
    cout << "|                   测试-双端队列-尾部入队                  |" << endl << endl << endl;

    // 1 声明队列
    DoubleEndedQueue<int> int_queue;

    // 2 数据入队队列
    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.PushBack(1);
    int_queue.PushBack(2);
    int_queue.PushBack(3);
    int_queue.PushBack(4);

    // 3 打印队列
    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-出队**
 * @note
 * 测试-循环队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 *
 *
 * ---------------
 */
void Test_DoubleEndedQueue_DeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test DoubleEndedQueue Dequeue               |" << endl;
    cout << "|                     测试-双端队列-出队                    |" << endl << endl << endl;

    // 1 声明队列
    CircularQueue<double> double_queue;

    // 2 数据入队队列
    cout << "double_queue enqueue 4 numbers." << endl;

    double_queue.EnQueue(1.1);
    double_queue.EnQueue(2.2);
    double_queue.EnQueue(3.3);
    double_queue.EnQueue(4.4);

    cout << double_queue << endl;

    cout << "double_queue dequeue." << endl << endl;

    // 3 队头出队
    double frontData;
    double_queue.DeQueue(frontData);
    cout << double_queue;

    double_queue.DeQueue(frontData);
    double_queue.DeQueue(frontData);
    double_queue.DeQueue(frontData);

    // 4 打印队列
    cout << double_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双端队列-获取队头/队尾数据**
 * @note
 * 测试-双端队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 *
 *
 * --------------------------
 */
void Test_DoubleEndedQueue_GetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test DoubleEndedQueue Front & Rear            |" << endl;
    cout << "|               测试-双端队列-获取队头/获取队尾             |" << endl << endl << endl;

    // 1 声明队列
    DoubleEndedQueue<string> string_queue;

    // 2 数据入队队列
    string_queue.PushBack("听我的");
    string_queue.PushBack("买买买");
    string_queue.PushBack("买冰箱");
    string_queue.PushBack("什么都要听我的");
    string_queue.PushBack("闹够了没有");
    string_queue.PushBack("我不要你觉得");
    string_queue.PushBack("我要我觉得");

    // 3 打印队头/队尾数据
    string front_data;
    string rear_data;

    string_queue.Front(front_data);
    string_queue.Rear(rear_data);

    cout << "The front of the queue: " << front_data << endl;
    cout << "The rear of the queue: " << rear_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双端队列-清空**
 * @note
 * 测试-双端队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列是否为空**\n
 * + **4 清空**\n
 * + **5 打印队列是否为空**\n
 *
 *
 * ---------------
 */
void Test_DoubleEndedQueue_IsEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoubleEndedQueue Clear                |" << endl;
    cout << "|                    测试-双端队列-清空                     |" << endl << endl << endl;

    // 1 声明队列
    DoubleEndedQueue<string> LinkinPark_song_queue;

    // 2 数据入队队列
    LinkinPark_song_queue.PushBack("<In the end>");
    LinkinPark_song_queue.PushBack("<Crawling>");
    LinkinPark_song_queue.PushBack("<One more light>");

    // 3 打印队列是否为空
    bool is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    // 4 清空
    cout << endl << "call function Clear." << endl << endl;

    LinkinPark_song_queue.Clear();

    // 5 打印队列是否为空
    is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-打印**
 * @note
 * 测试-循环队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 *
 *
 * ---------------
 */
void Test_DoubleEndedQueue_Print() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test DoubleEndedQueue Operator<<             |" << endl;
    cout << "|                  测试-双端队列-operator<<                 |" << endl << endl << endl;

    // 1 声明队列
    DoubleEndedQueue<string> string_queue;

    // 2 数据入队队列
    string_queue.PushBack("听我的");
    string_queue.PushBack("买买买");
    string_queue.PushBack("买冰箱");
    string_queue.PushBack("什么都要听我的");
    string_queue.PushBack("闹够了没有");
    string_queue.PushBack("我不要你觉得");
    string_queue.PushBack("我要我觉得");

    // 3 打印队列
    cout << string_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-队尾出队和队头入队**
 * @note
 * 测试-循环队列-队尾出队和队头入队
 * ---------------------------
 * ---------------------------
 *
 * ---------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列并打印**\n
 * + **3 部分元素出队并打印**\n
 *
 *
 * ---------------------------
 */
void Test_DoubleEndedQueue_PushAndPop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test DoubleEndedQueue Push & Pop             |" << endl;
    cout << "|              测试-双端队列-双向Push/双向Pop               |" << endl << endl << endl;

    // 1 声明队列
    DoubleEndedQueue<int> int_queue;

    // 2 数据入队队列并打印
    int_queue.PushBack(4);
    int_queue.PushBack(3);
    int_queue.PushBack(2);
    int_queue.PushBack(1);
    int_queue.PushFront(4);
    int_queue.PushFront(3);
    int_queue.PushFront(2);
    int_queue.PushFront(1);

    cout << int_queue;

    // 3 部分元素出队并打印
    int_queue.PopFront();
    int_queue.PopFront();
    int_queue.PopBack();
    int_queue.PopBack();

    cout << endl;
    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}
