/*!
 * @file graph_algorithm.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼ�㷨.h�ļ�
 * @version 0.2.1
 * @date 2021-02-04
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_GRAPH_ALGORITHM_H
#define CYBER_DASH_GRAPH_ALGORITHM_H


#include <iostream>
#include "graph.h"
#include <set>
#include <queue>

#include "min_heap.h"
#include "disjoint_set.h"


using namespace std;


// ͼ������ȱ���
template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex);


// ͼ������ȱ���(�ݹ�)
template<class T, class E>
void DFSOnVertex(Graph<T, E>& graph, T vertex, set<T>& visited_vertex_set);


// ͼ������ȱ���
template<class T, class E>
void BFS(Graph<T, E>& graph, const T& vertex);


// ��ͼ����ͨ����
template<class T, class E>
void Components(Graph<T, E>& graph);


/*!
 * @brief ��С���������ṹ��
 */
template<class V, class W>
struct MSTEdgeNode {
  /*! @brief ���캯��(�ղ���) */
  MSTEdgeNode() {}
  /*! @brief ���캯��() */
  MSTEdgeNode(W value): weight(value) {}
  /*! @brief ����<= */
  bool operator<=(MSTEdgeNode<V, W>& node) { return weight <= node.weight; }
  /*! @brief ����> */
  bool operator>(MSTEdgeNode<V, W>& node) { return weight > node.weight; }

  V tail; //!< β���
  V head; //!< ͷ���
  W weight; //!< ��Ȩ��
};


/*!
 * @brief ��С������ģ����
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 */
template<class T, class E>
class MinSpanTree {
protected:
  MSTEdgeNode<T, E>* edge_node_array_; //!< ��С�������������
  int max_size_; //!< �������
  int cur_size_; //!< ��ǰ�������Ľڵ�����
public:
  // ���캯��
  MinSpanTree(int size): max_size_(size), cur_size_(0) {
    edge_node_array_ = new MSTEdgeNode<T, E>[size];
  }

  // ��edge_node_array_������
  int Insert(MSTEdgeNode<T, E>& edge_node) {
    if (cur_size_ >= max_size_) {
      return -1;
    }

    edge_node_array_[cur_size_] = edge_node;
    cur_size_++;

    return cur_size_ - 1;
  }

  /*! @brief ��ʾ��С������ */
  void Show() {
    E sum = 0;
    for (int i = 0; i < cur_size_; i++) {
      sum += edge_node_array_[i].weight;
      cout << "head: " << edge_node_array_[i].head << ", tail: " << edge_node_array_[i].tail << ", weight: "
           << edge_node_array_[i].weight << endl;
    }

    cout<<"��С��������, ��Ȩֵ: "<<sum<<endl;
  }
};


// Kruskal��С������
template<class T, class E>
void Kruskal(Graph<T, E>& graph, MinSpanTree<T, E>& min_span_tree);


// Prim(Plus)
template<class T, class E>
void PrimPlus(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree);


// Prim�㷨����ʵ��
template<class T, class E>
void Prim(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree);


// �Ͻ�˹����(Dijkstra)���·��
template<class T, class E>
void DijkstraShortestPath(Graph<T, E>& graph, T origin_vertex, E min_dist_arr[], int from_path_arr[]);


// ��ʾ�Ͻ�˹����(Dijkstra)���·��
template<class T, class E>
void PrintDijkstraShortestPath(Graph<T, E>& graph, T origin_vertex, E min_dist_arr[], int from_path_arr[]);


#endif // CYBER_DASH_GRAPH_ALGORITHM_H
