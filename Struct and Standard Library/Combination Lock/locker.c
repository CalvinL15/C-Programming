#include "locker.h"
 
void init(Lock *lock){
	lock->status = 0;
}

int lock(Lock *lock, int combination){
	if(lock->status == 1)
		return -1;
	else{
		if(combination >= 0 && combination < 10000){
			lock->passcode = combination;
			lock->status = 1;
			return combination;
		}
		else return 10000;	
	}	
}
int unlock(Lock *lock, int combination){
	if(lock->status == 0)
		return -1;
	else{
		if(combination == lock->passcode){
			lock->status = 0;
			return 0;
		}
		else return 1;	
	}	
}
int isLocked(Lock *lock){
	if(lock->status == 0)
		return 0;
	else return 1;	
}

 
