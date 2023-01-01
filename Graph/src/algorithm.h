﻿/*!
 * @file graph_algorithm.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法h文件
 * @version 0.2.1
 * @date 2021-02-04
 */

#ifndef CYBER_DASH_GRAPH_ALGORITHM_H
#define CYBER_DASH_GRAPH_ALGORITHM_H


#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include "graph.h"


using namespace std;


/*!
 * @brief **最小生成树边结构体模板**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 最小生成树边结构体
 * ---------------
 * ---------------
 *
 * ---------------
 */
template<typename TVertex, typename TWeight>
struct MinimumSpanTreeEdge {
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * starting_vertex(起点), ending_vertex(终点), weight(边)调用默认构造函数进行初始化
     *
     * ----------
     */
    MinimumSpanTreeEdge(): starting_vertex(TVertex()), ending_vertex(TVertex()), weight(TWeight()) {};

    /*!
     * @brief **构造函数(边权值)**
     * @param weight 边权值
     * @note
     * 构造函数(边权值)
     * --------------
     * --------------
     *
     * --------------
     */
    explicit MinimumSpanTreeEdge(const TWeight& weight): starting_vertex(TVertex()), ending_vertex(TVertex()), weight(weight) {}

    /*!
     * @brief **构造函数(边权值/起点/终点)**
     * @param weight 边权值
     * @param starting_vertex 起点
     * @param ending_vertex 终点
     * @note
     * 构造函数(边权值/起点/终点)
     * -----------------------
     * -----------------------
     *
     * -----------------------
     */
    MinimumSpanTreeEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight):
      weight(weight), starting_vertex(starting_vertex), ending_vertex(ending_vertex) {}

    /*!
     * @brief **重载<=**
     * @param mst_edge 最小生成树边
     * @return 执行结果
     * @note
     * 重载<=
     * -----
     * -----
     *
     * -----
     */
    bool operator<=(const MinimumSpanTreeEdge<TVertex, TWeight>& mst_edge) { return weight <= mst_edge.weight; }

    /*!
     * @brief **重载>=**
     * @param mst_edge MST结点
     * @return 执行结果
     * @note
     * 重载>=
     * -----
     * -----
     *
     * -----
     */
    bool operator>=(const MinimumSpanTreeEdge<TVertex, TWeight>& mst_edge) { return weight >= mst_edge.weight; }

    /*!
     * @brief **重载>**
     * @param mst_edge 最小生成树边
     * @return 执行结果
     * @note
     * 重载>
     * ----
     * ----
     *
     * ----
     */
    bool operator>(const MinimumSpanTreeEdge<TVertex, TWeight>& mst_edge) { return weight > mst_edge.weight; }

    /*!
     * @brief **重载&lt;**
     * @param mst_edge 最小生成树边
     * @return 执行结果
     * @note
     * 重载<
     * ----
     * ----
     *
     * <span style="color:#DF5A00">
     * doxygen处理less-than符号(&lt;)不是很友好, 所以注释中使用"\&lt;"来表达&lt;
     * </span>
     *
     * ----
     */
    bool operator<(const MinimumSpanTreeEdge<TVertex, TWeight>& mst_edge) { return weight < mst_edge.weight; }

    TVertex ending_vertex;    //!< 起点
    TVertex starting_vertex;  //!< 终点
    TWeight weight;           //!< 边权重
};


/*!
 * @brief 最小生成树模板类
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 最小生成树模板类
 * --------------
 * --------------
 *
 * --------------
 * 最小生成树的大多数算法, 利用了MST性质:
 *     假设N = { TVertex(结点), { E(边) } }是一个连通网, U是顶点集V的一个非空子集.
 *     若
 *         (u, v)是一条具有最小权值的边, 其中u ∈ U, v ∈ TVertex - U,
 *     则
 *         必存在一颗包含边(u, v)的最小生成树
 */
template<typename TVertex, typename TWeight>
class MinimumSpanTree {
public:

    /*!
     * @brief **构造函数**
     * @param max_size 边数上限
     * @note
     * 构造函数
     * -------
     * -------
     *
     * -------
     */
    explicit MinimumSpanTree(int max_size): max_size_(max_size), size_(0) {
        this->mst_edges_ = new MinimumSpanTreeEdge<TVertex, TWeight>[max_size];
    }

    /*!
     * @brief 向MST插入边
     * @param mst_edge MST边
     * @return 当前最小生成树边的数量
     */
    int Insert(MinimumSpanTreeEdge<TVertex, TWeight>& mst_edge) {
        if (size_ >= max_size_) {
            return -1;
        }

        mst_edges_[size_] = mst_edge;
        size_++;

        return size_ - 1;
    }

    /*! @brief 显示最小生成树 */
    void Print() {
        TWeight total_weight = 0; // 总权值
        for (int i = 0; i < this->size_; i++) {
            total_weight += this->mst_edges_[i].weight;
            cout << "starting_vertex: " << this->mst_edges_[i].starting_vertex
                 << ", ending_vertex: " << mst_edges_[i].ending_vertex
                 << ", weight: " << mst_edges_[i].weight << endl;
        }

        cout << "最小生成树边, 总权值: " << total_weight << endl;
    }

protected:
    MinimumSpanTreeEdge<TVertex, TWeight>* mst_edges_; //!< 最小生成树边数组
    int max_size_;    //!< 边数上限
    int size_;        //!< 当前边数量
};


// 图深度优先遍历
template<typename TVertex, typename TWeight>
void DfsRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex);


// 图深度优先遍历(递归)
template<typename TVertex, typename TWeight>
void DfsOnVertexRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex, set<TVertex>& visited_vertex_set);


// 图广度优先遍历
template<typename TVertex, typename TWeight>
void Bfs(const Graph<TVertex, TWeight>& graph, const TVertex& vertex);


// 求图的连通分量
template<typename TVertex, typename TWeight>
int Components(const Graph<TVertex, TWeight>& graph);


// Prim算法
template<typename TVertex, typename TWeight>
bool Prim(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree);


// Kruskal最小生成树(优先队列)
template<typename TVertex, typename TWeight>
void Kruskal(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree);


// 迪杰斯特拉(Dijkstra)最短路径
template<typename TVertex, typename TWeight>
void Dijkstra(const Graph<TVertex, TWeight>& graph,
              const TVertex& starting_vertex,
              TWeight distance[],
              int predecessor[]);


// 迪杰斯特拉(Dijkstra)最短路径(优先队列)
template<class Vertex, class Weight>
void DijkstraByPriorityQueue(const Graph<Vertex, Weight>& graph,
                             Vertex starting_vertex,
                             Weight distance[],
                             int predecessor[]);

// 迪杰斯特拉(Dijkstra)最短路径2(优先队列, 优先队列控制循环)
template<class Vertex, class Weight>
void DijkstraByPriorityQueue2(Graph<Vertex, Weight>& graph,
                             Vertex starting_vertex,
                             Weight distance[],
                             int predecessor[]);

// 迪杰斯特拉(Dijkstra)最短路径2(stl优先队列)
template<class Vertex, class Weight>
void DijkstraByStlPriorityQueue(Graph<Vertex, Weight>& graph,
                              Vertex starting_vertex,
                              Weight distance[],
                              int predecessor[]);


// 贝尔曼福特(Bellman-Ford)最短路径
template<class Vertex, class Weight>
bool BellmanFord(const Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


// 弗洛伊德(Floyd-Warshall)最短路径
template<class Vertex, class Weight>
void Floyd(const Graph<Vertex, Weight>& graph, vector<vector<Weight> >& distance, vector<vector<int> >& predecessor);


// 打印单源最短路径(迪杰斯特拉Dijkstra, 贝尔曼福特BellmanFord等)
template<typename TVertex, typename TWeight>
void PrintSingleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                   TVertex starting_vertex,
                                   TWeight distance[],
                                   const int predecessor[]);


// 打印多源最短路径(弗洛伊德Floyd等)
template<typename TVertex, typename TWeight>
void PrintMultipleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                     vector<vector<TWeight> > distance,
                                     vector<vector<int> > predecessor);


#endif // CYBER_DASH_GRAPH_ALGORITHM_H
