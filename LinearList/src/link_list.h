/*!
 * @file link_list.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��������ģ����
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_LINK_LIST_H
#define CYBER_DASH_LINK_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


using namespace std;


/*!
 * @brief ��������ģ����
 * @tparam T ����ģ�����
 */
template <class T>
struct LinkNode {
  /*! @brief ���캯��(��һ����ַ) */
  explicit LinkNode(LinkNode<T>* node = NULL) { this->next = node; }

  /*!
   * @brief ���캯��(���������һ����ַ)
   * @param data ������
   * @param ptr ��һ�ڵ��ַ
   */
  explicit LinkNode(const T& data, LinkNode<T>* node = NULL) {
    this->data = data;
    this->next = node;
  }

  T data; //!< ����������
  LinkNode<T>* next; //!< ��һ���
};


/*!
 * @brief ������ģ����
 * @tparam T ����ģ�����
 */
template<class T>
class LinkList: public LinearList<T> {
public:
  // ���캯��(�޲���)
  LinkList();
  // ���ƹ��캯��
  LinkList(const LinkList<T>& link_list);
  // ��������
  ~LinkList();
  // �������
  void MakeEmpty();
  /*! @brief ������ */
  int Length() const { return this->length_; }
  /*! @brief ����ͷ��� */
  LinkNode<T>* Head() const { return this->head_; }
  // ����������Ϊdata��Ԫ��
  LinkNode<T>* Search(T data);
  // λ��pos�Ľ���ַ
  LinkNode<T>* Locate(int pos);
  // ��ȡ��pos����������
  bool GetData(int pos, T& data) const;
  // ���õ�pos����������
  bool SetData(int pos, const T& data);
  // �ڵ�pos��Ԫ��(��������pos - 1)֮��, ��������
  bool Insert(int pos, const T& data);
  // �ڵ�pos��Ԫ��(��������pos - 1)֮��, ������
  bool Insert(int pos, LinkNode<T>* node_ptr);
  // ɾ����pos�����
  bool Remove(int pos, T& data);
  // �Ƿ�Ϊ������
  bool IsEmpty() const;
  // ��ӡ����
  void Output();
  // ������CyberDash
  void CyberDashShow();

private:
  LinkNode<T>* head_; //!< ����ͷ���
  int length_; //!< ������
};


/*!
 * @brief ���캯��(�޲���)
 * @tparam T ���Ͳ���ģ��
 */
template<class T>
LinkList<T>::LinkList() {
  this->head_ = new LinkNode<T>();
  /* error handler */
  this->length_ = 0;
};


/*!
 * @brief ���ƹ��캯��
 * @tparam T ����ģ�����
 * @param link_list ��������
 */
template<class T>
LinkList<T>::LinkList(const LinkList<T>& link_list) {

  this->head_ = new LinkNode<T>();
  LinkNode<T>* dest_ptr = this->Head();

  LinkNode<T>* src_ptr = link_list.Head();

  while (src_ptr->next != NULL) {

    T data = src_ptr->next->data;
    dest_ptr->next = new LinkNode<T>(data);

    dest_ptr = dest_ptr->next;
    src_ptr = src_ptr->next;

    length_++;
  }

  dest_ptr->next = NULL;
}


template<class T>
LinkList<T>::~LinkList() {
  this->MakeEmpty();

  delete this->head_;
  this->head_ = NULL;
}


/*!
 * @brief ��ȡ��pos����������
 * @tparam T ����ģ�����
 * @param pos ��pos��
 * @param data ����(���ڱ���������)
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool LinkList<T>::GetData(int pos, T& data) const {

  if (pos < 1 || pos > this->Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  data = cur->data;

  return true;
}


/*!
 * @brief ���õ�pos����������
 * @tparam T ����ģ�����
 * @param pos ��pos��
 * @param data ����
 * @return �Ƿ����óɹ�
 */
template<class T>
bool LinkList<T>::SetData(int pos, const T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  cur->data = data;

  return true;
}


/*!
 * @brief �������
 * @tparam T ����ģ�����
 */
template<class T>
void LinkList<T>::MakeEmpty() {

  while (this->head_->next != NULL) {

    LinkNode<T>* delete_node_ptr = this->head_->next;
    this->head_->next = this->head_->next->next;

    delete delete_node_ptr;
    this->length_--;
  }
}


/*!
 * @brief ��ӡ����
 * @tparam T ����ģ�����
 */
template<class T>
void LinkList<T>::Output() {

  if (this->head_->next == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  LinkNode<T>* cur = Head()->next;
  while(cur != NULL) {
    cout << cur->data << " ";
    cur = cur->next;
  }

  cout << endl;
}


/*!
 * @brief �ڵ�pos��Ԫ��֮��, ��������
 * @param pos λ��pos
 * @param data ������ֵ
 * @return �Ƿ�ɹ�
 * @note
 * ����������, ��1��ʼ\n
 * ��posΪ0ʱ, ��ʾ����λ��1
 */
template<class T>
bool LinkList<T>::Insert(int pos, const T& data) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  LinkNode<T>* node_ptr = new LinkNode<T>(data);

  LinkNode<T>* cur = this->head_;
  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  node_ptr->next = cur->next;
  cur->next = node_ptr;

  length_++;

  return true;
}


/*!
 * @brief �ڵ�pos��Ԫ��֮��, ��������
 * @param pos λ��pos
 * @param node_ptr �������Ӧ�Ľ��ָ��
 * @return �Ƿ�ɹ�
 * @note
 * ����������, ��1��ʼ\n
 * ��posΪ0ʱ, ��ʾ����λ��1
 */
template<class T>
bool LinkList<T>::Insert(int pos, LinkNode<T>* node_ptr) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  if (node_ptr == NULL) {
    return false;
  }

  LinkNode<T>* cur = head_;
  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  node_ptr->next = cur->next;
  cur->next = node_ptr;

  length_++;

  return true;
}


/*!
 * @brief �Ƿ�Ϊ������
 * @tparam T ����ģ�����
 * @return �Ƿ�Ϊ������
 */
template<class T>
bool LinkList<T>::IsEmpty() const {
  if (this->head_->next == NULL) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief
 * @tparam T
 */
template<class T>
void LinkList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


/*!
 * @brief ����������Ϊdata��Ԫ��
 * @tparam T ����ģ�����
 * @param data ����
 * @return ��Ӧ�Ľ��ָ��
 */
template<class T>
LinkNode<T>* LinkList<T>::Search(T data) {

  LinkNode<T>* cur = this->head_->next;
  if (cur == NULL) { // ������
    return NULL;
  }

  while (cur != NULL) {
    if (cur->data == data) {
      return cur;
    }

    cur = cur->next;
  }

  return NULL;
}


/*!
 * @brief λ��pos�Ľ���ַ
 * @tparam T ����ģ����
 * @param pos λ��pos
 * @return ���ָ��
 */
template<class T>
LinkNode<T>* LinkList<T>::Locate(int pos) {
  if (pos < 1 || pos > this->Length()) {
    return NULL;
  }

  LinkNode<T>* cur = this->Head()->next;
  for (int i = 1; i < pos; i++) {
    cur = cur->next;
  }

  return cur;
}


/*!
 * @brief ɾ����pos�����
 * @tparam T ����ģ�����
 * @param pos ��pos��
 * @param data ����(���ڱ��汻ɾ�����������)
 * @return �Ƿ�ɾ���ɹ�
 * @note
 * ��1��ʼ����
 */
template<class T>
bool LinkList<T>::Remove(int pos, T &data) {

  if (this->Length() == 0 || pos < 1 || pos > this->Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  for (int i = 1; i < pos; i++) {
    cur = cur->next;
  }

  LinkNode<T>* delete_node_ptr = cur->next;
  cur->next = delete_node_ptr->next;

  data = delete_node_ptr->data;
  this->length_--;

  if (delete_node_ptr != NULL) {
    delete delete_node_ptr;
  }

  return true;
}


#endif // CYBER_DASH_LINK_LIST_H
