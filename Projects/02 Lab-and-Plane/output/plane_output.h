#ifndef PLANE_OUTPUT_H
#define PLANE_OUTPUT_H

/*
==============================================================================
                    TEST FOR PLANE PROJECT
==============================================================================

TESTING RESERVE FUNCTION
=================================================================
TEST 1: testing for char input for row
=================================================================

1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

[R]eserve    [C]ancel      e[x]it
 : R
---- RESERVE SEAT: ------
1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: `
Row: C
Row: 1
Seat letter: A

Seat reserved at 1A
1:  X     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

=================================================================
TEST 2: testing  for occupied seat (both row and seat number occupied)
=================================================================
[R]eserve    [C]ancel      e[x]it
:R
---- RESERVE SEAT: ------
1:  X     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 1
Seat letter: C

Seat reserved at 1C
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 1
Seat letter: c

Seat 1C is occupied
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

=================================================================
TEST 3: testing  for invalid seat letter
=================================================================

[R]eserve    [C]ancel      e[x]it
:R
---- RESERVE SEAT: ------
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 1
Seat letter: F
Seat number 1F is invalid.
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

=================================================================
TEST 4: testing  for invalid seat (row invalid)
=================================================================
[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  X     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 10
Seat letter: c
Seat number 10C is invalid.
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  X     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D



=================================================================
TEST 5: testing  for invalid seat (both row and seat letter invalid)
=================================================================
[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  X     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 10
Seat letter: c
Seat number 10C is invalid.
1:  X     B     X     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  X     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

=================================================================
TEST 5: testing to see after occupying all the seats
=================================================================

[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     D

Row: 9
Seat letter: d

Seat reserved at 9D
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X


[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

Row: 9
Seat letter: d

Seat 9D is occupied
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

Row: 5
Seat letter: a

Seat 5A is occupied
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

[R]eserve    [C]ancel      e[x]it
:r
---- RESERVE SEAT: ------
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

Row: 6
Seat letter: a

Seat 6A is occupied
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X


--------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------

TESTING CANCEL FUNCTION

=================================================================
TEST 1: testing for char input for row
=================================================================
[R]eserve    [C]ancel      e[x]it
:c
---- Cancel: ------

Row: a
Row: a
Row: b
Row: 1
Seat letter: d

Reservation cancelled
1:  X     X     X     D
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X


=================================================================
TEST 2: testing for invalid seat letter
=================================================================
[R]eserve    [C]ancel      e[x]it
:c
---- Cancel: ------

Row: 1
Seat letter: f

Seat number 1F is invalid.
1:  X     X     X     D
2:  X     X     X     X
3:  X     X     X     X
4:  X     X     X     X
5:  X     X     X     X
6:  X     X     X     X
7:  X     X     X     X
8:  X     X     X     X
9:  X     X     X     X

=================================================================
TEST 3: testing for invalid row
=================================================================

[R]eserve    [C]ancel      e[x]it
:c
---- Cancel: ------
1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 11
Seat letter: b

Seat number 11B is invalid.
1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D


=================================================================
TEST 4: testing for unreserved seat
=================================================================

[R]eserve    [C]ancel      e[x]i
 : c
---- Cancel: ------
1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 1
Seat letter: b

Seat was not reserved
1:  A     B     C     D
2:  A     B     C     D
3:  A     B     C     D
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

=================================================================
TEST 4: testing for normal seat cancellation
=================================================================


[R]eserve    [C]ancel      e[x]it
:c
---- Cancel: ------
1:  X     X     X     X
2:  X     X     X     X
3:  X     X     X     X
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

Row: 2
Seat letter: b

Reservation cancelled
1:  X     X     X     X
2:  X     B     X     X
3:  X     X     X     X
4:  A     B     C     D
5:  A     B     C     D
6:  A     B     C     D
7:  A     B     C     D
8:  A     B     C     D
9:  A     B     C     D

 */

#endif  // PLANE_OUTPUT_H
