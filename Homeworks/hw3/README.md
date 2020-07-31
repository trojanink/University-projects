# Toll station (Homework 3)

In the second set of exercises you had to save for each car the type, license plate and the amount owed. Because these quantities are of a different type (character, string, and floating point number), you first have to combine each type with the corresponding tag in a string and then use two "parallel" arrays, which confuses the code and increases the probability of error (eg to make a change in one table and not to make a corresponding change in the other.

When we want to store data of different types that refer to the same entity
(eg on a vehicle), the best way is to group these types into a struct.
For the third set of exercises, you will repeat the second, but this time instead of two tables of data
(one of strings and one of numbers), you will have a table of struct.

In addition, you will implement two more classification algorithms.
