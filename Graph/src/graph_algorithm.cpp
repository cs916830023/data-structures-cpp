/*!
 * @file graph_algorithm.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼ�㷨.cpp�ļ�
 * @version 0.2.1
 * @date 2021-02-04
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "graph_algorithm.h"
#include <iostream>


/*!
 * @brief ͼ������ȱ���
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param vertex ������ʼ���
 */
template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex) {

  set<T> visited_vertex_set;

  DFSOnVertex(graph, vertex, visited_vertex_set);
}


/*!
 * @brief ͼ������ȱ���(�ݹ�)
 * @tparam T �ڵ�����ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param vertex ������ʼ���
 * @param visited_vertex_set �ѷ��ʽڵ㼯��
 * @note ���ú����ĵ��ù�ϵ��ģ��ջ
 */
template<class T, class E>
void DFSOnVertex(Graph<T, E>& graph, T vertex, set<T>& visited_vertex_set) {

  cout<<"Vertex: "<<vertex<<endl;

  visited_vertex_set.insert(vertex);

  T neighbor_vertex;
  bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

  while (has_neighbor) {
    if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
      DFSOnVertex(graph, neighbor_vertex, visited_vertex_set);
    }

    T next_neighbor_vertex;
    has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

    if (has_neighbor) {
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief ͼ������ȱ���
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param vertex ������ʼ���
 * @note
 * ʹ�ö��н��й�����ȱ���
 */
template<class T, class E>
void BFS(Graph<T, E>& graph, const T& vertex) {

  set<T> visited_vertex_set;
  visited_vertex_set.insert(vertex);

  queue<T> vertex_queue;
  vertex_queue.push(vertex); // ������ʼ��������

  cout<<"Vertex "<<vertex<<endl;

  while (!vertex_queue.empty()) {
    T front_vertex = vertex_queue.front(); // ÿ��ȡ��ͷ
    vertex_queue.pop();

    // ��ȡ���Ķ�ͷ�������ڽ�����
    T neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, front_vertex);

    while (has_neighbor) {
      if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
        cout<<"Vertex "<<neighbor_vertex<<endl;

        visited_vertex_set.insert(neighbor_vertex);

        vertex_queue.push(neighbor_vertex);
      }

      T next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, front_vertex, neighbor_vertex);
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief ��ͼ����ͨ����
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @note
 * 1. ʹ��visited_vertex_set�����Ѿ��������Ľڵ�
 * 2. ÿ����һ���ڵ�vertex
 *   �����visited_vertex_set��, ���Ѿ���ĳ��ͨ������, ���ٴ���;
 *   �������visited_vertex_set��, ʹ��DFS��vertex���б���, ��ͨ��������+1
 */
template<class T, class E>
void Components(Graph<T, E>& graph) {

  int vertices_num = graph.NumberOfVertices(); // ͼ�ڽڵ������
  set<T> visited_vertex_set; // ʹ��set�����Ѿ��������Ľڵ�

  int component_index = 1; // ��ʼ��ͨ����Ϊ1

  for (int i = 0; i < vertices_num; i++) {

    T vertex;
    bool done = graph.GetVertexByIndex(vertex, i); // ��ȡ����i��Ӧ�Ľڵ�vertex

    if (done) {
      // ���visited_vertex_set��, û�в鵽vertex, ˵��vertex��һ���µ���ͨ������
      // ��vertexִ��DFS����(���е��㷨, ʹ��BFSҲ����)
      if (visited_vertex_set.find(vertex) == visited_vertex_set.end()) {
        cout<<"��ͨ����"<<component_index<<":"<<endl;
        DFSOnVertex(graph, vertex, visited_vertex_set);

        component_index++; // ��ͨ��������+1
        cout<<endl;
      }
    }
  }
}


/*!
 * @brief Kruskal�㷨
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param min_span_tree ��С������
 */
template<class T, class E>
void Kruskal(Graph<T, E>& graph, MinSpanTree<T, E>& min_span_tree) {

  MSTEdgeNode<T, E> edge_node;

  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<T, E> > min_heap(edge_num);

  DisjointSet disjoint_set(vertex_num);

  for (int u = 0; u < vertex_num; ++u) {
    for (int v = u + 1; v < vertex_num; v++) {
      T vertex_u;
      T vertex_v;
      graph.GetVertexByIndex(vertex_u, u);
      graph.GetVertexByIndex(vertex_v, v);

      E weight;
      bool get_weight_done = graph.GetWeight(weight, vertex_u, vertex_v);
      if (get_weight_done) {
        edge_node.tail = vertex_u;
        edge_node.head = vertex_v;
        edge_node.weight = weight;

        min_heap.Insert(edge_node);
      }

    }
  }

  int count = 1;

  while (count < vertex_num) {
    min_heap.RemoveMin(edge_node);


    int tail_idx = graph.GetVertexIndex(edge_node.tail);
    int head_idx = graph.GetVertexIndex(edge_node.head);

    int tail_root_idx = disjoint_set.Find(tail_idx);
    int head_root_idx = disjoint_set.Find(head_idx);

    if (tail_root_idx != head_root_idx) {
      disjoint_set.Union(tail_root_idx, head_root_idx);

      min_span_tree.Insert(edge_node);
      count++;
    }
  }
}


/*!
 * @brief Prim�㷨(�Ż�)
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param vertex ��ʼ�ڵ�(��ʼ���Բ����������, �ο��̿���, �˴�����)
 * @param min_span_tree ��С������
 * @note
 * ��������̲ĵ�ʵ��, ��Ϊ�����Ż��İ汾, �Ż����ڶѵĲ���
 */
template<class T, class E>
void PrimPlus(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree) {

  MSTEdgeNode<T, E> mst_edge_node;

  int count = 1; // ��ʼvertex����mst�ڵ㼯��, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<T, E> > min_heap(edge_num);

  set<T> mst_vertex_set; // ԭ���е�Vmst
  mst_vertex_set.insert(vertex);

  do {
    T neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

    while (has_neighbor) {
      if (mst_vertex_set.find(neighbor_vertex) == mst_vertex_set.end()) {

        mst_edge_node.tail = vertex;
        mst_edge_node.head = neighbor_vertex;

        graph.GetWeight(mst_edge_node.weight, vertex, neighbor_vertex);

        min_heap.Insert(mst_edge_node);
      }

      T next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

      if (has_neighbor) {
        neighbor_vertex = next_neighbor_vertex;
      }
    }

    while (min_heap.IsEmpty() == false && count < vertex_num) {

      min_heap.RemoveMin(mst_edge_node);

      if (mst_vertex_set.find(mst_edge_node.head) == mst_vertex_set.end()) {
        min_span_tree.Insert(mst_edge_node);

        vertex = mst_edge_node.head;
        mst_vertex_set.insert(vertex);
        count++;

        break;
      }
    }
  } while (count < vertex_num);
}


/*!
 * @brief Prim�㷨ʵ��
 * @tparam Vertex �������ģ�����
 * @tparam Weight ��Ȩֵ����ģ�����
 * @param graph ͼ
 * @param vertex ��ʼ�ڵ�(��ʵ���Բ����������, ���ս̿���, �˴�����)
 * @param min_span_tree ��С������
 */
template<class Vertex, class Weight>
void Prim(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree) {

  MSTEdgeNode<Vertex, Weight> mst_edge_node;

  int count = 1; // ��ʼvertex����mst�ڵ㼯��, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  set<Vertex> mst_vertex_set; // ԭ���е�Vmst
  mst_vertex_set.insert(vertex);

  do {

    MinHeap<MSTEdgeNode<Vertex, Weight> > min_heap(edge_num);

    for (typename set<Vertex>::iterator set_iter = mst_vertex_set.begin(); set_iter != mst_vertex_set.end(); set_iter++) {
      vertex = *set_iter;

      Vertex neighbor_vertex;
      bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

      while (has_neighbor) {
        if (mst_vertex_set.find(neighbor_vertex) == mst_vertex_set.end()) {

          mst_edge_node.tail = vertex;
          mst_edge_node.head = neighbor_vertex;

          graph.GetWeight(mst_edge_node.weight, vertex, neighbor_vertex);

          min_heap.Insert(mst_edge_node);
        }

        Vertex next_neighbor_vertex;
        has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

        if (has_neighbor) {
          neighbor_vertex = next_neighbor_vertex;
        }
      }
    }

    min_heap.RemoveMin(mst_edge_node);

    min_span_tree.Insert(mst_edge_node);

    vertex = mst_edge_node.head;
    mst_vertex_set.insert(vertex);
    count++;

  } while (count < vertex_num);
}


/**
 * @brief �Ͻ�˹����(Dijkstra)���·��
 * @tparam Vertex ͼ�ڵ�ģ������
 * @tparam Weight ͼ��Ȩֵģ������
 * @param graph ͼ����
 * @param origin_vertex ��ʼ�ڵ�
 * @param min_dist_arr ���·������, dist[i]��ʾ: ·����ʼ�ڵ㵽����i�ڵ�����·����Ȩֵ
 * @param from_path_arr ·������, from_path_arr[i]��ʾ: ������i�ڵ�Ϊ�յ�ıߵ���ʼ�ڵ�
 * @note ̰���㷨
 */
template<class Vertex, class Weight>
void DijkstraShortestPath(Graph<Vertex, Weight>& graph,
                          Vertex origin_vertex,
                          Weight min_dist_arr[],
                          int from_path_arr[])
{
  int vertex_num = graph.NumberOfVertices();
  set<Vertex> vertex_set;
  int origin_vertex_idx = graph.GetVertexIndex(origin_vertex); // origin_vertex�ڵ������

  // ��ʼ��
  for (int i = 0; i < vertex_num; i++) {

    // ��ȡ����i��Ӧ�Ľڵ�vertex_i
    Vertex vertex_i;
    bool get_vertex_done = graph.GetVertexByIndex(vertex_i, i);
    /* error handler */

    // ����(origin_vertex --> vertex_i)��ֵ, ���浽min_dist_arr[i], ���������, ��min_dist_arr[i]ΪMAX_WEIGHT
    bool get_weight_done = graph.GetWeight(min_dist_arr[i], origin_vertex, vertex_i);
    if (!get_weight_done) {
      min_dist_arr[i] = (Weight)MAX_WEIGHT;
    }

    // �����(origin_vertex --> vertex_i)����, ��from_path_arr[i]��ֵ, Ϊ����origin_vertex_idx; ����Ϊ-1
    if (vertex_i != origin_vertex && get_weight_done && get_vertex_done) {
      from_path_arr[i] = origin_vertex_idx;
    } else {
      from_path_arr[i] = -1;
    }
  }

  // �ڵ�origin_vertex���뵽����vertex_set
  vertex_set.insert(origin_vertex);
  min_dist_arr[origin_vertex_idx] = 0;

  // ��ͼ������vertex_num - 1���ڵ�, ����̰�Ĳ���, ִ���㷨, �����뵽����vertex_set
  for (int i = 0; i < vertex_num - 1; i++) {
    Weight cur_min_dist = (Weight)MAX_WEIGHT; // ��origin_vertexΪ���, ĳ���ڵ�Ϊ�յ�����·��(��ǰ���·��)
    Vertex cur_min_dist_dest_vertex; // ��ǰ���·�����յ�

    // ԭ�㵽���ڵ��е����·��, ���浽cur_min_dist(��ǰ���·��), ������cur_min_dist_dest_vertex(��ǰ���·���յ�)
    for (int j = 0; j < vertex_num; j++) {

      // �õ�����j��Ӧ�Ľڵ�vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // ���idx_j_vertex�Ѿ���vertex_set��, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      if (min_dist_arr[j] < cur_min_dist)
      {
        cur_min_dist_dest_vertex = vertex_j;
        cur_min_dist = min_dist_arr[j];
      }
    }

    vertex_set.insert(cur_min_dist_dest_vertex); // ��cur_min_dist_dest_vertex���뵽vertex_set

    int cur_min_dist_dest_vertex_idx = graph.GetVertexIndex(cur_min_dist_dest_vertex);

    // Dijkstra�����㷨
    for (int j = 0; j < vertex_num; j++) {
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // ���idx_j_vertex�Ѿ���vertex_set��, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // ��(cur_min_dist_dest_vertex --> vertex_j)��ֵ, ����weight
      Weight weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_dist_dest_vertex, vertex_j);
      if (!get_weight_done) {
        continue; // ���û�б�
      }

      // ���
      // ��(origin_vertex --> cur_min_dist_dest_vertex)��weight
      //  +
      // ��(cur_min_dist_dest_vertex --> dix_j_vertex)��weight(Ҳ���Ǳ���weight)
      //  <
      // ��(origin_vertex --> dix_j_vertex)��weight
      // ����min_dist_arr[j]��from_path_arr[j]
      if (min_dist_arr[cur_min_dist_dest_vertex_idx] + weight < min_dist_arr[j])
      {
        min_dist_arr[j] = min_dist_arr[cur_min_dist_dest_vertex_idx] + weight;
        from_path_arr[j] = cur_min_dist_dest_vertex_idx;
      }
    }
  }
}


/*!
 * @brief ��ʾ�Ͻ�˹����(Dijkstra)���·��
 * @tparam T �������ģ�����
 * @tparam E ��Ȩֵ����ģ�����
 * @param graph ͼ����
 * @param origin_vertex ·����ʼ�ڵ�
 * @param min_dist_arr ���·������, dist[i]��ʾ: ·����ʼ�ڵ㵽����i�ڵ�����·����Ȩֵ
 * @param from_path_arr ·������, from_path_arr[i]��ʾ: ������i�ڵ�Ϊ�յ�ıߵ���ʼ�ڵ�
 */
template<class T, class E>
void PrintDijkstraShortestPath(Graph<T, E>& graph, T origin_vertex, E min_dist_arr[], int from_path_arr[]) {
  cout << "�Ӷ���" << origin_vertex << "����������������·��Ϊ: " << endl;

  int vertex_count = graph.NumberOfVertices();
  int origin_vertex_idx = graph.GetVertexIndex(origin_vertex);

  // ���ڴ����ĳ���ڵ�Ϊ�յ�����·�������Ľڵ�
  int* cur_pre_path_arr = new int[vertex_count];
  /* error handler */

  // �ֱ���ʾorigin_vertex�������ڵ�����·��
  for (int i = 0; i < vertex_count; i++) {
    if (i == origin_vertex_idx) {
      continue;
    }

    int pre_vertex_idx = i; // ������i�ڵ�Ϊ�յ�
    int idx = 0;

    while (pre_vertex_idx != origin_vertex_idx) {
      cur_pre_path_arr[idx] = pre_vertex_idx;
      idx++;
      pre_vertex_idx = from_path_arr[pre_vertex_idx];
    }

    // ��ȡ����i�Ľڵ�
    T idx_i_vertex;
    graph.GetVertexByIndex(idx_i_vertex, i);

    cout << "����" << idx_i_vertex << "�����·��Ϊ:" << origin_vertex << " ";

    while (idx > 0) {
      idx--;
      graph.GetVertexByIndex(idx_i_vertex, cur_pre_path_arr[idx]);
      cout << idx_i_vertex << " ";
    }

    cout << "���·������Ϊ:" << min_dist_arr[i] << endl;
  }

  delete[] cur_pre_path_arr;
}


