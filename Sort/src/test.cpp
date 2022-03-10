/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �������.cpp�ļ�
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"
#include "sort.h"
#include "util.h"
#include <iostream>


using namespace std;


void TestBubbleSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Bubble Sort                     |"<<endl;
  cout<<"|                        ����ð������                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"ð������ǰ:"<<endl;
  PrintArray(array, array_size);

  BubbleSort(array, array_size);

  cout<<"ð�������:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestSelectSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Select Sort                     |"<<endl;
  cout<<"|                        ����ѡ������                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"ѡ������ǰ:"<<endl;
  PrintArray(array, array_size);

  SelectSort(array, array_size);

  cout<<"ѡ�������:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestInsertSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Insert Sort                     |"<<endl;
  cout<<"|                         ���Բ�������                        |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"��������ǰ:"<<endl;
  PrintArray(array, array_size);

  InsertSort(array, array_size);

  cout<<"���������:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestMergeSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Merge Sort                      |"<<endl;
  cout<<"|                         ���Թ鲢����                        |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"�鲢����ǰ:"<<endl;
  PrintArray(array, array_size);

  MergeSort(array, array_size);

  cout<<"�鲢�����:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestMergeSortNonRecursive() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|               Test Merge Sort(NonRecursive)               |"<<endl;
  cout<<"|                     ���Թ鲢����(�ǵݹ�)                     |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"�鲢����(�ǵݹ�)ǰ:"<<endl;
  PrintArray(array, array_size);

  MergeSortNonRecursive(array, array_size);

  cout<<"�鲢����(�ǵݹ�)��:"<<endl;
  PrintArray(array, array_size);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestQuickSort() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Quick Sort                      |"<<endl;
  cout<<"|                        ���Կ�������                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"��������ǰ:"<<endl;
  PrintArray(array, array_size);

  QuickSort(array, 0, array_size - 1);

  cout<<"���������:"<<endl;
  PrintArray(array, array_size);

  cout<<"-------------------------------------------------------------"<<endl;
}



void TestHeapSort() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                       Test Heap Sort                      |"<<endl;
  cout<<"|                         ���Զ�����                          |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"������ǰ:"<<endl;
  PrintArray(array, array_size);

  HeapSort(array, array_size);

  cout<<"�������:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}

