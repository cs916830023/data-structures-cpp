/*!
 * @file adjacency_list_graph.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �ڽӱ�ͼģ����
 * @version 0.2.1
 * @date 2021-01-16
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_ADJACENCY_LIST_GRAPH_H
#define CYBER_DASH_ADJACENCY_LIST_GRAPH_H


#include <iostream>
#include <cstdlib>
#include "graph.h"


using namespace std;


/*!
 * @brief �ڽӱ�ͼ�߽ṹ��ģ��
 * @tparam V
 * @tparam W
 */
template <class V, class W>
struct Edge {
  /*! @brief ���캯��(�޲���) */
  Edge() {}

  /*! @brief ���캯��(���յ�Ľ������and��Ȩ��) */
  Edge(int num, W weight): dest_index(num), weight(weight), next(NULL) {}

  /*! @brief ����!= */
  bool operator != (Edge<V, W>& edge) const {
    return (dest_index != edge.dest_index);
  }

  int dest_index; //!< ���յ�Ľ������
  W weight; //!< ��Ȩ��
  Edge<V, W>* next; //!< ��һ�ڽӱ�ͼ�ߵ�ָ��
};


/*!
 * @brief �ڽӱ�ͼ�ڵ�ṹ��
 * @tparam V ������ģ������
 * @tparam W ��Ȩֵ����ģ������
 */
template<class V, class W>
struct Vertex {
  V vertex; //!< ���
  Edge<V, W>* adjacency_list; //!< �ڽӱ�
};


/*!
 * @brief �ڽӱ�ͼģ����
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 */
template<class V, class W>
class AdjacencyListGraph: public Graph<V, W> {
public:

  // ���캯��
  AdjacencyListGraph(int size = DEFAULT_VERTICES);

  // ��������
  ~AdjacencyListGraph();

  /**
   * @brief ʹ�ý��������ȡ���
   * @param vertex ���(�������Ľڵ�)
   * @param vertex_index �������
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetVertexByIndex(V& vertex, int vertex_index);

  /**
   * @brief ��ȡ��Ȩֵ
   * @param weight ��Ȩֵ(���ڱ�����)
   * @param vertex1 �ߵĽڵ�1
   * @param vertex2 �ߵĽڵ�2
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetWeight(W& weight, V vertex1, V vertex2);

  // ������
  bool InsertVertex(const V& vertex);

  // ɾ�����
  bool RemoveVertex(V vertex);

  // �����
  bool InsertEdge(V vertex1, V vertex2, W weight);

  // ɾ����
  bool RemoveEdge(V vertex1, V vertex2);

  // ��ȡ��һ�����ڽ��
  bool GetFirstNeighborVertex(V& first_neighbor, const V& vertex);

  // ��ȡ��һ�����ڽ��
  bool GetNextNeighborVertex(V& next_neighbor, const V& vertex, const V& neighbor_vertex);

  // ��ȡ�������
  int GetVertexIndex(V vertex);

  // ����ͼ(���ر�׼����)
  template<class U>
  friend istream& operator>>(istream& in, AdjacencyListGraph<V, W>& graph_adjacency_list);
  // ��ӡͼ(���ر�׼���)
  template<class U>
  friend ostream& operator<<(ostream& out, AdjacencyListGraph<V, W>& graph_adjacency_list);

  /*! @brief ������CyberDash :-) */
  void CyberDashShow();
private:
  Vertex<V, W>* vertex_table_; //!< �ڽӵ�����
};


/*!
 * @brief ���캯��
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 * @param size �������
 */
template<class V, class W>
AdjacencyListGraph<V, W>::AdjacencyListGraph(int size) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edge_count_ = 0;

  this->vertex_table_ = new Vertex<V, W>[this->max_vertices_num_];

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->vertex_table_[i].adjacency_list = NULL;
  }
}


template<class T, class E>
AdjacencyListGraph<T, E>::~AdjacencyListGraph() {

  for (int i = 0; i < this->vertices_num_; i++) {

    Edge<T, E>* cur_edge = this->vertex_table_[i].adjacency_list;

    while (cur_edge != NULL) {
      this->vertex_table_[i].adjacency_list = cur_edge->next;
      delete cur_edge;
      cur_edge = this->vertex_table_[i].adjacency_list;
    }
  }

  delete[] this->vertex_table_;
}


/**
 * @brief ʹ�ý��������ȡ���
 * @param vertex ���(�������Ľڵ�)
 * @param vertex_index �������
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::GetVertexByIndex(T& vertex, int vertex_index) {
  if (vertex_index >= 0 && vertex_index < this->vertices_num_) {
    vertex = this->vertex_table_[vertex_index].vertex;

    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ��ȡ��Ȩֵ
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 * @param weight ��Ȩֵ(���ڱ�����)
 * @param vertex1 ���1
 * @param vertex2 ���2
 * @return �Ƿ��ȡ�ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::GetWeight(W& weight, V vertex1, V vertex2) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 || vertex2_index < 0) {
    return false;
  }

  Edge<V, W>* edge = this->vertex_table_[vertex1_index].adjacency_list;

  while (edge != NULL && edge->dest_index != vertex2_index) {
    edge = edge->next;
  }

  if (edge != NULL) {
    weight = edge->weight;
    return true;
  }

  return false;
}


/*!
 * @brief ������
 * @param vertex �ڵ�
 * @return �Ƿ����ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::InsertVertex(const V& vertex) {

  // ������нڵ�����������, ��ִ�в���, ����ʧ��
  if (this->vertices_num_ == this->max_vertices_num_) {
    return false;
  }

  this->vertex_table_[this->vertices_num_].vertex = vertex; // vertex_table_���ӽ������
  this->vertices_num_++; // ���������

  return true;
}


/*!
 * @brief ɾ�����
 * @param vertex �ڵ�
 * @return �Ƿ�ɾ���ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::RemoveVertex(V vertex) {

  int vertex_index = this->GetVertexIndex(vertex);

  if (this->vertices_num_ == 1 || vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  while (this->vertex_table_[vertex_index].adjacency_list != NULL) {

    Edge<V, W>* prior = NULL;
    Edge<V, W>* cur = this->vertex_table_[vertex_index].adjacency_list;
    int cur_vertex_index = cur->dest_index;

    Edge<V, W>* delete_edge = this->vertex_table_[cur_vertex_index].adjacency_list;

    while (delete_edge != NULL && delete_edge->dest_index != vertex_index) {
      prior = delete_edge;
      delete_edge = delete_edge->next;
    }

    if (delete_edge != NULL) {
      if (prior == NULL) {
        this->vertex_table_[cur_vertex_index].adjacency_list = delete_edge->next;
      } else {
        prior->next = delete_edge->next;
      }

      delete delete_edge;
    }

    this->vertex_table_[vertex_index].adjacency_list = cur->next;

    delete cur;

    this->edge_count_--;
  }

  this->vertices_num_--;

  this->vertex_table_[vertex_index].vertex = this->vertex_table_[this->vertices_num_].vertex;
  this->vertex_table_[vertex_index].adjacency_list = this->vertex_table_[this->vertices_num_].adjacency_list;

  Edge<V, W>* cur = this->vertex_table_[this->vertices_num_].adjacency_list;
  while (cur != NULL) {

    Edge<V, W>* modify_edge = this->vertex_table_[cur->dest_index].adjacency_list;

    while (modify_edge != NULL) {
      if (modify_edge->dest_index == this->vertices_num_) {
        modify_edge->dest_index = vertex_index;
        break;
      } else {
        modify_edge = modify_edge->next;
      }
    }

    cur = cur->next;
  }

  this->vertex_table_[this->vertices_num_].adjacency_list = NULL;

  return true;
}


/*!
 * @brief �����
 * @param vertex1 �߽ڵ�1
 * @param vertex2 �߽ڵ�2
 * @param weight ��Ȩֵ
 * @return �Ƿ����ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::InsertEdge(V vertex1, V vertex2, W weight) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  // ���vertex1��vertex2�Ϸ���, �Ƿ���ͼ��
  if (vertex1_index < 0 || vertex1_index >= this->vertices_num_ || vertex2_index < 0 || vertex2_index >= this->vertices_num_) {
    return false;
  }

  // ���ڽӱ����� vertex1_index --> vertex2_index �Ƿ����, �������˵�����Ѿ�����, ���ܲ���
  Edge<V, W>* cur_edge = this->vertex_table_[vertex1_index].adjacency_list;
  while (cur_edge != NULL && cur_edge->dest_index != vertex2_index) {
    cur_edge = cur_edge->next;
  }

  if (cur_edge != NULL) {
    return false;
  }

  Edge<V, W>* v2_dest_edge = new Edge<V, W>(); // vertex1 --> vertex2
  Edge<V, W>* v1_dest_edge = new Edge<V, W>(); // vertex2 --> vertex1
  /* error handler */

  // �����ڽӱ��ڶ�Ӧ������
  v2_dest_edge->dest_index = vertex2_index;
  v2_dest_edge->weight = weight;
  v2_dest_edge->next = this->vertex_table_[vertex1_index].adjacency_list;
  this->vertex_table_[vertex1_index].adjacency_list = v2_dest_edge;

  v1_dest_edge->dest_index = vertex1_index;
  v1_dest_edge->weight = weight;
  v1_dest_edge->next = this->vertex_table_[vertex2_index].adjacency_list;
  this->vertex_table_[vertex2_index].adjacency_list = v1_dest_edge;

  this->edge_count_++; // �ߵ�����+1

  return true;
}


/*!
 * @brief ɾ����
 * @param vertex1 �߽��1
 * @param vertex2 �߽��2
 * @return �Ƿ�ɾ���ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::RemoveEdge(V vertex1, V vertex2) {

  // ��ȡ���������vertex_table_����������, �����һ��������, �򷵻�false
  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 && vertex2_index < 0) {
    return false;
  }

  Edge<V, W>* delete_edge; // ��ɾ�����
  Edge<V, W>* prior_edge; // ��ɾ������ǰһ�ڵ�
  Edge<V, W>* first_edge; // ��һ���ڽӽ����Ǵ�ɾ�����

  // vertex1 --> vertex2��ɾ��
  delete_edge = this->vertex_table_[vertex1_index].adjacency_list;
  prior_edge = NULL;
  first_edge = this->vertex_table_[vertex1_index].adjacency_list;

  // ��λdelete_edge_ptr��prior_edge_ptr
  while (delete_edge != NULL && delete_edge->dest_index != vertex2_index) {
    prior_edge = delete_edge;
    delete_edge = delete_edge->next;
  }

  if (delete_edge != NULL) {
    if (first_edge == delete_edge) { // �����һ���ڽӽ����Ǵ�ɾ�����
      this->vertex_table_[vertex1_index].adjacency_list = delete_edge->next;
    } else { // ��һ����㲻�Ǵ�ɾ�����
      prior_edge->next = delete_edge->next;

      delete delete_edge;
    }
  } else {
    return false; // ���û�д�ɾ�����, �򷵻�false
  }

  // vertex2 --> vertex1��ɾ��
  delete_edge = this->vertex_table_[vertex2_index].adjacency_list;
  prior_edge = NULL;
  first_edge = this->vertex_table_[vertex2_index].adjacency_list;

  while (delete_edge != NULL && delete_edge->dest_index != vertex1_index) {
    prior_edge = delete_edge;
    delete_edge = delete_edge->next;
  }

  if (delete_edge != NULL) {
    if (first_edge == delete_edge) {
      this->vertex_table_[vertex2_index].adjacency_list = delete_edge->next;
    } else {
      prior_edge->next = delete_edge->next;

      delete delete_edge;
    }
  } else {
    return false;
  }

  // �ߵ�������1
  this->edge_count_--;

  return true;
}


/*!
 * @brief ��ȡ��һ�����ڽ��
 * @param first_neighbor ��һ�����ڽ��(���ڱ���ڵ�)
 * @param vertex �ڵ�
 * @return �Ƿ��ȡ�ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::GetFirstNeighborVertex(V& first_neighbor, const V& vertex) {

  int vertex_index = this->GetVertexIndex(vertex); // ��ȡ�����vertex_table_����������

  if (vertex_index >= 0) {
    Edge<V, W>* edge = this->vertex_table_[vertex_index].adjacency_list;
    if (edge != NULL) {

      int neighbor_index = edge->dest_index; // ��һ���ڽӽ���dest_index_

      bool has_vertex = this->GetVertexByIndex(first_neighbor, neighbor_index); // ȡdest_index��Ӧ�Ľ��

      return has_vertex;
    }
  }

  return false;
}


/*!
 * @brief ��ȡ��һ�����ڽ��
 * @param next_neighbor ��һ�����ڽ��(���ڱ�����)
 * @param vertex ���
 * @param neighbor_vertex ��ǰ���ڽ��
 * @return �Ƿ��ȡ�ɹ�
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::GetNextNeighborVertex(V& next_neighbor, const V& vertex, const V& neighbor_vertex) {

  // �õ�vertex��neighbor_vertex��Ӧ��vertex_table_����������
  int vertex_index = GetVertexIndex(vertex);
  int neighbor_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index >= 0) {

    // �ڽӱ���, �ҵ�neighbor_vertex��λ��
    Edge<V, W>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list;

    while (edge_ptr->next != NULL && edge_ptr->dest_index != neighbor_index) {
      edge_ptr = edge_ptr->next;
    }

    // ����һ��λ�õĽ�㸳��next_neighbor
    if (edge_ptr != NULL && edge_ptr->next != NULL) {
      int next_neighbor_index = edge_ptr->next->dest_index;

      bool has_next_neighbor = this->GetVertexByIndex(next_neighbor, next_neighbor_index);

      return has_next_neighbor;
    }
  }

  return false;
}


/*!
 * @brief ����ͼ
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 * @param in ������(����)
 * @param graph_adjacency_list �ڽӱ�ͼ
 * @return ������(����)
 */
template<class V, class W>
istream& operator>>(istream& in, AdjacencyListGraph<V, W>& graph_adjacency_list) {

  int vertex_num;
  int edge_num;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    V vertex;

    cout<<"Input vertex "<<i<<":"<<endl;
    in >> vertex;

    bool insert_done = graph_adjacency_list.InsertVertex(vertex);
    if (insert_done) {
      cout<<"Insert vertex "<<i<<" done."<<endl;
    } else {
      cout<<"Insert vertex "<<i<<" failed."<<endl;
      exit(1);
    }
  }

  for (int i = 0; i < edge_num; i++) {

    V src_vertex;
    V dest_vertex;
    W weight;

    cout<<"Edge "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = graph_adjacency_list.GetVertexIndex(src_vertex);
    int dest_vertex_index = graph_adjacency_list.GetVertexIndex(dest_vertex);
    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    graph_adjacency_list.InsertEdge(src_vertex, dest_vertex, weight);
  }

  return in;
}


/*!
 * @brief ���(��ӡ)ͼ
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 * @param out �����(����)
 * @param graph_adjacency_list �ڽӱ�ͼ
 * @return �����(����)
 */
template<class V, class W>
ostream& operator<<(ostream& out, AdjacencyListGraph<V, W>& graph_adjacency_list) {

  int vertex_num = graph_adjacency_list.NumberOfVertices();
  int edge_num = graph_adjacency_list.NumberOfEdges();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  if (edge_num == 0) {
    cout<<"No edge"<<endl;
    return out;
  }

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      V src_vertex;
      V dest_vertex;

      bool get_src_value_done = graph_adjacency_list.GetVertexByIndex(src_vertex, src_vertex_index);
      bool get_dest_value_done = graph_adjacency_list.GetVertexByIndex(dest_vertex, dest_vertex_index);

      if (get_src_value_done && get_dest_value_done) {

        W weight;
        bool hasWeight = graph_adjacency_list.GetWeight(weight, src_vertex, dest_vertex);

        if (hasWeight) {
          out << "(" << src_vertex << "," << dest_vertex << "," << weight << ")" << endl;
        }
      }
    }
  }

  return out;
}


/*!
 * @brief ��ȡ�������
 * @param vertex ���
 * @return �������
 */
template<class V, class W>
int AdjacencyListGraph<V, W>::GetVertexIndex(V vertex) {

  int vertex_index = -1; // ���ͼ��û�иý��, �򷵻�-1

  // ��vertex_table_�в��ĸ���value_Ϊvertex
  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertex_table_[i].vertex == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class V, class W>
void AdjacencyListGraph<V, W>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif // CYBER_DASH_ADJACENCY_LIST_GRAPH_H
