/*!
 * @file disjoint_set.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ���鼯.cpp�ļ�
 * @version 0.2.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "disjoint_set.h"


/*!
 * @brief ���캯��
 * @param size ��С
 */
DisjointSet::DisjointSet(int size) {
  size_ = size;
  this->parent_ = new int[this->size_];
  for (int i = 0; i < size; i++) {
    parent_[i] = -1;
  }
}


/*!
 * @brief ����=
 * @param disjoint_set Դ���鼯
 * @return ��ֵ��Ĳ��鼯
 * @note
 *  todo: δʵ��
 */
DisjointSet& DisjointSet::operator=(const DisjointSet& disjoint_set) {

  return *this;
}


/*!
 * @brief ����(�ǵݹ�)
 * @param value ��������
 * @return ���ڵ�
 */
int DisjointSet::FindNonRecursive(int value) {

  while (parent_[value] >= 0) {
    value = parent_[value];
  }

  return value;
}


/*!
 * @brief ����
 * @param value ��������
 * @return ���ڵ�
 */
int DisjointSet::Find(int value) {
  if (parent_[value] < 0) {
    return value;
  } else {
    return Find(parent_[value]);
  }
}


/**
 * @brief �ϲ�����(Weighted)
 * @param node1
 * @param node2
 */
void DisjointSet::WeightedUnion(int node1, int node2) {
  int root1 = Find(node1);
  int root2 = Find(node2);

  if (root1 == root2) {
    return;
  }

  int weighted_union_root = parent_[root1] + parent_[root2];

  if (parent_[root2] < parent_[root1]) {
    parent_[root1] = root2;
    parent_[root2] = weighted_union_root;
  } else {
    parent_[root2] = root1;
    parent_[root1] = weighted_union_root;
  }
}


/*!
 * @brief ����(��ԭ������Ż�)
 * @param node1
 * @param node2
 */
void DisjointSet::Union(int node1, int node2) {
  int root1 = Find(node1);
  int root2 = Find(node2);

  if (root1 == root2) {
    return;
  }

  parent_[root1] += parent_[root2];
  parent_[root2] = root1; // ����root2���ӵ���һ��root1����
}

