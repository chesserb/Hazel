##Use instructions...

Declare a associative array struct
`assoc_arr t;`

Then initialize it
`init_assoc_arr(&t, 45);`
where the second argument is how many 'channels' the associative array should have.

Then use the three functions to do operations on the associative array.
```int k = 1776;
	createvar(&t, "CreationOfMerica", &k); /*noting that the name can only be 16 characters long*/
  printf("%d\n",*(int*)findvar(&t, "CreationOfMerica"));
  deletevar(&t, "CreationOfMerica");```
  It should be noted that `deletevar` seems to be broken, but who ever wants to delete a variable anyway?
  
