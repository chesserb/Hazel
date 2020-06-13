# Hazel
*All alone my watch I'm keeping,*  
*In the Hazel-Dell;*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Root  
  
Hazel is an associative array library. I wrote it as a beginning point of a programming language I was working on before I realized how much time it would take to make. I still hope to finish the language, but this is at least a starting point.  
Here you can find the [documentation](https://github.com/chesserb/Hazel/blob/master/documentation.md). Little as it may be, it's enough. This is a small library.  
  
Unfortunately:
## There are problems with deleting entries...
sometimes it will just get caught in an infinite loop as C code likes to do. If you find the problem or make a fix please let me know or submit it.
It does often work though. Isn't that the worst kind of bug... the one that taunts you from time to time, just enough to be a problem?  
If you don't want to delete entries the rest of the library should work just fine for you!
  
  
  
### Things to be added or changed...
* When making this, since it hadn't become important to my project yet, I had not added a function to determine if an entry exists in an array with a particular name. This can be determined as is with `findvar` (which will return NULL if entry is not found, if I remember correctly...). I would be nice though, to have a simple `isentry` function to serve this specific purpose.  
* The second thing I would like to add is a method of deleting a whole associative array. This could be important if it were used to implement something like a JavaScript type object which is literally just an associative array and objects needed to be deleted. It may be better to just have one big master array and just store all elements of all objects in, encoding the object and object element names somehow to avoid conflict of names.  
* Changing the 
* I may come up with other things I want to add, so hopefully this library will grow quite a bit. It's my first piece of published code so I'd like to make it pretty good. If you have any suggestions for features or better ways of implementing things, please let me know!
