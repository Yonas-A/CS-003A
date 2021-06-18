#ifndef LINKED_LIST_SORTED_OUTPUT_H
#define LINKED_LIST_SORTED_OUTPUT_H
/*
 *
=====================================================================
        test output for individual functions from list_function.h
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

        ========== Test _insert() ==========

H->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 103
H->[103]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 139
H->[103]->[139]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 11
H->[11]->[103]->[139]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 32
H->[11]->[32]->[103]->[139]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 197
H->[11]->[32]->[103]->[139]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 180
H->[11]->[32]->[103]->[139]->[180]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 79
H->[11]->[32]->[79]->[103]->[139]->[180]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 176
H->[11]->[32]->[79]->[103]->[139]->[176]->[180]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 61
H->[11]->[32]->[61]->[79]->[103]->[139]->[176]->[180]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

Inserting 185
H->[11]->[32]->[61]->[79]->[103]->[139]->[176]->[180]->[185]->[197]->|||
         - - - - - - - - - - - - - - - - - - - -

        ======== end of test _insert()=========

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

         ======= Test _where_this_goes() ======

   TEST I: ACSENDING ORDER
----------- Test 1: -----------
H->|||
         - - - - - - - - - - - - - - - - - - - -

Where 25 go in empty list
It goes as head ptr

----------- Test 2: -----------
Inserting the following items:
  : 268: 296: 83: 40: 1: 50: 252: 41: 152: 93: 208: 56: 274: 232: 253
H->[1]->[40]->[41]->[50]->[56]->[83]->[93]->[152]->[208]->[232]->[252]->[253]->[268
>[274]->[296]->|||
         - - - - - - - - - - - - - - - - - - - -

Where 25 go in a list of 15 item list
It goes after 1

----------- Test 3: -----------
H->[1]->[40]->[41]->[50]->[56]->[83]->[93]->[152]->[208]->[232]->[252]->[253]->[268
>[274]->[296]->|||
         - - - - - - - - - - - - - - - - - - - -

Where -40 go in a list of 5 item list
It goes as head ptr

==================================================
==================================================
       TEST II: DESCENDING ORDER

H->|||
         - - - - - - - - - - - - - - - - - - - -

----------- Test 1: -----------
Where -40 go in empty list
It goes as head ptr

----------- Test 2: -----------
Inserting the following items:
  : 37: 6: 27: 164: 72: 233: 110: 228: 68: 247: 163: 33: 223: 219: 286
H->[286]->[247]->[233]->[228]->[223]->[219]->[164]->[163]->[110]->[72]->[68]->[37]-
33]->[27]->[6]->[-40]->|||
         - - - - - - - - - - - - - - - - - - - -

Where -55 go in a list of 15 item list
It goes after -55

----------- Test 3: -----------
H->[286]->[247]->[233]->[228]->[223]->[219]->[164]->[163]->[110]->[72]->[68]->[37]-
33]->[27]->[6]->[-40]->[-55]->|||
         - - - - - - - - - - - - - - - - - - - -

Where -20 go in a list of 5 item list
It goes after 6

     ======= end of test _where_this_goes() ======

=====================================================================
=====================================================================

    END OF TEST OUTPUT FOR linked_list_sorted.h of sorted functions

=====================================================================
=====================================================================
 */
#endif // LINKED_LIST_SORTED_OUTPUT_H
