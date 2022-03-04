/*!
 * @file graph.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼ���ģ����
 * @version 0.2.1
 * @date 2021-01-23
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


const int DEFAULT_VERTICES = 20; //<! Ĭ��ͼ������
const int MAX_WEIGHT = 1000; //<! ���Ȩֵ, todo: ����ͼ�޳�����߼�


/*!
 * @brief ͼ����(ģ����)
 * @tparam V �ڵ�����ģ�����
 * @tparam W ��Ȩֵ����ģ�����
 */
template<class V, class W>
class Graph {
public:

  /*!
   * @brief ��ȡͼ�������
   * @return ͼ�������
   */
  int NumberOfVertices() { return this->vertices_num_; }

  /*!
   * @brief ��ȡ������
   * @return ������
   */
  int NumberOfEdges() { return this->edge_count_; }

  /*!
   * @brief ��ȡ���(�ɽ������)
   * @param vertex ���(���ڱ�����)
   * @param vertex_index �������
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetVertexByIndex(V& vertex, int vertex_index) = 0;

  /*!
   * @brief ��ȡ��Ȩֵ
   * @param weight ��Ȩֵ(���ڱ�����)
   * @param v1 �ߵ�һ���ڵ�
   * @param v2 �ߵ���һ���ڵ�
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetWeight(W& weight, V v1, V v2) = 0;

  /*!
   * @brief ��ȡ���ĵ�һ�����ڽ��
   * @param first_neighbor ���(���ڱ����һ�����ڽ��)
   * @param vertex ���
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetFirstNeighborVertex(V& first_neighbor, const V& vertex) = 0;

  /*!
   * @brief ��ȡ������һ�����ڽ��
   * @param next_neighbor ���(���ڱ�����һ�����ڽ��)
   * @param vertex ���
   * @param neighbor_vertex ����һ�����ڽڵ�
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetNextNeighborVertex(V& next_neighbor, const V& vertex, const V& neighbor_vertex) = 0;

  /*!
   * @brief ������
   * @param vertex ���
   * @return �Ƿ����ɹ�
   */
  virtual bool InsertVertex(const V& vertex) = 0;

  /*!
   * @brief �����
   * @param vertex1 �ߵ�һ�����
   * @param vertex2 �ߵ���һ�����
   * @param weight �ߵ�Ȩֵ
   * @return �Ƿ����ɹ�
   */
  virtual bool InsertEdge(V vertex1, V vertex2, W weight) = 0;

  /*!
   * @brief ɾ�����
   * @param v �ڵ�
   * @return �Ƿ�ɾ���ɹ�
   */
  virtual bool RemoveVertex(V v) = 0;

  /*!
   * @brief ɾ����
   * @param v1 �ߵ�һ���ڵ�
   * @param v2 �ߵ���һ���ڵ�
   * @return �Ƿ�ɾ���ɹ�
   */
  virtual bool RemoveEdge(V v1, V v2) = 0;

  /*!
   * @brief ��ȡ��������ֵ
   * @param vertex �ڵ�
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual int GetVertexIndex(V vertex) = 0;

protected:
  int max_vertices_num_; //!< ͼ�ڵ������������
  int edge_count_; //!< ������
  int vertices_num_; //!< �ڵ�����
};


#endif //CYBER_DASH_GRAPH_H
