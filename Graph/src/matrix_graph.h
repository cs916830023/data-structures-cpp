/*!
 * @file matrix_graph.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ����ͼģ����
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_MATRIX_GRAPH_H
#define CYBER_DASH_MATRIX_GRAPH_H


#include "graph.h"
#include <iostream>


using namespace std;


/*!
 * @brief ����ͼģ����
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 */
template<class V, class W>
class MatrixGraph: public Graph<V, W> {

public:
  // ���캯��
  MatrixGraph(int size = DEFAULT_VERTICES);

  // ��������
  ~MatrixGraph();

  /*!
   * @brief ��ȡ�ڵ�(�ɽ������)
   * @param vertex ���(���ڱ�����)
   * @param vertex_index �������
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetVertexByIndex(V& vertex, int vertex_index);

  /*!
   * @brief ��ȡ��Ȩֵ
   * @param weight ��Ȩֵ(���ڱ�����)
   * @param vertex1 �ߵĽڵ�1
   * @param vertex2 �ߵĽڵ�2
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetWeight(W& weight, V vertex1, V vertex2);

  /*!
   * @brief ������
   * @param vertex �ڵ�
   * @return �Ƿ����ɹ�
   */
  bool InsertVertex(const V& vertex);

  /*!
   * @brief ɾ�����
   * @param vertex �ڵ�
   * @return �Ƿ�ɾ���ɹ�
   */
  bool RemoveVertex(V vertex);

  /*!
   * @brief �����
   * @param vertex1 �߽ڵ�1
   * @param vertex2 �߽ڵ�2
   * @param weight ��Ȩֵ
   * @return �Ƿ����ɹ�
   */
  bool InsertEdge(V vertex1, V vertex2, W weight);

  /*!
   * @brief ɾ����
   * @param vertex1 �߽��1
   * @param vertex2 �߽��2
   * @return �Ƿ�ɾ���ɹ�
   */
  bool RemoveEdge(V vertex1, V vertex2);

  /*!
   * ��ȡ��һ�����ڽ��
   * @param first_neighbor ��һ�����ڽ��(���ڱ���ڵ�)
   * @param vertex �ڵ�
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetFirstNeighborVertex(V& first_neighbor, const V& vertex);

  /*!
   * @brief ��ȡ��һ�����ڽ��
   * @param next_neighbor_vertex ��һ�����ڽ��(���ڱ�����)
   * @param vertex ���
   * @param neighbor_vertex ��ǰ���ڽ��
   * @return �Ƿ��ȡ�ɹ�
   */
  bool GetNextNeighborVertex(V& next_neighbor_vertex, const V& vertex, const V& neighbor_vertex);

  /*!
   * @brief ��ȡ�������
   * @param vertex ���
   * @return �������
   */
  int GetVertexIndex(V vertex);

  template<class U>
  friend istream& operator>>(istream& in, MatrixGraph<V, W>& graph_matrix);
  template<class U>
  friend ostream& operator<<(ostream& out, MatrixGraph<V, W>& graph_matrix);

  void PrintMatrix();
  void CyberDashShow();

private:
  V* vertices_list_; //!< ����б�
  W** edge_matrix_; //!< �߾���
};


/*!
 * @brief ���캯��
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 * @param size �������
 */
template<class V, class W>
MatrixGraph<V, W>::MatrixGraph(int size) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edge_count_ = 0;

  // ���нڵ�
  this->vertices_list_ = new V[this->max_vertices_num_];
  /* error handler */

  this->edge_matrix_ = (W**)new W*[this->max_vertices_num_];
  /* error handler */

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->edge_matrix_[i] = new W[this->max_vertices_num_]; // �ڵ�i��Ӧ�����б�
    for (int j = 0; j < this->max_vertices_num_; j++) {
      this->edge_matrix_[i][j] = (i == j) ? 0 : MAX_WEIGHT;
    }
  }
}


/*!
 * @brief ��������
 * @tparam V �������ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 */
template<class V, class W>
MatrixGraph<V, W>::~MatrixGraph() {
  delete[] this->vertices_list_;
  delete[] this->edge_matrix_;
}


/*!
 * @brief ʹ�ý��������ȡ���
 * @param vertex ���(�������Ľڵ�)
 * @param vertex_index �������
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T, class E>
bool MatrixGraph<T, E>::GetVertexByIndex(T& vertex, int vertex_index) {
  if (vertex_index >= 0 && vertex_index <= this->vertices_num_) {
    vertex = this->vertices_list_[vertex_index];
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ��ȡ��Ȩֵ
 * @tparam V
 * @tparam W
 * @param weight
 * @param vertex1
 * @param vertex2
 * @return
 */
template<class V, class W>
bool MatrixGraph<V, W>::GetWeight(W& weight, V vertex1, V vertex2) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  if (v1_index >= 0 && v2_index >= 0 &&
    v1_index != v2_index &&
    this->edge_matrix_[v1_index][v2_index] != MAX_WEIGHT &&
    this->edge_matrix_[v1_index][v2_index] > 0)
  {
    weight = this->edge_matrix_[v1_index][v2_index];

    return true;
  }

  return false;
}


template<class V, class W>
bool MatrixGraph<V, W>::GetFirstNeighborVertex(V& first_neighbor, const V& vertex) {

  int vertex_index = GetVertexIndex(vertex);

  if (vertex_index < 0) {
    return false;
  }

  for (int cur_index = 0; cur_index < this->vertices_num_; cur_index++) {
    W weight;
    V cur_vertex;

    bool done = GetVertexByIndex(cur_vertex, cur_index);
    if (!done) {
      continue;
    }

    bool has_weight = GetWeight(weight, vertex, cur_vertex);
    if (has_weight) {
      first_neighbor = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class T, class E>
bool MatrixGraph<T, E>::GetNextNeighborVertex(T& next_neighbor_vertex, const T& vertex, const T& neighbor_vertex) {

  int vertex_index = GetVertexIndex(vertex);
  int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index < 0 && neighbor_vertex_index < 0) {
    return false;
  }

  for (int cur_index = neighbor_vertex_index + 1; cur_index < this->vertices_num_; cur_index ++) {
    E weight;
    T cur_vertex;

    bool done = GetVertexByIndex(cur_vertex, cur_index);
    if (!done) {
      continue;
    }

    bool has_weight = GetWeight(weight, vertex, cur_vertex);
    if (has_weight) {
      next_neighbor_vertex = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class T, class E>
bool MatrixGraph<T, E>::InsertVertex(const T& vertex) {
  if (this->vertices_num_ >= this->max_vertices_num_) {
    return false;
  }

  this->vertices_list_[this->vertices_num_] = vertex;
  this->vertices_num_++;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::InsertEdge(T vertex1, T vertex2, E weight) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  if (v1_index < 0 || v2_index < 0 || v1_index == v2_index)
  {
    return false;
  }

  this->edge_matrix_[v1_index][v2_index] = weight;
  this->edge_matrix_[v2_index][v1_index] = weight;

  this->edge_count_++;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::RemoveVertex(T vertex) {

  int vertex_index = GetVertexIndex(vertex);

  if (vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  // ֻʣ1������ todo: ���ϵ��߼�, ʵ���Ͽ���ɾ��
  if (this->vertices_num_ == 1) {
    return false;
  }

  this->vertices_list_[vertex_index] = this->vertices_list_[this->vertices_num_ - 1];

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->edge_matrix_[i][vertex_index] > 0 && this->edge_matrix_[i][vertex_index] < MAX_WEIGHT) {
      this->edge_count_--;
    }
  }

  for (int row = 0; row < this->vertices_num_; row++) {
    this->edge_matrix_[row][vertex_index] = this->edge_matrix_[row][this->vertices_num_ - 1];
  }

  for (int col = 0; col < this->vertices_num_; col++) {
    this->edge_matrix_[vertex_index][col] = this->edge_matrix_[this->vertices_num_ - 1][col];
  }

  this->vertices_num_--;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::RemoveEdge(T vertex1, T vertex2) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  E weight;
  bool has_weight = GetWeight(weight, vertex1, vertex2);
  if (has_weight) {
    this->edge_matrix_[v1_index][v2_index] = MAX_WEIGHT;
    this->edge_matrix_[v2_index][v1_index] = MAX_WEIGHT;

    this->edge_count_--;

    return true;
  }

  return false;
}


template<class T, class E>
istream& operator>>(istream& in, MatrixGraph<T, E>& graph_matrix) {

  int vertex_num;
  int edge_num;
  T src_vertex;
  T dest_vertex;
  E weight;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    cout<<"Vertex "<<i<<":"<<endl;
    in >> src_vertex;

    graph_matrix.InsertVertex(src_vertex);
  }

  for (int i = 0; i < edge_num; i++) {

    cout<<"Edge "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = graph_matrix.GetVertexPos(src_vertex); // todo: pos
    int dest_vertex_index = graph_matrix.GetVertexPos(dest_vertex);

    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    graph_matrix.InsertEdge(src_vertex_index, dest_vertex_index, weight);
  }
}


template<class T, class E>
ostream& operator<<(ostream& out, MatrixGraph<T, E>& graph_matrix) {

  int vertex_num = graph_matrix.NumberOfVertices();
  int edge_num = graph_matrix.NumberOfEdges();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      E weight = graph_matrix.GetWeight(src_vertex_index, dest_vertex_index);

      if (weight > 0 && weight < MAX_WEIGHT) {

        T e1 = graph_matrix.GetValue(src_vertex_index);
        T e2 = graph_matrix.GetValue(dest_vertex_index);

        out << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
      }
    }
  }
}


template<class T, class E>
int MatrixGraph<T, E>::GetVertexIndex(T vertex) {

  int vertex_index = -1;

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertices_list_[i] == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class T, class E>
void MatrixGraph<T, E>::PrintMatrix() {
  for (int i = 0; i < this->vertices_num_; i++) {
    for (int j = 0; j < this->vertices_num_; j++) {
      cout<<this->edge_matrix_[i][j]<<"  ";
    }
    cout<<endl;
  }
}


template<class T, class E>
void MatrixGraph<T, E>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"�����ʵ��ѧ(������ڶ��о���)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_MATRIX_GRAPH_H
