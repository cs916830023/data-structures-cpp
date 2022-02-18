/*!
 * @file util.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ����.cpp�ļ�
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include <iostream>


using namespace std;


void Swap(int *a, int *b) {

    if (*a == *b) {
        return;
    }

    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int* min_by_ptr(int *ptr1, int *ptr2) {

    if (*ptr1 <= *ptr2) {
        return ptr1;
    } else {
        return ptr2;
    }
}


void PrintArray(int *arr, int array_size) {

  for (int i = 0; i < array_size; i++) {
    cout<<arr[i]<<" ";
  }

  cout<<endl;
}


void CyberDashShow() {
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
