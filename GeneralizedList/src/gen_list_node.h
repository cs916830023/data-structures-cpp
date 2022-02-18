/*!
 * @file gen_list_node.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �������ģ����
 * @version 0.2.1
 * @date 2021-07-14
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_GEN_LIST_NODE_H
#define CYBER_DASH_GEN_LIST_NODE_H


#include <iostream>
#include <cstdlib>


template<class T>
class GenListNode;


//! �����ڵ�Union����
template<class T>
union GenNodeUnion {
  int ref_count; //!< ���ü���
  T value; //!< ����
  GenListNode<T>* ref_node_ptr; //!< ��һ����ĵ�ַ
};


//! �������������(���ڱ������ݽڵ����Ϣ)
template<class T>
class Item {
public:
  /*!
   * @brief ���캯��
   */
  Item() {
    this->type = GenListNode<T>::REF_TYPE;
    this->union_info.ref_count = 0;
  }

  /*!
   * @brief ���ƹ��캯��
   * @param item �ڵ�����
   */
  Item(Item<T>& item) {
    this->type = item.union_type_;
    this->union_info = item.union_info;
  }

  int type; //!< ����
  GenNodeUnion<T> union_info; //!< union��Ϣ
};


//! �������
template<class T>
class GenListNode {

public:

  /*! @brief ���캯��(�ձ�) */
  GenListNode(): type(GenListNode<T>::REF_TYPE), next(NULL) { union_info.ref_count = 0; }

  /*!
   * @brief ���캯��(ʹ�ý��)
   * @param node �����ڵ�(����)
   */
  GenListNode(GenListNode<T>& node):
      type(node.type), next(node.next), union_info(node.union_info) {}

  int type; //!< ����
  GenNodeUnion<T> union_info; //!< Union����
  GenListNode<T>* next; //!< ��һ�ڵ�ָ��

  static const int REF_TYPE = 0; //!< ��������
  static const int ELEM_TYPE = 1; //!< ���ݽڵ�����
  static const int CHILD_LIST_TYPE = 2; //!< �ӱ�����
};


#endif // CYBER_DASH_GEN_LIST_NODE_H
