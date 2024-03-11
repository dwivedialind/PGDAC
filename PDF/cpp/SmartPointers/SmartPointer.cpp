//Smart pointers provide a safer and more convenient way to manage memory in C++ compared to raw pointers. They automatically handle deallocation when they get out of scope, preventing memory leaks and dangling pointers.


/*
std:unique_ptr
Ownership: Owns a single dynamically allocated object created with new.
Exclusivity: Ensure only this unique_ptr has ownership and responsibility for deleting the object. No sharing allowed.
Lifetime Management: When the unique_ptr itself goes out of scope, it automatically deletes the object it owns using delete.

 */

/*
 std::shared_ptr
Ownership: Allows multiple shared_ptr s to share ownership of a single dynamically allocated object
Reference Counting: Each shared_ptr keeps track of the number of other shared_ptr s referencing the same object using a reference count
Lifetime Mangement: The object is deleted only when the last shared_ptr referencing it goes out of scope.
 */

/*
 std::weak_ptr
 Non-owning reference: Holds a now-owning reference to an object potentially managed by shared_ptr
 Checking Object Existence: Allows you to check if the object the weak_ptr refers to stil exist without affecting its lifetime or reference count.
 Avoiding Circular References: Useful for breaking circular references between objects that hold shared_ptr s to each other
 */
//You cannot directly access the object through a weak_ptr. you might need to convert it to a shared_ptr before using it.

#include <iostream>
#include <memory> //provide facilites for dynamic memory management such as smart pointers
using namespace std;

class MyClass{
   public:
	   MyClass(){
	   	cout << "MyClass object created!" << endl;
	   }

	   ~MyClass(){
		 cout << "MyClass object destroyed";
	   }
};

int main(void){
	
shared_ptr<MyClass> ptr(new MyClass());

//Create a weak_ptr that doesn't affect ownership (reference count remains 1)

weak_ptr<MyClass> weakPtr = ptr;

//Check if the object pointed to by ptr is still alive (using use_count() of shared_ptr)

if(weakPtr.expired())
	cout << "MyClass object is gone!" << endl;
else
	cout << "MyClass object is still alive!" << endl;
//ptr goes out of scope here, but weakPtr doesn't affect its lifetime
//Now weakPtr.expired() will return true


return 0;
}





int main2(void){

	shared_ptr<MyClass> ptr1(new MyClass());

	//Create another shared_ptr referencing the same object
	
	shared_ptr<MyClass> ptr2 = ptr1;

	//Both ptr1 and ptr2 share ownership (reference count is 2)
	
	cout << "Number of shared_ptrs: " << ptr1.use_count() << endl;
	//Output: 2
	
	//When both ptr1 and ptr2 go out of scope, reh reference count becomes 0, and the MyClass object is deleted.
	



return 0;
}

int main1(void){
//Create a unique_ptr that owns a dynamically allocated integer with value 42

	unique_ptr<int> ptr(new int(42));
	cout << *ptr << endl;

	//No need to manually delete

return 0;
}

