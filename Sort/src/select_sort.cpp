/*!
 * @file select_sort.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ѡ������
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "util.h"


/*!
 * @brief ѡ������
 * @param arr ����
 * @param size ���鳤��
 */
void SelectSort(int* arr, int size) {

    for (int i = 0; i < size; i++) {

        int select_idx = i;
        int select_value = arr[select_idx];

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < select_value) {
                select_idx = j;
                select_value = arr[j];
            }
        }

      Swap(arr + i, arr + select_idx);
    }
}