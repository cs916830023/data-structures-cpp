
#define FALSE   0   //!< �߼���
#define TRUE    1   //!< �߼���

#define NUM_0_ASCII_CODE 48 //!< �ַ�'0'��ASC��
#define NUM_1_ASCII_CODE 49 //!< �ַ�'1'��ASC��

#define MAX_DIGIT_NUMBER 8                  //!< �ؼ������������ֵ

int BUCKETS[10];

template <typename info_t, typename DIGIT_TYPE>
struct static_linked_list_node_t {
    DIGIT_TYPE key[MAX_DIGIT_NUMBER];   //!< �ؼ���
    info_t info;                        //!< ����������
    int next;                           //!< ��һ��������
}; 


template <typename info_t, typename DIGIT_TYPE>
struct radix_static_linked_list_t {
    static_linked_list_node_t elements[100];    //!< Ԫ�صľ�̬����, elements[0]Ϊͷ���(������Ԫ��)
    int number_of_digit;    //!< �����ؼ��ָ���
    int length;             //!< ��̬������
};


template <typename info_t, typename DIGIT_TYPE>
void DistributeIntoBuckets(radix_static_linked_list_t<info_t, DIGIT_TYPE>* static_linked_list,
                           int place_of_digit,
                           int* digit_bucket_heads,
                           int* digit_bucket_tails)
{
    /// ### 1 ������Ͱ(����)��ʼ��Ϊ�� ###
    /// &emsp; **for loop** ����������λ :\n
    /// &emsp;&emsp; ����Ͱ����Ԫ������(��ͷ����)��������Ϊ0\n
    /// &emsp;&emsp; ����Ͱ��βԪ������(��β����)��������Ϊ0\n
    for (int j = 0; j < RADIX_10; j++) {
        digit_bucket_heads[j] = 0;
        digit_bucket_tails[j] = 0;
	}

    /// ### 2 ����λ��Ԫ�������е�����###
    int place_index = static_linked_list->number_of_digit - place_of_digit;

    /// ### 3 ������̬����, ִ�з��� ###
    static_linked_list_node_t* elements = static_linked_list->elements;
    /// &emsp; **for loop** ������̬�����Ԫ�� :\n
	for (int i = elements[0].next; i != 0; i = elements[i].next) {

        /// &emsp;&emsp; ȡ��i��Ԫ��, ��λplace_of_digit����λֵ\n
        int place_value = ord(static_linked_list->elements[i].key, place_index);

        /// &emsp;&emsp; **if** ����λ��Ӧ��Ͱ(����)Ϊ�� :\n
        if (!digit_bucket_heads[place_value]) {
            /// &emsp;&emsp;&emsp; ����λ����������place_index���(��Ͱ)\n
            digit_bucket_heads[place_value] = i;
        } else {    /// &emsp;&emsp; **else** (�������λ��Ӧ��Ͱ(����)��Ϊ��\n
            /// &emsp;&emsp;&emsp; ��βԪ�ص�next, ָ��place_index(�������β)\n
            elements[digit_bucket_tails[place_value]].next = i;
        }

        /// &emsp;&emsp; ���¸���λ��β����Ԫ��ֵ\n
        digit_bucket_tails[place_value] = i;
	}
}


/*!
 * ���������ռ�Ͱ
 * @param elements **��̬����Ԫ������**
 * @param digit_bucket_heads **����Ͱ����Ԫ������**(��ͷ����)
 * @param digit_bucket_tails **����Ͱ��βԪ������**(��β����)
 * @note
 * ���������ռ�Ͱ
 * ------------
 * ------------
 * digit��С����, ��digit_queue_heads[0 ... 9]��ָ��Ͱ, �������ӳ�һ������
 */
template <typename info_t, typename DIGIT_TYPE>
void CollectBuckets(static_linked_list_node_t<info_t, DIGIT_TYPE>* elements,
                    int* digit_bucket_heads,
                    int* digit_bucket_tails)
{

    /// ### 1 �ҵ���һ���ǿ�Ͱ(����) ###
    /// &emsp; ����digit_bucket_heads, �ҵ���һ���ǿ�Ͱ\n
    int place_value = 0;
    while (digit_bucket_heads[place_value] == 0) {
        place_value++;
    }

    /// &emsp; elements[0].nextָ���һ���ǿ�Ͱ���׽��(��һ���ǿն��еĶ�ͷ)\n
    elements[0].next = digit_bucket_heads[place_value];
    /// &emsp; ����digit_bucket_tail���浱ǰ�ǿ�Ͱ�����1��Ԫ��
    int digit_bucket_tail = digit_bucket_tails[place_value];

    /// ### 2 ִ��Ͱ�ռ� ###
    /// &emsp; **for loop** ��λ��0��9 :\n
    while (place_value < 10) {

        /// &emsp;&emsp; Ѱ����һ���ǿ�Ͱ\n
        place_value++;
        while (place_value < RADIX_10 && digit_bucket_heads[place_value] == 0) {
            place_value++;
        }

        /// &emsp;&emsp; **if** �Ҳ����ǿ�Ͱ : \n
        /// &emsp;&emsp;&emsp; �˳�
        if (place_value == RADIX_10) {
            break;
        }

        /// &emsp;&emsp; ǰһ�ǿ�Ͱ�����һ��Ԫ��(��βԪ��)elements[digit_bucket_tail]��next, ָ��ǰ��λ��Ӧ�ķǿ�Ͱ���׸�Ԫ�ص�����(��ͷ)
        elements[digit_bucket_tail].next = digit_bucket_heads[place_value];
        /// &emsp;&emsp; ����digit_bucket_tailֵΪ��ǰ�ǿ�Ͱ�����һ��Ԫ�ص�����(��β);
        digit_bucket_tail = digit_bucket_tails[place_value];
    }

    /// &emsp; ���һ���ǿ�Ͱ�����һ��Ԫ��(��βԪ��)��nextָ��0
    elements[digit_bucket_tail].next = 0;
}


/*!
 * <h1>��������</h1>
 * @param static_linked_list **������̬����**
 * @note
 */
template <typename info_t, typename DIGIT_TYPE>
void RadixSort(radix_static_linked_list_t<info_t, DIGIT_TYPE>* static_linked_list) {
    int digit_queue_heads[10];  // �������ж�ͷ����
    int digit_queue_tails[10];  // �������ж�β����

    /// ### 1 ��ʼ��static_linked_list��Ԫ�ص�next ###
    /// &emsp; **for loop** ������̬����, ������Χ[ 1 ... (length - 1) ] : \n
    for (int i = 0; i < static_linked_list->length; ++i) {
        /// &emsp;&emsp; ����iԪ�ص�next, ����Ϊi + 1 \n
        static_linked_list->elements[i].next = i + 1;
    }

    /// &emsp; ����lengthԪ�ص�next, ����Ϊ0(����ѭ����̬����)
    static_linked_list->elements[static_linked_list->length].next = 0; // ���һ��Ԫ�ص�nextָ��0

    /// ### 2 �����λ����(�Ҳ��λ��ʼ), ���ζԸ���λ���з�Ͱ���ռ� ###
    /// &emsp; **for loop** ���Ҳ࿪ʼ, ��������λ :\n
    for (int i = 1; i <= static_linked_list->number_of_digit; i++) {

        /// &emsp;&emsp; �Ҳ��iλ��Ϊ����, ���з�Ͱ \n
        DistributeIntoBuckets(static_linked_list, i, digit_queue_heads, digit_queue_tails);

        /// &emsp;&emsp; �Է����Ͱ, �����ռ�
        CollectBuckets(static_linked_list->elements, digit_queue_heads, digit_queue_tails);
    }
}
