/*!
 * @file double_link_list.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ˫������(ѭ��)
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_H


#include "linear_list.h"
#include <iostream>
#include <cstddef>


/*!
 * @brief ˫��������ģ����
 * @tparam T ����ģ�����
 */
template <class T>
struct DoubleLinkNode {
  /*!
   * @brief ���캯��(��һ�������һ���ָ��)
   * @param next ��һ���ָ��
   * @param prev ��һ���ָ��
   */
  explicit DoubleLinkNode(DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL): prev(prev), next(next) {}

  /*!
   * @brief ���캯��(������, ��һ������һ���ָ��)
   * @param data ������
   * @param next ��һ���ָ��
   * @param prev ��һ���ָ��
   */
  explicit DoubleLinkNode(const T& data, DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL):
    data(data), prev(prev), next(next) {}

  T data; //!< ����������
  DoubleLinkNode<T>* next; //!< ��һ���
  DoubleLinkNode<T>* prev; //!< ��һ���
};


/*!
 * @brief ˫������ģ����
 * @tparam T ����ģ�����
 */
template<class T>
class DoubleLinkList: public LinearList<T> {
public:
  /*! @brief ���캯��(�޲���) */
  DoubleLinkList();

  /*! @brief �������� */
  ~DoubleLinkList();

  /*! @brief ���� */
  int Length() const { return this->length_; }

  /*! @brief �Ƿ�Ϊ�� */
  bool IsEmpty() const { return this->head_->next == this->head_; }

  /*! @brief ��ȡ����ͷ��� */
  DoubleLinkNode<T>* Head() const { return this->head_; }

  // ����
  DoubleLinkNode<T>* Search(const T& data);

  // ������λ
  DoubleLinkNode<T>* LocateByDirection(int pos, int direction);

  // ��λ
  DoubleLinkNode<T>* Locate(int pos);

  // ���������
  bool InsertByDirection(int pos, const T& data, int direction);

  // ������
  bool Insert(int pos, const T& data);

  // ������ɾ�����
  bool RemoveByDirection(int pos, T& data, int direction);

  // ���ɾ���ڵ�
  bool Remove(int pos, T& data);

  // ��ȡ�������
  bool GetData(int pos, T& data) const;

  // ���ý������
  bool SetData(int pos, const T& data);

  //Լɪ��
  int LastRemaining(DoubleLinkNode* head, int m);

  // ��ӡ˫������
  void Output();

  // ������CyberDash
  void CyberDashShow();

  static const int PREV_DIRECTION = 0;
  static const int NEXT_DIRECTION = 1;

private:
  DoubleLinkNode<T>* head_;
  int length_;
};


/*!
 * @brief ���캯��(�޲���)
 */
template<class T>
DoubleLinkList<T>::DoubleLinkList() {
  this->head_ = new DoubleLinkNode<T>();
  /* error handler */

  this->head_->next = this->head_;
  this->head_->prev = this->head_;

  this->length_ = 0;
}


/*!
 * @brief ��������
 */
template<class T>
DoubleLinkList<T>::~DoubleLinkList() {

  while (this->head_->next != this->head_) {
    DoubleLinkNode<T>* delete_node = this->head_->next;
    this->head_->next = delete_node->next;

    delete delete_node;
  }

  delete this->head_;
  this->head_ = NULL;
}


/*!
 * @brief ����
 * @param data ����
 * @return ���ָ��
 * @note
 * ����������������ݵĽ��,
 * ��û��, �򷵻�NULL
 */
template<class T>
DoubleLinkNode<T>* DoubleLinkList<T>::Search(const T& data){
  DoubleLinkNode<T>* cur = this->head_->next;
  while (cur != this->head_ && cur->data != data) {
    cur = cur->next;
  }

  if (cur != this->head_) {
    return cur;
  }

  return NULL;
}


/*!
 * @brief ������λ
 * @param pos λ��
 * @param direction ����(0Ϊ��ǰ����0Ϊ���)
 * @return ���ָ��
 * @note
 * ���ϵ��߼�
 * ����ǿ�����, ����λλ��0ʱ, ����ͷ�ڵ�ĵ�ַ
 * ������ǿ�����
 *  ��λ��, �򷵻ص�ַ
 *  ��λ����, ����NULL
 */
template<class T>
DoubleLinkNode<T>* DoubleLinkList<T>::LocateByDirection(int pos, int direction) {

  if (this->head_->next == head_ || pos == 0) {
    return this->head_;
  }

  DoubleLinkNode<T>* cur;
  if (direction == DoubleLinkList::PREV_DIRECTION) {
    cur = head_->prev;
  } else {
    cur = head_->next;
  }

  for (int i = 1; i < pos; i++) {
    if (cur == this->head_) {
      return NULL;
    }
    
    if (direction == DoubleLinkList::PREV_DIRECTION) {
      cur = cur->prev;
    } else {
      cur = cur->next;
    }
  }

  if (cur != this->head_) {
    return cur;
  }

  return NULL;
}


/*!
 * @brief ���λ
 * @tparam T ����ģ�����
 * @param pos λ��
 * @return ���ָ��
 */
template<class T>
DoubleLinkNode<T>* DoubleLinkList<T>::Locate(int pos) {
  return this->LocateByDirection(pos, DoubleLinkList::NEXT_DIRECTION);
}


/*!
 * @brief ���������
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����
 * @param direction ����
 * @return �Ƿ����ɹ�
 */
template<class T>
bool DoubleLinkList<T>::InsertByDirection(int pos, const T& data, int direction) {

  DoubleLinkNode<T>* cur = LocateByDirection(pos, direction);
  if (cur == NULL) {
    return false;
  }

  DoubleLinkNode<T>* new_node = new DoubleLinkNode<T>(data);
  if (new_node == NULL) {
    return false;
  }

  if (direction == DoubleLinkList::PREV_DIRECTION) {
    new_node->prev = cur->prev;
    cur->prev = new_node;
    new_node->prev->next = new_node;
    new_node->next = cur;
  } else {
    new_node->next = cur->next;
    cur->next = new_node;
    new_node->next->prev = new_node;
    new_node->prev = cur;
  }

  this->length_++;

  return true;
}


/*!
 * @brief ������
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����
 * @return �Ƿ����ɹ�
 */
template<class T>
bool DoubleLinkList<T>::Insert(int pos, const T &data) {
  return this->InsertByDirection(pos, data, DoubleLinkList::NEXT_DIRECTION);
}


/*!
 * @brief ������ɾ�����
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����(���汻ɾ�����������)
 * @param direction ����
 * @return �Ƿ�ɾ���ɹ�
 */
template<class T>
bool DoubleLinkList<T>::RemoveByDirection(int pos, T& data, int direction){
  DoubleLinkNode<T>* cur = LocateByDirection(pos, direction);
  if (cur == NULL) {
    return false;
  }

  cur->next->prev = cur->prev;
  cur->prev->next = cur->next;
  data = cur->data;

  delete cur;
  this->length_--;

  return true;
}


/*!
 * @brief ���ɾ���ڵ�
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����(���汻ɾ�����������)
 * @return �Ƿ�ɾ���ɹ�
 */
template<class T>
bool DoubleLinkList<T>::Remove(int pos, T &data) {
  return this->RemoveByDirection(pos, data, DoubleLinkList::NEXT_DIRECTION);
}


/*!
 * @brief ��ȡ�������
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool DoubleLinkList<T>::GetData(int pos, T& data) const{
  if (pos < 1 || pos > Length()) {
    return false;
  }

  DoubleLinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  data = cur->data;

  return true;
}


/*!
 * @brief ���ý������
 * @tparam T ����ģ�����
 * @param pos λ��
 * @param data ����
 * @return �Ƿ����óɹ�
 */
template<class T>
bool DoubleLinkList<T>::SetData(int pos, const T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  DoubleLinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  cur->data = data;

  return true;
}

/*!
 * @brief Լɪ������
 * @param head ��λ���
 * @param m ����m�ͳ��� 
 * @return ʣ��Ľ��ֵ
 */
template<class T>
int DoubleLinkList<T>::LastRemaining(DoubleLinkNode* head, int m){

}


/*!
 * @brief ��ӡ˫������
 * @tparam T ����ģ�����
 */
template<class T>
void DoubleLinkList<T>::Output(){
  if (this->head_ == NULL) {
    cout<<"Empty list"<<endl;
    return;
  }

  cout << "�����������" << endl;
  DoubleLinkNode<T>* cur = this->Head()->next;
  while (cur != this->head_) {
    cout << cur->data << "; ";
    cur = cur->next;
  }
  cout << endl;

  cout << "��ǰ�������" << endl;
  cur = cur->prev;
  while (cur != this->head_) {
    cout << cur->data << "; ";
    cur = cur->prev;
  }
  cout << endl;

  cout<<endl;
}




template<class T>
void DoubleLinkList<T>::CyberDashShow() {
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



#endif // CYBER_DASH_DOUBLE_LINK_LIST_H
