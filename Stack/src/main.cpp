/*!
 * @file main.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ջdemo��ʾ
 * @version 0.2.1
 * @date 2020-07-15
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include <iostream>
#include "link_stack.h"


using namespace std;


int main() {

  LinkStack<int> test_stack;

  // ���� int ���͵�ջ
  test_stack.Push(1);
  test_stack.Push(2);
  test_stack.Push(3);
  test_stack.Push(4);

  // test GetTop
  int top_data;
  test_stack.GetTop(top_data);
  cout<<"top_data: "<<top_data<<endl;

  // test operator<<
  cout<<test_stack<<endl;

  // test Pop
  int pop_data;
  test_stack.Pop(pop_data);
  test_stack.Pop(pop_data);
  test_stack.Pop(pop_data);
  cout<<test_stack<<endl;

  test_stack.Pop(pop_data);
  cout<<test_stack<<endl;

  // test CyberDashShow
  test_stack.CyberDashShow();

  return 0;
}