Tortoise & Hare Algorithm

Take two pointers
slow , fast
slow = slow->next
fast = fast->next->next

when slow == fast

`findLength(slow , fast) {

cnt = 1, fast = fast->next

while(slow != fast){

cnt++;

fast = fast->next;

}

return cnt;
}`
