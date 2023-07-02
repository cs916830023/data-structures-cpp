﻿# 1 内容简介

## 线性表
| 编号 | 结构        | 操作                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ---- |-----------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [顺序表]()   | [默认构造函数&emsp;](/LinearList/src/seq_list.h#L41) [构造函数&emsp;](/LinearList/src/seq_list.h#L110) [复制构造函数&emsp;](/LinearList/src/seq_list.h#L151) [析构函数&emsp;](/LinearList/src/seq_list.h#L50) [插入&emsp;](/LinearList/src/seq_list.h#L395) [删除&emsp;](/LinearList/src/seq_list.h#L453) [获取结点数据&emsp;](/LinearList/src/seq_list.h#L304) [设置结点数据&emsp;](/LinearList/src/seq_list.h#L346) [容量&emsp;](/LinearList/src/seq_list.h#L56) [长度&emsp;](/LinearList/src/seq_list.h#L59) [搜索(查找)&emsp;](/LinearList/src/seq_list.h#L268) [是否空表&emsp;](/LinearList/src/seq_list.h#L501) [是否容量满&emsp;](/LinearList/src/seq_list.h#L528) [排序&emsp;](/LinearList/src/seq_list.h#L643) [打印&emsp;](/LinearList/src/seq_list.h#L611) |
| 2    | [单链表]()   | [默认构造函数&emsp;](/LinearList/src/singly_linked_list.h#L118) [复制构造函数&emsp;](/LinearList/src/singly_linked_list.h#L157) [析构函数&emsp;](/LinearList/src/singly_linked_list.h#L204) [插入(结点指针)&emsp;](/LinearList/src/singly_linked_list.h#L513) [插入(结点数据)&emsp;](/LinearList/src/singly_linked_list.h#L441) [删除&emsp;](/LinearList/src/singly_linked_list.h#L706) [获取结点数据&emsp;](/LinearList/src/singly_linked_list.h#L239) [设置结点数据&emsp;](/LinearList/src/singly_linked_list.h#L288) [长度&emsp;](/LinearList/src/singly_linked_list.h#L69) [搜索&emsp;](/LinearList/src/singly_linked_list.h#L606) [是否空链表&emsp;](/LinearList/src/singly_linked_list.h#L87) [打印&emsp;](/LinearList/src/singly_linked_list.h#L379)       |
| 3    | [双向链表]()  | [默认构造函数&emsp;](/LinearList/src/doubly_linked_list.h#L142) [析构函数&emsp;]() [插入(结点数据)&emsp;]() [删除结点&emsp;]() [获取结点数据&emsp;]() [设置结点数据&emsp;]() [长度&emsp;]() [搜索&emsp;]() [是否空链表&emsp;]() [打印&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 4    | [循环单链表]() | [默认构造函数&emsp;](/LinearList/src/circular_singly_linked_list.h#L63) [析构函数&emsp;]() [长度&emsp;]() [链表是否为空&emsp;]() [清空&emsp;]() [搜索&emsp;]() [获取结点&emsp;]() [插入结点&emsp;]() [删除结点&emsp;]() [获取结点数据&emsp;]() [设置结点数据&emsp;]() [打印&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| 5    | [循环双向表]() | [默认构造函数&emsp;](/LinearList/src/circular_doubly_linked_list.h#L79) [析构函数&emsp;]() [长度&emsp;]() [判断是否为空链表&emsp;]() [清空&emsp;]() [获取链表首结点&emsp;]() [搜索&emsp;]() [获取结点(按方向)&emsp;]() [获取结点&emsp;]() [插入结点&emsp;]() [删除结点(按方向)&emsp;]() [删除结点&emsp;]() [获取结点数据&emsp;]() [设置结点数据&emsp;]() [打印&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                             |
| 6    | [静态链表]()  | [构造函数&emsp;](/LinearList/src/static_linked_list.h#L67) [插入结点(数据项)&emsp;]() [删除结点&emsp;]() [获取结点数据&emsp;]() [设置结点数据&emsp;]() [长度&emsp;]() [搜索&emsp;]() [是否空链表&emsp;]() [打印&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | 
| 7    | [算法]()  | [顺序表求并集&emsp;](/LinearList/src/seq_list_algorithm.h#L27) [顺序表求交集&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | 
## 栈与队列
| 编号 | 结构       | 操作                                                                                                                                                     |
| ---- |----------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [顺序栈]()  | [构造函数&emsp;]() [析构函数&emsp;]() [入栈&emsp;]() [出栈&emsp;]() [出栈(保存数据)&emsp;]() [获取栈顶数据&emsp;]() [判断是否为空栈&emsp;]() [判断是否为满栈&emsp;]() [获取当前栈长度&emsp;]() [重载<<&emsp;]()                                                   |
| 2    | [链式栈]()  | [默认构造函数&emsp;]() [析构函数&emsp;]() [入栈&emsp;]() [出栈&emsp;]() [出栈(保存数据)&emsp;]() [获取栈顶数据&emsp;]() [判断是否为空栈&emsp;]() [获取当前栈长度&emsp;]() [重载<<&emsp;]()                                                                  |                                                              |
| 3    | [循环队列]() | [构造函数&emsp;]() [析构函数&emsp;]() [入队&emsp;]() [出队&emsp;]() [出队(保存数据)&emsp;]() [获取队头数据&emsp;]() [获取队尾数据&emsp;]() [判断是否为空队&emsp;]() [判断是否为满队&emsp;]() [长度&emsp;]() [清空&emsp;]() [重载<<&emsp;]()                                      |
| 4    | [链式队列]() | [默认构造函数&emsp;]() [析构函数&emsp;]() [入队&emsp;]() [出队&emsp;]() [出队(保存数据)&emsp;]() [获取队头数据&emsp;]() [获取队尾数据&emsp;]() [判断是否为空队&emsp;]() [长度&emsp;]() [清空&emsp;]() [重载<<&emsp;]()                                                |
| 5    | [双端队列]() | [构造函数&emsp;]() [析构函数&emsp;]() [队尾入队&emsp;]() [队头入队&emsp;]() [队头出队&emsp;]() [队头出队(保存数据)&emsp;]() [队尾出队&emsp;]() [队尾出队(保存数据)&emsp;]() [获取队头数据&emsp;]() [获取队尾数据&emsp;]() [判断是否为空队&emsp;]() [判断是否为满队&emsp;]() [长度&emsp;]() [清空&emsp;]() [重载<<&emsp;]() |
## 数组和广义表
| 编号 | 结构       | 操作                            |
| ---- |----------|-------------------------------|
| 1    | [稀疏矩阵]() | [转置&emsp;]()  [快速转置&emsp;]()              |
| 2    | [广义表]()  | [建表&emsp;]()  [长度&emsp;]() [深度&emsp;]() [序列化&emsp;]() |
## 字符串
| 编号 | 结构        | 操作                                 |
| ---- |-----------|------------------------------------|
| 1    | [字符串]() | [BF算法&emsp;]()  [KMP算法&emsp;]() [KMP求next数组&emsp;]() |
## 树
| 编号 | 结构           | 操作                                                                                                                                                                                                                                 |
| ---- |--------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [二叉树]()      | [默认构造函数&emsp;]() [构造函数&emsp;]() [复制构造函数&emsp;]() [析构函数&emsp;]() [获取根结点&emsp;]() [是否为空树&emsp;]() [获取父结点&emsp;]() [高度&emsp;]() [结点数&emsp;]() [插入(递归)&emsp;]() [是否存在(数据)&emsp;]() [前序遍历(递归)&emsp;]() [前序遍历&emsp;]() [中序遍历(递归)&emsp;]() [中序遍历&emsp;]() [后序遍历(递归)&emsp;]() [后序遍历&emsp;]() [层序遍历&emsp;]() [建树(by前序遍历和中序遍历)&emsp;]() [打印&emsp;]() [判断两棵树是否相同&emsp;]() |
| 2    | [中序线索树]()    | [创建线索&emsp;]() [获取第1个线索结点&emsp;]() [获取最后一个线索结点&emsp;]() [获取下一个线索结点&emsp;]() [获取前一个线索结点&emsp;]() [获取父结点&emsp;]() [中序遍历&emsp;]() [前序遍历&emsp;]() [后序遍历&emsp;]()                                                                                                                        |
| 3    | [子女兄弟树]()    | [使用带"()"的先根遍历字符串创建子女兄弟树&emsp;]() [是否空树&emsp;]() [结点数(递归)&emsp;]() [高度(递归)&emsp;]() [根结点&emsp;]() [先根遍历&emsp;]() [后根遍历&emsp;]() [层序遍历&emsp;]() [打印(递归)&emsp;]()                                                                                                                      |
| 4    | [Huffman树]() | [构造函数&emsp;]() [析构函数&emsp;]() [生成Huffman编码&emsp;]() [打印&emsp;]()                                                                                                                                                                                           |
| 5    | [堆]()        | [构造函数1&emsp;]() [构造函数2&emsp;]() [析构函数&emsp;]() [插入&emsp;]() [堆顶出堆&emsp;]() [获取堆顶&emsp;]() [是否空堆&emsp;]() [是否满堆&emsp;]() [获取堆大小&emsp;]() [清空堆&emsp;]()                                                                                                                                          |
| 6    | [最小优先队列]()   | [默认构造函数&emsp;]() [构造函数&emsp;]() [入队&emsp;]() [出队&emsp;]() [获取队头&emsp;]() [长度&emsp;]() [清空&emsp;]()                                                                                                                                                                           |
## 图
| 编号 | 结构         | 操作                                                                                                                                                                                       |
| ---- |------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [矩阵图]()    | [构造函数1&emsp;]() [构造函数2&emsp;]() [构造函数3&emsp;]() [构造函数4&emsp;]() [析构函数&emsp;]() [使用结点索引获取结点&emsp;]() [获取边权值&emsp;]() [获取边权值(by结点索引)&emsp;]() [插入结点&emsp;]() [删除结点&emsp;]() [插入边&emsp;]() [删除边&emsp;]() [获取第一个相邻结点&emsp;]() [获取下一个相邻结点&emsp;]() [获取结点索引&emsp;]() [重载<<&emsp;]() [打印邻接矩阵&emsp;]() |
| 2    | [邻接表图]()   | [构造函数1&emsp;]() [构造函数2&emsp;]() [构造函数3&emsp;]() [构造函数4&emsp;]() [析构函数&emsp;]() [使用结点索引获取结点&emsp;]() [获取边权值&emsp;]() [获取边权值(by结点索引)&emsp;]() [插入结点&emsp;]() [删除结点&emsp;]() [插入边&emsp;]() [删除边&emsp;]() [获取第一个相邻结点&emsp;]() [获取下一个相邻结点&emsp;]() [获取结点索引&emsp;]() [重载<<&emsp;]()            |
| 3    | [算法]()     | [深度优先遍历(DFS)&emsp;]() [广度优先遍历(BFS)&emsp;]() [拓扑排序&emsp;]() [连通分量&emsp;]() [最小生成树Prim&emsp;]() [最小生成树Kruskal&emsp;]() [最短路径Dijkstra&emsp;]() [最短路径BellmanFord&emsp;]() [最短路径Floyd&emsp;]() [关键路径&emsp;]()                                             |
## 搜索(查找)
| 编号 | 结构         | 操作                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ---- |------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [线性表搜索]()  | [顺序搜索&emsp;]() [折半搜索&emsp;]()                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 2    | [二叉搜索树]()  | [默认构造函数&emsp;]() [构造函数&emsp;]() [析构函数&emsp;]() [插入结点(调用递归)&emsp;]() [删除结点(调用递归)&emsp;]() [搜索(调用递归)&emsp;]() [高度(调用递归)&emsp;]() [获取最小结点的值&emsp;]() [获取最大结点的值&emsp;]() [获取根结点&emsp;]() [清空(调用递归)&emsp;]() [打印(中序遍历)&emsp;]() [重载=&emsp;]()                                                                                                                                                                                                                                                                        |
| 3    | [AVL树]()   | [默认构造函数&emsp;]() [构造函数1&emsp;]() [构造函数2&emsp;]() [插入结点&emsp;]() [插入节点(递归)&emsp;]() [删除结点&emsp;]() [删除结点(递归)&emsp;]() [高度&emsp;]() [高度(调用递归)&emsp;]() [最大值&emsp;]() [最小值&emsp;]() [搜索&emsp;]() [打印&emsp;]() [子树插入结点(递归)&emsp;]() [子树插入结点&emsp;]() [子树删除结点(递归)&emsp;]() [子树删除结点&emsp;]() [插入动作平衡(by回溯栈)&emsp;]() [删除动作平衡(by回溯栈)&emsp;]() [平衡&emsp;]() [左单旋转(Left Rotation)&emsp;]() [右单旋转(Right Rotation)&emsp;]() [先左后右双旋转(Left Right Rotation)&emsp;]() [先右后左双旋转(Right Left Rotation)&emsp;]() [子树搜索(递归)&emsp;]() [获取(子树中)关键字最小结点&emsp;]() [获取(子树中)关键字最大结点&emsp;]() [获取结点的(中序)前一结点&emsp;]() [子树高度&emsp;]() [子树打印(递归)&emsp;]() |
| 4    | [并查集]()    | [构造函数&emsp;]() [析构函数&emsp;]() [查找(递归)&emsp;]() [查找&emsp;]() [合并&emsp;]() [合并(Weighted)&emsp;]()                                                                                                                                                                                                                                                                                                                                                                       |
## 排序
| 编号 | 结构       | 操作                                                                                                   |
| ---- |----------|------------------------------------------------------------------------------------------------------|
| 1    | [排序]() | [冒泡搜索&emsp;]() [选择搜索&emsp;]() [插入排序&emsp;]() [希尔排序&emsp;]() [归并排序&emsp;]() [快速排序&emsp;]() [快速排序(递归)&emsp;]() [堆排序&emsp;]() [基数排序(链表)&emsp;]() [基数排序(数组)&emsp;]() |


# 2 关于我们
我们是拥有十多年开发经验的开发工程师, 长期就职于各互联网大厂与著名外企.  
如果想更多了解我们，欢迎关注抖音：cyberdash_yuan

**Y_Dash(元哥)**

北邮本硕, 短视频主要出镜人, 底层到应用层, 多年开发经验

**G_Dash(磊哥)**

北邮硕, 10余年安全/系统工程师, 专注C/Linux/网络/安全, 某互联网基础架构部资深工程师

**L_Dash**

北邮硕, 资深开发工程师, 热爱数据结构和算法

# 3 感谢名单

**感谢下列朋友发现代码bug**

LLcu2019205455@163.com 鲁子傲, 1723004698@qq.com 蔡博文, qiaoge77@163.com, 连菜菜 kukakatoo@gmail.com
