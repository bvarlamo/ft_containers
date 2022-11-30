#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include "set.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <list>

int	main()
{
	{
		std::cout<<"-----Vector----"<<std::endl;
		ft::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);
		ft::vector<int>::iterator it = v.begin();
		ft::vector<int>::iterator itP = v.begin();
		ft::vector<int>::const_iterator rt = v.begin();
		if (it == rt)
			std::cout<<"They are equal"<<std::endl;
		else
			std::cout<<"They are not equal"<<std::endl;

		ft::vector<int> v1;
		v1.push_back(11);
		v1.push_back(21);
		v1.push_back(31);
		v1.push_back(41);
		v1.push_back(51);
		v1.push_back(61);
		v1.push_back(71);
		v1.push_back(81);
		v1.push_back(91);

		ft::vector<int>::iterator it1P = v1.begin();
		ft::vector<int>::const_iterator rt1 = v1.begin();
		std::cout<<"first: ";
		while (it != v.end())
		{
			std::cout<<*it<<" ";
			it++;
		}
		std::cout<<std::endl;
		std::cout<<"second: ";
		while (rt1 != v1.end())
		{
			std::cout<<*rt1<<" ";
			rt1++;
		}
		std::cout<<std::endl;

		std::cout<<"itP before swap: "<<*itP<<std::endl;
		std::cout<<"it1P before swap: "<<*it1P<<std::endl;

		v.swap(v1);

		std::cout<<"itP after swap: "<<*itP<<std::endl;
		std::cout<<"it1P after swap: "<<*it1P<<std::endl;

		ft::vector<int>::iterator it3 = v1.begin();
		ft::vector<int>::iterator it2 = v.begin();

		std::cout<<"first: ";
		while (it2 != v.end())
		{
			std::cout<<*it2<<" ";
			it2++;
		}
		std::cout<<std::endl;
		std::cout<<"second: ";
		while (it3 != v1.end())
		{
			std::cout<<*it3<<" ";
			it3++;
		}
		std::cout<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::cout<<"-----STL-Vector----"<<std::endl;
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);
		std::vector<int>::iterator it = v.begin();
		std::vector<int>::iterator itP = v.begin();
		std::vector<int>::const_iterator rt = v.begin();
		if (it == rt)
			std::cout<<"They are equal"<<std::endl;
		else
			std::cout<<"They are not equal"<<std::endl;

		std::vector<int> v1;
		v1.push_back(11);
		v1.push_back(21);
		v1.push_back(31);
		v1.push_back(41);
		v1.push_back(51);
		v1.push_back(61);
		v1.push_back(71);
		v1.push_back(81);
		v1.push_back(91);

		std::vector<int>::iterator it1P = v1.begin();
		std::vector<int>::const_iterator rt1 = v1.begin();
		std::cout<<"first: ";
		while (it != v.end())
		{
			std::cout<<*it<<" ";
			it++;
		}
		std::cout<<std::endl;
		std::cout<<"second: ";
		while (rt1 != v1.end())
		{
			std::cout<<*rt1<<" ";
			rt1++;
		}
		std::cout<<std::endl;

		std::cout<<"itP before swap: "<<*itP<<std::endl;
		std::cout<<"it1P before swap: "<<*it1P<<std::endl;

		v.swap(v1);

		std::cout<<"itP after swap: "<<*itP<<std::endl;
		std::cout<<"it1P after swap: "<<*it1P<<std::endl;

		std::vector<int>::iterator it3 = v1.begin();
		std::vector<int>::iterator it2 = v.begin();
		std::cout<<"first: ";
		while (it2 != v.end())
		{
			std::cout<<*it2<<" ";
			it2++;
		}
		std::cout<<std::endl;
		std::cout<<"second: ";
		while (it3 != v1.end())
		{
			std::cout<<*it3<<" ";
			it3++;
		}
		std::cout<<std::endl;
		std::cout<<std::endl;
	}


	std::cout<<"-----Map----"<<std::endl;

	{
		ft::pair<int, int> p;
		p = ft::make_pair(1, 11);
		std::cout<<"make_pair first: " << p.first<<"  make_pair second: "<<p.second<<std::endl;
		const int range_int[] = {-652, -4, 98, 54, -210};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		ft::map<int, std::string> ft_map;
		std::cout<<"inserting: ";
		for (int i = 0; i < 5; i++)
		{
			std::cout<<ft_map.insert(ft::make_pair(range_int[i], range_str[i])).first->first<<" ";
		}
		std::cout<<std::endl;
		ft::map<int, std::string>::iterator a = ft_map.begin();
		std::cout<<"iterator a contains before insertion or deletion into map. first: "<<a->first<<" second: "<<a->second<<std::endl;
		std::cout<<"inserting: "<<ft_map.insert(ft::make_pair(-4, "Two")).first->first<<std::endl;

		std::cout<<"map contains after inserting existing key: ";
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" ";
		std::cout<<std::endl;

		ft_map.erase(-4);
		std::cout<<"map contains after deleting key: ";
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" ";
		std::cout<<std::endl;

		std::cout<<"iterator a contains after insertion or deletion into map. first: "<<a->first<<" second: "<<a->second<<std::endl;
		std::cout<<std::endl;

		const int range_int1[] = {478, 952, 12, -96, -9};
		const std::string range_str1[] = {"One", "Two", "Three", "Four", "Five"};

		ft::map<int, std::string> ft_map1;
		for (int i = 0; i < 5; i++)
		{
			ft_map1.insert(ft::make_pair(range_int1[i], range_str1[i]));
		}
		std::cout<<"ft_map contains before swap: ";
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_map1 contains before swap: ";
		for (ft::map<int, std::string>::iterator it = ft_map1.begin(); it != ft_map1.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;
		std::cout<<std::endl;

		ft_map.swap(ft_map1);

		std::cout<<"ft_map contains after swap: ";
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_map1 contains after swap: ";
		for (ft::map<int, std::string>::iterator it = ft_map1.begin(); it != ft_map1.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;



		std::cout<<std::endl;
		std::cout<<std::endl;
	}
	
	std::cout<<"-----STL-Map----"<<std::endl;

	{
		std::pair<int, int> p;
		p = std::make_pair(1, 11);
		std::cout<<"make_pair first: " << p.first<<"  make_pair second: "<<p.second<<std::endl;
		const int range_int[] = {-652, -4, 98, 54, -210};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> ft_map;
		std::cout<<"inserting: ";
		for (int i = 0; i < 5; i++)
		{
			std::cout<<ft_map.insert(std::make_pair(range_int[i], range_str[i])).first->first<<" ";
		}
		std::cout<<std::endl;
		std::map<int, std::string>::iterator a = ft_map.begin();
		std::cout<<"iterator a contains before insertion or deletion into map. first: "<<a->first<<" second: "<<a->second<<std::endl;
		std::cout<<"inserting: "<<ft_map.insert(std::make_pair(-4, "Two")).first->first<<std::endl;

		std::cout<<"map contains after inserting existing key: ";
		for (std::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" ";
		std::cout<<std::endl;

		ft_map.erase(-4);
		std::cout<<"map contains after deleting key: ";
		for (std::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" ";
		std::cout<<std::endl;

		std::cout<<"iterator a contains after insertion or deletion into map. first: "<<a->first<<" second: "<<a->second<<std::endl;
		std::cout<<std::endl;

		const int range_int1[] = {478, 952, 12, -96, -9};
		const std::string range_str1[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> ft_map1;
		for (int i = 0; i < 5; i++)
		{
			ft_map1.insert(std::make_pair(range_int1[i], range_str1[i]));
		}
		std::cout<<"ft_map contains before swap: ";
		for (std::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_map1 contains before swap: ";
		for (std::map<int, std::string>::iterator it = ft_map1.begin(); it != ft_map1.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;
		std::cout<<std::endl;

		ft_map.swap(ft_map1);

		std::cout<<"ft_map contains after swap: ";
		for (std::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_map1 contains after swap: ";
		for (std::map<int, std::string>::iterator it = ft_map1.begin(); it != ft_map1.end(); it++)
			std::cout<<it->first<<" "<<it->second<<" ";
		std::cout<<std::endl;



		std::cout<<std::endl;
		std::cout<<std::endl;
	}

	std::cout<<"-----Stack----"<<std::endl;

	{
		ft::stack<int> s;
		std::cout<<"stack empty before pushing 2 values: "<<s.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s.size()<<std::endl;
		s.push(1);
		s.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s.size()<<std::endl;
		std::cout<<"stack top value: "<<s.top()<<std::endl;
		s.pop();
		std::cout<<"stack top value after pop: "<<s.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::vector"<<std::endl;
		std::cout<<std::endl;
		
		ft::stack<int, std::vector<int> > s1;
		std::cout<<"stack empty before pushing 2 values: "<<s1.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s1.size()<<std::endl;
		s1.push(1);
		s1.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s1.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s1.size()<<std::endl;
		std::cout<<"stack top value: "<<s1.top()<<std::endl;
		s1.pop();
		std::cout<<"stack top value after pop: "<<s1.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s1.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s1.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::deque"<<std::endl;
		std::cout<<std::endl;
		
		ft::stack<int, std::deque<int> > s2;
		std::cout<<"stack empty before pushing 2 values: "<<s2.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s2.size()<<std::endl;
		s2.push(1);
		s2.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s2.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s2.size()<<std::endl;
		std::cout<<"stack top value: "<<s2.top()<<std::endl;
		s2.pop();
		std::cout<<"stack top value after pop: "<<s2.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s2.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s2.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::list"<<std::endl;
		std::cout<<std::endl;
		
		ft::stack<int, std::list<int> > s3;
		std::cout<<"stack empty before pushing 2 values: "<<s3.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s3.size()<<std::endl;
		s3.push(1);
		s3.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s3.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s3.size()<<std::endl;
		std::cout<<"stack top value: "<<s3.top()<<std::endl;
		s3.pop();
		std::cout<<"stack top value after pop: "<<s3.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s3.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s3.size()<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
	}

	std::cout<<"-----STL-Stack----"<<std::endl;

	{
		std::stack<int> s;
		std::cout<<"stack empty before pushing 2 values: "<<s.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s.size()<<std::endl;
		s.push(1);
		s.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s.size()<<std::endl;
		std::cout<<"stack top value: "<<s.top()<<std::endl;
		s.pop();
		std::cout<<"stack top value after pop: "<<s.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::vector"<<std::endl;
		std::cout<<std::endl;
		
		std::stack<int, std::vector<int> > s1;
		std::cout<<"stack empty before pushing 2 values: "<<s1.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s1.size()<<std::endl;
		s1.push(1);
		s1.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s1.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s1.size()<<std::endl;
		std::cout<<"stack top value: "<<s1.top()<<std::endl;
		s1.pop();
		std::cout<<"stack top value after pop: "<<s1.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s1.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s1.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::deque"<<std::endl;
		std::cout<<std::endl;
		
		std::stack<int, std::deque<int> > s2;
		std::cout<<"stack empty before pushing 2 values: "<<s2.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s2.size()<<std::endl;
		s2.push(1);
		s2.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s2.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s2.size()<<std::endl;
		std::cout<<"stack top value: "<<s2.top()<<std::endl;
		s2.pop();
		std::cout<<"stack top value after pop: "<<s2.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s2.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s2.size()<<std::endl;
		std::cout<<std::endl;

		std::cout<<"stack with std::list"<<std::endl;
		std::cout<<std::endl;
		
		std::stack<int, std::list<int> > s3;
		std::cout<<"stack empty before pushing 2 values: "<<s3.empty()<<std::endl;
		std::cout<<"stack size before pushing 2 values: "<<s3.size()<<std::endl;
		s3.push(1);
		s3.push(2);
		std::cout<<"stack empty after pushing 2 values: "<<s3.empty()<<std::endl;
		std::cout<<"stack size after pushing 2 values: "<<s3.size()<<std::endl;
		std::cout<<"stack top value: "<<s3.top()<<std::endl;
		s3.pop();
		std::cout<<"stack top value after pop: "<<s3.top()<<std::endl;
		std::cout<<"stack empty after pop: "<<s3.empty()<<std::endl;
		std::cout<<"stack size after pop: "<<s3.size()<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
	}

	std::cout<<"-----Set----"<<std::endl;

	{
		const int range_int[] = {-652, -4, 98, 54, -210};

		ft::set<int> ft_set;
		std::cout<<"inserting: ";
		for (int i = 0; i < 5; i++)
		{
			std::cout<<*ft_set.insert(range_int[i]).first<<" ";
		}
		std::cout<<std::endl;
		ft::set<int>::iterator a = ft_set.begin();
		std::cout<<"iterator a contains before insertion or deletion into set: "<<*a<<std::endl;
		std::cout<<"inserting: "<<*ft_set.insert(-4).first<<std::endl;

		std::cout<<"set contains after inserting existing key: ";
		for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		ft_set.erase(-4);
		std::cout<<"set contains after deleting key: ";
		for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"iterator a contains after insertion or deletion into set: "<<*a<<std::endl;
		std::cout<<std::endl;

		const int range_int1[] = {478, 952, 12, -96, -9};

		ft::set<int> ft_set1;
		for (int i = 0; i < 5; i++)
		{
			ft_set1.insert(range_int1[i]);
		}
		std::cout<<"ft_set contains before swap: ";
		for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_set1 contains before swap: ";
		for (ft::set<int>::iterator it = ft_set1.begin(); it != ft_set1.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		std::cout<<std::endl;

		ft_set.swap(ft_set1);

		std::cout<<"ft_set contains after swap: ";
		for (ft::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_set1 contains after swap: ";
		for (ft::set<int>::iterator it = ft_set1.begin(); it != ft_set1.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;



		std::cout<<std::endl;
		std::cout<<std::endl;

	}

	std::cout<<"-----STL-Set----"<<std::endl;

	{
		const int range_int[] = {-652, -4, 98, 54, -210};

		std::set<int> ft_set;
		std::cout<<"inserting: ";
		for (int i = 0; i < 5; i++)
		{
			std::cout<<*ft_set.insert(range_int[i]).first<<" ";
		}
		std::cout<<std::endl;
		std::set<int>::iterator a = ft_set.begin();
		std::cout<<"iterator a contains before insertion or deletion into set: "<<*a<<std::endl;
		std::cout<<"inserting: "<<*ft_set.insert(-4).first<<std::endl;

		std::cout<<"set contains after inserting existing key: ";
		for (std::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		ft_set.erase(-4);
		std::cout<<"set contains after deleting key: ";
		for (std::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"iterator a contains after insertion or deletion into set: "<<*a<<std::endl;
		std::cout<<std::endl;

		const int range_int1[] = {478, 952, 12, -96, -9};

		std::set<int> ft_set1;
		for (int i = 0; i < 5; i++)
		{
			ft_set1.insert(range_int1[i]);
		}
		std::cout<<"ft_set contains before swap: ";
		for (std::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_set1 contains before swap: ";
		for (std::set<int>::iterator it = ft_set1.begin(); it != ft_set1.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		std::cout<<std::endl;

		ft_set.swap(ft_set1);

		std::cout<<"ft_set contains after swap: ";
		for (std::set<int>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;

		std::cout<<"ft_set1 contains after swap: ";
		for (std::set<int>::iterator it = ft_set1.begin(); it != ft_set1.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;



		std::cout<<std::endl;
		std::cout<<std::endl;

	}
}