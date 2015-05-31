#include <iostream>

class BaseClass {
	public:
		virtual void fn1() {
			std::cout << "This is BaseClass::fn1()" << std::endl;
		}

		void fn2() {
			std::cout << "This is BaseClass::fn2()" << std::endl;
		}
};


class DerivedClass: public BaseClass {
	public:
		void fn1() {
			std::cout << "This is DerivedClass::fn1()" << std::endl;
		}
		void fn2() {
			std::cout << "This is DerivedClass::fn2()" << std::endl;
		}
};


int main()
{
    DerivedClass derived_object;
	BaseClass *base_ptr = &derived_object;
	DerivedClass *derived_ptr = &derived_object;

	base_ptr->fn1();	derived_ptr->fn1();
	base_ptr->fn2();	derived_ptr->fn2();
    return 0;
}

