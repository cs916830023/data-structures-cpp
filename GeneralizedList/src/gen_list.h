/*!
 * @file gen_list.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �����ģ����
 * @version 0.2.1
 * @date 2021-07-14
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_GENERALIZED_LIST_H
#define CYBER_DASH_GENERALIZED_LIST_H


#include <iostream>
#include <vector>
#include <queue>
#include "gen_list_node.h"


using namespace std;


//! �����ģ����
template<class T>
class GenList {

public:

  // ���캯��
  GenList();

  // ���Ա�ͷ���
  bool Head(Item<T>& item);
  // ���Ա�β
  bool Tail(GenList<T>& tail_list);

  void CopyFrom(GenList<T>& src_gen_list);

  // ����
  int Length();
  // ���
  int Depth();

  // ʹ��char���д��������(�ݹ�)
  void CreateGenListByQueueRecursive(queue<T>& char_queue, GenListNode<T>*& node_ptr, bool& in_referred_list);
  // ʹ���ַ������������
  void CreateListByString(string gen_list_string);

  // ɾ�����, todo: δʵ��
  void Remove(GenListNode<T>* node_ptr);

  GenListNode<T>* ref_node_ptr; //!< ���������ý��

  // ��������
  template<class U>
  friend istream& operator>>(istream& in, GenList<T>& gen_list);

private:
  // �ӱ���(�ݹ�)
  int SubGenListLengthRecursive_(GenListNode<T>* node_ptr);
  // �ӱ����(�ݹ�)
  int SubGenListDepthRecursive_(GenListNode<T>* node_ptr);

  // �Ƿ��Ǳ���(��д��ĸ)
  bool IsGenListNameChar_(T chr);
  // �Ƿ��Ǳ���ʼ�ַ�(��д��ĸ����'(')
  bool IsGenListBeginChar_(T chr);

  // �����Ŵ���
  void LeftBracketHandler_(queue<T>& char_queue);
  // '#'��Ӧ�������Ŵ���
  void PassRightBracketAfterSharpChar(queue<T>& char_queue);

  // �½�Ԫ�ؽ��
  GenListNode<T>* NewElemNode_(T chr);
  // �½��ӱ�ڵ�
  GenListNode<T>* NewChildGenListNode_();

  // �����Ѿ������õĽ��
  GenListNode<T>* FindReferredNodePtr_(T chr);
  // ��������, todo: δ����
  GenListNode<T>* Copy_(GenListNode<T>*& node_ptr);

  vector<T> gen_list_name_vec_; //!< ����ڵ��vector
  vector<GenListNode<T>*> gen_list_node_ptr_vec_; //!< ����ڵ�ָ���vector
};


/*!
 * @brief ���캯��(�޲���)
 * @tparam T ����ģ�����
 */
template<class T>
GenList<T>::GenList() {
  ref_node_ptr = new GenListNode<T>();
  if (ref_node_ptr == NULL) {
    cerr<<"GenList constructor wrong."<<endl;
  }
}


/*!
 * @brief ���Ա�ͷ���
 * @tparam T ����ģ�����
 * @param item ���ݱ���(�洢��ͷ����)
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool GenList<T>::Head(Item<T>& item) {

  if (this->ref_node_ptr->next == NULL) {
    return false;
  } else {
    item.type = this->ref_node_ptr->type;
    item.union_info = this->ref_node_ptr->union_info;
  }
}


/*!
 * @brief ���Ա�β
 * @tparam T ����ģ�����
 * @param tail_list ��������(�洢��β)
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool GenList<T>::Tail(GenList<T>& tail_list) {

  if (ref_node_ptr->next == NULL) {
    return false;
  } else {
    tail_list.ref_node_ptr->type = GenListNode<T>::REF_TYPE;
    tail_list.ref_node_ptr->union_info.ref_count = 0;
    tail_list.ref_node_ptr->next = CopyFrom(ref_node_ptr->next->next);
  }
}



template<class T>
void GenList<T>::CopyFrom(GenList<T>& src_gen_list) {
  ref_node_ptr = Copy_(src_gen_list.ref_node_ptr);
}


template<class T>
GenListNode<T>* GenList<T>::Copy_(GenListNode<T>*& node_ptr) {

  GenListNode<T> cur_node_ptr = NULL;

  if (node_ptr != NULL) {
    cur_node_ptr = new GenListNode<T>();
    cur_node_ptr.type = node_ptr->type;

    switch (node_ptr->type) {
      case GenListNode<T>::REF_TYPE:
        cur_node_ptr->union_info.ref_count = node_ptr->union_info.ref_count;
        break;
      case GenListNode<T>::ELEM_TYPE:
        cur_node_ptr->union_info.value = node_ptr->union_info.value;
        break;
      case GenListNode<T>::CHILD_LIST_TYPE:
        cur_node_ptr.union_info.ref_node_ptr = Copy_(node_ptr->union_info.ref_node_ptr);
        break;
      default:
        break;
    }

    cur_node_ptr.next = Copy_(node_ptr->next);
  }

  return cur_node_ptr;
}


/*!
 * @brief ��ȡ�ӱ���(�ݹ�)
 * @tparam T ����ģ������
 * @param node_ptr �ӱ�����(��ʼ)���ָ��
 * @return ����
 */
template<class T>
int GenList<T>::SubGenListLengthRecursive_(GenListNode<T>* node_ptr) {
  if (node_ptr == NULL) {
    return 0;
  }

  int sub_list_length = SubGenListLengthRecursive_(node_ptr->next) + 1;

  return sub_list_length;
}


/*!
 * @brief ��ȡ����
 * @tparam T ����ģ������
 * @return ����
 */
template<class T>
int GenList<T>::Length() {
  int list_length = SubGenListLengthRecursive_(this->ref_node_ptr->next);

  return list_length;
}


/*!
 * @brief ��ȡ���
 * @tparam T ����ģ������
 * @return ���
 */
template<class T>
int GenList<T>::Depth() {
  return SubGenListDepthRecursive_(ref_node_ptr);
}


/*!
 * @brief ��ȡ�ӱ����(�ݹ�)
 * @tparam T ����ģ������
 * @param node_ptr �ӱ�����(��ʼ)���ָ��
 * @return ���
 */
template<class T>
int GenList<T>::SubGenListDepthRecursive_(GenListNode<T> *node_ptr) {

  GenListNode<T>* cur_node_ptr = node_ptr->next;

  if (cur_node_ptr == NULL) {
    return 1;
  }

  int maxSubListDepth = 0;

  while (cur_node_ptr != NULL) {

    if (cur_node_ptr->type == GenListNode<T>::CHILD_LIST_TYPE) {

      int curSubListDepth = SubGenListDepthRecursive_(cur_node_ptr->union_info.ref_node_ptr);
      if (maxSubListDepth < curSubListDepth) {
        maxSubListDepth = curSubListDepth;
      }
    }

    cur_node_ptr = cur_node_ptr->next;
  }

  return maxSubListDepth + 1;
}


/*!
 * @brief �����Ŵ�����
 * @tparam T ����ģ�����
 * @param char_queue �ַ�����
 */
template<class T>
void GenList<T>::LeftBracketHandler_(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != '(') {
    exit(1);
  }
}


/*!
 * @brief '#'��Ӧ�������Ŵ���
 * @tparam T ����ģ�����
 * @param char_queue
 */
template<class T>
void GenList<T>::PassRightBracketAfterSharpChar(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != ')') {
    exit(1);
  }
}


/*!
 * @brief �ж��Ƿ��Ǳ���(��д��ĸ)
 * @tparam T ����ģ�����
 * @param chr ���Ա��ַ����е�ĳ���ַ�
 * @return ��or��
 */
template<class T>
bool GenList<T>::IsGenListNameChar_(T chr) {
  return isalpha(chr) && isupper(chr);
}


/*!
 * @brief �ж��Ƿ������Ա����ʼ�ַ�, ��д��ĸ����'('
 * @tparam T ���Ա�ڵ���������
 * @param chr ���Ա��ַ����е�ĳ���ַ�
 * @return ��or��
 */
template<class T>
bool GenList<T>::IsGenListBeginChar_(T chr) {
  return (isalpha(chr) && isupper(chr)) || chr == '(';
}


/*!
 * @brief ʹ��char���д��������(�ݹ�)
 * @tparam T ����ģ�����
 * @param char_queue char����
 * @param node_ptr �ڵ�ָ��
 * @param in_referred_list �ýڵ��Ƿ��Ѿ�������
 */
template<class T>
void GenList<T>::CreateGenListByQueueRecursive(queue<T>& char_queue, GenListNode<T>*& node_ptr, bool& in_referred_list) {

  T chr = char_queue.front();
  char_queue.pop();

  GenListNode<T>* referred_node_ptr = NULL;

  bool is_gen_list_begin_char = IsGenListBeginChar_(chr);
  if (is_gen_list_begin_char) {

    bool is_gen_list_name_char = IsGenListNameChar_(chr);
    if (is_gen_list_name_char) { // ��д��ĸ

      referred_node_ptr = FindReferredNodePtr_(chr); // ����Ƿ���vector��

      if (referred_node_ptr != NULL) {
        node_ptr = NewChildGenListNode_(); // ����һ���ӱ�����(2)�Ľڵ�
        node_ptr->union_info.ref_node_ptr = referred_node_ptr; // ָ��һ���Ѿ����ڵı�
        referred_node_ptr->union_info.ref_count++; // ������+1

        in_referred_list = true;
      } else { // ����node vector��
        node_ptr = NewChildGenListNode_(); // ����һ���ӱ�����(2)�Ľڵ�

        GenListNode<T>* ref_node_ptr = new GenListNode<T>();
        ref_node_ptr->union_info.ref_count = 1;

        node_ptr->union_info.ref_node_ptr = ref_node_ptr; // ����һ���ӱ��0�ڵ�

        gen_list_name_vec_.push_back(chr);
        gen_list_node_ptr_vec_.push_back(ref_node_ptr);

        in_referred_list = false;
      }

      LeftBracketHandler_(char_queue);

      CreateGenListByQueueRecursive(char_queue, node_ptr->union_info.ref_node_ptr->next, in_referred_list);
      CreateGenListByQueueRecursive(char_queue, node_ptr, in_referred_list);
    }
  } else if (isalpha(chr) && islower(chr)) {
    if (!in_referred_list) {
      node_ptr = NewElemNode_(chr);
      CreateGenListByQueueRecursive(char_queue, node_ptr, in_referred_list);
    }
  } else if (chr == ',') {
    CreateGenListByQueueRecursive(char_queue, node_ptr->next, in_referred_list);
  } else if (chr == ')') {
    if (!in_referred_list) {
      node_ptr->next = NULL;
    }
    in_referred_list = false;
  }
  else if (chr == '#') {
    if (!in_referred_list) {
      node_ptr = NULL;
      PassRightBracketAfterSharpChar(char_queue);
    }
    in_referred_list = false;
  }
}


/*!
 * @brief ʹ���ַ������������
 * @tparam T ģ��ڵ�����
 * @param gen_list_string ������ַ���
 * @note
 * �Ƚ��ַ������������
 * ����CreateGenListByQueueRecursive
 * ����ref_node_ptr
 */
template<class T>
void GenList<T>::CreateListByString(string gen_list_string) {

  // �Ƚ��ַ������������
  queue<T> char_queue;
  for (int i = 0; i < gen_list_string.length(); i++) {
    char cur_chr = gen_list_string[i];
    char_queue.push(cur_chr);
  }

  bool in_referred_list = false;

  // ����CreateGenListByQueueRecursive
  this->CreateGenListByQueueRecursive(char_queue, this->ref_node_ptr->next, in_referred_list);

  // ����ref_node_ptr
  this->ref_node_ptr = this->ref_node_ptr->next->union_info.ref_node_ptr;
}


/*!
 * @brief ��������(���ر�׼����)
 * @tparam T ����ģ�����
 * @param in ������
 * @param gen_list �����(������)
 * @return ������(������)
 */
template<class T>
istream& operator>>(istream& in, GenList<T>& gen_list) {

  string input_str;
  cout<<"Input the string:"<<endl;

  in >> input_str;

  gen_list.CreateListByString(input_str);

  return in;
}


/*!
 * @brief �����Ѿ������õĽ��
 * @tparam T ����ģ�����
 * @param chr �ַ�
 * @return �Ѿ������õĽڵ�ĵ�ַ
 */
template<class T>
GenListNode<T>* GenList<T>::FindReferredNodePtr_(T chr) {

  GenListNode<T>* node_ptr = NULL;

  typename vector<T>::iterator name_iter = gen_list_name_vec_.begin();
  typename vector<GenListNode<T>*>::iterator node_iter = gen_list_node_ptr_vec_.begin();

  for (; name_iter != gen_list_name_vec_.end(); name_iter++, node_iter++) {
    if (chr == *name_iter) {
      node_ptr = *node_iter;
      break;
    }
  }

  return node_ptr;
}


/*!
 * @brief �½�Ԫ�ؽ��
 * @tparam T ����ģ�����
 * @param chr �ַ�
 * @return ����ַ
 */
template<class T>
GenListNode<T>* GenList<T>::NewElemNode_(T chr) {

  GenListNode<T>* node_ptr = new GenListNode<T>();
  node_ptr->type = GenListNode<T>::ELEM_TYPE;
  node_ptr->union_info.value = chr;

  return node_ptr;
}


/*!
 * @brief �½��ӱ�ڵ�
 * @tparam T ����ģ�����
 * @return ����ַ
 */
template<class T>
GenListNode<T>* GenList<T>::NewChildGenListNode_() {

  GenListNode<T>* node_ptr = new GenListNode<T>();
  node_ptr->type = GenListNode<T>::CHILD_LIST_TYPE;

  return node_ptr;
}


#endif // CYBER_DASH_GENERALIZED_LIST_H
