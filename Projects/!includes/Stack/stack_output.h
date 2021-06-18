#ifndef STACK_OUTPUT_H
#define STACK_OUTPUT_H

/*
==========================================================================
    test output for Stack class memeber(), ctors and destructors
==========================================================================
- - - simple_Iterator_test - - -

s:
  H->[8]->[11]->[98]->[57]->[74]->[79]->[50]->[74]->[92]->[36]->[53]->|||
        - - - - - - - - - - - - - - - - - -


- - - Printing iterator: POSTFIX - - -

It ==>[8]->[11]->[98]->[57]->[74]->[79]->[50]->[74]->[92]->[36]->[53]->|||

- - - Printing iterator: PREFIX - - -

It ==>[8]->[11]->[98]->[57]->[74]->[79]->[50]->[74]->[92]->[36]->[53]->|||

    - - - - - - - - - - - - - - - - - - - - -

======================================================================
======================================================================

   = = = Test big_three() = = =

- - - default ctor(): Stack<int> s - - -
s
   H->[94]->[55]->[9]->[5]->[69]->[88]->[80]->[98]->[22]->[9]->|||
        - - - - - - - - - - - - - - - - - -

   - - - Copy Ctor: myS2(s) - - -
myS2
   H->[94]->[55]->[9]->[5]->[69]->[88]->[80]->[98]->[22]->[9]->|||
        - - - - - - - - - - - - - - - - - -

changing the first item of myS2 to -15

s
   H->[94]->[55]->[9]->[5]->[69]->[88]->[80]->[98]->[22]->[9]->|||
        - - - - - - - - - - - - - - - - - -

myS2
   H->[-15]->[55]->[9]->[5]->[69]->[88]->[80]->[98]->[22]->[9]->|||
        - - - - - - - - - - - - - - - - - -

   - - - Ctor = (): myS3 = myS2 - - -
myS3
   H->[-15]->[55]->[9]->[5]->[69]->[88]->[80]->[98]->[22]->[9]->|||
        - - - - - - - - - - - - - - - - - -

   = = = end of Test big_three() = = =

======================================================================
======================================================================

   = = = Test Empty() = = =

   - - - test 1: an empty stack - - -
myS
   H->|||
        - - - - - - - - - - - - - - - - - -

Stack is empty

   - - - test 1: stack of 10 items - - -
H->[46]->[76]->[81]->[27]->[34]->[36]->[97]->[33]->[42]->[90]->|||
        - - - - - - - - - - - - - - - - - -

Stack has 10items

   = = = end of Test Empty() = = =

======================================================================
======================================================================

-  -   - test Insert() - - -

 Insert head for Stack
Inserting: 62
    Top of stack is : 62
Inserting: 35
    Top of stack is : 35
Inserting: 31
    Top of stack is : 31
Inserting: 19
    Top of stack is : 19
Inserting: 54
    Top of stack is : 54
Inserting: 60
    Top of stack is : 60
Inserting: 90
    Top of stack is : 90
Inserting: 92
    Top of stack is : 92
Inserting: 12
    Top of stack is : 12
Inserting: 48
    Top of stack is : 48
Inserting: 80
    Top of stack is : 80
Stack:
  H->[80]->[48]->[12]->[92]->[90]->[60]->[54]->[19]->[31]->[35]->[62]->|||
        - - - - - - - - - - - - - - - - - -

-  -   - end of test Insert() - - -

======================================================================
======================================================================

   = = = Test operator[]() = = =
myS
   H->[25]->[20]->[83]->[43]->[33]->[89]->[59]->[53]->[35]->[87]->|||
        - - - - - - - - - - - - - - - - - -

- - - test 1: item at index = 4 - - -
item at myS[4] = 33

s
   H->|||
        - - - - - - - - - - - - - - - - - -

- - - test 2: item at index = 8 - - -
list is empty
Since list is empty assert must terminate program
Assertion failed!

   = = = end of Test operator[]() = = =
=====================================================================
=====================================================================

NOTE
// test was done with bottom function returning the last node
to see if it was set to nullptr after the last item in the list
was deleted.
Afterwards the bottom function was changed to return nullptr

   = = = Test Pop() = = =
myS
   H->[92]->[32]->[23]->[77]->[0]->[52]->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

- - - test 1: pop 15 items from  10 item Stack - - -
Delting item number: 0
Removed item = 92
After Pop(item)->:   head_ptr: 32   end_ptr: 17
new Stack:
       H->[32]->[23]->[77]->[0]->[52]->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 1
Removed item = 32
After Pop(item)->:   head_ptr: 23   end_ptr: 17
new Stack:
       H->[23]->[77]->[0]->[52]->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 2
Removed item = 23
After Pop(item)->:   head_ptr: 77   end_ptr: 17
new Stack:
       H->[77]->[0]->[52]->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 3
Removed item = 77
After Pop(item)->:   head_ptr: 0   end_ptr: 17
new Stack:
       H->[0]->[52]->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 4
Stack is empty. Nothing to remove

Delting item number: 5
Removed item = 52
After Pop(item)->:   head_ptr: 36   end_ptr: 17
new Stack:
       H->[36]->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 6
Removed item = 36
After Pop(item)->:   head_ptr: 26   end_ptr: 17
new Stack:
       H->[26]->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 7
Removed item = 26
After Pop(item)->:   head_ptr: 97   end_ptr: 17
new Stack:
       H->[97]->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 8
Removed item = 97
After Pop(item)->:   head_ptr: 17   end_ptr: 17
new Stack:
       H->[17]->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 9
Removed item = 17
new Stack:
       H->|||
        - - - - - - - - - - - - - - - - - -

Delting item number: 10
Stack is empty. Nothing to remove

Delting item number: 11
Stack is empty. Nothing to remove

Delting item number: 12
Stack is empty. Nothing to remove

Delting item number: 13
Stack is empty. Nothing to remove

Delting item number: 14
Stack is empty. Nothing to remove

- - -  check for _head and end ptr - - -

head and end are set to  null after  deleting all items


   = = = end of test Pop() = = =
=====================================================================
=====================================================================

   = = = Test Search() = = =
- - - test 1: search 10 in empty list - - -
myS
   H->|||
        - - - - - - - - - - - - - - - - - -

Cannot find item in list

- - - test 2: search 21 in 10 item list - - -
myS
   H->[48]->[26]->[94]->[21]->[23]->[98]->[86]->[56]->[3]->[5]->|||
        - - - - - - - - - - - - - - - - - -

Searched item is: 21

   = = = end of test Search() = = =

=====================================================================
=====================================================================

   = = = Test Size() = = =

        ------- test 1: empty list ---------
myS
   H->|||
        -------- END printing --------

List is empty. Size is 0

   - - - test 2: list with 10 items - - -
myS
   H->[71]->[87]->[47]->[64]->[89]->[62]->[67]->[3]->[34]->[74]->|||
        -------- END printing --------

Size of list is: 10


   = = = end of test Size() = = =

=====================================================================
=====================================================================

   = = = Test Top() = = =

        ------- test 1: empty list ---------
myS
   H->|||
        -------- END printing --------

No top node found. List is empty

   - - - test 2: list with 10 items - - -
myS
   H->[17]->[25]->[6]->[53]->[48]->[17]->[5]->[17]->[93]->[18]->|||
        -------- END printing --------


Top node is [17]

   = = =  end of test Top() = = =

=====================================================================
=====================================================================

                        END OF TEST FOR STACK CLASS

=====================================================================
=====================================================================
 */

#endif // STACK_OUTPUT_H
