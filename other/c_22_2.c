char** generateParenthesis(int n, int* returnSize){
	  char *stack = malloc(2 * n + 1);
	  int cap = 5000;
	  char **parent = (char **)malloc(cap * sizeof(char *));
	  int left = 0;
	  int right = 0;
	  char* p = stack;
    int count = 0;
    stack[2 * n] = '\0';
			
    while(p != stack || count == 0){
        if(left == n && right == n){
        	          parent[count] = malloc(2 * n + 1);
					  strcpy(parent[count], stack);
					  count++;
			
				      while(--p != stack){
					      if(*p == '('){
						      if(--left > right){
                               *p++ = ')';
							   right++;
							   break;
                        } 									
				     	    	}else{
						            right--;	
					     	    }
				        }
				}else{
				     while(left < n){
                 *p++ = '(';
                 left++;							
             }  					
				     while(right < n){
                 *p++ = ')';
                 right++;							 	            						
      	    }
	     	}			
    }
		*returnSize = count;
    return parent;
}
