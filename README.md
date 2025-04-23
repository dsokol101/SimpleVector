#SimpleVector class
This is the code from class 4/22/2025

The main concept here is that there is a pointer in this class. Job of the class (RAII) is to maintain safety of that pointer.

1a. every constructor must be sure to allocate memory for the pointer
1b. destructor must be sure to deallocate memory for the pointer
1c. copy constructor must be sure to allocate memory for the pointer
1d. copy assignment operator must be sure to allocate memory for the pointer
1e. move constructor must be sure to allocate memory for the pointer
1f. move assignment operator must be sure to allocate memory for the pointer