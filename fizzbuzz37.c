#include <stdio.h>
const char b[] = 
    "     	  	  	     		 "
    "   	    		     	  	 "
    " 	     		    	    		"
    "     	  	  	     		 "
    "   	    		     	  	 "
    " 	     		    	    		"
    "     	  	  	     		 "
    "   	    		     	  	 "
    " 	     		    	    		"
    "     	  	  	     		 ";
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch (2*b[2*i-2] + b[2*i-1]) {
            case 3*' '     : printf("%d\n", i); break;
            case 2*' '+'\t': puts("Fizz");      break;
            case 2*'\t'+' ': puts("Buzz");      break;
            case 3*'\t'    : puts("FizzBuzz");  break;
        }
    }
}
