//
// Created by cyberdash@163.com on 2021/6/26.
//


#include "test.h"
#include "vector"


void BSTNodeVisit(BSTNode<string, string>* node_ptr) {
  cout<<"["<<node_ptr->GetKey()<<":"<<node_ptr->GetData()<<"]";
}


void AVLNodeVisit(AVLNode<string, string>* node_ptr) {
  cout<<"["<<node_ptr->GetKey()<<":"<<node_ptr->GetData()<<"]";
}


void TestOperatorEqual() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                       Test Operator=                      |"<<endl;
  cout<<"|                     ��������������=����                     |"<<endl;

  // BST<string, string>* origin_search_tree_ptr = new BST<string, string>();
  BST<string, string> origin_search_tree_ptr;

  string question1 = "������ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�������Ϸ";
  string answer2 = "Dota2";

  string question3 = "����ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  // origin_search_tree_ptr->Insert(answer1, question1);
  origin_search_tree_ptr.Insert(answer1, question1);
  // origin_search_tree_ptr->Insert(answer2, question2);
  origin_search_tree_ptr.Insert(answer2, question2);
  // origin_search_tree_ptr->Insert(answer3, question3);
  origin_search_tree_ptr.Insert(answer3, question3);

  // BST<string, string> new_BST = *origin_search_tree_ptr;
  BST<string, string> new_BST = origin_search_tree_ptr;

  // todo: use following
  /*
  BST<string, string> origin_search_tree;

  string question1 = "������ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�������Ϸ";
  string answer2 = "Dota2";

  string question3 = "����ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  origin_search_tree.Insert(answer1, question1);
  origin_search_tree.Insert(answer2, question2);
  origin_search_tree.Insert(answer3, question3);

  BST<string, string> new_BST = origin_search_tree;
   */

  new_BST.PrintTree(BSTNodeVisit);

  cout<<endl<<"-------------------------------------------------------------"<<endl;
}


void TestBSTInsert() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Insert                      |"<<endl;
  cout<<"|                     ���������������Ĳ���                     |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "������ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�������Ϸ";
  string answer2 = "Dota2";

  string question3 = "����ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);

  binary_search_tree->PrintTree(BSTNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTRemove() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Remove                      |"<<endl;
  cout<<"|                     ����������������ɾ��                     |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);
  binary_search_tree->Insert(answer4, question4);
  binary_search_tree->Insert(answer5, question5);
  binary_search_tree->Insert(answer6, question6);
  binary_search_tree->Insert(answer7, question7);
  binary_search_tree->Insert(answer8, question8);

  binary_search_tree->PrintTree(BSTNodeVisit);

  cout<<endl;

  binary_search_tree->Remove(question1);

  binary_search_tree->PrintTree(BSTNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Search                      |"<<endl;
  cout<<"|                     ����������������ɾ��                     |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "�õ�������Ҳ����˵��";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);
  binary_search_tree->Insert(answer4, question4);
  binary_search_tree->Insert(answer5, question5);
  binary_search_tree->Insert(answer6, question6);
  binary_search_tree->Insert(answer7, question7);
  binary_search_tree->Insert(answer8, question8);
  binary_search_tree->Insert(answer9, question9);

  binary_search_tree->Remove(question9);

  BSTNode<string, string>* the_9th_node = binary_search_tree->Search(question9);
  if (the_9th_node == NULL) { // û��������
    // cout<<"question9: "<<question9<<endl<<"answer9: "<<"Duck����"<<endl;
    cout<<"��������ɾ��"<<endl;
  } else { // ������
    cout<<"question9: "<<the_9th_node->GetKey()<<endl<<"answer9: "<<the_9th_node->GetData()<<endl;
  }

  cout<<endl;

  BSTNode<string, string>* the_8th_node = binary_search_tree->Search(question8);
  if (the_8th_node == NULL) { // û��������
    cout<<"Duck����"<<endl;
  } else { // ������
    cout<<"question8: "<<the_8th_node->GetKey()<<endl<<"answer8: "<<the_8th_node->GetData()<<endl;
  }

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test AVL Search                      |"<<endl;
  cout<<"|                       ����AVL����ɾ��                       |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "�õ�������Ҳ����˵��";

  AVL_tree->Insert(answer1, question1);
  AVL_tree->Insert(answer2, question2);
  AVL_tree->Insert(answer3, question3);
  AVL_tree->Insert(answer4, question4);
  AVL_tree->Insert(answer5, question5);
  AVL_tree->Insert(answer6, question6);
  AVL_tree->Insert(answer7, question7);
  AVL_tree->Insert(answer8, question8);
  AVL_tree->Insert(answer9, question9);

  AVL_tree->RemoveByCyberDash(question9);

  AVLNode<string, string>* the_9th_node = AVL_tree->Search(question9);
  if (the_9th_node == NULL) { // û��������
    // cout<<"question9: "<<question9<<endl<<"answer9: "<<"Duck����"<<endl;
    cout<<"��������ɾ��"<<endl;
  } else { // ������
    cout<<"question9: "<<the_9th_node->GetKey()<<endl<<"answer9: "<<the_9th_node->GetData()<<endl;
  }

  cout<<endl;

  AVLNode<string, string>* the_8th_node = AVL_tree->Search(question8);
  if (the_8th_node == NULL) { // û��������
    cout<<"Duck����"<<endl;
  } else { // ������
    cout<<"question8: "<<the_8th_node->GetKey()<<endl<<"answer8: "<<the_8th_node->GetData()<<endl;
  }

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTMaxAndMin() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test BST Max and Min                   |"<<endl;
  cout<<"|                  �������������������ֵ/��Сֵ                 |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "��Щ�޷����ݵ�ʹ, �����ù�";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);
  binary_search_tree->Insert(answer4, question4);
  binary_search_tree->Insert(answer5, question5);
  binary_search_tree->Insert(answer6, question6);
  binary_search_tree->Insert(answer7, question7);
  binary_search_tree->Insert(answer8, question8);
  binary_search_tree->Insert(answer9, question9);

  string max_data = binary_search_tree->Max();
  cout << "max_data: " << max_data << endl;

  string min_data = binary_search_tree->Min();
  cout<<"min_data: "<<min_data<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLMaxAndMin() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                     Test AVL Max & Min                    |"<<endl;
  cout<<"|                    ����AVL�������ֵ/��Сֵ                  |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "��Щ�޷����ݵ�ʹ, �����ù�";

  AVL_tree->Insert(answer1, question1);
  AVL_tree->Insert(answer2, question2);
  AVL_tree->Insert(answer3, question3);
  AVL_tree->Insert(answer4, question4);
  AVL_tree->Insert(answer5, question5);
  AVL_tree->Insert(answer6, question6);
  AVL_tree->Insert(answer7, question7);
  AVL_tree->Insert(answer8, question8);
  AVL_tree->Insert(answer9, question9);

  string max_data = AVL_tree->Max();
  cout<<"max_data: "<<max_data<<endl;

  string min_data = AVL_tree->Min();
  cout<<"min_data: "<<min_data<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTMin() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test BST Min                       |"<<endl;
  cout<<"|                     ������������������Сֵ                    |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "��Щ�޷����ݵ�ʹ, �����ù�";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);
  binary_search_tree->Insert(answer4, question4);
  binary_search_tree->Insert(answer5, question5);
  binary_search_tree->Insert(answer6, question6);
  binary_search_tree->Insert(answer7, question7);
  binary_search_tree->Insert(answer8, question8);
  binary_search_tree->Insert(answer9, question9);

  string minData = binary_search_tree->Min();

  cout<<"minData: "<<minData<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTMakeEmpty() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                     Test BST MakeEmpty                    |"<<endl;
  cout<<"|                      ����������������ɾ��                    |"<<endl;

  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "����ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�����Ϸ";
  string answer2 = "Dota2";

  string question3 = "��ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  string question5 = "������ı������";
  string answer5 = "Java";

  string question6 = "��������������";
  string answer6 = "������ѧ��";

  string question7 = "�Ƽ����׸���";
  string answer7 = "Learning To Survive|Final Masquerade|Nothing";

  string question8 = "������˵�仰";
  string answer8 = "����һ��Ҫ���������, ����ֻ����ĥ";

  string question9 = "��һ����ڵ��¶�";
  string answer9 = "�õ�������Ҳ����˵��";

  binary_search_tree->Insert(answer1, question1);
  binary_search_tree->Insert(answer2, question2);
  binary_search_tree->Insert(answer3, question3);
  binary_search_tree->Insert(answer4, question4);
  binary_search_tree->Insert(answer5, question5);
  binary_search_tree->Insert(answer6, question6);
  binary_search_tree->Insert(answer7, question7);
  binary_search_tree->Insert(answer8, question8);
  binary_search_tree->Insert(answer9, question9);

  binary_search_tree->MakeEmpty();

  binary_search_tree->PrintTree(BSTNodeVisit);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLInsert() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test AVL Insert                      |"<<endl;
  cout<<"|                     ����ƽ��������Ĳ���                     |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string question1 = "������ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�������Ϸ";
  string answer2 = "Dota2";

  string question3 = "����ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  AVL_tree->Insert(answer1, question1);
  AVL_tree->Insert(answer2, question2);
  AVL_tree->Insert(answer3, question3);
  AVL_tree->Insert(answer4, question4);

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLInsert2() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                     Test AVL Insert2                      |"<<endl;
  cout<<"|                    ����ƽ��������Ĳ���2                     |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string question1 = "a";
  string answer1 = "a";

  string question2 = "d";
  string answer2 = "d";

  string question3 = "c";
  string answer3 = "c";

  string question4 = "b";
  string answer4 = "b";

  AVL_tree->InsertByCyberDash(answer1, question1);
  AVL_tree->InsertByCyberDash(answer2, question2);
  AVL_tree->InsertByCyberDash(answer3, question3);
  AVL_tree->InsertByCyberDash(answer4, question4);

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLInsertByCyberDash() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test AVL InsertByCyberDash                |"<<endl;
  cout<<"|               ����ƽ��������Ĳ���(CyberDash�汾)            |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string question1 = "������ֶ�";
  string answer1 = "�ֿϹ�԰";

  string question2 = "�������Ϸ";
  string answer2 = "Dota2";

  string question3 = "����ĵ�Ӱ";
  string answer3 = "���ڿ͵۹���";

  string question4 = "����˶�";
  string answer4 = "����";

  AVL_tree->InsertByCyberDash(answer1, question1);
  AVL_tree->InsertByCyberDash(answer2, question2);
  AVL_tree->InsertByCyberDash(answer3, question3);
  AVL_tree->InsertByCyberDash(answer4, question4);

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLRemoveByCyberDash() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test AVL RemoveByCyberDash                |"<<endl;
  cout<<"|               ����ƽ���������ɾ��(CyberDash�汾)             |"<<endl;

  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  string keyArr[19] =
    { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s" };
  string elemArr[19] =
    { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s" };

  for (int i = 0; i < 19; i++) {
    AVL_tree->InsertByCyberDash(keyArr[i], elemArr[i]);
  }

  AVL_tree->PrintTree(AVLNodeVisit);

  AVL_tree->RemoveByCyberDash("p");

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTAndAVLHeight() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BST & AVL Height                   |"<<endl;
  cout<<"|                  ��������������/AVL���ĸ߶�                  |"<<endl;

  string keyArr[19] =
    { "a", "d", "c", "b", "e", "f", "g", "h", "i", "k", "l", "j", "m", "n", "r", "p", "q", "o", "s" };
  string elemArr[19] =
    { "a", "d", "c", "b", "e", "f", "g", "h", "i", "k", "l", "j", "m", "n", "r", "p", "q", "o", "s" };

  cout<<"�ֱ���BST��AVL������:"<<endl;
  for (int i = 0; i < 19; i++) {
    cout<<"\"key:"<<keyArr[i]<<"/elem:"<<elemArr[i]<<"\"  ";
    // �ĸ�һ��
    if (i % 4 == 3 && i != 0) {
      cout<<endl;
    }
  }

  BST<string, string>* bst_tree = new BST<string, string>();
  AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

  for (int i = 0; i < 19; i++) {
    bst_tree->Insert(keyArr[i], elemArr[i]);
  }

  for (int i = 0; i < 19; i++) {
    AVL_tree->InsertByCyberDash(keyArr[i], elemArr[i]);
  }

  cout<<endl<<endl;

  cout<<"BST���߶�: "<<bst_tree->Height()<<endl;
  cout<<"AVL���߶�: "<<AVL_tree->Height()<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}
