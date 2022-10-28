#include <iostream>
#include <vector>
#include "vector.hpp"
#include "ft.hpp"
#include <string>
#include <map>
#include <iterator>
#include "map.hpp"

int	main(void)
{
	// ft::vector<std::string> a;
	// a.insert(a.begin(),"c");
	// a.insert(a.begin(),"b");
	// a.insert(a.begin(),"a");
	// ft::vector<std::string>::reverse_iterator re = a.rbegin();
	// re++;
	// std::cout<< *re <<std::endl;

	// std::vector<std::string> s;
	// s.insert(s.begin(),"c");
	// s.insert(s.begin(),"b");
	// s.insert(s.begin(),"a");
	// std::vector<std::string>::reverse_iterator rev = s.rbegin();
	// rev++;
	// std::cout<< *rev <<std::endl;



	// std::map<std::string, std::string> a;
	// a["b"] = "2";
	// a["a"] = "1";
	// a["c"] = "3";
	// std::map<std::string, std::string>::iterator it = a.begin();
	// std::map<std::string, std::string>::iterator end = a.end();
	// for (; it != end; it++)
	// 	std::cout<< it->first << ": " << it->second << std::endl;
	// std::cout<< a["b"] << ": " << a["a"] << ": " << a["c"] << std::endl;
	// ft::pair<std::string, std::string> a("a", "1");
	ft::map<std::string, std::string> c;
	ft::map<std::string, std::string> b;

	std::cout<< (b.insert(ft::pair<std::string, std::string>("c", "3"))).first->second <<std::endl;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("a", "1"))).first->second <<std::endl;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("b", "2"))).first->second <<std::endl;
	std::cout<<"eljo "<<std::endl;
	// std::cout<< (b.insert(ft::pair<std::string, std::string>("c", "3"))).first->second <<std::endl;
	// b.print();
	ft::map<std::string, std::string>::reverse_iterator it = b.rend();
	ft::map<std::string, std::string>::reverse_iterator itt;
	itt = it;
	// b.print();

	std::cout<< (--it)->first <<std::endl;
	std::cout<< (--it)->first <<std::endl;
	std::cout<< (it--)->first <<std::endl;
	itt--;
	std::cout<< itt->first <<std::endl;
	std::cout<< (it++)->first <<std::endl;
	std::cout<< (++it)->first <<std::endl;
	*it--;
	*it++;
	std::cout<< it->first <<std::endl;



	std::map<std::string, std::string> d;
	std::map<std::string, std::string> f;

	std::cout<< (f.insert(std::pair<std::string, std::string>("c", "3"))).first->second <<std::endl;
	std::cout<< (f.insert(std::pair<std::string, std::string>("a", "1"))).first->second <<std::endl;
	std::cout<< (f.insert(std::pair<std::string, std::string>("b", "2"))).first->second <<std::endl;
	// std::cout<< (f.insert(std::pair<std::string, std::string>("c", "3"))).first->second <<std::endl;
	

	std::map<std::string, std::string>::reverse_iterator it1 = f.rend();
	std::map<std::string, std::string>::reverse_iterator it1t;
	it1t = it1;

	std::cout<< (--it1)->first <<std::endl;
	std::cout<< (--it1)->first <<std::endl;
	std::cout<< (it1--)->first <<std::endl;
	it1t--;
	std::cout<< it1t->first <<std::endl;
	std::cout<< (it1++)->first <<std::endl;
	std::cout<< (++it1)->first <<std::endl;
	*it1--;
	*it1++;
	std::cout<< it1->first <<std::endl;

	
	// b.print();

	// std::map <int, int> a;
	// ft::pair <int,int> foo;
	// ft::pair <int,int> bar;

	// foo = ft::make_pair (10,20);
	// bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	// std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	// std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
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
