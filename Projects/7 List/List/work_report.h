#ifndef LIST_WORK_REPORT_H
#define LIST_WORK_REPORT_H

/*
    Features:
        -Not Implemented: None

        -Implemented: all insertion functions(insert_after, insert_before,
                      insert_end, insert_head)
                      beginning and end accessors, bracket operator for the
                      list class previous_node, both remove functions(remove
                      node and remove head) search functions, copy and clear
                      functions as well as the print functions with extraction
                      operator for both list class and list_functions

        *Note         In the user interface when searching for an item
                      search starts from the next item to the cursor's
                      current position. If next item(Node) is null search
                      starts from the first node in the list

        **Note        for the purpose of the navigation(User interface)
                      the return value of Previous was changed.
                      if an item was head and we wanted the previous node to
                      it, Previous would return the node itself. the reason
                      behinde it is that if null was returned then the
                      navigation test would terminate if user wanted to insert
                      an item before  head since we cann't insert anything
                      before a nullptr;

        ***Note       since previous was changed, insert_before was also
                      slightly  alterd.
                      If inserting before a head note, previous returns
                      the node itself and item is inserted using Insert_Head


        -Partly implemented:none



    Bugs:
        -None

    Reflections:
        - was not as bad as i expected it to be. however it was tedious writing
          all the functions and testing all scenarios
          Previous_node functions was a little bit complicated but once I sat
          down and drew all the possible cases it became easy

*/

#endif // LIST_WORK_REPORT_H
