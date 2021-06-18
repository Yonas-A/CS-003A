#ifndef UNION_INTERSECTION_OUTPUT_H
#define UNION_INTERSECTION_OUTPUT_H

/*

//NOTE: ALL CHARACTERS AND INTEGERS ARE SEPERATED BY A SPACE FOR
        clarity

----------------------------Test 1: ----------------------------

comment:   	both source arrays filled to their full size

3  4  15  20  25  30  31  32  33  35

5  10  13  20  21  22  25  35  37  40

-------------------------------------------------------


SRC1 array:
3  4  15  20  25  30  31  32  33  35

SRC1 array:
5  10  13  20  21  22  25  35  37  40

UNION array:
3  4  5  10  13  15  20  21  22  25  30  31  32  33  35  37  40

INTERSECTION array:
20  25  35

----------------------------TEST 2: ----------------------------

comment: 	src1 partially filled while src2 is full

3  4  15  20  25

5  10  13  20  21  22  25  35  37  40

-------------------------------------------------------

SRC1 array:
3  4  15  20  25

SRC1 array:
5  10  13  20  21  22  25  35  37  40

UNION array:
3  4  5  10  13  15  20  21  22  25  35  37  40

INTERSECTION array:
20  25



----------------------------Test 3: ----------------------------

comment:	SRC1 is full while SRC2 is partially filled

3  4  15  20  25  30  31  32  33  35

5  10  13

-------------------------------------------------------

SRC1 array:
3  4  15  20  25  30  31  32  33  35

SRC1 array:
5  10  13

UNION array:
3  4  5  10  13  15  20  25  30  31  32  33  35

INTERSECTION array:



----------------------------Test 4:  ----------------------------

comment: 	one of the source arrays is empty

3  4  15  20  25  30  31  32  33  35

    // empty array
-------------------------------------------------------


SRC1 array:
3  4  15  20  25  30  31  32  33  35

SRC1 array:		// empty array

UNION array:
3  4  15  20  25  30  31  32  33  35


INTERSECTION array:

----------------------------Test 5:  ----------------------------

comment: 	both source arrays have same size and elements

3  4  15  20  25  30  31  32  33  35

3  4  15  20  25  30  31  32  33  35

-------------------------------------------------------


SRC1 array:
3  4  15  20  25  30  31  32  33  35

SRC1 array:
3  4  15  20  25  30  31  32  33  35

UNION array:
3  4  15  20  25  30  31  32  33  35

INTERSECTION array:
3  4  15  20  25  30  31  32  33  35


----------------------------Test 6:  ----------------------------

comment: 	source arrays have no common elements

3  4  15  20  25  30  31  32  33  34

5  10  13  19  21  22  27  35  37  40

-------------------------------------------------------

SRC1 array:
3  4  15  20  25  30  31  32  33  34

SRC1 array:
5  10  13  19  21  22  27  35  37  40

UNION array:
3  4  5  10  13  15  19  20  21  22  25  27  30  31  32  33  34  35  37  40

INTERSECTION array:
// empty array

 */
#endif // UNION_INTERSECTION_OUTPUT_H
