Tortoise and hare algo

Take slow and fast pointers
move slow->next;
move fast->next->next;

if they collide there is a loop

What in Linear LL ?
If fast!=NULL && fast->next != NULL return false.
Because in loop there will be no NULL it will just go on :P.

The distance between fast and slow = d;
if d = 5;

fast will move by 2 step
slow will move by 1 step

d = 4;

Reduction is by 1 why ?
Fast is moving by 2
Slow is moving by 1

Net reduction = d-1 ;
there will be a point it will be 0.
d%1 = 0
