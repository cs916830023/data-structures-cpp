/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向链表
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINK_LIST_H
#define CYBER_DASH_LINK_LIST_H


#include <iostream>
#include <cstddef>


using namespace std;


/*!
 * @class 链表结点模板类
 * @tparam T 类型模板参数
 */
template <class T>
struct LinkNode {
  /*! @brief 构造函数(结点指针) */
  explicit LinkNode(LinkNode<T>* ptr = NULL) { this->link_ = ptr; }
  explicit LinkNode(const T& data, LinkNode<T> *ptr = NULL) {
    this->data_ = data;
    this->link_ = ptr;
  }

  T data_;
  LinkNode<T>* link_;
};


template<class T>
class LinkList {

public:

  // 构造函数(无参数)
  LinkList();
  // 构造函数(参数为头结点的数据项)
  LinkList(const T& data);
  // 构造函数(参数为节点指针引用)
  LinkList(LinkNode<T>* node);
  LinkList(LinkList<T>& link_list);
  ~LinkList();

  void MakeEmpty();
  int Length() const { return length_; }
  LinkNode<T>* GetHead() const { return head_ptr_; }
  LinkNode<T>* Search();
  LinkNode<T>* Locate(int pos);
  bool GetData(int pos, T& data) const;
  bool SetData(int pos, T& data);
  bool Insert(int pos, const T& data);
  bool Remove(int pos, T& data);
  bool IsEmpty() const;
  bool IsFull() const;
  bool Insert(int pos, LinkNode<T>* node);
  void Output();
  void CyberDashShow();

private:
  LinkNode<T>* head_ptr_;
  int length_;
  // int size_;
};


template<class T>
LinkList<T>::LinkList() {
  this->head_ptr_ = NULL;
  this->length_ = 0;
};


template<class T>
LinkList<T>::LinkList(const T& data) {
  this->head_ptr_ = new LinkNode<T>(data);
  this->length_ = 1;
}


template<class T>
LinkList<T>::LinkList(LinkNode<T>* node_ptr) {

  if (node_ptr == NULL) {
    LinkNode<T>();
    return;
  }

  this->head_ptr_ = node_ptr;
  this->length_ = 0;

  LinkNode<T>* cur_ptr = head_ptr_;

  while (cur_ptr != NULL) {
    this->length_++;
    cur_ptr = cur_ptr->link_;
  }
}


template<class T>
LinkList<T>::LinkList(LinkList<T>& link_list) {

  if (link_list.Length() == 0) {
    head_ptr_ = NULL;
    length_ = 0;
    return;
  }

  LinkNode<T>* cur_src_ptr = link_list.GetHead();

  if (link_list.Length() == 1) {
    head_ptr_ = new LinkNode<T>(cur_src_ptr->data_);
    head_ptr_->link_ = NULL;
    length_ = 1;
    return;
  }

  head_ptr_ = new LinkNode<T>();

  LinkNode<T>* cur_dest_ptr = head_ptr_;

  while (cur_src_ptr->link_ != NULL) {
    cur_dest_ptr->data_ = cur_src_ptr->data_;

    cur_dest_ptr->link_ = new LinkNode<T>();

    cur_dest_ptr = cur_dest_ptr->link_;
    cur_src_ptr = cur_src_ptr->link_;

    length_++;
  }

  cur_dest_ptr->data_ = cur_src_ptr->data_;
  cur_dest_ptr->link_ = NULL;
}


template<class T>
bool LinkList<T>::GetData(int pos, T& data) const {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = head_ptr_;

  while (pos - 1 > 0) {
    cur = cur->link_;
    pos--;
  }

  data = cur->data_;

  return true;
}


template<class T>
bool LinkList<T>::SetData(int pos, T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = head_ptr_;

  while (pos - 1 > 0) {
    cur = cur->link_;
    pos--;
  }

  cur->data_ = data;

  return true;
}


template<class T>
void LinkList<T>::MakeEmpty() {

}


template<class T>
void LinkList<T>::Output() {

  if (head_ptr_ == NULL) {
    cout<<"Empty list"<<endl;
    return;
  }

  LinkNode<T>* cur = GetHead();
  while(cur != NULL) {
    cout<<cur->data_<<" ";
    cur = cur->link_;
  }
  cout<<endl;

}


template<class T>
bool LinkList<T>::Insert(int pos, LinkNode<T>* node) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  if (node == NULL) {
    return false;
  }

  if (head_ptr_ == NULL) {
    node->link_ = head_ptr_;
    head_ptr_ = node;
    length_ = 1;
    return true;
  }

  if (pos == 0) {

    node->link_ = head_ptr_;
    head_ptr_ = node;
  } else {

    LinkNode<T>* cur = head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node->link_ = cur->link_;
    cur->link_ = node;
  }

  length_++;

  return true;
}


template<class T>
bool LinkList<T>::Insert(int pos, const T& data) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  LinkNode<T>* node = new LinkNode<T>(data);

  if (head_ptr_ == NULL) {
    node->link_ = head_ptr_;
    head_ptr_ = node;
    length_ = 1;
    return true;
  }

  if (pos == 0) {

    node->link_ = head_ptr_;
    head_ptr_ = node;
  } else {

    LinkNode<T>* cur = head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node->link_ = cur->link_;
    cur->link_ = node;
  }

  length_++;

  return true;
}


template<class T>
bool LinkList<T>::IsEmpty() const {

  if (length_ == 0) {
    return true;
  } else {
    return false;
  }
}


template<class T>
void LinkList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif // CYBER_DASH_LINK_LIST_H
