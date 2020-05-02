bag
===

`data / bag`



**bag** is a data structure that stores items in in an unordered arrangement.
Items can be stored in a *bag*, removed, and retrieved (read) from the *bag*.
The retrieved items however, *may* not be in any specific order.

A *bag* can be used in cases where it is requred to store a number of items, but
their order in which they are kept is unimportant.





Structure
---------

+------------------+-----------------+------------------+
| uword: **Count** | uword: **Size** | uint **Value[]** |
+------------------+-----------------+------------------+

-   *Count*: number of items contained in the bag

-   *Size*: maximum number of items that can be added to this *bag*

-   *Value[]*: array where the items are stored

Naming **bag**s are named with their size, i.e., the maximum number of items
they can contain. Hence, a bag which can store a miximum of 16 items is called
*bag16*. *bag*s of sizes 2, 4, 8, 16, 32, 64, 128, 256 are predefined but *bag*s
of other sizes can be defined and used as well.

Usage *bag* is simply a data structure that is defined using *typedef struct*,
and hence can be used as a datatype. Example usage of *bag*:



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// include headers here
// including the nitros header
bag32 MyBag;
void main()
{
// add 3 items
    bag_Add(MyBag, 1);
    bag_Add(MyBag, 2);
    bag_Add(MyBag, 3);
    // MyBag.Value[] = {1, 2, 3}
// remove 1 item from a location
    bag_RemoveAt(MyBag, 0);	// item at index 0 (1)
    // MyBag.Value[] = {3, 2}
// add 2 more items
    bag_Add(MyBag, 4);
    bag_Add(MyBag, 5);
    // MyBag.Value[] = {3, 2, 4, 5}
// remove 1 specific item
    bag_Remove(MyBag, 2);
    // MyBag.Value[] = {3, 5, 4}
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



Methods
-------


