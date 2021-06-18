#ifndef QUEUE_OUTPUT_H
#define QUEUE_OUTPUT_H

/*
==========================================================================
    test output for queue class memeber fun, ctors and destructors
==========================================================================

    - - - simple_test_Iterator - - -

q:
  H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->|||
        -------- END printing --------


- - - - Printing iterator stuff - - -

It ==>[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->   |||

    -  -  -  -  -  -  -   -   -
=============================================================================
=============================================================================
     ======== test _big_three ========

        ----- default ctor(): myQ ------
myQ
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


        ----- copy ctor(): myQ2(myQ) ------
myQ
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


myQ2
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


changing the front of myQ2 with 625

myQ
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


myQ2
   H->[-15]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


        ----- ctor = () myQ2 = myQ2 ------
myQ3
   H->[-15]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


     ======== end of test _big_three ========

=============================================================================
=============================================================================
        ====== Test Empty() =======
myQ
   H->|||
        -------- END printing --------

        ------- test 1: empty list ---------
List is empty

        ------- test 2: list with 10 items --------
myQ
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------

List is not empty

        ====== end of test Empty() ======

=============================================================================
=============================================================================
        ====== Test Front() =======

        ------- test 1: empty list ---------
No front node found. List is empty

        ------- test 2: list with 10 items --------
Front node is [100]
changing the front of myQ

H->[41]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------

        ====== end of test Front() ======
=============================================================================
=============================================================================


-  -   - test Push() - - -

Inserting: 10
    End of list is : 10
Inserting: 20
    End of list is : 20
Inserting: 30
    End of list is : 30
Inserting: 40
    End of list is : 40
Inserting: 50
    End of list is : 50
Inserting: 60
    End of list is : 60
Inserting: 70
    End of list is : 70
Inserting: 80
    End of list is : 80
Inserting: 90
    End of list is : 90
Inserting: 100
    End of list is : 100
Queue:
  H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->|||
        -------- END printing --------


-  -   - end of test Push() - - -

=============================================================================
=============================================================================

        ====== Test operator[]() ======

myQ
   H->|||
        -------- END printing --------


----- test 1: item at index = 7 -------
list is empty
Index out of bounds/ list doesn't exist

myQ
   H->[100]->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


----- test 2: item at index = 3 -------
list has 10 items
Item at myQ[3] = 400

        ====== end of test operator[]() ======

=============================================================================
=============================================================================
Note
// test was done with end function returning the last node
to see if it was set to nullptr after the last item in the list
was deleted.
Afterwards the end function was changed to return nullptr
        ====== Test Pop() ======

----- test 1: pop 15 items from  10 item queue -------
Delting item number: 0
Removed item = 100
head_ptr: 200 end_ptr 1000 after remove_item()
new queue:
       H->[200]->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 1
Removed item = 200
head_ptr: 300 end_ptr 1000 after remove_item()
new queue:
       H->[300]->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 2
Removed item = 300
head_ptr: 400 end_ptr 1000 after remove_item()
new queue:
       H->[400]->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 3
Removed item = 400
head_ptr: 500 end_ptr 1000 after remove_item()
new queue:
       H->[500]->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 4
Removed item = 500
head_ptr: 600 end_ptr 1000 after remove_item()
new queue:
       H->[600]->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 5
Removed item = 600
head_ptr: 700 end_ptr 1000 after remove_item()
new queue:
       H->[700]->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 6
Removed item = 700
head_ptr: 800 end_ptr 1000 after remove_item()
new queue:
       H->[800]->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 7
Removed item = 800
head_ptr: 900 end_ptr 1000 after remove_item()
new queue:
       H->[900]->[1000]->|||
        -------- END printing --------


Delting item number: 8
Removed item = 900
head_ptr: 1000 end_ptr 1000 after remove_item()
new queue:
       H->[1000]->|||
        -------- END printing --------


Delting item number: 9
Removed item = 1000
new queue:
       H->|||
        -------- END printing --------


Delting item number: 10
Queue is empty. Nothing to remove

Delting item number: 11
Queue is empty. Nothing to remove

Delting item number: 12
Queue is empty. Nothing to remove

Delting item number: 13
Queue is empty. Nothing to remove

Delting item number: 14
Queue is empty. Nothing to remove

- - -  check for _head and end ptr - - -

head and end are set to  null after  deleting all items

        ====== end of test Pop() ======

=============================================================================
=============================================================================

        ====== Test Search() =======
- - - test 1: search 10 in empty list - - -
myQ
   H->|||
        -------- END printing --------


Cannot find item in list

- - - test 2: search 100 in 10 item list - - -
myQ
   H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->|||
        -------- END printing --------


Searched item is: 100

        ====== end of test Queue.Search() ======

=============================================================================
=============================================================================

        ====== Test Size() =======
myQ
   H->|||
        -------- END printing --------


        - - - - test 1: empty list - - - -
List is empty. Size is 0
        - - - test 2: list with 10 items - - -
myS
   H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->[100]->|||
        -------- END printing --------


Size of list is: 10

        ====== end of test Queue.Size() ======

=============================================================================
=============================================================================

                        END OF TEST FOR QUEUE CLASS

=============================================================================
=============================================================================
 */
#endif // QUEUE_OUTPUT_H
