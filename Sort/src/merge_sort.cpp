/*!
 * @file merge_sort.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �鲢����
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */


/*!
 * @brief �ϲ�����
 * @param array ���ϲ�����(��������������)
 * @param cache_array ��������
 * @param left �����������
 * @param mid ���������Ҳ�
 * @param right ���������Ҳ�
 * @note
 * array�ڵ�������������(�����������������,��left/mid/right����), �ϲ���Ϊһ����������
 */
void Merge(int* array, int* cache_array, int left, int mid, int right) {

  for (int i = left; i <= right; i++) {
    cache_array[i] = array[i];
  }

  int left_cache_index = left;
  int right_cache_index = mid + 1;

  int array_index = left;

  while (left_cache_index <= mid && right_cache_index <= right) {

    if (cache_array[left_cache_index] <= cache_array[right_cache_index]) {
      array[array_index] = cache_array[left_cache_index];
      left_cache_index++;
    } else {
      array[array_index] = cache_array[right_cache_index];
      right_cache_index++;
    }

    array_index++;
  }

  while (left_cache_index <= mid) {
    array[array_index] = cache_array[left_cache_index];
    left_cache_index++;
    array_index++;
  }

  while (right_cache_index <= right) {
    array[array_index] = cache_array[right_cache_index];
    right_cache_index++;
    array_index++;
  }
}


/**
 * @brief ������鲢����(�ݹ�/����)
 * @param array ����������
 * @param cache_array ��������(���ڸ����鲢����)
 * @param left ������������߽�
 * @param right �����������ұ߽�
 * @note
 * ʹ�ô�������������ұ߽�, �ͻ�������.
 * ʹ�ö��ַ��η�, �ֱ����������������(sub array)ִ�еݹ�, ���ݹ�����������������ִ��merge
 */
void SubArrayMergeSortRecursive(int* array, int* cache_array, int left, int right) {

  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2; // ʹ��mid��������������

  SubArrayMergeSortRecursive(array, cache_array, left, mid); // ���������ݹ�
  SubArrayMergeSortRecursive(array, cache_array, mid + 1, right); // �Ҳ�������ݹ�

  Merge(array, cache_array, left, mid, right);
}


/**
 * @brief �鲢����(ʹ�õݹ�/����)
 * @param array ����
 * @param arr_size ���鳤��
 * @note
 * ����sub_array_merge_sort_recursiveʵ�ֹ鲢����
 */
void MergeSort(int* array, int size) {

  int* cache_array = new int[size];

  int left = 0;
  int right = size - 1;

  SubArrayMergeSortRecursive(array, cache_array, left, right);
}


int GetNextTurnArrayCount(int array_count) {

  int rem = array_count % 2;
  int next_turn_array_count;

  if (rem == 0) {
    next_turn_array_count = array_count / 2;
  } else {
    next_turn_array_count = array_count / 2 + 1;
  }

  return next_turn_array_count;
}


/*!
 * @brief �鲢����(�ǵݹ�/����)
 * @param array ����
 * @param size ���鳤��
 */
void MergeSortNonRecursive(int* array, int size) {

  int* cache_array = new int[size];

  int merge_array_length = 1;
  int sub_array_count = size;

  do {
    int merge_count = sub_array_count / 2;

    for (int i = 0; i < merge_count; i++) {
      int left = 2 * i * merge_array_length;
      int mid = (2 * i + 1) * merge_array_length - 1;
      int right;

      if ((2 * i + 2) * merge_array_length - 1 > size - 1) {
        right = size - 1;
      } else {
        right = (2 * i + 2) * merge_array_length - 1;
      }

      Merge(array, cache_array, left, mid, right);
    }

    sub_array_count = GetNextTurnArrayCount(sub_array_count);

    merge_array_length = merge_array_length * 2;

  } while (sub_array_count != 1);
}