#include <iostream>
#include <vector>
#include "vector.hpp"
#include "ft.hpp"
#include <string>

int	main(void)
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

	ft::vector<int>::iterator it1 = foo.begin();
	ft::vector<int>::iterator it2 = bar.begin();

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

   std::cout << "foo contains:";
 
    std::cout << ' ' << *it1;
  std::cout << '\n';

  std::cout << "bar contains:";

    std::cout << ' ' << *it2;
  std::cout << '\n';

	return 0;
}