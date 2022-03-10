//
// Created by Zhongyuan.Li on 9/29/2021.
//

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_TEST_H

#include "double_link_list.h"


using namespace std;


/*!
 * @brief ˫�����������
 */
class DoubleLinkListTest {
public:
  /*! @brief ���԰�������� */
  static void TestInsertByDirection();
  /*! @brief ����ɾ�� */
  static void TestRemoveByDirection();
  /*! @brief ���Գ��� */
  static void TestLength();
  /*! @brief ���������Ƿ�Ϊ�� */
  static void TestEmpty();
  /*! @brief ����������� */
  static void TestSearch();
  /*! @brief ��������λ */
  static void TestLocate();
  /*! @brief ���Ի�ȡ�������� */
  static void TestGetDataAndSetData();
};


void DoubleLinkListTest::TestInsertByDirection() {
  cout << endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test DoubleList InsertByDirection            |"<<endl;
  cout<<"|                     ����˫�������������                    |"<<endl<<endl<<endl;

  DoubleLinkList<string>* band_list = new DoubleLinkList<string>();

  band_list->InsertByDirection(0, "The Script", DoubleLinkList<string>::NEXT_DIRECTION);
  band_list->InsertByDirection(1, "Linkin Park", DoubleLinkList<string>::NEXT_DIRECTION);
  band_list->InsertByDirection(2, "Starship", DoubleLinkList<string>::NEXT_DIRECTION);

  band_list->Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestRemoveByDirection() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test DoubleList RemoveByDirection            |"<<endl;
  cout<<"|                     ����˫����������ɾ��                   |"<<endl<<endl<<endl;

  DoubleLinkList<string>* city_list = new DoubleLinkList<string>();

  city_list->Insert(0, "Beijing");
  city_list->Insert(1, "Shanghai");
  city_list->Insert(2, "Shenzhen");

  city_list->Output();

  string delete_item;

  int delete_pos = 3;
  city_list->RemoveByDirection(delete_pos, delete_item, DoubleLinkList<int>::NEXT_DIRECTION);

  cout<<"���ɾ������"<<delete_pos<<"֮��: "<<endl;
  city_list->Output();

  delete_pos = 1;
  city_list->RemoveByDirection(delete_pos, delete_item, DoubleLinkList<int>::NEXT_DIRECTION);

  cout<<"���ɾ������"<<delete_pos<<"֮��: "<<endl;
  city_list->Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestLength(){

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test DoubleList Length                  |"<<endl;
  cout<<"|                       ����˫��������                      |"<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  cout<<"˫��������: "<<double_list->Length()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestEmpty(){

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test DoubleList Empty                   |"<<endl;
  cout<<"|                        ����˫�������Ƿ�Ϊ��                  |"<<endl<<endl<<endl;

  DoubleLinkList<string>* double_link;
  double_link = new DoubleLinkList<string>();

  cout<<"Before insert any string:"<<endl;

  bool isEmpty = double_link->IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  string BJ = "Beijing";
  double_link->Insert(0,BJ);

  cout<<"After insert the string \"Beijing\":"<<endl;

  isEmpty = double_link->IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestSearch(){

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test DoubleList Search                  |"<<endl;
  cout<<"|                       ����˫���������                      |"<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  DoubleLinkNode<int>* node_1 = double_list->Search(1);
  DoubleLinkNode<int>* node_3 = double_list->Search(3);

  cout << "The pos of " << 1 << " is " << node_1 <<endl;
  cout << "The pos of " << 3 << " is " << node_3 <<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestLocate() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test DoubleList Locate                   |"<<endl;
  cout<<"|                       ����˫������λ                       |"<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  DoubleLinkNode<int>* node_ptr = double_list->Locate(3);

  cout<<"The node_ptr is: " <<node_ptr<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestGetDataAndSetData() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test DoubleList GetData And SetData          |"<<endl;
  cout<<"|                   ����˫�������ȡ/����������                 |"<<endl<<endl<<endl;

  DoubleLinkList<string>* city_list = new DoubleLinkList<string>();

  city_list->Insert(0, "Beijing");
  city_list->Insert(1, "Shanghai");
  city_list->Insert(2, "Shenzhen");

  string city_name;
  city_list->GetData(1, city_name);
  cout<<"The city_name: "<<city_name;

  cout<<endl<<"-------------------------------------------------------------"<<endl<<endl;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
