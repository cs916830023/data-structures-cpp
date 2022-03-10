/*!
 * @file quick_sort.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��������
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "util.h"


/*!
 * @brief ���ֺ���
 * @param arr ����
 * @param left ��߽�
 * @param right �ұ߽�
 * @return ��
 */
int Split(int* arr, int left, int right) {

    int pivot = left;

    while (left <= right) {

        for (; right >= pivot; right--) {
            if (arr[pivot] > arr[right]) {
              Swap(arr + pivot, arr + right);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }

        for (; left <= pivot; left++) {
            if (arr[pivot] < arr[left]) {
              Swap(arr + left, arr + pivot);
                right = pivot - 1;
                pivot = left;
                break;
            }
        }
    }

    return pivot;
}


/*!
 * @brief ��������(�ݹ�)
 * @param arr ����
 * @param left ��߽�
 * @param right �ұ߽�
 */
void QuickSort(int *arr, int left, int right) {

  if (left >= right) {
    return;
  }

  int pivot = Split(arr, left, right);

  QuickSort(arr, left, pivot - 1);
  QuickSort(arr, pivot + 1, right);
}


