﻿# CyberDash数据结构开源代码  
----------------------------- 

我们的数据结构C语言版本

传送门：https://gitee.com/cyberdash/data-structure-c

-----------------------------
# 1 简介
## 1.1 配套书籍
通用C++数据结构书籍，如果使用C++模板，那是最好的:-)  

## 1.2 代码运行环境  
目前在Linux和Mac环境已经测试通过。

**Linux测试环境**

    kernel >= 3.10
    cmake：3.13
    doxygen: 1.9.2
**Mac测试环境**

    MAC OS BigSur（11.2.1）
    cmake：3.13
    doxygen: 1.9.2


## 1.3 代码规范与风格
**代码规范**  
标准编码规范，参考文档连接:  
https://github.com/zh-google-styleguide/zh-google-styleguide/tree/master/google-cpp-styleguide

**使用STL**  
部分代码(例如图)(大量)使用STL, 参考文档或者<C++ Primer>

**C++特性**  
考虑很多读者是学生和初学者, 使用C++98

# 2 使用方式
为了方便分类, 项目主目录下, 每个目录对应一个独立的项目
## 2.1 构建与运行
    git clone https://gitee.com/cyberdash/data-structure-cpp.git
    # 进入目录
    cd data-structure-cpp/<dir>
    # 构建
    cmake3 .
    make
    # 执行程序
    ./main


# 3 内容简介

## 线性表
| 编号 | 结构        | 操作                                                                                                      |
| ---- |-----------|---------------------------------------------------------------------------------------------------------|
| 1    | [顺序表]()   | [插入]()  [删除]() [获取结点数据]() [设置结点数据]() [容量]() [长度]() [搜索(查找)]() [是否空表]() [是否容量满]() [排序]() [打印]() [重载<<]() |
| 2    | [单链表]()   | [插入(结点指针)]() [插入(结点数据)]() [删除]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                   |
| 3    | [双向链表]()  | [插入(结点数据)]() [删除结点]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                              |
| 4    | [循环单链表]() | [插入结点(数据项)]() [删除结点]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                             |
| 5    | [循环双向表]() | [插入结点(数据项)]() [删除结点]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                             |
| 6    | [静态链表]()  | [插入结点(数据项)]() [删除结点]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                             | 
| 7    | [常见算法]()  | [插入结点(数据项)]() [删除结点]() [获取结点数据]() [设置结点数据]() [长度]() [搜索]() [是否空链表]() [打印]()                             | 
## 栈与队列
| 编号 | 结构       | 操作                                                          |
| ---- |----------|-------------------------------------------------------------|
| 1    | [顺序栈]()  | [入栈]()  [出栈]() [出栈(保存数据)]() [获取栈顶]() [排序]() [打印]() [重载<<]() |
| 2    | [链式栈]()  | [入栈]()  [出栈]() [出栈(保存数据)]() [获取栈顶]() [排序]() [打印]() [重载<<]() |                                                              |
| 3    | [循环队列]() | [入队]()  [出栈]() [出栈(保存数据)]() [获取栈顶]() [排序]() [打印]() [重载<<]() |
| 4    | [链式队列]() | [入队]()  [出栈]() [出栈(保存数据)]() [获取栈顶]() [排序]() [打印]() [重载<<]() |                                                              |
| 5    | [双端队列]() | [入队]()  [出栈]() [出栈(保存数据)]() [获取栈顶]() [排序]() [打印]() [重载<<]() |                                                              |
## 数组和广义表
| 编号 | 结构       | 操作                            |
| ---- |----------|-------------------------------|
| 1    | [稀疏矩阵]() | [转置]()  [快速转置]()              |
| 2    | [广义表]()  | [建表]()  [长度]() [深度]() [序列化]() |
## 字符串
| 编号 | 结构        | 操作                                                                 |
| ---- |-----------|--------------------------------------------------------------------|
| 1    | [字符串]() | [BF算法]()  [KMP算法]() |
## 树
| 编号 | 结构           | 操作                                                                 |
| ---- |--------------|--------------------------------------------------------------------|
| 1    | [二叉树]()      | |
| 2    | [线索树]()      | |
| 3    | [子女兄弟树]()    | |
| 4    | [Huffman树]() | |
| 5    | [堆]()        | |
## 图
| 编号 | 结构       | 操作                                                                                                                                                                                       |
| ---- |----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | [矩阵图]()  | [构造函数1]() [构造函数2]() [构造函数3]() [构造函数4]() [析构函数]() [使用结点索引获取结点]() [获取边权值]() [获取边权值(by结点索引)]() [插入结点]() [删除结点]() [插入边]() [删除边]() [获取第一个相邻结点]() [获取下一个相邻结点]() [获取结点索引]() [重载<<]() [打印邻接矩阵]() |
| 2    | [邻接表图]() | [构造函数1]() [构造函数2]() [构造函数3]() [构造函数4]() [析构函数]() [使用结点索引获取结点]() [获取边权值]() [获取边权值(by结点索引)]() [插入结点]() [删除结点]() [插入边]() [删除边]() [获取第一个相邻结点]() [获取下一个相邻结点]() [获取结点索引]() [重载<<]()            |
| 3    | [算法]()   | [深度优先遍历(DFS)]() [广度优先遍历(BFS)]() [拓扑排序]() [连通分量]() [最小生成树Prim]() [最小生成树Kruskal]() [最短路径Dijkstra]() [最短路径BellmanFord]() [最短路径Floyd]() [关键路径]()                                             |
## 搜索
| 编号 | 结构        | 操作                |
| ---- |-----------|-------------------|
| 1    | [线性表搜索]() | [顺序搜索]() [折半搜索]() |
| 2    | [二叉搜索树]() | |
| 3    | [AVL树]()  | |
## 排序
| 编号 | 结构       | 操作                                                                                                   |
| ---- |----------|------------------------------------------------------------------------------------------------------|
| 1    | [排序]() | [冒泡搜索]() [选择搜索]() [插入排序]() [希尔排序]() [归并排序]() [快速排序]() [快速排序(递归)]() [堆排序]() [基数排序(链表)]() [基数排序(数组)]() |

## 4 Doxygen生成文档
### 4.1 Doxygen配置文件
每个代码目录下的cyber_dash_doxygen_config文件为doxygen的配置文件
### 4.2 Doxygen生成文件
可以使用doxygen命令生成每个测试项目的文档
    doxygen cyber_dash_doxygen_config
执行成功之后可以去html目录下打开index.html阅读使用说明

### 4.3 生成PDF文件
doxygen配置文件将GENERATE_LATEX/LATEX_OUTPUT/USE_PDFLATEX/PDF_HYPERLINKS设置为YES

打开latex目录中的refman.tex,  
找到"\begin{document}"这一行, 改为
```
\usepackage{CJKutf8}
\begin{document}
\begin{CJK}{UTF8}{gbsn}
```
找到"\end{document}"这一行, 改为
```
\end{CJK}
\end{document}
```


## 5 关于我们
我们是拥有十多年开发经验的开发工程师, 长期就职于各传统与互联网大厂.  
目前在做计算机考研相关的内容, 如果想更多了解我们，欢迎关注抖音：cyberdash_yuan

**Y_Dash(元哥)**

用过很多语言, 做过很多项目, 从底层到应用层, 安全/服务/社区/IoT/...  
写代码能剪裁kernel, 吹拉谈唱能去欧洲做展会讲解, 从外太空到内XX, 五花八门什么都略懂一些

**G_Dash(磊哥)**

10多年安全/系统工程师, 专注C/Linux/网络/安全, 某互联网基础架构部资深工程师, 元哥身后稳如磐石的男人

**L_Dash**

资深测试开发工程师, 热爱数据结构和算法

## 6 感谢名单

**感谢下列朋友发现代码bug**

LLcu2019205455@163.com 鲁子傲, 1723004698@qq.com 蔡博文, qiaoge77@163.com, 连菜菜 kukakatoo@gmail.com

## 7 你好有缘人

