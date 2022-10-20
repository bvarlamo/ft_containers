#include <iostream>
#include <vector>
#include "vector.hpp"
#include "ft.hpp"
#include <string>
#include <map>

int	main(void)
{
	std::map <int, int> a;
	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
 	// int range_array1[] = { 74, 569, -8822, 8515, 5 };

    //     std::vector<int> range_array(&range_array1[0], &range_array1[5]);
	// 	ft::vector<int> range_arrayf(&range_array1[0], &range_array1[5]);

    //     std::vector<int>::iterator stl_iterator = range_array.begin();
    //     ft::vector<int>::iterator ft_iterator = range_arrayf.begin();

    //     std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);
    //     ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);

        
    //     std::vector<int> stl_assign_vector = stl_range_vector;
    //     ft::vector<int> ft_assign_vector = ft_range_vector;

	// ft::vector<int> numbers(2, 42);
	// std::cout << numbers.begin() << std::endl;
	// numbers.insert(numbers.end(), numbers.begin(), numbers.end());
	// std::cout << numbers.begin() << std::endl;
	// for (ft::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	// {
	// 	std::cout<< *it << " ";
	// }
	// std::cout << std::endl;

	// std::vector<int> numbers1(2, 42);
	// numbers1.insert(numbers1.end(), numbers1.begin(), numbers1.end());
	// for (std::vector<int>::iterator it = numbers1.begin(); it != numbers1.end(); it++)
	// {
	// 	std::cout<< *it << " ";
	// }
	// std::cout << std::endl;
	// for (std::vector<int>::iterator it = stl_assign_vector.begin(); it != stl_assign_vector.end(); it++)
	// {
	// 	std::cout<< *it << " ";
	// }
	// std::cout << std::endl;

	// for (ft::vector<int>::iterator it = ft_assign_vector.begin(); it != ft_assign_vector.end(); it++)
	// {
	// 	std::cout<< *it << " ";
	// }
	// std::cout << std::endl;

	return 0;
}