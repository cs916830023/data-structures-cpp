/*!
 * @file insert_sort.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��������
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "util.h"


/*!
 * @brief ��������
 * @param arr ����
 * @param size ���鳤��
 */
void InsertSort(int* arr, int size) {

    for (int i = 1; i < size; i++) {

        int cur_idx = i;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[cur_idx]) {
              Swap(arr + i, arr + j);
                cur_idx = j;
            } else {
                break;
            }   
        }   
    }   
}
