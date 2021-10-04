public class StackUsingArray {
	
	public static void main(String[] args) {

		stack s = new stack();
        s.push(10);
        s.push(20);
        s.push(30);
        System.out.println(s.size() + " length of stack");
        System.out.println(s.pop() + " Popped from stack");
        System.out.println("Top element is :" + s.peek());
        System.out.print("Elements present in stack :");
        s.print();

	}

}

class stack {
	
	static final int MAX = 100;
	int top;
	int element[] = new int[MAX];
	
	boolean isEmpty() {
		return top < 0;
	}
	
	stack() {
		top = -1;
	}
	
	boolean push(int val) {
		if(top >= (MAX-1)) {
			System.out.println("Stack Overflow!");
			return false;
		} else {
			element[++top] = val;
			System.out.println(val);
			return true;
		}
	}
	
	int pop() {
		if(top < 0) {
			System.out.println("Stack Underflow");
            return -1;
		} else {
			int x = element[top--];
            return x;
		}
	}
	
	int size() {
		return top+1;
	}
	
	int peek()
    {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return -1;
        }
        else {
            int x = element[top];
            return x;
        }
    }
	
	void print(){
	    for(int i = top;i>-1;i--){
	      System.out.print(" "+ element[i]);
	    }
	}
}
