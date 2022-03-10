/*!
 * @file link_stack.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��ʽջģ����
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_LINK_STACK_H
#define CYBER_DASH_LINK_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


/*!
 * @brief ���ģ��ṹ��
 * @tparam T ����ģ�����
 */
template <class T>
struct LinkNode {
  explicit LinkNode(LinkNode<T>* node = NULL): link(node) {}
  explicit LinkNode(const T& data, LinkNode<T>* node = NULL): data(data), link(node) {}

  T data; //!< ������
  LinkNode<T>* link; //!< ��һ���
};


/*!
 * @brief ��ʽջģ����
 * @tparam T ����ģ�����
 */
template <class T>
class LinkStack: public Stack<T>{

public:
  /*! @brief ���캯�� */
  LinkStack(): top_(NULL) {}
  // ��������
  ~LinkStack();
  // ��ջ
  void Push(const T& data);
  // ��ջ(��������)
  bool Pop(T& data);
  // ��ջ(����������)
  bool Pop();
  // ��ȡջ������
  bool GetTop(T& data) const;
  // �ж�ջ�Ƿ�Ϊ��
  bool IsEmpty() const;
  // ��ȡջ��С
  int GetSize() const;
  // ���
  void MakeEmpty();

  // ��ȡջ�����ָ��
  LinkNode<T>* GetTopPtr();

  //�Թ�����
  // int SeekPath(int x,int y);

  // ����<<(��ӡջ)
  template<class U>
  friend ostream& operator<<(ostream& os, LinkStack<T>& stack);

  void CyberDashShow();

private:
  LinkNode<T>* top_;     //!< ջ�����ָ��
};


/*!
 * @brief ��������
 * @tparam T ����ģ�����
 * @note ��ʽ����ʱ����
 */
template<class T>
LinkStack<T>::~LinkStack<T>() {
  MakeEmpty();
}


/*!
 * @brief ��ȡջ�����ָ��
 * @tparam T ����ģ�����
 * @return ջ�����ָ��
 */
template<class T>
LinkNode<T>* LinkStack<T>::GetTopPtr() {
  return top_;
}


/*!
 * @brief ��ջ
 * @tparam T ����ģ�����
 */
template <class T>
void LinkStack<T>::Push(const T& data)
{
  LinkNode<T>* node = new LinkNode<T>(data);

  node->link = this->top_;
  this->top_ = node;
}


/**
 * @brief ��ջ(����������)
 * @tparam T ����ģ�����
 * @param data ����(����������)
 * @return �Ƿ�ɹ�
 */
template <class T>
bool LinkStack<T>::Pop(T& data)
{
  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* delete_node = this->top_;
  this->top_ = this->top_->link;

  data = delete_node->data;

  delete delete_node;
  delete_node = NULL;

  return true;
}


/**
 * @brief ��ջ(������������)
 * @tparam T ����ģ�����
 * @param data ����(����������)
 * @return �Ƿ�ɹ�
 */
template <class T>
bool LinkStack<T>::Pop()
{
  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* delete_node = this->top_;
  this->top_ = this->top_->link;

  delete delete_node;
  delete_node = NULL;

  return true;
}


/*!
 * @brief ��ȡջ��Ԫ��
 * @tparam T ջԪ������
 * @return ���ز����Ƿ�ִ�гɹ�
 * @note
 * ������ȡջ��Ԫ�أ�����Ҫ��ջ��Ԫ��ɾ��
 */
template <class T>
bool LinkStack<T>::GetTop(T& data) const
{
  if (IsEmpty()) {
    return false;
  }

  data = this->top_->data;

  return true;
}


/*!
 * @brief ��ȡջ�Ĵ�С
 * @return ջ�Ĵ�С
 */
template<class T>
int LinkStack<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur = this->top_;

  while (cur != NULL) {
    count++;
    cur = cur->link;
  }

  return count;
}


/*!
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @return �Ƿ�Ϊ��
 */
template<class T>
bool LinkStack<T>::IsEmpty() const {
  if (this->top_ == NULL) {
    return true;
  } else {
    return false;
  }
}


/**
 * @brief ���ջ
 * @tparam T ջԪ������
 * @note
 * ��Ҫ�ͷ�ջ��ÿ��Ԫ��
 */
template<class T>
void LinkStack<T>::MakeEmpty() {
  while (this->top_ != NULL) {
    LinkNode<T>* cur = this->top_;
    top_ = top_->link;

    delete cur;
    cur = NULL;
  }
}


/*
template<class T>
int LinkStack<T>::SeekPath(int x,int y){

}
 */


/**
 * @brief ����<<(��ӡջ)
 * @tparam T ����ģ�����
 * @param os �����
 * @param link_stack ջ
 * @return �����
 */
template<class T>
ostream& operator<<(ostream& os, LinkStack<T>& stack) {

  os<<"ջ��Ԫ�ظ���: "<<stack.GetSize()<<endl;

  LinkNode<T>* cur = stack.GetTopPtr();

  for (int i = 1; cur != NULL; i++) {
    os << i << ":" << cur->data << endl;
    cur = cur->link;
  }

  return os;
}


template<class T>
void LinkStack<T>::CyberDashShow() {
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


#endif //CYBER_DASH_LINK_STACK_H
