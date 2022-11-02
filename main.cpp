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

	std::cout<< (b.insert(ft::pair<std::string, std::string>("c", "3"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("a", "1"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("b", "2"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("d", "4"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("e", "5"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("f", "6"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("g", "7"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("h", "8"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("i", "9"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("3", "c"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("1", "a"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("2", "b"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("4", "d"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("5", "e"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("6", "f"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("7", "g"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("8", "h"))).first->second;
	std::cout<< (b.insert(ft::pair<std::string, std::string>("9", "i"))).first->second;
	// b.print();
	// ft::map<std::string, std::string>::iterator it = b.begin();
	// ft::map<std::string, std::string>::iterator end = b.end();
	ft::map<std::string, std::string> x(b);
	std::cout << "\nmymap['d'] is " << x["1"];

	
	std::cout<<"size: "<<x.max_size()<<std::endl;
	std::cout<<c.empty()<<std::endl;
	x.at("8") = "H";
	ft::pair<std::string, std::string> pp;
	pp = ft::make_pair ("90", "X");
	x.insert(x.begin(), pp);

	x.swap(b);
	ft::map<std::string, std::string>::iterator x1 = x.begin();
	ft::map<std::string, std::string>::iterator x2 = x.end();
	while (x1 != x2)
	{
		std::cout<<x1->first<<" : "<<x1->second<<" ";
		x1++;
	}
	std::cout<<std::endl;

	b.clear();
	std::cout<<"size: "<<b.size()<<std::endl;
	b = x;
	ft::map<std::string, std::string>::iterator bb = b.find("f");
	ft::map<std::string, std::string>::iterator b1 = b.begin();
	b.erase(bb, --b.end());
	// swap(b, x);
	// ft::map<std::string, std::string>::iterator b1 = b.begin();
	ft::map<std::string, std::string>::iterator b2 = b.end();
	while (b1 != b2)
	{
		std::cout<<b1->first<<" : "<<b1->second<<" ";
		b1++;
	}
	std::cout<<std::endl;
	
	std::cout<<"count: "<<b.count("99")<<std::endl;
	std::cout<<"size: "<<b.size()<<std::endl;
	ft::map<std::string, std::string>::const_iterator b3 = b.lower_bound("1");
	ft::map<std::string, std::string>::const_iterator b4 = b.upper_bound("e");
	while (b3 != b4)
	{
		std::cout<<b3->first;
		b3++;
	}
	std::cout<<std::endl;

	ft::pair<ft::map<std::string, std::string>::const_iterator, ft::map<std::string, std::string>::const_iterator> b5 = b.equal_range("e");
	std::cout<<"Pair: "<<b5.first->first<<" = "<<b5.second->first<<std::endl;

	std::cout<<"oper: "<<(b >= x)<<std::endl;
	// std::cout<<"find: "<<b.find("9")->second<<std::endl;
	// ft::map<std::string, std::string>::reverse_iterator itt;
	// itt = it;
	// // b.print();

	// // std::cout<<"eljo "<<std::endl;	
	// std::cout<< (--it)->first <<std::endl;
	// std::cout<< (--it)->first <<std::endl;
	// std::cout<< (it--)->first <<std::endl;
	// itt--;
	// std::cout<< itt->first <<std::endl;
	// std::cout<< (it++)->first <<std::endl;
	// std::cout<< (++it)->first <<std::endl;
	// *it--;
	// *it++;
	// std::cout<< it->first <<std::endl;



	std::map<std::string, std::string> d;
	std::map<std::string, std::string> f;

	std::cout<< (f.insert(std::pair<std::string, std::string>("c", "3"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("a", "1"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("b", "2"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("d", "4"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("e", "5"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("f", "6"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("g", "7"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("h", "8"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("i", "9"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("3", "c"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("1", "a"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("2", "b"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("4", "d"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("5", "e"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("6", "f"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("7", "g"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("8", "h"))).first->second;
	std::cout<< (f.insert(std::pair<std::string, std::string>("9", "i"))).first->second;
	

	// std::map<std::string, std::string>::iterator it1 = f.begin();
	// std::map<std::string, std::string>::iterator it1e = f.end();
	std::map<std::string, std::string> y(f);
	std::cout << "\nmymap['d'] is " << y["1"];
	
	
	std::cout<<"size: "<<y.max_size()<<std::endl;
	std::cout<<d.empty()<<std::endl;
	y.at("8") = "H";
	std::pair<std::string, std::string> p;
	p = std::make_pair ("90", "X");
	y.insert(y.begin(), p);

	y.swap(f);

	std::map<std::string, std::string>::iterator y1 = y.begin();
	std::map<std::string, std::string>::iterator y2 = y.end();
	while (y1 != y2)
	{
		std::cout<<y1->first<<" : "<<y1->second<<" ";
		y1++;
	}
	std::cout<<std::endl;

	f.clear();
	std::cout<<"size: "<<f.size()<<std::endl;
	f = y;
	std::map<std::string, std::string>::iterator ff = f.find("f");
	std::map<std::string, std::string>::iterator f1 = f.begin();
	f.erase(ff, --f.end());
	// swap(f, y);
	// std::map<std::string, std::string>::iterator f1 = f.begin();
	std::map<std::string, std::string>::iterator f2 = f.end();
	while (f1 != f2)
	{
		std::cout<<f1->first<<" : "<<f1->second<<" ";
		f1++;
	}
	std::cout<<std::endl;

	std::cout<<"count: "<<f.count("99")<<std::endl;
	std::cout<<"size: "<<f.size()<<std::endl;
	std::map<std::string, std::string>::const_iterator f3 = f.lower_bound("1");
	std::map<std::string, std::string>::const_iterator f4 = f.upper_bound("e");
	while (f3 != f4)
	{
		std::cout<<f3->first;
		f3++;
	}
	std::cout<<std::endl;

	std::pair<std::map<std::string, std::string>::const_iterator, std::map<std::string, std::string>::const_iterator> f5 = f.equal_range("e");
	std::cout<<"Pair: "<<f5.first->first<<" = "<<f5.second->first<<std::endl;
	
	std::cout<<"oper: "<<(f >= y)<<std::endl;
	// std::cout<<"find: "<<f.find("9")->second<<std::endl;
	// std::map<std::string, std::string>::reverse_iterator it1t;
	// it1t = it1;

	// std::cout<< (--it1)->first <<std::endl;
	// std::cout<< (--it1)->first <<std::endl;
	// std::cout<< (it1--)->first <<std::endl;
	// it1t--;
	// std::cout<< it1t->first <<std::endl;
	// std::cout<< (it1++)->first <<std::endl;
	// std::cout<< (++it1)->first <<std::endl;
	// *it1--;
	// *it1++;
	// std::cout<< it1->first <<std::endl;

	
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

