//
// Created by alei_go@163.com(����: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include <stdlib.h>
#include "min_heap.h"


using namespace std;


template <class E>
MinHeap<E>::MinHeap(int size) {

  max_size_ = (size > DEFAULT_SIZE) ? size : DEFAULT_SIZE;

  heap_array_ = new E[max_size_];
  if (heap_array_ == NULL) {
    cerr << "�Ѵ洢����ʧ�ܣ�" << endl;
    exit(1);
  }

  current_size_ = 0;
}


template <class E>
MinHeap<E>::MinHeap(E arr[], int arr_size) {
  max_size_ = (arr_size > DEFAULT_SIZE) ? arr_size : DEFAULT_SIZE;
  heap_array_ = new E[max_size_];

  if (heap_array_ == NULL) {
    cerr << "�Ѵ洢����ʧ�ܣ�" << endl;
    exit(1);
  }

  for (int i = 0; i < arr_size; i++) {
    heap_array_[i] = arr[i];
  }

  current_size_ = arr_size;

  int current_index_ = (current_size_ - 2) / 2;

  while (current_index_ >= 0) {
    siftDown(current_index_, current_size_ - 1);
    current_index_--;
  }
}


template <class E>
void MinHeap<E>::siftDown(int start, int end) {

  int cur = start;

  int left_child = 2 * cur + 1;
  int right_child = left_child + 1;

  int min_child = left_child;

  E cur_value = heap_array_[cur];

  while (left_child <= end) {

    // find the min child
    if (left_child < end && heap_array_[left_child] > heap_array_[right_child]) {
      min_child = right_child;
    }

    if (cur_value <= heap_array_[min_child]) {
      break;
    } else {
      heap_array_[cur] =  heap_array_[min_child];
      cur = min_child;

      left_child = 2 * min_child + 1;
      right_child = left_child + 1;
      min_child = left_child;
    }
  }

  heap_array_[cur] = cur_value;
}


template <class E>
void MinHeap<E>::siftUp(int start) {
  int j = start, i = (j - 1) / 2;
  E temp = heap_array_[j];

  while (j > 0) {
    if (heap_array_[i] <= temp) {
      break;
    } else {
      heap_array_[j] = heap_array_[i];
      j = i;
      i = (i - 1) / 2;
    }
  }

  heap_array_[j] = temp;
}


template <class E>
bool MinHeap<E>::Insert(const E& item) {

  if (current_size_ == max_size_) {
    cerr << "Heap Full." << endl;
    return false;
  }

  heap_array_[current_size_] = item;

  siftUp(current_size_);

  current_size_++;

  return true;
}


template <class E>
bool MinHeap<E>::RemoveMin(E& x) {
  if (!current_size_) {
    cerr << "Heap Empty." << endl;
    return false;
  }

  x = heap_array_[0];
  heap_array_[0] = heap_array_[current_size_ - 1];
  current_size_--;

  siftDown(0, current_size_ - 1);

  return true;
}


template<class T>
void MinHeap<T>::CyberDashShow() {
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
