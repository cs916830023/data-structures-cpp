//
// Created by cyberdash@163.com on 2021/5/29.
//

#include "test.h"
#include "string"


using namespace std;


void TestSearchListSeqSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test SearchListSeqSearch                 |"<<endl;
  cout<<"|                      ����˳����˳������                    |"<<endl;

  int size = 100;
  SearchList<string, string> search_list(size);

  search_list.Insert("My hometown", "����");
  search_list.Insert("My senior high school", "����������ѧ");
  search_list.Insert("My college", "�����ʵ��ѧ");

  int pos1 = search_list.SeqSearch("My hometown");
  int pos2 = search_list.SeqSearch("My senior high school");
  int pos3 = search_list.SeqSearch("My college");

  cout<<"(��1��ʼ)"<<endl;
  cout<<"\"My hometown\"����λ��: "<<pos1<<endl;
  cout<<"\"My senior high school\"����λ��: "<<pos2<<endl;
  cout<<"\"My college\"����λ��: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestSearchListSeqSearchRecursive() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|             Test SearchListSeqSearchRecursive             |"<<endl;
  cout<<"|                    ����˳����˳������(�ݹ�)                 |"<<endl;

  int size = 100;
  SearchList<string, string> search_list(size);

  search_list.Insert("My hometown", "����");
  search_list.Insert("My senior high school", "����������ѧ");
  search_list.Insert("My college", "�����ʵ��ѧ");

  int pos1 = search_list.SeqSearchRecursive("My hometown", 1);
  int pos2 = search_list.SeqSearchRecursive("My senior high school", 1);
  int pos3 = search_list.SeqSearchRecursive("My college", 1);

  cout<<"(��1��ʼ)"<<endl;
  cout<<"\"My hometown\"����λ��: "<<pos1<<endl;
  cout<<"\"My senior high school\"����λ��: "<<pos2<<endl;
  cout<<"\"My college\"����λ��: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestSortedListSeqSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test SortedListSeqSearch                 |"<<endl;
  cout<<"|                    ��������˳����˳������                   |"<<endl;

  int size = 100;
  SortedList<string, string> sorted_list(size);

  sorted_list.Insert("My hometown", "����");
  sorted_list.Insert("My senior high school", "����������ѧ");
  sorted_list.Insert("My college", "�����ʵ��ѧ");

  int pos1 = sorted_list.SeqSearch("My hometown");
  int pos2 = sorted_list.SeqSearch("My senior high school");
  int pos3 = sorted_list.SeqSearch("My college");

  cout<<"(��1��ʼ)"<<endl;
  cout<<"\"My hometown\"����λ��: "<<pos1<<endl;
  cout<<"\"My senior high school\"����λ��: "<<pos2<<endl;
  cout<<"\"My college\"����λ��: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestSortedListBinarySearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                Test SortedListBinarySearch                |"<<endl;
  cout<<"|                ��������˳�����۰�����(�ǵݹ�)                   |"<<endl;

  int size = 100;
  SortedList<string, string> sorted_list(size);

  sorted_list.Insert("My hometown", "����");
  sorted_list.Insert("My senior high school", "����������ѧ");
  sorted_list.Insert("My college", "�����ʵ��ѧ");

  int pos1 = sorted_list.BinarySearch("My hometown");
  int pos2 = sorted_list.BinarySearch("My senior high school");
  int pos3 = sorted_list.BinarySearch("My college");

  cout<<"(��1��ʼ)"<<endl;
  cout<<"\"My hometown\"����λ��: "<<pos1<<endl;
  cout<<"\"My senior high school\"����λ��: "<<pos2<<endl;
  cout<<"\"My college\"����λ��: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestSortedListBinarySearchRecursive() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|            Test SortedListBinarySearchRecursive           |"<<endl;
  cout<<"|                  ��������˳�����۰�����(�ݹ�)               |"<<endl;

  int size = 100;
  SortedList<string, string> sorted_list(size);

  sorted_list.Insert("My hometown", "����");
  sorted_list.Insert("My senior high school", "����������ѧ");
  sorted_list.Insert("My college", "�����ʵ��ѧ");

  int pos1 = sorted_list.BinarySearchRecursive("My hometown", 1, sorted_list.Length());
  int pos2 = sorted_list.BinarySearchRecursive("My senior high school", 1, sorted_list.Length());
  int pos3 = sorted_list.BinarySearchRecursive("My college", 1, sorted_list.Length());

  cout<<"(��1��ʼ)"<<endl;
  cout<<"\"My hometown\"����λ��: "<<pos1<<endl;
  cout<<"\"My senior high school\"����λ��: "<<pos2<<endl;
  cout<<"\"My college\"����λ��: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}
