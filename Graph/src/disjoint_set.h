/*!
 * @file disjoint_set.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ���鼯.h�ļ�
 * @version 0.2.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_DISJOINT_SET_H
#define CYBER_DASH_DISJOINT_SET_H


/*!
 * @brief ���鼯��
 */
class DisjointSet {

public:
  // ���캯��
  DisjointSet(int size);

  /*! @brief �������� */
  ~DisjointSet() { delete[] parent_; }

  // �ϲ���������
  void Union(int root1, int root2);

  // ����=
  DisjointSet& operator=(const DisjointSet& disjoint_set);

  // ����
  int Find(int value);

  // �ϲ�����(Weighted)
  void WeightedUnion(int node1, int node2);

  // ����(�ǵݹ�)
  int FindNonRecursive(int value);
private:
  int size_; //!< ��С
  int* parent_; //!< ���ڵ�����
};


#endif //CYBER_DASH_DISJOINT_SET_H
