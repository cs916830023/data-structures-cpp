/*!
 * @file link_list_test.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �����������
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_LINK_LIST_TEST_H
#define CYBER_DASH_LINK_LIST_TEST_H


#include "link_list.h"


/*!
 * @brief �����������
 */
class LinkListTest {
public:
  /*! @brief ���Ը��ƹ��캯�� */
  static void TestCopyConstructor();

  /*! @brief ���Բ��� */
  static void TestInsert();

  /*! @brief ���Գ��� */
  static void TestLength();

  /*! @brief ����ɾ�� */
  static void TestRemove();

  /*! @brief ����������� */
  static void TestMakeEmpty();

  /*! @brief ���Բ��� */
  static void TestSearch();

  /*! @brief ���Զ�λ */
  static void TestLocate();

  /*! @brief �������úͻ�ȡ���� */
  static void TestGetDataAndSetData();
};


void LinkListTest::TestCopyConstructor() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                Test LinkList CopyConstructor              |" << endl;
  cout << "|                       ���������ƹ���                       |" << endl << endl << endl;

  LinkList<string> link_list;

  link_list.Insert(0, "Beijing");
  link_list.Insert(1, "Shanghai");
  link_list.Insert(2, "Guangzhou");

  link_list.Output();

  // LinkList<string>* link_list_2 = new LinkList<string>(link_list);
  LinkList<string> link_list_2(link_list);

  link_list_2.Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestInsert() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Insert                   |" << endl;
  cout << "|                         �����������                        |" << endl << endl << endl;

  LinkList<int>* link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLength() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Length                   |" << endl;
  cout << "|                         ����������                        |" << endl << endl << endl;

  LinkList<int> *link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  cout << "������: " << link_list->Length() << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestRemove() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Remove                   |" << endl;
  cout << "|                         ��������ɾ��                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  cout << "ɾ��ǰ������:" << endl;
  link_list->Output();

  cout << "����ɾ������:" << endl;

  string delete_str;
  link_list->Remove(1, delete_str);
  link_list->Output();
  link_list->Remove(4, delete_str);
  link_list->Output();
  link_list->Remove(2, delete_str);
  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestMakeEmpty() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                  Test LinkList MakeEmpty                  |" << endl;
  cout << "|                         �����������                        |" << endl << endl << endl;

  LinkList<double>* link_list = new LinkList<double>();

  link_list->Insert(0, 135.34);
  link_list->Insert(1, 305.43);
  link_list->Insert(2, 304.83);
  link_list->Insert(3, 405.31);
  link_list->Insert(4, 804.54);

  link_list->Output();

  link_list->MakeEmpty();

  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestSearch() {

  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                   Test LinkList Search                    |" << endl;
  cout << "|                         ������������                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  LinkNode<string>* bj_node_ptr = link_list->Search("Beijing");
  LinkNode<string>* cx_node_ptr = link_list->Search("Caoxian");

  cout << "bj_node_ptr->data: " << bj_node_ptr->data << endl;
  cout << "cx_node_ptr->data: " << cx_node_ptr->data << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLocate() {

  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                   Test LinkList LocateByDirection                    |" << endl;
  cout << "|                         ��������λ                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  LinkNode<string>* pos_1_node_ptr = link_list->Locate(1);
  LinkNode<string>* pos_2_node_ptr = link_list->Locate(2);

  cout << "pos_1_node_ptr->data: " << pos_1_node_ptr->data << endl;
  cout << "pos_2_node_ptr->data: " << pos_2_node_ptr->data << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestGetDataAndSetData() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|              Test LinkList GetDataAndSetData              |" << endl;
  cout << "|                     �����������úͻ�ȡ����                   |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");

  string city;
  link_list->GetData(2, city);
  cout << city << endl;

  link_list->SetData(2, "Shenzhen");

  link_list->Output();


  cout << "-------------------------------------------------------------" << endl << endl;
}

#endif // CYBER_DASH_LINK_LIST_TEST_H
