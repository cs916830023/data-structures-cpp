/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 排序测试.cpp文件
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
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
  cout<<"|                        测试冒泡排序                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"冒泡排序前:"<<endl;
  PrintArray(array, array_size);

  BubbleSort(array, array_size);

  cout<<"冒泡排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestSelectSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Select Sort                     |"<<endl;
  cout<<"|                        测试选择排序                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"选择排序前:"<<endl;
  PrintArray(array, array_size);

  SelectSort(array, array_size);

  cout<<"选择排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestInsertSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Insert Sort                     |"<<endl;
  cout<<"|                         测试插入排序                        |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"插入排序前:"<<endl;
  PrintArray(array, array_size);

  InsertSort(array, array_size);

  cout<<"插入排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestMergeSort() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Merge Sort                      |"<<endl;
  cout<<"|                         测试归并排序                        |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"归并排序前:"<<endl;
  PrintArray(array, array_size);

  MergeSort(array, array_size);

  cout<<"归并排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}


void TestMergeSortNonRecursive() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|               Test Merge Sort(NonRecursive)               |"<<endl;
  cout<<"|                     测试归并排序(非递归)                     |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"归并排序(非递归)前:"<<endl;
  PrintArray(array, array_size);

  MergeSortNonRecursive(array, array_size);

  cout<<"归并排序(非递归)后:"<<endl;
  PrintArray(array, array_size);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestQuickSort() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Quick Sort                      |"<<endl;
  cout<<"|                        测试快速排序                         |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"快速排序前:"<<endl;
  PrintArray(array, array_size);

  QuickSort(array, 0, array_size - 1);

  cout<<"快速排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"-------------------------------------------------------------"<<endl;
}



void TestHeapSort() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                       Test Heap Sort                      |"<<endl;
  cout<<"|                         测试堆排序                          |"<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"堆排序前:"<<endl;
  PrintArray(array, array_size);

  HeapSort(array, array_size);

  cout<<"堆排序后:"<<endl;
  PrintArray(array, array_size);

  cout<<"------------------------- CyberDash -------------------------"<<endl;
}

