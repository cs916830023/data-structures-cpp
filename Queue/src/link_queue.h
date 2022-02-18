/**
 * @file link_queue.h
 * @author cyberdash@163.com(����: cyberdash_yuan)
 * @brief ����ʵ�ֶ���
 * @version 0.2.1
 * @date 2021-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_LINK_QUEUE_H
#define CYBER_DASH_LINK_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


/*!
 * @brief ������н��ģ��ṹ��
 * @tparam T ����ģ�����
 */
template <class T>
class LinkNode{

public:
  /*!
   * @brief ���캯��(��һ���ָ��)
   * @param node ��һ���ָ��
   */
  LinkNode(LinkNode<T>* node = NULL): link_(node) {}

  /**
   * @brief ���캯��(������&��һ���ָ��)
   * @param data ������
   * @param node ��һ���ָ��
   */
  LinkNode(const T& data, LinkNode<T>* node = NULL): data_(data), link_(node) {}

  /**
   * @brief ��ȡ��ǰ���ֵ
   * @return T ����ģ�����
   */
  T GetData() { return data_; }

  /*!
   * @brief ���õ�ǰ���ֵ
   * @param data ����Ľ��ֵ
   * @return �Ƿ�ɹ�
   */
  bool SetData(const T& data)
  {
    data_ = data;
    return true;
  }

  /*!
   * @brief ��ȡ��һ���
   * @return LinkNode<T>* ������һ���
   */
  LinkNode<T>* GetLink() { return link_; }

  /*!
   * @brief ������һ���
   * @param node ��һ���ָ��
   * @return �Ƿ�ɹ�
   */
  bool SetLink(LinkNode<T>* node)
  {
    link_ = node;
    return true;
  }

private:
  T data_; //!< ���������
  LinkNode<T>* link_; //!< ��һ���
};


/**
 * @brief �������ģ����
 * @tparam T ����ģ�����
 */
template <class T>
class LinkQueue: public Queue<T> {

public:
  /*! @brief ���캯�� */
  LinkQueue(): front_(NULL), rear_(NULL) {}

  /*! @brief �������� */
  ~LinkQueue() { MakeEmpty(); }

  /*!
   * @brief ���
   * @param data ������
   * @return �Ƿ���ӳɹ�
   */
  bool EnQueue(const T& data);

  // ����(��������)
  bool DeQueue(T& data);

  // ����(����������)
  bool DeQueue();

  // ��ȡ��ͷ����
  bool GetFront(T& data) const;

  // ��ȡ��β����
  bool GetRear(T& data) const;

  // �ж϶����Ƿ�Ϊ��
  bool IsEmpty() const;

  // ��ȡ���г���
  int GetSize() const;

  // ��ն���
  void MakeEmpty();

  /*!
   * @brief ��ȡ��ͷ���ָ��
   * @return ��ͷ���ָ��
   */
  LinkNode<T>* GetFrontPtr() { return this->front_; }

  /*!
   * @brief ��ȡ��β���ָ��
   * @return LinkNode<T>* ��β���ָ��
   */
  LinkNode<T>* GetRearPtr() { return this->rear_; }

  // ����<<(��ӡ����)
  template<class U>
  friend ostream& operator<<(ostream& os, LinkQueue<T>& link_queue);
  
  // ������CyberDash:-)
  void CyberDashShow();

private:
  LinkNode<T>* front_; //!< ��ͷָ��
  LinkNode<T>* rear_; //!< ��βָ��
};


/*!
 * @brief ���
 * @tparam T ����ģ�����
 * @param data ����
 * @return �Ƿ�ɹ�
 */
template<class T>
bool LinkQueue<T>::EnQueue(const T& data) {

  LinkNode<T>* new_node = new LinkNode<T>(data);
  if (new_node == NULL) {
    return false;
  }

  if (IsEmpty()) {
    this->front_ = new_node;
    this->rear_ = new_node;
  } else {
    this->rear_->SetLink(new_node);
    this->rear_ = new_node;
  }

  return true;
}


/*!
 * @brief ����(��������)
 * @tparam T ����ģ�����
 * @param data ����(������ӽ���������)
 * @return �Ƿ���ӳɹ�
 */
template<class T>
bool LinkQueue<T>::DeQueue(T& data) {

  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* cur = front_;

  data = cur->GetData();
  this->front_ = this->front_->GetLink();

  delete cur;
  cur = NULL;

  return true;
}


/*!
 * @brief ����(����������)
 * @tparam T ����ģ�����
 * @param data ����(������ӽ���������)
 * @return �Ƿ���ӳɹ�
 */
template<class T>
bool LinkQueue<T>::DeQueue() {

  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* cur = this->front_;

  this->front_ = this->front_->GetLink();

  delete cur;
  cur = NULL;

  return true;
}


/*!
 * @brief ��ȡ��ͷ����
 * @tparam T ����ģ�����
 * @param data ����(���ڱ����ͷ������)
 * @return �Ƿ�ɹ�
 */
template<class T>
bool LinkQueue<T>::GetFront(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->front_->GetData();

  return true;
}


/*!
 * @brief ��ȡ��β����
 * @tparam T ����ģ�����
 * @param data ����(���ڱ���������)
 * @return �Ƿ�ɹ�
 */
template<class T>
bool LinkQueue<T>::GetRear(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->rear_->GetData();

  return true;
}


/*!
 * @brief �ж϶����Ƿ�Ϊ��
 * @tparam T ����ģ�����
 * @return �Ƿ�Ϊ��
 */
template<class T>
bool LinkQueue<T>::IsEmpty() const {
  if (this->front_ == NULL) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ��ȡ���г���
 * @tparam T ����ģ�����
 * @return ���г���
 */
template<class T>
int LinkQueue<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur = this->front_;

  while (cur != NULL) {
    cur = cur->GetLink();
    count++;
  }

  return count;
}


/*!
 * @brief ��ն���
 * @tparam T ����ģ�����
 */
template<class T>
void LinkQueue<T>::MakeEmpty() {
  while (!this->IsEmpty()) {
    this->DeQueue();
  }
}


/*!
 * @brief ����<<(��ӡ����)
 * @tparam T ����ģ�����
 * @param os �����
 * @param link_queue �������
 * @return �����
 */
template<class T>
ostream& operator<<(ostream& os, LinkQueue<T>& link_queue) {

  os<<"The size of link queue: "<<link_queue.GetSize()<<endl;

  LinkNode<T>* cur_ptr = link_queue.GetFrontPtr();

  for (int i = 1; cur_ptr != NULL; i++) {
    os<<i<<":"<<cur_ptr->GetData()<<endl;
    cur_ptr = cur_ptr->GetLink();
  }

  return os;
}


template<class T>
void LinkQueue<T>::CyberDashShow() {
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

#endif //CYBER_DASH_LINK_QUEUE_H
