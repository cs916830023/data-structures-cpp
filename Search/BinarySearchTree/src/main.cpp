//
// Created by cyberdash@163.com on 2021/6/26.
//

#include "test.h"


using namespace std;


int main()
{
  /* ���� */
  TestBSTInsert();
  TestAVLInsert2();
  TestAVLInsertByCyberDash();

  /* ɾ�� */
  TestBSTRemove();
  TestAVLRemoveByCyberDash();

  /* ��ѯ */
  TestBSTSearch();
  TestAVLSearch();

  /* �߶� */
  TestBSTAndAVLHeight();

  /* �����Сֵ */
  TestBSTMaxAndMin();
  TestAVLMaxAndMin();

  /* ����������� */
  TestBSTMakeEmpty();

  return 0;
}
