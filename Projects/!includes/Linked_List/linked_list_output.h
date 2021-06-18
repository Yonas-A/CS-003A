#ifndef LINKED_LIST_OUTPUT_H
#define LINKED_LIST_OUTPUT_H

/*
=====================================================================
        test output for individual functions from Linked_List.h
=====================================================================

     ========== Test _at() ==========

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
------- test 1: pos = 4 ---------
Node @ 4 = [0]

List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
------- test 2: pos = -5 ---------
Since pos is invalid, assert must terminate program

Assertion failed: (head_ptr != nullptr && position >= 0),
function _at,
file ../../../Dropbox/CS/Projects/12 Iterated_List/
        Iterated_List/../!includes/List_Functions/list_functions.h,
line 161.

=====================================================================
=====================================================================

    ========== Test _beginning() ==========

List :
       H->|||
       - - - - - - - - - - - - - - - -
------- test 1: empty list  ---------
List is empty
Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
------- test 2: 5 items in the list  ---------
Beginning node is [40]

   ========= end of Test _beginning ==========

=====================================================================
=====================================================================
    ========== Test _clear_list() ==========

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
List  after _clear_list():
       H->|||
       - - - - - - - - - - - - - - - -
   ======= end of Test _clear_list() =======

=====================================================================
=====================================================================

    ========== Test _copy_list() ==========

Inserting 5 items
src List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Dest List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -

-----Checking uniquness of two lists------
Src list after insert_last(100):
       H->[40]->[30]->[20]->[10]->[0]->[200]->|||
       - - - - - - - - - - - - - - - -
Dest list after insert_last(67):
       H->[40]->[30]->[20]->[10]->[0]->[200]->|||
       - - - - - - - - - - - - - - - -
Src_end = : [100]
Dest_edn = : [200]
   ========== end of test _copy_list() ==========

=====================================================================
=====================================================================
    ========== Test _end() ==========

------- test 1: empty list  ---------
List :
       H->|||
       - - - - - - - - - - - - - - - -
List is empty

------- test 2: 5 items in the list  ---------
Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
End node is [0]

    ========== end of Test _end() ==========

=====================================================================
=====================================================================

    ========== Test _empty() ==========

------- test 1: empty list  ---------
List :
       H->|||
       - - - - - - - - - - - - - - - -
List is empty

Inserting 5 items
------- test 2: 5 items in the list  ---------

List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
List is not empty

    ========== end of Test _empty() ==========

=====================================================================
=====================================================================

    ========== Test _insert_after() ==========

--- test 1: Insert 120 after empty list ---

List :
       H->|||
       - - - - - - - - - - - - - - - -
Inserted node: = [120]
List after insert_after():
       H->[120]->|||
       - - - - - - - - - - - - - - - -
Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->[120]->|||
       - - - - - - - - - - - - - - - -
--- test 2: Insert 12 after [120]---

Inserted node: = [12]
List after insert_after():
       H->[40]->[30]->[20]->[10]->[0]->[120]->[12]->|||
       - - - - - - - - - - - - - - - -
--- test 3: Insert 123 after [20]---

Inserted node: = [123]
List after insert_after():
       H->[40]->[30]->[20]->[123]->[10]->[0]->[120]->[12]->|||
       - - - - - - - - - - - - - - - -
--- test 4: Insert 1400 after NULL -----

After the next line assert from _insert_after() must stop program

Assertion failed: (mark != nullptr),
function _insert_after,
file ../../../Dropbox/CS/Projects/12 Iterated_List/Iterated_List/
                        ../!includes/List_Functions/list_functions.h,
line 354.


=====================================================================
=====================================================================
    ========== Test _insert_before() ==========

--- test 1: Insert 120 before empty list ---

List :
       H->|||
       - - - - - - - - - - - - - - - -
Inserted node: = [120]
List after insert_before():
       H->[120]->|||
       - - - - - - - - - - - - - - - -
Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->[120]->|||
       - - - - - - - - - - - - - - - -
--- test 2: Insert 360 before [0]---

Inserted node: = [360]
List after insert_before():
       H->[40]->[30]->[20]->[10]->[360]->[0]->[120]->|||
       - - - - - - - - - - - - - - - -
--- test 3: Insert 720 before [40]---

List :
       H->[720]->[40]->[30]->[20]->[10]->[360]->[0]->[120]->|||
       - - - - - - - - - - - - - - - -
--- test 4: Insert 24 before [70]---

After this assert from _previous_node() must
terminate program since iMarker is not in the list
Assertion failed: (walker != nullptr && iMarker != nullptr),
function _previous_node,
file ../../../Dropbox/CS/Projects/12 Iterated_List/
        Iterated_List/../!includes/List_Functions/list_functions.h,
line 531.

=====================================================================
=====================================================================

    ======== Test _insert_last() ========
List :
        H->|||
       - - - - - - - - - - - - - - - -
----- Test 1: insert [60] in an emtpy list
Last node: = [60]
List after _insert_last()
        H->[60]->|||
       - - - - - - - - - - - - - - - -
Inserting 5 items
List after _insert_head():
        H->[40]->[30]->[20]->[10]->[0]->[60]->|||
       - - - - - - - - - - - - - - - -
----- Test 2: insert [24] in a list of 6 items
Last node: = [24]
List after _insert_last()
        H->[40]->[30]->[20]->[10]->[0]->[60]->[24]->|||
       - - - - - - - - - - - - - - - -

    ========== end of test _insert_last()==========

=====================================================================
=====================================================================

    ========== Test _index_of() ==========

Inserting 5 items
---- test 1: Index of [70] ---

List :
        H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
70 key is not in the list

----- test 2: Index of [40] -----

List:
        H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Index of [40] is 0

    ========= end of test _index_of() =========

=====================================================================
=====================================================================
   ======== Test _previous_node() ========
Inserting 5 items
List:
        H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
----- test 1: previous to [40]-------
No previous node: head_ptr only

List:
        H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
----- test 2: previous to [0]-------
Node before [0] is: [10]

----- test 3: previous to [90]-------
After this line assert from _previous_node must
end program since node doesn't exist

Assertion failed: (walker != nullptr && iMarker != nullptr),
function _previous_node,
file ../../../Dropbox/CS/Projects/12 Iterated_List/Iterated_List/
                ../!includes/List_Functions/list_functions.h,
line 531.

=====================================================================
=====================================================================


    ========== Test _remove_head() ==========

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Removed item number = 0
Removed item = 40
List after remove_node:
H->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Removed item number = 1
Removed item = 30
List after remove_node:
H->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Removed item number = 2
Removed item = 20
List after remove_node:
H->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
Removed item number = 3
Removed item = 10
List after remove_node:
H->[0]->|||
       - - - - - - - - - - - - - - - -
Removed item number = 4
Nothing to remove from list. Break loop

    ======== end of test _remove_head() ========
=====================================================================
=====================================================================
    ========== Test _remove_head() ==========

List :
       H->|||
       - - - - - - - - - - - - - - - -
----test 1: remove[30] from empty list
Nothing to remove from list

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------test 2: remove [40]---------
Removed item = 40
Printing new list:
H->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------test 3: remove [0]---------
Removed item = 0
Printing new list:
H->[30]->[20]->[10]->|||
       - - - - - - - - - - - - - - - -
---------test 4: remove [10]---------
Removed item = 10
Printing new list:
H->[30]->[20]->|||
       - - - - - - - - - - - - - - - -
---------test 5: remove [60]---------
Node doesn't exist. Assert from _previous_node()
must terminate program

Assertion failed: (walker != nullptr && iMarker != nullptr),
function _previous_node, f
ile ../../../Dropbox/CS/Projects/12 Iterated_List/Iterated_List/
                        ../!includes/List_Functions/list_functions.h,
line 531.

=====================================================================
=====================================================================

    =========== test _search() ===========

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------- Test 1: key = 12 ----------
12 is not found

List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------- Test 2: key = 40 ----------
printing searched item: [40]->

List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------- Test 3: key = 0 ----------
printing searched item: [0]->

    ============ end of test_search ============

=====================================================================
=====================================================================

    =========== test _size() ===========

List :
       H->|||
       - - - - - - - - - - - - - - - -
---------- Test 1: empty list ----------

Size of the list is: 0

Inserting 5 items
List :
       H->[40]->[30]->[20]->[10]->[0]->|||
       - - - - - - - - - - - - - - - -
---------- Test 2: list of 5 items----------

Size of the list is: 5

    =========== end of test _size() ===========

=====================================================================
=====================================================================

    END OF TEST OUTPUT FOR linked_list.h functions

=====================================================================
=====================================================================
*/

#endif // LINKED_LIST_OUTPUT_H
