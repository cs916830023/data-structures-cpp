/*!
 * @file seq_list.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ˳���ģ����
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include "linear_list.h"


using namespace std;


/*!
 * @brief ˳���ģ����
 * @tparam T ����ģ�����
 */
template<class T>
class SeqList: public LinearList<T> {

public:
  // ���캯��(�޲���)
  SeqList(): data_array_(NULL), size_(0), last_idx_(-1) {}

  // ���캯��(����:˳����ܳ���)
  SeqList(int size);

  // ���ƹ��캯��(����:˳���)
  SeqList(SeqList<T>& seq_list);

  // ��������
  ~SeqList() { delete[] data_array_; }

  // ��ȡ�ܳ���
  int Size() const;

  // ��ȡ��ǰ����
  int Length() const;

  // ����
  int Search(T& data) const;

  // ��λ
  int Locate(int pos) const;

  // ��ȡλ��pos������
  bool GetData(int pos, T& data) const;

  // ����λ��pos������
  bool SetData(int pos, const T& data);

  // λ��pos��������data
  bool Insert(int pos, const T& data);

  // ɾ��λ��pos������
  bool Remove(int pos, T& data);

  // �Ƿ�Ϊ��
  bool IsEmpty() const;

  // �Ƿ���
  bool IsFull() const;

  // ����˳���ĳ���
  int Resize(int new_size);

  // ����˳���
  void Input();

  // ����
  void Sort();

  // ��ӡ˳���
  void Output();

  // ��ֵ��������غ���
  SeqList<T>& operator= (const SeqList<T>& seq_list);

  // ������CyberDash
  void CyberDashShow();

private:
  T* data_array_; //!< ����������
  int size_; //!< ˳����ܳ���
  int last_idx_; //!< ���һ�����������
};


/**
 * @brief ���캯��
 * @tparam T ����ģ�����
 * @param size ˳���size
 */
template<class T>
SeqList<T>::SeqList(int size) {

  if (size > 0) {
    this->size_ = size;
    this->last_idx_ = -1;
    this->data_array_ = new T[size];
  }

  if (this->data_array_ == NULL) {
    cerr<<"new error"<<endl;
    exit(1);
  }
}


/*!
 * @brief ���ƹ��캯��
 * @tparam T ����ģ�����
 * @param seq_list ˳���
 */
template<class T>
SeqList<T>::SeqList(SeqList<T>& seq_list) {

  this->size_ = seq_list.Size();
  this->last_idx_ = seq_list.Length() - 1;

  if (this->size_ == 0) {
    return;
  }

  this->data_array_ = new T[this->Size()];
  if (this->data_array_ == NULL) {
    cerr<<"�洢�������!"<<endl;
    exit(1);
  }

  for (int i = 1; i <= this->last_idx_ + 1; i++) {
    T cur_value;
    seq_list.GetData(i, cur_value);
    this->data_array_[i - 1] = cur_value;
  }
}


/*!
 * @brief ����˳���ĳ���
 * @tparam T ����ģ�����
 * @param new_size �µ��ܳ���
 * @return �µ��ܳ���
 * @note
 * **����ֵ˵��**
 * -2: �����ڴ�ʧ��
 * -1: ��Ч����
 * 0: �µ��ܳ�����ԭ������ͬ
 */
template<class T>
int SeqList<T>::Resize(int new_size) {

  if (new_size <= 0) {
    cerr<<"��Ч�������С"<<endl;
    return -1;
  }

  if (new_size == this->Size()) {
    cout<<"�ط������鳤����ԭ���鳤����ͬ"<<endl;
    return 0;
  }

  T* new_data_array = new T[this->Size()];
  if (new_data_array == NULL) {
    cerr<<"�洢�������"<<endl;
    return -2;
  }

  T* src_ptr = data_array_;
  T* dest_ptr = new_data_array;

  for (int i = 0; i < this->Length(); i++) {
    *(dest_ptr + i) = *(src_ptr + i);
  }

  delete [] data_array_;
  data_array_ = new_data_array;

  size_ = new_size;

  return new_size;
}


/*!
 * @brief ��������
 * @tparam T ����ģ�����
 * @param data ����
 * @return ��˳����е�λ��
 */
template<class T>
int SeqList<T>::Search(T& data) const {

  int pos = 0; // ��1��ʼ, ����0��ʾû�в鵽

  for (int i = 0; i <= last_idx_; i++) {
    if (data_array_[i] == data) {
      pos = i + 1;
      break;
    }
  }

  return pos;
}


/*!
 * @brief ��λ
 * @tparam T ����ģ�����
 * @param pos ��pos��
 * @return λ��pos
 * @note
 * pos����1Ϊ��ʼ, ��ͬ��������0��ʼ
 */
template<class T>
int SeqList<T>::Locate(int pos) const {
  if (pos >= 1 && pos <= last_idx_ + 1) {
    return pos;
  } else {
    return 0;
  }
};


/*!
 * @brief ��ȡλ��pos������
 * @tparam T ����ģ�����
 * @param pos λ��pos
 * @param data ����(���ڱ���������)
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool SeqList<T>::GetData(int pos, T& data) const {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data = data_array_[pos - 1];
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ����λ��pos������
 * @tparam T ����ģ�����
 * @param pos λ��pos
 * @param data ����
 * @return �Ƿ����óɹ�
 */
template<class T>
bool SeqList<T>::SetData(int pos, const T& data) {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data_array_[pos - 1] = data;
    return true;
  } else {
    return false;
  }
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
bool SeqList<T>::Insert(int pos, const T& data) {

  if (last_idx_ == size_ - 1) {
    return false;
  }

  if (pos < 0 || pos > last_idx_ + 1) {
    return false;
  }

  for (int i = last_idx_; i >= pos; i--) {
    data_array_[i + 1] = data_array_[i];
  }

  data_array_[pos] = data;

  last_idx_++;

  return true;
}


/*!
 * @brief ɾ��λ��pos������
 * @tparam T ����ģ�����
 * @param pos λ��pos
 * @param remove_data ��ɾ����������
 * @return �Ƿ�ɾ���ɹ�
 */
template<class T>
bool SeqList<T>::Remove(int pos, T& remove_data) {

  if (last_idx_ == -1) {
    return false;
  }

  if (pos < 1 || pos > last_idx_ + 1) {
    return false;
  }

  remove_data = data_array_[pos - 1];

  for (int i = pos; i <= last_idx_; i++) {
    data_array_[i - 1] = data_array_[i];
  }

  last_idx_--;

  return true;
}


/*!
 * @brief �Ƿ�Ϊ�ձ�
 * @tparam T ����ģ�����
 * @return �Ƿ�Ϊ��
 */
template<class T>
bool SeqList<T>::IsEmpty() const {
  if (last_idx_ == -1) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ˳����Ƿ���
 * @tparam T ����ģ�����
 * @return �Ƿ���
 */
template<class T>
bool SeqList<T>::IsFull() const {
  if (last_idx_ == size_ - 1) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ��ֵ��������غ���
 * @tparam T ����ģ�����
 * @param seq_list ˳���
 * @return ˳�������
 */
template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& seq_list) {

  this->size_ = seq_list.Size();
  int p_length = seq_list.Length();

  for (int i = 0; i < p_length; i++) {
    int curData;
    seq_list.GetData(i, curData);

    this->SetData(i, curData);
  }

  return *this;
}


/*!
 * @brief ��ȡ�ܳ���
 * @tparam T ����ģ�����
 * @return �ܳ���
 */
template<class T>
int SeqList<T>::Size() const {
  return size_;
}


/*!
 * @brief ��ȡ��ǰ����
 * @tparam T ����ģ�����
 * @return ��ǰ����
 */
template<class T>
int SeqList<T>::Length() const {
  return last_idx_ + 1;
}


/*!
 * @brief ��ӡ˳���
 * @tparam T ����ģ�����
 */
template<class T>
void SeqList<T>::Output() {

  if (last_idx_ == -1) {
    cout<<"˳���Ϊ�ձ�:"<<endl;
  } else {
    for (int i = 0; i <= last_idx_; i++) {
      cout<<"#"<<i + 1<<":"<<data_array_[i]<<endl;
    }
  }

}


/*!
 * @brief ����
 * @tparam T ����ģ�����
 */
template<class T>
void SeqList<T>::Sort() {

    int length = this->Length();
    for (int i = 1; i < length; i++) {
        for (int j = 1; j <= length - i; j++) {

            T j_data;
            this->GetData(j, j_data);

            T j_next_data;
            this->GetData(j + 1, j_next_data);

            if (j_data > j_next_data) {
                this->SetData(j, j_next_data);
                this->SetData(j + 1, j_data);
            }
        }
    }
}


/*!
 * @brief ������CyberDash
 */
template<class T>
void SeqList<T>::CyberDashShow() {
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

#endif //CYBER_DASH_YUAN_SEQ_LIST_H
