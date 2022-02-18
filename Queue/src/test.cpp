/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ���в���.cpp�ļ�
 * @version 0.2.1
 * @date 2021-10-9
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"
#include "link_queue.h"


void TestGetSize() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test Queue GetSize                     |"<<endl;
  cout<<"|                        ���Զ���Size                        |"<<endl<<endl<<endl;

  LinkQueue<string> old_memory_queue;

  string old_memory[12] = {
      "���������¹�̫�Ի�", "ȴ��������һ�߳�Ц��",
      "����������˸�����Į", "�Ҹÿ�ʼΪ�Լ�����",

      "����ѳ��صĹ�ȥ����", "�뿪���������簮����",
      "�뿪���벻�����ų��", "������ǰ����һ������",

      "���ڰ���ʹ�Ĺ�ȥ����", "�뿪�Լ�������ٶԴ�",
      "���Ƿɶ�û�ʸ��˻�", "�˵��˵���������ʱ��"
  };

  for (int i = 0; i < 12; i++) {
    cout<<"Old memory enqueue: "<<old_memory[i]<<endl;
    old_memory_queue.EnQueue(old_memory[i]);
  }

  cout<<endl<<"Old memory queue size: "<<old_memory_queue.GetSize()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestEnQueue() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test Queue Enqueue                     |"<<endl;
  cout<<"|                        ���Զ������                         |"<<endl<<endl<<endl;

  LinkQueue<int> int_queue;

  cout<<"Enqueue 4 integers."<<endl<<endl;

  int_queue.EnQueue(1);
  int_queue.EnQueue(2);
  int_queue.EnQueue(3);
  int_queue.EnQueue(4);

  cout << int_queue;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestDeQueue() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test Queue Dequeue                     |"<<endl;
  cout<<"|                        ���Զ��г���                         |"<<endl<<endl<<endl;

  LinkQueue<double> double_queue;

  cout<<"double_queue enqueue 4 numbers."<<endl;

  double_queue.EnQueue(1.1);
  double_queue.EnQueue(2.2);
  double_queue.EnQueue(3.3);
  double_queue.EnQueue(4.4);

  cout << double_queue << endl;

  cout<<"double_queue dequeue."<<endl<<endl;

  double frontData;
  double_queue.DeQueue(frontData);

  cout << double_queue;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestGetFrontAndGetRear() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                Test Queue GetFront & GetRear              |"<<endl;
  cout<<"|                   ���Զ��л�ȡ��ͷ/��ȡ��β                   |"<<endl<<endl<<endl;

  LinkQueue<string> string_queue;

  string_queue.EnQueue("���ҵ�");
  string_queue.EnQueue("������");
  string_queue.EnQueue("�����");
  string_queue.EnQueue("ʲô��Ҫ���ҵ�");
  string_queue.EnQueue("�ֹ���û��");
  string_queue.EnQueue("�Ҳ�Ҫ�����");
  string_queue.EnQueue("��Ҫ�Ҿ���");

  string front_data;
  string rear_data;

  string_queue.GetFront(front_data);
  string_queue.GetRear(rear_data);
  cout<<"The front of the queue: "<<front_data<<endl;
  cout<<"The rear of the queue: "<<rear_data<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestIsEmpty() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test Queue MakeEmpty                    |"<<endl;
  cout<<"|                        ������ն���                         |"<<endl<<endl<<endl;
  LinkQueue<string> LinkinPark_song_queue;

  LinkinPark_song_queue.EnQueue("<In the end>");
  LinkinPark_song_queue.EnQueue("<Crawling>");
  LinkinPark_song_queue.EnQueue("<One more light>");

  bool is_empty = LinkinPark_song_queue.IsEmpty();
  if (is_empty) {
    cout<<"LinkinPark_song_queue is empty."<<endl;
  } else {
    cout<<"LinkinPark_song_queue isn't empty."<<endl;
  }

  cout<<endl<<"call function MakeEmpty."<<endl<<endl;

  LinkinPark_song_queue.MakeEmpty();

  is_empty = LinkinPark_song_queue.IsEmpty();
  if (is_empty) {
    cout<<"LinkinPark_song_queue is empty."<<endl;
  } else {
    cout<<"LinkinPark_song_queue isn't empty."<<endl;
  }

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestOperatorCout() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Operator <<                     |"<<endl;
  cout<<"|                      ���Զ���operator<<                    |"<<endl<<endl<<endl;

  LinkQueue<string> string_queue;

  string_queue.EnQueue("���ҵ�");
  string_queue.EnQueue("������");
  string_queue.EnQueue("�����");
  string_queue.EnQueue("ʲô��Ҫ���ҵ�");
  string_queue.EnQueue("�ֹ���û��");
  string_queue.EnQueue("�Ҳ�Ҫ�����");
  string_queue.EnQueue("��Ҫ�Ҿ���");

  cout<<string_queue;
}
