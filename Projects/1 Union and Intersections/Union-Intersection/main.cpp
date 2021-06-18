#include <iostream>
//#include "../Union_Intersection/Union_Intersection.h"
#include "../Union_Intersection/union.h"
using namespace std;

/*
    Author: Yonas Adamu
    Project: Union and Intersection
    Purpose: finding the Union (all unique elements) and  Intersection
            or the commomn elements of two sorted sets and writing
            these values in two empty arrays
 */

void simple_test();

void new_test();

int main()
{

    new_test();
//    simple_test();
    return 0;
}

//void simple_test()
//{
//    int src_1[SRC_1_MAX] = {3,4,15,20,25,30,31,32,33,34};
//    int src_2[SRC_2_MAX] = {5,10,13,19,21,22,27,35, 37,40};
//    int arrInters[RESULT_MAX] = {}; //array to hold intersection elements
//    int arrUnion[RESULT_MAX] = {};  //array to hold the union elements

//    int inters_size = 0; // initial intersection array size
//    int union_size = 0;  // initial union array size

//    print (src_1, SRC_1_MAX);
//    print (src_2, SRC_2_MAX);
//    cout << "printing intersectin N union array with size = 0\n";
//    print (arrInters, inters_size);// printing the empty inter. array
//    print (arrUnion, union_size);  // printing the empty union array


//    intersection (src_1, SRC_1_MAX,  src_2, SRC_1_MAX, arrInters, inters_size);
//    Union (src_1,SRC_1_MAX, src_2, SRC_2_MAX, arrUnion, union_size);

//    cout << "\nSRC1 array:\n";
//    print (src_1, SRC_1_MAX);
//    cout << "\nSRC1 array:\n";
//    print (src_2, SRC_2_MAX);
//    cout << "\nUNION array:\n";
//    print (arrUnion, union_size);
//    cout << "\nINTERSECTION array:\n";
//    print (arrInters, inters_size);
//}

void new_test()
{
    int src_1[] = {3,4,15,20,25,30,31,32,33,34};
    int src_2[SRC_2_MAX] = {5,10,13,19,21,22,27,35, 37,40};

    int union_size = 0;  // initial union array size

    print (src_1, SRC_1_MAX);
    print (src_2, SRC_2_MAX);

    int* ptr =  Union (src_1,SRC_1_MAX, src_2, SRC_2_MAX, union_size);

    cout << "\nUNION array:\n";
    print( ptr, union_size);
    delete ptr;

}
