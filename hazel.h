
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


typedef int dtype;

//#define HASHSIZE 120


typedef struct holder {
	dtype type;											//t is datatype of variable
	char ident[17];										//ident is the name (to test if right spot in hash chain)
	void *location;										//location is where the actual value (of whatever kind is located)
	struct holder *next;								//next is location of next entry in that branch of hash listing
} holder;


typedef struct {
	int hashsize;
	holder **varhash; /*NULL PTR*/
} assoc_arr;


int strhash(assoc_arr *arr, const char str[]);
void createvar(assoc_arr *arr, const char name[], void *location);
void *findvar(assoc_arr *arr, const char name[]);
void deletevar(assoc_arr *arr, const char name[]);
void init_assoc_arr(assoc_arr *arr, int hashsize);






void init_assoc_arr(assoc_arr *arr, int hashsize) {
	
	arr->hashsize = hashsize;
	if (!(arr->varhash = (holder**)malloc(sizeof(assoc_arr) * hashsize))){
		puts("Memory allocation error"); sleep(4); exit(1);
	}
	
	
}
void createvar(assoc_arr *arr, const char name[], void *loc) {		// name: name of var, loc: location of value
	register int hash = strhash(arr, name);
	register holder *newh;							// the new one being added
	if (newh = (holder*)malloc(sizeof(holder)));			// create the holder
	else abort();//could change to return 0 to allow internal handling.


	newh->next = (arr->varhash[hash]);				//Point next to the previous first element in chain
	arr->varhash[hash] = (holder*) newh;			//Point varhash[hash] to the new element
	newh->location = loc;
	strcpy(newh->ident, name);
}


//not actually a void function --void pointer
void *findvar(assoc_arr *arr, const char name[]) {		// return location in memory  -- returns uncast pointer
	register int hash = strhash(arr, name);
	register holder *spot; spot = arr->varhash[hash];
	while (spot) {
		if (!strcmp(name, spot->ident)) {
			return (spot->location)?spot->location:NULL;				//hopelessly redundant -simplify
		}
		spot = spot->next;
	}
	return NULL;
}

void deletevar(assoc_arr *arr, const char name[]) {		//deletes variable - deleting the value pointed to is not this function's responsibility
	register int hash = strhash(arr, name);
	register holder *spot; spot = arr->varhash[hash];
	register holder *previous; previous = arr->varhash[hash];				//---This function is probably working!!!---	
	while (spot) {					//error somewhere in this loop
		spot = spot->next;
		if (!strcmp(name, spot->ident)) {			//find match					
			previous->next = spot ? spot->next : NULL;			//connect previous in chain to the next, or else nulptr
			if (spot) free(spot);								//free the deleted entry -- no need to check for nullptr
			
			return;
		}
		previous = spot;
	}
	return;
}



												//				could also be made into a macro for better speed
int strhash(assoc_arr *arr, const char str[]) {					//This function could be rewritten better, but it should work well enough for now
	int temp = 0;
	while (*str) {
		temp += (int)*str; str++;              //create hash of var name (1999 chosen because prime & nice seeming
	}
	return (temp * 1999) % arr->hashsize;				//1999 added for extra mixup (will slow things down, eliminate if unecessary)
}






