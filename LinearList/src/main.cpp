//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/15.
//

#include "link_list_test.h"
#include "seq_list_test.h"
#include "double_link_list_test.h"


using namespace std;


int main() {

  /*
  SeqListTest::TestInsert();

  SeqListTest::TestSize();

  SeqListTest::TestEmpty();

  SeqListTest::TestLength();

  SeqListTest::TestSearch();

  SeqListTest::TestLocate();

  SeqListTest::TestGetData();

  SeqListTest::TestSetData();

  SeqListTest::TestSort();

  SeqListTest::TestUnion();

  SeqListTest::TestIntersection();
  */

  DoubleLinkListTest::TestInsertByDirection();

  DoubleLinkListTest::TestRemoveByDirection();

  DoubleLinkListTest::TestLength();

  DoubleLinkListTest::TestLocate();

  DoubleLinkListTest::TestEmpty();

  DoubleLinkListTest::TestSearch();

  DoubleLinkListTest::TestGetDataAndSetData();


  LinkListTest::TestCopyConstructor();

  LinkListTest::TestRemove();

  LinkListTest::TestMakeEmpty();

  LinkListTest::TestLocate();

  LinkListTest::TestGetDataAndSetData();

  return 0;
}
