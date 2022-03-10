/*!
 * @file seq_list_algorithm.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ˳����㷨������
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_SEQ_LIST_ALGORITHM_H
#define CYBER_DASH_SEQ_LIST_ALGORITHM_H


#include "seq_list.h"


/*!
 * @brief ˳����󲢼�
 * @tparam T ����ģ�����
 * @param seq_list_a ˳���a(�������ı�)
 * @param seq_list_b ˳���b
 * @note
 * ����˳���b, ��ÿ��Ԫ��, ����ڱ�a�в�����, ����뵽��a��
 */
template<class T>
void SeqListUnion(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {
  int a_length = seq_list_a.Length();
  int b_length = seq_list_b.Length();

  for (int i = 1; i <= b_length; i++) {

    int list_b_item;
    seq_list_b.GetData(i, list_b_item);

    int pos = seq_list_a.Search(list_b_item);
    if (pos == 0) {
      seq_list_a.Insert(a_length, list_b_item);
      a_length++;
    }
  }
}


/*!
 * @brief ˳����󽻼�
 * @tparam T ����ģ�����
 * @param seq_list_a ˳���a(�������ı�)
 * @param seq_list_b ˳���b
 */
template<class T>
void SeqListIntersection(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {

  int a_length = seq_list_a.Length();

  int iter_pos = 1;
  while (iter_pos <= a_length) {
    int list_a_item;
    seq_list_a.GetData(iter_pos, list_a_item);

    int pos = seq_list_b.Search(list_a_item);
    if (pos == 0) {
      seq_list_a.Remove(iter_pos, list_a_item);
      a_length--;
    } else {
      iter_pos++;
    }
  }
}


#endif // CYBER_DASH_SEQ_LIST_ALGORITHM_H
